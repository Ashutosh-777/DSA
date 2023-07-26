// vector<vector<int>> t;
// int solve(int k,int sum,vector<int> v,vector<int> &arr,int i){
//     if(i>=arr.size()){
//         return 0;
//     }
//     if(sum==0){
//         if(v.size()!=k) return  0;
//         sort(v.begin(),v.end());
//         //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
//         t.push_back(v);
//         return 1;
//     }
//     int x = INT_MIN;
//     if(arr[i]<=sum){
//         v.push_back(arr[i]);
//      x = solve(k,sum,v,arr,i+1);
//     }
//     int y = solve(k,sum-arr[i],v,arr,i+1);
//     return x||y;
    
// }
// vector<vector<int> > Solution::avgset(vector<int> &arr) {
//     t.clear();
//     sort(arr.begin(),arr.end());
//     int sum = 0;
//     for(auto it: arr){
//         sum+=it;
//     }
//     int n= arr.size();
//     double avg = (sum+0.00)/(n+0.00);
//     //avg  =  sum/n;
//     //cout<<avg<<"avg "<<endl;
//     int ans[n+1][sum+1];
//     int target[n];
//     //cout<<" HELLO "<<avg<<endl;
//     for(int i=0;i<=n;i++){
//         if(i!=n){
//             if(avg*(i+1) == static_cast<int>(avg*(i+1)))
//             target[i] = static_cast<int>(avg*(i+1));
//             else target[i]=0;
//         }
//         for(int j=0;j<=sum;j++){
//             if(i==0){
//                 ans[i][j] = 0;
//                 continue;
//             }
//             if(j==0){
//                 ans[i][j]=1;
//                 continue;
//             }
//             if(arr[i-1]<=j){
//                 ans[i][j] = ans[i-1][j]||ans[i][j-arr[i-1]];
//             }else{
//                 ans[i][j] =ans[i-1][j];
//             }
            
//         }
//     }
//     sort(arr.begin(),arr.end());
//     //cout<<"hi "<<endl;
//     vector<int> v;
//     for(int i=0;i<n;i++){
//         //cout<<target[i]<<" ";
//         if(target[i]!=0)
//       int a=  solve(i+1,target[i],v,arr,0);
//     }
//     if(t.size()==0) return t;
//     sort(t.begin(),t.end());
//     cout<<"hello "<<t.size()<<endl;
//     for(int i=0;i<3;i++){
//         cout<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2]<<" "<<t[i][3]<<endl;
//     }
//     vector<vector<int>> finalAns;
    
//     finalAns.push_back(t[0]);
//     unordered_map<int,bool> m;
//     for(int i=0;i<t[0].size();i++){
//         m[t[0][i]] = true;
//     }
//     for(int i=0;i<n;i++){
//         if(!m[arr[i]]){
//             v.push_back(arr[i]);
//         }
//     }
//     sort(v.begin(),v.end());
//     finalAns.push_back(v);
//     return finalAns;
// }































int solve(int k,double sum,vector<int> v,vector<int> &arr,int i){
    if(i>arr.size()){
        return 0 ;
    }
    if(sum==0){
        if(v.size()!=k) return 0;
        sort(v.begin(),v.end());
        //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        t.push_back(v);
        return 1 ;
    }
    int x = solve(k,sum,v,arr,i+1);
    int y = INT_MIN;
    if(sum>=arr[i]){
        //cout<<"sum "<<sum<<" arr[i] "<<arr[i]<<endl;
    v.push_back(arr[i]);
    y = solve(k,sum-arr[i],v,arr,i+1);
    }
    return x||y;
}