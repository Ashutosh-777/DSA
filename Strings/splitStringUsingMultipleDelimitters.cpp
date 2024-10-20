#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> split(const string& s, const string& delimiters) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = s.find_first_of(delimiters);

    while (end != string::npos) {
        if (end != start) {  //in order to  Avoid adding empty tokens (when delimiters are next to each other)
            tokens.push_back(s.substr(start, end - start));
        }
        start = end + 1;
        end = s.find_first_of(delimiters, start);
    }

    // Add the last token if any
    if (start < s.length()) {
        tokens.push_back(s.substr(start));
    }

    return tokens;
}

int main() {
    string text = "apple,banana;,orange,axy; grape hello\nahisih";
    string delimiters = ",; \n";  // Split on commas, semicolons, or spaces
    
    vector<string> result = split(text, delimiters);
    
    // Output the tokens
    for (const string& token : result) {
        cout << "'" << token << "'" << endl;
    }

    return 0;
}
