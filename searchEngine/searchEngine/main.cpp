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
	/*searchData tmp;
	tmp.fileName = "1.txt";
	tmp.place.push_back(10);
	result.push_back(tmp);
	tmp.fileName = "000.txt";
	result.push_back(tmp);*/
	char status = 'n';
	
	DrawMain();
	GotoXY(21, 15);
	getline(cin, query);
	Sleep(500);
	system("CLS");
		
	while (status != 'x') {
	    result = search(docData, stopwordData,  query);

		displaySearchResult(fin, result);

		cout << endl;
		displayOption(status);

		switch (status) {
		case 'x':
			exit(1);
			break;
		case 'y':
			system("CLS");
			DrawMain();
			GotoXY(21, 15);
			cin.ignore();
			getline(cin, query);
			Sleep(500);
			system("CLS");
			break;
		case 'n':
			while (status == 'n') {
				system("CLS");
				displaySearchResult(fin, result);
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
			break;
		default:
			break;
		}
    }


	return 0;
}