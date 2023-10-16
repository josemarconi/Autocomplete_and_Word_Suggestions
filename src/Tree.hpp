#ifndef TREE_HPP
#define TREE_HPP

#include "Binary_Tree.hpp"
#include "AVL_Tree.hpp"
#include "Huffman_Tree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void CommumBinary(vector<pair<string, int>> tree, string input, string textos, ofstream &arquivo);

void AVL(vector<pair<string, int>> tree, string input, string textos, ofstream &arquivo);

void Huffman_T(vector<pair<string, int>> tree, string input, string textos, ofstream &arquivo);

#endif  
