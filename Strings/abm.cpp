#include <bits/stdc++.h>
using namespace std;
vector<string> split(string str){
    vector<string> result;
    stringstream ss(str);
    string word;
    while(getline(ss,word,',')){
        result.push_back(word);
    }
    return result;
}
class StripeAccount{
    public:
    string name;
    int balance;
    vector<string> banks;
    StripeAccount(vector<string> &v){
        name = v[1];
        balance = stoi(v[2]);
        for(int i=3;i<(int)v.size();i++){
            banks.push_back(v[i]);
        }
    }
};
vector<string> solve(vector<string> &vec){
    vector<vector<string>> transactions;
    int n = vec.size();
    int index = 0;
    vector<StripeAccount> account;
    map<string,int> mp;
    for(index;index<n;index++){
        if(vec[index][0]=='I'){
            vector<string> v = split(vec[index]);
            StripeAccount acc(v);
            mp[acc.name] = account.size();
            account.push_back(acc);
        }else{
            break;
        }
    }
    int k = index;
    for(index;index<n;index++){
        vector<string> temp = split(vec[index]);
        swap(temp[0],temp[1]);
        temp.push_back(to_string(index-k));
        transactions.push_back(temp);
    }
    sort(transactions.begin(),transactions.end());
    int tSize = transactions.size();
    vector<string> result(tSize);
    for(vector<string> temp:transactions){
        string method = temp[1];
        int i = stoi(temp.back());
        string sender = temp[2];
        if(method=="GET"){
            if(mp.find(sender)==mp.end()) {result[i] = "-1,"; continue;}
            result[i] = (to_string(account[mp[sender]].balance));
        }else{
            string reciever = temp[3];
            if(mp.find(sender)!=mp.end()&&mp.find(reciever)!=mp.end()){
                StripeAccount *senderAcc = &account[mp[sender]],*recieverAcc = &account[mp[reciever]];
                int amount = stoi(temp[4]);
                if(amount<=senderAcc->balance){
                    senderAcc->balance-=amount;
                    recieverAcc->balance+=amount;
                    result[i] = ("SUCCESS");
                }else{
                    result[i] = ("FAILURE");
                }
            }
            else if(mp.find(sender)!=mp.end()){
                StripeAccount *senderAcc = &account[mp[sender]];
                auto bank = senderAcc->banks;
                bool flag = false;
                for(string s:bank){
                    if(s==reciever){
                        flag=true;
                        break;
                    }
                }
                int amount = stoi(temp[4]);
                if(flag){
                    int balance = senderAcc->balance;
                    if(balance>=amount){
                        result[i] = "SUCCESS";
                        senderAcc->balance-=amount;
                    }else{
                        result[i] = "FAILURE";
                    }
                }else{
                    result[i] = "FAILURE";
                }
            }else if(mp.find(reciever)!=mp.end()){
                StripeAccount *recieverAcc = &account[mp[reciever]];
                auto bank = recieverAcc->banks;
                bool flag = false;
                for(string s:bank){
                    if(s==reciever){
                        flag=true;
                        break;
                    }
                }
                int amount = stoi(temp[4]);
                if(flag){
                    result[i] = "SUCCESS";
                    recieverAcc->balance+=amount;
                }else{
                    result[i] = "FAILURE";
                }  
            }else{
                result[i] = "FAILURE";
            }
        }
        result[i]+=",";
    }
    result.back().pop_back();
    return result;
}
int main(){
    #include <vector>
#include <string>

std::vector<std::string> commands = {
    // Original inputs
    "INIT,Alice,100,Chase,Wells Fargo",
    "INIT,Bob,50,Bank of America,Chase,Ally",
    "INIT,Charles,0,Bank of America",
    "INIT,David,200,HSBC,Citi",
    "INIT,Emma,300,Barclays,Chase,HSBC",
    "POST,501,David,Bob,75",
    "POST,212,Alice,Bob,50",
    "GET,211,Alice",
    "POST,213,Alice,Charles,50",
    "GET,214,Alice",
    "POST,301,Charles,Bob,100",
    "POST,302,Ally,Charles,10",
    "POST,365,Kate,Alice,50",
    "GET,401,Charles",
    "POST,306,Alice,Chase,50",
    
    // Additional inputs
    "GET,502,David",
    "POST,503,Emma,Alice,150",
    "POST,504,Emma,Charles,25",
    "GET,505,Emma",
    "POST,601,Alice,David,50",
    "GET,602,Alice",
    "POST,603,Charles,David,30",
    "POST,604,Bob,Emma,100",
    "GET,605,Bob"
};

 auto result = solve(commands);
 for(auto str:result){
    cout<<str;
 }
 cout<<endl;
 return 0;
}