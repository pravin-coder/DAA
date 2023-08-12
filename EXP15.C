#include <stdio.h>

// Function to add two matrices
void matrixAdd(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void matrixSubtract(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassenMultiply(int A[][2], int B[][2], int C[][2]) {
    if (C == NULL) {
        return;
    }
    
    int P1[2][2], P2[2][2], P3[2][2], P4[2][2], P5[2][2], P6[2][2], P7[2][2];
    
    // Calculating the intermediate matrices
    matrixAdd(A[0], A[1], P1);
    matrixAdd(B[0], B[1], P2);
    matrixAdd(A[0], A[0], P3);
    matrixAdd(B[1], B[1], P4);
    matrixAdd(A[1], A[0], P5);
    matrixSubtract(B[0], B[1], P6);
    matrixSubtract(A[0], A[1], P7);
    
    int T1[2][2], T2[2][2], T3[2][2], T4[2][2];
    
    // Calculating the intermediate result matrices
    strassenMultiply(P1, P2, T1);
    strassenMultiply(P3, B[1], T2);
    strassenMultiply(A[0], P4, T3);
    strassenMultiply(P5, P6, T4);
    
    // Calculating the final result matrices
    matrixAdd(T1, T2, C[0]);
    matrixSubtract(T4, T3, C[1]);
    matrixAdd(T3, T2, C[2]);
    matrixAdd(T1, T4, C[3]);
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2] = {{0}};

    strassenMultiply(A, B, C);

    printf("Resultant matrix after Strassen's multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
