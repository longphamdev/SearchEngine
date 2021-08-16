
#pragma once
#ifndef _UI_H_
#define _UI_H_
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include "search.h"
#include <vector>

using namespace std;

void resizeConsole(int width, int height);

void TextColor(int x);

void GotoXY(int x, int y);

void showImage(string link);

void FixConsoleWindow();

void DrawMain();

void displaySearchResult(ifstream& fin, vector<searchData> result);

void displayOption(char& status);
#endif 