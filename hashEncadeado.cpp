#include <iostream>
//#include <random>

using namespace std;

typedef struct modlista {
        int valor;
        struct modlista *prox;           //ponteiro para o proximo elemento
}*vetor,lista, *elo;                 //um vetor de ponteiro para a struct, a estrutura, ponteiro para a struct

void inicio(vetor *v,int n){
	elo novo;
	int i;
	for(i=0;i<n;i++){
		novo = (elo)calloc(1,sizeof(lista));
		novo->valor = i;
		novo->prox = NULL;
		v[i] = novo;
	}
}


int calculoHash(int x,int m){
	return (x%m);
}
int inserir(vetor *v,int valor,int m){
	 elo aux, novo;

	 int posicao = calculoHash(valor,m);

	 aux = v[posicao];

	 while(1){
	 	if(aux->prox == NULL)
	 		break;
	 	aux = aux->prox;
	 }

	novo = (elo)calloc(1,sizeof(lista));
	novo->valor = valor;
	novo->prox = NULL;
	aux->prox = novo;

}

void imprimir(vetor *v,int m){
	elo aux;
	int i;

	for(i=0;i<m;i++){
		aux = v[i];

		while(1){
			if(aux == NULL)
				break;

			printf("%d -> ",aux->valor);

			aux = aux->prox;
		}
		printf("\\\n");

	}
}

int main(){
    clock_t t_inicial,t_final;
	double tempoGasto;

	int m=36131;//número primo para o tamanho do vetor
	vetor *v = (vetor*)malloc(m * sizeof(vetor));
	inicio(v,m);

    int i;

    t_inicial = clock();
    for(i=0;i<8000000;i++)
        inserir(v,i,m);
    t_final = clock();


    //,imprimir(v,m);


    tempoGasto = (double(t_final - t_inicial)) / CLOCKS_PER_SEC	;

	cout << "Tempo gasto: " << tempoGasto << "\n";

	return 0;
}
