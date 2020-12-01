#include <vector>
#include <iostream>
#include <string>

int partOne(const std::vector<int>& v, const int& findMe) {
	for (const int& i : v) {
		for (const int& j : v) {
			if (i + j  == 2020) {
				return i * j;
			}
		}
	}
	return -1;
}

int partTwo(const std::vector<int>& v, const int& findMe) {
	for (const int& i : v) {
		for (const int& j : v) {
			for (const int& k : v) {
				if (i + j + k == 2020) {
					return i * j * k;
				}
			}
		}
	}
	return -1;
}

int main(int argc, char** argv) {

	std::vector<int> v;
	v.reserve(200);
	std::string s;
	while (std::getline(std::cin, s)) {
		v.emplace_back(stoi(s));
	}

	std::sort(v.begin(), v.end());

	std::cout
		<< partOne(v, 2020) << '\n'
		<< partTwo(v, 2020) << '\n';

	return 0;
}
