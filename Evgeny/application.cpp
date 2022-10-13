#include "functions.hpp"


/*!
\file
\brief Главный файл проекта с функцией main, по умолчанию проверяет корректность работы функций библиотеки
\authors Zhdanov_EA
*/


int main ()
{
    size_t max_len = 255;

    char* sp_a[6300]  = {};

    sp_a[0] = (char*) calloc(max_len, sizeof(char));

    FILE* f = fopen("input/input.txt", "r");
    int len = 0;

    while (getline(&sp_a[len], &max_len, f) != -1){
        ++len;

        sp_a[len] = (char*) calloc(max_len, sizeof(char));
    }
    qsort(sp_a, len, sizeof(char*), Compare_Strings);

    for (int j = 0; j < len; j++){
        printf("%s", sp_a[j]);
    }

    FILE* fw = fopen("output/output.txt", "w");

    for (int j = 0; j < len; j++){
        fprintf(fw, sp_a[j]);
    }

    return 0;
}
