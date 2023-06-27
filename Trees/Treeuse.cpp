#include <iostream>
#include <bits/stdc++.h>
#include "Tree_Node_Class.h"
#include <queue>
//printing tree LevelWise
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
//using recursion to print tree
void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<':';
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

//taking input level wise
TreeNode<int>* takeInput_LW(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0){
       TreeNode<int>* front = pendingNodes.front();
       pendingNodes.pop();
       cout<<"Enter number of children of "<<front->data<<":";
       int n;
       cin>>n;
       for(int i=0;i<n;i++ ){
        cout<<"Enter "<<i<<"th child of"<<front->data<<":";
        int childData;
        cin>>childData;
        TreeNode<int>* child = new TreeNode<int>(childData);
        front->children.push_back(child);
        pendingNodes.push(child);
       }
    }
    return root;
}
//taking tree from user
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of "<<rootData<<':';
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child= takeInput();
        root->children.push_back(child);
    }
    return root;
}
//counting number of nodes
int numNodes(TreeNode<int> * root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}
int sumNodes(TreeNode<int> * root){
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=sumNodes(root->children[i]);
    }
    return ans;
}
int maxNodes(TreeNode<int> * root){
    int max=root->data;
    for(int i=0;i<root->children.size();i++){
        if(max<maxNodes(root->children[i])){
            max=maxNodes(root->children[i]);
        }
    }
    return max;
}
int height_Tree(TreeNode<int> * root){
    int max=0;
    for(int i=0;i<root->children.size();i++){
        if(max<=height_Tree(root->children[i])){
            max=height_Tree(root->children[i]);
        }
    }
    return max+1;
}
//counting leaf of tree
int leaf(TreeNode<int>* root){
    int ans=0;
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0;i<root->children.size();i++){
       ans =ans+leaf(root->children[i]);
    }
    return ans;
}
//printing node at level k
void print_at(TreeNode<int>* root,int k){
    if(k==0){
        cout<<root->data<<' ';
        return;
    }
    for(int i=0;i<root->children.size();i++){
        print_at(root->children[i],k-1);
    }
}
//printing in post order traversal
void post_order(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        post_order(root->children[i]);
    }
    cout<<root->data<<" ,";
}
//pre order traversal
void pre_order(TreeNode<int>* root){
    cout<<root->data<<" ,";
    for(int i=0;i<root->children.size();i++){
        pre_order(root->children[i]);
    }
}
//deleting the tree
void delete_tree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        delete_tree(root->children[i]);
    }
    delete root;
}
bool find_x(TreeNode<int>* root,int x){
    if(root->data==x){
        return true;
    }
    if(root==NULL){
        return false;
    }
    bool ans =false;
    for(int i =0;i<root->children.size();i++){
        if(find_x(root->children[i],x)){
            ans =true;
            break;
        }else{
            continue;
        }
    }
    return ans;
}
int count_greater_than_x(TreeNode<int>* root,int x){
    if(root==NULL){
        return 0;
    }
    int count = 0;
    if(root->data>x){
        count++;
    }
    for(int i =0;i<root->children.size();i++){
        count=count+count_greater_than_x(root->children[i],x);
    }
    return count;
}
pair<TreeNode<int>*,int> maxChildSum(TreeNode<int>* root){
    if(root==NULL){
        pair<TreeNode<int>*,int> b;
        b.first=NULL;
        b.second=INT_MIN;
        return b;
    }
    pair<TreeNode<int>*,int> temp;
    temp.first=NULL;
    temp.second = INT_MIN;
    for(int i=0;i<root->children.size();i++){
     if(maxChildSum
     (root->children[i]).second>temp.second){
        temp = maxChildSum
        (root->children[i]);
     }
    }
    int sum =root->data;
    for(int i =0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    if(sum>temp.second){
        temp.second = sum;
        temp.first = root;
    }
    return temp;
}
bool identical(TreeNode<int>* root1,TreeNode<int>* root2){
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
        ans = ans&&identical(root1->children[i],root2->children[i])
        if(ans =false) break;
    }
    return ans;
}
// void nextLarger(TreeNode<int>* root,int data,vector<int>& v){
//     if(root==NULL){
//         return;
//     }
//     for(int i =0;i<root->children.size();i++){
//         nextLarger(root->children[i],data,v);
//     }
//     if(root->data>=data){
//         v.push_back(root->data);
//     }
//     return;
// }
// int nextLarger_final(int data,TreeNode<int>* root){
//     vector<int> v;
//     nextLarger(root,data,v);
//     sort(v.begin(),v.end());
//     return v.size() ? v[0] : 0;
// }
// int nextLarger(TreeNode<int>* root,int data){
//     if(root==NULL){
//         return -1;
//     }
//     int ans = INT_MAX;
//     for(int i =0;i<root->children.size();i++){
//         int smallAns = nextLarger(root->children[i],data);
//         if(smallAns<ans){
//             ans =smallAns;
//         }
//     }
//     if(root->data>=data){
//         if(ans>root->data){
//             ans=root->data;
//         }
//     }
//     return ans;
// }
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *nextLargest = NULL;
    if (root->data > x)
    {
        nextLargest = root;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = getNextLargerElement(root->children[i], x);

        if (nextLargest == NULL)
        {
            nextLargest = smallAns;
        }
        else if (smallAns != NULL && smallAns->data < nextLargest->data) //No need to check if smallAns -> data > x.. its already checked
        { 
            nextLargest = smallAns;
        }
    }
    return nextLargest;
}
void replaceWithDepth(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int max= height_Tree(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        front->data=max-height_Tree(front);
        int n =front->children.size();
        for(int i =0;i<n;i++){
            pendingNodes.push(front->children[i]);
        }
    }
}
int main(){
    TreeNode<int>* root = takeInput_LW();
    cout<<endl<<endl;
    printTree_LW(root);
    cout<<endl<<"replaced tree"<<endl;
    replaceWithDepth(root);
    printTree_LW(root);
    cout<<endl;
    //delete_tree(root);
    //delete root;
    //deleting tree is necessary
}
//input for my tree
// 1 3 2 3 4 2 5 6 1 7  2 8 9 0 0 1 10 0 0 0
// 1 3 40 3 4 2 5 6 1 7  2 8 9 0 0 1 10 0 0 0
