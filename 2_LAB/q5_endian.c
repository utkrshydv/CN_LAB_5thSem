#include <stdio.h>
#include <stdlib.h>

void printBytes(unsigned char *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%p -> %d\n", (void*)(ptr + i), *(ptr + i));
    }
}

// Function to check endianness
int isLittleEndian() {
    unsigned int x = 1;
    char *c = (char *)&x;
    return (*c == 1);  // If LSB is stored first, it's little endian
}

// Function to reverse bytes (convert endian)
unsigned int convertEndian(unsigned int num) {
    unsigned char *ptr = (unsigned char *)&num;
    unsigned int result = 0;
    unsigned char *resPtr = (unsigned char *)&result;

    for (int i = 0; i < 4; i++) {
        resPtr[i] = ptr[3 - i];
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    unsigned int num = atoi(argv[1]);

    printf("Original number = %u\n", num);
    printf("\nMemory representation of the Number\n");
    printf("--------------------------------------\n");

    printBytes((unsigned char*)&num, sizeof(num));

    if (isLittleEndian())
        printf("\nThe LSB of the number is stored at the lowest memory address\nHence, the host machine is in Little Endian\n");
    else
        printf("\nThe MSB of the number is stored at the lowest memory address\nHence, the host machine is in Big Endian\n");

    unsigned int converted = convertEndian(num);

    printf("\nThe Number is converted to %s Endian now\n",
        isLittleEndian() ? "Big" : "Little");

    printf("Memory representation of the Number\n");
    printf("--------------------------------------\n");

    printBytes((unsigned char*)&converted, sizeof(converted));

    printf("\nThe number in %s Endian Format is %u\n",
        isLittleEndian() ? "Big" : "Little", converted);

    return 0;
}