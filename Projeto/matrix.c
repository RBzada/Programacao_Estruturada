#include <stdio.h>
#include "matrix.h"

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

void print_matrix(Matrix matrix){
    int dados[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int contagem = 0;
    matrix.data = dados;
    matrix.n_cols = 3;
    matrix.n_rows = 3;
    
    for (int linha = 0; linha < 3; linha++){
        for (int coluna = 0; coluna < 3; coluna++){
            printf("%d ", matrix.data[contagem]);
            contagem++;
        }

        printf("\n");
    }
}
