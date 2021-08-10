#include "search.h"

void preprocess(string& input)
{
    int Aa = 'A' - 'a';

    for (int i = 0; i < input.size(); ++i)
    {

    }

    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] > 'z' && input[i] < 'a' && input[i] < '0' && input[i] > '9' && input[i] != '#' && input[i] != '$' && input[i] != '*' 
            && input[i] != '"')
        {

        }
    }
}

vector<searchData> search(const vector<fileData>& docData, const vector<fileData>& stopwordData,
    const vector<fileData>& synonymData, const string& query)
{
	//cut the query

    //preprocess query

    //remove stopwords 

	vector<searchData>  result;

    //exact search (and wild card)
 
    //intitle search

    // AND *

    // OR *

    //search price range *

    //search price *

    //synonym *

    //normal search

    //sort search result
	return result;
}

vector<int> normalSearch(const fileData& file, const string& key)
{
	vector<int> empty;
    trieNode* pCrawl = file.data.root;

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



vector<int> exactSearch(const fileData& file, const vector<string>& query)
{
    vector<int> empty;
    
    return empty;
}


