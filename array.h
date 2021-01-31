/*
* Batuhan Düzgün - 31.01.2021
*/

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>

/* Constant Declarations */

#define TRUE    1
#define FALSE   0

/* Type Declarations */

typedef int BOOL;
typedef double DATATYPE;

typedef struct tagARRAY {
    DATATYPE *pdArray;      /* Starting point address of array */
    size_t size;            /* Array size */
} ARRAY;

typedef void* HARRAY;

/* Function Prototypes */
HARRAY CreateArray(size_t size);
HARRAY CreateArrayWithZero(size_t size);
HARRAY CreateArrayWithValue(const double* pdSource, size_t size);

void CloseArray(HARRAY hArray);


HARRAY SinArray(HARRAY hArray);
HARRAY CosArray(HARRAY hArray);
HARRAY TanArray(HARRAY hArray);
HARRAY SqrtArray(HARRAY hArray);
HARRAY LogArray(HARRAY hArray);
HARRAY PowArray(HARRAY hArray, double y);

HARRAY AddArray(HARRAY hArray1, HARRAY hArray2);
HARRAY SubArray(HARRAY hArray1, HARRAY hArray2);
HARRAY DivArray(HARRAY hArray1, HARRAY hArray2);
HARRAY MulArray(HARRAY hArray1, HARRAY hArray2);

void PrintArray(const char *opText, HARRAY hArray);

#endif
