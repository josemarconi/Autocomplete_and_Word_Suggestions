#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <locale>
#define endl '\n'
using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;

struct Record {
	string name;
	int key;
};

struct Tree {
	Record reg;
	Tree *esq, *dir;
};

Tree *createTree();

void insertItem(Tree **t, Record r);

void preordem(Tree *t, ofstream &arquivo);
void inordem(Tree *t, ofstream &arquivo);
void posordem(Tree *t, ofstream &arquivo);

void freeRaiz_1(Tree *t);

#endif 