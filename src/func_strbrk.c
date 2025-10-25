#include <stdio.h>
#include <string.h>
 
int main(void) 
{
         char pass[] = "dfdfg90!#$$A";
         char *ptr = strpbrk(pass, "@!#$^&?");
         
         printf("pass = %p\nptr = %p\n", pass, ptr);
         if(ptr != NULL)
                   printf("ptr: %s\n", ptr);
 
         return 0;
}