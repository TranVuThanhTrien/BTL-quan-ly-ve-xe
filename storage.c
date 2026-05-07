#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char hoTen[50];
    char soGhe[10];
    float giaVe;
} VeXe;

void luuVe(VeXe v) {
    FILE *f = fopen("vexe.txt", "a");
    if (f == NULL) return;
    fprintf(f, "%d|%s|%s|%.2f\n", v.id, v.hoTen, v.soGhe, v.giaVe);
    fclose(f);
}

int checkTest(int idTim) {
    FILE *f = fopen("vexe.txt", "r");
    if (f == NULL) return 0;

    VeXe v;
    while (fscanf(f, "%d|%[^|]|%[^|]|%f\n", &v.id, v.hoTen, v.soGhe, &v.giaVe) != EOF) {
        if (v.id == idTim) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int main() {
    VeXe v1 = {101, "Nguyen Van A", "A12", 50000};
    
    printf("Processing: %d\n", v1.id);
    luuVe(v1);

    if (checkTest(101)) {
        printf("Test result: PASS\n");
    } else {
        printf("Test result: FAIL\n");
    }

    return 0;
}