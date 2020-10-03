#include<stdio.h>
long int multiplyNumbers(int n);
int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d",&n);
    printf("Factorial of %d = %ld", n, multiplyNumbers(n));
    return 0;
}

long int multiplyNumbers(int n) {
    if(n==0)
        return 1;
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else   
	printf("you entered something wrong\n") ;       
}
