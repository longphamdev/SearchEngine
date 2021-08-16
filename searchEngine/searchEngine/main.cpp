#include "Trie.h"
#include "search.h"
#include "query1.h"
#include "UI.h"

int main()
{
	ifstream fin;
	string query;
	const vector<fileData> docData = getFileData();
	fileData stopwordData = getStopWord();
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
		
	result = search(docData, stopwordData,  query);
	


	for (int i = 0; i < 2; i++) {
		TextColor(241);
		cout << "[ " << i+1 << " ]";
		cout << result[i].fileName << endl;
		TextColor(240);
		string temp;
		fin.open("./Search Engine-Data/Search Engine-Data/" + result[i].fileName);
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
	fin.open("./Search Engine-Data/Search Engine-Data/" + result[choose -1].fileName);
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

	
		//vector<fileData> test;
		//
		//test.push_back(tmp);
	DrawMain();

	GotoXY(21, 15);
	getline(cin, query);
	Sleep(500);
	system("CLS");

	char status = 'y';
	//result = search(docData, stopwordData, synonymData,  query);

	while (status != 'x'){
		displaySearchResult(fin, result);

		cout << endl;
		displayOption(status);

	    if (status == 'x') {
			exit(1);
	    }
	    if (status == 'y') {
			system("CLS");
		    DrawMain();
			GotoXY(21, 15);
			cin.ignore();
			getline(cin, query);
			Sleep(500);
			system("CLS");
	    }
		if (status == 'n') {
			system("CLS");
		}
    }


	return 0;
}