typedef struct {
    int rows;
    int cols;
    double *value;
} MATRIX;

MATRIX *create(int rows, int cols) {
    if(rows <= 0 || cols <= 0) 
        return NULL;
    
    MATRIX *matrix = (MATRIX *)malloc(sizeof(MATRIX));

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->value = (double *)malloc(rows*cols*sizeof(double));

    for(int i = 0; i < rows*cols; i++)
        matrix->value[i] = 0.0;

    return matrix;
}

#define ELEMENT(matrix, row, col)\
        matrix->value[(col-1)*matrix->rows+(row-1)]

void entry(MATRIX *matrix, int row, int col, double value) {  
    assert(matrix->value);
    ELEMENT(matrix, row, col) = value;
}

void display(MATRIX *matrix) {
    for(int i = 1; i <= matrix->rows; i++) {
        for(int j = 1; j <= matrix->cols; j++)
            printf("% 6.2f ", ELEMENT(matrix, i, j));
        printf("\n");
    }
}

void delete(MATRIX *matrix) {
    assert(matrix->value);
    free(matrix->value);
    free(matrix);
}
