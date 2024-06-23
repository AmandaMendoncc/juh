#ifndef TUDO_H
#define TUDO_H

////////////////////////////////////////////////////////////////////////////////
//STRUCTS



////////////////////////////////////////////////////////////////////////////////
// STYLE

void JogarNovamente();

void Limpar();
void Buffer();
void RemoverLinha(char *str);

void Logo();
void LogoVelha();
void LogoForca();
void LogoCampoMinado();

////////////////////////////////////////////////////////////////////////////////
// MENU

void MenuPrincipal();

////////////////////////////////////////////////////////////////////////////////
// JOGO DA VELHA

void Velha(char *nome);


void Tabuleiro(char casas[3][3]);
void InicializarCasas(char casas[3][3]);
int VerificarVitoria(char casas[3][3], char jogador);

////////////////////////////////////////////////////////////////////////////////
// CAMPO MINADO

// Estrutura da célula do jogo
typedef struct {
    int Bomba;
    int Aberta;
    int vizinhos;
} Celula;

typedef struct {
	char jogador[50];
} Jogador;

void InicializarJogo();
void SortearBombas();
int CoordenadaValida(int l, int c);
int BombasVizinhas(int l, int c);
void ContarBombas();
void Imprimir();
void AbrirCelula(int l, int c);
int Ganhou();
void Jogar();
void Jogo(Jogador nome_usuario);
int CampoMinado();

////////////////////////////////////////////////////////////////////////////////
// JOGO DA FORCA

void Forca();


#endif
