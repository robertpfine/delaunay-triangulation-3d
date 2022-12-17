#include "vector3d.h"
#include "triangle3d.h"

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
T
Vector3d<T>::dot(const Vector3d<T> &vertexA, const Vector3d<T> &vertexB) const
{
    //std::cout << " dot Product: " << (vertexA.x * vertexB.x + vertexA.y * vertexB.y + vertexA.z * vertexB.z) << std::endl;
    return (vertexA.x * vertexB.x + vertexA.y * vertexB.y + vertexA.z * vertexB.z);
}




template<class T>
T
Vector3d<T>::norm(const Vector3d<T> &v) const
    {
        return sqrt(x * x + y * y + z * z);
    }





template<class T>
Vector3d<T> Vector3d<T>::crossProd(const dt::Vector3d<T> &u, const dt::Vector3d<T> &v) const
{
        //const Vector3d<T> test;

        T x = u.y * v.z - u.z * v.y;
        T y = -(u.x * v.z - u.z * v.x);
        T z = u.x * v.y - u.y * v.x;

        return  Vector3d<T> (x, y, z);
}



template<class T>
Vector3d<T> Vector3d<T>::scalarTimesVector(const T &u, const Vector3d<T>  &v) const
{

        T x = u * v.x;
        T y = u * v.y;
        T z = u * v.z;

        return Vector3d<T> (x, y, z);

}


    template<class T>
    Vector3d<T>
    Vector3d<T>::operator +(const Vector3d<T> &v) const
    {
        return Vector3d<T> (this->x + v.x, this->y + v.y, this->z + v.z);
    }




template<class T>
Vector3d<T>
Vector3d<T>::operator -(const Vector3d<T> &v) const
    {
        return Vector3d<T> (this->x - v.x, this->y - v.y, this->z - v.z);
    }



template<class T>
Vector3d<T>
Vector3d<T>::operator ^(const Vector3d<T> &v) const
    {
        return Vector3d<T> (this->x * v.x, this->y * v.y, this->z * v.z);
    }


    template<class T>
    Vector3d<T>
    Vector3d<T>::operator /(const Vector3d<T> &v) const
    {
        return Vector3d<T> (this->x / v.x, this->y / v.y, this->z / v.z);
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
