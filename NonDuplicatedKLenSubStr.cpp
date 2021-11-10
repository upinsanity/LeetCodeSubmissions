
#include<string>
#include<map>
using namespace std;

/*
Leetcode #1100
Given a string s and an integer k, return the number of substrings in s of length k with no repeated characters.

Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation: There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.

Solution -
Check for unique characters using a map of characters and their occurence indexes.
When a character is found existing in map, reset its index and push out all characters 
before this index
Every time the size of unique characters in the map equals k, increase output count
*/

int numKLenSubstrNoRepeats(string S, int K) {
        
    if (S.empty())
		  return 0;
    
    if (K > nLen)
      return 0;
      
  int nLen = S.length();	
	int currLen = 0;
	int subsCnt = 0;
  
  std::map<char, int> cmap;
	for (int i = 0; i<nLen; i++)
	{
		char currch = S[i];
		auto it = cmap.find(currch);
		
		if (it == cmap.end())
		{
			cmap[currch] = i;
			currLen++;			

			if (currLen > K)
			{
				cmap.erase(S[i - K]);
				currLen--;
			}
			if (currLen == K)
				subsCnt++;			
		}
		else
		{
			int foundAt = it->second;
			for(std::map<char, int>::iterator iter =cmap.begin(); iter != cmap.end();)
			{ 
				if (iter->second < foundAt)
					iter = cmap.erase(iter);
				else
					iter++;
			}
			cmap[currch] = i;
			currLen = cmap.size();
			if (currLen == K)
				subsCnt++;
		}
	}
	return subsCnt;        
}
