// time complexity : O(n^2)
bool iswordBreak(string s, unordered_set<string> &dict, unordered_set<string> &unpassed)
{
	if (s == "")
		return true;
	else if (unpassed.count(s) > 0)
		return false;

	for (int i = 0; i < s.size(); i++)
	{
		string tmp = s.substr(0, i+1);
		if (dict.count(tmp) > 0 && iswordBreak(s.substr(i + 1), dict, unpassed))
			return true;
		else
			unpassed.insert(tmp);
	}
	return false;
}
bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
  // unpassed is for recording the pass impossibile access, avoiding to calculate repetitively
	unordered_set<string> unpassed; 
	return iswordBreak(s, dict, unpassed);
}
