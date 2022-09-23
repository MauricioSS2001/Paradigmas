#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para armazenar atributos do estudante.
typedef struct {
    char nome[30];
    int idade;
    float nota;
    char nivel[10];

} estudante;

int main()
{
    int qtd_estudantes;
    estudante est; // Criação de vetor para armazenar mais de 1 estudante.
    estudante *pont; // Ponteiro para realizar alocação dinâmica.

    printf("Digite quantos estudantes deseja registrar: ");
    scanf("%d", &qtd_estudantes);
    pont = malloc(qtd_estudantes*sizeof(est)); // Alocação dinâmica de memória.

    for(int x=0; x<qtd_estudantes; x++){
        printf("Digite o nome do estudante: ");
        scanf("%s", &pont[x].nome);
        printf("Digite a idade do estudante: ");
        scanf("%d", &pont[x].idade);
        printf("Digite a nota do aluno de maneira decimal: ");
        scanf("%f", &pont[x].nota);
        printf("Digite o nivel do aluno: ");
        scanf("%s", &pont[x].nivel);
        printf("\n");
        if(x == qtd_estudantes){
            break;
        }
    };

    printf("\n====== Estudantes registrados ======");
    for(int z=0;z<qtd_estudantes;z++){
        printf("\nNome: %s\n", pont[z].nome);
        printf("Idade: %d\n", pont[z].idade);
        printf("Nota: %.2f\n", pont[z].nota);
        printf("Nivel: %s\n\n", pont[z].nivel);
    };

    return 0;
}
