/**
 * -------------------------------------
 * @file  matrix.c
 * Assignment 2  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 * *
 * ------------------------------------- */

#include <stdio.h>
#include <math.h>
#include "matrix.h"

/**
 *  add your comment
 */
float norm(float *v, int n) {
float temp = 0;
for (int i=0; i<n; ++i)
	temp += v[i]*v[i];
return sqrtf(temp);
}



/**
 *  add your comment
 */
float dot_product(float *v1, float *v2, int n) {
    float result = 0;
    for (int i = 0; i < n; ++i)
        result += v1[i] * v2[i];
    return result;
}


/**
 *  add your comment
 */
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
    for (int i = 0; i < n; i++) {    
        for (int j = 0; j < n; j++) {
            float sum = 0;
            for (int k = 0; k < n; k++)  
                sum += m1[i*n + k] * m2[k*n + j];  
            m3[i*n + j] = sum;      
        }                                              
    }             
}

/**
 *  add your comment
 */
void matrix_multiply_vector(float *m, float *vin, float *vout, int n) {
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < n; j++)  
            sum += m[i*n + j]*vin[j];  
        vout[i] = sum;          
    }                        
}