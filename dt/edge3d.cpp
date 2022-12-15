#include "edge3d.h"

namespace dt {

template<typename T>
Edge3d<T>::Edge3d(const VertexType &v1, const VertexType &v2) :
	v(&v1), w(&v2)
{}

template<typename T>
bool
Edge3d<T>::operator ==(const Edge3d<T> &e) const
{
	return (*(this->v) == *e.v && *(this->w) == *e.w) ||
			(*(this->v) == *e.w && *(this->w) == *e.v);
}

template<typename U>
std::ostream&
operator <<(std::ostream &str, const Edge3d<U> &e)
{
	return str << "Edge " << *e.v << ", " << *e.w;
}

template struct Edge3d<float>;
template struct Edge3d<double>;

} // namespace dt
