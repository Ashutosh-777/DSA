#include <iostream>
#include <algorithm>
using namespace std;
#include "binary_tree_class.h"
#include <queue>
class Node {
    public:
    int data;
    Node *next;
    Node (int data){
        this->data=data;
        this->next=NULL;
    }
};
//BST to sorted LL
class Pair{
    public:
    Node* head;
    Node* tail;
};
BinaryTreeNode<int>* takeInput_LW(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
       int leftdata;
       int rightdata;
      // cout<<"Enter left child data of "<<front->data<<endl;
       cin>>leftdata;
       if(leftdata!=-1){
        BinaryTreeNode<int>* left=new BinaryTreeNode<int>(leftdata);
        front->left=left;
        pendingNodes.push(left);
       }
      // cout<<"Enter right child data of "<<front->data<<endl;
       cin>>rightdata;
       if(rightdata!=-1){
        BinaryTreeNode<int>* right=new BinaryTreeNode<int>(rightdata);
        front->right=right;
        pendingNodes.push(right);
       }
    }
    return root;

}
void print_LW(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front=pendingNodes.front();
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
bool find_x(BinaryTreeNode<int>* root,int x){
    if(root==NULL){
        return false;
    }
    int data =root->data;
    if(x==data){
        return true;
    }
    if(x>data){
        return find_x(root->right,x);
    }
        return find_x(root->left,x);
    
}
void elements_in_Range(BinaryTreeNode<int>* root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data<k1){
        //if(root->data==k1) cout<<root->data<<" ";
        elements_in_Range(root->right,k1,k2);
    }else
    if(root->data>k2){
        elements_in_Range(root->left,k1,k2);
        //cout<<root->data<<" ";
    }else{
        elements_in_Range(root->left,k1,k2);
        cout<<root->data<<" ";
        elements_in_Range(root->right,k1,k2);
    }
    return;
}
//wrong approach
bool checkforBST(BinaryTreeNode<int>* root){
    
    if(root==NULL){
        return true;
    }
    bool ans1 = checkforBST(root->left);
    bool ans2 = checkforBST(root->right);
    
    int l =INT_MIN;
    int r= INT_MAX;
    if(root->left!=NULL){
        l=root->left->data;
    }
    if(root->right!=NULL){
        r=root->right->data;
    }
    if(l< root->data&& root->data <= r){
        if(ans1 ==true && ans2==true){
            return true;
        }
        return false;
    }else{
        return false;
    }

}
pair<int,int> min_max(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p ;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    pair<int,int> l = min_max(root->left);
    pair<int,int> r = min_max(root->right);
    pair<int,int> a;
    a.first = min(l.first,min(r.first,root->data));
    a.second =max(l.second,max(root->data,r.second)) ;
    return a;
}
bool isBST1(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    bool ans1 = isBST1(root->left);
    bool ans2 = isBST1(root->right);
    pair<int,int> l = min_max(root->left);
    pair<int,int> r = min_max(root->right);
    if(ans1&&ans2){
        if(l.second<root->data<=r.first){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

}
//better time complexity
pair<pair<int,int> , bool> isBST2(BinaryTreeNode<int>* root){
    if(root==NULL){
        return pair<pair<int,int>,bool>(pair<int,int>(INT_MAX,INT_MIN),true);
    }
    pair<pair<int,int> , bool> l = isBST2(root->left);
    pair<pair<int,int> , bool> r = isBST2(root->right);
    pair<pair<int,int> , bool> ans;
    ans.first.first = min(root->data,min((l.first).first,(r.first).first));
    ans.first.second =max(root->data,max( (l.first).second,(r.first).second));
    bool output = l.second && r.second && (root->data > (l.first).second) && (root->data <= (r.first).first) ;
    ans.second = output;
    return ans;
}
//top down approahc with time complexity O(n)
bool isBST3(BinaryTreeNode<int>* root,int min =INT_MIN,int max =  INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min||root->data>max){
        return false;
    }
    bool l = isBST3(root->left,min,root->data);
    bool r = isBST3(root->right,root->data,max);
    return l&&r;
}
BinaryTreeNode<int>* constructBST(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = s+(e-s)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
    root->left  =constructBST(a,s,mid-1);
    root->right =constructBST(a,mid+1,e);
    return root;
}
//BST to LL
Pair constructLL(BinaryTreeNode<int>* root){
    if(root==NULL){
        Pair p;
        p.head=NULL;
        p.tail=NULL;
        return p;
    }
    Pair leftNode = constructLL(root->left);
    Pair rightNode = constructLL(root->right);
    Node* lhead=leftNode.head;
    Node* ltail =leftNode.tail;
    Node* rhead =rightNode.head;
    Node* rtail =rightNode.tail; 
    Node* rootNode =new Node(root->data);
    rootNode->next=rhead;
    Pair ans;
    if(ltail!=NULL){
        ltail->next=rootNode;
        ans.head=lhead;
    }else{
        ans.head=rootNode;
    }
    if(rtail!=NULL){
        ans.tail=rtail;
    }else{
        ans.tail=rootNode;
    }
    return ans;
}
//printing Linked List
void print_LL(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    return;
}
//path through root in BST
void path(BinaryTreeNode<int>* root,int x,vector<int> &v){
    if(root==NULL){
        return ;
    }
    v.push_back(root->data);
    if(root->data==x){
        return;
    }
    if(root->data>x){
       path(root->left,x,v);
    }else{
       path(root->right,x,v);
    }
    return;
}
vector<int>* path_BT(BinaryTreeNode<int>* root,int x){
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){
        vector<int>* output = new vector<int> ();
        output->push_back(root->data);
        return output;
    }
    vector<int>* l=path_BT(root->left,x);
    if(l!=NULL){
        l->push_back(root->data);
        return l;
    }
    vector<int>* r=path_BT(root->right,x);
    if(r!=NULL){
        r->push_back(root->data);
        return r;
    }else{
        return NULL;
    }
}
int main(){
    BinaryTreeNode<int>* root = takeInput_LW();
    elements_in_Range(root,2,6);
    if(isBST3(root)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    // vector<int>* v;
    // int x;
    // cin>>x;
    // v = path_BT(root,x);
    // for(int i=0;i < v->size();i++){
    //     cout<<v->at(i)<<" ";
    // }
    // cout<<endl;
    return 0;
}
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
//BST
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
//1 0 3 -1 -1 2 6 -1 -1 5 -1 4 -1 -1 -1