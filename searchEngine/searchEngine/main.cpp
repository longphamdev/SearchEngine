#include "Trie.h"
#include "search.h"
#include "query1.h"
#include "UI.h"

int main()
{
	ifstream fin;
	string query;

	auto start = high_resolution_clock::now();
	const vector<fileData> docData = getFileData();
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);

	fileData stopwordData = getStopWord();
	const vector<synonymData> synoData = getSynonym();
	vector<searchData> result;
	cout <<"Time load is: "<< duration.count()<<" s" << endl;
	Sleep(10000);
	system("CLS");
	DrawMain();
	GotoXY(21, 15);
	getline(cin, query);
	Sleep(500);
	system("CLS");

	char status = 'y';
	while (status != 'x') {
		auto start = high_resolution_clock::now();
		result = search(docData, stopwordData, synoData, query);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		

		displaySearchResult(fin, result,duration);

		cout << endl;
		displayOption(status);

		switch (status) {
		case 'x':
			exit(1);
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
				displaySearchResult(fin, result,duration);
				cout << endl;
				displayOption(status);
			}
			if (status == 'x') exit(0);
			system("CLS");
			DrawMain();
			GotoXY(21, 15);
			cin.ignore();
			getline(cin, query);
			Sleep(500);
			system("CLS");
			break;
		default:
			system("CLS");
			break;
		}

    }


	return 0;
}