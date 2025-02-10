#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilha {
    char dado;
    struct Pilha* proximo;
};

struct Pilha* criarcaso(char dado){
    struct Pilha* novocaso = (struct Pilha*)malloc(sizeof(struct Pilha));
    novocaso->dado = dado;
    novocaso->proximo = NULL;
    return novocaso;
}

int vazia(struct Pilha* pilha){
    return (pilha == NULL);
}

void empilhar(struct Pilha** pilha, char dado){
    struct Pilha* novocaso = criarcaso(dado);
    novocaso->proximo = *pilha;
    *pilha = novocaso;
}

char desempilhar(struct Pilha** pilha){
    if (vazia(*pilha)){
        return '\0';
    }
    struct Pilha* temp = *pilha;
    *pilha = (*pilha)->proximo;
    char desempilhou = temp->dado;
    free(temp);
    return desempilhou;
}

int verifica(char op){
    switch (op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
int verifyAlpha(char c){
    return (c >= '0' && c <= '9')|| (c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z');
}
void infixaParaPosfixa(char* infixa, char* posfixa){
    struct Pilha* pilha = NULL;
    int i, j = 0;
    for (i = 0; infixa[i]; i++){
        char c = infixa[i];
        if (verifyAlpha(c)){
            posfixa[j++] = c;
        } else if (c == '('){
            empilhar(&pilha, c);
        } else if (c == ')'){
            while (!vazia(pilha) && pilha->dado != '('){
                posfixa[j++] = desempilhar(&pilha);
            }
            desempilhar(&pilha);
        } else {
            while (!vazia(pilha) && verifica(c) <= verifica(pilha->dado)){
                posfixa[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, c);
        }
    }
    while (!vazia(pilha)){
        posfixa[j++] = desempilhar(&pilha);
    }    
    posfixa[j] = '\0';
}
int main(){
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        char expressao[301];
        scanf("%s", expressao);
        char posfixa[301];
        infixaParaPosfixa(expressao, posfixa);
        printf("%s\n", posfixa);
    }
    return 0;
}