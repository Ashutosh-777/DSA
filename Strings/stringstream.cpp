// Example 1: Converting between data types

// #include <iostream>
// #include <sstream>
// #include <string>

// int main() {
//     std::string text = "123";
//     int number;

//     // Convert string to integer
//     std::stringstream ss(text);
//     ss >> number;

//     std::cout << "String to int: " << number << std::endl;

//     // Convert integer to string
//     int num = 456;
//     std::stringstream ss2;
//     ss2 << num;
//     std::string strNum = ss2.str();

//     std::cout << "Int to string: " << strNum << std::endl;

//     return 0;
// }


// Example 2: Parsing Space-Separated Strings

// #include <iostream>
// #include <sstream>
// #include <string>

// int main() {
//     std::string line = "12 45 78";
//     std::stringstream ss(line);
//     int num;

//     while (ss >> num) {
//         std::cout << "Extracted number: " << num << std::endl;
//     }

//     return 0;
// }

// Example 3: Concatenating Different Data Types into a String

// #include <iostream>
// #include <sstream>
// #include <string>

// int main() {
//     int a = 10;
//     float b = 20.5;
//     std::string text = "hello";

//     std::stringstream ss;
//     ss << "a = " << a << ", b = " << b << ", text = " << text;

//     std::string result = ss.str();
//     std::cout << result << std::endl;

//     return 0;
// }

// Example 4: Reading Comma-Separated Values (CSV)

// #include <iostream>
// #include <sstream>
// #include <string>

// int main() {
//     std::string line = "apple,banana,orange";
//     std::stringstream ss(line);
//     std::string word;

//     while (std::getline(ss, word, ',')) {
//         std::cout << "Extracted word: " << word << std::endl;
//     }

//     return 0;
// }

// Example 5: Using istringstream and ostringstream
// #include <iostream>
// #include <sstream>
// #include <string>

// int main() {
//     std::string data = "42 3.14 hello";
//     std::istringstream iss(data);

//     int i;
//     double d;
//     std::string s;

//     iss >> i >> d >> s;

//     std::cout << "int: " << i << ", double: " << d << ", string: " << s << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <sstream>
// #include <string>

// int main() {
//     std::string data = "42 3.14 hello";
//     std::istringstream iss(data);

//     int i;
//     double d;
//     std::string s;

//     iss >> i >> d >> s;

//     std::cout << "int: " << i << ", double: " << d << ", string: " << s << std::endl;
//     return 0;
// }
