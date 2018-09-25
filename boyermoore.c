#include <string.h>
#include "boyermoore.h"

/*
 * @badcharrule
 *   Return шаги вперед по правилу bad char:
 *     - Если этот символ находился в строке поиска, верните
 *       (смещение - x)
 *     - Если этот символ не находится в строке поиска,
 *       return (offset - (-1))
 *
 * @pSearch:
 *   Строка поиска
 * @badchar:
 *   Плохой символ в исходной строке, который не соответствует
 * строке поиска
 * offset:
 *   Текущее смещение * pSearch
 *
 * return:
 *   Вернуть шаг текущего смещения -
 */
static int badcharrule(const char *pSearch, const char badchar, const int offset)
{
    for (int index = offset - 1; index > -1; --index) {
        if (pSearch[index] == badchar)
            return (offset - index);
    }

    return (offset - (-1));
}

/*
 * @displaycurstate
 *   Отображение текущего хода поиска
 * @pSrc:
 *   Исходная строка
 * @pSearch:
 *   Строка поиска
 * @offset:
 *   Текущее смещение * pSrc
 */
static void displaycurstate(const char *pSrc, const char *pSearch, const int offset)
{
    printf("%s\n", pSrc);

    for (int i = 0; i < (offset - (strlen(pSearch) - 1)); ++i)
        printf("-");

    printf("%s\n\n", pSearch);

    return;
}

/*
 * @strfind
 *   Поиск подстроки из исходной строки с помощью алгоритма BoyerMoore
 *
 * @pSrc
 *   Исходная строка
 * @pSearch
 *   Строка поиска, найдите эту строку из * pSrc
 *
 * @return
 *   Return -1, если * pSearch не найден, иначе вернуть индекс, который
 * найден по адресу
 */
int strfind(const char *pSrc, const char *pSearch)
{
    int srcEndOffset = strlen(pSrc) - 1;    // Конец смещения *pSrc
    int seaEndOffset = strlen(pSearch) - 1; // Конец смещения *pSearch
    int srcCurOffset = seaEndOffset;        // Текущее смещение *pSrc
    int seaCurOffset = seaEndOffset;        // Текущее смещение *pSearch

    int srcStartIndex 	= -1; // Индекс начального совпадения каждого поиска
    int step;                 // Шагам необходимо переслать строку поиска

    while (srcCurOffset <= srcEndOffset) {
        srcStartIndex = srcCurOffset;

        displaycurstate(pSrc, pSearch, srcCurOffset);

        while (seaCurOffset > -1) {
            // Соответствие текущему символу
            if (pSearch[seaCurOffset] == pSrc[srcCurOffset]) {
                if (seaCurOffset == 0)
                    return srcCurOffset;

                --srcCurOffset; // Смещение *pSrc текущего смещение
                --seaCurOffset; // Смещение *pSearch текущего смещения
            } else {
                // Сгенерировать шаги, необходимые для пересылки
                step = badcharrule(pSearch, pSrc[srcCurOffset], seaCurOffset);

                srcCurOffset = srcStartIndex + step; // Шаг вперед
                seaCurOffset = seaEndOffset; // Сбросить текущее смещение * pSearch

                break;
            }
        }
    }

    return -1;
}
