#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1,2,3,4,5,6};
    vector<int> :: iterator it = v.begin();
    for( int &value:v){
        value++;
        cout<<value<<" ";
    }
    cout<<endl;
    for(;it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it:v){
        cout<<it<<" ";
    }
 return 0;
}