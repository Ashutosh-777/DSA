#include <bits/stdc++.h>
using namespace std;
#define v2 vector<vector<int>>
#define pi pair<int,int>
void bfs(int row,int col,v2&vis,v2&mat){
    queue<pi> q;
    q.push({row,col});
    vis[row][col] = 1;
    int del[] = {-1,0,1,0,-1};
    int n =mat.size();
    int m =mat[0].size();
    while(q.size()){
        auto it = q.front();
        int i =it.first;
        int j =it.second;
        q.pop();
        for(int k=0;k<=3;k++){
            int nr = i+del[k];
            int nc = j+del[k+1];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&mat[nr][nc]){
                q.push({nr,nc});
                vis[nr][nc]=1;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
     v2 mat(n,vector<int>(m,0)),vis(n,vector<int>(m,0));
     queue<pi> q;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch ='#';
            cin>>ch;
            if(ch=='.'){
                mat[i][j]=1;
                q.push({i,j});
            }
        }
     }
     int ans = 0;
     while(q.size()){
        auto it =q.front();
        q.pop();
        int r = it.first;
        int c = it.second;
        if(!vis[r][c]){
            ans++;
            bfs(r,c,vis,mat);
        }
     }
     cout<<ans<<endl;
 return 0;
}