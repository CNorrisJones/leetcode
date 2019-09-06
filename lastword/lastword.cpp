#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

int lengthofLastWord(std::string s) {

    std::istringstream iss(s);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    if (results.size() == 0) {
        return 0;
    }

    std::string ret_string = results[results.size()-1];
    return ret_string.size();
}

int main() {
    std::string test_string = "  t ";

    int test = lengthofLastWord(test_string);
    std::cout << test << std::endl;

    return 0;
}