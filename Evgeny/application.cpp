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

    size_t max_len = 35;
    int len = 0;
    read(sp_all, max_len, &len);

    different_sorting(sp_all, len);
    
    printf("OK\n");
    return 0;
}


char** generate(){
    struct params params_main = {};

    char** sp_all = (char**) calloc(params_main.text_len, sizeof(char*));;
    assert(sp_all != NULL);

    return sp_all;
}


int read(char** sp_all, size_t max_len, int* len_main){
    FILE*  fread = fopen("input/input.txt", "r");
    assert(fread != NULL);
    assert(sp_all != NULL);

    sp_all[0] = (char*) calloc(max_len, sizeof(char));
    while (getline(&sp_all[*len_main], &max_len, fread) != -1){
        assert(sp_all[*len_main] != NULL);
        ++*len_main;
        sp_all[*len_main] = (char*) calloc(max_len, sizeof(char));
    }
    fclose(fread);

    return 0;
}


int different_sorting(char** sp_all, int len){
    FILE*  fwc = fopen("output/output_canon.txt", "w");
    WriteListToFile(fwc, sp_all, len);
    fclose(fwc);
    
    MergeSort((void **)sp_all, len, Compare_Strings);
    FILE* fws = fopen("output/output_sorted.txt", "w");
    WriteListToFile(fws, sp_all, len);
    fclose(fws);

    MergeSort((void **)sp_all, len, Reversed_Compare_Strings);
    FILE* fwr = fopen("output/output_sorted_reversed.txt", "w");
    WriteListToFile(fwr, sp_all, len);
    fclose(fwr);

    return 0;
}