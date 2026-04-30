#include "vexe.h"
int main() {
    VeXe *head = NULL;
    int chon;
    char ma[10];
    docFile(&head); // Tu dong tai du lieu khi khoi dong 
    do {
        printf("\n--- QUAN LY VE XE KHACH ---");
        printf("\n1. Them ve");
        printf("\n2. Hien thi danh sach");
        printf("\n3. Xoa ve");
        printf("\n4. Thong ke (De quy)");
        printf("\n0. Luu va Thoat");
        printf("\nChon: ");
        scanf("%d", &chon);
        switch(chon) {
            case 1: themVe(&head); break;
            case 2: hienThi(head); break;
            case 3: 
                printf("Nhap ma can xoa: "); scanf("%s", ma);
                xoaVe(&head, ma); 
                break;
            case 4: printf("Tong so ve: %d\n", demVeDeQuy(head)); break;
            case 0:
                luuFile(head);
                giaiPhong(head);
                printf("Tam biet!\n");
                break;
        }
    } while (chon != 0);
    return 0;
}

