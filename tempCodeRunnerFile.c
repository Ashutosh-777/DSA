#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class Node{
    public:
    char data;
    Node* children[26];
    bool isTerminal;
    Node(char data='\0'){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class Trie {
    Node *root;
    public:
    Trie(){
        root =   new Node('\0');
    }
    void insert(string word){
        Node* prev=  root;
        for(auto ch:word){
            int ind = ch-'a';
            if(prev->children[ind]!=NULL){
                prev = prev->children[ind];
            }else{
                Node *child = new Node(ch);
                prev = child;
            }
        }
        prev->isTerminal = true;
    }
    bool search(string word){
        Node *prev = root;
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
    void remove(string word){
        Node *prev = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(prev->children[ind]==NULL){
                return;
            }else{
                prev = prev->children[ind];
            }
        }
        prev->isTerminal = false;
        return;
    }
    bool startsWith(string word){
        Node *prev = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(prev->children[ind]){
                prev = prev->children[ind];
            }else{
                return false;
            }
        }
        return true;
    }
    /** Inserts a word into the trie. */

    /** Returns if the word is in the trie. */

    /** Returns if there is any word in the trie that starts with the given prefix. */
};
int main(){
    Trie tr;
    tr.insert("abcd");
    cout<<tr.search("abcd")<<"   "<<tr.startsWith("abc")<<endl;
 return 0;
}