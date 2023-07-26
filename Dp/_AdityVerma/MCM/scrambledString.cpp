//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    map<string,bool> ans;
    bool solve(string s,string t){
        //Base Condition
        //return true if strings are same or empty
        int n = s.length();
        if(s==t) return 1;
        //cannot divide into empty string
        if(n<=1) return 0;
        //recursive calls and necessary calculations
        //i can not start from 0 bcoz empty strings not allowed
        //i can go upto n-1 only bcoz empty string not allowed as of now lets see
        string key = s+"_"+t;
        if(ans.find(key)!=ans.end()){
            return ans[key];
        }
        bool flag = false;
        for(int i=1;i<n;i++){
            //caseI when swapped
            int a = solve(s.substr(0,i),t.substr(n-i,i)); 
            int b = solve(s.substr(i,n-i),t.substr(0,n-i)); 
            if(a&&b){
                flag = true;
                break;
            }
            //casII not swapped
            int x = solve(s.substr(0,i),t.substr(0,i)); 
            int y = solve(s.substr(i,n-i),t.substr(i,n-i)); 
            if(x&&y){
                flag = true;
            }
        }
        return ans[key]=flag;
    }
    
    public:
    bool isScramble(string S1, string S2){
        //if they are not of same size they will never be scrambled string of each other
        if(S1.size()!=S2.size()) return 0;
        return solve(S1,S2);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob; 
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends