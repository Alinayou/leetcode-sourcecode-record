/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  TreeNode* addOneRow(TreeNode* root, int v, int d, deque<int> &level, int depth) 
  {
      if(!root)
          return NULL;
      if(level.size() <= depth)  
          level.push_back(1);

      if(depth == d-1)
      {
          // "issubtree" is to confirm is there subtrees at current node 
          bool issubtree = false;
          TreeNode* p = NULL;
          if(root->left)
          {
              p = root->left;
              root->left = new TreeNode(v);
              root->left->left = p;
              issubtree = true;
          }
          else 
              root->left = new TreeNode(v);  

          if(root->right)
          {
              p = root->right;
              root->right = new TreeNode(v);
              root->right->right = p;
              issubtree = true;
          }
          else
              root->right = new TreeNode(v);

          if(!issubtree)
              root = new TreeNode(v);
          return root;
      }
      // d == 1
      else if(depth == d)
      {
          TreeNode* p = root;
          root = new TreeNode(v);
          root->left = p;
          return root;
      }

      addOneRow(root->left, v, d, level, depth + 1);
      addOneRow(root->right, v, d, level, depth + 1);
      return root;
  }
  TreeNode* addOneRow(TreeNode* root, int v, int d) 
  {
      // "deque<int> level" if for calculate current depth 
      deque<int> level;
      return addOneRow(root, v, d, level, 1);  
  }
