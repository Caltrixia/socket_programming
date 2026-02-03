# Socket Programming Tutorials: Beginner to Advanced

## 📚 Complete Learning Path

This comprehensive tutorial series will take you from zero to hero in socket programming.

## Course Structure

| Module | Topic | Difficulty |
|--------|-------|------------|
| 01 | Fundamentals of Networking | Beginner |
| 02 | Basic TCP Socket Programming | Beginner |
| 03 | UDP Socket Programming | Beginner |
| 04 | Concurrent Server Design | Intermediate |
| 05 | Socket Options and Configuration | Intermediate |
| 06 | Protocol Design and Message Framing | Intermediate |
| 07 | Secure Sockets (TLS/SSL) | Advanced |
| 08 | High-Performance I/O (epoll) | Advanced |
| 09 | IPv6 and Dual-Stack Programming | Advanced |
| 10 | Unix Domain Sockets | Advanced |
| Final | Chat Application Project | Expert |

## How to Use This Tutorial

1. **Read the README.md** in each module folder for theory
2. **Study the code examples** in the `examples/` subfolder
3. **Complete the exercises** in the `exercises/` subfolder
4. **Check your answers** against the `expected_output/` files
5. **Build the mini-project** for each module

## Prerequisites

- Basic C programming knowledge
- Linux/Unix environment (or WSL on Windows)
- GCC compiler
- Make utility

## Compilation

Most examples can be compiled with:
```bash
gcc -o program program.c
```

For threaded programs:
```bash
gcc -o program program.c -pthread
```

For TLS programs:
```bash
gcc -o program program.c -lssl -lcrypto
```

## Quick Start

```bash
cd 01_networking_fundamentals
cat README.md
cd examples
gcc -o example1 example1.c
./example1
```

## Author

Github Copilot
## License

Educational use only.
