#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	   
	  vector<int> dpincr(n,1),dpdecr(n,1);
	  for(int curr = 0;curr<n;curr++){
		  for(int prev = 0;prev<curr;prev++){
			  if(arr[prev]<arr[curr]&&1+dpincr[prev]>dpincr[curr]){
				  dpincr[curr] = 1 + dpincr[prev];
			  }
		  }
	  }
	  for(int curr=n-1;curr>=0;curr--){
		  for(int prev=n-1;prev>curr;prev--){
			  if(arr[curr]>arr[prev]&&dpdecr[prev]+1>dpdecr[curr]){
				  dpdecr[curr]=dpdecr[prev]+1;
			  }
		  }
	  }
	  int ans = 0;
	  for(int i=0;i<n;i++){
		  int x = dpincr[i]+dpdecr[i];
		  ans=max(ans,x);
	  }
	  return ans-1;
} 
