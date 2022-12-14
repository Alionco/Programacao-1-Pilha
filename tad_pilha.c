#include <stdio.h>
#define MAX 5

/* aqui vao as declaracoes iniciais e os codigos das funcoes */
/* inicio das suas modificacoes nesta parte                  */


/* fim das suas modificacoes desta parte                     */

/* O codigo abaixo so pode ser modificado para resolver o    */
/* problema da passagem de endereços como parâmetros!        */
/* Deixe o restante do programa inalterado!!!                */

typedef struct tad_pilha {
       
        int vetor[MAX];
        int topo;
    } tad_pilha;

void inicializa_pilha(tad_pilha *p) {
    p->topo = 0;
}

int pilha_vazia(tad_pilha *p) {
    if (p->topo == 0) {
        return 1;
    } else {
        return 0;
    }
}

int tamanho_pilha(tad_pilha *p) {
    return p->topo;

}

int empilha(int x, tad_pilha *p) {
    if(p->topo == MAX-1) {
        return 0;
    } else {
        p->vetor[p->topo] = x;
        p->topo++;
        return 1; 
    }
}

int desempilha(int *t, tad_pilha *p) {
    if(p->topo == 0){
        return 0;
    } else {
        t = p->vetor[p->topo-1];
        p->topo--;
        return 1;
    }
}

int topo(int *t, tad_pilha *p) {
    if(p->topo == 0){
        return 0;
    } else {
        *t = p->vetor[p->topo-1];
        return 1;
    }

}


int main() {
    tad_pilha p; 
    int i,x,t;
    
    inicializa_pilha(&p);
    printf("tamanho inicial da pilha eh: %d\n",tamanho_pilha(&p));

    for (i=1; i<=MAX; i++)
        if (! empilha(i,&p)) {
            printf("%d nao inserido: pilha cheia\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(&p));
        }
        else {
            printf("%d empilhado\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(&p));
        }

    for (i=1; i<=MAX; i++) {
        x = topo(&t,&p);
        if (! x)
            printf("pilha vazia, topo nao existe\n");
        else
            printf("topo eh: %d\n",t);

        x = desempilha(&t,&p);
        if (! x)
            printf("nao desempilhou: pilha vazia\n");
        else
            printf("%d desempilhado\n",t);
    }
    
    return 0;
}
