#include<iostream>
 
int main(){
    int loops;
    std::cin >> loops;
    for (int i = 0; i < loops; i += 1)
    {
        int n, m, sx, sy, d;
        std::cin >> n >> m >> sx >> sy >> d;
        
        if (std::min(sx - 1, m - sy) <= d and std::min(n - sx, sy - 1) <= d)
        {
            std::cout << "-1" << std::endl;
        }
        else
        {
            std::cout << std::abs(n - 1) + std::abs(m - 1) << std::endl;
        }
    }
    return 0;
}
