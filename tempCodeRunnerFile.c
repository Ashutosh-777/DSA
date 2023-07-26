#include <bits/stdc++.h>
using namespace std;
struct Node {  

    public:
    int val;  
    Node *left, *right, *next;
   Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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
        if(front->next) cout<<front->next->val<<" ";
        else cout<<"NULL"<<" ";
        cout<<endl;
        if(front->left!=NULL){
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            pendingNodes.push(front->right);
        }
    }
}

void connect(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()!=0){
        Node* temp = q.front();
        q.pop();
            int n = q.size();
            cout<<n<<endl;
            Node* next =  q.front();
            if(n) {
                n--;
            }else{
                cout<<"______"<<endl;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            while(n--){
                temp->next = next;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                temp = next;
                q.pop();
                next = q.front();
            }
    }
}
int main(){
    Node* root = takeInput_LW();
    print_LW(root);
    connect(root);

    return 0;
}