#include <iostream>
#include <string>

std::string caesar(const std::string& text, int shift) {
	while(shift < 0) shift += 26;
	shift = shift % 26;
	std::string res = "";
	for(auto i = text.begin(); i != text.end(); i++)
		if(*i >= 'A' && *i <= 'Z') res += 'A' + (*i - 'A' + shift) % 26;
		else if (*i >= 'a' && *i <= 'z') res += 'a' + (*i - 'a' + shift) % 26;
		else res += *i;
	return res;
}

int main() {
	std::cout << caesar("Hello, World!", 3) << std::endl;
	std::cout << caesar("Khoor, Zruog!", -3) << std::endl;
}
