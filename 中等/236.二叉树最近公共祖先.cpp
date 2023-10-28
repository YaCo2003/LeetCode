
// class Solution {
// public:
//     bool isTree(TreeNode* root, TreeNode* x)
//     {
//         if(root==NULL)
//         return false;

//         if(root==x)
//         return true;

//         return isTree(root->left,x)||isTree(root->right,x);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

//         if(root==p||root==q)
//         {
//             return root;
//         }

//         bool pLeft = isTree(root->left,p);
//         bool pRight=!pLeft;

//         bool qLeft = isTree(root->left,q);
//         bool qRight=!qLeft;

//         //在左右两边
//         if((pLeft&&qRight)||(qLeft&&pRight))
//         {
//             return root;
//         }
//         //都在左边
//         if(pLeft&&qLeft)
//         {
//             return lowestCommonAncestor(root->left,p,q);
//         }
//         //都在右边
//         if(qRight&&pRight)
//         {
//             return lowestCommonAncestor(root->right,p,q);
//         }

//         return NULL;
      
//     }
// };


//上述方法性能较低  O(n^2)

// class Solution {
// public:
//     bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>&path)
//     {
//         if(root==NULL)
//         return false;

//         path.push(x);
//         if(root==x)
//         return true;

//         if(FindPath(root->left, x, path))
//         return true;

//         if(FindPath(root->right,x, path))
//         return true;

//         path.pop();
//         return false;

//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         stack<TreeNode*>ppath;
//         stack<TreeNode*>qpath;
//         //找两点路径
//         FindPath(root,p,ppath);
//         FindPath(root,q,qpath);

//         //先同步个数
//         while(ppath.size()!=qpath.size())
//         {
//             if(ppath.size()>qpath.sizes())
//             {
//                 ppath.pop();
//             }
//             else
//             {
//                 qpath.pop();
//             }
//         }

//         //找交点
//         while(ppath.top()!=qpath.top())
//         {
//             ppath.pop();
//             qpath.pop();
//         }

//         return ppath.top();
      
//     }
// };
//性能高，O(n)