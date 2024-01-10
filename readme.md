
# Recover

This is a C program that recovers JPEG images from a forensic image. The program accepts one and only one command line argument, the name of the file the images will be recovered from. The program outputs each of the JPEG images recovered as a separate file.

## Usage

1. Clone this repository to your local machine.
2. In the terminal, navigate to the directory where you cloned this repository.
3. Run `make` to compile the program.
4. Run `./recover card.raw` to start the program.

## Implementation

This program is built using C. The following files are included in this repository:

- `recover.c`: This file contains the main C program.
- `card.raw`: The forensic image file from which the JPEGs are recovered.