#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

// Funções para criação de matrizes:

Matrix create_matrix(int *data, int n_rows, int n_cols){
    Matrix matriz;

    matriz.data = data;
    matriz.n_rows = n_rows;
    matriz.n_cols = n_cols;
    matriz.stride_rows = n_cols;
    matriz.stride_cols = 1;
    matriz.offset = 0;

    return matriz;
}

Matrix zeros_matrix(int n_rows, int n_cols){
    int *arr = malloc((n_cols * n_rows) * sizeof(int));

    for (int i = 0; i < (n_cols * n_rows); i++){
        arr[i] = 0;
    }

    return create_matrix(arr, n_rows, n_cols);
}

Matrix full_matrix(int n_rows, int n_cols, int value){
    int *arr = malloc((n_cols * n_rows) * sizeof(int));

    for (int i = 0; i < (n_cols * n_rows); i++){
        arr[i] = value;
    }

    return create_matrix(arr, n_rows, n_cols);
}

Matrix i_matrix(int n){
    int *arr = malloc((n * n) * sizeof(int));

    for (int i = 0; i < (n * n); i++){
        if (i % (n + 1) == 0){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }

    return create_matrix(arr, n, n);
}











// Funções para acessar elementos:
 
int get_element(Matrix matrix, int ri, int ci){    
    return matrix.data[(ri * matrix.stride_rows)  + (ci * matrix.stride_cols)];
}

void put_element(Matrix matrix, int ri, int ci, int elem){
    int contagem = 0;
    for (int linha = 0; linha < matrix.n_rows; linha++){
        for (int coluna = 0; coluna < matrix.n_cols; coluna++){
            if (linha == ri && coluna == ci){
                printf("%d ", elem);
            }
            else{
                printf("%d ", matrix.data[contagem]);
                contagem++;
            }
            
        }
        printf("\n");
    }
}

void print_matrix(Matrix matrix){
    int contagem = 0;
    
    for (int linha = 0; linha < matrix.n_rows; linha++){
        for (int coluna = 0; coluna < matrix.n_cols; coluna++){
            printf("%d ", matrix.data[contagem]);
            contagem++;
        }
        printf("\n");
    }
}