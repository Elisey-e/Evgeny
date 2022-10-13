#include "functions.hpp"


/*!
\file
\brief Исполняемый файл с библиотечными функциями
*/

int Compare_Strings(const void* el_1, const void* el_2){


    return strcmp(*(char**)el_1, *(char**)el_2);
}

