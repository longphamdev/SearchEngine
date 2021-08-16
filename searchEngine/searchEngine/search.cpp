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
    result.push_back(tmp);

    return result;
}

vector<searchData> search(const vector<fileData>& docData, const fileData& stopwordData,
const string& query)
{
    //init the searchData
    vector<searchData>  result;
    searchData tmpS;
    tmpS.score = 0;
    for (int i = 0; i < docData.size(); ++i)
    {
        tmpS.fileName = docData[i].fileName;
        result.push_back(tmpS);
    }

	//cut the query
    vector<string> cutQuery = stringToWord(query);


    vector <int> tmpSearchResult;
    ////exact search (and wild card I guess...)
    //string firstWord = cutQuery[0];
    //string lastWord = cutQuery[cutQuery.size() - 1];
    //if (firstWord[0] == '"' && lastWord[lastWord.size() - 1] == '"')
    //{
    //    // preprocess the query first
    //    for (int i = 0; i < cutQuery.size(); ++i)
    //    {
    //        preprocess_exactSearch(cutQuery[i]);
    //    }

    //    // then search all the doc
    //    for (int i = 0; i < docData.size(); ++i)
    //    {
    //        result[i].place = exactSearch(docData[i], cutQuery);           //scoring each file
    //        result[i].score = result[i].place.size();
    //    }

    //    // select top 5 and return
    //    return selectTop5(result);
    //}


    ////intitle search


    ////now preprocess the query in normal way

    //// AND *

    //// OR *

    //if (cutQuery.size() == 3)
    //{
    //    if (cutQuery[1] == "AND")
    //    {
    //        preprocess(cutQuery[0]);
    //        preprocess(cutQuery[2]);
    //        for (int j = 0; j < docData.size(); ++j)
    //        {
    //            result[j].place = findAnd(cutQuery[0], cutQuery[2], docData[j]);
    //            result[j].score = result[j].place.size();
    //        }

    //        return selectTop5(result);
    //            
    //    }
    //    else if (cutQuery[1] == "OR")
    //    {
    //        preprocess(cutQuery[0]);
    //        preprocess(cutQuery[2]);
    //        for (int j = 0; j < docData.size(); ++j)
    //        {
    //            result[j].place = findOr(cutQuery[0], cutQuery[2], docData[j]);
    //            result[j].score = result[j].place.size();

    //            return selectTop5(result);
    //        }
    //    }
    //}



    //preprocess query
    for (int i = 0; i < cutQuery.size(); ++i)
    {
        preprocess(cutQuery[i]);
    }

    ////remove stopwords (wait for trie....)


    //// start the search
	

    //
 

    //vector<int> remove;
    //string tmp;
    ////NOT *
    //for (int i = 0; i < cutQuery.size(); ++i)
    //{
    //    if (cutQuery[i][0] == '-')
    //    {
    //        tmp = "";
    //        remove.push_back(i);

    //        for (int j = 1; j < cutQuery[i].size(); ++j)
    //        {
    //            tmp = tmp + cutQuery[i][j];
    //        }

    //        for (int j = 0; j < docData.size(); ++j)
    //        {
    //            if (findNOT(tmp, docData[j]))
    //            {
    //                result[j].score -= 5;
    //            }
    //            else result[j].score += 5;
    //        }
    //    }
    //}

    ////search price range *

    ////search price *
    //for (int i = 0; i < cutQuery.size(); ++i)
    //{
    //    if (isPrice(cutQuery[i]))
    //    {
    //        tmp = "";
    //        remove.push_back(i);

    //        for (int j = 1; j < cutQuery[i].size(); ++j)
    //        {
    //            tmp = tmp + cutQuery[i][j];
    //        }

    //        for (int j = 0; j < docData.size(); ++j)
    //        {
    //            tmpSearchResult = findPrice(stoi(tmp), docData[j]);
    //            result[j].place.insert(result[j].place.end(), tmpSearchResult.begin(), tmpSearchResult.end());
    //            if (tmpSearchResult.size() == 0)
    //            {
    //                result[j].score -= 5;
    //            }
    //            else result[j].score += tmpSearchResult.size();
    //        }
    //    }
    //}

    ////synonym *

    //normal search
    for (int i = 0; i < cutQuery.size(); ++i)
    {
        for (int j = 0; j < docData.size(); ++j)
        {
            tmpSearchResult = normalSearch(docData[j], cutQuery[i]);
            result[j].place.insert(result[j].place.end(), tmpSearchResult.begin(), tmpSearchResult.end());
            result[j].score += tmpSearchResult.size();
        }
    }

    //select top 5 and return
	return selectTop5(result);
}

vector<int> normalSearch(const fileData& file, const string& key)
{
	vector<int> empty;
    trieNode* pCrawl = file.data.root;
    if (pCrawl == NULL)
        return empty;
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
            preprocess_exactSearch(tmp);
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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int Partition(vector<int>& v, int start, int end) {

    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (v[i] < v[pivot]) {
            swap(v[i], v[j]);
            ++j;
        }
    }
    swap(v[j], v[pivot]);
    return j;

}
void Quicksort(vector<int>& v, int start, int end) {

    if (start < end) {
        int p = Partition(v, start, end);
        Quicksort(v, start, p - 1);
        Quicksort(v, p + 1, end);
    }

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

    Quicksort(positiveScore, 0, positiveScore.size() - 1);
    for (int i = 0; i < 5; i++)
    {
        cout << positiveScore[positiveScore.size() - 1 - i] << endl;
    }
    int n;
    if (positiveScore.size() < 5)
        n = positiveScore.size();
    else
        n = 5;


    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < searchResult.size(); ++i)
        {
            if (positiveScore[positiveScore.size() - 1 - j] == searchResult[i].score)
            {
                result.push_back(searchResult[i]);
                searchResult.erase(searchResult.begin() + i);
                break;
            }            
        }
    }

    // sort the highlight places
    for (int i = 0; i < result.size(); ++i)
    {
        Quicksort(result[i].place, 0, result[i].place.size() - 1);
    }

    return result;
}
vector<string> removeElements(vector<string> input, vector<int> remove)
{
    vector<string> result;
    bool check = 0;
    for (int i = 0; i < input.size(); ++i)
    {
        check = 1;
        for (int j = 0; j < remove.size(); ++j)
        {
            if (i == j)
                check = 0;
        }

        if (check)
            result.push_back(input[i]);
    }

    return result;
}

vector<int> findAnd(string ss1, string ss2, const fileData& file)
{
    vector<int> rs;
    vector<int> resultSs1(normalSearch(file, ss1));
    vector<int> resultSs2(normalSearch(file, ss2));
    if (!resultSs1.empty() && !resultSs2.empty())
    {
        rs.insert(rs.end(), resultSs1.begin(), resultSs1.end());
        rs.insert(rs.end(), resultSs2.begin(), resultSs2.end());
    }
    return rs;
}
vector<int> findOr(string ss1, string ss2, const fileData& file)
{
    vector<int> rs;
    vector<int> resultSs1(normalSearch(file, ss1));
    vector<int> resultSs2(normalSearch(file, ss2));
    if (!resultSs1.empty() && !resultSs2.empty())
    {
        rs.insert(rs.end(), resultSs1.begin(), resultSs1.end());
        rs.insert(rs.end(), resultSs2.begin(), resultSs2.end());
    }
    return rs;
}
bool findNOT(string ss, const fileData& file)
{
    vector<int> rs(normalSearch(file, ss));
    if (rs.empty() == 1)
    {
        return 0;
    }
    return 1;
}
vector<int> findPrice(int amountSearch, const fileData& file)
{
    vector<int> place;
    for (int i = 0; i < file.priceData.size(); i++)
    {
        if (amountSearch == file.priceData[i].amount)
        {
            place.push_back(file.priceData[i].place);
        }
    }
    return place;
}

vector<int> findRangePrice(int amountSearch1, int amountSearch2, const fileData& file)
{
    vector<int> place;
    int tempAmount;
    for (int i = 0; i < file.priceData.size(); i++)
    {
        tempAmount = file.priceData[i].amount;
        if (amountSearch1 <= tempAmount && amountSearch2 >= tempAmount)
        {
            place.push_back(file.priceData[i].place);
        }
    }
    return place;
}


bool isPriceRange(string input)
{
    bool check = 0;
    if (input[0] != '$')
        return 0;
    bool counter = 1;

    while (counter < input.size() && !isNumber(input[counter]))
    {
        ++counter;
    }
}

bool isNumber(char input) 
{
    if (input < '0' && input > '9')
        return 0;
    return 1;
}

void displayTest(searchData searchResult)
{
    ifstream fin("./Search Engine-Data/Search Engine-Data/" + searchResult.fileName);
    if (!fin.is_open())
        cout << "cannot open file: " << searchResult.fileName;
    cout << searchResult.fileName << ": ";
    int fileCounter = 0;
    string tmp;
    for (int i = 0; i < searchResult.place.size(); ++i)
    {
        while (fileCounter < searchResult.place[i])
        {
            fin >> tmp;
            ++fileCounter;
        }
        cout << tmp << " ";
    }

    cout << endl << endl;
}