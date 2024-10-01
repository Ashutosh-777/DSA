void generateMasks(int n,int i,int mask,int next,vector<int> &masks){

    if(i==n){
        masks.push_back(next);
        return;
    }
    if(mask&(1<<i)){
        generateMasks(n,i+1,mask,next,masks);
        return;
    }
    if((i+1!=n)&&!(mask&(1<<(i+1)))){
        generateMasks(n,i+2,mask|(1<<i)|(1<<(i+1)),next,masks);
        // generateMasks(n,i+1,mask|(1<<i),next|(1<<i),masks);
        // return;
    }
    generateMasks(n,i+1,mask|(1<<i),next|(1<<i),masks);
}