#include "vector3d.h"
#include "triangle3d.h"

namespace dt {

template<typename T>
Triangle3d<T>::Triangle3d(const VertexType &v1, const VertexType &v2, const VertexType &v3) :
	a(&v1), b(&v2), c(&v3), isBad(false)
{}

template<typename T>
bool
Triangle3d<T>::containsVertex(const VertexType &v) const
{
	// return p1 == v || p2 == v || p3 == v;
	return almost_equal(*a, v) || almost_equal(*b, v) || almost_equal(*c, v);
}

template<class T>
bool
Triangle3d<T>::circumCircleContains(const VertexType &v) const
{
	const T ab = a->norm2();
	const T cd = b->norm2();
	const T ef = c->norm2();

	const T ax = a->x;
	const T ay = a->y;
	const T az = a->z;

    const T bx = b->x;
	const T by = b->y;
    const T bz = b->z;

    const T cx = c->x;
	const T cy = c->y;
    const T cz = c->z;

	const T circum_x = (ab * (cy - by) + cd * (ay - cy) + ef * (by - ay)) / (ax * (cy - by) + bx * (ay - cy) + cx * (by - ay));
	const T circum_y = (ab * (cx - bx) + cd * (ax - cx) + ef * (bx - ax)) / (ay * (cx - bx) + by * (ax - cx) + cy * (bx - ax));
    //const T circum_z = 0;


    const T sideAx = ax - cx;
    const T sideAy = ay - cy;
    const T sideAz = az - cz;

    const T sideBx = bx - cx;
    const T sideBy = by - cy;
    const T sideBz = bz - cz;

    const VertexType sideA(sideAx, sideAy, sideAz);
    const VertexType sideB(sideBx, sideBy, sideBz);


    dt::Vector3d<T> cprod;
    dt::Vector3d<T> TEST;
    TEST = cprod.crossProd(sideA, sideB);
    std::cout << " " << "RRRRRRRRRRRRRRRRRRRRRRRRR crossProd"
    << " Test.x: " << TEST.x
    << " Test.y: " << TEST.y
    << " Test.z: " << TEST.z
    << std::endl;

    dt::Vector3d<T> _cprod;
    //T norm_a;
    //T norm_b;
    //T norm_a_cross_b{};

    T norm_a = _cprod.norm(sideA);
    T norm_a_square = norm_a * norm_a;
    T norm_b = _cprod.norm(sideB);
    T norm_b_square = norm_a * norm_b;
    Vector3d<T> a_cross_b = _cprod.crossProd(sideA, sideB);
    Vector3d<T> a_cross_b_square = a_cross_b^a_cross_b;
    Vector3d<T> axb_square_times_2 = _cprod.scalarTimesVector(2, a_cross_b_square);


    const VertexType vertexC(cx, cy, cz);

    const VertexType circumCenter =
            -cprod.crossProd(_cprod.scalarTimesVector(norm_a * norm_a, sideB ))
                - _cprod.scalarTimesVector(norm_b * norm_b, sideA )), _cprod.crossProd(sideA, sideB));













	const VertexType circum(circum_x / 2, circum_y / 2, 0);
	const T circum_radius = a->dist2(circum);
	const T dist = v.dist2(circum);
	return dist <= circum_radius;
}

template<typename T>
bool
Triangle3d<T>::operator ==(const Triangle3d &t) const
{
	return	(*this->a == *t.a || *this->a == *t.b || *this->a == *t.c) &&
			(*this->b == *t.a || *this->b == *t.b || *this->b == *t.c) &&
			(*this->c == *t.a || *this->c == *t.b || *this->c == *t.c);
}

template<typename U>
std::ostream&
operator <<(std::ostream &str, const Triangle3d<U> &t)
{
	return str << "Triangle:" << "\n\t" <<
			*t.a << "\n\t" <<
			*t.b << "\n\t" <<
			*t.c << '\n';
}

template struct Triangle3d<float>;
template struct Triangle3d<double>;

} // namespace dt
