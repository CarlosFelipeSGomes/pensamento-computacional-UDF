#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_HIST 50

typedef struct {
    char tipo[30];
    double a, b;
    double resultado;
    int id;
} Operacao;

Operacao historico[MAX_HIST];
int contador = 0;

// Variáveis globais
double num1, num2, resultado;

// ------------------------------------------------
// Função: Adiciona operação ao histórico
// ------------------------------------------------
void registrarOperacao(char tipo[], double a, double b, double resultado) {
    if (contador < MAX_HIST) {
        strcpy(historico[contador].tipo, tipo);
        historico[contador].a = a;
        historico[contador].b = b;
        historico[contador].resultado = resultado;
        historico[contador].id = contador + 1;
        contador++;
    } else {
        printf("Histórico cheio! Limpe ou salve em arquivo.\n");
    }
}

// ------------------------------------------------
// Função: Exibe o histórico de operações
// ------------------------------------------------
void mostrarHistorico() {
    printf("\n------ Histórico de Operações ------\n");
    for (int i = 0; i < contador; i++) {
        printf("ID %d | %-15s | a=%.2lf | b=%.2lf | Resultado=%.2lf\n",
               historico[i].id, historico[i].tipo, historico[i].a, historico[i].b, historico[i].resultado);
    }
    if (contador == 0)
        printf("Nenhuma operação registrada.\n");
}

// ------------------------------------------------
// Função: Salva o histórico em arquivo texto
// ------------------------------------------------
void salvarHistorico() {
    FILE *f = fopen("historico.txt", "w");
    if (!f) {
        printf("Erro ao criar arquivo!\n");
        return;
    }

    fprintf(f, "ID,Tipo,A,B,Resultado\n");
    for (int i = 0; i < contador; i++) {
        fprintf(f, "%d,%s,%.2lf,%.2lf,%.2lf\n",
                historico[i].id, historico[i].tipo, historico[i].a, historico[i].b, historico[i].resultado);
    }

    fclose(f);
    printf("Histórico salvo em 'historico.txt'.\n");
}

// ------------------------------------------------
// Funções de Operações Básicas
// ------------------------------------------------
void somar() {
    printf("Digite dois numeros: ");
    scanf("%lf %lf", &num1, &num2);
    resultado = num1 + num2;
    printf("Resultado: %.2lf\n", resultado);
    registrarOperacao("Soma", num1, num2, resultado);
}

void subtrair() {
    printf("Digite dois numeros: ");
    scanf("%lf %lf", &num1, &num2);
    resultado = num1 - num2;
    printf("Resultado: %.2lf\n", resultado);
    registrarOperacao("Subtracao", num1, num2, resultado);
}

void multiplicar() {
    printf("Digite dois numeros: ");
    scanf("%lf %lf", &num1, &num2);
    resultado = num1 * num2;
    printf("Resultado: %.2lf\n", resultado);
    registrarOperacao("Multiplicacao", num1, num2, resultado);
}

void divisao() {
    printf("Digite dois numeros: ");
    scanf("%lf %lf", &num1, &num2);
    if (num2 == 0)
        printf("Erro: divisao por zero!\n");
    else {
        resultado = num1 / num2;
        printf("Resultado: %.2lf\n", resultado);
        registrarOperacao("Divisao", num1, num2, resultado);
    }
}

// ------------------------------------------------
// Funções Matemáticas Adicionais
// ------------------------------------------------
void potencia() {
    printf("Digite base e expoente: ");
    scanf("%lf %lf", &num1, &num2);
    resultado = pow(num1, num2);
    printf("Resultado: %.2lf\n", resultado);
    registrarOperacao("Potencia", num1, num2, resultado);
}

void raiz() {
    printf("Digite um numero: ");
    scanf("%lf", &num1);
    if (num1 < 0)
        printf("Erro: raiz negativa!\n");
    else {
        resultado = sqrt(num1);
        printf("Resultado: %.2lf\n", resultado);
        registrarOperacao("Raiz", num1, 0, resultado);
    }
}

void fatorial() {
    int n;
    printf("Digite um inteiro positivo (max 20): ");
    scanf("%d", &n);
    if (n < 0 || n > 20)
        printf("Erro: fora do limite!\n");
    else {
        long long fat = 1;
        for (int i = 1; i <= n; i++)
            fat *= i;
        printf("Resultado: %lld\n", fat);
        registrarOperacao("Fatorial", n, 0, fat);
    }
}

void media() {
    double soma = 0;
    int n;
    printf("Quantos valores? ");
    scanf("%d", &n);
    double v[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
        soma += v[i];
    }
    resultado = soma / n;
    printf("Media = %.2lf\n", resultado);
    registrarOperacao("Media", n, 0, resultado);
}

void mediana() {
    int n;
    printf("Quantos valores? ");
    scanf("%d", &n);
    double v[n];
    for (int i = 0; i < n; i++)
        scanf("%lf", &v[i]);

    // ordena
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j]) {
                double tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }

    if (n % 2 == 0)
        resultado = (v[n/2 - 1] + v[n/2]) / 2.0;
    else
        resultado = v[n/2];

    printf("Mediana = %.2lf\n", resultado);
    registrarOperacao("Mediana", n, 0, resultado);
}

void desvioPadrao() {
    int n;
    printf("Quantos valores? ");
    scanf("%d", &n);
    double v[n], soma = 0, media = 0, soma2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
        soma += v[i];
    }
    media = soma / n;
    for (int i = 0; i < n; i++)
        soma2 += pow(v[i] - media, 2);
    resultado = sqrt(soma2 / n);
    printf("Desvio padrao = %.2lf\n", resultado);
    registrarOperacao("DesvioPadrao", n, 0, resultado);
}

void maxMin() {
    double a, b;
    printf("Digite dois numeros: ");
    scanf("%lf %lf", &a, &b);
    printf("Maior: %.2lf | Menor: %.2lf\n", fmax(a, b), fmin(a, b));
}

// ------------------------------------------------
// Operações com Matrizes (2x2)
// ------------------------------------------------
void somaMatriz2x2() {
    double A[2][2], B[2][2], C[2][2];
    printf("Digite a matriz A (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%lf", &A[i][j]);

    printf("Digite a matriz B (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%lf", &B[i][j]);

    printf("Resultado (A+B):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%.2lf ", C[i][j]);
        }
        printf("\n");
    }
}

void multMatriz2x2() {
    double A[2][2], B[2][2], C[2][2];
    printf("Digite a matriz A (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%lf", &A[i][j]);

    printf("Digite a matriz B (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%lf", &B[i][j]);

    printf("Resultado (A*B):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
            printf("%.2lf ", C[i][j]);
        }
        printf("\n");
    }
}

// ------------------------------------------------
// Menu principal (mantido do seu original)
// ------------------------------------------------
void menu() {
    printf("\n                 Calculadora Cientifica\n");
    printf("1.  Adicao\n");
    printf("2.  Subtracao\n");
    printf("3.  Multiplicacao\n");
    printf("4.  Divisao\n");
    printf("5.  Potencia\n");
    printf("6.  Raiz Quadrada\n");
    printf("7.  Fatorial\n");
    printf("8.  Media\n");
    printf("9.  Mediana\n");
    printf("10. Desvio Padrao\n");
    printf("11. Maximo/Minimo\n");
    printf("12. Soma Matriz 2x2\n");
    printf("13. Multiplicacao Matriz 2x2\n");
    printf("14. Mostrar Historico\n");
    printf("15. Salvar Historico\n");
    printf("0.  Sair\n");
}

// ------------------------------------------------
// Função Principal
// ------------------------------------------------
int main() {
    int opcao;

    do {
        menu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        printf("---------------------------------------------\n");

        switch (opcao) {
            case 1: somar(); break;
            case 2: subtrair(); break;
            case 3: multiplicar(); break;
            case 4: divisao(); break;
            case 5: potencia(); break;
            case 6: raiz(); break;
            case 7: fatorial(); break;
            case 8: media(); break;
            case 9: mediana(); break;
            case 10: desvioPadrao(); break;
            case 11: maxMin(); break;
            case 12: somaMatriz2x2(); break;
            case 13: multMatriz2x2(); break;
            case 14: mostrarHistorico(); break;
            case 15: salvarHistorico(); break;
            case 0: printf("Encerrando a calculadora...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
        printf("---------------------------------------------\n");
    } while (opcao != 0);

    return 0;
}
