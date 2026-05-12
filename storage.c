#include "vexe.h" 

// Ham luu danh sach lien ket vao file nhi phan
void luuFile(VeXe *head) {
    FILE *f = fopen(FILE_BIN, "wb");
    if (f == NULL) {
        printf("Loi: Khong the tao hoac mo file de ghi!\n");
        return;
    }
    VeXe *temp = head;
    while (temp != NULL) {
        fwrite(temp, sizeof(VeXe), 1, f);
        temp = temp->next;
    }
    fclose(f);
}

// Ham doc du lieu tu file nhi phan ra danh sach lien ket
void docFile(VeXe **head) {
    FILE *f = fopen(FILE_BIN, "rb");
    if (f == NULL) {
        return; // Chua co file thi thoi, khong bao loi
    }
    
    VeXe nodeDocDuoc;
    while (fread(&nodeDocDuoc, sizeof(VeXe), 1, f) == 1) {
        VeXe *newNode = (VeXe*)malloc(sizeof(VeXe));
        *newNode = nodeDocDuoc; 
        newNode->next = NULL; 
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            VeXe *tail = *head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = newNode;
        }
    }
    fclose(f);
}