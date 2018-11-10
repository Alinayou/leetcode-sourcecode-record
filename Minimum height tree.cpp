vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
	unordered_map<int, unordered_set<int> > m;
	vector<int> res;
	unordered_map<int, int> height;
	for (int i = 0; i < edges.size(); i++)
	{
		m[edges[i].first].insert(edges[i].second);
		m[edges[i].second].insert(edges[i].first);
	}
	int depth = 0;
	while (height.size() < n)
	{ 
		++depth;
		vector<int> leaves;
		for (int i = 0; i < n; i++)
		{
                        // height.count(i) 代表前一個while迴圈就已經記錄過深度了
			if (height.count(i) || m[i].size() > 1)
				continue;
                        // 找到小孩囉
			leaves.push_back(i);
		}
		for (int i = 0; i < leaves.size(); i++)
		{
			height[leaves[i]] = depth;
                        // 可能在前一個迴圈就被砍掉了
			if (m[leaves[i]].size() == 0) 
				continue;
			// 砍小孩囉
			int pairnode = *m[leaves[i]].begin();
			m[pairnode].erase(leaves[i]);
		}
		leaves.clear();
	}
	for (int i = 0; i < height.size(); i++)
	{
		if (height[i] == depth)
			res.push_back(i);
	}
	return res;
}
