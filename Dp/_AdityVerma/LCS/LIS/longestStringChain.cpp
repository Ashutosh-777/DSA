#include <bits/stdc++.h> 
bool compareByLetterCount(const string& a, const string& b) {
    return a.length() < b.length();
}
bool check(string &s,string &t){
    int m = s.size();
    int n = t.size();
    if(m!=n+1) return false;
    int j = 0;
    int i = 0;
    while(i<m){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j==n&&i==m) return true;
    return false;
}
int longestStrChain(vector<string> &arr)
{
    sort(arr.begin(),arr.end(),compareByLetterCount);
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n,1);
    int maxi = -1;
    for(int curr = 0;curr<n;curr++){
        for(int prev = 0;prev<curr;prev++){
            string s = arr[curr];
            string t = arr[prev];
            if(check(s,t)&&1+dp[prev]>dp[curr]){
                dp[curr] = 1 + dp[prev];
            }
            //need to check if t is present in s or not

        }
        maxi = max(dp[curr],maxi);
    }
    return maxi;
}