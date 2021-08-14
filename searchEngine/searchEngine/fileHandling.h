#ifndef _FILEHANDLING_
#define _FILEHANDLING_

#include "Trie.h"
#include <iostream>
#include <iosfwd>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <regex> 

#include <unordered_map>
#include <algorithm>

using namespace std;

class fileHandling {
private:
	trieNode* stopword = nullptr;
	trieNode* loadStopWord();
	void checkPunctuation(string& s);
	bool checkStopword(string str, trieNode* stopword);
	void importfileExe(unordered_map<string, int>& result, string& str, trieNode* stopword);
	regex unicode = regex("[^\\u0020-\\u0024\\u0030-\\u0039\\u0041-\\u005A\\u0061-\\u007A\\u002E]+");
public:
	vector<string> loadNameOfFiles(string file);
	unordered_map<string, int> importFile(string filename);
};

int get_index(char key);
#endif
