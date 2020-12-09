#include <iostream>
#include "mhw.h"

struct Position {
    int x = 0;
    int y = 0;
    int treesHit = 0;
    char on = '.';
};

auto move(Position& p, const int length) {
    if (p.on == '#') { ++p.treesHit; }
    p.x += 3;
//    ++p.y; 
    if (p.x > length - 1) { p.x -= length; }
}

bool onTree(const char c) {
    return c == '#';
}

int main(int argc, char** argv) {
    auto todaysInput = mhw::getFile(argv[1]);
    Position p;
    
    for (int i = 0; auto& line : todaysInput) {
        p.on = line[p.x];
        std::cout << line << "  "
            << p.x  << " On: " << line[p.x]
            << '\n';
        move(p, line.size());
        ++i;
    }
    std::cout << '\n' << p.treesHit << '\n';
    return 0;
}
