#include "functions.hpp"


/*!
\file
\brief Главный файл проекта с функцией main
\authors Zhdanov_EA
*/



/*!
	\brief Главная функция проекта.

    <main> производит считывание текста из файла, сортирует его различными способами и методами и записывает результат в папку output проекта
*/

int main ()
{
    char** sp_all = generate();

    size_t max_len = 35; // определяет стандартный размер буфура для calloc каждой строки
    int sp_all_len = 0;
    read(sp_all, max_len, &sp_all_len);

    different_sorting(sp_all, sp_all_len);
    
    printf("OK\n");
    return 0;
}


char** generate(){
    struct params params_main = {};

    char** sp_all = (char**) calloc(params_main.text_len, sizeof(char*));;
    assert(sp_all != NULL);

    return sp_all;
}


int read(char** sp_all, size_t max_len, int* sp_all_len){
    FILE*  fread = fopen("input/input.txt", "r");
    assert(fread != NULL);
    assert(sp_all != NULL);

    sp_all[0] = (char*) calloc(max_len, sizeof(char));
    while (getline(&sp_all[*sp_all_len], &max_len, fread) != -1){
        assert(sp_all[*sp_all_len] != NULL);
        ++*sp_all_len;
        sp_all[*sp_all_len] = (char*) calloc(max_len, sizeof(char));
    }
    fclose(fread);

    return 0;
}


int different_sorting(char** sp_all, int sp_all_len){
    FILE*  fwc = fopen("output/output_canon.txt", "w");
    WriteListToFile(fwc, sp_all, sp_all_len);
    fclose(fwc);
    
    MergeSort((void **)sp_all, sp_all_len, Compare_Strings);
    FILE* fws = fopen("output/output_sorted.txt", "w");
    WriteListToFile(fws, sp_all, sp_all_len);
    fclose(fws);

    MergeSort((void **)sp_all, sp_all_len, Reversed_Compare_Strings);
    FILE* fwr = fopen("output/output_sorted_reversed.txt", "w");
    WriteListToFile(fwr, sp_all, sp_all_len);
    fclose(fwr);

    return 0;
}