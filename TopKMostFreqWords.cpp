
/*
Leetcode #692
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
*/
typedef pair<string, int> nType;
struct compare
{
public:
	bool operator()(nType a, nType b)
	{
		if (a.second == b.second)		
			return (a.first.compare(b.first) < 0);
		
		return a.second > b.second;
	}
};

//["i", "love", "leetcode", "i", "love", "coding"], k = 2
vector<string> topKFrequent(vector<string> words, int k) {

	unordered_map<string, int> m;
	for (string word : words)
		m[word]++;

	priority_queue< nType, vector<nType>, compare> pq;
	
	for (auto item : m)
	{
		if (pq.size() < k)
			pq.push(item);
		else
		{
			if ( (pq.top().second < item.second)||
			   ( pq.top().second == item.second &&
				 pq.top().first.compare(item.first)>0))
			{
				pq.pop();
				pq.push(item);
			}
		}
	}

	vector<string> out(k);
	int currIdx = k - 1;
	while (!pq.empty())
	{
		nType item = pq.top();
		pq.pop();
		out[currIdx--] = item.first;
	}
	return out;
}
