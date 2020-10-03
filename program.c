#include<stdio.h>//include library
long int multiplyNumbers(int n);
int main() {
    int n;
    printf("Enter a positive integer: ");//print text for help user
    scanf("%d",&n);//input number to variable n
    printf("Factorial of %d = %ld", n, multiplyNumbers(n));//print output
    return 0;
}
//function
long int multiplyNumbers(int n) {
    if (n>=1)//to exclude 0
        return n*multiplyNumbers(n-1);
    else
        return 1;
}
