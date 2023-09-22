#include "Binary_Tree.hpp"

Tree *createTree() 
{
	return NULL;
}

void insertItem(Tree **t, Record r) 
{
	Tree *newNode = new Tree;
	newNode->reg = r;
	newNode->esq = nullptr;
	newNode->dir = nullptr;

	if (*t == NULL) 
	{
		*t = newNode;
	} 
	else 	
	{
		Tree *current = *t;
		while (current != nullptr) 
		{
			if (r.key < current->reg.key) 
			{
				if (current->esq == nullptr) 
				{
					current->esq = newNode;
					return;
				}
				current = current->esq;
			} 
			else 
			{
				if (current->dir == nullptr) 
				{
					current->dir = newNode;
					return;
				}
				current = current->dir;
			}
		}
	}
}

void preordem(Tree *t, ofstream &arquivo) 
{
	if (!(t == NULL)) 
	{
		arquivo << t->reg.name << ": " << t->reg.key << " | ";
		preordem(t->esq, arquivo);
		preordem(t->dir, arquivo);
	}
}

void inordem(Tree *t, ofstream &arquivo) 
{
	if (!(t == NULL)) 
	{
		inordem(t->esq, arquivo);
		arquivo << t->reg.name << ": " << t->reg.key << " | ";
		inordem(t->dir, arquivo);
	}
}

void posordem(Tree *t, ofstream &arquivo) 
{
	if (!(t == NULL)) 
	{
		posordem(t->esq, arquivo);
		posordem(t->dir, arquivo);
		arquivo << t->reg.name << ": " << t->reg.key << " | ";
	}
}

void freeRaiz_1(Tree *t) 
{
	if (t != NULL) 
	{
		freeRaiz_1(t->esq);
		freeRaiz_1(t->dir);
		free(t);
	}
}