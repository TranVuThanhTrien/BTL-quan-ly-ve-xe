#include "vexe.h"

void luuFile(VeXe *head) {
    FILE *f = fopen(FILE_BIN, "wb"); 
    if (f == NULL) {
        printf("Loi: Khong the mo file de luu du lieu!\n");
        return;
    }
    
    VeXe *temp = head;
    while (temp != NULL) {
        fwrite(temp, sizeof(VeXe), 1, f);
        temp = temp->next;
    }
    
    fclose(f);
    printf(">> Da luu du lieu thanh cong vao %s\n", FILE_BIN);
}

void docFile(VeXe **head) {
    FILE *f = fopen(FILE_BIN, "rb"); 
    if (f == NULL) {
        printf(">> Khong tim thay file %s. Se tao file moi khi luu.\n", FILE_BIN);
        return;
    }
    
    VeXe temp;
    while (fread(&temp, sizeof(VeXe), 1, f) == 1) {
        VeXe *newNode = (VeXe*)malloc(sizeof(VeXe));
        if (newNode != NULL) {
            *newNode = temp;       
            newNode->next = NULL;  
            
            if (*head == NULL) {
                *head = newNode;
            } else {
                VeXe *curr = *head;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }
    }
    
    fclose(f);
    printf(">> Da tai du lieu tu %s thanh cong.\n", FILE_BIN);
}