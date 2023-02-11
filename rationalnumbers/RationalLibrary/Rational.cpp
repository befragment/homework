#include <iostream>
#include "Rational.hpp"

std::ostream& operator<<(std::ostream& ostream, Rational& frac) {
    if (frac.num % frac.denum != 0 && frac.num != 0) {
        return ostream << frac.num << Rational::frac_sign << frac.denum;
    } else {
        return ostream << frac.num;
    }
}

std::istream& operator>>(std::istream& istream, Rational& frac) {
    char frac_sign = 0;
    int32_t numerator = 0;
    int32_t denumerator = 0;
    istream >> numerator >> frac_sign >> denumerator;

    if (istream.good()) {
        if (frac_sign == Rational::frac_sign) {
            frac.num = numerator;
            frac.denum = denumerator;
        } else {
            istream.setstate(std::ios_base::failbit);
        }
    }
    return istream;
}
