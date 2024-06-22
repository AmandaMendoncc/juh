#include <stdio.h>
#include <stdlib.h>
#include "tudo.h"

//TABULEIRO DO JOGO DA VELHA
void Tabuleiro(char casas[3][3]) 
{
    Limpar();
	LogoVelha();

    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t    1   2   3  \n");
    printf("\t\t\t\t\t\t\t\t\t  +---+---+---+\n");
    printf("\t\t\t\t\t\t\t\t\t1 | %c | %c | %c |\n", casas[0][0], casas[0][1], casas[0][2]);
    printf("\t\t\t\t\t\t\t\t\t  +---+---+---+\n");
    printf("\t\t\t\t\t\t\t\t\t2 | %c | %c | %c |\n", casas[1][0], casas[1][1], casas[1][2]);
    printf("\t\t\t\t\t\t\t\t\t  +---+---+---+\n");
    printf("\t\t\t\t\t\t\t\t\t3 | %c | %c | %c |\n", casas[2][0], casas[2][1], casas[2][2]);
    printf("\t\t\t\t\t\t\t\t\t  +---+---+---+\n");
}


//AUTO EXPLICATIVO DIVOS
void InicializarCasas(char casas[3][3]) 
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            casas[i][j] = ' ';
        }
    }
}


//COMENTAR ALGO SOBRE
int VerificarVitoria(char casas[3][3], char jogador) 
{
    // Verificação de linhas, colunas e diagonais
    int i;
    for (i = 0; i < 3; i++) 
    {
        if ((casas[i][0] == jogador && casas[i][1] == jogador && casas[i][2] == jogador) || 
            (casas[0][i] == jogador && casas[1][i] == jogador && casas[2][i] == jogador)) 
        {
            return 1;
        }
    }
    if ((casas[0][0] == jogador && casas[1][1] == jogador && casas[2][2] == jogador) || 
        (casas[0][2] == jogador && casas[1][1] == jogador && casas[2][0] == jogador)) 
    {
        return 1;
    }
    return 0;
}

void Velha(char *nome)
{
    printf("\t\t\n\nINICIALIZANDO JOGO DA VELHA...\n");

    char casas[3][3];
    char res;
    int cont_jogadas;
	int l, c;
	int vez = 0;
	int jogadorO = 0;
	int jogadorX = 0;

    do {
        InicializarCasas(casas);//ZERA TABULEIRO
        
        
        cont_jogadas = 0;
        vez = 0;


        do {
            Tabuleiro(casas); //TABULEIRO
            
            if (vez % 2 == 0) // APARECER O TEXTO DE QM É A VEZ DE JOGAR
			{
                printf("\n\n\n\t\t\tVEZ DE 'X'");
            } else {
                printf("\n\n\n\t\t\tVEZ DE 'O'");
            }
            
            //SABER ONDE TÁ JOGANDO
            printf("\n\n\n\t\t\tDIGITE A COLUNA: ");
            scanf("%d", &c);
            printf("\t\t\tDIGITE A LINHA: ");
            scanf("%d", &l);
            
            //FICAR DE ACORDO COM O QUE A PESSOA DIGITAR
            l--; 
            c--;

            //PERMITE JOGAR SÓ EM POSIÇÕES VÁLIDAS
            if (l < 0 || l > 2 || c < 0 || c > 2 || casas[l][c] != ' ')
			{
                printf("\n\n\n\t\t\tPOSIÇÃO INVÁLIDA! TENTE NOVAMENTE.\n");sleep(3);
                Buffer();
                while (getchar() != '\n');
                continue;
            }
            
            //PREENCHE O CAMPO QUE A PESSOA ESCOLHEU JOGAR
            if (vez % 2 == 0) {
                casas[l][c] = 'X';
            } else {
                casas[l][c] = 'O';
            }

            vez++; //ALTERNA A VEZ DE JOGAR
            cont_jogadas++;

            //VITÓRIA
            if (VerificarVitoria(casas, 'X')) // SE JOGADOR 'X' GANHOU
			{
                cont_jogadas = 10;
                Tabuleiro(casas);
                printf("\n\n\n\t\t\tO JOGADOR 'X' GANHOU!");
                printf("\n\t\t\tPARABÉNS!");
                jogadorX++;
                
                //TABELA DE VITÓRIA
                printf("\n\n\n\t\t\tNÚMERO DE VITÓRIAS");
    			printf("\n\t\t\tJOGADOR 'X': %d", jogadorX);
    			printf("\n\t\t\tJOGADOR 'O': %d \n", jogadorO);
                break;
            } else if (VerificarVitoria(casas, 'O')) // SE JOGADOR 'O' GANHOU
			{
                cont_jogadas = 10;
                Tabuleiro(casas);
                printf("\n\n\n\t\t\tO JOGADOR 'O' GANHOU!");
                printf("\n\t\t\tPARABÉNS!");
                jogadorO++;
                
                //TABELA DE VITÓRIA
                printf("\n\n\n\t\t\tNÚMERO DE VITÓRIAS");
    			printf("\n\t\t\tJOGADOR 'X': %d", jogadorX);
    			printf("\t\t\tJOGADOR 'O': %d \n", jogadorO);
                break;
            }
			
        } while (cont_jogadas < 9);

		//VELHA
        if (cont_jogadas == 9) {
            Tabuleiro(casas);
            printf("\n\n\n\t\t\tDEU VELHA!");
        }
	
        printf("\n\n\n\t\t\tDESEJA JOGAR NOVAMENTE? [S/N]\n");
        scanf(" %c", &res);
    } while (res == 'S' || res == 's');
}

