/**
 * -------------------------------------
 * @file  fibonacci.c
 * Assignment 2  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */

#include "fibonacci.h"

/**
 *  add your comment
 */
int recursive_fibonacci(int n) {
    if (n <= 1) return n;
    else return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}


/**
 *  add your comment
 */
int iterative_fibonacci(int n)
{
    int a = 0, b = 1, i;

    for (i=1 ; i < n; i++){
        int temp = a + b;
        a = b;
        b = temp;
    }
    if (n==0) b = 0;
    return b;
}

/**
 *  add your comment
 */
int dpbu_fibonacci(int *f, int n) {
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; ++i){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

/**
 *  add your comment
 */
int dptd_fibonacci(int *f, int n) {
    if(n<=1) {
        f[n]=n; 
        return n;
    }
    if (f[n]>0) return f[n];
    else {
        f[n]=dptd_fibonacci(f,n-1)+dptd_fibonacci(f,n-2);
        return f[n];
    }
}
