class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int ans[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) {ans[i][j]=0; continue;}
                if(s[i-1]==t[j-1]) ans[i][j] = 1+ ans[i-1][j-1];
                else ans[i][j] =  max(ans[i-1][j],ans[i][j-1]);
                //cout<<ans[i][j]<<" ";
            }
            //cout<<endl;
        }
        int lcs =  ans[m][n];
        int i = m;
        int j = n ;
        string str;
        while(i>0&&j>0){
            if(s[i-1]==t[j-1]){
                str.push_back(s[i-1]);
                i--;
                j--;
            }else{
                if(ans[i-1][j]>ans[i][j-1]){
                    i--;
                }else{
                    j--;                    
                }
            }
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;
        return ans[m][n];
    }
};