#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vexe.h" 

int validatePrice(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0; 
        }
    }
    return 1;
}
int validateDate(const char *date) {
    int d, m, y;
    if (sscanf(date, "%d/%d/%d", &d, &m, &y) != 3) return 0;
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900) return 0;
    return 1;
}

int demVeDeQuy(VeXe *head) {
    if (head == NULL) return 0;
    return 1 + demVeDeQuy(head->next);
}

VeXe* timTheoTenDeQuy(VeXe *head, const char *ten) {
    if (head == NULL) return NULL;
    if (strcmp(head->tenKhach, ten) == 0) return head;
    return timTheoTenDeQuy(head->next, ten);
}

void giaiPhong(VeXe *head) {
    VeXe *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf(">> Bo Nho Da Duoc Giai Phong \n");
}
