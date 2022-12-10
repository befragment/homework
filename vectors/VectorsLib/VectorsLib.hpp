#ifndef VECTORS_VECTORSLIB_HPP
#define VECTORS_VECTORSLIB_HPP
#pragma once

#include <iosfwd>
#include <cmath>

namespace crd {

    namespace dec {

        // Descartes coordinates functions and operators //

        struct RDec2d {
            double x = 0.0;
            double y = 0.0;
        };

        inline bool operator==(const RDec2d& lhs, const RDec2d& rhs) {
            double delta_req = pow(10, -10);
            double delta1 = std::abs(1 - lhs.x / rhs.x);
            double delta2 = std::abs(1 - lhs.y / rhs.y);
            return (delta1 < delta_req) & (delta2 < delta_req);
        }

        inline bool operator!=(const RDec2d& lhs, const RDec2d& rhs) {
            double delta_req = pow(10, -10);
            double delta1 = std::abs(1 - lhs.x / rhs.x);
            double delta2 = std::abs(1 - lhs.y / rhs.y);
            return (delta1 > delta_req) & (delta2 > delta_req);
        }

        inline RDec2d operator+(const RDec2d& lhs, const RDec2d& rhs) {
            return {lhs.x + rhs.x, lhs.y + rhs.y};
        }

        inline RDec2d operator-(const RDec2d& lhs, const RDec2d& rhs) {
            return {lhs.x - rhs.x, lhs.y - rhs.y};
        }

        inline RDec2d operator-(const RDec2d& arg) {
            return {-arg.x, -arg.y};
        }

        inline RDec2d operator*(const double& num, const RDec2d& vec) {
            return {num * vec.x, num * vec.y};
        }

        std::ostream &operator<<(std::ostream& ostrm, const RDec2d& vec);

        RDec2d operator-(const RDec2d& lhs, const RDec2d& rhs);

        RDec2d operator-(const RDec2d &arg);

        RDec2d operator*(const double& num, const RDec2d& vec);

        double Norm(const RDec2d& arg);

        double Dot(const RDec2d& lhs, const RDec2d& rhs);
    }

    namespace pol {

        // Polar coordinates functions and operators //

        struct RPol2d {
            double r = 0.0;
            double phi = 0.0;
        };

        inline bool operator==(const RPol2d& lhs, const RPol2d& rhs) {
            double delta = pow(10, -10);
            double delta1 = std::abs(1 - lhs.r / rhs.r);
            double delta2 = std::abs(1 - lhs.r / rhs.r);
            return (delta1 < delta) & (delta2 < delta);
        }

        inline bool operator!=(const RPol2d& lhs, const RPol2d& rhs) {
            double delta = pow(10, -10);
            double delta1 = std::abs(1 - lhs.r / rhs.r);
            double delta2 = std::abs(1 - lhs.r / rhs.r);
            return (delta1 > delta) & (delta2 > delta);
        }

        std::ostream& operator<<(std::ostream& ostrm, const RPol2d& vec);
    }

    pol::RPol2d dec2pol(const dec::RDec2d& arg);

    dec::RDec2d pol2dec(const pol::RPol2d& arg);
}

#endif



