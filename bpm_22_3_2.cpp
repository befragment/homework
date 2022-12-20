#include <iostream>

bool second(const double& x, const double& y) {
    if (std::abs(x) <= 2 && std::abs(y) <= 1 && x * x + y * y >= 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double x = 0.0;
    double y = 0.0;
    while (std::cin >> x >> y) {
        second(x, y) ? std::cout << "right\n" : std::cout << "wrong\n";
    }
    return 0;
}
