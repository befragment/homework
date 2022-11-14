#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
int main(){
    int amount = 0;
    std::cin >> amount;
    std::vector<int>rests_vec;
    
    for (int i = 0; i < amount; ++i){
        int k = 0;
        std::cin >> k;
        rests_vec.push_back(k);
    }
    
    std::set<int>rests_set;
    
    for (int i = 0; i < amount; ++i){
        rests_set.insert(rests_vec[i]);
    }
    
    for (int i = amount - 1; !((rests_set).size() == 1); --i){
        rests_set.erase(rests_vec[i]);
    }
    
    for (auto i: rests_set){
        std::cout << i << std::endl;
    }
    
    return 0;
}
