#ifndef BMATH_GEOMETRY
#define BMATH_GEOMETRY

#include "Vector.hpp"
#include "Matrix.hpp"
#include <vector>

namespace bMath {

    struct Triangle {
        float3 a,b,c;
 
        Triangle(float3 a, float3 b, float3 c)
        : a(a), b(b), c(c) {}
 
       float3 getNormal() const {
            return cross(b-a,c-a);
        }
    };

    struct RayIntersection {
        bool hit = false;
        float3 point;
        float3 normal;
        int hits = 0;

        RayIntersection(bool _hit)
        : hit(_hit) {}

        RayIntersection(bool _hit, int hits)
        : hit(_hit), hits(hits) {}

        RayIntersection(float3 _point, float3 _normal)
        : hit(true), point(_point), normal(_normal) {}

        RayIntersection(float3 _point, float3 _normal, int hits)
        : hit(true), point(_point), normal(_normal), hits(hits) {}
    };

    struct Ray {
        float3 p, d;

        Ray(float3 p, float3 d)
        : p(p), d(d) {}
    };

    RayIntersection Raycast(const Ray &ray, const Triangle &tri) {
        float3 point;
        float t = dot((tri.a-ray.p), tri.getNormal())/(dot(tri.getNormal(), ray.d));
        std::cout << t << "\n";
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

    RayIntersection Raycast(const Ray &ray, const std::vector<Triangle> &tris) {
        RayIntersection result(false, 0);
        int hits = 0;
        for (int i = 0; i < tris.size(); i++) {
            float3 point;
            Triangle tri = tris[i];
            float t = dot((tri.a-ray.p), tri.getNormal())/(dot(tri.getNormal(), ray.d));
            std::cout << "t: " << t << "\n";
            if (t <= 0) {
                continue;
            }
            point = ray.p + ray.d*t;
            std::cout <<"point: " << point << "\n";

            float3 triNormal = tri.getNormal();

            float3 AB = tri.b-tri.a;
            float3 BC = tri.c-tri.b;
            float3 CA = tri.a-tri.c;

            float3 AP = point - tri.a;
            float3 BP = point - tri.b;
            float3 CP = point - tri.c;

            bool ATest = dot(cross(AB,AP), triNormal) >= 0.0f;
            bool BTest = dot(cross(BC,BP), triNormal) >= 0.0f;
            bool CTest = dot(cross(CA,CP), triNormal) >= 0.0f;
            
            if (ATest && BTest && CTest) {
                hits++;
                if (result.hit) {
                    float currentDist = bMath::distance(ray.p, result.point);
                    float newDist = bMath::distance(ray.p, point);
                    if (newDist < currentDist) {result = RayIntersection(point, tri.getNormal(), hits);}
                    else {result.hits = hits;}
                }
                else {
                    result = RayIntersection(point, tri.getNormal(), hits);
                }
            }
            else {
                continue;
            }
        }
        return result;
    }


    Matrix3 CubeInertiaTensor() {
      return Matrix3();
    }

    Matrix3 ConeInertiaTensor() {
      return Matrix3();
    }

    
}

#endif
