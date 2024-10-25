#ifndef BMATH_GEOMETRY
#define BMATH_GEOMETRY

#include "Vector.hpp"

namespace bMath {

    struct Triangle {
        Vector3 a,b,c;

        Triangle(Vector3 a, Vector3 b, Vector3 c)
        : a(a), b(b), c(c) {}

        Vector3 getNormal() const {
            return cross(b-a,c-a);
        }
    };

    struct RayIntersection {
        bool hit;
        Vector3 point;
        Vector3 normal;

        RayIntersection(bool _hit)
        : hit(_hit) {}

        RayIntersection(Vector3 _point, Vector3 _normal)
        : hit(true), point(_point), normal(_normal) {}
    };

    struct Ray {
        Vector3 p, d;

        Ray(Vector3 p, Vector3 d)
        : p(p), d(d) {}
    };

    RayIntersection Raycast(const Ray &ray, const Triangle &tri) {
        Vector3 point;
        float t = dot((tri.a-ray.p), tri.getNormal())/(dot(tri.getNormal(), ray.d));
        if (t < 0) {
            return RayIntersection(false);
        }
        point = ray.p + ray.d*t;

        float w1 = (tri.a.x*(tri.c.y-tri.a.y)+(point.y-tri.a.y)*(tri.c.x-tri.a.x)-point.x*(tri.c.y-tri.a.y))/((tri.b.y-tri.a.y)*(tri.c.x-tri.a.x)-(tri.b.x-tri.a.x)*(tri.c.y-tri.a.y));
        float w2 = (point.x-tri.a.x-w1*(tri.b.x-tri.a.x))/(tri.c.x-tri.a.x);
        if (w1 > 0 && w1 < 1 && w2 > 0 && w2 < 1 && (w1+w2) < 1) {
            return RayIntersection(point, tri.getNormal());
        }
        else {
            return RayIntersection(false);
        }
    }

    
}

#endif