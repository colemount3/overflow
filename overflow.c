#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[200];
    printf("%p\n", buffer);
    printf("Enter input: ");
    fflush(stdout);  // Flush the output buffer
    gets(buffer);    // This function is intentionally vulnerable
}

int main() {
    while (1) {
        vulnerable_function();
        printf("Program completed successfully.\n");
    }
    return 0;
}