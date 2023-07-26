class MaxHeap{
    vector<int> pq;
    public:
    MaxHeap(){}
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMax(){
       if(!isEmpty()){
        return pq[0];
       }else cout<<"Empty!"<<endl; 
       return -1;
    }
    private:
    void upHeapify(int parent,int childIndex){
        swap(pq[parent],pq[childIndex]);
        childIndex = parent ;
        if(childIndex<=0) return;
        parent = (childIndex-1)/2;
        if(pq[parent]<pq[childIndex]){
            upHeapify(parent,childIndex);
        }
    }
    void downHeapify(int i){
        int size = getSize();
        size--;
        if((2*i+1)>size) return;
        if((2*i+2)>size){
            int parent = pq[i];
            int child = pq[2*i+1];
            if(parent<child){
                swap(pq[2*i+1],pq[i]);
                downHeapify(2*i+1);
            }
        }else{
            if(pq[2*i+1]<pq[2*i+2]){
                swap(pq[2*i+2],pq[i]);
                downHeapify(2*i+2);
            }else{
                swap(pq[2*i+1],pq[i]);
                downHeapify(2*i+1);
            }
        }
        return ; 
    }
    //insert in a priority Queue
    public:
    void insert(int data){
        int childIndex = pq.size();
        pq.push_back(data);
        if(childIndex>=1){
        int parent = (childIndex-1)/2;
        if(pq[parent]<data){
            upHeapify(parent,childIndex);
        }
        }
    }
    void print(){
        int n = pq.size();
        for(int i=0;i<n;i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
    void pop(){
        if(getSize()==0){
            cout<<"Error! Protity Queue is already empty \n";
            return;
        }
        swap(pq[0],pq[getSize()-1]);
        pq.pop_back();
        downHeapify(0);
    }
};