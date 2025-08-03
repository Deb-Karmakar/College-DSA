#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int coeff;
    int expo;
} Term;

void inputPolynomial(Term poly[], int *n) {
    printf("Enter number of non-zero terms: ");
    scanf("%d", n);
    printf("Enter each term as: coefficient exponent\n");
    for (int i = 0; i < *n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].expo);
    }
}

void displayPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        if (i != n - 1)
            printf(" + ");
    }
    printf("\n");
}

int compareExpo(int a, int b) {
    return a > b ? 1 : (a < b ? -1 : 0);
}

void addPolynomials(Term A[], int n1, Term B[], int n2, Term res[], int *n3) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        switch (compareExpo(A[i].expo, B[j].expo)) {
            case 1:
                res[k++] = A[i++];
                break;
            case -1:
                res[k++] = B[j++];
                break;
            case 0:
                res[k].expo = A[i].expo;
                res[k++].coeff = A[i++].coeff + B[j++].coeff;
                break;
        }
    }
    while (i < n1) res[k++] = A[i++];
    while (j < n2) res[k++] = B[j++];
    *n3 = k;
}

void multiplyPolynomials(Term A[], int n1, Term B[], int n2, Term res[], int *n3) {
    Term temp[MAX];
    int k = 0;

    // Multiply each term of A with every term of B
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            temp[k].expo = A[i].expo + B[j].expo;
            temp[k].coeff = A[i].coeff * B[j].coeff;
            k++;
        }
    }

    // Combine like terms in temp[]
    for (int i = 0; i < k; i++) {
        if (temp[i].coeff == 0) continue;
        for (int j = i + 1; j < k; j++) {
            if (temp[i].expo == temp[j].expo) {
                temp[i].coeff += temp[j].coeff;
                temp[j].coeff = 0;
            }
        }
    }

    // Copy non-zero terms to res[]
    int r = 0;
    for (int i = 0; i < k; i++) {
        if (temp[i].coeff != 0)
            res[r++] = temp[i];
    }
    *n3 = r;
}

int main() {
    Term poly1[MAX], poly2[MAX], sum[MAX], product[MAX];
    int n1, n2, nSum, nProduct;

    printf("Polynomial A:\n");
    inputPolynomial(poly1, &n1);
    printf("Polynomial B:\n");
    inputPolynomial(poly2, &n2);

    printf("\nA(x) = ");
    displayPolynomial(poly1, n1);
    printf("B(x) = ");
    displayPolynomial(poly2, n2);

    addPolynomials(poly1, n1, poly2, n2, sum, &nSum);
    printf("\nSum A(x) + B(x) = ");
    displayPolynomial(sum, nSum);

    multiplyPolynomials(poly1, n1, poly2, n2, product, &nProduct);
    printf("Product A(x) * B(x) = ");
    displayPolynomial(product, nProduct);

    return 0;
}
