#include <stdio.h>
int main(){
    int n;
    char *c;
    printf("Enter a number: \n");
    scanf("%d", &n);
    c = n % 2 == 0 ? "even" : "odd";
    printf("%d is %s", n, c );
    return 0;
}