#include "functions.hpp"


/*!
\file
\brief Главный файл проекта с функцией main
\authors Zhdanov_EA
*/

int reversed = false;


/*!
	\brief Главная функция проекта.

    <main> производит считывание текста из файла, сортирует его различными способами и методами и записывает результат в папку output проекта
*/

int main ()
{
    struct params params_main;

    size_t max_len = 35;
    char* sp_a[params_main.text_len]  = {};
    size_t sp_len[params_main.text_len] = {};
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
    
    MergeSort(sp_a, len, sizeof(char*));
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
