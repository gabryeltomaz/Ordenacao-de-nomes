#include <stdio.h>
#include <string.h>

#define MAX 50
#define N 5     

void ordenarNomes(char nomes[N][MAX], int n) {
    char temp[MAX];
    int i, j;

    //explicação lexografica pg 256 livro
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) {
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], temp);
            }
        }
    }
}

int main() {
    char nomes[N][MAX];
    int i;

    printf("Digite %d nomes:\n", N);
    for (i = 0; i < N; i++) {
        fgets(nomes[i], MAX, stdin);

        //como isso tira o \0 do final????? pesquisar mais
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    ordenarNomes(nomes, N);

    for (i = 0; i < N; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
