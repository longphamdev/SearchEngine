#ifndef _FILEHANDLING_
#define _FILEHANDLING_

#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class fileHandling {
private:
	trieNode* stopword = nullptr;
	trieNode* loadStopWord();

public:

};

int get_index(char key);
#endif
