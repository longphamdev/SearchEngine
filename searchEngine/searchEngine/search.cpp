#include "search.h"

void preprocess_exactSearch(string& input)
{
    int Aa = 'A' - 'a';
    string tmp = "";
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] <= 'Z' && input[i] >= 'A')
        {
            input[i] -= Aa;
        }
    }

    // i am so lazy
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] > 'z' && input[i] < 'a' && input[i] < '0' && input[i] > '9' && input[i] != '#' && input[i] != '$' && input[i] != '*')
        {
            continue;
        }
        tmp += input[i];
    }

    input = tmp;
}

void preprocess(string& input)
{
    int Aa = 'A' - 'a';
    string tmp = "";
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] <= 'Z' && input[i] >= 'A')
        {
            input[i] -= Aa;
        }
    }

    // i am so lazy
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] > 'z' && input[i] < 'a' && input[i] < '0' && input[i] > '9' && input[i] != '#' && input[i] != '$' && input[i] != '*' 
            && input[i] != '"'  && input[i] != '-')
        {
            continue;
        }
        tmp += input[i];
    }

    input = tmp;
}

vector<string> stringToWord(const string& input)
{
    vector<string> result;
    string tmp;

    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == ' ')
        {
            result.push_back(tmp);
            tmp = "";
        }
        else
            tmp += input[i];
    }

    return result;
}

// 
// 

vector<searchData> search(const vector<fileData>& docData, const vector<fileData>& stopwordData,
    const vector<fileData>& synonymData, const string& query)
{
    vector<searchData>  result;

	//cut the query
    vector<string> cutQuery = stringToWord(query);

    //exact search (and wild card I guess...)
    string firstWord = cutQuery[0];
    string lastWord = cutQuery[cutQuery.size() - 1];
    if (firstWord[0] == '"' && lastWord[lastWord.size() - 1] == '"')
    {

    }
    //intitle search

    // AND *

    // OR *

    if (cutQuery.size() == 3)
    {
        if (cutQuery[1] == "AND")
        {
            preprocess(cutQuery[0]);
            preprocess(cutQuery[2]);
            //call AND search
        }
        else if (cutQuery[1] == "OR")
        {
            preprocess(cutQuery[0]);
            preprocess(cutQuery[2]);
            //call OR search
        }
    }



    //preprocess query
    for (int i = 0; i < cutQuery.size(); ++i)
    {
        preprocess(cutQuery[i]);
    }

    //remove stopwords (wait for trie....)


    // start the search
	

    
 


    //NOT *

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

    vector<int> firstWordLocation = normalSearch(file, query[0]);

    for (int i = 0; i < query.size(); ++i)
    {
        if (query[i] == "*")
            continue;

        if (normalSearch(file, query[i]).size() == 0)
            return empty;
    }

    //for (int i )

    return empty;
}


