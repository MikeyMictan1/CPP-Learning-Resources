# C++ Coding Notes 
---
## Fundamentals

### Declarations
`void Log(const char* message);` : as long as the function is declared before it is used (forward declaration), it can be defined after the main function, OR in another file and linked together during compilation (the compiler just knows/does the linking automatically).

### Header Files and CPP Files
Header files allow us to put many forward declarations in one place then include that header file in many CPP files. This is useful for code organisation and reusability. <br>
E.g. if we have a class definition in a header file, we can include that header in multiple CPP files that need to use that class without having to redefine it in each file. <br>
If we have two methods with the same function signature in two headers in the same file, then there will be linking errors as it struggles to choose how to link what declaration to what definition (this is handled fine if they are in seperate classes tho).<br>

<u>__1:1 Header-Source Ratio:__</u> It is best practice for ALL cpp files with function definitions, to have a paired header file with the declarations, and those CPP files should #include their paired header file. <br>
<u>__Headers-In-Headers:__</u> Headers may include other headers. ONLY put a header in a h or cpp file if that file itself needs the logic from that other header. <br>
<u>__Transitive Inclusion:__</u> When a source (.cpp) file includes a header file that #includes other header files, thus are included in the source file __implicitly__. <br>
<u>__#pragma once__</u>: Written at the top of header files, ensures function declarations from headers can't be included twice in one file. <br>

__For Including Headers From Other Directories In Visual Studio:__ Right click on your project in the Solution Explorer, and choose Properties, then the VC++ Directories tab. From here, you will see a line called Include Directories. Add the directories you’d like the compiler to search for additional headers there.


### Preprocessor Statements
__`#include <iostream>`, `#include "MyHeader.h"` :__  Literally copy-pastes the contents of a header into the current file before compilation (during pre-processing). The angle brackets are for standard library headers, while the quotes are for user-defined headers. <br>
`#define IDENTIFIER substitute` : Replaces the IDENTIFIER instance with the "substitute".

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