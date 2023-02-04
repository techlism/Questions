class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void inorder(Node * root,vector<Node* >&sorted){
        if(root==nullptr){
            return;
        }
        inorder(root->left,sorted);
        sorted.push_back(root);
        inorder(root->right,sorted);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        vector<Node *>sorted;
        inorder(root,sorted);
        for(int i=0;i<sorted.size()-1;i++){
            if(sorted[i]->data==x->data){
                return sorted[i+1];
            }
        }
        return nullptr;
    }
};
