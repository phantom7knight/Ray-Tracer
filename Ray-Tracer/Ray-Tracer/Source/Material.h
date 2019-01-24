#pragma once

#include "Intersection.h"
#include "../pch.h"

class Material
{
public:
	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3 attenuation,  Ray& scatterd) const = 0;
};



class Lambertian :public Material
{
public:
	Lambertian(){}
	Lambertian(const glm::vec3& a) :albedo(a) {}
	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3 attenuation, Ray& scattered) const
	{
		glm::vec3 target = rec.point_intersection + rec.Normal + random_point_sphere();
		scattered = Ray(rec.point_intersection, target - rec.point_intersection);
		attenuation = albedo;

		return true;
	}

private:
	glm::vec3 albedo;

};

glm::vec3 ReflectedRay(const glm::vec3& v,const glm::vec3 n)
{
	return v - 2 * dotProduct(v, n)*n;
}


class Metal:public Material
{
private:
	glm::vec3 albedo;

public:
	Metal() {}

	Metal(const glm::vec3& a):albedo(a){}

	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3 attenuation, Ray& scattered) const 
	{
		glm::vec3 reflected = ReflectedRay(Normalize(R_in.getDirection()), rec.Normal);
		scattered = Ray(rec.point_intersection, reflected);
		attenuation = albedo;

		return (dotProduct(scattered.getDirection(), rec.Normal) > 0);
	}

};