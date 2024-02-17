/**
 * -------------------------------------
 * @file  mysort.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * ------------------------------------- */
 #include <stdio.h>
 #include "mysort.h"
 
 
 void select_sort_inc(float *a[], int left, int right) {

    for (int i = left; i < right - 1; i++) {
        int min = i;

        for (int j = i + 1; j < right; j++) {
            if (*a[j] < *a[min]) {
                float *temp = a[min];
                a[min] = a[j];
                a[j] = temp;
            }
        }
    }
}



void quick_sort(float *a[], int left, int right) {
    int i, j;
    float key;
    if (left < right) {
        key = *a[left];
        i = left + 1;
        j = right;
        while (i <= j) {
            while (i <= right && *a[i] <= key)
                i++;
            while (j >= left && *a[j] > key)
                j--;
            if (i < j) {
                float *temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        float *temp = a[left];
        a[left] = a[j];
        a[j] = temp;
        quick_sort(a, left, j - 1);
        quick_sort(a, j + 1, right);
    }
}