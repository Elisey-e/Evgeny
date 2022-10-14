#ifndef SQUARESOLVER_H
#define SQUARESOLVER_H


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

typedef struct type_el{
    int STRING = 1;
    int CHAR = 2;
    int INT = 3;
    int DOUBLE = 4;
} TYPE_EL;


/*!
	Структура, содержащая констатны, отвечающие за варианты обработки данных.
*/

typedef struct params{
    struct type_el el_all;
    int data_type = el_all.STRING;
    int reverse = false;
    int text_len = 6300;
} PARAMS;


/*!
	\brief Функция, сравнивающая элементы различных типов.
	\param[in] el1 Указатель на первый элемент.
    \param[in] el2 Указатель на второй элемент.
	\return 1 если первый элемент больше, -1 если второй элемент больше, 0 если элементы равны.

    Функция распределяет сравнение 2-х объектов заранее известного типа в множество функций, отвечающих за сравнение элементов фиксированного типа.
*/

int Compare_Elements(const void* el_1, const void* el_2);


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

int is_letter(int c);


/*!
	\brief Сортировка слиянием.
	\param[in] values Массив указателей.
    \param[in] buffer Буфер для хранения подмассивов.
    \param[in] l Левая граница сортировки.
    \param[in] r правая граница сортировки.

    Функция реккурентная, поэтому она вынесена отдельно от инициализации сортировки.
*/

void MergeSortImpl(char** values, char** buffer, int l, int r);


/*!
	\brief Сортировка слиянием.
	\param[in] sp Массив указателей.
    \param[in] len Длина массива.
    \param[in] size_of_el Размер одного элемента массива.

    Инициализатор реккурентной сортировки.
*/

void MergeSort(char** sp, int len, int size_of_el);

#endif