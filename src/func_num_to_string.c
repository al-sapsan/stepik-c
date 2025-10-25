#include <stdio.h>
#include <string.h>

int main ()
{
    int var_i = -123;
    char str_var[10];
/*
    double var_d = 35.7895;
    sprintf(str_var, "%.2f", var_d);*/

    sprintf(str_var, "%d", var_i);

    puts(str_var); // puts(var_d);
}