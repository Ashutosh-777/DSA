#include <bits/stdc++.h>
using namespace std;

// Function to trim leading and trailing spaces
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to remove quotes from a string (for parsing keys/values)
string removeQuotes(const string& str) {
    if (str.front() == '"' && str.back() == '"') {
        return str.substr(1, str.size() - 2);
    }
    return str;
}

// Function to parse an array
vector<string> parseArray(const string& arrayString) {
    vector<string> result;
    stringstream ss(arrayString);
    string item;
    
    // Remove brackets
    string content = arrayString.substr(1, arrayString.size() - 2);
    stringstream ssArray(content);
    
    while (getline(ssArray, item, ',')) {
        result.push_back(trim(removeQuotes(item)));
    }
    return result;
}

// Recursive JSON-like parser for key-value pairs and nested objects/arrays
map<string, any> parseJson(const string& jsonString) {
    map<string, any> jsonMap;
    stringstream ss(jsonString);
    string line;

    while (getline(ss, line, ',')) {
        size_t colon = line.find(':');
        if (colon != string::npos) {
            string key = trim(line.substr(0, colon));
            string value = trim(line.substr(colon + 1));
            key = removeQuotes(key);

            // Check if value is another JSON object or array
            if (value.front() == '{' && value.back() == '}') {
                // Parse nested object
                jsonMap[key] = parseJson(value.substr(1, value.size() - 2));
            } else if (value.front() == '[' && value.back() == ']') {
                // Parse array
                jsonMap[key] = parseArray(value);
            } else {
                // Parse regular value
                jsonMap[key] = removeQuotes(value);
            }
        }
    }
    return jsonMap;
}

// Helper function to print the parsed JSON
void printJson(const map<string, any>& jsonMap, int indent = 0) {
    for (const auto& kv : jsonMap) {
        for (int i = 0; i < indent; ++i) cout << "  ";
        cout << kv.first << ": ";

        // Check if the value is another object or array
        if (kv.second.type() == typeid(map<string, any>)) {
            cout << "{\n";
            printJson(any_cast<map<string, any>>(kv.second), indent + 1);
            for (int i = 0; i < indent; ++i) cout << "  ";
            cout << "}\n";
        } else if (kv.second.type() == typeid(vector<string>)) {
            cout << "[ ";
            for (const auto& val : any_cast<vector<string>>(kv.second)) {
                cout << val << " ";
            }
            cout << "]\n";
        } else {
            cout << any_cast<string>(kv.second) << endl;
        }
    }
}

int main() {
    // Example complex JSON string
    string jsonString = R"({
        "name": "John Doe",
        "age": "30",
        "is_student": "false",
        "skills": ["C++", "Python", "JavaScript"],
        "address": {
            "street": "123 Main St",
            "city": "New York",
            "zip": "10001"
        }
    })";

    // Remove outer braces for simpler parsing
    jsonString.erase(remove(jsonString.begin(), jsonString.end(), '{'), jsonString.end());
    jsonString.erase(remove(jsonString.begin(), jsonString.end(), '}'), jsonString.end());

    // Parse the JSON string
    map<string, any> parsedJson = parseJson(jsonString);

    // Output the parsed values in a readable format
    printJson(parsedJson);

    return 0;
}
