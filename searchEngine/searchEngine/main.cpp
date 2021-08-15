#include "Trie.h"
#include "search.h"
#include "query1.h"
#include "UI.h"





int main()
{
	/*ifstream fin;
	ofstream fout;
	string query;
	const vector<fileData> synonymData;
	const vector<fileData> stopwordData;
	const vector<fileData> docData;
	vector<searchData> result;
	DrawMain();
	GotoXY(21, 15);
	getline(cin, query);

	result = search(docData, stopwordData,
		synonymData, query);

	for (int i = 0; i < 5; i++) {
		TextColor(12);
		cout << result[i].fileName << endl;
		TextColor();
		string temp;
		fin.open(result[i].fileName);
		if (!fin.is_open()) {
			cout << "Cannot open file" << endl;
		}
		else {
			for (int i = 0; i < 3; i++) {
				getline(fin, temp);
				cout << temp;
			}

		}
		fin.close();
	}*/

	for (int i = 0; i < 20; i++) {
		TextColor(i);
		cout << "Hello" << endl;
	}
	return 0;
}