#include<stdio.h>
#include<stdlib.h>

#define hash(v, M) (v % M)

typedef struct DataTable Data;
typedef struct HashTable HashTable;


struct DataTable{
	int key;
	int value;
	int count; //necessário apenas para a política LRU
};


struct HashTable{
	Data *table;
	int M;
};


void Initialize(HashTable *h, int M){
	h->table = (Data*) malloc (M * sizeof(Data));
	for(int i=0; i<M; i++){
		h->table[i].key   = -1;
		h->table[i].value = 0;
		h->table[i].count = 0;
	}

	h->M = M;
}


void Imprime(HashTable *h){
	for(int i=0; i<h->M; i++)
		printf("KEY:%d - VALUE:%d\n", h->table[i].key, h->table[i].value);
}


int getValue(HashTable *h, int key){
	int idx = hash(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != key){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			return -1;
		}
	}

	h->table[idx].count++;
	return h->table[idx].value;
}


int LRUPolicy(HashTable *h){
	int key;

	key = 0;
	for(int i=0; i<h->M; i++){
		if(h->table[i].count < h->table[key].count)
			key = i;
		h->table[i].count = 0;
	}

	return key;
}


void Insert(HashTable *h, int key, int value){
	int idx = hash(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != -1){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			idx = LRUPolicy(h);
			break;
		}
	}	
	
	printf("IDX:%d\n", idx);

	h->table[idx].key   = key;
	h->table[idx].value = value;
	h->table[idx].count = 1;
}


int main(){
	HashTable h;
	int M = 3;
	int key, value;

	Initialize(&h, M);
	Imprime(&h);

	printf("\n\n");
	Insert(&h, 10, 2020);
	Insert(&h, 20, 4020);
	Insert(&h, 30, 5020);
	Imprime(&h);
	printf("\n\n");
	printf("Value:%d\n", getValue(&h, 20));
	printf("Value:%d\n", getValue(&h, 20));
	printf("Value:%d\n", getValue(&h, 10));

	Insert(&h, 40, 1000);

	Imprime(&h);

	return 0;
	
}
