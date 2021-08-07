#ifndef _TRIE_
#define _TRIE_

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
class TrieNode {
public:
	unordered_map <string, int> data;
	TrieNode* child[38];
	bool exist = false;
	void trieTraverse(TrieNode* head);
};
class Trie {
private:
	TrieNode* root = nullptr;
	void __clear(TrieNode* node);

public:
	vector <pair <string, int>> search(string keyword);
	void build(string key, unordered_map<string, int> data);

	void save(string filename);

	void load(string filename);

	void clear();

	bool isEmpty();

	void trieTraverse();

};
int get_index(char key);
#endif