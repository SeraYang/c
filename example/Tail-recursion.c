/*
 * Recursive procedures call themselves to work towards a solution to a problem. In simple implementations this balloons the stack as the nesting gets deeper and deeper, reaches the solution, then returns through all of the stack frames. This waste is a common complaint about recursive programming in general.A function call is said to be tail recursive if there is nothing to do after the function returns except return its value. Since the current recursive instance is done executing at that point, saving its stack frame is a waste. Specifically, creating a new stack frame on top of the current, finished, frame is a waste. A compiler is said to implement TailRecursion if it recognizes this case and replaces the caller in place with the callee, so that instead of nesting the stack deeper, the current stack frame is reused. This is equivalent in effect to a "GoTo", and lets a programmer write recursive definitions without worrying about space inefficiency (from this cause) during execution. TailRecursion is then as efficient as iteration normally is.
The term TailCallOptimization is sometimes used to describe the generalization of this transformation to non-recursive TailCall?s. The best-known example of a language that does this is the SchemeLanguage, which is required to support ProperTailCalls. Recursion is the basic iteration mechanism in Scheme.
*/
#include <stdio.h>

int factorial(int);
int factorial1(int);
int fac(int,int);

main(){
    int n = 20;
    int x = factorial(n);
    int y = factorial1(n);

    printf("%d \n",x);
    printf("%d \n",y);
}

int factorial(int n){   // this is NOT tail-recursion.
    if(n == 0) return 1;
    return n * factorial(n-1);
}
/* Below is tail-recursion */
int factorial1(int n){
    return fac(n,1);
}

int fac(int n,int accumulator){
    if(n == 0) return accumulator;
    return fac(n - 1, n * accumulator);
}
