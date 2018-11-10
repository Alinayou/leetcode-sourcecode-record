static pretree *root; // root of trie
typedef struct Trie
{
    unordered_map<char, Trie*> child;
    bool isword;
    string wholeword; // whole word
    Trie():isword(false), wholeword(""){};
}pretree;
// insert a word to the trie
void InsertTree(string word)
{
    pretree *p = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (p->child.count(word[i]) == 0)
            p->child[word[i]] = new pretree();
        p = p->child[word[i]];
    }
    p->isword = true;
    p->wholeword = word;
}
// search if board has path to the word node 
void searchword(vector<vector<char>>& board, int m, int n, int i, int j, unordered_set<string> &res, vector<vector<bool>> &vesited, pretree *p)
{
    if (!p || i < 0 || i >= m || j < 0 || j >= n || vesited[i][j])
        return;

    if (p->child.count(board[i][j]) > 0)
    {
        vesited[i][j] = true;
        p = p->child[board[i][j]];
        if (p->isword)
            res.insert(p->wholeword);

        searchword(board, m, n, i - 1, j, res, vesited, p);
        searchword(board, m, n, i + 1, j, res, vesited, p);
        searchword(board, m, n, i, j - 1, res, vesited, p);
        searchword(board, m, n, i, j + 1, res, vesited, p);
        /* reason for "vesited[i][j] = false" is (i, j) may not be the path1 for word1,
           but it's path2 for word2. If "vesited[i][j] is still true", the path2 won't exist */

        vesited[i][j] = false;
    }
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
    int m = board.size();
    int n = board[0].size();
    unordered_set<string> res;
    root = new pretree();
    for (int i = 0; i < words.size(); i++)
        InsertTree(words[i]);
    for (int i = 0; i < m && res.size() < words.size(); i++)
    {
        for (int j = 0; j < n && res.size() < words.size(); j++)
        {
            // vesited is for avoiding to access the same walked path
            vector<vector<bool>> vesited(m, vector<bool>(n, false));
            searchword(board, m, n, i, j, res, vesited, root);
        }
    }
    return vector<string>(res.begin(), res.end());
}  
pretree *root; 
