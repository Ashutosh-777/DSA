#include <bits/stdc++.h>
using namespace std;
// vector<string> split(const string &s,const string &delimitters){
//     vector<string> ans;
//     int start = 0;
//     int end = s.find_first_of(delimiters);
//     while(end!=string::npos){
//         if(end!=start){
//             ans.push_back(s.substr(start,end));
//         }
//         start  =end;
//         end = s.find_first_of(delimiters,start);
//     }
//     if(start<s.length()) ans.push_back(s.substr(start));
//     return ans;
// }
class Transactions{
    public:
    string transaction,merchant,amount,currency,evidence_due_by,reason,cardName;
    Transactions(vector<string> &v){
        transaction = v[0];
        merchant = v[1];
        amount = v[2];
        currency = v[3];
        evidence_due_by = v[4];
        reason = v[5];
        cardName = v[6];
    }
};
vector<string> split(const string &s,const char delimiter){
    stringstream ss(s);
    vector<string> v;
    string word;
    while(getline(ss,word,delimiter)){
        v.push_back(word);
    }
    return v;
}
string extractCardName(string fileName){
    string cardName = "";
    for(char ch:fileName){
        if(isalpha(ch)){
            cardName+=ch;
        }else break;
    }
    return cardName;
}
bool isNotFileName(string s){
    // return s.ends_with(".csv");
    int n = s.size();
    return s.substr(n-4) != ".csv";
}
bool isValid(string s,string t){
    for(char ch:s){
        if(!isdigit(ch)) return false;
    }
    for(char ch:t){
        if(!isdigit(ch)) return false;
    }
    return true;
}
vector<Transactions> parseNetworkCharegebackInfo(vector<string> &rows,unordered_map<string,double> &mMCurr,unordered_map<string,int> &getIndex){
    vector<Transactions> data;
    for(int i=0;i<(int)rows.size();i++){
        //filenname contains .csv at end
        string fileName = rows[i];
        //cardName consist of alphabets at beginning of the filename
        string cardName = extractCardName(fileName);
        //next row tells about index of transaction,amt,curr.. and many more
        vector<string>  columnOrder = split(rows[i+1],',');
        //now we traverse through the rows until we found new file
        int j = 2;
        for(j;i+j<(int)rows.size()&&isNotFileName(rows[i+j]);j++ ){
            //now from i+2 onwards we have our data
            vector<string> tempData = split(rows[i+j],',');
            //each row has 6 columns
            vector<string> v(6);
            for(int k=0;k<6;k++){
                v[getIndex[columnOrder[k]]] = tempData[k];
            }
            if(mMCurr.find(v[getIndex["currency"]])==mMCurr.end()) continue;
            if(!isValid(v[getIndex["amount"]],v[getIndex["evidence_due_by"]])) continue;
            //now we have our data in structured format
            //now we add cardName to each Data
            v.push_back(cardName);
            Transactions transaction(v);
            data.push_back(transaction);
        }
        i = i+j-1;
    }
    return data;
}
string joinData(Transactions &parsedResult,unordered_map<string,double> &mMCurr){
    string data = "";
    data += parsedResult.cardName + parsedResult.transaction+",";
    data += parsedResult.merchant+",";
    string currency = parsedResult.currency;
    double amt = stod(parsedResult.amount)/mMCurr[currency];
    stringstream ss;
    ss<<fixed<<setprecision(2)<<static_cast<double>(amt);
    string combinedAmtCurrency = ss.str();
    combinedAmtCurrency+=currency;
    data+=combinedAmtCurrency+",";
    data+= parsedResult.evidence_due_by;
    return data;
}
int main(){
    // int n ;
    // cin>>n;
    vector<string> rows = {
        // File name header
        "VISA_20231016.csv",
        
        // Valid header
        "transaction,merchant,amount,currency,evidence_due_by,reason",
        
        // Valid cases
        "123456789,6789,37906,USD,1700000000,fraudulent",  // Valid
        "987654321,1234,500.50,USD,1700001234,withdrawn",  // Valid
        "555555555,9999,12750,JPY,1700005678,duplicate",   // Valid
        "111111111,8888,15000,SGD,1700001111,withdrawn",   // Valid

        // Violation cases
        "123456789,6789,200.75,USD,1700005678.5,fraudulent", // Evidence_due_by not a whole number (contains decimal)
        "123456789,6789,1500,EURA,1700005678,fraudulent",   // Currency not in map (EURA is invalid if mMcurr doesn't include EUR)

        // Withdrawn transactions
        "876543210,5678,10000,SGD,1700003333,withdrawn",   // Valid withdrawn
        "98765432,4321,200,USD,1700001234,withdrawn",      // Valid withdrawn

        // File name header for another batch of data
        "JCB_20231016.csv",

        // Valid header
        "merchant,currency,amount,transaction,evidence_due_by,reason",
        
        // Valid cases
        "6789,USD,120.45,123456789,1700000000,fraudulent",   // Valid
        "1234,USD,50050,987654321,1700001234,withdrawn",     // Valid
        "9999,JPY,100000,555555555,1700005678,duplicate",    // Valid

        // Violation cases
        "8888,USD,7525,111111111,1700001111.1,withdrawn",    // Evidence_due_by not a whole number (decimal number)
        "6789,USD,120.45,123456789,1700000000,fraudulent",   // Currency not in map (GBP is invalid if mMcurr doesn't include GBP)
        "8888,JPY,7525,111111111,withdrawn,duplicate"        // Evidence_due_by missing
    };
    //Case not considered Invalid Withdrawn but automatically withdrawn
    unordered_map<string,int> getIndex = {{"transaction",0},{"merchant",1},{"amount",2},{"currency",3},{"evidence_due_by",4},{"reason",5}};
    unordered_map<string,double> mMCurr = {{"EUR",100.00},{"USD",100.00},{"SGD",100.00},{"BRL",100.00},{"JPY",1.00},{"ISK",1.00},{"KRW",1.00}};
    vector<Transactions> parsedResults = parseNetworkCharegebackInfo(rows,mMCurr,getIndex);
    map<string,int> withdrawn;
    for(auto parsedResult:parsedResults){
        if(parsedResult.reason=="withdrawn"){
            string key = parsedResult.cardName;
            key+='-';
            key+=parsedResult.transaction;
            withdrawn[key] = 1;
        }
    }
    for(Transactions parsedResult:parsedResults){
        string key = parsedResult.cardName;
        key+='-';
        key+=parsedResult.transaction;
        if(withdrawn[key]) continue;
        string finalResult = joinData(parsedResult,mMCurr);
        cout<<finalResult<<"\n";
    }
 return 0;
}