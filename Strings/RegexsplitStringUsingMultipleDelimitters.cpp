#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;
vector<string> split(const string& s, const string& delimiters) {
    regex re("[" + delimiters + "]+");  // Create a regex that matches one or more delimiters
    sregex_token_iterator it(s.begin(), s.end(), re, -1);  // -1 to split
    sregex_token_iterator end;

    vector<string> tokens;
    while (it != end) {
        if (!it->str().empty()) {
            tokens.push_back(*it);  // Only add non-empty tokens
        }
        ++it;
    }

    return tokens;
}

int main() {
    string text = "apple,banana; orange grape";
    string delimiters = ",; ";  // Delimiters are commas, semicolons, and spaces

    vector<string> result = split(text, delimiters);
    
    // Output the tokens
    for (const string& token : result) {
        cout << "'" << token << "'" << endl;
    }

    return 0;
}
