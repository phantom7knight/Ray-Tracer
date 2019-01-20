
#include "pch.h"
#include "Source/Ray.h"

glm::vec3 Normalize(glm::vec3 right)
{
	return  right / (sqrt(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]));
}
glm::vec3 Color( Ray& ray)
{
	glm::vec3 unit_dir = Normalize(ray.getDirection());
	float interpolate_value = 0.5*(unit_dir.y) + 1.0;
	return (1.0 - interpolate_value) * (glm::vec3(1.0, 1.0, 1.0) )+ interpolate_value * (glm::vec3(0.55, 0.7, 1.0));
	
}


int main()
{
	int pass_count = 0;
	std::ofstream outfile("Output_Image.ppm", std::ios_base::out);

	outfile << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

	//==========================================================================
	//==========================================================================


	glm::vec3 lower_left_corner(-2.0, -1.0, -1.0);
	glm::vec3 horizontal(4.0,0.0,0.0);
	glm::vec3 vertical(0.0,2.0,0.0);
	glm::vec3 origin(0.0,0.0,0.0);
	
	for (int j = IMAGE_HEIGHT; j > 0; j--)
	{
		for (int i = 0; i < IMAGE_WIDTH; ++i)
		{
			//float r = (float)(j) / (float) (IMAGE_WIDTH);
			//float g = (float)(i) / (float) (IMAGE_HEIGHT);
			//float b = 0.5;

			float u = float(i) / (float)IMAGE_WIDTH;
			float v = float(j) / (float)IMAGE_HEIGHT;

			Ray ray(origin, lower_left_corner + u * horizontal + v * vertical);
			glm::vec3 getColor = Color(ray);
			glm::vec3 col(r, g, b);

			int colorr = int(255.99 * col.x);
			int colorg = int(255.99 * col.y);
			int colorb = int(255.99 * col.z);

			outfile << colorr << " " << colorg << " " << colorr << "\n";
			
		}

		++pass_count;
		std::cout << pass_count << std::endl;
	}

	//==========================================================================

	
	system("Pause");
	return 0;
}