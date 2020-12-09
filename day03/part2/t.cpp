#include <iostream>
#include "mhw.h"

struct Position {
    int x = 0;
    int y = 0;
    int treesHit = 0;
    char on = '.';
    int length = 0;

    void move(const int right, const int down) {
        x += right;
        y += down;
        if (x > length - 1) { x -= length; }
    }
};

bool onTree(const char c) {
    return c == '#';
}

auto goSled(
    Position p,
    std::vector<std::string>& input,
    const int right,
    const int down
    ) {
    int max = input.size();
    std::cout << "Total lines: " << max
        << "\nLine length: " << p.length << '\n';
    for (int i = 0; i < max;) {
        auto line = input[i];
        p.on = line[p.x];
        if (p.on == '#') {
            std::cout << "Tree hit\n";
            ++p.treesHit;
        }
        line.insert(p.x + 1, 1, 'X');
        std::cout << line << "  " << " On: " << p.on << '\n';
        p.move(right, down);
        i += down;
    }
    return p.treesHit;
}

int main(int argc, char** argv) {
    auto todaysInput = mhw::getFile(argv[1]);
    Position p;
    p.length = todaysInput[0].size();
    std::vector<int> rights{1, 3, 5, 7, 1};
    std::vector<int> downs{1, 1, 1, 1, 2};
    std::vector<int> answers;
    for (int i = 0; i < rights.size(); ++i) {
        answers.push_back(goSled(p, todaysInput, rights[i], downs[i]));
    }
    long long int total = 1;
    for (const auto& i : answers) {
        total *= i;
    }
    std::cout << '\n' << total << '\n';
    
    return 0;
}
