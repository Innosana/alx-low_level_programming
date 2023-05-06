#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t value = 0x0102;
    uint8_t *ptr = (uint8_t *)&value;

    if (*ptr == 0x02 && *(ptr + 1) == 0x01) {
        printf("Little endian.\n");
    } else if (*ptr == 0x01 && *(ptr + 1) == 0x02) {
        printf("Big endian.\n");
    } else {
        printf("Unknown endianness.\n");
    }

    return 0;
}
