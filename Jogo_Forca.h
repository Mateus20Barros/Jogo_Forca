#ifndef FORCA_H
   #define FORCA_H
   
      #define TAMANHO_PALAVRA 20
      char palavrasecreta[TAMANHO_PALAVRA];
      char chutes[26];
      int chutesdados = 0;

      int ganhou(void);
      int acertou(void);
      int enforcou(void);
      int chuteserrados(void);
      int jachutou(char letra);
      int letraexiste(char letra);

      void chuta(void);
      void abertura(void);
      void desenhaforca(void);
      void escolhepalavra(void);
      void adicionapalavra(void);
      void cavera(char palavrasecreta[]);
      void trofeu(char palavarasecreta[]);
#endif