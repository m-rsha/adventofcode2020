#include "mhw.h"
#include <set>
#include <queue>

bool isValid(const std::vector<int>& pre, const int n) {
    bool res = false;
    for (const int i : pre) {
        for (const int j : pre) {
            if (i + j == n) {
                return true;
            }
        }
    }
    return res;
}

int main(int argc, char** argv) {
    
    if (argc == 1) { exit(1); }

    else {
        auto todaysInput = mhw::getFile(argv[1]);
        const int preamble = 25;
        std::vector<int> prev{};
        for (int lineNum = 0; auto& line : todaysInput) {
            ++lineNum;
            int n = std::stoi(line);
            prev.insert(prev.begin(), n);
            if (lineNum > preamble) {
                if (!isValid(prev, n)) {
                    std::cout << "Answer: " << line << '\n';
                    exit(0);
                }
                prev.pop_back();
            }
        }
    }
    return 0;
}
