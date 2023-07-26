#include <iostream>
using namespace std;
#include "binary_tree_class.h"
#include "BST.h"
#include <queue>
void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);

}
BinaryTreeNode<int>* takeInput(){
    cout<<"Enter Data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=takeInput();
    root->right=takeInput();
    return root;
}
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
int count_nodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    //cout<<ans;
    int ans=1;
    ans+=count_nodes(root->left);
    //cout<<ans;
    ans+=count_nodes(root->right);
    //cout<<ans<<endl;
    return ans; 
}
bool find_x(BinaryTreeNode<int>* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    return find_x(root->left,x)||find_x(root->right,x) ; 
}
int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return  1+max(height(root->left),height(root->right));
}
void mirror(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    mirror(root->left);
    mirror(root->right);
    BinaryTreeNode<int>* root1 =root->left;
    BinaryTreeNode<int>* root2 = root->right;
    root->left=root2;
    root->right=root1;
    return;

}
void print_postorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}
void print_inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<' ';
    print_inorder(root->right);
}
//constructing tree using preorder and indorder traversal
BinaryTreeNode<int>* constructTreeHelper(int *in,int *pre,int ins,int ine,int pres,int pree){
    if(ins>ine){
        return NULL;
    }
    int rootData = pre[pres];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++){
        if(in[i]==rootData){
            rootindex=i;
            break;
        }
    }
    int lpres=pres+1;
    int lins=ins;
    int line=rootindex-1;
    int lpree=line-lins+lpres;
    int rpres=lpree+1;
    int rpree=pree;
    int rins=rootindex+1;
    int rine=ine;
    BinaryTreeNode<int>* root =new BinaryTreeNode<int>(rootData);
    root->left=constructTreeHelper(in,pre,lins,line,lpres,lpree);
    root->right=constructTreeHelper(in,pre,rins,rine,rpres,rpree);
    return root;
}
BinaryTreeNode<int>* constructTree(int *in,int *pre,int size){
    return constructTreeHelper(in,pre,0,size-1,0,size-1);
}
//constructing tree using inorder and postorder
BinaryTreeNode<int>* constructTreeHelper_2(int *in,int *pos,int ins,int ine,int poss,int pose){
    if(ins>ine){
        return NULL;
    }
    int rootData = pos[pose];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++){
        if(in[i]==rootData){
            rootindex=i;
            break;
        }
    }
    int lins=ins;
    int line=rootindex-1;
    int lposs=poss;
    int lpose=line-lins+lposs;
    int rins=rootindex+1;
    int rine=ine;
    int rposs=lpose+1;
    int rpose=pose-1;
    BinaryTreeNode<int>* root =new BinaryTreeNode<int>(rootData);
    root->left=constructTreeHelper_2(in,pos,lins,line,lposs,lpose);
    root->right=constructTreeHelper_2(in,pos,rins,rine,rposs,rpose);
    return root;
}
BinaryTreeNode<int>* constructTree_2(int *in,int *pos,int size){
    return constructTreeHelper_2(in,pos,0,size-1,0,size-1);
}
//diameter of tree 
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return max((height(root->left)+height(root->right)),max(diameter(root->left),diameter(root->right)));
}
pair<int,int> diameter_better(BinaryTreeNode<int>* root){
    if(root ==NULL){
        return pair<int,int>(0,0);
    }
    pair<int,int> c;
    pair<int,int> d = diameter_better(root->left);
    pair<int,int> e = diameter_better(root->right);
    c.first = d.first>e.first ? 1 + d.first : 1 + e.first;
    int a =d.second;
    int b =e.second;
    int f =max((d.first+e.first),max(a,b));
    c.second =f;
    return c;
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
int hasPathSum(BinaryTreeNode<int>* A, int B) {
        if(A==NULL&&B==0) return 1;
    if(A==NULL&&B!=0) return 0;
    if(A->left==NULL&&A->right==NULL) return B== A->data;
    return hasPathSum(A->left,B-A->data)||hasPathSum(A->right,B-A->data);
}

int main(){
    BinaryTreeNode<int>* root =takeInput_LW();
    print_LW(root);
    cout<<diameter_better(root).second<<endl;
    cout<<diameter(root)<<endl;
    // BST b;
    // b.insert(10);
    // b.insert(5);
    // b.insert(20);
    // b.insert(7);
    // b.insert(3);
    // b.insert(15);
    // b.printTree();
    // b.deleteData(10);
    // b.printTree();
    // if(b.hasData(20)) cout<<"Bella Ciao"<<endl;   
    return 0;
}
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
