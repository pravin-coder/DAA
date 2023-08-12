#include <stdio.h>
#include <string.h>

int main() {
    char source[100], destination[100];

    printf("Enter a string: ");
    scanf("%s", source);

    // Copy the content of source to destination
    strcpy(destination, source);

    printf("Original string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}
