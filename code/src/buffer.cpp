/* Work with buffer*/
#include <stdio.h>
int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    return 0;
}
/* Work without buffer

#include <conio.h>
#include <stdio.h>
int main()
{
    int c;
    while ((c = _getche()) != '#') //<повторяет введенный символ на консоли
    {
        putchar(c);
    }
    _getch(); //<задержка экрана
    return 0;
}
*/