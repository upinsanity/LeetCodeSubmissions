#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
Leetcode #833 - Find And Replace in String
Input: S = "abcd", indexes = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
Output: "eeebffff"
*/

/*
Solution :
create mapping of indexes to source and target indexes and sort the index list.
traverse index array backwards and replace source strings to target
*/

string findReplaceString(string S, vector<int> indexes, vector<string> sources, vector<string> targets) {

	vector<pair<int, int>> m;
	int i = 0;
	for (int idx : indexes)
	{
		m.push_back(make_pair(idx, i));
		i++;
	}
	sort(m.begin(), m.end());

	vector<pair<int, int>>::reverse_iterator it = m.rbegin();
	while (it != m.rend())
	{
		int idx = it->second;
		if (S.compare(it->first, sources[idx].length(), sources[idx]) == 0)
			S.replace(it->first, sources[idx].length(), targets[idx]);
		it++;
	}
	return S;
}
