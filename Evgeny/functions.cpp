#include "functions.hpp"


/*!
\file
\brief Исполняемый файл с функциями, необходимыми при сортировке
*/



int is_letter(int c){
    return 'a' <= c && c <= 'z' || c <= 0 || 'A' <= c && c <= 'Z';
}


int Compare_Elements(const void* el_1, const void* el_2){
    extern int reversed;
    struct params params_main_comp;
    struct type_el type_el_comp;
    
    
    if (params_main_comp.data_type == type_el_comp.STRING){
        if (reversed == false){
            return Compare_Strings(*(char**)el_1, *(char**)el_2);
        }
        else{
            return Reversed_Compare_Strings(*(char**)el_1, *(char**)el_2);
        }
    }
    return 0;
}


int Compare_Strings(char* str1, char* str2){
    int i1 = 0;
    int i2 = 0;
    int el1, el2;
    while (true){
        while (!is_letter(str1[i1]) && str1[i1] != '\0'){
            i1++;
        }
        while (!is_letter(str2[i2]) && str2[i2] != '\0'){
            i2++;
        }
        el1 = str1[i1];
        el2 = str2[i2];

        if (el1 == '\0' && el2 == '\0'){
            return 0;
        }
        else if (el1 == '\0'){
            return -1;
        }
        else if (el2 == '\0'){
            return 1;
        }


        if (el1 > el2){
            return 1;
        }
        else if (el2 > el1){
            return -1;
        }
        ++i1;
        ++i2;
    }
}


int Reversed_Compare_Strings(char* str1, char* str2){
    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);
    char el1, el2;
    while (true){
        while (!is_letter(str1[len1]) && len1 != -1){
            len1--;
        }
        while (!is_letter(str2[len2]) && len2 != -1){
            len2--;
        }
        el1 = str1[len1];
        el2 = str2[len2];
        if (len1 == -1 && len2 == -1){
            return 0;
        }
        else if (len1 == -1){
            return -1;
        }
        else if (len2 == -1){
            return 1;
        }
        else if (el1 > el2){
            return 1;
        }
        else if (el1 < el2){
            return -1;
        }
        else{
            --len1;
            --len2;
        }
    }
}


void MergeSortImpl(char** values, char** buffer, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSortImpl(values, buffer, l, m);
        MergeSortImpl(values, buffer, m + 1, r);

        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r; ) {
            if (j > r || (i <= m && Compare_Strings(values[i], values[j]) < 0)) {
                buffer[k] = values[i];
                ++i;
            }
            else {
                buffer[k] = values[j];
                ++j;
            }
            ++k;
        }
        for (int i = l; i <= r; ++i) {
            values[i] = buffer[i];
        }
    }
}

void MergeSort(char** sp, int len, int size_of_el) {
    char* buffer[len] = {};
    MergeSortImpl(sp, buffer, 0, len - 1);
}