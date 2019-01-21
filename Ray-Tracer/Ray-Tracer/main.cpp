
#include "pch.h"
#include "Source/Ray.h"

glm::vec3 Normalize(glm::vec3 right)
{
	return  right / (sqrt(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]));
}

glm::vec3 Lerp(glm::vec3 A, glm::vec3 B, float t)
{
	return (1 - t)*A + t * B;
}


glm::vec3 GetColor( Ray& ray)
{
	glm::vec3 unit_dir = Normalize(ray.getDirection());
	float interpolate_value = 0.5*(unit_dir.y) + 1.0;
	return Lerp(glm::vec3(1.0, 1.0, 1.0), glm::vec3(0.5, 0.7, 1.0), interpolate_value);
}


int main()
{
	int pass_count = 0;
	std::ofstream outfile;
	outfile.open("Output_Image.ppm", std::ios::out|std::ios::trunc);

	int nx = 200;
	int ny = 100;

	outfile << "P3" << std::endl << IMAGE_WIDTH << " " << IMAGE_HEIGHT << std::endl << "255" << std::endl;

	//==========================================================================
	//==========================================================================


	glm::vec3 lower_left_corner(-2.0, -1.0, -1.0);
	glm::vec3 horizontal(4.0,0.0,0.0);
	glm::vec3 vertical(0.0,2.0,0.0);
	glm::vec3 origin(0.0,0.0,0.0); 
	
	for (int j = IMAGE_HEIGHT -1; j >= 0; j--)
	{
		for (int i = 0; i < IMAGE_WIDTH; i++)
		{
			float r = (float)(i) / (float) (IMAGE_WIDTH);
			float g = (float)(j) / (float) (IMAGE_HEIGHT);
			float b = 0.2;

			float u = float(i) / (float)IMAGE_WIDTH;
			float v = float(j) / (float)IMAGE_HEIGHT;

			Ray ray(origin, lower_left_corner + u * horizontal + v * vertical);
			glm::vec3 getColor = GetColor(ray);// glm::vec3(r, g, b);
			
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