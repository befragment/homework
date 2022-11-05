#include #iostream

int main(){
    int t;
    std::cin >> t;
    while(t--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << ((a + b + c + d + 2)/3) << std::endl;
    }
    return 0;
}
