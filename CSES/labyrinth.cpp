#include <bits/stdc++.h>
using namespace std;
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define v2i  vector<vector<int>>
#define v2c  vector<vector<char>>
#define pi pair<int,int>
int main(){
    int n,m;
    cin>>n>>m;
    v2c mat(n,vector<char>(m));
    v2i vis(n,vector<int>(m,0));
    pi start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){
                start.first=i;
                start.second=j;
            }
            if(mat[i][j]=='B'){
                end.first=i;
                end.second=j;
            }
        }
    }
        auto cmp = [](const pair<string, pair<int, int>>& left, 
                  const pair<string, pair<int, int>>& right) {
        return left.first.size() > right.first.size();
    };

    priority_queue<
        pair<string, pair<int, int>>, 
        vector<pair<string, pair<int, int>>>, 
        decltype(cmp)
    > q(cmp);
    q.push({"",start});
    vis[start.first][start.second] = 1;
    int del[] = {-1,0,1,0,-1};
    string path[] ={"U","R","D","L"};
    string ans = "";
    while(q.size()){
        auto it =q.top();
        q.pop();
        int i =it.second.first;
        int j =it.second.second;
        string s=it.first;
        if(end.first==i&&end.second==j){
            ans=s;
            break;
        }
        for(int k=0;k<=3;k++){
            int nr = i+del[k];
            int nc = j+del[k+1];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&mat[nr][nc]!='#'){
                q.push({s+path[k],{nr,nc}});
                vis[nr][nc]=1;
            }
        }
    }
    if(ans.size()){
        yes;
      cout<<ans.size()<<endl<<ans<<endl;  
    }else{
        no;
    }
    
 return 0;
}