#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode**children;
    bool isTerminal;
    TrieNode(char data){
        this->data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    TrieNode* root;
    void insertWord(TrieNode*root,string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child,word.substr(1));
    }
    bool search(TrieNode *root,string word){
        if(word.size()==0) return root->isTerminal;
        int ind = word[0]-'a';
        if(root->children[ind]==NULL){
            return false;
        }else{
            TrieNode *child = root->children[ind];
            return search(child,word.substr(1));
        }
    }
    void remove(TrieNode*root,string word){
        if(word.size()==0){
            if(root->isTerminal==false){
                cout<<"Word is not present in the dictionary "<<endl; 
            }
            root->isTerminal = false;
            return;
        }
        int index = word[0]-'a';
        TrieNode *child = root->children[index];
        if(child==NULL){
            cout<<"Word is not present in the dictionary\n";
            return;
        }
        remove(child,word.substr(1));
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL){
                return;
            }
        }
        if(child->isTerminal==false){
            delete child;
            root->children[index] = NULL;
        }
    }
    public:
    Trie(){
        root = new TrieNode('\0'); 
    }
    void insertWord(string word){
        insertWord(root,word);
    }
    bool search(string word){
        return search(root,word);
    }
    void remove(string word){
        remove(root,word);
    }
};
int main(){
    Trie tr;
    tr.insertWord("abcd");
    // tr.insertWord("z");
    // cout<<tr.search("z")<<" "<<tr.search("z")<<"  "<<tr.search("abcd")<<" "<<tr.search("zc")<<tr.search("abcd")<<endl;
    // tr.remove("z");
    // tr.insertWord("abcdef");
    // cout<<tr.search("abcdef")<<endl;
    // tr.remove("abcdef");
    // tr.remove("abcd");
    // cout<<tr.search("abcdef");
    tr.remove("abcd");
    tr.insertWord("abc");
    cout<<tr.search("abcd")<<"\n"<<tr.search("abc")<<endl;
 return 0;
}