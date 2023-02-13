#ifndef RATIONALNUMBERS_RATIONAL_HPP
#define RATIONALNUMBERS_RATIONAL_HPP
#pragma once

#include <iostream>
#include <numeric>

class Rational {

private:

    int32_t num {0};
    int32_t denum {0};
    static const char frac_sign {'/'};

    Rational frac_reduction() {
        auto gcd = std::gcd(num, denum);
        num /= gcd; denum /= gcd;
        return *this;
    }

public:

    Rational(int32_t num_, int32_t denum_) {
        if (denum <= 0) {
            throw std::invalid_argument("expected positive denumerator");
        }
        num = num_;
        denum = std::abs(denum_);
    };
    
    explicit Rational(int32_t num_) {
        num = num_;
        denum = 1;
    }

    ~Rational() = default;

    // ============================== plus operators ============================== //
    inline Rational operator+(const Rational& frac) const {
        int32_t new_numerator = num * frac.denum + denum * frac.num;
        int32_t common_denum = denum * frac.denum;
        Rational res = { new_numerator, common_denum };
        return res.frac_reduction();
    }

    inline Rational operator+(const int32_t& arg) const {
        Rational arg2frac = { denum * arg, denum };
        Rational res = arg2frac + *this;
        return res.frac_reduction();
    }

    inline Rational operator+=(const Rational& frac) {
        num = num * frac.denum + denum * frac.num;
        denum = denum * frac.denum;
        this->frac_reduction();
        return *this;
    }

    inline Rational operator+=(const int32_t& arg) {
        Rational frac_arg = { denum * arg, denum };
        num = frac_arg.num * denum + frac_arg.denum * num;
        denum *= frac_arg.denum;
        this->frac_reduction();
        return *this;
    }

    inline Rational operator++() {
        num += denum;
        return *this;
    }
    // ============================== plus operators ============================== //

    // ============================== minus operators ============================== //
    inline Rational operator-() const {
        return {-num, denum};
    }

    inline Rational operator-(const Rational& frac) const {
        int32_t new_numerator = num * frac.denum - denum * frac.num;
        int32_t common_denum = denum * frac.denum;
        Rational res = {new_numerator, common_denum};
        return res.frac_reduction();
    }

    inline Rational operator-(const int32_t& arg) const {
        Rational arg2frac = { denum, denum };
        Rational res = *this - arg2frac;
        return res.frac_reduction();
    }

    inline Rational operator-=(const Rational& frac) {
        num = num * frac.denum - denum * frac.num;
        denum *= frac.denum;
        this->frac_reduction();
        return *this;
    }

    inline Rational operator-=(const int32_t& arg) {
        Rational frac_arg = { denum * arg, denum };
        num = num * frac_arg.denum - denum * frac_arg.num;
        denum *= frac_arg.denum;
        this->frac_reduction();
        return *this;
    }

    inline Rational operator--() {
        num -= denum;
        return *this;
    }
    // ============================== minus operators ============================== //

    // ============================== multi operators ============================== //
    inline Rational operator*(const Rational& frac) const {
        Rational res = {num * frac.num, denum * frac.denum};
        return res.frac_reduction();
    }

    inline Rational operator*(const int32_t& arg) const {
        Rational res = {num * arg, denum};
        return res.frac_reduction();
    }

    inline Rational operator*=(const Rational& frac) {
        num *= frac.num;
        denum *= frac.denum;
        this->frac_reduction();
        return *this;
    }

    inline Rational operator*=(const int32_t& arg) {
        num *= arg;
        this->frac_reduction();
        return *this;
    }

    // ============================== multi operators ============================== //

    // ============================== div operators ============================== //
    inline Rational operator/(const Rational& frac) const {
        Rational res = {num * frac.denum, denum * frac.num};
        return res.frac_reduction();
    }

    inline Rational operator/(const int32_t& arg) const {
        Rational res = {num, denum * arg};
        return res.frac_reduction();
    }

    inline Rational operator/=(const Rational& frac) {
        num *= frac.denum;
        denum *= frac.num;
        this->frac_reduction();
        return *this;
    }

    inline Rational operator/=(const int32_t& arg) {
        denum *= arg;
        this->frac_reduction();
        return *this;
    }
    // ============================== div operators ============================== //

    // ============================== bool operators ============================== //

    inline bool operator==(Rational& frac) const {
        Rational first = {num, denum};
        frac.frac_reduction();
        first.frac_reduction();
        Rational res = first - frac;
        return res.num == 0;
    }

    inline bool operator!=(Rational& frac) const {
        return !(*this == frac);
    }

    inline bool operator>(Rational& frac) const {
        Rational diff = *this - frac;
        return diff.num > 0;
    }

    inline bool operator>=(Rational& frac) const {
        return (*this > frac || *this == frac);
    }

    inline bool operator<(Rational& frac) const {
        return !(*this > frac) && !(*this == frac);
    }

    inline bool operator<=(Rational& frac) const {
        return !(*this > frac) & (*this == frac);
    }

    // ============================== bool operators ============================== //

    // ============================== bit operators ============================== //

    friend std::ostream& operator<<(std::ostream& ostream, Rational& frac);

    friend std::istream& operator>>(std::istream& istream, Rational& frac);

    // ============================== bit operators ============================== //

};

#endif
