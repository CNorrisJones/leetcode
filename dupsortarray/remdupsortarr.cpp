#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int value = nums.front();
    for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
        if (value == *iter) {
            nums.erase(iter);
            --iter;
        }
        else {
            value = *iter;
        }
    }
    return nums.size();
}


int main() {
    std::vector<int> vec = {0,0,1,1,1,2,2,3,3,4};

    int len = removeDuplicates(vec);
    std::cout << len << std::endl;

    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    return 0;
}