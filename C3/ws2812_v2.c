#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct WS2812 {
    uint8_t data[3];    /* R,G,B */
    bool connected;
    struct WS2812 *next;
} WS2812_t;

WS2812_t* WS2812_Create(void) {
    WS2812_t* p = (WS2812_t*)malloc(sizeof(WS2812_t));
    if (!p) return NULL;
    p->data[0] = p->data[1] = p->data[2] = 0;
    p->connected = true;
    p->next = NULL;
    return p;
}

uint32_t WS2812_Add(WS2812_t* head) {
    if (!head) return (uint32_t)-1;
    uint32_t index = 1;
    WS2812_t* cur = head;
    while (cur->next) { cur = cur->next; index++; }
    WS2812_t* n = WS2812_Create();
    if (!n) return (uint32_t)-1;
    cur->next = n;
    return index;
}

void WS2812_SetColor(WS2812_t* head, uint32_t index, uint8_t r, uint8_t g, uint8_t b) {
    if (!head) return;
    WS2812_t* cur = head;
    for (uint32_t i = 0; i < index && cur; i++) cur = cur->next;
    if (!cur) return;
    if (!cur->connected) return;          /* 灯已断，数据传不到，改不动 */
    cur->data[0] = r; cur->data[1] = g; cur->data[2] = b;
}

WS2812_t* WS2812_Break(WS2812_t* head, uint32_t index) {
    if (!head) return head;
    WS2812_t* cur = head;
    for (uint32_t i = 0; i < index && cur; i++) cur = cur->next;
    if (!cur) return head;
    while (cur) { cur->connected = false; cur = cur->next; }
    return head;
}

void WS2812_Show(WS2812_t* head) {
    WS2812_t* cur = head;
    uint32_t i = 0;
    while (cur) {
        printf("%2u: (%02x,%02x,%02x) %s\n", i, (int)cur->data[0], (int)cur->data[1], (int)cur->data[2],
               cur->connected ? "true" : "false");
        cur = cur->next;
        i++;
    }
    printf("\n");
}

int main(void) {
    WS2812_t* head = WS2812_Create();               // 第 0 颗
    if (!head) return 1;

    for (uint8_t i = 0; i < 14; i++) WS2812_Add(head);
    printf("Add: %d\n", WS2812_Add(head));          // 期望 15

    for (uint32_t i = 0; i <= 15; i++)
        WS2812_SetColor(head, i, (uint8_t)(17*i), 0, (uint8_t)(255-17*i));

    WS2812_SetColor(head, 99, 1, 2, 3);             // 不应崩溃

    printf("\n--- before break ---\n");
    WS2812_Show(head);

    head = WS2812_Break(head, 8);                   // 让 8 号死

    printf("\n--- after break(8) ---\n");
    WS2812_Show(head);

    WS2812_SetColor(head, 3, 0xFF, 0xFF, 0xFF);     // 应该成功
    WS2812_SetColor(head, 10, 0xFF, 0xFF, 0xFF);    // 应该失败

    printf("\n--- SetColor test ---\n");
    WS2812_Show(head);

    printf("Add on NULL: %d\n", WS2812_Add(NULL));  // 期望 -1
    WS2812_Break(NULL, 0);                          // 不应崩溃
    printf("done\n");

    getchar();
    return 0;
}
