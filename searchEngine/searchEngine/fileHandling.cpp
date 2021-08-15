#include "fileHandling.h"

using namespace std;




fileData::fileData(string fileName)
{
    // phan nay la 1
    vector<string> input;
    string fileName = "‪";
    string dir = "C:/Users/BarryAllen/Desktop/testthu.txt";
    //dir+=fileName;
    vector<int> price;
    string s1;

    ifstream iFile;
    iFile.open(dir);
    char c;
    string word;
    int count = 0;
    while (iFile >> word)
    {
        word = lowCase(word);

        if (checkSymbol(word).size() != 0)
            input.push_back(checkSymbol(word));
    }
    iFile.close();

    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << endl;
    }


    //phan nay theo yeu cau 2 

    vector<string> input;
    string fileName = "test.txt";
    string dir = "C:/Users/BarryAllen/Desktop/";
    dir += fileName;
    ifstream iFile;
    iFile.open(dir);
    string line;
    while (getline(iFile, line))
    {
        lowCase(line);
        input.push_back(deleteTxt(line));
    }
    iFile.close();
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << endl;
    }

}




//-- ham ho tro

string lowCase(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = (char)tolower(s[i]);

    }
    return s;
}


string checkSymbol(string s)
{
    char symbol[] = { 33,34,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126 };
    int lenght = s.length();
    string s1 = {};
    for (int i = 0; i < 25; i++)
    {
        if (s[0] == symbol[i])
        {
            s[0] = ' ';
        }
        if (s[lenght - 1] == symbol[i])
        {
            s[lenght - 1] = ' ';
        }
    }
    for (int i = 0; i < lenght; i++)
    {
        if (s[i] != ' ')
            s1 += s[i];
    }
    return s1;
}


string deleteTxt(string s)
{
    string s1;
    for (int i = 0; i < s.length() - 4; i++)
    {

        s1 += s[i];
    }
    return s1;
}

