#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int opcao; // opção de para sair da calculadora
    double num1, num2, resultado; //declarando as variaveis num1 será usado como angulo ou quando não precisar usar o num2

    do {
        // Menu interativo
        printf("\n                 Calculadora Cientifica\n");
        printf("1.  Adicao\n");
        printf("2.  Subtracao\n");
        printf("3.  Multiplicacao\n");
        printf("4.  Divisao\n");
        printf("5.  Seno\n");
        printf("6.  Cosseno\n");
        printf("7.  Tangente\n");
        printf("8.  Raiz Quadrada\n");
        printf("9.  Potencia (x^y)\n");
        printf("10. Logaritmo Natural (ln)\n");
        printf("11. Logaritmo Base 10 (log10)\n");
        printf("12. Exponencial (e^x)\n");
        printf("13. Porcentagem (x%% de y)\n");
        printf("14. Fatorial\n");
        printf("15. Valor Absoluto\n");
        printf("16. Inverso (1/x)\n");
        printf("17. Arco Seno (asin)\n");
        printf("18. Arco Cosseno (acos)\n");
        printf("19. Arco Tangente (atan)\n");
        printf("20. Parte Inteira\n");
        printf("21. Arredondar\n");
        printf("0.  Sair\n");
        

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Adição
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 + num2;
                printf("Resultado: %.2lf\n", resultado);
                break;

            case 2: // Subtração
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 - num2;
                printf("Resultado: %.2lf\n", resultado);
                break;

            case 3: // Multiplicação
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 * num2;
                printf("Resultado: %.2lf\n", resultado);
                break;

            case 4: // Divisão
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0) {
                    printf("Erro: Divisao por zero!\n");
                } else {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf\n", resultado);
                }
                break;

            case 5: // Seno
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", sin(num1));
                break;

            case 6: // Cosseno
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", cos(num1));
                break;

            case 7: // Tangente
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", tan(num1));
                break;

            case 8: // Raiz Quadrada
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                if(num1 < 0) {
                    printf("Erro: nao existe raiz quadrada real de numero negativo!\n");
                } else {
                    printf("Resultado: %.2lf\n", sqrt(num1));
                }
                break;

            case 9: // Potencia
                printf("Digite a base e o expoente: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Resultado: %.2lf\n", pow(num1, num2));
                break;

            case 10: // Logaritmo natural
                printf("Digite um numero positivo: ");
                scanf("%lf", &num1);
                if(num1 <= 0) { //verificando se o logaritmando é negativo
                    printf("Erro: log de numero nao positivo!\n");
                } 
                else{
                    printf("Resultado: %.2lf\n", log(num1));
                }
                break;

            case 11: // Log de base 10
                printf("Digite um numero positivo: ");
                scanf("%lf", &num1);
                if(num1 <= 0) { //verificando se o logaritmando é negativo
                    printf("Erro: log10 de numero nao positivo!\n");
                } else {
                    printf("Resultado: %.2lf\n", log10(num1));
                }
                break;

            case 12: // Exponencial
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", exp(num1));
                break;

            case 13: // Porcentagem
                printf("Digite o valor e a porcentagem: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 * num2 / 100;
                printf("%.2lf%% de %.2lf = %.2lf\n", num2, num1, resultado);
                break;

            case 14: // Fatorial
                printf("Digite um numero inteiro nao-negativo: ");
                scanf("%lf", &num1);
                if(num1 < 0 || num1 != (int)num1) { //verificar se o numero é inteiro ou menor que zero
                    printf("Erro: fatorial apenas para inteiros nao-negativos!\n");
                } else {
                    long long fat = 1; //como fatorial cresce muito rapido e é um numero inteiro, declarar uma variavel do tipo long long é melhor pra situação
                    for(int i=1; i <= num1; i++) { // laço para multiplicar 1, 2, 3... até n
                        fat *= i;
                    }
                    printf("Resultado: %lld\n", fat);
                }
                break;

            case 15: // Valor absoluto
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", fabs(num1));
                break;

            case 16: // Inverso
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                if(num1 == 0) {
                    printf("Erro: nao existe inverso de zero!\n");
                } else {
                    printf("Resultado: %.2lf\n", 1/num1);
                }
                break;

            case 17: // Arco seno
                printf("Digite um valor entre -1 e 1: ");
                scanf("%lf", &num1);
                if(num1 < -1 || num1 > 1) { // verificando se o numero está no intervalo de [-1, 1]
                    printf("Erro: dominio invalido!\n");
                } else {
                    printf("Resultado: %.2lf rad\n", asin(num1));
                }
                break;

            case 18: // Arco cosseno
                printf("Digite um valor entre -1 e 1: ");
                scanf("%lf", &num1);
                if(num1 < -1 || num1 > 1) {
                    printf("Erro: dominio invalido!\n");
                } else {
                    printf("Resultado: %.2lf rad\n", acos(num1));
                }
                break;

            case 19: // Arco tangente
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf rad\n", atan(num1));
                break;

            case 20: // Parte inteira
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", floor(num1));
                break;

            case 21: // Arredondar
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                printf("Resultado: %.2lf\n", round(num1));
                break;

            case 0: // Sair
                printf("Encerrando a calculadora...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
