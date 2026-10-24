#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define TAM 100

void lerNome(char s[TAM], int n) {
    do {
        printf("Nome do estudante %d: ", n);
        fgets(s, TAM, stdin);
        s[strcspn(s, "\n")] = '\0';
        if (!s[0]) puts("Nome vazio!");
    } while (!s[0]);
}

double lerNota(int n, int j) {
    double x;
    int ok;
    do {
        printf("Nota %d do estudante %d: ", j + 1, n);
        ok = scanf("%lf", &x);
        while (getchar() != '\n');
        if (ok != 1 || x < 0 || x > 10)
            puts("Nota invalida! Digite de 0 a 10.");
    } while (ok != 1 || x < 0 || x > 10);
    return x;
}

void calcular(double n[MAX][3], double *m, int q) {
    for (int i = 0; i < q; i++)
        m[i] = (n[i][0] + n[i][1] + n[i][2]) / 3.0;
}

int main(void) {
    char nomes[MAX][TAM];
    double n[MAX][3] = {{0}}, soma = 0, maior;
    int q;

    do {
        printf("Quantidade de estudantes (1 a 10): ");
        if (scanf("%d", &q) != 1) q = 0;
        while (getchar() != '\n');
        if (q < 1 || q > MAX) puts("Quantidade invalida!");
    } while (q < 1 || q > MAX);

   double *m = (double *)malloc(q * sizeof(double)); 
if (m == NULL) return 1;
for (int i = 0; i < q; i++) m[i] = 0;

    for (int i = 0; i < q; i++) {
        lerNome(nomes[i], i + 1);
        for (int j = 0; j < 3; j++)
            n[i][j] = lerNota(i + 1, j);
    }

    calcular(n, m, q);
    maior = m[0];

    for (int i = 0; i < q; i++) {
        printf("\n%s: %.1f, %.1f, %.1f | Media: %.2f | %s\n",
            nomes[i], n[i][0], n[i][1], n[i][2], m[i],
            m[i] >= 6 ? "Atingiu a meta" : "Abaixo da meta");

        soma += m[i];
        if (m[i] > maior) maior = m[i];
    }

    printf("\nMedia geral: %.2f\nMaior media: %.2f\n",
           soma / q, maior);

    for (int i = 0; i < q; i++)
        if (m[i] == maior) printf("Maior media: %s\n", nomes[i]);

    free(m);
    return 0;
}
