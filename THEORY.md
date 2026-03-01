<h1 align="center">C++ Theory Learning Resources - Introduction</h1>
<p align="center">
<b>Notes for teaching myself C++ THEORY.</b>
</p>

# The Compiler

### Compile-Time Optomisation
**C++ Compilers can automatically optomise programs as part of compilation (these don't modify source code, but are applied during compilation) e.g. evaluating expressions.** <br>
**The as-if Rule** : The compiler can modify a program however it likes in order to produce more optimised code, as long as the modifications don't affect the program's "observable behaviour". <br>

**Types of Compile-Time Optomisation:** <br>
- **Constant Folding** : Replaces expressions with the result of the expression e.g. `3+4` is replaced to be `7`.
- **Constant Propagation** : Replaces variables with known constant values with their values e.g. if `int x {7};` and `x` never changes value.
- **Dead Code Elimination** : Removes code that has no effect on the program's behaviour.

### Compile-Time Programming Pros + Cons
#### Pros
- Less to do at runtime, improving performance.
- Less bugs due to errors and undefined behaviour being caught at compile time.

#### Cons
- Reliant on the compiler, so on a different device + compiler, the program may behave differently.
