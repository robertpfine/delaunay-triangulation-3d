#include "vector3d.h"

namespace dt {

template<typename T>
Vector3d<T>::Vector3d(const T vx, const T vy, const T vz) :
	x(vx), y(vy), z(vz)
{}

template<typename T>
T
Vector3d<T>::dist2(const Vector3d<T> &v) const
{
	const T dx = x - v.x;
	const T dy = y - v.y;
    const T dz = z - v.z;
	return dx * dx + dy * dy;
}

template<>
float
Vector3d<float>::dist(const Vector3d<float> &v) const
{
	//return hypotf(x - v.x, y - v.y, z - v.z);
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}

template<>
double
Vector3d<double>::dist(const Vector3d<double> &v) const
{
	//return hypot(x - v.x, y - v.y, z - v.z);
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}

template<typename T>
T
Vector3d<T>::norm2() const
{
	return x * x + y * y+ z * z;
}

template<typename T>
bool
Vector3d<T>::operator ==(const Vector3d<T> &v) const
{
	return (this->x == v.x) && (this->y == v.y);
}

template<typename U>
std::ostream &
operator <<(std::ostream &str, const Vector3d<U> &v)
{
	return str << "Point x: " << v.x << " y: " << v.y;
}

template struct Vector3d<float>;
template struct Vector3d<double>;

} // namespace dt
