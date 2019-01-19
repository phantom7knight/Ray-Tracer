
#include "pch.cpp"

//This Function emits the basic RGB color based on position

void BasicColor()
{
	for (int i = IMAGE_HEIGHT - 1; i > 0; --i)
	{
		for (int j = 0 ; j < IMAGE_WIDTH; ++j)
		{
			float r = (float)(i / IMAGE_WIDTH);
			float g = (float)(j / IMAGE_HEIGHT);
			float b = 0.5f;

			glm::vec3 color_test(r, g, b);

			int colorr = int(255 * color_test.x);
			int colorg = int(255 * color_test.y);
			int colorb = int(255 * color_test.z);
		}
	}
}

int main()
{
	
	//Basic Color Function
	BasicColor();





	system("Pause");
	return 0;
}