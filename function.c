#include "vexe.h"

// Ham xoa bo nho dem, tranh troi lenh
void xoaDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cap phat bo nho dong va nhap du lieu
VeXe* taoNode(VeXe *head) {
    VeXe *newNode = (VeXe*)malloc(sizeof(VeXe));
    if (newNode == NULL) return NULL;
    
    printf("Nhap ma ve: "); scanf("%s", newNode->maVe);
    xoaDem(); 
    printf("Nhap ten khach hang: "); fgets(newNode->tenKhach, MAX, stdin);
    newNode->tenKhach[strcspn(newNode->tenKhach, "\n")] = 0;
    printf("Nhap tuyen duong: "); fgets(newNode->tuyenDuong, MAX, stdin);
    newNode->tuyenDuong[strcspn(newNode->tuyenDuong, "\n")] = 0;

    // XU LY NHAP NGAY THANG (Su dung ham validateDate co san)
    int ngayHopLe = 0;
    do {
        printf("Nhap ngay di (dd/mm/yyyy): ");
        scanf("%s", newNode->ngayDi);
        
        if (validateDate(newNode->ngayDi) == 1) {
            ngayHopLe = 1; // Ngay hop le thi thoat vong lap
        } else {
            printf(">> LOI: Ngay thang khong hop le hoac sai dinh dang. Vui long nhap lai!\n");
        }
    } while (ngayHopLe == 0);
    
    // XU LY CHON GHE (Bat loi nhap sai hoac trung ghe)
    int gheHopLe = 0;
    do {
        printf("Nhap so ghe (1 - 50): ");
        scanf("%d", &newNode->soGhe);
        
        if (newNode->soGhe < 1 || newNode->soGhe > 50) {
            printf(">> LOI: So ghe phai tu 1 den 50. Vui long nhap lai!\n");
        } else if (kiemTraGheTrong(head, newNode->soGhe) == 1) {
            printf(">> LOI: Ghe so %d da co nguoi dat. Vui long chon ghe khac!\n", newNode->soGhe);
        } else {
            gheHopLe = 1; // Du lieu chuan
        }
    } while (gheHopLe == 0);

    printf("Nhap gia ve: "); scanf("%f", &newNode->giaVe);
    
    newNode->next = NULL;
    return newNode;
}

// Them ve vao cuoi danh sach
void themVe(VeXe **head) {
    VeXe *newV = taoNode(*head); 
    if (*head == NULL) {
        *head = newV;
    } else {
        VeXe *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newV; 
    }
    printf(">> Them ve thanh cong!\n");
}

// Xoa ve theo ma ve
void xoaVe(VeXe **head, char *ma) {
    VeXe *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->maVe, ma) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf(">> Khong tim thay ve co ma: %s\n", ma);
        return;
    }
    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;
    free(temp); 
    printf(">> Da xoa ve thanh cong!\n");
}

// Hien thi danh sach ve kem Ngay Di va So Ghe
void hienThi(VeXe *head) {
    if (head == NULL) {
        printf(">> Danh sach ve hien dang trong!\n");
        return;
    }
    VeXe *temp = head; 
    
    // Mo rong cot Ten Khach (25) va Tuyen Duong (30), them dau | de ke bang dep hon
    printf("\n%-10s | %-25s | %-30s | %-12s | %-8s | %-15s\n", "Ma Ve", "Ten Khach", "Tuyen Duong", "Ngay Di", "So Ghe", "Gia (VND)");
printf("---------------------------------------------------------------------------------------------------------------\n");
    
    while (temp != NULL) {
        printf("%-10s | %-25s | %-30s | %-12s | %-8d | %-15.2f\n", 
               temp->maVe, temp->tenKhach, temp->tuyenDuong, temp->ngayDi, temp->soGhe, temp->giaVe);
        temp = temp->next;
    }
}