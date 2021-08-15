#include "fileHandling.h"

using namespace std;

vector<fileData> getFileData()
{
    vector<fileData> result;
    ifstream fin;
    string fileName;
    string dir = "./Search Engine-Data/Search Engine-Data/";
    fin.open("./Search Engine-Data/Search Engine-Data/___index.txt");

    if (!fin.is_open())
    {
        cout << "Cannot open file: " << "___index.txt";
        exit(0);
    }
    int count = 0;
    getline(fin , fileName);
    while (!fin.eof())
    {
        result.push_back(fileData(dir ,fileName));
        getline(fin, fileName);
        ++count;
        if (count % 1000 == 0)
        {
            cout << count << endl;
        }
        
    }

    fin.close();

    return result;
}
fileData getStopWord()
{
    string dir = "./data/";
    return fileData(dir, "stopword.txt");
}


fileData::fileData(string dir ,string fileName)
{

   // phan nay la 1
   vector<string> input;
   dir+=fileName;

   ifstream iFile;
   iFile.open(dir);
   if (!iFile.is_open())
   {
       cout << "cannot open file: " << fileName;
       exit(0);
   }

   string word;
   while (iFile >> word)
   {
       word = lowCase(word);
       if (checkSymbol(word).size() != 0)
           input.push_back(checkSymbol(word));
   }
   iFile.close();

   this->data.insertTrie(input);


    string line =fileName;
    vector<string> input2(splitWord(line));
    for(int i=0;i<input2.size();i++)
    {
        lowCase(input2[i]);
    }

    string temp=deleteTxt(input2[input2.size()-1]);
    input2.pop_back();
    input2.push_back(temp);

    //--------------------------------------------
    this->titleData.insertTrie(input2);

    string tmpstring;
    price tmpPrice;
    for (int i = 0; i < input.size(); ++i)
    {
       if (isPrice(input[i]))
       {
           tmpstring = "";
           
           for (int j = 1; j < input[i].size(); ++j)
           {
               tmpstring += input[i][j];
           }

           tmpPrice.amount = stoi(tmpstring);
           tmpPrice.place = i;
       }
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

vector<string> splitWord(string S)
{
   vector<string> rs;
   string T;  
   
    
   
    stringstream X(S); 
    while (getline(X, T, ' ')) {  

     rs.push_back(T);
    }  
   return rs;
}


bool isPrice(string input)
{
    if (input[0] != '$')
        return 0;

    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] < '0' && input[i] > '9')
            return 0;
    }

    return 1;
}