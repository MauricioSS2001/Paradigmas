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

void imprimir_estudantes(estudante *pont, int qtd_estudantes){
    printf("\n====== Estudantes registrados ======");
    for(int z=0;z<qtd_estudantes;z++){
        printf("\nNome: %s\n", pont[z].nome);
        printf("Idade: %d\n", pont[z].idade);
        printf("Nota: %.2f\n", pont[z].nota);
        printf("Nivel: %s\n\n", pont[z].nivel);
    };
}

void alunos_calouros(estudante *pont, int qtd_estudantes){
    printf("\n====== Estudantes Calouros registrados ======");
    for(int z=0;z<qtd_estudantes;z++){
        if(strcmp(pont[z].nivel,"calouro") == 0){
            printf("\nNome: %s\n", pont[z].nome);
            printf("Idade: %d\n", pont[z].idade);
            printf("Nota: %.2f\n", pont[z].nota);
            printf("Nivel: %s\n\n", pont[z].nivel);
        }
    };
}

void alunos_veteranos(estudante *pont, int qtd_estudantes){
    printf("\n====== Estudantes Veteranos registrados ======");
    for(int z=0;z<qtd_estudantes;z++){
        if(strcmp(pont[z].nivel,"veterano") == 0){
            printf("\nNome: %s\n", pont[z].nome);
            printf("Idade: %d\n", pont[z].idade);
            printf("Nota: %.2f\n", pont[z].nota);
            printf("Nivel: %s\n\n", pont[z].nivel);
        }
    };
}

float media_estudantes(estudante *pont, int qtd_estudantes){
    float total = 0;
    for(int z=0;z<qtd_estudantes;z++){
        total = total + pont[z].nota;
    };
    total = total/qtd_estudantes;
    return total;
}

float media_calouros(estudante *pont, int qtd_estudantes){
    float total_calouros = 0;
    float calouro = 0;
    for(int z=0;z<qtd_estudantes;z++){
        if(strcmp(pont[z].nivel,"calouro") == 0){
          total_calouros = total_calouros + pont[z].nota;
          calouro = calouro + 1;
        }
    };
    total_calouros = total_calouros/calouro;
    return total_calouros;
}

float media_veteranos(estudante *pont, int qtd_estudantes){
    float total_veteranos = 0;
    float veterano = 0;
    for(int z=0;z<qtd_estudantes;z++){
        if(strcmp(pont[z].nivel,"veterano") == 0){
          total_veteranos = total_veteranos + pont[z].nota;
          veterano = veterano + 1;
        }
    };
    total_veteranos = total_veteranos/veterano;
    return total_veteranos;
}

void media_seis(estudante *pont, int qtd_estudantes){
    printf("\n====== Estudantes com nota superior a seis ======");
    for(int z=0;z<qtd_estudantes;z++){
        if(pont[z].nota >= 6.0){
            printf("\nNome: %s\n", pont[z].nome);
            printf("Nota: %.2f\n", pont[z].nota);
        }
    };
}

void media_seis_calouros(estudante *pont, int qtd_estudantes){
    printf("=== Calouros com media superior a seis ===");
    for(int z=0;z<qtd_estudantes;z++){
        if(pont[z].nota >= 6.0 && strcmp(pont[z].nivel,"calouro") == 0){
            printf("\nNome: %s\n", pont[z].nome);
            printf("Nota: %.2f\n", pont[z].nota);
            printf("Nivel: %s\n\n", pont[z].nivel);
        }
    }
}

void media_seis_veteranos(estudante *pont, int qtd_estudantes){
    printf("=== Veteranos com media superior a seis ===");
    for(int z=0;z<qtd_estudantes;z++){
        if(pont[z].nota >= 6.0 && strcmp(pont[z].nivel,"veterano") == 0){
            printf("\nNome: %s\n", pont[z].nome);
            printf("Nota: %.2f\n", pont[z].nota);
            printf("Nivel: %s\n\n", pont[z].nivel);
        }
    }
}

int main()
{
    int qtd_estudantes;
    estudante est; // Criação de vetor para armazenar mais de 1 estudante.
    estudante *pont; // Ponteiro para realizar alocação dinâmica.
    int op_menu;

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
    }

    printf("\n\n=== Menu ===");
    printf("\n1. Imprimir todos alunos");
    printf("\n2. Imprimir calouros");
    printf("\n3. Imprimir veteranos");
    printf("\n4. Calcular media de todos alunos");
    printf("\n5. Calcular media de alunos calouros");
    printf("\n6. Calcular media de alunos veteranos");
    printf("\n7. Alunos com media superior a seis");
    printf("\n8. Alunos calouros com media superior a seis");
    printf("\n9. Alunos veteranos com media superior a seis");
    printf("\nOpcao: ");
    scanf("%d", &op_menu);

    switch(op_menu){
        case 1:
            imprimir_estudantes(pont, qtd_estudantes);
            break;
        case 2:
            alunos_calouros(pont, qtd_estudantes);
            break;
        case 3:
            alunos_veteranos(pont, qtd_estudantes);
            break;
        case 4:
            printf("\nMedia de todos alunos: %.2f", media_estudantes(pont, qtd_estudantes));
            break;
        case 5:
            printf("\nMedia de notas dos alunos calouros: %.2f", media_calouros(pont, qtd_estudantes));
            break;
        case 6:
            printf("\nMedia de notas dos alunos veteranos: %.2f", media_veteranos(pont, qtd_estudantes));
            break;
        case 7:
            media_seis(pont, qtd_estudantes);
            break;
        case 8:
            media_seis_calouros(pont, qtd_estudantes);
            break;
        case 9:
            media_seis_veteranos(pont, qtd_estudantes);
            break;

    };

    return 0;
}
