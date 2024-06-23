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


////////////////////////////////////////////////////////////////////////////////
// JOGO DA FORCA

void Forca();


////////////////////////////////////////////////////////////////////////////////
// RANKING

#endif
