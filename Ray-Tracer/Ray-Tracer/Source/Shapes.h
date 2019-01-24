#pragma once

#include "Intersection.h"


class Sphere :public Intersection
{
public:
	Sphere(){}
	Sphere(glm::vec3 center, float radius, Material* m) : m_center(center), m_radius(radius), m_material_ptr(m)
	{}
	virtual bool hit(const Ray& ray, float t_min, float t_max, hit_record& rec) const;
	
	inline float	 getRadius();
	inline glm::vec3 getCenter();
	inline Material* getMaterial();

private:
	float		m_radius;
	glm::vec3	m_center;
	Material*	m_material_ptr;

};


inline float Sphere::getRadius()
{
	return m_radius;
}


inline glm::vec3 Sphere::getCenter()
{
	return m_center;
}

inline Material* Sphere::getMaterial()
{
	return m_material_ptr;
}
