
#include "pch.h"
#include "Source/Ray.h"
#include "Source/hitablelist.h"
#include "Source/Shapes.h"
#include "Source/Camera.h"

glm::vec3 random_point_sphere()
{
	glm::vec3 p;

	do {
		p =  2.0f * glm::vec3(getRandomNumber(), getRandomNumber(), getRandomNumber()) - glm::vec3(1, 1, 1);
	} while (vector_square(p) >= 1.0);

	return p;
}

glm::vec3 GetColor( Ray& ray,Intersection* world)
{
	hit_record rec;

	float sphere_radius		= 0.5;
	glm::vec3 sphere_color	= glm::vec3(1.0, 0.5, 0.5);
	glm::vec3 sphere_center = glm::vec3(0, 0, -1);

	if (world->hit(ray, 0.0, INFINITY, rec))
	{
		glm::vec3 target = rec.point_intersection + rec.Normal + random_point_sphere();
		return 0.5f * GetColor( &Ray(rec.point_intersection,target - rec.point_intersection), world);//glm::vec3(rec.Normal.x + 1, rec.Normal.y + 1, rec.Normal.z + 1);
	}
	else
	{
		//Draw Rest of the Scene
		glm::vec3 unit_dir = Normalize(ray.getDirection());
		float interpolate_value = 0.5*((unit_dir.y) + 1.0);

		return Lerp(glm::vec3(1.0, 1.0, 1.0), glm::vec3(0.5, 0.7, 1.0), interpolate_value);
	}

	//float t = Sphere_hit(sphere_center, sphere_radius, ray);
	//if (t > 0.0)
	//{
	//	//N = P-C
	//	glm::vec3 N = Normalize(ray.PointRayIntersection(t) - sphere_center);
	//	return 0.5f*glm::vec3(N.x + 1, N.y + 1, N.z + 1);
	//}
		
}


int main()
{
	int pass_count = 0;
	std::ofstream outfile;
	outfile.open("Output_Image.ppm", std::ios::out|std::ios::trunc);
	outfile << "P3" << std::endl << IMAGE_WIDTH << " " << IMAGE_HEIGHT << std::endl << "255" << std::endl;

	//==========================================================================
	//==========================================================================


	glm::vec3 lower_left_corner(-2.0, -1.0, -1.0);
	glm::vec3 horizontal(4.0,0.0,0.0);
	glm::vec3 vertical(0.0,2.0,0.0);
	glm::vec3 origin(0.0,0.0,0.0); 

	Intersection *list[2];
	list[0] = new Sphere(glm::vec3(-0.2, 0, -1), 0.15);
	list[1] = new Sphere(glm::vec3( 0.2, 0, -1), 0.15);

	Intersection* world = new hitable_list(list, 2);
	Camera cam;

	for (int j = IMAGE_HEIGHT -1; j >= 0; j--)
	{
		for (int i = 0; i < IMAGE_WIDTH; i++)
		{
			//float r = (float)(i) / (float) (IMAGE_WIDTH);
			//float g = (float)(j) / (float) (IMAGE_HEIGHT);
			//float b = 0.2;
		
			glm::vec3 getColor(0, 0, 0);
			
			for (int s = 0; s < SAMPLE_COUNT; ++s)
			{
				float u = float(i + getRandomNumber()) / (float)IMAGE_WIDTH;
				float v = float(j + getRandomNumber()) / (float)IMAGE_HEIGHT;
				

				 Ray ray = cam.get_Ray(u, v);
				
				getColor += GetColor(ray, world);

			}

			//Anti Aliasing take avg of the pixel sample count

			getColor /= float(SAMPLE_COUNT);

			//Ray ray(origin, lower_left_corner + u * horizontal + v * vertical);
			
			
			int ir = int(255.99 * getColor.x);
			int ig = int(255.99 * getColor.y);
			int ib = int(255.99 * getColor.z);

			outfile << ir << " " << ig << " " << ib << std::endl;
			
		}

	}

	//==========================================================================

	
	system("Pause");
	return 0;
}