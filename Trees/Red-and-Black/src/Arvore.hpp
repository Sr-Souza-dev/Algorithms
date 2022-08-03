#ifndef ARVORE_HPP
#define ARVORE_HPP

#define BLACK 0
#define RED 1

#include <iostream>
using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
    int value;
    string nome;
    string data;
    string nota;
    int quantidade;
};

Tree* CreateTree();
void showTreeInOrder(Tree *tree);
bool search(Tree **node, Tree **root, Record record);

//Funções que não haviam ou foram modificadas da arvore binaria simples
int insertTree(Tree **tree, Record record);
void removeTree(Tree **tree, Record record);
int color(Tree *tree);
void changeColor(Tree *tree);
Tree *rotationLeft(Tree *nodeA);
Tree *rotationRight(Tree *nodeA);
Tree *moveLeftRed(Tree *tree);
Tree *moveRightRed(Tree *tree);
Tree *balance(Tree *tree);
Tree *insertNode(Tree **tree, Record record, int *resp);
Tree *searchSmaller(Tree *node);
Tree *removeSmaller(Tree *node);
Tree *removeNode(Tree *node, Record record);

//Função adicional
bool vender(Tree** tree, Record record, int quantidade);

//Funções auxiliares para verificar a construção da arvore
void print2DUtil(Tree *root, int space);
void print2D(Tree *root);

#endif