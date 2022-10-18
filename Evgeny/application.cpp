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
    char** sp_a = generate();

    size_t max_len = 35;
    int len = read(sp_a, max_len);

    write(sp_a, len);
    
    printf("OK\n");
    return 0;
}


char** generate(){
    struct params params_main = {};

    char**  sp_a = (char**) calloc(params_main.text_len, sizeof(char*));;
    assert(sp_a != NULL);

    return sp_a;
}


int read(char** sp_a, size_t max_len){
    FILE*  f = fopen("input/input.txt", "r");
    assert(f != NULL);
    assert(sp_a != NULL);

    int len = 0;
    sp_a[0] = (char*) calloc(max_len, sizeof(char));
    while (getline(&sp_a[len], &max_len, f) != -1){
        ++len;
        sp_a  [len] = (char*) calloc(max_len, sizeof(char));
    }

    return len;
}


int write(char** sp_a, int len){
    FILE*  fwc = fopen("output/output_canon.txt", "w");
    WriteListToFile(fwc, sp_a, len);
    
    MergeSort((void **)sp_a, len, Compare_Elements, false);
    FILE* fw = fopen("output/output_sorted.txt", "w");
    WriteListToFile(fw, sp_a, len);

    MergeSort((void **)sp_a, len, Compare_Elements, true);
    FILE* fwr = fopen("output/output_sorted_reversed.txt", "w");
    WriteListToFile(fwr, sp_a, len);

    return 0;
}