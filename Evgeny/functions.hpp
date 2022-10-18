#ifndef EVGENY_H
#define EVGENY_H


#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define ASSERT(cond)\
    do {            \
	    if (!(cond))\
		    printf("\tError in line %d\n\tof the file %s\n\tcondinion (%s) is false\n", __LINE__, __FILE__, #cond);\
    } while(0)


/*!
    \file
    \brief Заголовочный файл с прототипами функций.
*/


/*!
	Структура, содержащая констатны, отвечающие за тип обрабатываемых данных.
*/

enum TYPE_EL
{
    STRING = 0,
    CHAR   = 1,
    INT    = 2,
    DOUBLE = 3,
};

/*!
	Структура, содержащая констатны, отвечающие за варианты обработки данных.
*/

#define TEXT_LEN_DEFAULT 6800
#define STRINGS_COMPARE_ERROR -666

typedef struct params{
    int data_type = STRING;
    int reverse = false;
    int text_len = TEXT_LEN_DEFAULT;
    int comp_err = STRINGS_COMPARE_ERROR;
} PARAMS;

#undef STRINGS_COMPARE_ERROR
#undef TEXT_LEN_DEFAULT

/*!
	\brief Функция, сравнивающая элементы различных типов.
	\param[in] el1 Указатель на первый элемент.
    \param[in] el2 Указатель на второй элемент.
	\return 1 если первый элемент больше, -1 если второй элемент больше, 0 если элементы равны.

    Функция распределяет сравнение 2-х объектов заранее известного типа в множество функций, отвечающих за сравнение элементов фиксированного типа.
*/

int Compare_Elements(void* el_1, void* el_2, bool reverse);


/*!
	\brief Функция, сравнивающая строки.
	\param[in] str1 Указатель на первый элемент.
    \param[in] str2 Указатель на второй элемент.
	\return 1 если первый элемент больше, -1 если второй элемент больше, 0 если элементы равны.

    Функция использует для проверки на принадлежность буквам функцию <is_letter>. 
*/

int Compare_Strings(char* str1, char* str2);


/*!
	\brief Функция, сравнивающая строки с конца.
	\param[in] str1 Указатель на первый элемент.
    \param[in] str2 Указатель на второй элемент.
	\return 1 если первый элемент больше, -1 если второй элемент больше, 0 если элементы равны.

    Функция использует для проверки на принадлежность буквам функцию <is_letter>. Сравнивая строки с конца, мы получаем словарь рифм.
*/

int Reversed_Compare_Strings(char* str1, char* str2);


/*!
	\brief Функция, проверяющая на принадлежность буквам символ.
	\param[in] c Код символа в формате <int>(для анализа юникода и русского текста в частности).
	\return 1 если буква, 0 если нет.

    Функция использует для проверки на принадлежность буквам функцию <is_letter>. Сравнивая строки с конца, мы получаем словарь рифм.
*/

void MergeSortImpl(void** values, void** buffer, int l, int r, int (*comp) (void * v, void * q, bool reverse), bool reverse);


/*!
	\brief Сортировка слиянием.
	\param[in] sp Массив указателей.
    \param[in] len Длина массива.
    \param[in] size_of_el Размер одного элемента массива.

    Инициализатор реккурентной сортировки.
*/

void MergeSort(void** sp, int len, int (*comp) (void * k, void * m, bool reverse), bool reverse);


/*!
	\brief Запись в файл.
	\param[in] file Указатель на файл.
    \param[in] sp Указатель на массив указателей.
    \param[in] len Длина массива.

    Функция, производящая запись элементов массива в файл.
*/

void WriteListToFile(FILE* file, char** sp, int len);


/*!
	\brief Чтение из файла.
    \param[in] sp_a Указатель на массив указателей.
    \param[in] max_len Длина.

    Функция, производящая чтение элементов из файла в массив.
*/

int read(char** sp_a, size_t max_len, int* len);


/*!
	\brief Запись в файл.
    \param[in] sp_a Указатель на массив указателей.
    \param[in] max_len Длина.

    Функция, производящая необходимую сортировку и записывающую результат в файлы.
*/

int write(char** sp_a, int len);


/*!
	\brief Чтение из файла.

    Функция, выделяющая память и создающая необходимые переменные.
*/

char** generate();


#endif