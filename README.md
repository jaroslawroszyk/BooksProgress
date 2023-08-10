# BooksProgress

BooksProgress is a simple command-line program for tracking and managing your reading progress.

## Build

To build the project, you'll need CMake 3.17+.

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

### Using Ninja

```bash
mkdir build
cd build
cmake -G Ninja ..
ninja
```

## Execute

Once the project is built, navigate to the `bin` directory and run the executable.

```bash
cd bin
./BookStatistic
```

## Features

- Enter your daily reading progress and automatically save it to files.
- Calculate and display the total number of pages read for a given book.

## Usage

1. Run the executable `./BookStatistic` in your terminal.
2. Choose from the available options in the menu:
   - Enter your daily reading progress and save it to files.
   - Calculate and display the total number of pages read for a given book.
   - Show available files, their contents, and delete files.
   - Calculate how many pages you have read.
   - Exit the program.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
