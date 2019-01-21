#include "../pch.h"
//#include "../Source/Ray.h"
#include "Shapes.h"


bool Sphere::hit(Ray & ray, float t_min, float t_max, hit_record & rec) const
{
	glm::vec3 OC = ray.getOrigin() - m_center;

	float a = dotProduct(ray.getDirection(), ray.getDirection());
	float b = 2.0 * dotProduct(OC, ray.getDirection());
	float c = dotProduct(OC, OC) - m_radius * m_radius;
	float D = b * b - a * c;

	if (D > 0)
	{
		float temp = (-b - sqrt(D)) / a;

		if (temp < t_max && temp>t_min)
		{
			rec.t = temp;
			rec.point_intersection = ray.PointRayIntersection(rec.t);
			rec.Normal = (rec.point_intersection - m_center) / m_radius;

			return true;
		}

		temp = (-b + sqrt(D)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.point_intersection = ray.PointRayIntersection(rec.t);
			rec.Normal = (rec.point_intersection - m_center) / m_radius;

			return true;
		}

	}

	return false;
}