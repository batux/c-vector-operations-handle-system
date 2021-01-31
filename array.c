/*
* Batuhan Düzgün - 31.01.2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

ARRAY* InitArray(size_t size, BOOL exit_flag)
{
    ARRAY* pdArray;

    if ((pdArray = (ARRAY*)malloc(sizeof(ARRAY))) == NULL)
    {
        if (exit_flag)
        {
            printf(stderr, "ARRAY create process failed!\n");
            exit(EXIT_FAILURE);
        }
        return NULL;
    }

    if ((pdArray->pdArray = (DATATYPE*)malloc(size * sizeof(DATATYPE))) == NULL)
    {
        free(pdArray);
        printf(stderr, "ARRAY create process failed!\n");
        exit(EXIT_FAILURE);
    }
    pdArray->size = size;
    return pdArray;
}

HARRAY CreateArray(size_t size)
{
    ARRAY* pdArray;
    pdArray = InitArray(size, TRUE);
    return pdArray;
}

HARRAY CreateArrayWithZero(size_t size)
{
    int i;
    ARRAY* pdArray;
    pdArray = InitArray(size, TRUE);

    for (i = 0; i < size; i++)
    {
        pdArray->pdArray[i] = 0;
    }
    return pdArray;
}

HARRAY CreateArrayWithValue(const double* pdSource, size_t size)
{
    int i;
    ARRAY* pdArray;
    pdArray = InitArray(size, TRUE);

    for (i = 0; i < size; i++)
    {
        pdArray->pdArray[i] = pdSource[i];
    }
    return pdArray;
}

void CloseArray(HARRAY hArray)
{
    if (hArray == NULL)
    {
        return;
    }

    ARRAY* pdArray = (ARRAY*)hArray;
    free(pdArray->pdArray);
    free(pdArray);
}

void PrintArray(const char* opText, HARRAY hArray)
{
    if(hArray == NULL)
    {
        printf("NULL array can not be displayed!\n");
        return;
    }

    int i;
    ARRAY* pdArray = (ARRAY*)hArray;

    printf("%s Array\n", opText);
    for (i = 0; i < pdArray->size; i++)
    {
        printf("%0.4lf ", pdArray->pdArray[i]);
    }
    printf("\n");
}

HARRAY SinArray(HARRAY hArray)
{
    int i;
    ARRAY* pdArray = (ARRAY*)hArray;
    ARRAY* pdSinArray;

    if ( (pdSinArray = InitArray(pdArray->size, FALSE)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < pdArray->size; i++)
    {
        pdSinArray->pdArray[i] = sin(pdArray->pdArray[i]);
    }

    return pdSinArray;
}

HARRAY CosArray(HARRAY hArray)
{
    int i;
    ARRAY* pdArray = (ARRAY*)hArray;
    ARRAY* pdCosArray;

    if ((pdCosArray = InitArray(pdArray->size, FALSE)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < pdArray->size; i++)
    {
        pdCosArray->pdArray[i] = cos(pdArray->pdArray[i]);
    }

    return pdCosArray;
}

HARRAY TanArray(HARRAY hArray)
{
    int i;
    ARRAY* pdArray = (ARRAY*)hArray;
    ARRAY* pdTanArray;

    if ((pdTanArray = InitArray(pdArray->size, FALSE)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < pdArray->size; i++)
    {
        pdTanArray->pdArray[i] = tan(pdArray->pdArray[i]);
    }

    return pdTanArray;
}

HARRAY SqrtArray(HARRAY hArray)
{
    int i;
    ARRAY* pdArray = (ARRAY*)hArray;
    ARRAY* pdSqrtArray;

    if ((pdSqrtArray = InitArray(pdArray->size, FALSE)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < pdArray->size; i++)
    {
        pdSqrtArray->pdArray[i] = sqrt(pdArray->pdArray[i]);
    }

    return pdSqrtArray;
}

HARRAY LogArray(HARRAY hArray)
{
    int i;
    ARRAY* pdArray = (ARRAY*)hArray;
    ARRAY* pdLogArray;

    if ((pdLogArray = InitArray(pdArray->size, FALSE)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < pdArray->size; i++)
    {
        pdLogArray->pdArray[i] = log(pdArray->pdArray[i]);
    }

    return pdLogArray;
}

HARRAY PowArray(HARRAY hArray, double y)
{
    int i;
    ARRAY* pdArray = (ARRAY*)hArray;
    ARRAY* pdPowArray;

    if ((pdPowArray = InitArray(pdArray->size, FALSE)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < pdArray->size; i++)
    {
        pdPowArray->pdArray[i] = pow(pdArray->pdArray[i], y);
    }

    return pdPowArray;
}

HARRAY PerformVectorOperation(HARRAY hArray1, HARRAY hArray2, char op)
{
    int i, j;
    ARRAY* smallSizeArr = NULL;
    ARRAY* largeSizeArr = NULL;
    ARRAY* pdArray1 = (ARRAY*)hArray1;
    ARRAY* pdArray2 = (ARRAY*)hArray2;
    ARRAY* pdResArray;

    largeSizeArr = pdArray1;
    smallSizeArr = pdArray2;

    if (pdArray2->size > pdArray1->size)
    {
        largeSizeArr = pdArray2;
        smallSizeArr = pdArray1;
    }

    if ((pdResArray = InitArray(largeSizeArr->size, FALSE)) == NULL)
    {
        return NULL;
    }

    if (smallSizeArr == NULL || largeSizeArr == NULL)
    {
        return NULL;
    }

    j = 0;
    while (j < pdResArray->size)
    {
        for (i = 0; (i < smallSizeArr->size && j < pdResArray->size); i++)
        {
            if (op == 'a')
            {
                pdResArray->pdArray[j] = largeSizeArr->pdArray[j] + smallSizeArr->pdArray[i];
            }
            else if (op == 's')
            {
                pdResArray->pdArray[j] = largeSizeArr->pdArray[j] - smallSizeArr->pdArray[i];
            }
            else if (op == 'm')
            {
                pdResArray->pdArray[j] = largeSizeArr->pdArray[j] * smallSizeArr->pdArray[i];
            }
            else if (op == 'd')
            {
                if (smallSizeArr->pdArray[i] == 0)
                {
                    pdResArray->pdArray[j] = 0;
                }
                else
                {
                    pdResArray->pdArray[j] = largeSizeArr->pdArray[j] / smallSizeArr->pdArray[i];
                }
            }
            j++;
        }
    }
    return pdResArray;
}

HARRAY AddArray(HARRAY hArray1, HARRAY hArray2)
{
    return PerformVectorOperation(hArray1, hArray2, 'a');
}

HARRAY SubArray(HARRAY hArray1, HARRAY hArray2)
{
    return PerformVectorOperation(hArray1, hArray2, 's');
}

HARRAY DivArray(HARRAY hArray1, HARRAY hArray2)
{
    return PerformVectorOperation(hArray1, hArray2, 'd');
}

HARRAY MulArray(HARRAY hArray1, HARRAY hArray2)
{
    return PerformVectorOperation(hArray1, hArray2, 'm');
}
