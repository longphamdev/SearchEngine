#include "Trie.h"

int get_index(char key){
	if ('0' <= key && key <= '9')
		return key - '0';
	if ('a' <= key && key <= 'z')
		return key - 'a' + 10;
	if ('A' <= key && key <= 'Z')
		return key - 'A' + 10;
	if (key == '$')
		return 36;
	if (key == '#')
		return 37;
	return -1;
}

void Trie::build(string filename, unordered_map<string, int>data) {
	if (data.size() == 0) return;
	TrieNode* root = this->root;
	for (auto it : data) {
		string key = it.first;
		if (root == nullptr)
			root = new TrieNode;
		TrieNode* tmproot = root;
		for (int i = 0; i < key.length(); ++i)	{
			int tmp = get_index(key[i]);
			if (tmp == -1)
				continue;
			if (tmproot->child[tmp] == nullptr)
				tmproot->child[tmp] = new TrieNode;
			tmproot = tmproot->child[tmp];
		}
		tmproot->data[filename] += it.second;
	}

	if (!this->root) 
		this->root = root;
}