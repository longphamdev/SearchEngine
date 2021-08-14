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
        if (input[i] > 'z' && input[i] < 'a' && input[i] < '0' && input[i] > '9' && input[i] != '#' && input[i] != '$' && input[i] != '-')
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


    vector <int> tmpSearchResult;
    //exact search (and wild card I guess...)
    string firstWord = cutQuery[0];
    string lastWord = cutQuery[cutQuery.size() - 1];
    if (firstWord[0] == '"' && lastWord[lastWord.size() - 1] == '"')
    {
        // preprocess the query first
        for (int i = 0; i < cutQuery.size(); ++i)
        {
            preprocess_exactSearch(cutQuery[i]);
        }

        // then search all the doc
        for (int i = 0; i < docData.size(); ++i)
        {
            result[i].place = exactSearch(docData[i], cutQuery);           //scoring each file
            result[i].score = result[i].place.size();
        }

        // select top 5 and return
        return selectTop5(result);
    }


    //intitle search


    //now preprocess the query in normal way

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

    //select top 5 and return
    
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
    
    // check if every word is in the file
    for (int i = 0; i < query.size(); ++i)
    {
        if (query[i] == "*")
            continue;

        if (normalSearch(file, query[i]).size() == 0)
            return empty;
    }

    vector<int> firstWordLocation = normalSearch(file, query[0]);

    ifstream fin;

    fin.open(file.fileName);

    if (!fin.is_open())
    {
        cout << "Cannot open file: " << file.fileName;
        exit(0);
    }

    bool check;
    bool fileCounter = 0;
    string tmp;
    for (int i = 0; i < firstWordLocation.size(); ++i)
    {
        check = false;
        // go to the location of the firstword

        while (fileCounter != firstWordLocation[i])
        {
            fin >> tmp;
            ++fileCounter;
        }

        for (int j = 0; j < query.size(); ++j)
        {
            fin >> tmp;
            if (tmp != query[i + j])
                break;

            // push all location to the array if it is the end of the query
            if (j == query.size() - 1)
            {
                for (int t = 0; t < query.size(); ++t)
                {
                    empty.push_back(fileCounter - j + t);
                }
            }
        }
    }

    fin.close();
    return empty;
}


int getMax(vector<int>& arr)
{
    int n = arr.size();
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    int * output = new int[n]; // output array

    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];

    delete [] output;
}
void radixsort(vector<int>& arr)
{
    int n = arr.size();
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}


vector<searchData> selectTop5(vector<searchData>& searchResult)
{
    vector<searchData> result;
    vector<int> positiveScore;
    
    for (int i = 0; i < searchResult.size(); ++i)
    {
        if (searchResult[i].score > 0)
            positiveScore.push_back(searchResult[i].score);
    }

    radixsort(positiveScore);

    int n;
    if (positiveScore.size() < 5)
        n = positiveScore.size();
    else
        n = 5;
    for (int i = 0; i < searchResult.size(); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (positiveScore[j] == searchResult[i].score)
                result.push_back(searchResult[i]);
        }
    }

    return result;
}