#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vexe.h"

// Hàm xóa bộ nhớ đệm an toàn
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

VeXe* taoNode() {
    VeXe *newNode = (VeXe*)malloc(sizeof(VeXe));
    if (newNode == NULL) {
        printf("Loi: Khong the cap phat bo nho!\n");
        return NULL;
    }
    
    printf("Nhap ma ve: "); 
    scanf("%s", newNode->maVe);
    clearBuffer(); // Xóa sạch đệm để tránh trôi fgets

    printf("Nhap ten khach hang: "); 
    fgets(newNode->tenKhach, MAX, stdin);
    newNode->tenKhach[strcspn(newNode->tenKhach, "\n")] = 0;

    printf("Nhap tuyen duong: "); 
    fgets(newNode->tuyenDuong, MAX, stdin);
    newNode->tuyenDuong[strcspn(newNode->tuyenDuong, "\n")] = 0;

    printf("Nhap gia ve: "); 
    if (scanf("%f", &newNode->giaVe) != 1) {
        newNode->giaVe = 0;
    }
    clearBuffer();
    
    newNode->next = NULL;
    return newNode;
}

void themVe(VeXe **head) {
    VeXe *newV = taoNode();
    if (newV == NULL) return; // Kiểm tra an toàn bộ nhớ

    if (*head == NULL) {
        *head = newV;
    } else {
        VeXe *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newV;
    }
    printf("===Them ve thanh cong===\n");
}

void xoaVe(VeXe **head, char *ma) {
    if (*head == NULL) return;

    VeXe *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->maVe, ma) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay ma ve: %s\n", ma);
        return;
    }

    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;

    free(temp);
    printf("Da xoa ve %s\n", ma);
}
void hienThi(VeXe *head) {
    if (head == NULL) {
        printf("\nDanh sach hien dang trong.\n");
        return;
    }
    printf("\n%-10s %-20s %-25s %-10s\n", "Ma Ve", "Ten Khach", "Tuyen Duong", "Gia Ve");
    printf("------------------------------------------------------------------\n");
    while (head != NULL) {
        printf("%-10s %-20s %-25s %-10.2f\n", head->maVe, head->tenKhach, head->tuyenDuong, head->giaVe);
        head = head->next;
    }
}