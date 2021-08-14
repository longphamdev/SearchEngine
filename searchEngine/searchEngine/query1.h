#pragma once
#ifndef _QUERY1_H_
#define _QUERY1_H_
#include"search.h"



// ss stand for search string
vector<int> findAnd(string ss1, string ss2,  const fileData& file);
vector<int> findOr(string ss1, string ss2,  const fileData& file);
bool findNOT(string ss, const fileData& file); 
vector<int> findPrice(int amountSearch, const fileData& file);
vector<int> findRangePrice(int amountSearch1, int amountSearch2, const fileData& file);




#endif 

