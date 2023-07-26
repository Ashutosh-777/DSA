#include <iostream>
using namespace std;
int  Binary_search(int a[],int x,int n){
        int start,middle,end;
        start=0;
        end=n-1;
        while(end>=start){
            middle = start + (end-start)/2;
            if(a[middle]==x){
             return middle;
            }
            if(a[middle]<x){
             start=middle+1;
             continue;
            }else{
             end=middle-1;
             continue;
            }
        } 
        return -1;
}
int  Binary_searchFirst(int a[],int x,int n){
        int start,middle,end;
        start=0;
        end=n-1;
        int index=-1;
        while(end>=start){
            middle = start + (end-start)/2;
            if(a[middle]==x){
             index=middle;
             end = middle-1;
             continue;
            }
            if(a[middle]<x){
             start=middle+1;
             continue;
            }else{
             end=middle-1;
             continue;
            }
        } 
        return index;
}
int  Binary_searchLast(int a[],int x,int n){
        int start,middle,end;
        start=0;
        end=n-1;
        int index=-2;
        while(end>=start){
            middle = start + (end-start)/2;
            if(a[middle]==x){
             index=middle;
             start = middle+1;
             continue;
            }
            if(a[middle]<x){
             start=middle+1;
             continue;
            }else{
             end=middle-1;
             continue;
            }
        } 
        return index;
}
int  Binary_search_descending(int a[],int x,int n){
        int start,middle,end;
        start=0;
        end=n-1;
        while(end>=start){
            middle = start + (end-start)/2;
            if(a[middle]==x){
             return middle;
            }
            if(a[middle]<x){
             end=middle-1;
             continue;
            }else{
             start=middle+1;
             continue;
            }
        } 
        return -1;
}
int count(int a[],int n,int s,int e,int x){
    if(s>=e){
        if(s==e&&a[s]==x){return 1;}else{
            return 0;
        }
    }
    int count1 =0;
        int middle = s+(e-s)/2;
        if(a[middle]==x){
            count1  += count(a,n,s,middle,x);
            count1  += count(a,n,middle+1,e,x);
        }
        if(a[middle]>x){
             count1  += count(a,n,s,middle,x);
        }
        if(a[middle]<x){
         count1 +=count(a,n,middle+1,e,x);
        }
    return count1 ;
}
int count_1(int a[],int n,int x){
    return Binary_searchLast(a,x,n)-Binary_searchFirst(a,x,n)+1;
}
int rotated(int a[],int n){
    int start,middle,end;
    start=0;
    end=n-1;
    while(start<=end){
        int middle = (start + (end-start)/2)%n;
        cout<<a[middle]<<a[middle+1]<<a[middle-1]<<endl;
        if(a[middle]<a[(middle+1)%n]&&a[middle]<a[(middle-1+n)%n]){
            return middle;
        }else{
            if(a[middle]<a[end]){
                end = middle-1;
            }else{
                start = middle+1;
            }
        }
    }
    return -1;
}
int find_rotated(int a[],int n,int x){
    if(n==1){
        return a[0]==x? 0:-1;
    }
    int start,middle,end;
    start=0;
    end=n-1;
    int index;
    while(start<=end){
        int middle = (start + (end-start)/2)%n;
        if(a[middle]<a[(middle+1)%n]&&a[middle]<a[(middle-1+n)%n]){
            index= middle;
            break;
        }else{
            if(a[middle]<a[end]){
                end = middle-1;
            }else{
                start = middle+1;
            }
        }
    }
    start = 0;
    end = index-1;
    int start1 =index;
    int end1=n-1;
    int result=-1;
    int result1=-1;
    while(end>=start){
        middle = start + (end-start)/2;
        if(a[middle]==x){
            result =  middle;
        }
        if(a[middle]<x){
            start=middle+1;
            continue;
        }else{
            end=middle-1;
            continue;
        }
    } 
    while(end1>=start1){
        middle = start1 + (end1-start1)/2;
        if(a[middle]==x){
            result1 =  middle;
        }
        if(a[middle]<x){
            start1=middle+1;
            continue;
        }else{
            end1=middle-1;
            continue;
        }
    }
    return result == -1? result1:result;
}
int main(){
    int n=50;
    delete(n);
    n=60;
    cout<<n<<endl;
    
    return 0;
}