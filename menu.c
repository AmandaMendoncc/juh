#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tudo.h"


void MenuPrincipal()
{
	char nome[50];
    int opcao;
    do {
    	Limpar();
		Logo();
		
        printf("\n\n\n\t[1] - JOGO DA VELHA");
        printf("\n\t[2] - CAMPO MINADO");
        printf("\n\t[3] - JOGO DA FORCA");
        printf("\n\t[4] - RANKING");
        printf("\n\t[5] - SAIR DO PROGRAMA");
        printf("\n\n\tESCOLHA UMA OP플O: ");
        scanf("%d", &opcao);


        switch(opcao)
		{
            case 1:
                // CHAMAR FUN플O JOGO DA VELHA
                Velha(nome);
                break;
            case 2:
                // CHAMAR FUN플O CAMPO MINADO
                break;
            case 3:
                // CHAMAR FUN플O JOGO DA FORCA
                break;
            case 4:
                // CHAMAR FUN플O RANKING
                break;
            case 5:
                printf("\n\tSAINDO...");
                break;
            default:
                printf("\n\tOP플O INV핶IDA! TENTE NOVAMENTE.");
        }
    } while(opcao != 3);
}
