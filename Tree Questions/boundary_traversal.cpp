class Solution {
private:
 bool isleaf(Node * root){
     if(root->left==NULL && root->right==NULL){
         return true;
     }
     else{
        return false;
     }
 }
 void traverseLeft(Node * root , vector<int> & ans){
    //  ans.push_back(root->data);
     root=root->left;
     while(root){
         if(!isleaf(root)){
             ans.push_back(root->data);
         }
         if(root->left){
             root=root->left;
         }
         else{
             root=root->right;
         }
     }
 }
 void traverseRight(Node * root , vector<int>& ans){
     root= root->right;
     stack<int>s;
     while(root){
         if(!isleaf(root)){
             s.push(root->data);
         }
         if(root->right){
             root=root->right;
         }
         else{
             root=root->left;
         }
     }
     while(!s.empty()){
         ans.push_back(s.top());
         s.pop();
     }
 }
 void traverseleaf(Node * root , vector<int> & ans){
     if(root==NULL){
        return;
     }
     if(isleaf(root)){
         ans.push_back(root->data);
     }
     traverseleaf(root->left,ans);
     traverseleaf(root->right,ans);

 }
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        if(!isleaf(root)){
        traverseLeft(root,ans);
        traverseleaf(root,ans);
        traverseRight(root,ans);            
        }
        return ans;
    }
};
