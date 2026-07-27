// source: https://raytracing.github.io/books/RayTracingInOneWeekend.html

#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include <cmath>

class vec3 {
    // why p? the source uses e
    public:
        double p[3];

        vec3() : p{0, 0, 0} {}

        vec3(double p0, double p1, double p2) : 
            p{p0, p1, p2} {}

        double x() const { return p[0]; }
        double y() const { return p[1]; }
        double z() const { return p[2]; }

        vec3 operator-() const { return vec3(-p[0], -p[1], -p[2]); }
        double operator[](int i) const { return p[i]; }

        // why are we returning a reference here?
        // OH I GOT IT. (after two minutes)
        double& operator[](int i) { return p[i]; }

        vec3& operator+=(const vec3& v) {
            p[0] += v.p[0];
            p[1] += v.p[1];
            p[2] += v.p[2];
            return *this;
        }

        vec3& operator*=(double t) {
            p[0] *= t;
            p[1] *= t;
            p[2] *= t;

            return *this;
        }

        vec3& operator/=(double t) {
            // look at the functio right above.
            (*this) *= 1.0/t;
            return *this;
        }

        double length_squared() const {
            return p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
        }

        double length() const {
            return std::sqrt(length_squared());
        }
};

// aliasing basically. 
// point3 and vec3 are the same thing
using point3 = vec3;

// utility functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << "< " << v.p[0] << ' ' << v.p[1] << ' ' << v.p[3] << " >";
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(
        u.p[0] + v.p[0],
        u.p[1] + v.p[1],
        u.p[2] + v.p[2]
    );
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(
        u.p[0] - v.p[0],
        u.p[1] - v.p[1],
        u.p[2] - v.p[2]
    );
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(
        u.p[0] * v.p[0], 
        u.p[1] * v.p[1],
        u.p[2] + v.p[2]
    );
}

inline vec3 operator*(const double t, const vec3& u) {
    return vec3(
        t * u.p[0],
        t * u.p[1],
        t * u.p[2]
    );
}

inline vec3 operator*(const vec3& u, const double t) {
    return t * u;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3& u, const vec3 v) {
    return u.p[0] * v.p[0]
        + u.p[1] * v.p[1]
        + u.p[2] * v.p[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(
        u.p[1] * v.p[2] - u.p[2] * v.p[1],
        u.p[2] * v.p[0] - u.p[0] * v.p[2],
        u.p[0] * v.p[1] - u.p[1] * v.p[0]
    );
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif