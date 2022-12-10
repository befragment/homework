#include <iostream>
#include "VectorsLib/VectorsLib.hpp"


//using namespace crd;
//using namespace dec;
//using namespace pol;

int main() {
    crd::dec::RDec2d vec1 = {1.0, 2.0};
    crd::dec::RDec2d vec2 = {2.0, 3.0};
    crd::dec::RDec2d vec3 = {3.0, 4.0};
    crd::dec::RDec2d vec4 = {1.0, 1.0};
    crd::dec::RDec2d vec5 = -vec4;
    crd::dec::RDec2d vec6 = {1.1, 1.1};
    crd::dec::RDec2d vec7 = {1.0, 1.0};
    crd::dec::RDec2d vec8 = -vec5;
    crd::dec::RDec2d vec9 = {0.0, 1.0};

    double num = 2.0;

    std::cout << "vec1 + vec2 = " << vec1 + vec2 << std::endl;
    std::cout << "vec1 * vec2 = " << crd::dec::Dot(vec1, vec2) << std::endl;
    std::cout << "vec3 length is: " << crd::dec::Norm(vec3) << std::endl;
    std::cout << num << " * vec3 = " << num * vec3 << std::endl;
    std::cout << "vec4: " << vec4 << std::endl;
    std::cout << "vec5: " << vec5 << std::endl;

    vec1 == vec6 ? std::cout << "yes" << std::endl : std::cout << "no" << std::endl;
    vec1 != vec6 ? std::cout << "yes" << std::endl : std::cout << "no" << std::endl;
    vec1 != vec7 ? std::cout << "yes" << std::endl : std::cout << "no" << std::endl;


    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec1 + vec2 << std::endl;
    std::cout << vec1 - vec2 << std::endl;
    std::cout << crd::dec::Norm(vec3) << std::endl;
    std::cout << crd::dec::Dot(vec2, vec3) << std::endl;

    crd::pol::RPol2d pol1 = {1.0, 1.0};
    crd::pol::RPol2d pol2 = {1.1, 1.0};

    pol1 == pol2 ? std::cout << "yes" << std::endl : std::cout << "no" << std::endl;

    std::cout << vec8 << std::endl;

    std::cout << "vec9 to pol: " << crd::dec2pol(vec9) << std::endl;

    return 0;
}