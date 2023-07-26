class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int ans[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0|j==0){
                    ans[i][j]=0;
                    continue;
                }
                if(s[i-1]==t[j-1]) ans[i][j]=ans[i-1][j-1]+1;
                else ans[i][j] = max(ans[i][j-1],ans[i-1][j]);
            }
        }
        int len = ans[m][n];
        int i=m;
        int j=n;
        string str;
        while(i>0&&j>0){
            if(s[i-1]==t[j-1]){
                str.push_back(s[i-1]);
                i--;
                j--;
            }else{
                if(ans[i-1][j]>ans[i][j-1]){
                    str.push_back(s[i-1]);
                    i--;
                }else{
                    str.push_back(t[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            str.push_back(s[i-1]);
            i--;
        }
        while(j>0){
            str.push_back(t[j-1]);
            j--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};