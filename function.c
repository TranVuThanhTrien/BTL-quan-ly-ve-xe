#include "vexe.h"
// Ham xoa bo nho dem, tranh troi lenh
void xoaDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// Cap phat bo nho dong
VeXe* taoNode() {
    VeXe *newNode = (VeXe*)malloc(sizeof(VeXe));
    if (newNode == NULL) return NULL;
    
    printf("Nhap ma ve: "); scanf("%s", newNode->maVe);
    xoaDem(); // SUA: xoadem() thanh xoaDem()
    printf("Nhap ten khach hang: "); fgets(newNode->tenKhach, MAX, stdin);
    newNode->tenKhach[strcspn(newNode->tenKhach, "\n")] = 0;
    printf("Nhap tuyen duong: "); fgets(newNode->tuyenDuong, MAX, stdin);
    newNode->tuyenDuong[strcspn(newNode->tuyenDuong, "\n")] = 0;
    printf("Nhap gia ve: "); scanf("%f", &newNode->giaVe);
    
    newNode->next = NULL;
    return newNode;
}
// them ve vao cuoi danh sach
void themVe(VeXe **head) {
    VeXe *newV = taoNode();
    if (*head == NULL) {
        *head = newV;
    } else {
        VeXe *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newV; // SUA: dua dong nay vao trong khoi else
    }
}
//Xoa ve theo ma ve
void xoaVe(VeXe **head, char *ma) {
    VeXe *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->maVe, ma) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;
    free(temp); // Giai phong bo nho 
}
//Hien thi danh sach ve
void hienThi(VeXe *head) {
    VeXe *temp = head; // SUA: Vexe thanh VeXe, them dau ;
    printf("\n%-10s %-20s %-20s %-10s\n", "Ma Ve", "Ten Khach", "Tuyen Duong", "Gia");
    while (temp != NULL) {
        // SUA: head->giaVe thanh temp->giaVe
        printf("%-10s %-20s %-20s %-10.2f\n", temp->maVe, temp->tenKhach, temp->tuyenDuong, temp->giaVe);
        temp = temp->next;
    }

}