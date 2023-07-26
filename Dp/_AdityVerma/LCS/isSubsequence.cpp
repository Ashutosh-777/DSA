class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int ans[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    ans[i][j]=0;
                    continue;
                }
                if(s[i-1]==t[j-1]) ans[i][j] = 1 + ans[i-1][j-1];
                else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
        return ans[m][n]==m;
    }
};