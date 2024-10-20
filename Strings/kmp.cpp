#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(string& s, string& p) {
    string str = p + '#' + s;
    int n = str.size();
    vector<int> lps(n, 0);
    vector<int> index;
    int k = p.size();
    for (int i = 1; i < n; i++) {
        int prev_idx = lps[i - 1];
        while (prev_idx > 0 && str[prev_idx] != str[i]) {
            prev_idx = lps[prev_idx - 1];
        }
        lps[i] = prev_idx + (str[i] == str[prev_idx]);
        if(lps[i]==k) index.push_back(i-2*k);
    }
    //return lps;
    return index;
}
vector<int> kmp(string &s,string &p){
    string str = p+'$'+s;
    int n =str.size();
    vector<int> lps(n,0),index;
    for(int i=1;i<n;i++){
        int prev_idx = lps(i-1);
        while(prev_idx>0&&s[i]!=s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }
        lps[i] = prev_idx + (str[i]==str[prev_idx]);
        if(lps[i]==(int)p.size()) index.push_back(i-2*(int)p.size());
    }
    return lps;
}
// String : a a b a a  c  a a b a a  d
// LPS    : 0 1 0 1 2  0  1 2 3 4 5  0

// String : a a b #  a a b  a a b  a a b
// LPS    : 0 1 0 0  1 2 3  1 2 3  1 2 3

// Prefix that matches any subtsring of the string
// Largest prefix that matches a suffix
// vector<int> kmp(string s){
//     vector<int> lps(s.size(), 0);

//     for(int i=1;i<lps.size();i++){
//         int prev_idx = lps[i-1];

//         while(prev_idx>0 && s[i] != s[prev_idx]){
//             prev_idx = lps[prev_idx-1];
//         }

//         lps[i] = prev_idx + (s[i]==s[prev_idx] ? 1 : 0);
//     }

//     return lps;
// }
int main(){
 return 0;
}