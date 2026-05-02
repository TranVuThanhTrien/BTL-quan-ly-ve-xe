#ifndef VEXE_H
#define VEXE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif
#ifndef VEXE_H
#define VEXE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro va tien xu ly 
#define MAX 100
#define FILE_BIN "data_vexe.dat"

#endif
#ifndef VEXE_H
#define VEXE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro va tien xu ly 
#define MAX 100
#define FILE_BIN "data_vexe.dat"

// Cau truc danh sach lien ket don 
typedef struct VeXe {
    char maVe[10];
    char tenKhach[MAX];
    char tuyenDuong[MAX];
    float giaVe;
    struct VeXe *next; // Cau truc tu tro
} VeXe;

#endif
