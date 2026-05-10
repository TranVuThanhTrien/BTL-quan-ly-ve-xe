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

// Sten ham thanh demVeDeQuy
int demVeDeQuy(VeXe *head) {
    if (head == NULL) return 0;
    return 1 + demVeDeQuy(head->next);
}

// customerName thanh tenKhach
VeXe* searchByNameRecursive(VeXe *head, const char *name) {
    if (head == NULL) return NULL;
    if (strcmp(head->tenKhach, name) == 0) return head;
    return searchByNameRecursive(head->next, name);
}

//  Ticket thanh VeXe
void giaiPhong(VeXe *head) {
    VeXe *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf(">> Bo Nho Da Duoc Giai Phong \n");