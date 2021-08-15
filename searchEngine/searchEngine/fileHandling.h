#pragma once
#ifndef _FILEHANDLING_
#define _FILEHANDLING_
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Trie.h"
#include<string.h>
#include<sstream>


using namespace std;

struct price {
    int amount;
    int place;
};

struct synonymData {
    trie data;
    vector<string> words;
};

struct fileData
{
public:
    trie data;
    trie titleData;
    string fileName;
    vector<price> priceData;
    fileData(string dir, string fileName);
};









vector<fileData> getFileData();
vector<synonymData> getSynonym();
fileData getStopWord();

int get_index(char key);


//--------------------ham ho tro
string lowCase(string s);
string checkSymbol(string s);
string deleteTxt(string s);
vector<string> splitWord(string S);
bool isPrice(string input);
#endif
