#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <stdio.h>

/*
 * @strfind
 *   Строка поиска из исходной строки с помощью алгоритма BoyerMoore
 *
 * @pSrc
 *   Исходная строка
 * @pSearch
 *   Строка поиска, найденная из исходной строки * pSrc
 *
 * @return
 *   Return -1, если *pSearch не найден, else return индекс, который найден по адресу
 */
int strfind(const char *pSrc, const char *pSearch);

#endif /* End of _MYSTRING_H_ */

