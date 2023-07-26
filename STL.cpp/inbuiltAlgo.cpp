//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pb push_back
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        wordList.pb(targetWord);
        int n = wordList.size();
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            m[wordList[i]]=1;
        }
        queue<pair<string,int>> q;
        q.push({startWord,1});
        int ans = INT_MAX;
        int len = startWord.size();
        while(q.size()!=0){
            pair<string,int> front  = q.front();
            string word = front.first;
            int step = front.second;
           // cout<<"hello"<<endl;
            q.pop();
            for(int j=0;j<len;j++){
                string temp =word;
                for(int i = 'a';i<='z';i++){
                    temp[j]= i;
                    if(m[temp]&&temp!=startWord){
                        q.push({temp,step+1});
                        cout<<temp<<"   "<<step+1<<endl;
                        if(temp == targetWord){
                            ans = step+1;
                            return ans;
                        }
                    }
                }
            }
        }
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