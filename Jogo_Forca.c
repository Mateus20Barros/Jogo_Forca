#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Jogo_Forca.h"
#include <locale.h>


void abertura(void) {
   printf("\n\t+++++++++++++++++++++++++++++++++++++");
   printf("\n\t+           JOGO DA FORCA           +");
   printf("\n\t+++++++++++++++++++++++++++++++++++++\n\n");
}

int letraexiste(char letra) {
   for (int i = 0; i < strlen(palavrasecreta); i++) {
      if (letra == palavrasecreta[i]) {
         return 1;
      }
   }

   return 0;
}

int chuteserrados(void) {
   int erros = 0;

   for (int i = 0; i < chutesdados; i++) {
      if (!letraexiste(chutes[i])) erros++;
   }

   return erros;
}

int enforcou(void) {
   return chuteserrados() >= 5;
}

int ganhou(void) {
   for (int i = 0; i < strlen(palavrasecreta); i++) {
      if (!jachutou(palavrasecreta[i])) return 0;
   }

   return 1;
}

void chuta(void) {
   char chute;
   
   printf("\tInsira uma letra..: ");
   scanf(" %c", &chute);

   letraexiste(chute) 
      ? printf("\n\tVocê acertou: a palavra tem a letra %c\n\n", chute) 
      : printf("\n\tVocê errou: a palavra NÃO tem a letra %c\n\n", chute);

   chutes[chutesdados] = chute;
   chutesdados++;
}

int jachutou(char letra) {
   int achou = 0;

   for (int i = 0; i < chutesdados; i++) {
      if (chutes[i] == letra) {
         achou = 1;
         break;
      }
   }

   return achou;
}

void desenhaforca(void) {
   int erros = chuteserrados();

   printf("\t  _______       \n");
   printf("\t |/      |      \n");
   printf("\t |      %c%c%c  \n", (erros>=1 ? '(' : ' '), (erros>=1 ? '_' : ' '), (erros>=1 ? ')' : ' '));
   printf("\t |      %c%c%c  \n", (erros>=3 ? '\\' : ' '), (erros>=2 ? '|' : ' '), (erros>=3 ? '/' : ' '));
   printf("\t |       %c     \n", (erros>=2 ? '|' : ' '));
   printf("\t |      %c %c   \n", (erros>=4 ? '/' : ' '), (erros>=4 ? '\\' : ' '));
   printf("\t |              \n");
   printf("\t_|___           \n");
   printf("\n\n");

   for (int i = 0; i < strlen(palavrasecreta); i++) {
      jachutou(palavrasecreta[i])
         ? printf("\t%c ", palavrasecreta[i])
         : printf("\t_");
   }

   printf("\n\n");
}

void escolhepalavra(void) {
   FILE* f;

   f = fopen("palavras.txt", "r");
   if (f == 0) {
      printf("\n\tNão foi possivel acessar o banco de palavras\n\n");
      exit(1);
   }

   int qtddepalavras;
   fscanf(f, "%d", &qtddepalavras);

   srand(time(0));
   int randomico = rand() % qtddepalavras;

   for (int i = 0; i <= randomico; i++) {
      fscanf(f, "%s", palavrasecreta);
   }

   fclose(f);
}

void adicionapalavra(void) {
   char adicionarPalavra;

   printf("\n\tDeseja adicionar uma nova palavra ao jogo ?");
   printf("\n\t[S] Sim / [N] Não ..: ");
   scanf(" %c", &adicionarPalavra);

   if (adicionarPalavra == 'S') {
      char novapalavra[TAMANHO_PALAVRA];
      int qtdpalavra;

      printf("\n\tDigite a palavra em MAIUSCULO..: ");
      scanf("%s", novapalavra);

      FILE* f;

      f = fopen("palavras.txt", "r+");
      if (f == 0) {
         printf("\n\tNão foi possivel acessar o banco de palavras\n\n");
         exit(1);
      }

      fscanf(f, "%d", &qtdpalavra);
      qtdpalavra++;

      fseek(f, 0, SEEK_SET);
      fprintf(f, "%d", qtdpalavra);

      fseek(f, 0, SEEK_END);
      fprintf(f, "\n%s", novapalavra);

      fclose(f);

      printf("\n\t+-------------------------------------------+");
		printf("\n\t| >>   Palavra adicionada com sucesso.   << |");
		printf("\n\t+-------------------------------------------+\n");
   }
}

void trofeu(char palavarasecreta[]) {
   printf("\n\tParabéns pela conquista!\n\n");

   printf("\t     ___________      \n");
   printf("\t    '._==_==_=_.'     \n");
   printf("\t    .-\\:      /-.    \n");
   printf("\t   ( (|:.     |) )    \n");
   printf("\t    '-|:.     |-'     \n");
   printf("\t      \\::.    /      \n");
   printf("\t       '::. .'        \n");
   printf("\t         ) (          \n");
   printf("\t       _.' '._        \n");
   printf("\t      '-------'       \n");

   printf("\n\tVoce acertou a palavra [%s]\n\n", palavrasecreta);
}

void cavera(char palavrasecreta[]) {
   printf("\n\tPuxa, você foi enforcado!\n");

   printf("\t     _______________        \n");
   printf("\t    /               \\      \n"); 
   printf("\t   /                 \\     \n");
   printf("\t  /                   \\    \n");
   printf("\t  |   XXXX     XXXX   |     \n");
   printf("\t  |   XXXX     XXXX   |     \n");
   printf("\t  |   XXX       XXX   |     \n");
   printf("\t  |                   |     \n");
   printf("\t  \\__       X       __/    \n");
   printf("\t    |\\     X X     /|      \n");
   printf("\t    | |           | |       \n");
   printf("\t    | I I I I I I I |       \n");
   printf("\t    |  I I I I I I  |       \n");
   printf("\t    \\_             _/      \n");
   printf("\t      \\_         _/        \n");
   printf("\t        \\_______/          \n");

   printf("\n\tA palavra secreta era %s\n\n", palavrasecreta);
}

int main(void) {
   setlocale(LC_ALL, "Portuguese");

   escolhepalavra();

   do {
      abertura();
      desenhaforca();
      chuta();
      system("cls");
   } while (!ganhou() && !enforcou());

   ganhou() ? trofeu(palavrasecreta) : cavera(palavrasecreta);
   adicionapalavra();

   return 0;
}