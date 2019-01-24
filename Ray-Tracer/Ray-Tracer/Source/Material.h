#pragma once

#include "Intersection.h"
#include "../pch.h"

class Material
{
public:
	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3& attenuation,  Ray& scatterd) const = 0;
};



class Lambertian :public Material
{
public:
	Lambertian(){}
	Lambertian(const glm::vec3& a) :albedo(a) {}
	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3& attenuation, Ray& scattered) const
	{
		glm::vec3 target = rec.point_intersection + rec.Normal + random_point_sphere();
		scattered = Ray(rec.point_intersection, target - rec.point_intersection);
		attenuation = albedo;

		return true;
	}

private:
	glm::vec3 albedo;

};

glm::vec3 ReflectRay(const glm::vec3& v,const glm::vec3 n)
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

	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3 &attenuation, Ray& scattered) const 
	{
		glm::vec3 reflected = ReflectRay(Normalize(R_in.getDirection()), rec.Normal);
		scattered = Ray(rec.point_intersection, reflected);
		attenuation = albedo;

		return (dotProduct(scattered.getDirection(), rec.Normal) > 0);
	}

};

bool refract(const glm::vec3& v, const glm::vec3& n, float ni_nt, glm::vec3& refracted)
{
	glm::vec3 uv = Normalize(v);
	float dt = dotProduct(uv, n);
	float D = 1.0 - ni_nt * ni_nt*(1 - dt * dt);

	if (D > 0)
	{
		refracted = ni_nt * (uv - n * dt) - n * sqrt(D);
		return true;
	}
	else
		return false;
}

float schlik(float cosine, float ref_indx)
{
	float r0 = (1 - ref_indx) / (ref_indx + 1);
	r0 = r0 * r0;

	return r0 + (1 - r0)*pow(1 - cosine, 5);

}

class Dielectric :public Material
{

public:
	Dielectric(){}
	Dielectric(const float index):refraction_indx(index){ }

	virtual bool scatter(const Ray& R_in, const hit_record& rec, glm::vec3 &attenuation, Ray& scattered) const
	{
		glm::vec3 outward_normal;
		glm::vec3 reflected = ReflectRay(R_in.getDirection(), rec.Normal);

		float ni_nt;
		attenuation = glm::vec3(1, 1, 1);

		glm::vec3 refracted;
		float reflect_prob;
		float cosine;

		if (dotProduct(R_in.getDirection(), rec.Normal) > 0)
		{
			outward_normal = -rec.Normal;
			ni_nt = refraction_indx;
			cosine = refraction_indx * dotProduct(R_in.getDirection(), rec.Normal) / Length(R_in.getDirection());
		}
		else
		{
			outward_normal = rec.Normal;
			ni_nt = 1.0 / refraction_indx;
			cosine = -dotProduct(R_in.getDirection(), rec.Normal) / Length(R_in.getDirection());
		}

		if (refract(R_in.getDirection(), outward_normal, ni_nt, refracted))
		{
			reflect_prob = schlik(cosine, refraction_indx);
			//scattered = Ray(rec.point_intersection, refracted);
		}
		else
		{
			scattered = Ray(rec.point_intersection, reflected);
			reflect_prob = 1.0;
		}

		if (getRandomNumber() < reflect_prob)
		{
			scattered = Ray(rec.point_intersection, reflected);
		}
		else
		{
			scattered = Ray(rec.point_intersection, refracted);
		}

		return true;
	}


private:
	float refraction_indx;
};