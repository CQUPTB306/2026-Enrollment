#include <stdio.h>

typedef struct T3 {
    int input[4][4];
    int outputMain, outputSubMain;
} T3;

int main() {
    T3 t3 = {0, 0, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &t3.input[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) t3.outputMain += t3.input[i][j];
            if ((3 - i) == j) t3.outputSubMain += t3.input[i][j];
        }
    }

    printf("%d %d", t3.outputMain, t3.outputSubMain);

    return 0;
}



// Cost 7 min
