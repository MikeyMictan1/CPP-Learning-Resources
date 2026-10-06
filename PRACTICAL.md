# Writing Good C++ Checklist

## Ownership & Lifetime
- RAII everything
- No naked `new`/`delete`. Use `std::make_unique` or `std::make_shared`
- `unique_ptr` by default
- `shared_ptr` only for truly shared ownership
- `weak_ptr` to break cycles
- Raw pointers and references mean just looking, don't own. Use a reference if it can't be null, a pointer if it can.
- Rule of Zero: If your members clean themselves up, write no destructor, copy or move. If you write one of the five, think about all five.
- Never return a reference, pointer, `string_view`, or `span` to a local, as it dies when it goes out of scope.