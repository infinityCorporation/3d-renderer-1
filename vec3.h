#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public: 
        double e[3];

        // This defines the vec3 type and shape
        vec3() : e{0,0,0}{}

        // Defines it more specifically with arguments
        vec3(double e0, double e1, double e2) : e{e0,e1,e2}{}

        // Here we map our input arguments e[0],e[1],e[2] to x,y,z
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // This operator just negates the vec3 class
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // This is just a method to add a new vec3 v to the current vec3
        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // Given a scalar value t, this operator allows us to multiple it by the current vec3
        vec3 operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // Same as mult but division
        vec3 operator/=(double t){
            return *this *= 1/t;
        }

        // Returns the length
        double length() const {
            return std::sqrt(length_squared());
        }

        // returns the square length of the vec3, a useful tool when working with vectors
        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

// Now here we are going to define some useful methods for our vec3 class for
// use with rendering

// Additionally, we are going to define two types of this class (really just by 
// name though) which are point3 and color. Point3 is for working with pixel locations
// and color defines the color in rgb

// This is just an alias for vec3
using Point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// This adds two vectors which I though we already defined in the class
// It also takes what looks like two pointer inputs
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// This one is sort of like dot product
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// now here is the dot product, I saw this one coming
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// This one just turns our vec3 into a unit vector based on the current vec3
inline vec3 unit_vector(const vec3 v) {
    return v / v.length();
}

#endif
