#include "libc.h"

// Do not export
// Either give a file and it will print the resulting utf8_chars list or two and he will copy one into the other.
int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3)
        err("[UTF8][MAIN] Wrong number of arguments.");
}
