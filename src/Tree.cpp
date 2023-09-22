#include "Tree.hpp"

void CommumBinary(vector<pair<string, int>> tree, string input, string textos, ofstream &arquivo)
{
    Tree *t = createTree();

    Record aux;

    for (const auto& pair : tree)
    {
        aux.name = pair.first;
        aux.key = pair.second; 

        insertItem(&t, aux);
    }

    inordem(t, arquivo);

    freeRaiz_1(t);
}

void AVL(vector<pair<string, int>> tree, string input, string textos, ofstream &arquivo)
{
    Tree_AVL *t = createTree_AVL();

    Record_AVL aux;

    for (const auto& pair : tree)
    {
        aux.name = pair.first;
        aux.key = pair.second;

        insertItem_AVL(&t, aux);
    }

    posordem_AVL(t, arquivo);

    free_AVL(t);
}

void Huffman_T(vector<pair<string, int>> tree, string input, string textos, ofstream &arquivo)
{
    Huffman_Tree H_Tree;


    for (const auto& pair : tree)
    {
        H_Tree.insere(make_shared<NO_Huffman>(pair.first, pair.second));
    }

    H_Tree.constroi();

    H_Tree.imprime(arquivo);
}