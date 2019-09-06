#include <iostream>
#include <limits.h>
#include <string>
#include <algorithm>
#include <cstdlib>

int reverse_one(int x) {
    
    // Get initial int setup as array of chars
    std::string start_num = std::to_string(x);
    char const* pchar = start_num.c_str();
    std::string rev_num = "";

    int num_length = start_num.length();
    // Reverse the int
    for (int x = 0; x < num_length; ++x) {
        char current = pchar[num_length-x-1];
        rev_num += current;
    }

    // Remove any leading zeros
    rev_num.erase(0, std::min(rev_num.find_first_not_of('0'), rev_num.size()-1));

    // Convert string to int, and check for over/underflow
    try
    {
        int final_int = std::stoi(rev_num);
        // Ensure proper sign is maintained
        if (x != 0) {
            int sign = x/abs(x);
            return sign * final_int; 
        }
        return final_int;

    }
    catch(std::out_of_range const &e)
    {
        return 0;
    }
}


int reverse_two(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}


int main() {
    int start = -1999999999;
    int finish = reverse_two(start);
    std::cout << finish << std::endl;
}