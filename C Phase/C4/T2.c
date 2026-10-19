#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef struct T2 {
    uint32_t input;
    int answerBinary[32];
    char answerHex[8];
} T2;

char conv(int num);

int main() {
    T2 t2 = {0, 0, 0};
    scanf("%u", &t2.input);

    uint32_t input = t2.input;
    int hexCache[8] = {0};
    bool bPrintable = false;
    bool hPrintable = false;

    for (int i = 0; i < 32; i++) {
        t2.answerBinary[31 - i] = (input >> i) & 0x1;
    }

    for (int i = 0; i < 32; i++) {
        if ((t2.answerBinary[i] == 1 && !bPrintable) || i == 31) bPrintable = true;
        if (bPrintable) printf("%d", t2.answerBinary[i]);
    }

    printf("\n");

    for (int i = 0; i < 8; i++) {
        hexCache[7 - i] = (input >> 4 * i) & 0xf;
    }

    for (int i = 0; i < 8; i++) {
        t2.answerHex[i] = conv(hexCache[i]);
        if ((hexCache[i] != 0 && !hPrintable) || i == 7) hPrintable = true;
        if (hPrintable) printf("%c", t2.answerHex[i]);
    }

    return 0;
}

char conv(int num) {
    switch (num) {
        case 0:  return '0';
        case 1:  return '1';
        case 2:  return '2';
        case 3:  return '3';
        case 4:  return '4';
        case 5:  return '5';
        case 6:  return '6';
        case 7:  return '7';
        case 8:  return '8';
        case 9:  return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';

        default: return '0';
    }
}


// Cost 50 min
