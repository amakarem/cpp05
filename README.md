# CPP05 — Repetition and Exceptions

This repository contains the solutions for **CPP Module 05** from the 42 school curriculum, focused on **exception handling**, **abstract classes**, and the interactions between objects with proper error reporting in **C++98**.

## 🧩 Overview

CPP05 deepens the understanding of advanced C++ concepts by introducing:
- **Exception handling** with `try` / `catch` blocks and custom exception types.
- **Abstract classes** and inheritance to define interfaces and polymorphic behavior.
- Encapsulation of logic with robust error checking (e.g., validating grades, signing forms, executing actions safely).

## 🚧 Exercises

Each exercise lives in its own directory (`ex00` through `ex03`) and is designed to be built independently.

### ex00: Bureaucracy
- Implements the `Bureaucrat` class.
- Demonstrates basic exception handling for invalid grade values (too high / too low).
- Provides mechanisms to increment/decrement grades safely and throw exceptions on violations.

### ex01: Forms
- Introduces a `Form` class that must be signed by a `Bureaucrat`.
- Builds on ex00 by adding validation logic and exception propagation between interacting classes.

### ex02: More complex form interactions
- Combines abstract base classes with exception logic.
- Demonstrates polymorphism through form execution and controlled behavior depending on bureaucrat permissions.

### ex03: Final integration
- Uses the abstract form interface from previous exercises inside other classes.
- Solidifies the design pattern of separating interface (abstract) from implementation while handling errors gracefully.

## 🛠️ Requirements

- **C++ standard**: C++98 (mandatory for compatibility with the subject)
- **Compiler**: `g++` or `clang++` supporting the `-std=c++98` flag
- **Make**: Each exercise contains its own `Makefile` for building
- **Platform**: Tested on Unix-like systems (Linux, macOS)

## 🔧 Building

From the root of an exercise directory:

```bash
cd ex00
make          # builds the executable (e.g., Bureaucrat)
./Bureaucrat  # run the demonstration binary
```

Common `make` targets:
- `make` or `make all` — compile the exercise
- `make re` — recompile from scratch (usually does `fclean` then `all`)
- `make clean` / `make fclean` — remove object files / binaries

Ensure you compile with:

```bash
g++ -Wall -Wextra -Werror -std=c++98 <sources> -o <executable>
```

## 📦 Usage

Run the produced binaries to see example flows, such as:
- Creating `Bureaucrat` instances with valid and invalid grades.
- Signing forms and handling failure when prerequisites are not met.
- Executing form behaviors through the abstract interface, catching and reporting exceptions.

Inspect the source files (`*.cpp`, `*.hpp`/`*.h`) to understand the class hierarchies and exception types defined (e.g., `GradeTooHighException`, `GradeTooLowException`, etc.).

## 🧪 Testing Strategy

Each exercise typically includes a demonstrative `main` function that:
- Attempts invalid operations to trigger exceptions.
- Prints human-readable messages when exceptions are caught.
- Shows correct operation when invariants are respected.

You can extend or write your own tests by instantiating the classes and wrapping calls in `try`/`catch` to verify behavior.

## ✅ Style & Norm

- Follows the 42 coding standards for C++ projects.
- Exceptions are used instead of raw error codes to separate error-handling logic.
- Abstract classes define clear interfaces and force derived classes to implement required functionality.

## 📚 References

- 42 Subject: CPP05 (Repetition and Exceptions)
- C++98 Standard documentation
- Tutorials on exception handling and abstract base classes

## 📝 Notes

Customize each exercise’s README if you add enhancements or platform-specific instructions. The current setup assumes the original subject constraints (e.g., no C++11 features).

## 📌 License

This is educational code following the 42 school curriculum. Use for learning and personal development. Attribution appreciated if reused.

