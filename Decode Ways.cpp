int numDecodings(string s)
{
	int m = s.length();
	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= m; i++)
	{
    // 第 i-1 項是否有在 'A' ~ 'I'的範圍內，有的話把 i-1 的結果加起來
		if (s[i - 1] == '0')
			dp[i] = 0;
		else
			dp[i] += dp[i-1];
    // 第 i-2 項是否有在 'A' ~ 'Z'的範圍內，有的話把 i-2 的結果加起來 
		if (i > 1 && s[i - 2] != '0' && ((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] < '7')))
		{
			dp[i] += dp[i - 2];
		}
	}
	return dp[m];
}
