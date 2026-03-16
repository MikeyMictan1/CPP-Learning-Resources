<h1 align="center">C++ Learning Resources - Introduction</h1>
<p align="center">
<b>A repo for teaching myself C++ (the notes + code im making along the way to look back at and remember).</b>
</p>

# C++ Coding Notes 
---
## The Fundamentals

### Declarations
`void Log(const char* message);` : as long as the function is declared before it is used (forward declaration), it can be defined after the main function, OR in another file and linked together during compilation (the compiler just knows/does the linking automatically).

### Preprocessor Statements
__`#include <iostream>`, `#include "MyHeader.h"` :__  Literally copy-pastes the contents of a header into the current file before compilation (during pre-processing). The angle brackets are for standard library headers, while the quotes are for user-defined headers. <br>
`#define IDENTIFIER substitute` : Replaces the IDENTIFIER instance with the "substitute".

### Variable Initialisation
| Syntax | Name | Behavior |
| :--- | :--- | :--- |
| `int x = 2;` | Copy Initialisation | Classic C-style; allows "narrowing" (e.g., `int x = 2.9;` becomes `2`). |
| `int x(2);` | Direct Initialisation | Can sometimes be confused with function declarations ("Most Vexing Parse"). |
| `int x { 2 };` | Braced Initialisation | Safest. Prevents data loss and works the same for almost all types. |
| `int x {};` | Value Initialisation | Automatically sets x to 0 (Zero-initialization). |

**For best practices, use Braced Initialisation (const/constexpr is an exception).**

### User I/O
- `std::cout << "hello" << "\n";` : Prints 'hello' to console and goes to a newline.
- `std::cin >> ch` :  Gets next input char from console, EXCLUDES whitespace as letters.
- `std::cin.get(ch)` : Gets next input char from console, INCLUDES whitespace as letters.

---

## Data Types

### Default Data Types
- `short` : 2 bytes, -32,768 to 32,767
- `int` (long = int on most platforms) : 4 bytes, -2,147,483,648 to 2,147,483,647
- `long long` : 8 bytes, -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 
- `float` : 4 bytes, 6-7 decimal digits of precision
- `double` : 8 bytes, 15-16 decimal digits of precision 
- __Unsigned Types :__ only positive values, double the maximum value of their signed counterparts (e.g., `unsigned int` ranges from 0 to 4,294,967,295)
- `char` : 1 byte, typically used for characters (ASCII values from 0 to 127)
- `bool` : 1 byte, can be `true` or `false`
- `void` : represents the absence of a value or return type (used for functions that do not return anything)


### More Complex Data Types 
- <u>**Integral Types**</u> : **Type that can represent a whole number e.g. standard integer types, `bool`, char. They are signed by default. <br>**
- Under the hood, a `char` is really just a integer in ASCII form.
- `std::size_t` : An alias (`typedef`) for an unsigned integral type, is often like doing `unsigned int;`, but advantage is often 8 bits not just 4 (Size depends on architecture e.g. 64 bits on 64-bit system).
- **It's better practice to do** : `for (std::size_t i = 0; i < myVector.size(); i++) {}` rather than `for (int i = 0; i < myVector.size(); i++) {}`, as an unsigned int can technically mismatch a signed one. <br>
- **It's BEST practice is to do** : `for (auto i = 0ULL; i < vec.size(); ++i) {}`, where `auto` lets the compiler fit the type perfectly.
- `int8_t` : 1 byte integer (can also do int16,32,64_t from the `<cstdint>` library)
- `char8_t` : 1 byte char   (can also do char16,32_t)
- 
### Standard Library Data Types
- `std::string` : A sequence of characters (a string).
- `std::vector<T>` : A dynamic array that can resize itself automatically when elements are added or removed.
- `std::array<T, N>` : A fixed-size array that cannot be resized after creation.
- `std::map<Key, Value>` : A collection of key-value pairs, where each key is unique and maps to a value.
- `std::set<T>` : A collection of unique elements, sorted by default.
- `std::unordered_map<Key, Value>` : A collection of key-value pairs that does not maintain any order.
- `std::unordered_set<T>` : A collection of unique elements that does not maintain any order.
- `std::pair<T1, T2>` : A simple container that holds two values of potentially different types.
- `std::tuple<T1, T2, ...>` : A fixed-size collection of heterogeneous values (can hold more than two values).

### Type Conversion
**Explicit Type Conversion** : The `static_cast` operator explicitly casts types e.g.: `print( static_cast<int>(5.5) );` explicitly convert double value 5.5 to an int.

**Implicit Type Conversion** : When the compiler decides the type for us e.g.:
```
void print(double x) {
	std::cout << x << '\n';
}

void main() {
	int y { 5 };
	print(y); // y is of type int, but passes into a 'double' parameter, so converts implicitly due to the compiler.
}
```

**Numeric Promotion** : Converting a smaller type to a larger one e.g. int -> double. (typically happens automatically)

**Numeric Conversion** : Conversion where data loss can occur (e.g. Double -> int).

**Brace initialisaion `int x {5.5};` is better, as it throws a hard error, rather than silently truncating.**

### Escape Sequences
**These can just be placed in the middle of a string.**
 
| Name | Symbol | Meaning |
| :--- | :--- | :--- |
| **Alert** | `\a` | Makes an alert, such as a beep |
| **Backspace** | `\b` | Moves the cursor back one space |
| **Formfeed** | `\f` | Moves the cursor to next logical page |
| **Newline** | `\n` | Moves cursor to next line |
| **Carriage return** | `\r` | Moves cursor to beginning of line |
| **Horizontal tab** | `\t` | Prints a horizontal tab |
| **Vertical tab** | `\v` | Prints a vertical tab |
| **Single quote** | `\'` | Prints a single quote |
| **Double quote** | `\"` | Prints a double quote |
| **Backslash** | `\\` | Prints a backslash |

**Ternary Operator**
```
if (x > y)
    max = x;
else
    max = y;
```
**Can be rewritten as:**
`max = ((x > y) ? x : y);`

---

## File Systems + Code Organisation

### Header Files and CPP Files
Header files allow us to put many forward declarations in one place then include that header file in many CPP files. This is useful for code organisation and reusability. <br>
E.g. if we have a class definition in a header file, we can include that header in multiple CPP files that need to use that class without having to redefine it in each file. <br>
If we have two methods with the same function signature in two headers in the same file, then there will be linking errors as it struggles to choose how to link what declaration to what definition (this is handled fine if they are in seperate classes tho).<br>

<u>__1:1 Header-Source Ratio:__</u> It is best practice for ALL cpp files with function definitions, to have a paired header file with the declarations, and those CPP files should #include their paired header file. <br>
<u>__Headers-In-Headers:__</u> Headers may include other headers. ONLY put a header in a h or cpp file if that file itself needs the logic from that other header. <br>
<u>__Transitive Inclusion:__</u> When a source (.cpp) file includes a header file that #includes other header files, thus are included in the source file __implicitly__. <br>
<u>__#pragma once__</u>: Written at the top of header files, ensures function declarations from headers can't be included twice in one file. <br>

__For Including Headers From Other Directories In Visual Studio:__ Right click on your project in the Solution Explorer, and choose Properties, then the VC++ Directories tab. From here, you will see a line called Include Directories. Add the directories you’d like the compiler to search for additional headers there.

---

## Constants & Strings
### Constants
- **Literal** : Pretty much just a constant (but doesn't have a name attached). Suffixes can be added to literals to specify their type (but this is niche use case).
- **Expression** :  A non-empty sequence of literals, variables, operators, and function calls that calculates a value. Evaluates at runtime by default (unless optomisation methods used).
- **Constant Expression** : An expression that MUST be evaluatable at compile-time, must write `constexpr int x = 2 + 2;`
- `const type varName;` : Makes a Named Constant variable (like in Java, nice and simple). <br>
- `const` vs `constexpr` : `const` is set at runtime, whereas `constexpr` is set at compile-time.

**So at the start of a program if I had some `int damage = 10`; that NEVER changes, `constexpr` is better as it allows compile-time programming. All constants that are known at compile-time should (mostly) be `constexpr`.** <br>
**Function parameters cannot be declared as constexpr, since their initialization value isn’t determined until runtime.**

**Conditional Statements evaluate at runtime UNLESS the constexpr keyword is used (as of C++ 17).** <br>
`if constexpr (gravity == 9.81) { ... }` evaluates at compile time.

### Strings
**C-Strings** : Strings represented as an array of chars with a `\0` null terminator to indicate the end of the string (largely replaced by `std::string` now).

**Standard String** <br>
`std::string` : Way of creating strings in modern C++ `std::string name { "Mikey" };`. This should NEVER be passed by value as it makes an expensive copy, but it's ok to return.
<br>This string has dynamic (heap) memory allocation, so can't ever have a `constexpr std::string = "hello";`.

**Standard String View** <br>
`std::string_view` : A standard string that holds a pointer to the start of some text, and the length of the text. Given it's only a pointer, it can use `constexpr`.
**DONT return them, as iof they point to local values that get destroyed at the end of the function, we reach undefined behaviour.**

- **Use `std::string` when you need to build a string (like adding two names together: first + last) or when you need to own the data.**
- **Use `std::string_view` for function parameters (best use case imo), constants, and any situation where you just need a read-only string.**

```
void printSV(std::string_view str) // now a std::string_view, creates a view of the argument
{
    std::cout << str << '\n';
}

int main()
{
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2{ "Hello, world!" };
    printSV(s2); // call with std::string

    std::string_view s3{ s2 };
    printSV(s3); // call with std::string_view

    return 0;
}
```

**Turning String Literals into Standard Strings:**
```
using namespace std::string_literals;      // access the s suffix
using namespace std::string_view_literals; // access the sv suffix

std::cout << "foo\n";   // no suffix is a C-style string literal
std::cout << "goo\n"s;  // s suffix is a std::string literal
std::cout << "moo\n"sv; // sv suffix is a std::string_view literal
```

**Reading String Input Better:**
```
#include <string> // For std::string and std::getline

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name
    // std::ws tells std::cin to ignore leading whitespaces.

```
---

## Scope, Duration, Linkage
### Namespaces
Namespaces are used to give different names to areas of code to prevent methods of the same name conflicting when linking. (Java equivalent is packages, in Python every .py file is a 'module' which is the equivalent (import module ...). <br>
An example is the standard library namespace in C++: `std::`

#### Creating a namespace
Namespaces can be in multiple different files, and the compiler will know to link them together.
```
namespace NamespaceIdentifier
{
    // content of namespace here
}
```

#### Namespace Best Practices
- Project-Wide Namespace to prevent clashes with third-party libraries.
- Use namespaces for individual modules e.g. `GameApp:UI`, `GameApp:Network`
- Don't nest more than 2-3 levels deep e.g. `Company::Project::Module::SubModule::Class`
- Doing `::method` gets the method from the global namespace
- Namespaces must BOTH be in cpp files AND header files
- Namespace Aliases `namespace Active = Foo::Goo; // active now refers to Foo::Goo`
- The 'Detail' or 'Internal' namespace convention is used to hide implementation details that are necessary for code to work, but nothing else should use it (C++ equivalent of 'private'). E.g:
```
namespace MathLib {
    // This is for the internal math logic
    namespace detail {
        double secretHelperFormula(double x) {
            return x * 3.14159 / 42.0; 
        }
    }

    // This is the public API people SHOULD use
    double calculate(double input) {
        return detail::secretHelperFormula(input) + 10.0;
    }
}
```

**Local variables are automatically destroyed when they go out of scope (e.g. at the end of a function). Classic RAII example.**

### Linkage
**Linkage** : property that determines whether a name (like a variable or function name) refers to the same entity across different parts of a program.

**Internal Linkage** : Name is unique to the source file it's defined in and can't be accessed elsewhere. `static int x;` is internal due to `static` keyword.

**External Linkage** : Names are external by default. `extern const int g_y { 3 };` const globals can be defined as extern, making them external.

**To use an external global variable, you must use a forward declaration with extern: (CANNOT be done with constexpr)** <br>
```
extern int g_x;       // this extern is a forward declaration of a variable named g_x that is defined somewhere else
extern const int g_y; // this extern is a forward declaration of a const variable named g_y that is defined somewhere else
```

**It is important to note it is bad practice to EVER use global variables, especially in C++, so try to avoid this anyways!!**

**Another Example:** <br>
a.cpp
```
int x {5};
```

b.cpp
```
extern int x;
```

if I printed x in b.cpp, it would give me 5. If b.cpp ONLY said `int x;`, then it would not print 5 as no longer looking for an external x.

**Static Keyword** <br>
Static local variables are used when you need a local variable to remember its value across function calls. Doesn't automatically get destroyed, but is out of scope outside of the function. So both local AND non-raii.
```
void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope
```
**A very common use-case, is for ID generation, as it will keep incrementing.**

## Types

## Functions Expanded

## Pointers & References

## Enums & Structs

## C++ Idioms

**Resource Acquisition Is Initialisation (RAII)** : Resource memory is tied to the lifetime of a local object, and when the object goes out of scope, its destructor is called, freeing the resource (done automatically for variables in functions, smart pointers).

**Pimpl** : 

**Curiously Recurring Template Pattern (CRTP)** : 

**Copy-and-swap** : 

**Type Erasure** : 

**Non-Virtual Interface (NVI)** : 

**Substitute Failure Is Not An Error (SFIAE)** : 

---

## Coding Best Practices/Quirks
- Single quotes for chars 'a', double for string "abc".
- Functions **cannot** be nested.
- Functions **must** be declared before being called.
- It's bad practice to EVER use global variables, especially in C++.