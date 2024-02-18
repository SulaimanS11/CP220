/**
 * -------------------------------------
 * @file  bigint.c
 * Assignment #5  Header File
 * -------------------------------------
 * @author Mir Sulaiman Sultan, 169042271, sult2271@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * ------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') {// just "0"
    dll_insert_end(&bn, new_node(*p -'0'));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        dll_insert_end(&bn, new_node(*p -'0'));
      } else {
        dll_clean(&bn);
        break;
      }
      p++;
    }
    return bn;
  }
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
// your code
}

BIGINT bigint_fibonacci(int n) {
// your code
}