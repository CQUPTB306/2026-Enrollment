#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct T4 {
    char a[10000+1], b[10000+1];
    int lena, lenb, carry;
    int output[10001];
} T4;

// int clamp(int i);
int  c2n(char num);
// char n2c(int num);

int main() {
    T4 t4 = {0};

    scanf("%10000s", t4.a);
    scanf("%10000s", t4.b);
    t4.lena = strlen(t4.a);
    t4.lenb = strlen(t4.b);

    for (int i = 0; i < 10001; i++) {
        int indexa = t4.lena - i - 1;
        int indexb = t4.lenb - i - 1;
        int a = (indexa >= 0) ? c2n(t4.a[indexa]) : 0;
        int b = (indexb >= 0) ? c2n(t4.b[indexb]) : 0;
        t4.output[10000 - i] = a + b + t4.carry;
        if (t4.output[10000 - i] > 9) {
            t4.carry = 1;
            t4.output[10000 - i] -= 10;
        } else {
            t4.carry = 0;
        }
    }

    bool printable = false;
    for (int i = 0; i < 10001; i++) {
        if ((t4.output[i] != 0 && !printable) || i == 10000) printable = true;
        if (printable) printf("%d", t4.output[i]);
    }

    return 0;
}

// int clamp(int i) {
//     return (i == 10000) ? 9999 : i;
// }

int c2n(char num) {
    switch (num) {
        case '0':  return 0;
        case '1':  return 1;
        case '2':  return 2;
        case '3':  return 3;
        case '4':  return 4;
        case '5':  return 5;
        case '6':  return 6;
        case '7':  return 7;
        case '8':  return 8;
        case '9':  return 9;

        default:   return 0;
    }
}

// char n2c(int num) {
//     switch (num) {
//         case 0:  return '0';
//         case 1:  return '1';
//         case 2:  return '2';
//         case 3:  return '3';
//         case 4:  return '4';
//         case 5:  return '5';
//         case 6:  return '6';
//         case 7:  return '7';
//         case 8:  return '8';
//         case 9:  return '9';
//     }
// }

// void reverse(char a[10001])