//
// Created by kurchin_iu on 06.05.2026.
//

#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

int main () {
    std::vector<int> list = {1, 2, 3, 4, 5, 3, 1};
    auto filterUniqNum {[](const std::vector<int>&InitList) {
        auto result = std::make_unique<std::vector<int>>();
        std::pmr::unordered_set<int> check;

        for (auto num: InitList) {
            if (check.find(num) == check.end()) {
                check.insert(num);
                result->push_back(num);
            }
        }
        return result;
    }};

    auto uniq_list_ptr = filterUniqNum(list);

    for (auto n: *uniq_list_ptr) {
        std::cout << n << " ";
    }

    return 0;
}