#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 5
#define CHUTE_MINIMO 0
#define CHUTE_MAXIMO 100
#define NIVEL_MINIMO 1
#define NIVEL_MAXIMO 3

int main() {
    printf("\n\n");                                                
	printf("           P  /_\\  P                              	\n");
	printf("          /_\\_|_|_/_\\                             \n");
	printf("      n_n | ||. .|| | n_n         Bem vindo ao    	\n");
	printf("      |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao!	\n");
	printf("     |" "  |  |_|  |"  " |                       	\n");
	printf("     |_____| ' _ ' |_____|                        	\n");
	printf("           \\__|_|__/                               \n");           
	printf("\n\n");
    
    // variaveis
    int segundos = time(0);
    srand(segundos);
    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100; 
	int chute; 
	int tentativas = 1;
	int acertou = 0;
	double pontos = 1000;
	
	int nivel;
	printf("Qual nivel voce deseja jogar? \n");
	printf("(1) facil (2) medio (3) dificil \n");
	printf("escolha: ");
	scanf("%d", &nivel);

	int numeroDeTentativas;
	
	switch(nivel) {
		case 1: 
			numeroDeTentativas = 20;
			break;
		case 2:
			numeroDeTentativas = 15;
			break;
		default:
			numeroDeTentativas = 6;
			break;
	}
	
    int i;
    for(i = 1; i <= numeroDeTentativas; i++) {
    	
        printf("tentativas %d \n" , tentativas);
        printf("Faca um chute de %d a %d: ", CHUTE_MINIMO, CHUTE_MAXIMO);
        scanf("%d", &chute);
        printf("seu chute foi %d \n", chute);
        
        if(chute < CHUTE_MINIMO || chute > CHUTE_MAXIMO) {
            system("color 4f");
            printf("---------------------------------------------- \n");
            printf("atencao \n");
            printf("digite um numero valido entre (%d a %d). \n", CHUTE_MINIMO, CHUTE_MAXIMO);
            printf("---------------------------------------------- \n");
            continue;
        } 
        system("color 0f");
        
        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;
        
        if(chute == numeroSecreto) {
           
            break;
        } else {
            system("color 0f");
            printf("voce errou...\n");
                
            if(chute > numeroSecreto) {
	            printf("o numero secreto e menor\n");
	            printf("nao desista, tente novamente \n");
	            printf("*********************************** \n");
            } else {
	            printf("o numero secreto e maior\n");
	            printf("nao desista, tente novamente \n");
	            printf("*********************************** \n");
            }
        }
        tentativas++;
        
        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        
        pontos = pontos - pontosPerdidos;
    }
    
    printf("fim de jogo! \n");
    
    if(acertou) {
    	printf("voce ganhou \n");
    	printf("\n\n");                                                                    
		printf("            ###########################           \n");
		printf("            ##########################            \n");
		printf("            ##########################            \n");
		printf("            ##########################            \n");
		printf("      ########################################    \n");
		printf("    ####     #########################      ##    \n");
		printf("    ####      ########################      ##    \n");
		printf("      ##      ########################    ####    \n");
		printf("        ####   ######################    ####     \n");
		printf("          ################################        \n");
		printf("              ########################            \n");
		printf("                  ##############                  \n");
		printf("                   ############                   \n");
		printf("                      ########                    \n");
		printf("                                                  \n");
		printf("                                                  \n");
		printf("                  ##############                  \n");
		printf("                  ################                \n");
		printf("                  ################                \n");
		printf("                ##################                \n");
        printf("\n\n");                                                                                   
    	printf("voce acertou em %d tentativas! \n", tentativas);
    	printf("total de pontos: %.1f \n ", pontos);
	} else {
		printf("voce perdeu! tente novamente \n");
		printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
	}

}
