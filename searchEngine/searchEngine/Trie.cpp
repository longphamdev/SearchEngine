#include "Trie.h"


trieNode::trieNode()
{
    for (int i = 0; i < 38; ++i)
    {
        this->child[i] = NULL;
    }
}

void copyTrieNode(trieNode* origin, trieNode* copy) 
{
    if (origin)
        copy = new trieNode;
    else return;

    for (int i = 0; i < 38; ++i)
    {
        copyTrieNode(origin->child[i], copy->child[i]);
    }
}


void trie::insertTrie(vector<string> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        insert(this->root, input[i], i);
    }
}
bool trie::isEmpty(trieNode*root) {
    for (int i = 0; i < 38; i++) {
        if (root->child[i])
            return false;
    }
    return true;
}

trie::trie() {
    root = new trieNode;
}

trie::trie(const trie& origin)
{
    this->root = NULL;
    copyTrieNode(origin.root, this->root);
}

trie::~trie() {
    deleteTrie(root);
}

void deleteTrie(trieNode* root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < 38; ++i)
    {
        deleteTrie(root->child[i]);
    }
    delete root;
}

void insert(struct trieNode* root, string key, int place)
{
    trieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index;

        if (key[i] >= 'a' && key[i] <= 'z')
            index = key[i] - 'a';

        else if (key[i] >= '0' && key[i] <= '9')
            index = key[i] - '0' + 26;

        else if (key[i] == '#')
            index = 36;
        else if (key[i] == '$')
            index = 37;
        else continue;

        if (!pCrawl->child[index])
            pCrawl->child[index] = new trieNode;

        pCrawl = pCrawl->child[index];
    }
    // mark last node as leaf
    pCrawl->place.push_back(place);
}