#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <algorithm>


int main() {
    std::vector<int> vec = {3, -1, 7, 0, 3, 10, 2, 3, 3};
    int num = 0;
    std::unordered_set<int> mySet;

    auto f = [&] ()
    {
        for (auto i : vec)
        {
            num += mySet.count(i);
            mySet.insert(i);

            if (num > 1)
            {
                vec.erase(std::remove(vec.begin(), vec.end(), i), vec.end());
            }
        }

        std::cout << "Number of repeating elements: "<< num << std::endl;

        return std::make_unique<std::vector<int>>(vec);
    };

    auto newVec = f();
    for (auto i : *newVec)
    {
        std::cout << i << " ";
    }
}
