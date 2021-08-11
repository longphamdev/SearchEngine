#include "query1.h"


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