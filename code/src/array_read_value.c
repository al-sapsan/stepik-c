#include <stdio.h>
 
int main(void) 
{
    short ar[] = {4, 3, 2, 1, 5, 6, 7};
    
    // Print the array using pointer arithmetic
    for(int i = 0; i < sizeof(ar) / sizeof(*ar); ++i)
         printf("%d ", *(ar+i)); 
    
         return 0;
}