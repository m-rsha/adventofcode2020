#include <iostream>
#include <vector>
#include <algorithm>
#include "mhw.h"

struct Range {
    int min = 0;
    int max = 127;
    int diff = 64;
    
    auto update() { diff >>= 1; }
    auto f() { max -= diff; update(); }
    auto b() { min += diff; update(); }
    auto row() { return min; }

    int lmin = 0;
    int lmax = 7;
    int ldiff = 4;

    auto lupdate() { ldiff /= 2; }
    auto l() { lmax -= ldiff; lupdate(); }
    auto r() { lmin += ldiff; lupdate(); }
    auto column() { return lmin; }
    
    auto seatID() { return (row() * 8) + column(); }
    auto passCheck() {}
};

namespace color {
    auto pre(const std::string& s) { return "\033[" + s + "m"; }
    std::string suf = "\033[0m";
    auto paint(const std::string& n, const std::string& s) {
        return pre(n) + s + suf;
    }
    auto cyan(const std::string& s) { return paint("36", s); }
    auto white(const std::string& s) { return paint("37", s); }
    auto yellow(const std::string& s) { return paint("33", s); }
}

std::ostream& operator<<(std::ostream& os, Range& r) {
    os << color::yellow("Row: ") << r.row()
        << color::yellow(" Column: ") << r.column()
        << color::yellow(" Seat ID: ") << r.seatID();
    return os;
}

auto highestSeatID(std::vector<int>& v) {
    std::sort(v.begin(), v.end(), [](const int a, const int b){
        return a > b;
    });
    return color::yellow("Highest seat ID: ") + std::to_string(v[0]);
}

auto getMySeatID(const std::vector<int>& v) {
    int next = 0;
    for (int i = 0; i < v.size(); i++) {
        ++next;
        if ((v[i] - 1) != v[next]) {
            return v[i] - 1;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    auto todaysInput = mhw::getFile(argv[1]);
    std::vector<int> seatIDs{};
    seatIDs.reserve(todaysInput.size());
    for (const auto& line : todaysInput) {
        Range r;
        for (const auto c : line) {
            if (c == 'F') { r.f(); }
            if (c == 'B') { r.b(); }
            if (c == 'L') { r.l(); }
            if (c == 'R') { r.r(); }
        }
        seatIDs.emplace_back(r.seatID());
//        std::cout << r << '\n';
    }
    highestSeatID(seatIDs);
    std::cout << color::yellow("\nMy seat ID: ")
        << getMySeatID(seatIDs) << '\n';
    return 0;
}
