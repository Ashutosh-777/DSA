#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* takeInput_LW(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    Node* root=new Node(rootData);
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node* front=pendingNodes.front();
        pendingNodes.pop();
       int leftdata;
       int rightdata;
      // cout<<"Enter left child data of "<<front->data<<endl;
       cin>>leftdata;
       if(leftdata!=-1){
        Node* left=new Node(leftdata);
        front->left=left;
        pendingNodes.push(left);
       }
      // cout<<"Enter right child data of "<<front->data<<endl;
       cin>>rightdata;
       if(rightdata!=-1){
        Node* right=new Node(rightdata);
        front->right=right;
        pendingNodes.push(right);
       }
    }
    return root;

}
void print_LW(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            cout<<" L"<<front->left->data;
        }
        if(front->right!=NULL){
            cout<<" R"<<front->right->data;
        }
        cout<<endl;
        if(front->left!=NULL){
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            pendingNodes.push(front->right);
        }
    }
}
void solve(Node* root,int sum,vector<int> ans,vector<vector<int>> &v){
    if(root==NULL||sum==0){
        return ;
    }
    int a = root->data;
    ans.push_back(a);
    if(!root->left&&!root->right&&a==sum){
        v.push_back(ans);
    }
    solve(root->left,sum-a,ans,v);
    solve(root->right,sum-a,ans,v);
}
vector<vector<int> > pathSum(Node* root, int sum) {
    vector<int> ans;
    vector<vector<int>> v;
    solve(root,sum,ans,v);
    return v;
}

int main(){
    Node* root = takeInput_LW();
    print_LW(root);
    int sum;
    cin>>sum;
    vector<vector<int>> ans = pathSum(root,sum);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
 return 0;
}