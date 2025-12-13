# Assignment 4: Transformers v2

## Author
**Name**: Egor Kadomtsev  
**Group**: 25.Б81-мм  
**Contact**: st116930@student.spbu.ru

## Description
This project expands on Assignment 3, introducing:
- **Abstract Base Class**: `Transformer` with pure virtual methods.
- **Polymorphism**: Virtual methods `openFire`, `ultraMove`, `transform`.
- **Operator Overloading**: `operator<<` for all classes.
- **Strict Styling**: Validated with `astyle -A1 -s4`.

## Build
```bash
make
```

## Testing
Run unit tests with GoogleTest:
```bash
make test
```
