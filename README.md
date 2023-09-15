# Documentação

## Depêndencias
Necessário ter instalado um compilador de linguagem C++ e o make.
- Distribuições Debian🐧
```shell
sudo apt install build-essential cmake
```
## Parte 1 - Compilação:

Para compilar o programa, navegue até o diretório atual onde se encontram os arquivos correspondentes do programa, usando o terminal. Agora, basta executar o seguinte comando:

```bash
make
``````
Isso irá compilar o programa.

## Parte 2 - Execução

Após compilar o programa, você pode executá-lo de duas maneiras diferentes:

### Opção 1:
Rode o seguinte comando, e a saída será impressa diretamente no terminal:

```bash
make rodar_programa
```
### Opção 2:

Você também pode executar o programa e salvar a saída em um arquivo no diretório "/output". Para fazer isso, execute o seguinte comando:

```bash
make rodar_programa_saida_arquivo
```


## Inserir Novos Testes

**O arquivo teste.txt está localizado na pasta "input/"**

Após inserir o grafo que deseja testar no arquivo "teste.txt", lembre-se de que o programa aceita apenas entradas no formato de letras, como A, B e C. Separe os vértices por espaços, conforme exemplificado abaixo:

```txt
A C
B A
C B
C D
D B
```

## Alguns testes e suas saídas esperadas
### Teste 1:
**Input :**
```txt
A C
B A
C B
C D
D B
```
**Output:**
```txt
Componente 1
A B C D
```
### Teste 2:
**Input :**
```txt
A B
B A
C C
```
**Output:**
```txt
Componente 1
A B
Componente 2
C
```
### Teste 3:
**Input :**
```txt
K L
L M
M K
N O
O P
P N
```
**Output:**
```txt
Componente 1
K L M
Componente 2
N O P
```
