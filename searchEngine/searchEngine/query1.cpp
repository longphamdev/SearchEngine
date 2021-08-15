#include "query1.h"
/*
vector<int> findAnd(string ss1, string ss2, const fileData& file)
{
	vector<int> rs;
	vector<int> resultSs1(normalSearch(file, ss1));  
	vector<int> resultSs2(normalSearch(file, ss2));
	if (!resultSs1.empty() && !resultSs2.empty())
	{
		rs.insert(rs.end(),resultSs1.begin(), resultSs1.end());
		rs.insert(rs.end(), resultSs2.begin(), resultSs2.end());
	}
	return rs;
}

vector<int> findOr(string ss1, string ss2, const fileData& file)
{
	vector<int> rs;
	vector<int> resultSs1(normalSearch(file, ss1));
	vector<int> resultSs2(normalSearch(file, ss2));
	if (!resultSs1.empty() && !resultSs2.empty())
	{
		rs.insert(rs.end(), resultSs1.begin(), resultSs1.end());
		rs.insert(rs.end(), resultSs2.begin(), resultSs2.end());
	}
	return rs;
}

bool findNOT(string ss, const fileData& file)
{
	vector<int> rs(normalSearch(file,ss));
	if (rs.empty() == 1)
	{
		return 0;
	}
	return 1;
}


vector<int> findPrice(int amountSearch, const fileData& file)
{
	vector<int> place;
	for (int i = 0; i < file.priceData.size(); i++)
	{
		if (amountSearch == file.priceData[i].amount)
		{
			place.push_back(file.priceData[i].place);
		}
	}
	return place;
}

vector<int> findRangePrice(int amountSearch1, int amountSearch2, const fileData& file)
{
	vector<int> place;
	int tempAmount;
	for (int i = 0; i < file.priceData.size(); i++)
	{
		tempAmount = file.priceData[i].amount;
		if (amountSearch1 <= tempAmount && amountSearch2 >= tempAmount)
		{
			place.push_back(file.priceData[i].place);
		}
	}
	return place;
}
*/