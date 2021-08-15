#pragma once
#ifndef _FILEHANDLING_
#define _FILEHANDLING_
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Trie.h"
#include<string.h>


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
    string fileName;
    vector<price> priceData;
    fileData(vector<string> input, string fileName);
};







vector<fileData> getFileData(string folderName);

int get_index(char key);
#endif
