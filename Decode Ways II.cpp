int numDecodings(string s)
{
	int len = s.length();
  // 怕超過範圍，所以除以題目給定的數字
	long int mod = 1e9 + 7;
	vector<long long> dp(len + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= len; i++)
	{
    // 加上第 i-1 step 的結果
		dp[i] += s[i - 1] == '0' ? 0 : (s[i - 1] == '*' ? dp[i - 1] * 9: dp[i - 1] );
    // 加上第 i-2 step 的結果
		if (i > 1)
		{
			if (s[i - 1] == '*')
			{
				if (s[i - 2] == '*')
					dp[i] += dp[i - 2] * 15; // 6 + 9 共 15 種情形
				else if (s[i - 2] == '1')// 有可能是 '11' ~ '19'的情形
					dp[i] += dp[i - 2] * 9;
				else if(s[i - 2] == '2') 有可能是 '21' ~ '26'的情形
					dp[i] += dp[i - 2] * 6;
			}
			else
			{
				if (s[i - 2] == '*')
				{
					if(s[i - 1] > '6') // 若是 s[i - 1] > '6'，只有可能是 '11' ~ '19'的情形
						dp[i] += dp[i - 2];
					else // 若是 s[i - 1] <= '6'，有可能是 '11' ~ '16' 或是 '21' ~ '26' 的情形
						dp[i] += dp[i - 2] * 2;
				}// s[i-1] 和 s[i-2] 都是數字的情形
				else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
					dp[i] += dp[i - 2] ;
			}
		}
		dp[i] = dp[i] % mod;
	}
	return dp[len];
}
