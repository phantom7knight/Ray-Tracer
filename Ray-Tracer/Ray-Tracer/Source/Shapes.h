#pragma once

#include "Intersection.h"

class Sphere :public Intersection
{
public:
	Sphere(){}
	Sphere(glm::vec3 center, float radius): m_center(center),m_radius(radius)
	{}
	virtual bool hit(Ray& ray, float t_min, float t_max, hit_record& rec) const;
	
	inline float	 getRadius();
	inline glm::vec3 getCenter();

private:
	float		m_radius;
	glm::vec3	m_center;

};


inline float Sphere::getRadius()
{
	return m_radius;
}


inline glm::vec3 Sphere::getCenter()
{
	return m_center;
}
