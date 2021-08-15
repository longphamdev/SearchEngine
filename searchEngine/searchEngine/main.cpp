#include "Trie.h"
#include "search.h"
#include "query1.h"
#include "UI.h"





int main()
{
	ifstream fin;
	string query;
	const vector<fileData> docData;
	const vector<fileData> stopwordData;
	const vector<fileData> synonymData;
	vector<searchData> result;
	searchData tmp;
	tmp.fileName = "1.txt";
	tmp.place.push_back(10);
	result.push_back(tmp);
	tmp.fileName = "000.txt";
	result.push_back(tmp);

	DrawMain();
	GotoXY(21, 15);
	getline(cin, query);
	Sleep(500);
	system("CLS");
		
	//result = search(docData, stopwordData, synonymData,  query);
	

	for (int i = 0; i < 2; i++) {
		TextColor(241);
		cout << "[ " << i+1 << " ]";
		cout << result[i].fileName << endl;
		TextColor(240);
		string temp;
		fin.open("C:/Users/tin85/OneDrive/Máy tính/GitHub/SearchEngine/searchEngine/searchEngine/Search Engine-Data/Search Engine-Data/" + result[i].fileName);
		if (!fin.is_open()) {
			cout << "Can not open file";
		}
		else {
			for (int j = 0; j < 3; j++) {
				getline(fin, temp);
				cout << temp;
			}
			cout << endl;
			cout << "--------------------------------------------------------- " << endl;
		}
		fin.close();
	}

	int choose;
	cout << "Select chosen file: ";
	cin >> choose;
	Sleep(500);
	system("CLS");

	string temp;
	fin.open("C:/Users/tin85/OneDrive/Máy tính/GitHub/SearchEngine/searchEngine/searchEngine/Search Engine-Data/Search Engine-Data/" + result[choose -1].fileName);
	if (!fin.is_open()) {
		cout << "Can not open file";
	}
	else {
		while (!fin.eof()) {
			getline(fin, temp);
			cout << temp;
		}
	}
	fin.close();

	//vector<fileData> docData = getFileData();
	////vector<fileData> test;
	////fileData tmp = getStopWord();
	////test.push_back(tmp);
	return 0;
}