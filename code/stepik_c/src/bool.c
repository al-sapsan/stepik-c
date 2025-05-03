#include <stdio.h>
#include <stdbool.h>
 
int main(void)
{
    double x = 5.67;
    int var_i = 7;
 
    bool fl_view = x < 10;      // true
    bool res_1 = 5 > 7;         // false
    bool res_2 = x+2 >= 10.56;    // false
    bool res_3 = var_i == 7;    // true
    bool res_4 = var_i != 7;    // false
 
    return 0;
}
