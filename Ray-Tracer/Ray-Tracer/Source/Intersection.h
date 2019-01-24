#pragma once
//#include "../pch.h"
#include "Ray.h"



struct hit_record
{
	float t;
	glm::vec3 point_intersection;
	glm::vec3 Normal;
	class Material *material_ptr;
};


class Intersection
{
public:
	virtual bool hit(const Ray& ray, float t_min, float t_max, hit_record& rec) const = 0;
};