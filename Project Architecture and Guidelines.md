# Zurui: Project Architecture and Guidelines 🚀

## Table of Contents
1. [Component Overview](#component-overview) 📦
2. [Coding Standards](#coding-standards) 📝
3. [Build Process](#build-process) ⚙️
4. [Debugging](#debugging) 🐞
5. [Version Control](#version-control) 🔄

## Component Overview 📦

- **`main.cpp`**: Entry point of the application.
- **`Main.qml`**: Main QML file for the user interface.
- **`MsQuic/`**: Contains MsQuic library files and headers for QUIC protocol implementation.
- **`translation_tools/`**: Tools for managing translations in the application.
- **`ui_components/`**: QML files for reusable UI components.
- **`ui_themes/`**: Theme configurations and assets for different visual styles.
- **`vpn_manager/`**: VPN connection handling.
- **`zurui_client/`**: Core client functionality for communication.

## Coding Standards 📝

### C++ 
- Follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) as a base.
- Use the `.clang-format` file provided by the project for consistent formatting.
- Choose descriptive names for variables and functions.

### QML
- Follow `Qt's QML` Coding Conventions.
- Use `camelCase` for property and function names.
- Use `PascalCase` for component names.

### Comments and Documentation
- Write clear and concise comments to explain complex logic.
- Document public APIs and significant functions.
- Use `Qt QDoc` comments for header files to generate documentation.

## Build Process ⚙️

To build the project, use the following custom command:

```bash
alias zurui_build='mkdir -p build && cd build && cmake -G Ninja .. && ninja && ./appZurui; cd ..; rm -rf build'
```
Here's the complete content formatted in Markdown:

# Project Build and Development Guide

## Build Process ⚙️

To build the project, use the following custom command:

```bash
alias zurui_build='mkdir -p build && cd build && cmake -G Ninja .. && ninja && ./appZurui; cd ..; rm -rf build'
```

This command:
* Creates a `build` directory
* Runs CMake with the Ninja generator
* Builds the project
* Executes the compiled application
* Cleans up the build directory

To run the build command, simply use:

```bash
zurui_build
```

## Debugging 🐞

To enable debug mode and compile with the `ZURUI_DEBUG` flag, use:

```bash
alias zurui_debug='mkdir -p build && cd build && cmake -G Ninja -DZURUI_DEBUG=ON .. && ninja && gdb ./appZurui; cd ..; rm -rf build'
```

When using debug mode:
* Additional logging will be enabled
* Performance metrics will be collected
* Assertion checks will be more verbose

You can add debug statements in your code like this:

```cpp
#ifdef ZURUI_DEBUG
    qDebug() << "Executing command: tree themes";
#endif
```

## Version Control 🔄

* Use Git for version control
* Follow the Git Flow branching model
* Use semantic versioning (MAJOR.MINOR.PATCH)
* Write clear, concise commit messages
* Squash commits before merging feature branches

Remember to keep this document updated as the project evolves. If you have any questions about the architecture or guidelines, please contact the project maintainers. 🙌
