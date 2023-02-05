class info{
  public:
  int maxi;
  int mini;
  bool isBST;
  int size;
};
class Solution{
    private:
    info solve(Node * root,int & ans){
        if(root==nullptr){
            return {INT_MIN,INT_MAX,true,0};
        }
        info left = solve(root->left,ans);
        info right= solve(root->right,ans);
        info currNode;
        currNode.size=left.size + right.size + 1;
        currNode.maxi=max(root->data,right.maxi);
        currNode.mini=min(root->data,left.mini);
        currNode.isBST=left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini;
        if(currNode.isBST){
            ans=max(currNode.size,ans);
        }
        return currNode;
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {   
        int ans=0;
    	solve(root,ans);
    	return ans;
    }
};
