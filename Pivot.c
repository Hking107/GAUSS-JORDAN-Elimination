#include <stdio.h>
#include <math.h>

/* GAUSS-JORDAN Elimination*/
/* Reduced Echelon form of an n ordered Matrix */
void swap(float *a, float *b){
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void divide_row(int n , float A[n][n], int row, float divisor){
    for(int j = 0; j < n; j++){
        A[row][j] /= divisor;
    }
}

void swap_rows(int n, float A[n][n], int row1, int row2){
    for(int j = 0; j < n; j++){
        swap(&A[row1][j], &A[row2][j]);
    }
}

int max_in_column(int n, float A[n][n], int starting_row, int column){
    
    int max = 0;
    for(int i = starting_row ; i < n; i++){
        if(fabs(A[i][column]) > fabs(A[max][column])){
            max = i;
        }
    }
    return max;
}

void print(int n, float A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.0f ", A[i][j]);
        }
        printf("\n");
    }
}

void scan(int n, float A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Entree la valeur avec coordonee (%d, %d): \n>>", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
}

int main(){
    int n;

    printf("Entree l'ordre de la matrice: ");
    scanf("%d", &n);

    float A[n][n];

    scan(n, A);

    
    printf("Avant echelonage: \n");
    print(n, A);

    int r = -1;

    for(int j = 0; j < n; j++){
        int k = max_in_column(n, A, r+1, j);
        int pivot = A[k][j];
        
        if (pivot != 0){
            r++;
            divide_row(n, A, k, pivot);

            if(k != r){
                swap_rows(n, A, k, r);
            }
            
            for(int i = 0; i < n; i++){
                if(i != r){
                    for(int c = 0; c < n; c++){
                        A[i][c] -= A[r][c]*A[i][j];
                    }
                }
            } 
        }
    }

    printf("\nApres echelonage: \n");
    print(n, A);

    return 0;
}
