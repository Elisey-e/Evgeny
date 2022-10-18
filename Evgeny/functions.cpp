#include "functions.hpp"


/*!
\file
\brief Исполняемый файл с функциями, необходимыми при сортировке
*/


int Compare_Elements(void* el_1, void* el_2, bool reverse){
    assert(el_1 != NULL);
    assert(el_2 != NULL);

    struct params params_main_comp = {};
    char* el_1_c = (char*) el_1;
    char* el_2_c = (char*) el_2;
    
    if (params_main_comp.data_type == STRING){
        if (reverse == false){
            return Compare_Strings(el_1_c, el_2_c);
        }
        else{
            return Reversed_Compare_Strings(el_1_c, el_2_c);
        }
    }
    return 0;
}


int Compare_Strings(char* str1, char* str2){
    struct params params_main_comp = {};
    assert(str1 != NULL);
    assert(str2 != NULL);

    int i1 = 0;
    int i2 = 0;
    int el1, el2;
    while (true){
        while (!isalpha(str1[i1]) && str1[i1] != '\0'){
            i1++;
        }
        while (!isalpha(str2[i2]) && str2[i2] != '\0'){
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

    return params_main_comp.comp_err;
}


int Reversed_Compare_Strings(char* str1, char* str2){
    struct params params_main_comp = {};
    assert(str1 != NULL);
    assert(str2 != NULL);

    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);
    char el1, el2;
    while (true){
        while (!isalpha(str1[len1]) && len1 != -1){
            len1--;
        }
        while (!isalpha(str2[len2]) && len2 != -1){
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

    return params_main_comp.comp_err;
}


void MergeSortImpl(void** values, void** buffer, int l, int r, int (*comp) (void *, void *, bool), bool reverse) {
    assert(values != NULL);
    assert(buffer != NULL);
    assert(comp != NULL);

    if (l < r) {
        int m = (l + r) / 2;
        MergeSortImpl(values, buffer, l, m, comp, reverse);
        MergeSortImpl(values, buffer, m + 1, r, comp, reverse);

        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r; ) {
            if (j > r || (i <= m && comp(values[i], values[j], reverse) < 0)) {
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


void MergeSort(void** sp, int len, int (*comp) (void *, void *, bool), bool reverse) {
    assert(sp != NULL);
    assert(comp != NULL);

    void** buffer = (void**) calloc(len, sizeof(void*));
    assert(buffer != NULL);

    MergeSortImpl(sp, buffer, 0, len - 1, comp, reverse);
}


void WriteListToFile(FILE* file, char** sp, int len){
    assert(file != NULL);
    for (int j = 0; j < len; j++){
        fprintf(file, "%s", sp[j]);
    }
}