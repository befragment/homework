#include "VectorsLib.hpp"
#include <iostream>
#include <cmath>


std::ostream& crd::dec::operator<<(std::ostream& ostrm, const crd::dec::RDec2d& vec) {
    return ostrm << "(" << vec.x << ", " << vec.y << ")";
}

std::ostream& crd::pol::operator<<(std::ostream& ostrm, const crd::pol::RPol2d& vec) {
    return ostrm << "(" << vec.r << ", " << vec.phi << ")";
}

crd::dec::RDec2d crd::pol2dec(const crd::pol::RPol2d& arg) {
    crd::dec::RDec2d dec = {0.0, 0.0};
    dec.x = arg.r * std::cos(arg.phi);
    dec.y = arg.r * std::sin(arg.phi);
    return { dec };
}

crd::pol::RPol2d crd::dec2pol(const crd::dec::RDec2d& arg) {
    crd::pol::RPol2d pol = {0.0, 0.0};
    pol.r = std::sqrt(arg.x * arg.x + arg.y * arg.y);
    pol.phi = std::atan(arg.y / arg.x);
    return { pol };
}

double crd::dec::Norm(const crd::dec::RDec2d& arg) {
    return arg.x * arg.x + arg.y * arg.y;
}

double crd::dec::Dot(const crd::dec::RDec2d& lhs, const crd::dec::RDec2d& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}