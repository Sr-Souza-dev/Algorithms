#include "Arvore.hpp"

struct Tree{
    Record record;
    Tree *left, *right;
    int color;
};

Tree* CreateTree()
{return NULL;}

void showTreeInOrder(Tree *tree)
{
    if(tree != NULL)
    {
        showTreeInOrder(tree->left);
        cout<<"Código: "<<tree->record.value<<"\t Data: "<<tree->record.data<<"\t Nome: "<<tree->record.nome<<"\t Quantidade: "<<tree->record.quantidade<<"\t Nota Fiscal: "<<tree->record.nota<<endl;
        showTreeInOrder(tree->right);
    }
}

bool search(Tree **node, Tree **root, Record record)
{
    bool  a = true;
    if(*node == NULL)
    {
        cout<<"\n [ERROR]: Record not found!";
        return false;
    }
    if((*node)->record.value > record.value)
    {
        a = search(&(*node)->left, root, record);
        return a;
    }
    if((*node)->record.value < record.value)
    {
        a = search(&(*node)->right, root, record);
        return a;
    }
    *root = *node;
    return a;
}

//Funções que não haviam ou foram modificadas da arvore binaria simples
int color(Tree *tree)
{
    if(tree == NULL)
        return BLACK;
    else
        return tree->color;
}

void changeColor(Tree *tree)
{
    tree->color = !tree->color;
    if(tree->left != NULL)
        tree->left->color = !tree->left->color;
    if(tree->right != NULL)
        tree->right->color = !tree->right->color;
}

Tree *rotationLeft(Tree *nodeA)
{
    Tree *nodeB = nodeA->right;
    nodeA->right = nodeB->left;
    nodeB->left = nodeA;
    nodeB->color = nodeA->color;
    nodeA->color = RED;
    return nodeB;
}

Tree *rotationRight(Tree *nodeA)
{
    Tree *nodeB = nodeA->left;
    nodeA->left = nodeB->right;
    nodeB->right = nodeA;
    nodeB->color = nodeA->color;
    nodeA->color = RED;
    return nodeB;
}

Tree *moveLeftRed(Tree *tree)
{
    changeColor(tree);
    if(color(tree->right->left) == RED)
    {
        tree->right = rotationRight(tree->right);
        tree = rotationLeft(tree);
        changeColor(tree);
    }
    return tree;
}

Tree *moveRightRed(Tree *tree)
{
    changeColor(tree);
    if(color(tree->left->left) == RED)
    {
        tree = rotationRight(tree);
        changeColor(tree);
    }
    return tree;
}

Tree *balance(Tree *tree)
{
    if(color(tree->right) == RED)
        tree = rotationLeft(tree);
    if(tree->left != NULL && color(tree->right) == RED && color(tree->left->left) == RED)
        tree = rotationRight(tree);
    if(color(tree->left) == RED && color(tree->right) == RED)
        changeColor(tree);
    return tree;
}

Tree *insertNode(Tree **tree, Record record, int *resp)
{
    if(*tree == NULL)
    {
        Tree *node = new Tree;
        if(node == NULL)
        {
            *resp = 0;
            return NULL;
        }
        node->left = NULL;
        node->right = NULL;
        node->record = record;
        node->color = RED;
        return node;
    }
    if(record.value == (*tree)->record.value)
    {
        *resp = 0;
    }
    else
    {
        if(record.value < (*tree)->record.value)
            (*tree)->left = insertNode(&(*tree)->left,record, resp);
        else
            (*tree)->right = insertNode(&(*tree)->right,record, resp);
    }
    if(color((*tree)->right) == RED && color((*tree)->left) == BLACK)
        *tree = rotationLeft(*tree);
    if(color((*tree)->left) == RED && color((*tree)->left->left) == RED)
        *tree = rotationRight(*tree);
    if(color((*tree)->left) == RED && color((*tree)->right) == RED)
        changeColor(*tree);
    return *tree;
}

int insertTree(Tree **tree, Record record)
{
    int resp = 1;
    *tree = insertNode(tree, record, &resp);
    if((*tree) != NULL)
        (*tree)->color = BLACK;
    return resp;
}

Tree *searchSmaller(Tree *node)
{
    Tree *node1 = node;
    Tree *node2 = node->left;
    while(node2 != NULL)
    {
        node1 = node2;
        node2 = node2->left;
    }
    return node1;
}

Tree *removeSmaller(Tree *node)
{
    if(node->left == NULL)
    {
        delete(node);
        return NULL;
    }
    if(color(node->left) == BLACK && color(node->left->left) == BLACK)
        node = moveLeftRed(node);
    node->left = removeSmaller(node->left);
    return balance(node);
}

Tree *removeNode(Tree *node, Record record)
{
    if(record.value < node->record.value)
    {
        if(color(node->left) == BLACK && color(node->left->left) == BLACK)
            node = moveLeftRed(node);
        node->left = removeNode(node->left, record);
    }
    else{
        if(color(node->left) == RED)
            node = rotationRight(node);
        if(record.value == node->record.value && (node->right == NULL))
        {
            delete(node);
            return NULL;
        }
        if(color(node->right) == BLACK && color(node->right->left) == BLACK)
            node = moveRightRed(node);
        if(record.value == node->record.value)
        {
            Tree *aux = searchSmaller(node->right);
            node->record = aux->record;
            node->right = removeSmaller(node->right);
        }
        else{
            node->right = removeNode(node->right, record);
        }
    }
    return balance(node);
}

void removeTree(Tree **tree, Record record)
{
    Tree *node = *tree;
    *tree = removeNode(node, record);
    if(*tree != NULL)
        (*tree)->color = BLACK;
    cout<<"\n Produto chegou ao fim e foi removido do banco de dados!";
}

//Funções adicionais


bool vender(Tree** tree, Record record, int quantidade)
{
    Tree *aux = CreateTree();
    if(search(tree, &aux, record))
    {
        if(aux->record.quantidade <= quantidade)
        {
            if(aux->record.quantidade < quantidade)
                cout<<"\n Foi possível efetuar a venda de somente "<<aux->record.quantidade<<" Produto(s) (Estoque vazio)!";
            removeTree(tree, record);
        }
        else
            aux->record.quantidade -= quantidade;
        return true; 
    }
    else    
        return false;
}



//Funções auxiliares para verificar a construção da arvore
#define COUNT 10 
void print2DUtil(Tree *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->record.value<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
// Wrapper over print2DUtil()  
void print2D(Tree *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
} 