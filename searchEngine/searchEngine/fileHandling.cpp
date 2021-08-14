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
bool fileHandling::checkStopword(string str, trieNode* stopword) {
	if (stopword == nullptr) {
		return false;
	}
	for (int i = 0; i < str.length(); i++) {
		int tmp = get_index(str[i]);
		if (stopword->child[tmp] == nullptr) {
			return false;
		}
		else stopword = stopword->child[tmp];
	}
	if (stopword) {
		return stopword->existed;
	}
	else return false;
}
void fileHandling::importfileExe(unordered_map<string, int>& result, string& str, trieNode* stopword) {

	for (int i = 0; i < str.length(); ++i)
		if (get_index(str[i]) == -1) str[i] = ' ';

	stringstream ss;
	ss << str;
	str = "";

	while (!ss.eof())
	{
		ss >> str;
		if (!this->checkStopword(str, stopword) && ! str.empty())
		{
			result[str] += 1;
		}
	}
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

void fileHandling::checkPunctuation(string& s) {
	for (int i = 0, length = s.size(); i < length; i++) {
		if (ispunct(s[i])) {
			s.erase(i--, 1);
			length = s.size();
		}
	}
}

vector<string>fileHandling::loadNameOfFiles(string file) {
	ifstream fin;
	fin.open(file);
	if (!fin.is_open()) {
		cout << "Can not load the file!" << endl;
		return vector<string>();
	}

	else cout << "Successfully !" << endl;

	char c;
	string tmp = "";
	vector<string> result;
	while (fin.get(c))
	{
		if (c == '\n') continue;
		tmp.push_back(c);
		if (tmp.find("txt", 0) != string::npos)
		{
			tmp = regex_replace(tmp, this->unicode, "");
			cout << tmp << endl;
			result.push_back(tmp);
			tmp = "";
		}
	}
	cout << "Read all the files!...Done!" << endl;

	return result;
}
unordered_map<string, int>fileHandling::importFile(string filename) {
	ifstream fin;
	unordered_map<string, int> result;
	fin.open(filename);
	if (!fin.is_open())
	{
		return result;
		//cout << "Open file error" << endl;
		//err << filename << endl;
	}
	else
	{
		string temp;
		while (!fin.eof())
		{
			getline(fin, temp, '\n');
			temp = regex_replace(temp, this->unicode, " ");
			this->importfileExe(result, temp, this->stopword);
		}
		fin.close();
	}
	return result;
}

