#include "fileHandling.h"
#include "Trie.h"

using namespace std;

trieNode* fileHandling::loadStopWord() {

	string* arr = new string[174];
	ifstream fin;
	fin.open("D:\\Project_CS163_2021\\searchEngine\\searchEngine\\data\\stopword.txt");
	if (!fin.is_open()) {
		cout << "Can not open this file!" << endl;
	}
	else {
		int i = 0;
		while (!fin.eof()) {
			fin >> arr[i];
			arr[i] = 1;
			++i;
		}
	}
	fin.close();

	trieNode* root = new trieNode;
	trieNode* tmpRoot = root;

	for (int i = 0; i < 174; i++) {
		for (int j = 0; j < arr[i].length(); j++) {
			int tmp = get_index(arr[i][j]);

			if (tmp == -1) {
				continue;
			}
			if (tmpRoot->child[tmp] == NULL) {
				tmpRoot->child[tmp] = new trieNode;
			}

			tmpRoot = tmpRoot->child[tmp];
		}
		tmpRoot->existed = true;
	}

	return root;
}

int get_index(char key) {
	if ('0' <= key && key <= '9')
		return key - '0';
	if ('a' <= key && key <= 'z')
		return key - 'a' + 10;
	if ('A' <= key && key <= 'Z')
		return key - 'A' + 10;
	if (key == '$')
		return 36;
	if (key == '#')
		return 37;
	return -1;
}