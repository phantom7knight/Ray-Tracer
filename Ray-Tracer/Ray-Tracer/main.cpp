
#include "pch.h"
#include "Source/Ray.h"
#include "Source/hitablelist.h"
#include "Source/Shapes.h"
#include "Source/Camera.h"
#include "Source/Material.h"

//=============================================================
//Get the Color on each Pixel after being ray traced
//=============================================================
glm::vec3 GetColor(const Ray& ray,Intersection* world,int depth)
{
	hit_record rec;

	
	if (world->hit(ray, 0.001f, INFINITY, rec))
	{
		Ray scattered;
		glm::vec3 attenuation = glm::vec3(1,0,1);
		if (depth < 50 && rec.material_ptr->scatter(ray, rec, attenuation, scattered))
		{
			return attenuation * GetColor(scattered, world, depth + 1);
		}
		else
		{
			return glm::vec3(0, 0, 0);
		}
		
		//To print normal Color's of the scene sphere's
		//return 0.5f * glm::vec3(rec.Normal.x + 1, rec.Normal.y + 1, rec.Normal.z + 1);
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


	Intersection *list[4];
	list[0] = new Sphere(glm::vec3(0, 0, -1), 0.5f, new Lambertian(glm::vec3(0.8, 0.3, 0.3)));
	list[1] = new Sphere(glm::vec3( 0,-100,-1), 100, new Lambertian(glm::vec3(0.8, 0.8, 0.0)));
	list[2] = new Sphere(glm::vec3( 1.0, 0, -1), 0.5, new Metal(glm::vec3(0.8, 0.6, 0.2)));
	list[3] = new Sphere(glm::vec3( -1.0, 0, -1), 0.15, new Lambertian(glm::vec3(0.8, 0.8, 0.8)));

	Intersection* world = new hitable_list(list, 4);
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
				glm::vec3 p = ray.PointRayIntersection(2.0);
				getColor += GetColor(ray, world,0);

			}

			getColor /= float(SAMPLE_COUNT);

			//Ray ray(origin, lower_left_corner + u * horizontal + v * vertical);
			getColor = glm::vec3(sqrt(getColor.x), sqrt(getColor.y), sqrt(getColor.z));
			
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