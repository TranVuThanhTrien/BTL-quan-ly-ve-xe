#ifndef VEXE_H
#define VEXE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define FILE_BIN "data_vexe.dat"

// Cau truc danh sach lien ket don
typedef struct VeXe {
    char maVe[10];
    char tenKhach[MAX];
    char tuyenDuong[MAX];
    float giaVe;
    struct VeXe *next; 
} VeXe;

// Khai bao cac ham trong function.c
void xoaDem();
VeXe* taoNode();
void themVe(VeXe **head);
void hienThi(VeXe *head);
void xoaVe(VeXe **head, char *ma);

// Khai bao cac ham trong storage.c
void luuFile(VeXe *head);
void docFile(VeXe **head);

// Khai bao cac ham trong utils.c
void giaiPhong(VeXe *head);
int demVeDeQuy(VeXe *head);
int validatePrice(const char *input);

#endif
