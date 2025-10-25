#include <stdio.h>
 
int main(void)
{
    int pass_code = 13;
    int enter_code;
    int c;

    do {
        printf("Please enter the secret code: ");
        scanf("%d", &enter_code);
        // Clear the input buffer
        while ((c = getchar()) != '\n' && c != EOF) { 
            // empty loop
        }
    } while(enter_code != pass_code);
 
    printf("Access is allowed\n");
 
    return 0;
}