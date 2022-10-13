#include "functions.hpp"


/*!
\file
\brief Главный файл проекта с функцией main, по умолчанию проверяет корректность работы функций библиотеки
\authors Zhdanov_EA
*/

int reversed = false;


int main ()
{
    params.data_type = TYPE_EL.STRING;
    params.reverse = false;

    size_t max_len = 35;
    char* sp_a[6300]  = {};
    size_t sp_len[6300] = {};
    sp_a[0] = (char*) calloc(max_len, sizeof(char));

    FILE* f = fopen("input/input.txt", "r");

    int len = 0;
    while (getline(&sp_a[len], &max_len, f) != -1){
        sp_len[len] = strlen(sp_a[len]);
        ++len;
        sp_a[len] = (char*) calloc(max_len, sizeof(char));
    }

    FILE* fwc = fopen("output/output_canon.txt", "w");
    for (int j = 0; j < len; j++){
        fprintf(fwc, sp_a[j]);
    }
    
    qsort(sp_a, len, sizeof(char*), Compare_Elements);
    FILE* fw = fopen("output/output_sorted.txt", "w");
    for (int j = 0; j < len; j++){
        fprintf(fw, sp_a[j]);
    }

    reversed = true;
    qsort(sp_a, len, sizeof(char*), Compare_Elements);
    FILE* fwr = fopen("output/output_sorted_reversed.txt", "w");
    for (int j = 0; j < len; j++){
        fprintf(fwr, sp_a[j]);
    }
    
    printf("OK\n");

    return 0;
}
