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