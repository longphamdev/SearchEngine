#include "Trie.h"


trieNode::trieNode()
{
    for (int i = 0; i < 38; ++i)
    {
        this->child[i] = NULL;
    }
}


trie::trie(vector<string> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        insert(this->root, input[i], i);
    }
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
            index = key[i] - '0';

        else if (key[i] == '#')
            index = 36;
        else index = 37;

        if (!pCrawl->child[index])
            pCrawl->child[index] = new trieNode;

        pCrawl = pCrawl->child[index];
    }
    // mark last node as leaf
    pCrawl->place.push_back(place);
}