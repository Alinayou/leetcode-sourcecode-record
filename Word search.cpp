// 檢查 x, y 的範圍是否合法
bool isinrange(int x, int y, int m, int n)
{
	if (x < m && x >= 0 && y < n && y >= 0)
		return true;
	else
		return false;
}
// DFS Search 是否有符合的字串，用 vesited 紀錄是否走過同個(x, y)
bool isexist(vector<vector<char>>& board, string word, int m, int n, vector<vector<bool>> &vesited, string res, int x, int y)
{
	if (vesited[x][y] || word.find(res + board[x][y]) == string::npos)
		return false;
	vesited[x][y] = true;
	res += board[x][y];
	if (res == word)
		return true;
	if ((isinrange(x - 1, y, m, n) && isexist(board, word, m, n, vesited, res, x - 1, y)) ||
		(isinrange(x + 1, y, m, n) && isexist(board, word, m, n, vesited, res, x + 1, y)) ||
		(isinrange(x, y - 1, m, n) && isexist(board, word, m, n, vesited, res, x, y - 1)) ||
		(isinrange(x, y + 1, m, n) && isexist(board, word, m, n, vesited, res, x, y + 1)))
		return true;
	else
	{
/* vesited[x][y] 改成 false 的原因是因為，雖然在某條路主路徑下沒有搜尋到，
 但是可能會成為主路徑的分支。 ex : 考慮 case
 [["A","B","C","E"],
 ["S","F","E","S"],
 ["A","D","E","E"]]
 word = "ABCESEEEFS"*/

		vesited[x][y] = false;
		return false;
	}
}
bool exist(vector<vector<char>>& board, string word)
{
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == word[0])
			{
				vector<vector<bool>> vesited(m, vector<bool>(n, false));
				if (isexist(board, word, m, n, vesited, "", i, j))
					return true;
			}
		}
	}
	return false;
}
