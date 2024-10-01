#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left,*right;
    Node(int data){
        this->data = data;
        left= NULL;
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
void print(Node* root){
    queue<Node*> q;
    if(root==NULL) return;
    q.push(root);
    while(q.size()!=0){
        int n = q.size();
        while(n--){
            Node* front =q.front();
            cout<<front->data<<" ";
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
            q.pop();
        }
        cout<<endl;
    }
}
//Assignment
//1.
void insetDuplicateNode(Node* root){
    if(root==NULL) return;
    Node* temp =  root->left;
    Node* attach = new Node(root->data);
    root->left  =  attach;
    attach->left  =  temp;
    insetDuplicateNode(temp);
    insetDuplicateNode(root->right);
}
//2.

int main(){
    Node* root = takeInput_LW();
    //insetDuplicateNode(root);
    print(root);
 return 0;
}