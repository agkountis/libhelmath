#ifndef HELMATH_SWIZZLE2_CLASS_MACROS_H_H
#define HELMATH_SWIZZLE2_CLASS_MACROS_H_H

#define HM_SWIZZLE2_TEMPLATE_CLASS \
template<int A, int B> \
class _Swizzle { \
private: \
    T v[2]; \
public: \
    inline Vec2<T> &operator=(const Vec2<T> &rhs) \
    { \
        v[A] = rhs.x; \
        v[B] = rhs.y; \
\
        return *(Vec2<T> *) this; \
    } \
\
    inline operator Vec2() \
    { \
        return Vec2<T>{v[A], v[B]}; \
    } \
\
    inline Vec2<T> &operator()() \
    { \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> operator+(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] + rhs.x, v[B] + rhs.y}; \
    } \
\
    inline Vec2<T> operator-(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] - rhs.x, v[B] - rhs.y}; \
    } \
\
    inline Vec2<T> operator*(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] * rhs.x, v[B] * rhs.y}; \
    } \
\
    inline Vec2<T> operator/(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] / rhs.x, v[B] / rhs.y}; \
    } \
\
    inline Vec2<T> &operator+=(const Vec2<T> &rhs) \
    { \
        v[A] += rhs.x; \
        v[B] += rhs.y; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> &operator-=(const Vec2<T> &rhs) \
    { \
        v[A] -= rhs.x; \
        v[B] -= rhs.y; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> &operator*=(const Vec2<T> &rhs) \
    { \
        v[A] *= rhs.x; \
        v[B] *= rhs.y; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> &operator/=(const Vec2<T> &rhs) \
    { \
        v[A] /= rhs.x; \
        v[B] /= rhs.y; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> operator+(T rhs) \
    { \
        return Vec2<T>{v[A] + rhs, v[B] + rhs}; \
    } \
\
    inline Vec2<T> operator-(T rhs) \
    { \
        return Vec2<T>{v[A] - rhs, v[B] - rhs}; \
    } \
\
    inline Vec2<T> operator*(T rhs) \
    { \
        return Vec2<T>{v[A] * rhs, v[B] * rhs}; \
    } \
\
    inline Vec2<T> operator/(T rhs) \
    { \
        return Vec2<T>{v[A] / rhs, v[B] / rhs}; \
    } \
\
    inline Vec2<T> &operator+=(T rhs) \
    { \
        v[A] += rhs; \
        v[B] += rhs; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> &operator-=(T rhs) \
    { \
        v[A] -= rhs; \
        v[B] -= rhs; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> &operator*=(T rhs) \
    { \
        v[A] *= rhs; \
        v[B] *= rhs; \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> &operator/=(T rhs) \
    { \
        v[A] /= rhs; \
        v[B] /= rhs; \
        return *(Vec2<T> *) this; \
    } \
};

#define HM_SWIZZLE2_TEMPLATE_CLASS_SPEC \
template<int A> \
class _Swizzle<A, A> { \
private: \
    T v[2]; \
public: \
    operator Vec2() \
    { \
        return Vec2<T>{v[A]}; \
    } \
\
    inline Vec2<T> &operator()() const \
    { \
        return *(Vec2<T> *) this; \
    } \
\
    inline Vec2<T> operator+(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] + rhs.x, v[A] + rhs.y}; \
    } \
\
    inline Vec2<T> operator-(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] - rhs.x, v[A] - rhs.y}; \
    } \
\
    inline Vec2<T> operator*(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] * rhs.x, v[A] * rhs.y}; \
    } \
\
    inline Vec2<T> operator/(const Vec2<T> &rhs) \
    { \
        return Vec2<T>{v[A] / rhs.x, v[A] / rhs.y}; \
    } \
\
    inline Vec2<T> operator+(T rhs) \
    { \
        return Vec2<T>{v[A] + rhs, v[A] + rhs}; \
    } \
\
    inline Vec2<T> operator-(T rhs) \
    { \
        return Vec2<T>{v[A] - rhs, v[A] - rhs}; \
    } \
\
    inline Vec2<T> operator*(T rhs) \
    { \
        return Vec2<T>{v[A] * rhs, v[A] * rhs}; \
    } \
\
    inline Vec2<T> operator/(T rhs) \
    { \
        return Vec2<T>{v[A] / rhs, v[A] / rhs}; \
    } \
};

#endif //HELMATH_SWIZZLE2_CLASS_MACROS_H_H
