#include "Huffman_tree.hpp"

void Huffman_Tree::insere(std::shared_ptr<NO_Huffman> no)
{
	this->filaPrioridade_.push_back(no);
}

void Huffman_Tree::constroi()
{
	while (this->filaPrioridade_.size() > 1) 
	{
		std::shared_ptr<NO_Huffman> x = this->filaPrioridade_[0];
		std::shared_ptr<NO_Huffman> y = this->filaPrioridade_[1];

		auto z = std::make_shared<NO_Huffman>("#", x->getFrequencia() + y->getFrequencia());

		z->setEsquerda(x);

		z->setDireita(y);

		this->filaPrioridade_.erase(this->filaPrioridade_.begin());

		this->filaPrioridade_.erase(this->filaPrioridade_.begin());

		this->insere(z);

		sort(this->filaPrioridade_.begin(), this->filaPrioridade_.end(), NO_Huffman::compara);
	}

	this->raiz_ = this->filaPrioridade_[0];
}

void Huffman_Tree::preOrdem(std::shared_ptr<NO_Huffman> no, ofstream &arquivo) 
{
	string code="";

	queue<pair<std::shared_ptr<NO_Huffman>, string>> q;

    q.push({no, code});

	while (!q.empty()) 
	{
		pair<std::shared_ptr<NO_Huffman>, string> currentPair = q.front();
		q.pop();

		std::shared_ptr<NO_Huffman>	current = currentPair.first;
		string currentCode = currentPair.second;

		if (current->getEsquerda() == nullptr && current -> getDireita() == nullptr) 
		{
            arquivo << "[" << currentCode << "] = " << current ->getPalavra() << ": " << current -> getFrequencia() << "  |  ";
        }

        if (current->getEsquerda())
            q.push({current->getEsquerda(), currentCode + "0"});

        if (current->getDireita())
            q.push({current->getDireita(), currentCode + "1"});
	}
}

void Huffman_Tree::posOrdem(std::shared_ptr<NO_Huffman> no, ofstream &arquivo) 
{
	if (no != nullptr) 
	{
		this->posOrdem(no->getEsquerda(), arquivo);
		this->posOrdem(no->getDireita(), arquivo);

		if (no->getPalavra() != "#") 
		{
			arquivo << no->getPalavra() << ": " << no->getFrequencia() << " | ";
		}
	}
}

void Huffman_Tree::central(std::shared_ptr<NO_Huffman> no, ofstream &arquivo) 
{
	if (no != nullptr) 
	{
		this->central(no->getEsquerda(), arquivo);

		if (no->getPalavra() != "#") 
		{
			arquivo << no->getPalavra() << ": " << no->getFrequencia() << " | ";
		}

		this->central(no->getDireita(), arquivo);
	}
}

void Huffman_Tree::imprime(ofstream &arquivo) 
{
	this->preOrdem(this->raiz_, arquivo);
}