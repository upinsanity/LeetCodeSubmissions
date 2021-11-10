/*
Leetcode #40
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]


*/
   
void recurseSum(vector<int> A, int idx, int start, int sum, vector<int>& combiStr, vector<vector<int>>& result)
{
	if (sum < 0)
		return;

	if (sum == 0)
	{
		result.push_back(combiStr);
		return;
	}

	for (int i = idx; i < A.size(); i++)
	{
		if ( A[i] <= sum )
		{
			if (i > idx && A[i] == A[i - 1])
				continue;
			combiStr.push_back(A[i]);
			recurseSum(A, i+1, start, sum - A[i], combiStr, result);
			combiStr.pop_back();
		}
		start++;
	}
}

vector<vector<int>> combinationSum2(vector<int>& A, int target) 
{
	vector<int> combiStr;
	vector<vector<int>> result;
	sort(A.begin(), A.end());
	recurseSum(A, 0, 0, target, combiStr, result);
	return result;
}
