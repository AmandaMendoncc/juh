#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tudo.h"


void Forca()
{
	int ganhou = 0;
while (1) {
        FILE *arquivo;
        arquivo = fopen("palavras.txt", "r");
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo de palavras");
            return;
        }

        char palavra[100];
        char palavra_digitada[100]; // Array para armazenar a palavra secreta digitada
        char letras_digitadas[27] = {0}; // Array para armazenar letras digitadas, inicializado com 0
        int contador_de_tentativas = 0;
        int tentativas_erradas = 0;
        int verificar_conclusao = 0;

        srand(time(NULL));
        int min = 0;
        int max = 631;
        int linha_sorteada = min + rand() % (max - min + 1);

        int contador_de_linhas = 0;
        
        while (fgets(palavra, sizeof(palavra), arquivo) != NULL) {
            contador_de_linhas++;
            if (contador_de_linhas == linha_sorteada) {
                break;
            }
        }
        fclose(arquivo);

        // Remover o caractere de nova linha (\n) da palavra lida
        palavra[strcspn(palavra, "\n")] = '\0';

		Limpar();
		Logo();
		
        printf("\n\n\n\t\t\tSUA PALAVRA TEM '%d' LETRAS", (int)strlen(palavra));

        // Inicializar palavra_digitada com espaços em branco para ocultar a palavra
        memset(palavra_digitada, ' ', strlen(palavra));
        palavra_digitada[strlen(palavra)] = '\0';

        while (verificar_conclusao < strlen(palavra)) {
            char letra;
            int verificador = 0;

            if (tentativas_erradas < 10) {
                Buffer();
                printf("\n\n\n\t\t\tDIGITE UMA LETRA: ");
                scanf(" %c", &letra);

                // Verificar se a letra já foi digitada
                if (letras_digitadas[letra - 'a'] == 1 || letras_digitadas[letra - 'A'] == 1) {
                    printf("Você já digitou essa letra. Tente outra.\n");
                    continue;
                }

                letras_digitadas[letra - 'a'] = 1;
                letras_digitadas[letra - 'A'] = 1;
				int i;
                for ( i = 0; i < strlen(palavra); i++) {
                    if (letra == palavra[i]) {
                        if (palavra_digitada[i] == ' ') { // Substitui se a letra for ' '
                            palavra_digitada[i] = letra;
                            verificar_conclusao++;
                        }
                        verificador++;
                    }
                }

                // mostra a palavra
                for (i = 0; i < strlen(palavra); i++) {
                    if (palavra_digitada[i] != ' ') {
                        printf(" %c ", palavra_digitada[i]);
                    } else {
                        printf(" ___ ");
                    }
                }
                printf("\n");

                if (verificador != 0) {
                    printf("Essa letra existe na palavra\n");
                } else {
                    printf("Essa letra não existe na palavra\n");
                    tentativas_erradas++;
                }

                printf("Tentativas restantes: %d\n", 10 - tentativas_erradas);
            } else {
                printf("Máximo de erros atingido. Você foi enforcado!\n");
                ganhou = 1;
                break;
            }
        }
        
        if(ganhou == 1){
        	printf("Voce perdeu!!!!!\n");
        	printf("A palavra era %s\n", palavra);
		} else {
			printf("PARABENS VOCE GANHOU!!!!!!!!!!!!!!");
		}

        // deseja jogar novamente
        char jogar_novamente;
        Buffer(); // função para o scanf nao pular
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);

        if (jogar_novamente != 's' && jogar_novamente != 'S') {
            MenuPrincipal();
            break;
        }
    }
}
