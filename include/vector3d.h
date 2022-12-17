#ifndef H_VECTOR3D
#define H_VECTOR3D

#include "numeric.h"

#include <iostream>
#include <cmath>
#include <type_traits>

namespace dt {

template<typename T>
class Vector3d
{
public:

    using Type = T;
	Vector3d() = default;
	Vector3d(const Vector3d<T> &v) = default;
    //Vector3d(const Vector3d<T> &v);

    Vector3d(Vector3d<T>&&) = default;
	Vector3d(const T vx, const T vy, const T vz);

	T dist2(const Vector3d<T> &v) const;
	T dist(const Vector3d<T> &v) const;
	T norm2() const;






    T norm(const Vector3d<T> &v) const;

    T dot(const Vector3d<T> &vertexA, const Vector3d<T> &vertexB) const;

    Vector3d<T> crossProd(const Vector3d<T> &u, const Vector3d<T> &v) const;
    //dt::Vector3d<T> &test;



    Vector3d<T> scalarTimesVector(const T &u, const Vector3d<T> &v) const;

    Vector3d<T> operator +(const Vector3d<T> &v) const;
    Vector3d<T> operator -(const Vector3d<T> &v) const;
    Vector3d<T> operator ^(const Vector3d<T> &v) const;
    Vector3d<T> operator /(const Vector3d<T> &v) const;
    Vector3d<T> operator /(const T &v) const;


    Vector3d &operator=(const Vector3d<T>&) = default;
	Vector3d &operator=(Vector3d&&) = default;
	bool operator ==(const Vector3d<T> &v) const;
	template<typename U>
	friend std::ostream &operator <<(std::ostream &str, const Vector3d<U> &v);

	T x;
	T y;
    T z;

	static_assert(std::is_floating_point<Vector3d<T>::Type>::value,
		"Type must be floating-point");
};

template<typename T>
bool almost_equal(const Vector3d<T> &v1, const Vector3d<T> &v2)
{
	return almost_equal(v1.x, v2.x) && almost_equal(v1.y, v2.y) && almost_equal(v1.z, v2.z);
}

} // namespace dt

#endif
