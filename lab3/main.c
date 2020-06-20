#include <stdio.h>

int main() {

    int hex = 0x00;
    int Dec = 0;

    printf("Dec: %d\t", Dec);
    printf("Hex: %x\n", hex);

    int i = 0;

    while (i < 15)
    {
    i++;
    Dec++;
    hex++;

    printf("Dec: %d\t", Dec);
    printf("Hex: %x\n", hex);
    }

  return 0;

}
