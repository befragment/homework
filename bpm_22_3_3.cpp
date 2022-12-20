#include <iostream>
#include <string>

bool third(std::string str) {
    for (int i = 0; i < str.size() - 2; i++) {
        if (str[i] != str[i + 1] && str[i + 1] != str[i + 2]
        && str[i] != '.' && str[i + 1] != '.' && str[i + 2] != '.') {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    std::string str;
    std::cin >> str;
    third(str) ? std::cout << "yes\n" : std::cout << "no\n";
    return 0;
}
