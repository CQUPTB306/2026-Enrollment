#include <stdio.h>
#include <stdbool.h>

int n;
bool used[10];
int cur[10];
int cnt;

void fill(int k);

int main(void) {
    scanf("%d", &n);
    fill(0);
    printf("%d\n", cnt);
    return 0;
}

void fill(int k) {
    if (k == n) {
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", cur[i]);
        }
        printf("%d\n", cur[n - 1]);
        cnt++;
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (used[v]) continue;
        cur[k] = v;
        used[v] = true;

        fill(k + 1);

        used[v] = false;
    }
}