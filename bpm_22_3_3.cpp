#include <iostream>
#include <string>

bool third(std::string& str) {
    for (int i = 0; i < str.size() - 2; i++) {
        return (str[i] != str[i + 1] && str[i + 1] != str[i + 2]
                && str[i] != '.' && str[i + 1] != '.' && str[i + 2] != '.');
    }
}

int main() {
    std::string str;
    std::cin >> str;
    third(str) ? std::cout << "yes\n" : std::cout << "no\n";
    return 0;
}
