/**
 * -------------------------------------
 * @file  matrix.h
 * Assignment 2  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-01-20
 * *
 * ------------------------------------- */

#ifndef MATRIX_H
#define MATRIX_H
 
float norm(float *v, int n);
float dot_product(float *v1, float *v2, int n);
void matrix_multiply_vector(float *m, float *v1, float *v2, int n);
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n);

#endif