#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <locale>
#include <string>
#define endl '\n'
using namespace std;

typedef struct Record_AVL Record_AVL;
typedef struct Tree_AVL Tree_AVL;

struct Record_AVL {
	string name;
	int key;
};

struct Tree_AVL {
	Record_AVL item;
	Tree_AVL *esq, *dir;
	int peso;
};

Tree_AVL *createTree_AVL();

void insertItem_AVL(Tree_AVL **t, Record_AVL r);

void preordem_AVL(Tree_AVL *t, ofstream &arquivo);
void central_AVL(Tree_AVL *t, ofstream &arquivo);
void posordem_AVL(Tree_AVL *t, ofstream &arquivo);

int getPeso(Tree_AVL **t);
int getMaxPeso(int left, int right);

void rotacaoSimplesDireita_AVL(Tree_AVL **t);
void rotacaoSimplesEsquerda_AVL(Tree_AVL **t);
void rotacaoDuplaDireita_AVL(Tree_AVL **t);
void rotacaoDuplaEsquerda_AVL(Tree_AVL **t);

void free_AVL(Tree_AVL *t);
#endif