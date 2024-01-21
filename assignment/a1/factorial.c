/**
 * -------------------------------------
 * @file  factorial.c
 * Assignment 1  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 *
 * ------------------------------------- */
#include "factorial.h"

int factorial(int n) {
    int result = 1;
    for (int i=1; i<=n; ++i){
        result *= i;
    }
    return result;
}