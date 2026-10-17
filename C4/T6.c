// X

#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
    int num;
    struct Link* next;
} L;

int n, m;

L* createLink(int n);
L* addNode(int num, L* head);
L* deleteNode(L* cur);

int main() {
    scanf("%d %d", &n, &m);
    int M = m;
    int remaining = n;

    L* head = createLink(n);
    L* cur = head;
    while (remaining > 0) {
        while (m > 1) {
            cur = cur->next;
            m--;
        }
        remaining == 1 ? printf("%d", cur->num) : printf("%d ", cur->num);
        cur = deleteNode(cur);
        m = M;
        remaining--;
    }

    return 0;
}

L* createLink(int n) {

    L* head = addNode(1, NULL);
    if (n == 1) {
        head->next = head;
        return head;
    }

    L* last;
    for (int i = 2; i <= n; i++) {
        last = addNode(i, head);
    }
    last->next = head;

    return head;
}

L* addNode(int num, L* head) {
    L* thisN = (L*)malloc(sizeof(L));
    thisN->num = num;
    thisN->next = NULL;

    if (head == NULL) {
        return thisN;
    }

    L* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = thisN;
    return thisN;
}

L* deleteNode(L* cur) {
    if (cur->next == cur) {
        free(cur); return NULL;
    }

    L* prev = cur;
    while (prev->next != cur) prev = prev->next;
    prev->next = cur->next;
    L* next = cur->next;

    free(cur);
    return next;
}
