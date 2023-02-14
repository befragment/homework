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


Rational abs(Rational& frac) {
    frac.num = std::abs(frac.num);
    frac.denum = std::abs(frac.denum);
    return {frac.num, frac.denum};
}

Rational reversed_fraction(Rational& arg) {
    Rational new_arg(1, 1);
    if (arg.num > 0) {
        new_arg.num = arg.denum;
        new_arg.denum = arg.num;
    } else if (arg.num == 0) {
        new_arg = {0, 1};
    } else {
        new_arg.num = -arg.denum;
        new_arg.denum = std::abs(arg.num);
    }
    return new_arg;
}

Rational pow(Rational& frac, int32_t& exp) {
    Rational new_frac(1, 1);
    if (frac.num == 0 && exp == 0) {
        throw std::invalid_argument("mathematical uncertainty: 0^0");
    }
    if (exp >= 0) {
        for (int i = 0; i < exp; i++) {
            new_frac *= frac;
        }
    } else {
        frac = reversed_fraction(frac);
        for (int i = 0; i < std::abs(exp); i++) {
            new_frac *= frac;
        }
    }
    return new_frac.frac_reduction();
}
