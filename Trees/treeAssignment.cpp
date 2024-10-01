#include <iostream>
#include "Tree_Node_Class.h"
#include <queue>
//take input level wise
TreeNode<int>* takeInput_LW(){
    queue<TreeNode<int>*> pendingNodes;
    int rootData;
    cout<<"Enter root Data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        //cout<<"Enter Number of Children of "<<front->data;
        cin>>n;
        for(int i=0;i<n;i++){
            int data;
          //  cout<<"Enter data of "<<i<<"th child"<<"of "<<front->data;
            cin>>data;
            TreeNode<int>* child = new TreeNode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
//printing tree level wise
void printTree_LW(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        int n=front->children.size();
        for(int i=0;i<n;i++){
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<'\n';
    }
}
void delete_tree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        delete_tree(root->children[i]);
    }
    delete root;
}
int maxChildSum(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    int maxi = sum;
    for(int i=0;i<root->children.size();i++){
        maxi = max(maxi,maxChildSum(root->children[i]));
    }
    return maxi;
}
pair<TreeNode<int>*,int> maxChild_Sum(TreeNode<int>* root){
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    pair<TreeNode<int>*,int> finalAns;
    finalAns.first =root;
    finalAns.second = sum;
    int maxi = sum;
    for(int i=0;i<root->children.size();i++){
        pair<TreeNode<int>* ,int> smallAns = maxChild_Sum(root->children[i]);
        if(smallAns.second>maxi){
            maxi = smallAns.second;
            finalAns.first = smallAns.first;
        }
    }
    finalAns.second = maxi;
    return finalAns;
}
bool isIdentical(TreeNode<int>* root1,TreeNode<int>* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if((root1==NULL||root2==NULL)){
        return false;
    }
    bool ans =root1->data==root2->data;
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        ans = ans&&isIdentical(root1->children[i],root2->children[i]);
        if(ans ==false) break;
    }
    return ans;
}
int maxNode(TreeNode<int>* root){
    if(root==NULL) return -1;
    int maxi = root->data;
    for(int i=0;i<root->children.size();i++){
        maxi = max(maxi,maxNode(root->children[i]));
    }
    return maxi;
}
int helper(TreeNode<int>* root,int x ,int y){
    if(root->data>x){
        if(root->data<y) y=root->data;
    }
    for(int i=0;i<root->children.size();i++){
        int a = helper(root->children[i],x,y);
        if(x<a&&y>a) y=a;      
    }
    return y;
}
int nextLarger(TreeNode<int>* root,int x){
    if(root==NULL){
        cout<<"INVALID ROOT"<<endl;
        return -1;
    }
    int y = maxNode(root);
    if(x>=y) return -1;
    return helper(root,x,y);
}
int nextLarger_2(TreeNode<int>* root,int x){
    if(root==NULL){
        return -1;
    }
    int ans ;
    if(root->data>x){
        ans = root->data;
    }
    else ans =INT_MAX;
    for(int i=0;i<root->children.size();i++){
        int temp = nextLarger_2(root->children[i],x);
        ans = min(temp,ans);
    }
    return ans;
}
void replaceWithDepth(TreeNode<int>* root,int x){
    if(root==NULL){
        return ;
    }
    root->data = x;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],x+1);
    }
}
int main(){
    TreeNode<int>* root = takeInput_LW();
    //printTree_LW(root);
    int x;
    cin>>x;
    cout<<nextLarger_2(root,x)<<endl;
    return 0;
}
//input for my tree
// 1 3 2 3 4 2 5 6 1 7  2 8 9 0 0 1 10 0 0 0
// 1 3 40 3 4 2 5 6 1 7  2 8 9 0 0 1 10 0 0 0
//input for tree takeInput()
//1 3 2 2 5 0 6 0 3 0 4 1 7 1 8  0 0 0 0 0 0 0