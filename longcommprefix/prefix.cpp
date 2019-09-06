#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    // Eliminate edge cases, one string or no string
    if (strs.size() == 0) {
        return "";
    } else if (strs.size() == 1) {
        return strs[0];
    }

    std::string result = strs[0];
    std::string compare;
    int iter = 1;

    while (iter < strs.size()) {
        compare = strs[iter];
        // Ensure size of both strings is equal
        result.size() > compare.size() ? result = result.substr(0,compare.size()): compare = compare.substr(0,result.size());

        while (result != compare) {
            result.pop_back();
            compare.pop_back();
            if (result == "") {
                return "";
            }
        }
        ++iter;
    }
    return result;
}

int main() {
    std::vector<std::string> strs = {};

    std::string result = longestCommonPrefix(strs);

    std::cout << result << std::endl;

    // std::string test = "flow";
    // std::string test2 = "flight";

    // test.size() > test2.size() ? test = test.substr(0,test2.size()): test2 = test2.substr(0, test.size());
    
    // std::cout << test.size() << " " << test2.size() << " " << test.substr(0,test2.size()) << std::endl;
    // std::cout << test << " " << test2 << std::endl;
    
    return 0;
}