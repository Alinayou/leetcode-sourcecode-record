vector<string> wordBreak(string s, unordered_set<string> &dict, unordered_set<string> &unpassed, unordered_map<string, vector<string> > &m)
{
	if (m.count(s) > 0)// 回傳舊組合拉
		return m[s];
	else if (s == "") // 找到新組合拉
		return{ "" };
	else if (unpassed.count(s) > 0)
		return{};

	vector<string> res;
	for (int i = 0; i < s.length(); i++)
	{
		string tmp = s.substr(0, i+1);
		if (dict.count(tmp) > 0)
		{
			vector<string> tmpres = wordBreak(s.substr(i + 1), dict, unpassed, m);
			if (!tmpres.empty()) // 把找到的結果組合起來
			{
				string ss = "";
				for (int i = 0; i < tmpres.size(); i++)
				{
					ss = tmp + (tmpres[i] == "" ? tmpres[i] : " " + tmpres[i]);
					res.push_back(ss);
				}
			}
			else
				unpassed.insert(s);
		}
	}
	return m[s] = res;
}
vector<string> wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	unordered_set<string> unpassed; // 避免重複找到不可能的組合，所以把不可能的組合記錄下來
	unordered_map<string, vector<string> > m; // m 用來暫存之前search 到的結果，才不用每次都重複找
	return wordBreak(s, dict, unpassed, m);
}
