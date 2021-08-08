#include "search.h"

vector<searchData> search(vector<fileData> docData, vector<fileData> stopwordData, vector<fileData> synonymData, string query)
{
	//do something :v
	vector<searchData>  result;
	//do something :v
	return result;
}

vector<int> normalSearch(trieNode* root, string key)
{
	vector<int> empty;
    trieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        
        int index;

        if (key[i] >= 'a' && key[i] <= 'z')
            index = key[i] - 'a';

        else if (key[i] >= '0' && key[i] <= '9')
            index = 26 + key[i] - '0';

        else if (key[i] == '#')
            index = 36;
        else index = 37;

        if (!pCrawl->child[index])
            return empty;

        pCrawl = pCrawl->child[index];
    }

    return (pCrawl->place);
	
}
