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
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        next = NULL;
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
int sumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->data+sumNodes(root->left)+sumNodes(root->right);
}
int height(Node* root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}
bool isBalanced(Node* root){
    if(root==NULL){
        return 1;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int a = abs(lh-rh);
    if(a<=1&&isBalanced(root->left)&&isBalanced(root->right)) return 1;
    else return 0;
}
Node* removeLeaf(Node* root){
    if(root==NULL||(root->left==NULL&&root->right==NULL)) {
        delete(root);
        return NULL;
    }
    root->left = removeLeaf(root->left);
    root->right = removeLeaf(root->right);
    return root;
}
vector<ListNode*> getLinkedList(Node* root){
    vector<ListNode*> a;
    queue<Node*> q;
    q.push(root);
    while(q.size()!=0){
        Node* front1 = q.front();
        ListNode* head = new ListNode(front1->data);
        a.push_back(head);
        int n = q.size();
        bool skip = true;
        while(n--){
            Node* front = q.front();
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
            q.pop();
            if(skip) {
                skip = false;
                continue;
            }
            ListNode* temp = new ListNode(front->data);
            head->next = temp;
            head=temp;
        }
        head->next =  NULL;
    }
    return a;
}
void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void nodesWithoutSibling(Node* root,vector<int> &a){
    if(root==NULL) return;
    if(root->left==NULL&&root->right!=NULL) a.push_back(root->right->data);
    if(root->right==NULL&&root->left!=NULL) a.push_back(root->left->data);
    nodesWithoutSibling(root->left,a);
    nodesWithoutSibling(root->right,a);
}
void printZigZag(Node* root){
    queue<Node*> q;
    q.push(root);
    bool reverse =  false;
    vector<int> a;
    while(q.size()){
        int n = q.size();
        stack<int> s;
        while(n--){
            Node* front = q.front();
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            if(!reverse) {
                a.push_back(front->data);
            }else{
                s.push(front->data);
            }
        }
        if(reverse){
            while(s.size()){
                a.push_back(s.top());
                s.pop();
            }
        }
        reverse = !reverse;
    }
}
vector<int> solve1(Node* root, int x) {
    queue<pair<Node*,int>> q;
    q.push({root,0});
    bool found = false;
    Node* sibling=NULL;
    vector<int> v;
    int level = -1;
    while(!q.empty()){
        int n= q.size();
        while(n--){
        Node* front = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if(sibling!=NULL){
        if(front!=sibling&&front->data!=x&&lvl==level)
        {
            v.push_back(front->data);
        }
        }else{
            cout<<"lvl = "<<lvl<<"level = "<<level<<endl;
        if(front->data!=x&&lvl==level)
        {
            v.push_back(front->data);
        }  
        }
        if(front->left) {
            q.push({front->left,lvl+1});
            if(front->left->data==x){
                    level=lvl+1;
                if(front->right){
                    sibling = front->right;
                }
            }
        }
        if(front->right){
            q.push({front->right,lvl+1});
            if(front->right->data==x){
                cout<<"hello";
                    level = lvl+1;
                if(front->left){
                    sibling = front->left;
                }
            }    
        }
        }
    }
    return v;
}
void traversal(Node* root,vector<Node*>& v){
    if(root==NULL) return ;
    v.push_back(root);
    traversal(root->left,v);
    traversal(root->right,v);
}
int main(){
    Node* root = takeInput_LW();
    vector<Node*> v;
    print_LW(root);
    traversal(root,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]->data<<' ';
    }
    // vector<int> a = solve1(root,5);
    // cout<<"hi"<<endl;
    // //nodesWithoutSibling(root,a);
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }
    // //print_LW(root);
    //cout<<isBalanced(root);
 return 0;
}