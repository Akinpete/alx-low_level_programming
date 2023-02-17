#include <unistd.h>

int main(void) {
    const char* message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    const int length = 37;
    const int file_descriptor = 2; // 2 is the standard error file descriptor

    // Write the message to the standard error
    write(file_descriptor, message, length);

    return 1;
}

