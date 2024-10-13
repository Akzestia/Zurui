# Zurui

**Zurui** is a high-speed data transferring and exchange application designed for seamless, decentralized communication. It enables users to connect directly with one another, ensuring maximum privacy and security without relying on centralized servers.

## Current Status

This repository is in the early stages of development. The primary goal is to create a decentralized chat application that allows for high-speed data transfer and secure communication.

## Features (Planned)

- **Decentralized Communication**: Bypass centralized servers for enhanced privacy and security.
- **Peer-to-Peer Connectivity**: Fast and direct connections between devices for efficient data transfer.
- **Portability**: Connect from anywhere with Wi-Fi, making it ideal for on-the-go communication.
- **Intuitive Interface**: User-friendly design for easy navigation and interaction.
- **Secure File Sharing**: Share files safely with end-to-end encryption.

## Roadmap

- [ ] Set up project structure and initialize repository
- [ ] Implement basic peer-to-peer connectivity
- [ ] Develop user interface for sending and receiving messages
- [ ] Enable secure file sharing capabilities
- [ ] Test and refine performance and security features

## Installation

Instructions for installation will be provided once the project is further developed.

## Usage

Details on how to use **Zurui** will be available in the future as the project progresses.

## Contributing

Contributions are welcome! If you would like to help with the development of **Zurui**, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes.
4. Push to the branch and create a pull request.

## Code Formatting

To maintain consistent code style across the project, **Zurui** uses different formatting tools for C++ and QML files:
- C++: We use a `.clang-format` file based on Google's C++ style guide.
- QML: We use `qmlformat` for consistent QML formatting.

### C++ Formatting Guidelines

- The `.clang-format` file is located in the root directory of the repository.
- Use this file to format C++ code.

#### How to Format C++ Code

1. Ensure you have Clang-Format installed on your system.

2. To format a single C++ file:
   ```bash
   clang-format -i <file.cpp>
   ```

3. To format all C++ files in the project:
   ```bash
   find . \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} +
   ```

### QML Formatting Guidelines

- We use `qmlformat` for QML files to ensure consistent styling.

#### How to Format QML Code

1. Ensure you have `qmlformat` installed. It's typically included with Qt installations.

2. To format a single QML file:
   ```bash
   qmlformat -i <file.qml>
   ```

3. To format all QML files in the project:
   ```bash
   find . -name '*.qml' -exec qmlformat -i {} +
   ```

### IDE Integration

Consider setting up your IDE to use the project's `.clang-format` file automatically for C++ files and `qmlformat` for QML files.

### Pre-commit Hook (Optional)

To ensure all committed code is properly formatted, you can set up a pre-commit hook:

1. Create a file named `pre-commit` in `.git/hooks/`
2. Add the following content:
   ```bash
   #!/bin/sh
   find . \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} +
   find . -name '*.qml' -exec qmlformat -i {} +
   git add .
   ```
3. Make the hook executable:
   ```bash
   chmod +x .git/hooks/pre-commit
   ```

This will automatically format your C++ and QML code before each commit.

Remember, consistent formatting helps maintain code readability and reduces merge conflicts. If you have any questions about the coding style or formatting tools, please reach out to the project maintainers.


## Contact

For inquiries or support, please reach out to [Email](akzestia@gmail.com).
