#include <stdio.h>

int main()
{
    int qntDeAlunos = 0;
    float media = 0;
    
    printf("Digite quantos alunos: ");
    scanf("%d", &qntDeAlunos);
    
    float notas[qntDeAlunos];
    
    for (int i = 0; i < qntDeAlunos; i++ ){ //prencher cada index do meu array
        printf("Digite a nota dos alunos: ");
        scanf("%f", &notas[i]);
    }
    
    for(int j = 0; j < qntDeAlunos; j++){  // fazendo a media 
        media += notas[j];
    }
    
    media = media / qntDeAlunos;
    
    printf("Media geral igual: %.2f", media);
    
    return 0;
}