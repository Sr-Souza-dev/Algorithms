#include <iostream>
#include <map>

using namespace std;

#define M 10

typedef struct HashTable HashTable;

struct HashTable{
  map<int,int> hash;
};

void Imprime(HashTable *h){
  map<int, int>::iterator it;
  for(it=h->hash.begin(); it!=h->hash.end(); ++it)
    printf("KEY:%d - VALUE:%d\n", it->first, it->second);
}

void Insert(HashTable *h, int key, int value){
  h->hash[key] = value;
}

int main (){
  HashTable h;

  Insert(&h, 1, 100);
  Insert(&h, 2, 200);
  Insert(&h, 3, 300);
  
  Imprime(&h);

  return 0;
}