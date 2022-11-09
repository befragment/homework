#include<iostream>
 
int main(){
    
    int loops, a, b, c, d, k;
    std::cin >> loops;
    for (int i = 0; i < loops; i += 1){
        
        std::cin >> a >> b >> c >> d >> k;
        
        int x = (a - 1) / c + 1;
        int y = (b - 1) / d + 1;
        
        if(x + y > k){
            std::cout << -1 << std::endl;
        } else {
            std::cout << x << ' ' << y<< std::endl;
            
        }
    }
}
