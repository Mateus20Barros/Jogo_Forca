***

<div align="center">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="100"/>
</div>

<br>

### 📃 Sobre o arquivo Jogo_Forca_C.c


O arquivo **`Jogo_Forca_C.c`** e o arquivo que contém a função **`int main()`** responsável por executar o codigo escrito na linguagem C, quando o compilador esta em execução ele procura pela função **`int main()`** para executar o código, caso não seja encontrada um erro e mostrado em tempo de execução. Então para que o jogo da forca seja executado no seu computador e preciso compilar o arquivo **`Jogo_Forca_C.c`**.

Além da função **`int main()`**, este arquivo também contém todas as funções do jogo, as bibliotecas da linguagem C usada para desenvolver o jogo.

O Jogo foi desenvolvido utilizando o editor de código **`VS Code`** código também pode ser exectado em IDEs como **`Visual Studio Code`**, **`DevC++`**, **`Eclipse`** entre outras, já que as IDEs possuem compiladores embutido, porém para executar o jogo no **`VS Code`** e necessario algumas configurações no computador e no próprio **`VS Code`** como a seguir:

* Baixar e instalar o ***[GCC Compiler](https://www.baixaki.com.br/linux/download/gcc.htm)*** ou outro compilador que esteja familiarizado.
* Configurar o compilador baixado e instalado nas variaveis de ambiente do computador.
* Instalar as extensões ***[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)*** e ***[C/C++ Compile Run](https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-compile-run)***, no VS Code, para que o código escrito em C seja compilado no editor.

##

### 🔣 Acentuação de Caracteres nas IDEs

Para que as **`IDEs`** consiga entender os caracteres acentuados e preciso incluir a biblioteca **`locale.h`** no começo do arquivo **`Jogo_Forca_C.c`**, assim ao inserir  caracteres acentuados as **`IDE`** entenderar os caracteres.

```C
#include<locale.h>
```

Em seguida insira o **`setlocale(LC_ALL, "Portuguese")`** dentro da função **`int main()`** antes de qualquer outro código conforme a seguir:

```C
#include<stdio.h>
#include<locale.h>

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  
  // Código aqui
  
  return 0;
}
```
Assim os caracteres acentuados seram entendidos pela linguagem C nas **`IDEs`**.

##

### 🔣 Acentuação de Caracteres no VS Code

Para usar acentuação de caracteres no **`VS Code`** e preciso incluir a biblioteca **`windows.h`** no começo do arquivo **`Jogo_Forca_C.c`** assim ao inserir um caracter acentuado no **`VS Code`** o mesmo entenderar o caracter.

```C
#include<windows.h>
```
Em seguida, insira os trechos de códigos a baixo dentro da função **`int main()`**, sendo uma parte no começo da função, e a outra parte antes do fechamento da função, conforme a seguir:

```C
#include<stdio.h>
#include<windows.h>

int main(void) {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  
  // Código aqui
  
  SetConsoleOutputCP(CPAGE_DEFAULT);
}
```
Assim os caracteres acentuados seram entendidos pela linguagem C no **`VS Code`**.

Execute o código no **`VS Code`** sem abrir um terminal manualmente, usando a tecla **`F8`** no arquivo **`Jogo_Forca_C.c`** assim o **`VS Code`** abrirá um terminal automaticamente com a saida do código após compilar o arquivo. 

> ***Para que esse atalho seja possivel no **`VS Code`** e necessario que o compilador baixado e instalado no computador esteja configurado corretamente nas variaveis de ambiente do computador, conforme explicado no início do arquivo.***

<br>

<div align="center">
    :octocat: Feito por Mateus Barros :octocat:
</div>

***
