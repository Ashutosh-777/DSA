//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int len = startWord.size();
        vector<int> adj[len];
        map<string,bool> myMap;
        for(int i=0;i<wordList.size();i++){
            string op = wordList[i];
            myMap[op]=true;
            for(int i=0;i<len;i++){
                adj[i].push_back(op[i]-'a');
            }
        }
        queue<pair<string,int>> q;
        q.push({startWord,0});
        int count = 0;
        map<string,bool> m;
        m[startWord] = true;
        //cout<<"endWord#   "<<targetWord<<endl;
        //cout<<startWord<<endl;
        while(q.size()!=0){
            pair<string,int> ans = q.front();
            string s = ans.first;
            int step = ans.second;
            q.pop();
            for(int i=0;i<len;i++){
                for(auto it:adj[i]){
                    char reqd = s[i];
                    s[i]=it+'a';
                    if(myMap[s] ==true&&m[s]!=true){
                        m[s]=true;
                        //cout<<s<<"  ";
                    q.push({s,step+1});
                    if(s==targetWord){
                        count = step +1;
                        return count+1;
                        break;
                    }
                    }
                    s[i]=reqd;
                }
            }
           // cout<<endl;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends