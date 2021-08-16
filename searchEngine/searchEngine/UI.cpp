#include "UI.h"





void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showImage(string link) {
	ifstream fin;
	ofstream fout;

	fin.open(link);
	if (!fin.is_open()) cout << "Cannot open file" << endl;
	string inp;
	int i = 3;
	while (!fin.eof())
	{

		getline(fin, inp);
		GotoXY(10, i);
		cout << inp << endl;
		i++;
		//Sleep(150);
	}
	fin.close();
	GotoXY(40, 40);


}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DrawMain() {
	TextColor(12);
	for (int i = 0; i < 101; i++) {
		GotoXY(i, 0);
		cout << (char)223;
	}

	for (int i = 0; i < 28; i++) {
		GotoXY(0, i);
		cout << (char)219;
	}

	for (int i = 0; i < 27; i++) {
		GotoXY(101, i);
		cout << (char)219;
	}

	for (int i = 0; i < 102; i++) {
		GotoXY(i, 27);
		cout << (char)223;
	}

	showImage("text.txt");

	GotoXY(35, 8);
	cout << "Nguyen Ngoc Trung  - 19125xxx" << endl;
	GotoXY(35, 9);
	cout << "Pham Thien Long - 19125xxx" << endl;
	GotoXY(35, 10);
	cout << "Vu Ngoc Tuan - 19125xxx" << endl;
	GotoXY(35, 11);
	cout << "Nguyen Hoang Son - 19125118" << endl;
	GotoXY(35, 12);
	cout << "Tran Minh Nhut - 19125111" << endl;

	//GotoXY(30, 13);
	//cout << "";
	for (int i = 20; i < 80; i++) {
		GotoXY(i, 14);
		cout << (char)223;
	}
	GotoXY(20, 14);
	cout << (char)219;
	GotoXY(20, 15);
	cout << (char)219;
	GotoXY(79, 14);
	cout << (char)219;
	GotoXY(79, 15);
	cout << (char)219;
	for (int i = 20; i < 80; i++) {
		GotoXY(i, 16);
		cout << (char)223;
	}
	
}

void displaySearchResult(ifstream& fin, vector<searchData> result) {
	for (int i = 0; i < result.size(); i++) {
		TextColor(9);
		cout << "[ " << i + 1 << " ]";
		cout << result[i].fileName << endl;
		TextColor(14);
		string temp;
		fin.open("C:/Users/tin85/OneDrive/Máy tính/GitHub/SearchEngine/searchEngine/searchEngine/Search Engine-Data/Search Engine-Data/" + result[i].fileName);
		if (!fin.is_open()) {
			cout << "Can not open file";
		}
		else {
			for (int j = 0; j <= 10; j++) {
				fin >> temp;
				cout << temp << " ";
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

	TextColor(7);
	string temp;
	fin.open("C:/Users/tin85/OneDrive/Máy tính/GitHub/SearchEngine/searchEngine/searchEngine/Search Engine-Data/Search Engine-Data/" + result[choose - 1].fileName);
	if (!fin.is_open()) {
		cout << "Can not open file";
	}
	else {
		vector<int> tempPlace = result[choose - 1].place;
		int place = 0;
		while (!fin.eof()) {
			place++;
			fin >> temp;
			for (int i = 0; i < tempPlace.size(); i++) {
				if (place == tempPlace[i]) {
					TextColor(30);
					cout << temp << "";
					TextColor(7);
					tempPlace.erase(tempPlace.begin()+i);
					temp = "";
				}
			}
			cout << temp << " ";
		}
	}
	fin.close();
}

void displayOption(char& status) {
	TextColor(4);
	cout << "Back to search menu [ y ]" << endl;
	cout << "Back to result menu [ n ]" << endl;
	cout << "Exit [ x ]" << endl;
	cout << "[ y / n / x ]";
	cin >> status;
}