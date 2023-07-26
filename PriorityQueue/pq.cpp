//MAX HEAP
#include <bits/stdc++.h>
using namespace std;
#include "maxHeap.h"
int main(){
    MaxHeap pq;
    pq.insert(12);
    pq.print();
    pq.insert(6);
    //pq.pop();
    pq.print();
    pq.insert(5);
    pq.insert(100);
    pq.print();
    pq.insert(1);
    pq.insert(9);
    pq.print();
    pq.insert(0);
    pq.insert(14);
    pq.print();
    // pq.insert(0);
    // pq.print();
    cout<<"Size: "<<pq.getSize()<<" Max: "<<pq.getMax()<<endl;
    pq.pop();
    pq.print();
    cout<<"Size: "<<pq.getSize()<<" Max: "<<pq.getMax()<<endl;
    pq.pop();
    pq.print();
    cout<<"Priority Queue Successfully Created"<<endl;
 return 0;
}
//MIN HEAP
// #include <bits/stdc++.h>
// using namespace std;
// #include "pq.h"
// int main(){
//     PriorityQueue pq;
//     pq.insert(12);
//     pq.print();
//     pq.insert(6);
//     pq.pop();
//     pq.print();
//     pq.insert(5);
//     pq.insert(100);
//     pq.print();
//     pq.insert(1);
//     pq.insert(9);
//     pq.print();
//     pq.insert(0);
//     pq.insert(14);
//     pq.print();
//     // pq.insert(0);
//     // pq.print();
//     cout<<"Size: "<<pq.getSize()<<" MIn: "<<pq.getMin()<<endl;
//     pq.pop();
//     pq.print();
//     cout<<"Size: "<<pq.getSize()<<" MIn: "<<pq.getMin()<<endl;
//     pq.pop();
//     pq.print();
//     cout<<"Priority Queue Successfully Created"<<endl;
//  return 0;
// }