#include <bits/stdc++.h>

using namespace std;

const vector<string> allPermissions = {
    "banking.confirm_intent", 
    "banking.create_intent", 
    "banking.read_intent", 
    "banking.read_settings", 
    "banking.write_settings",
    "capital.confirm_intent", 
    "capital.create_intent", 
    "capital.read_intent", 
    "capital.read_settings", 
    "capital.write_settings",
    "climate.confirm_intent", 
    "climate.create_intent", 
    "climate.read_intent", 
    "climate.read_settings", 
    "climate.write_settings",
    "identity.confirm_intent", 
    "identity.create_intent", 
    "identity.read_intent", 
    "identity.read_settings", 
    "identity.write_settings",
    "payments.cancel_refund", 
    "payments.confirm_intent", 
    "payments.create_dispute", 
    "payments.create_intent", 
    "payments.create_refund",
    "payments.read_dispute", 
    "payments.read_intent", 
    "payments.read_refund", 
    "payments.read_settings", 
    "payments.update_dispute", 
    "payments.write_settings"
};

int main() {
    string key_mode = "full_tokes";  
    vector<string> roles = {"admin_readonly","payments"};
    
    map<string , vector<int>> mpp;
    
    for(int i=0;i<31;i++){
    	mpp["admin"].push_back(i);
    }
    
    mpp["admin_readonly"] = {2,3,7,8,12,13,17,18,25,26,27,28};
    
    for(int i=0;i<5;i++){
    	mpp["banking"].push_back(i);
    }
    
    for(int i=5;i<10;i++){
    	mpp["capital"].push_back(i);
    }
    
    for(int i=10;i<15;i++){
    	mpp["climate"].push_back(i);
    }
    
    for(int i=15;i<20;i++){
    	mpp["identity"].push_back(i);
    }
    
    for(int i=20;i<31;i++){
    	mpp["payments"].push_back(i);
    }
    
    set<int> s;
    for(int i=0;i<roles.size();i++){
    	for(int x : mpp[roles[i]]){
    		s.insert(x);
    	}
    }
    
    string ans , bit_ans(31 , '0');
    for(int x : s){
    	ans += allPermissions[x];
    	ans += '\n';
    	bit_ans[x] = '1'; 
    }
    ans.pop_back();
    
    if(key_mode == "full_tokens"){
    	cout << bit_ans << endl;
    } 
    else{
    	cout << ans << endl;
    }
}