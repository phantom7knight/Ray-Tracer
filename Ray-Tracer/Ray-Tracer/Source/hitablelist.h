#pragma once

#include "Intersection.h"

class hitable_list :public Intersection
{
public:

	hitable_list(){}
	hitable_list(Intersection **l,int n)
	{
		Ilist = l;
		list_size = n;
	}

	virtual bool hit(Ray& ray, float t_min, float t_max, hit_record& rec) const;

private:
	Intersection ** Ilist;
	int list_size;

};


bool hitable_list::hit(Ray & ray,float t_min, float t_max, hit_record & rec) const
{
	hit_record temp_rec;

	bool IsHit = false;
	double closest_so_far = t_max;

	for (int i = 0; i < list_size; ++i)
	{
		if (Ilist[i]->hit(ray, t_min, closest_so_far, temp_rec))
		{
			IsHit = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return IsHit;
}