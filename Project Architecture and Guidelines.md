# Zurui: Project Architecture and Guidelines

## Table of Contents
1. [Project Structure](#project-structure)
2. [Component Overview](#component-overview)
3. [Coding Standards](#coding-standards)
4. [Build Process](#build-process)
5. [Debugging](#debugging)
6. [Version Control](#version-control)

## Project Structure

```
zurui/
├── CMakeLists.txt
├── CMakeLists.txt.user
├── LICENSE_GPL
├── LICENSE_LGPL
├── LICENSE_MIT
├── main.cpp
├── Main.qml
├── MsQuic/
│   ├── bin/
│   │   ├── libmsquic.lttng.so.2.4.5
│   │   └── libmsquic.so.2.4.5
│   └── include/
│       ├── msquic.h
│       ├── msquic_posix.h
│       └── quic_sal_stub.h
├── Project Architecture and Guidelines.md
├── README.md
├── translation_tools/
│   ├── CMakeLists.txt
│   ├── translation_manager.cpp
│   └── translation_manager.h
├── ui_components/
│   ├── CMakeLists.txt
│   ├── Sign_in.qml
│   └── Sign_up.qml
├── ui_themes/
│   ├── zurui_dark/
│   │   ├── assets/
│   │   └── conf.qml
│   └── zurui_light/
│       ├── assets/
│       └── conf.qml
└── zurui_client/
    ├── CMakeLists.txt
    ├── zurui_client.cpp
    └── zurui_client.h
```

## Component Overview

- `main.cpp`: Entry point of the application
- `Main.qml`: Main QML file for the user interface
- `MsQuic/`: MsQuic library files and headers for QUIC protocol implementation
- `translation_tools/`: Tools for managing translations in the application
- `ui_components/`: QML files for reusable UI components
- `ui_themes/`: Theme configurations and assets for different visual styles
- `zurui_client/`: Core client functionality for communication

## Coding Standards

### C++
- Follow the Google C++ Style Guide as a base
- Use snake_case for variable and function names (Rust-like style)
- Use PascalCase for class names
- Use UPPER_CASE for constants and macros
- Limit line length to 100 characters
- Use descriptive variable and function names

### QML
- Follow Qt's QML Coding Conventions
- Use camelCase for property and function names
- Use PascalCase for component names

### Comments and Documentation
- Use clear and concise comments to explain complex logic
- Document public APIs and important functions
- Use Doxygen-style comments for header files

## Build Process

The project uses a custom build command for convenience:

```bash
alias zurui_build='mkdir -p build && cd build && cmake -G Ninja .. && ninja && ./appZurui; cd ..; rm -rf build'
```

This command:
1. Creates a `build` directory
2. Runs CMake with Ninja generator
3. Builds the project
4. Runs the compiled application
5. Cleans up the build directory

To build and run the project, use:

```bash
zurui_build
```

Ensure you have CMake, Ninja, and all necessary dependencies installed before building.

## Debugging

Debug information should be placed inside the `ZURUI_DEBUG` compile definition. To enable debug mode, compile with the `ZURUI_DEBUG` flag:

```bash
g++ -DZURUI_DEBUG -c main.cpp
```

When using debug mode:
- Additional logging will be enabled
- Performance metrics will be collected
- Assertion checks will be more verbose

## Version Control

- Use Git for version control
- Follow the Git Flow branching model
- Use semantic versioning (MAJOR.MINOR.PATCH)
- Write clear, concise commit messages
- Squash commits before merging feature branches

Remember to keep this document updated as the project evolves. If you have any questions about the architecture or guidelines, please contact the project maintainers.
