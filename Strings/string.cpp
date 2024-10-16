#include <bits/stdc++.h>
using namespace std;
string ltrim(const string& s) {
    return s.substr(s.find_first_not_of(" \t\n\r"));
}
string rtrim(const string& s) {
    return s.substr(0, s.find_last_not_of(" \t\n\r") + 1);
}
string trim(const string& s) {
    return ltrim(rtrim(s));
}
vector<string> split(string str, char delim){
  vector<string> splittedString;
  string token;
  istringstream ss(str);
  while(getline(ss,token,delim)){
    splittedString.push_back(token);
  }
  return splittedString;
}
string join(const vector<string>& vec, const string& delim) {
    string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i != vec.size() - 1) result += delim;
    }
    return result;
}
void search(string str,string s){
    string text = "hello world";
    //size_t index = text.rfind("world");
    size_t index = text.find("world");
    cout<<index<<endl;
}
void substring(string str,int fromIndex,int length){
  cout<<str.substr(fromIndex,length);
}
//replace 

// int main() {
//     string text = "I love apples";
//     //replace(index,length,newText)
//     text.replace(9, 6, "bananas");
//     cout<<text<<endl;
//     // text: "I love bananas"
// }

//starts_with or ends with
// int main() {
//     string text = "hello world";
//     bool starts = text.starts_with("hello");  // true
//     bool ends = text.ends_with("world");      // true
// }

//to UPPERCASE or to lowercase
// string to_upper(const string& s) {
//     string result = s;
//     for (char& c : result) c = toupper(c);
//     return result;
// }

//isalpha() isdigit() isalnum()
// int main() {
//     std::string text = "12345";
//     bool result = std::all_of(text.begin(), text.end(), ::isdigit);
//     // result: true
// }
int main() {
    std::string name = "Alice";
    int age = 25;
    std::stringstream ss;
    ss << "Name: " << name << ", Age: " << age;
    std::string result = ss.str();
    cout<<result<<endl;
    // result: "Name: Alice, Age: 25"
}