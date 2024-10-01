class Node{
    public:
    char data;
    Node* *children;
    bool  isTerminal;
    Node(char data){
        this->data = data;
        children = new Node*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal =false;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node('\0');
    }
    void insert(string word){
        Node *prev = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(prev->children[ind]!=NULL){
                prev = prev->children[ind];
            }else{
                Node *child = new Node(ch);
                prev->children[ind] = child;
                prev= child;
            }
        }
        prev->isTerminal=true;
    }
    bool search(string word){
        Node *prev =root;
        for(auto ch:word){
            int ind = ch-'a';
            if(prev->children[ind]==NULL){
                return false;
            }else{
                prev = prev->children[ind];
            }
        }
        return prev->isTerminal;
    }
    bool startsWith(string word){
        Node *prev = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(prev->children[ind]==NULL){
                return false;
            }else{
                prev=prev->children[ind];
            }
        }
        return true;
    }
};