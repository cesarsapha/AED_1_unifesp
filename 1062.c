//Trilhos. Sendo resolvido com pilha
#include <stdio.h>
#include <stdlib.h>

struct inicio_pilha{
    int valor;
    struct inicio_pilha* lim_abaixo;
};

struct empilha{
    int tam;
    struct inicio_pilha* topo;
};


//funcao push. Limite -1 passa a ser o topo

void push(struct empilha* p, int valor){
    p->tam += 1;
    struct inicio_pilha* limite = (struct inicio_pilha*) malloc(sizeof(struct inicio_pilha));
    limite->valor = valor;
    limite->lim_abaixo = p->topo;
    p->topo = limite;
}


//pop para limpar a memória do topo anterior

void pop(struct empilha* p){
    if(p->tam > 0){
        p->tam -= 1;
        struct inicio_pilha* topoAnterior = p->topo;
        p->topo = p->topo->lim_abaixo;
        free(topoAnterior);
    }
}

//funcoes para print
void inicio(struct empilha* p){
    p->tam = 0;
    p->topo = NULL;
}

int tamanho(struct empilha* p){
    return p->tam;
}

int printa_topo(struct empilha* p){
    return p->topo->valor;
}

int vazio(struct empilha* p){
    return p->tam == 0;
}

void limpa(struct empilha* p){
    while(!vazio(p)){
        pop(p);
    }
}


int main(){
    int N, x;
    struct empilha A, estacao, B;

    while(scanf("%d", &N) != EOF){
        if(!N)  break;

        while(scanf("%d", &x)){
            if(!x){
                printf("\n");
                break;
            }

            inicio(&A);
            inicio(&estacao);
            inicio(&B);

            push(&A, x);
            push(&B, 1);
            for(int i = 2; i <= N; ++i){
                scanf("%d", &x);
                push(&A, x);
                push(&B, i);
            }

            //percorre a pilha
            while(!vazio(&A) || !vazio(&estacao) || !vazio(&B)){
                if(!vazio(&A) && !vazio(&B) && printa_topo(&A) == printa_topo(&B)){
                    pop(&A);
                    pop(&B);

                }else if(!vazio(&estacao) && !vazio(&B) && printa_topo(&estacao) == printa_topo(&B)){
                    pop(&estacao);
                    pop(&B);

                }else if(!vazio(&A)){
                    push(&estacao, printa_topo(&A));
                    pop(&A);

                }else{
                    break;
                }
            }

            if(vazio(&A) && vazio(&estacao) && vazio(&B)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }

            limpa(&A);
            limpa(&estacao);
            limpa(&B);
        }
    }

    return 0;
}