#include "AVL_Tree.hpp"

Tree_AVL *createTree_AVL() { return NULL; }

void insertItem_AVL(Tree_AVL **t, Record_AVL item) 
{
	Tree_AVL *newNode = new Tree_AVL;
	newNode -> item = item;
	newNode -> esq = NULL;
	newNode -> dir = NULL;
	newNode -> peso = 0;

	if (*t == NULL)
	{
		*t = newNode;
	}
	else
	{
		Tree_AVL *current = *t;

		while (current != nullptr)
		{
			if(item.key == (*t)->item.key)
			{
				if (current->esq == nullptr) 
				{
					current->esq = newNode;
					return;
				}
				current = current->esq;

				if (getPeso(&(*t)->esq) - getPeso(&(*t)->dir) == 2) 
				{
					if (item.key < (*t)->esq->item.key)
						rotacaoSimplesDireita_AVL(t);
					else
						rotacaoDuplaDireita_AVL(t);
				}
			} 
			else if (item.key < (*t)->item.key) 
			{
				if(item.key == (*t)->item.key)
				{
					if (current->esq == nullptr) 
					{
						current->esq = newNode;
						return;
					}
					current = current->esq;

					if (getPeso(&(*t)->esq) - getPeso(&(*t)->dir) == 2) 
					{
						if (item.key < (*t)->esq->item.key)
							rotacaoSimplesDireita_AVL(t);
						else
							rotacaoDuplaDireita_AVL(t);
					}
				}
			}
			else if (item.key > (*t)->item.key) 
			{
				if (current->dir == nullptr) 
				{
					current->dir = newNode;
					return;
				}
				current = current->dir;

				if (getPeso(&(*t)->dir) - getPeso(&(*t)->esq) == 2) 
				{
					if (item.key > (*t)->dir->item.key)
						rotacaoSimplesEsquerda_AVL(t);
					else
						rotacaoDuplaEsquerda_AVL(t);
				}
			}
		}

		(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	}
}

void preordem_AVL(Tree_AVL *t, ofstream &arquivo) 
{
	if (!(t == NULL)) 
	{
		arquivo << t->item.name << ": " << t->item.key << " | ";
		preordem_AVL(t->esq, arquivo);
		preordem_AVL(t->dir, arquivo);
	}
}

void central_AVL(Tree_AVL *t, ofstream &arquivo)
{
	if (!(t == NULL)) 
	{
		central_AVL(t->esq, arquivo);
		arquivo << t->item.name << ": " << t->item.key << " | ";
		central_AVL(t->dir, arquivo);
	}
}

void posordem_AVL(Tree_AVL *t, ofstream &arquivo) 
{
	if (!(t == NULL)) 
	{
		preordem_AVL(t->esq, arquivo);
		preordem_AVL(t->dir, arquivo);
		arquivo << t->item.name << ": " << t->item.key << " | ";
	}
}

int getPeso(Tree_AVL **t) 
{
	return (*t == NULL) ? -1 : (*t)->peso;
}

int getMaxPeso(int left, int right) 
{
	return (left > right) ? left : right;
}

void rotacaoSimplesDireita_AVL(Tree_AVL **t) 
{
	Tree_AVL *aux;

	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = *t;
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(&aux->esq), (*t)->peso) + 1;
	*t = aux;
}

void rotacaoSimplesEsquerda_AVL(Tree_AVL **t) 
{
	Tree_AVL *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = *t;
	(*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
	aux->peso = getMaxPeso(getPeso(&aux->dir), (*t)->peso) + 1;
	*t = aux;
}

void rotacaoDuplaDireita_AVL(Tree_AVL **t) 
{
	rotacaoSimplesEsquerda_AVL(&(*t)->esq);
	rotacaoSimplesDireita_AVL(t);
}

void rotacaoDuplaEsquerda_AVL(Tree_AVL **t) 
{
	rotacaoSimplesDireita_AVL(&(*t)->dir);
	rotacaoSimplesEsquerda_AVL(t);
}

void free_AVL(Tree_AVL *t) 
{
	if (t != NULL) 
	{
		free_AVL(t->esq);
		free_AVL(t->dir);
		free(t);
	}
}