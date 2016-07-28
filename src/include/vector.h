#ifndef HELMATH_VECTOR_H
#define HELMATH_VECTOR_H

/**
 * @file vector.h
 * This file defines the Vector templated classes.
 */

#include <cmath>
#include "swizzle.h"

/**
 * @namespace hm
 * This is helmath's namespace.
 * @details All of helmaths code will be inside hm to avoid name collisions.
 */
namespace hm {

/**
 * @class Vec2
 * @tparam T Can be any numeric type.
 * @brief A class that represents a 2 dimensional vector.
 * @details Vec2 is a class that represents a 2 dimensional
 * vector. It supports accessing the vector values with various
 * ways to accommodate various use cases:
 * @li position coordinates
 * @li texture coordinates
 * @details Swizzles are available for all data representations.
 * @note This class uses macros to generate the swizzle classes and
 * the swizzle public members. The macros used are the following:
 * @note Private classes macros:
 * @li @ref HM_SWIZZLE2_TEMPLATE_CLASS
 * @li @ref HM_SWIZZLE2_TEMPLATE_CLASS_SPEC
 * @note Swizzle public members macro:
 * @li @ref HM_VEC2_SWIZZLES
 */
template<typename T>
class Vec2 {
private:
    HM_SWIZZLE2_TEMPLATE_CLASS
    HM_SWIZZLE2_TEMPLATE_CLASS_SPEC

public:
    /**
     * This union is used in order to be able to use
     * different vector member names depending on the vector usage
     * as well as access the vector using swizzles.
     * @details Position coordinate representation:
     * @li x
     * @li y
     * @details Texture coordinate representation:
     * @li s
     * @li t
     * @details All the cobinations for both representations are
     * available as swizzles.
     * @details e.g.:
     * @details Asume a vector v(1.0f, 2.0f). Using the xx swizzle:
     * @code
     * Vec2<float> v2 = v.xx;
     * @endcode
     * @details Then v2 values are v2(1.0f, 1.0f).
     */
    union {
        struct {
            T x;
            T y;
        };

        struct {
            T s;
            T t;
        };

        /**
         * Array representations of the vector.
         */
        T v[2];

        HM_VEC2_SWIZZLES
    };

    /**
     * Default Vec2 constructor.
     * @details Initializes Vec2's values to 0.
     * @return A new Vec2.
     */
    Vec2() : x(0), y(0)
    { }

    /**
     * Vec2 single argument constructor.
     * @details Initializes Vec2's values with the argument passed.
     * @param val The numeric value used to initialize Vec2's values.
     * @return A new Vec2.
     */
    explicit Vec2(T val) : x(val), y(val)
    { }

    /**
     * Vec2 double argument constructor.
     * @details Initializes Vec2's values with the arguments passed.
     * @param x The x coordinate of the vector.
     * @param y The y coordinate of the vector.
     * @return A new Vec2.
     */
    Vec2(T x, T y) : x(x), y(y)
    { }

    /**
     * Calculates the length (magnitude) of the vector.
     * @return The vector length as a double precision floating point number.
     */
    inline double length()
    {
        return std::sqrt(x * x + y * y);
    }

    /**
     * Calculates the length (magnitude) of the vector.
     * @return The vector length as a floating point number.
     */
    inline float lengthf()
    {
        return sqrtf(x * x + y * y);
    }

    /**
     * Normalizes the vector.
     * @details Divides each coordinate of the vector by the vector length
     * in order for the vector to have a length (magnitude) of 1.
     */
    inline void normalize()
    {
        double len = length();

        if(!len) {
            return;
        }

        *this /= len;
    }

    /**
     * Constucts a normalized copy of the vector.
     * @return A normalized copy of the vector.
     */
    inline Vec2<T> normalized() const
    {
        double len = length();

        if(!len) {
            return Vec2<T>{};
        }

        return Vec2<T>{static_cast<T>(x / len),
                       static_cast<T>(y / len)};
    }

    /**
     * Calculates the dot product.
     * @param v The vector with whom the dot product will be calculated.
     * @return The value of the dot product as a
     * double precision floating point number.
     */
    inline double dot(const Vec2<T> &v)
    {
        return x * v.x + y * v.y;
    }

    /**
     * Calculates the dot product.
     * @param v The vector with whom the dot product will be calculated.
     * @return The value of the dot product as a floating point number.
     */
    inline float dotf(const Vec2<T> &v)
    {
        return x * v.x + y * v.y;
    }

    /**
     * Negates the vector coordinates.
     * @return A negated copy of the vector.
     */
    inline Vec2<T> operator-()
    {
        return Vec2<T>{-x, -y};
    }

    /**
     * Calculates the addition of 2 vectors.
     * @param rhs The right hand side vector of the addition.
     * @return A new vector as the result of the addition.
     */
    inline Vec2<T> operator+(const Vec2<T> &rhs)
    {
        return Vec2<T>{x + rhs.x, y + rhs.y};
    }

    /**
     * Calculates the subtraction of 2 vectors.
     * @param rhs The right hand side vector of the subtraction.
     * @return A new vector as the result of the subtraction.
     */
    inline Vec2<T> operator-(const Vec2<T> &rhs)
    {
        return Vec2<T>{x - rhs.x, y - rhs.y};
    }

    /**
     * Calculates the multiplication of 2 vectors.
     * @param rhs The right hand side vector of the multiplication.
     * @return A new vector as the result of the multiplication.
     */
    inline Vec2<T> operator*(const Vec2<T> &rhs)
    {
        return Vec2<T>{x * rhs.x, y * rhs.y};
    }

    /**
     * Calculates the division of 2 vectors.
     * @param rhs The right hand side vector of the division.
     * @return A new vector as the result of the division.
     */
    inline Vec2<T> operator/(const Vec2<T> &rhs)
    {
        return Vec2<T>{x / rhs.x, y / rhs.y};
    }

    /**
     * Adds a vector to the left hand side operand.
     * @param rhs The right hand side vector of the addition.
     */
    inline void operator+=(const Vec2<T> &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
    }

    /**
     * Subtracts a vector from the left hand side operand.
     * @param rhs The right hand side vector of the subtraction.
     */
    inline void operator-=(const Vec2<T> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
    }

    /**
     * Multiplies the left hand side operand with a vector.
     * @param rhs The right hand side vector of the multiplication.
     */
    inline void operator*=(const Vec2<T> &rhs)
    {
        x *= rhs.x;
        y *= rhs.x;
    }

    /**
     * Divides the left hand side operand by a vector.
     * @param rhs The right hand side vector of the division.
     */
    inline void operator/=(const Vec2<T> &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
    }

    inline Vec2<T> operator+(T rhs)
    {
        return Vec2<T>{x + rhs, y + rhs};
    }

    inline Vec2<T> operator-(T rhs)
    {
        return Vec2<T>{x - rhs, y - rhs};
    }

    inline Vec2<T> operator*(T rhs)
    {
        return Vec2<T>{x * rhs, y * rhs};
    }

    inline Vec2<T> operator/(T rhs)
    {
        return Vec2<T>{x / rhs, y / rhs};
    }

    inline void operator+=(T rhs)
    {
        x += rhs;
        y += rhs;
    }

    inline void operator-=(T rhs)
    {
        x -= rhs;
        y -= rhs;
    }

    inline void operator*=(T rhs)
    {
        x *= rhs;
        y *= rhs;
    }

    inline void operator/=(T rhs)
    {
        x /= rhs;
        y /= rhs;
    }
};

/**
 * @typedef Vec2f
 * Defines a two dimensional vector of floats.
 */
using Vec2f = Vec2<float>;

/**
 * @typedef Vec2d
 * Defines a two dimensional vector of double floats.
 */
using Vec2d = Vec2<double>;

/**
 * @typedef Vec2c
 * Defines a two dimensional vector of characters.
 */
using Vec2c = Vec2<char>;

/**
 * @typedef Vec2uc
 * Defines a two dimensional vector of unsigned characters.
 */
using Vec2uc = Vec2<unsigned char>;

/**
 * @typedef Vec2s
 * Defines a two dimensional vector of short integers.
 */
using Vec2s = Vec2<short>;

/**
 * @typedef Vec2us
 * Defines a two dimensional vector of unsigned short integers.
 */
using Vec2us = Vec2<unsigned short>;

/**
 * @typedef Vec2i
 * Defines a two dimensional vector of integers.
 */
using Vec2i = Vec2<int>;

/**
 * @typedef Vec2ui
 * Defines a two dimensional vector of unsigned integers.
 */
using Vec2ui = Vec2<unsigned int>;

/**
 * @typedef Vec2l
 * Defines a two dimensional vector of long integers.
 */
using Vec2l = Vec2<long>;

/**
 * @typedef Vec2ul
 * Defines a two dimensional vector of unsigned long integers.
 */
using Vec2ul = Vec2<unsigned long>;

/**
 * @typedef Vec2ll
 * Defines a two dimensional vector of long long integers.
 */
using Vec2ll = Vec2<long long>;

/**
 * @typedef Vec2ull
 * Defines a two dimensional vector of unsigned long long integers.
 */
using Vec2ull = Vec2<unsigned long long>;


/**
 * @class Vec3
 * @tparam T Can be any numeric type.
 * @brief A class that represents a 3 dimensional vector.
 * @details Vec3 is a class that represents a 3 dimensional
 * vector. It supports accessing the vector values with various
 * ways to accommodate various use cases:
 * @li position coordinates
 * @li texture coordinates
 * @li color values
 * @details Swizzles are available for all data representations.
 */
template<typename T>
class Vec3 {
private:
    HM_SWIZZLE3_TEMPLATE_CLASS
    HM_SWIZZLE3_TEMPLATE_CLASS_SPEC

public:
    union {
        struct {
            T x;
            T y;
            T z;
        };

        struct {
            T r;
            T g;
            T b;
        };

        struct {
            T s;
            T t;
            T p;
        };

        T v[3];

        HM_VEC3_SWIZZLES
    };

    Vec3() : x(0), y(0), z(0)
    { }

    explicit Vec3(T val) : x(val), y(val), z(val)
    { }

    Vec3(T x, T y, T z) : x(x), y(y), z(z)
    { }

    /**
     * Calculates the length (magnitude) of the vector.
     * @return The length of the vector as
     * a double precision floating point number.
     */
    inline double length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    /**
     * Calculates the length (magnitude) of the vector.
     * @return The length of the vector as a floating point number.
     */
    inline float lengthf() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    inline void normalize()
    {
        double len = length();

        if (!len) {
            return;
        }

        *this /= len;
    }

    inline Vec3<T> normalized() const
    {
        double len = length();

        if (!len) {
            return Vec3<T>{};
        }

        return Vec3<T>{static_cast<T>(x / len),
                       static_cast<T>(y / len),
                       static_cast<T>(z / len)};
    }

    inline double dot(const Vec3<T> &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline float dotf(const Vec3<T> &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline Vec3<T> cross(const Vec3<T> &v) const
    {
        return Vec3<T>{y * v.z - z * v.y,
                       z * v.x - x * v.z,
                       x * v.y - y * v.x};
    }

    /**
     * Calculates the reflected vector.
     * @param normal The normal vector used for the reflection calculation.
     */
    inline void reflect(const Vec3<T> normal)
    {
        *this -= normal * 2 * dot(normal);
    }

    /**
     * Calculates the reflected vector as a new vector.
     * @param normal The normal vector used for the reflection calculation.
     * @return A new reflected vector.
     */
    inline Vec3<T> reflected(const Vec3<T> normal) const
    {
        return *this - normal * 2 * dot(normal);
    }

    inline Vec3<T> operator-() const
    {
        return Vec3<T>{-x, -y, -z};
    }

    inline Vec3<T> operator+(const Vec3<T> &rhs) const
    {
        return Vec3<T>{x + rhs.x, y + rhs.y, z + rhs.z};
    }

    inline Vec3<T> operator-(const Vec3<T> &rhs) const
    {
        return Vec3<T>{x - rhs.x, y - rhs.y, z - rhs.z};
    }

    inline Vec3<T> operator*(const Vec3<T> &rhs) const
    {
        return Vec3<T>{x * rhs.x, y * rhs.y, z * rhs.z};
    }

    inline Vec3<T> operator/(const Vec3<T> &rhs)
    {
        return Vec3<T>{x / rhs.x, y / rhs.y, z / rhs.z};
    }

    inline void operator+=(const Vec3<T> &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
    }

    inline void operator-=(const Vec3<T> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
    }

    inline void operator*=(const Vec3<T> &rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
    }

    inline void operator/=(const Vec3<T> &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
    }

    inline Vec3<T> operator+(T rhs) const
    {
        return Vec3<T>{x + rhs, y + rhs, z + rhs};
    }

    inline Vec3<T> operator-(T rhs) const
    {
        return Vec3<T>{x - rhs, y - rhs, z - rhs};
    }

    inline Vec3<T> operator*(T rhs) const
    {
        return Vec3<T>{x * rhs, y * rhs, z * rhs};
    }

    inline Vec3<T> operator/(T rhs) const
    {
        return Vec3<T>{x / rhs, y / rhs, z / rhs};
    }

    inline void operator+=(T rhs)
    {
        x += rhs;
        y += rhs;
        z += rhs;
    }

    inline void operator-=(T rhs)
    {
        x -= rhs;
        y -= rhs;
        z -= rhs;
    }

    inline void operator*=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
    }

    inline void operator/=(T rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
    }
};

/**
 * @typedef Vec3f
 * Defines a three dimensional vector of floats.
 */
using Vec3f = Vec3<float>;

/**
 * @typedef Vec3d
 * Defines a three dimensional vector of double floats.
 */
using Vec3d = Vec3<double>;

/**
 * @typedef Vec3s
 * Defines a three dimensional vector of short integers.
 */
using Vec3s = Vec3<short>;

/**
 * @typedef Vec3us
 * Defines a three dimensional vector of unsigned short integers.
 */
using Vec3us = Vec3<unsigned short>;

/**
 * @typedef Vec3c
 * Defines a three dimensional vector of characters.
 */
using Vec3c = Vec3<char>;

/**
 * @typedef Vec3uc
 * Defines a three dimensional vector of unsigned characters.
 */
using Vec3uc = Vec3<unsigned char>;

/**
 * @typedef Vec3i
 * Defines a three dimensional vector of integers.
 */
using Vec3i = Vec3<int>;

/**
 * @typedef Vec3ui
 * Defines a three dimensional vector of unsigned integers.
 */
using Vec3ui = Vec3<unsigned int>;

/**
 * @typedef Vec3l
 * Defines a three dimensional vector of long integers.
 */
using Vec3l = Vec3<long>;

/**
 * @typedef Vec3ul
 * Defines a three dimensional vector of unsigned long integers.
 */
using Vec3ul = Vec3<unsigned long>;

/**
 * @typedef Vec3ll
 * Defines a three dimensional vector of long long integers.
 */
using Vec3ll = Vec3<long long>;

/**
 * @typedef Vec3ull
 * Defines a three dimensional vector of unsigned long long integers.
 */
using Vec3ull = Vec3<unsigned long long>;


/**
 * @class Vec4
 * @tparam T Can be any numeric type.
 * @brief A class that represents a 4 dimensional vector.
 * @details Vec4 is a class that represents a 4 dimensional
 * vector. It supports accessing the vector values with various
 * ways to accommodate various use cases:
 * @li position coordinates
 * @li texture coordinates
 * @li color values
 * @details Swizzles are available for all data representations.
 */
template<typename T>
class Vec4 {
private:
    HM_SWIZZLE4_TEMPLATE_CLASS
    HM_SWIZZLE4_TEMPLATE_CLASS_SPEC

public:
    union {
        struct {
            T x;
            T y;
            T z;
            T w;
        };

        struct {
            T r;
            T g;
            T b;
            T a;
        };

        struct {
            T s;
            T t;
            T p;
            T q;
        };

        T v[4];

       HM_VEC4_SWIZZLES
    };

    Vec4() : x(0), y(0), z(0), w(0)
    { }

    explicit Vec4(T val) : x(val), y(val), z(val), w(val)
    { }

    Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
    { }

    inline double length() const
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    inline float lengthf() const
    {
        return sqrtf(x * x + y * y + z * z + w * w);
    }

    inline void normalize()
    {
        double len = length();

        if (!len) {
            return;
        }

        *this /= len;
    }

    inline Vec4<T> normalized() const
    {
        double len = length();

        if (!len) {
            return Vec4<T>{};
        }

        return Vec4<T>{*this /= len};
    }

    inline Vec4<T> operator-() const
    {
        return Vec4<T>{-x, -y, -z, -w};
    }

    inline Vec4<T> operator+(const Vec4<T> &rhs) const
    {
        return Vec4<T>{x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w};
    }

    inline Vec4<T> operator-(const Vec4<T> &rhs) const
    {
        return Vec4<T>{x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w};
    }

    inline Vec4<T> operator*(const Vec4<T> &rhs) const
    {
        return Vec4<T>{x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w};
    }

    inline Vec4<T> operator/(const Vec4<T> & rhs) const
    {
        return Vec4<T>{x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w};
    }

    inline void operator+=(const Vec4<T> &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
    }

    inline void operator-=(const Vec4<T> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
    }

    inline void operator*=(const Vec4<T> &rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        w *= rhs.w;
    }

    inline void operator/=(const Vec4<T> &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        w /= rhs.w;
    }

    inline Vec4<T> operator+(T rhs) const
    {
        return Vec4<T>{x + rhs, y + rhs, z + rhs, w + rhs};
    }

    inline Vec4<T> operator-(T rhs) const
    {
        return Vec4<T>{x - rhs, y - rhs, z - rhs, w - rhs};
    }

    inline Vec4<T> operator*(T rhs) const
    {
        return Vec4<T>{x * rhs, y * rhs, z * rhs, w * rhs};
    }

    inline Vec4<T> operator/(T rhs) const
    {
        return Vec4<T>{x / rhs, y / rhs, z / rhs, w / rhs};
    }

    inline void operator+=(T rhs)
    {
        x += rhs;
        y += rhs;
        z += rhs;
        w += rhs;
    }

    inline void operator-=(T rhs)
    {
        x -= rhs;
        y -= rhs;
        z -= rhs;
        w -= rhs;
    }

    inline void operator*=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
    }

    inline void operator/=(T rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        w /= rhs;
    }
};

/**
 * @typedef Vec4f
 * Defines a four dimensional vector of floats.
 */
using Vec4f = Vec4<float>;

/**
 * @typedef Vec4d
 * Defines a four dimensional vector of doubles.
 */
using Vec4d = Vec4<double>;

/**
 * @typedef Vec4s
 * Defines a four dimensional vector of short integers.
 */
using Vec4s = Vec4<short>;

/**
 * @typedef Vec4us
 * Defines a four dimensional vector of unsigned short integers.
 */
using Vec4us = Vec4<unsigned short>;

/**
 * @typedef Vec4c
 * Defines a four dimensional vector of characters.
 */
using Vec4c = Vec4<char>;

/**
 * @typedef Vec4uc
 * Defines a four dimensional vector of unsigned characters.
 */
using Vec4uc = Vec4<unsigned char>;

/**
 * @typedef Vec4i
 * Defines a four dimensional vector of integers.
 */
using Vec4i = Vec4<int>;

/**
 * @typedef Vec4ui
 * Defines a four dimensional vector of unsigned integers.
 */
using Vec4ui = Vec4<unsigned int>;

/**
 * @typedef Vec4l
 * Defines a four dimensional vector of long integers.
 */
using Vec4l = Vec4<long>;

/**
 * @typedef Vec4ul
 * Defines a four dimensional vector of unsigned long integers.
 */
using Vec4ul = Vec4<unsigned long>;

/**
 * @typedef Vec4ll
 * Defines a four dimensional vector of long long integers.
 */
using Vec4ll = Vec4<long long>;

/**
 * @typedef Vec4ull
 * Defines a four dimensional vector of unsigned long long integers.
 */
using Vec4ull = Vec4<unsigned long long>;

/**
 * Calculates the dot product of two two dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The result of the dot product as a double float.
 */
template<typename T>
inline double dot(const Vec2<T> &v1, const Vec2<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

/**
 * Calculates the dot product of two two dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The result of the dot product as a float.
 */
template<typename T>
inline float dotf(const Vec2<T> &v1, const Vec2<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

/**
 * Calculates the dot product of two three dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The result of the dot product as a double float.
 */
template<typename T>
inline double dot(const Vec3<T> &v1, const Vec3<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/**
 * Calculates the dot product of two three dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The result of the dot product as a float.
 */
template<typename T>
inline float dotf(const Vec3<T> &v1, const Vec3<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/**
 * Calculates the dot product of two four dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The result of the dot product as a double float.
 */
template<typename T>
inline double dot(const Vec4<T> &v1, const Vec4<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

/**
 * Calculates the dot product of two four dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The result of the dot product as a float.
 */
template<typename T>
inline float dotf(const Vec4<T> &v1, const Vec4<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

/**
 * Calculates the cross product of two three dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @return The resulting vector from the cross porduct.
 */
template<typename T>
inline Vec3<T> cross(const Vec3<T> &v1, const Vec3<T> &v2)
{
    return Vec3<T>{v1.y * v2.z - v1.z * v2.y,
                   v1.z * v2.x - v1.x * v2.z,
                   v1.x * v2.y - v1.y * v2.x};
}

/**
 * Calculates the cross product of three four dimensional vectors.
 * @tparam T Can be any numeric type.
 * @param v1 First vector argument.
 * @param v2 Second vector argument.
 * @param v3 Third vector argument.
 * @return The resulting vector from the cross product.
 */
template<typename T>
inline Vec4<T> cross(const Vec4<T> &v1, const Vec4<T> &v2, const Vec4<T> &v3)
{
    //TODO
}

/**
 * Calculates a reflected two dimensional vector based
 * on a two dimensional normal vector.
 * @tparam T Can be any numeric type.
 * @param v The vector to be reflected.
 * @param normal The normal vector used in the reflection calculation.
 * @return A new reflected vector.
 */
template<typename T>
inline Vec2<T> reflect(const Vec2<T> v, const Vec2<T> normal)
{
    return v - normal * 2 * dot(v, normal);
}

/**
 * Calculates a reflected three dimensional vector based
 * on a three dimensional normal vector.
 * @tparam T Can be any numeric type.
 * @param v The vector to be reflected.
 * @param normal The normal vector used in the reflection calculation.
 * @return A new reflected vector.
 */
template<typename T>
inline Vec3<T> reflect(const Vec3<T> v, const Vec3<T> normal)
{
    return v - normal * 2 * dot(v, normal);
}

}

#endif //HELMATH_VECTOR_H
