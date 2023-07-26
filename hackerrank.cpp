#include <bits/stdc++.h>
using namespace std;
int func(int val[],int s,int e){
    if(s>e){
        return 0;
    }
    int a = 0 ;
    int b=0;
    if(val[s+1]<val[e]){
        a = func(val,s+1,e-1)+val[s];
    }else{
        a = func(val,s+2,e)+val[s];
    }
    if(val[s]<val[e-1]){
        b = func(val,s,e-2)+val[e];
    }else{
        b = func(val,s+1,e-1)+val[e];
    }
    return max(a,b);
}
int main(){
    int val[] = {20,20,190,11,55};
    cout<<func(val,0,3);
 return 0;
}