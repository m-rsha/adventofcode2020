#include "mhw.h"
#include <algorithm>

auto summer(const std::vector<int>& v) {
    int sum = 0;
    for (const auto i : v) {
        sum += i;
    }
    return sum;
}

auto answer(std::vector<int>& v) {
    struct S { int a, b; };
    std::sort(v.begin(), v.end());
    return S{ v[0], v[v.size() - 1]};
}

int main(int argc, char** argv) {
    
    if (argc == 1) { exit(1); }

    else {
        auto todaysInput = mhw::getFile(argv[1]);
        // find a CONTIGUOUS SET of AT LEAST TWO NUMBERS
        // which sum to the invalid number from part 1
        // 15353384
        std::vector<int> prev{};
//        const int findMe = 127;
        const int findMe = 15353384;
        for (auto& line : todaysInput) {
            int n = std::stoi(line);
            prev.insert(prev.begin(), n);
            while (summer(prev) > findMe) { prev.pop_back(); }
            if (summer(prev) == findMe) {
                auto [one, two] = answer(prev);
                std::cout << "Answer: " << one + two << '\n';
                exit(0);
            }
        }
    }
    return 0;
}
