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

	DrawMain();
	GotoXY(21, 15);
	getline(cin, query);
	Sleep(500);
	system("CLS");

	char status = 'y';
	while (status != 'x') {
	    result = search(docData, stopwordData,  query);

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
			while (status == 'n') {
				system("CLS");
				displaySearchResult(fin,result);
				cout << endl;
				displayOption(status);
			}
			system("CLS");
			DrawMain();
			GotoXY(21, 15);
			cin.ignore();
			getline(cin, query);
			Sleep(500);
			system("CLS");
		}
    }


	return 0;
}