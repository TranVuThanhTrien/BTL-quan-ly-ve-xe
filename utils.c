#include "vexe.h" 

// Validate kiem tra gia ve
int validatePrice(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0; 
        }
    }
    return 1;
}

// Validate kiem tra ngay thang 
int validateDate(const char *date) {
    int d, m, y;
    if (sscanf(date, "%d/%d/%d", &d, &m, &y) != 3) return 0;
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900) return 0;
    return 1;
}

// Thong ke so luong bang thuat toan de quy
int demVeDeQuy(VeXe *head) {
    if (head == NULL) return 0;
    return 1 + demVeDeQuy(head->next);
}

// Tim kiem ve theo ten bang thuat toan de quy
VeXe* timTheoTenDeQuy(VeXe *head, const char *ten) {
    if (head == NULL) return NULL;
    if (strcmp(head->tenKhach, ten) == 0) return head;
    return timTheoTenDeQuy(head->next, ten);
}

// Giai phong toan bo bo nho tranh Leak RAM
void giaiPhong(VeXe *head) {
    VeXe *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf(">> Bo nho da duoc giai phong an toan!\n");
}

// Kiem tra ghe da co nguoi dat chua (Tra ve 1 la trung, 0 la trong)
int kiemTraGheTrong(VeXe *head, int soGheCanKiemTra) {
    VeXe *temp = head;
    while (temp != NULL) {
        if (temp->soGhe == soGheCanKiemTra) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0; 
}