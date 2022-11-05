#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
 
int main(){
    int t = 0;
    std::cin >> t;
    
    std::string str;
    std::cin >> str;
    
    std::vector<int>pos_x;
    std::vector<int>pos_y;
    int res = 0;
    
    int x_counter = 0;
    int y_counter = 0;
    for (int j = 0; j < str.size(); ++j){
        if (str[j] == 'U'){
            ++y_counter;
            pos_y.push_back(y_counter);
            pos_x.push_back(x_counter);
        } else if (str[j] == 'R'){
            ++x_counter;
            pos_x.push_back(x_counter);
            pos_y.push_back(y_counter);
        }
    }
    
    for (int j = 1; j < str.size() - 1; j++){
        if ((pos_x[j] == pos_y[j]) &&
            ((pos_x[j - 1] == pos_x[j + 1] - 2) || (pos_y[j - 1] == pos_y[j + 1] - 2))){
            ++res;
        }
    }
    std::cout << res << std::endl;
    
    /*
    for (int j = 0; j < pos_x.size(); ++j){
        std::cout << pos_x[j] << ' ';
    }
    std::cout << std::endl;
    
    for (int j = 0; j < pos_x.size(); ++j){
        std::cout << pos_y[j] << ' ';
    }
    
    std::cout << std::endl;
    */
    
    return 0;
}
