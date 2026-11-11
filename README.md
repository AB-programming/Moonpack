# Moonpack

Moonpack is a lightweight JavaScript bundler written in C++ (work in progress). The goal: starting from an entry file, recursively parse `import` references across JS files, build a module dependency graph, and finally bundle all modules into a single JS file.

## Current Status

The project is still in its early stages. What's implemented so far:

- **Directory scanning**: recursively scan a given project directory and collect all files (`file_scanner`)
- **File reading**: read source file contents (`file_utils`)
- **Import parsing**: regex-based parsing of ES Module named import statements, extracting imported names and module paths (`parse`)
- **Module structure**: data structures describing module dependencies and imports (`module`)

Running the program lists the scanned files along with the import dependencies parsed from each file.

Still to come: dependency graph construction, module path resolution, code merging and bundle output.

## Tech Stack

- **Language**: C++17
- **Build system**: CMake (>= 3.20)
- **Dependencies**: C++ standard library only (`std::filesystem`, `std::regex`, etc.) — no third-party dependencies

## Requirements

- CMake 3.20 or higher
- A C++17-compatible compiler (GCC / Clang / MinGW / MSVC)

## Quick Start

### 1. Clone the repository

```bash
git clone https://github.com/AB-programming/Moonpack.git
cd Moonpack
```

### 2. Build

```bash
cmake -S . -B build -G "Your Generator"
cmake --build build
```

The output binary is `build/Moonpack.exe` (Windows) or `build/Moonpack` (Linux/macOS).

### 3. Run

Pass the directory of the JS project you want to scan:

```bash
./build/Moonpack <project-directory>
```

For example:

```bash
./build/Moonpack ./examples/my-js-project
```

The program prints the list of scanned files and the import dependencies parsed from each file.

## Project Structure

```
Moonpack/
├── CMakeLists.txt        # CMake build configuration
├── src/
│   ├── main.cpp          # Entry point: scans a directory and prints parsed results
│   ├── file_scanner.*    # Recursive directory scanning
│   ├── file_utils.*      # File reading utilities
│   ├── parse.*           # Import statement parsing (regex)
│   └── module.cpp        # Module data structures
└── build/                # Build output directory
```
