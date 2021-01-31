/*
* Batuhan Düzgün - 31.01.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

int main(void)
{
    int d1_size;
    int d2_size;
    double tmpArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double d1[] = { 1, 2, 3, 4, 5 };
    double d2[] = { 10, 20, 30 };
    HARRAY hArray, hArray1, hArray2;
    HARRAY hResArray;
    size_t size = 10;


    d1_size = sizeof(d1) / sizeof(d1[0]);
    d2_size = sizeof(d2) / sizeof(d2[0]);

    /* Init source array */
    hArray = CreateArray(size);
    PrintArray("Empty", hArray);

    hArray = CreateArrayWithZero(size);
    PrintArray("Zero-Base", hArray);

    hArray = CreateArrayWithValue(tmpArray, size);
    PrintArray("Initialized", hArray);

    /* Math operations of the vector */
    hResArray = SinArray(hArray);
    PrintArray("Sin", hResArray);
    CloseArray(hResArray);

    hResArray = CosArray(hArray);
    PrintArray("Cos", hResArray);
    CloseArray(hResArray);
    
    hResArray = TanArray(hArray);
    PrintArray("Tan", hResArray);
    CloseArray(hResArray);

    hResArray = SqrtArray(hArray);
    PrintArray("Sqrt", hResArray);
    CloseArray(hResArray);

    hResArray = LogArray(hArray);
    PrintArray("Log", hResArray);
    CloseArray(hResArray);

    hResArray = PowArray(hArray, 2);
    PrintArray("Pow", hResArray);
    CloseArray(hResArray);

    hArray1 = CreateArrayWithValue(d1, d1_size);
    hArray2 = CreateArrayWithValue(d2, d2_size);

    /* Summation of two vectors */
    hResArray = AddArray(hArray1, hArray2);
    PrintArray("Sum", hResArray);
    CloseArray(hResArray);

    /* Subsraction of two vectors */
    hResArray = SubArray(hArray1, hArray2);
    PrintArray("Sub", hResArray);
    CloseArray(hResArray);

    /* Multiplication of two vectors */
    hResArray = MulArray(hArray1, hArray2);
    PrintArray("Mul", hResArray);
    CloseArray(hResArray);

    /* Division of two vectors */
    hResArray = DivArray(hArray1, hArray2);
    PrintArray("Div", hResArray);
    CloseArray(hResArray);

    CloseArray(hArray);

    return 0;
}
