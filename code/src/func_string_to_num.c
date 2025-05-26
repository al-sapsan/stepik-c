#include <stdio.h>
#include <stdlib.h>
 
int main(void) 
{
         int a = atoi("123");
         long b = atol("234235354");
         long long c = atoll("23423535456456");
         double d = atof("4564.4545");
 
         printf("a = %d\nb = %ld\nc = %lld\nd = %f\n", a, b, c, d);
 
         return 0;
}