# Slang
## About

__slang__ - is a simple compiler, based on LLVM. S language is planned to be a clone of c, with some extra features.

__HUGE NOTE__ - the compiler is in deep development, though it works, there are a lot of unsupported features, that would be implemented later.
## Building

In order to build the project, you need to have LLVM installed and set its binaries in $PATH.
After installing dependencies run

```
make
```
to build the compiler, or

```
make tests
```
to build the tests.

## Usage
```
slang [filename]
```
generates result.o, object file that can be linked with gcc.

## Examples
### Fibonacci function
```
func fib(n: i32): i32 {
  if n <= 2 ret 1;
  ret fib(n - 1) + fib(n - 2);
}
```

## Supported features
* func definition
* branching
* let, ret keywords
* int types

## Planned features
* float types
* bool types
* structs
* interfaces
* string support
* type deduction
* pointer and array type support
* lots of more...
