/**
 * -------------------------------------
 * @file  myrecord.c
 * Assignment #  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * ------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score) {
    GRADE result;

    if (score >= 90) {
        strcpy(result.letter_grade, "A+");
    } else if (score >= 85) {
        strcpy(result.letter_grade, "A");
    } else if (score >= 80) {
        strcpy(result.letter_grade, "A-");
    } else if (score >= 77) {
        strcpy(result.letter_grade, "B+");
    } else if (score >= 73) {
        strcpy(result.letter_grade, "B");
    } else if (score >= 70) {
        strcpy(result.letter_grade, "B-");
    } else if (score >= 67) {
        strcpy(result.letter_grade, "C+");
    } else if (score >= 63) {
        strcpy(result.letter_grade, "C");
    } else if (score >= 60) {
        strcpy(result.letter_grade, "C-");
    } else if (score >= 57) {
        strcpy(result.letter_grade, "D+");
    } else if (score >= 53) {
        strcpy(result.letter_grade, "D");
    } else if (score >= 50) {
        strcpy(result.letter_grade, "D-");
    } else {
        strcpy(result.letter_grade, "F");
    }

    return result;
}


STATS process_data(RECORD *dataset, int count) {    
// your code
}

int import_data(FILE *fp, RECORD *dataset) {
// your code
}

int report_data(FILE *fp, RECORD *dataset, int count) {
// your code
}