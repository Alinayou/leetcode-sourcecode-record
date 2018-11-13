unsigned long long climbStairs(int n) 
{
    vector<unsigned long long> dp(n+1, 0);
    dp[1] = 1;// climbing one stair
    dp[2] = 2;// climbing two stairs
    for(int i = 3; i <= n; i++)
    {
        dp[i] += dp[i-1] + dp[i-2];
    }
    return dp[n];
}
