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
class Trie_1{
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
    bool startsWith(TrieNode *root,string word){
        if(word.size()==0) return true;
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
        bool canBeDeleted = true;
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
    Trie_1(){
        root = new TrieNode('\0'); 
    }
    void insertWord(string word){
        insertWord(root,word);
    }
    bool search(string word){
        return search(root,word);
    }
    bool startsWith(string word){
        return startsWith(root,word);
    }
    void remove(string word){
        remove(root,word);
    }
};

class Trie {
    Trie_1 tr;
public:

    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        tr.insertWord(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return tr.search(word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return tr.startsWith(prefix);
    }
};
int main(){
    Trie tr;
    tr.insert("hello");
    tr.insert("help");
    cout<<tr.search("help")<<endl;
    cout<<tr.startsWith("hell")<<endl;
    cout<<tr.search("hell")<<endl;
 return 0;
}