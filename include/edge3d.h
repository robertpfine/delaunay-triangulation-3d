#ifndef H_EDGE3D
#define H_EDGE3D

#include "vector3d.h"

namespace dt {

template<typename T>
struct Edge3d
{
	using Type = T;
	using VertexType = Vector3d<Type>;

	Edge3d() = default;
	Edge3d(const Edge3d&) = default;
	Edge3d(Edge3d&&) = default;
	Edge3d(const VertexType &v1, const VertexType &v2);

	Edge3d &operator=(const Edge3d&) = default;
	Edge3d &operator=(Edge3d&&) = default;
	bool operator ==(const Edge3d &e) const;

	template<typename U>
	friend std::ostream &operator <<(std::ostream &str, const Edge3d<U> &e);

	const VertexType *v;
	const VertexType *w;
	bool isBad = false;

	static_assert(std::is_floating_point<Edge3d<T>::Type>::value,
		"Type must be floating-point");
};

template<typename T>
bool
almost_equal(const Edge3d<T> &e1, const Edge3d<T> &e2)
{
	return	(almost_equal(*e1.v, *e2.v) && almost_equal(*e1.w, *e2.w)) ||
			(almost_equal(*e1.v, *e2.w) && almost_equal(*e1.w, *e2.v));
}

} // namespace dt

#endif
