#pragma once

//#pragma warning(disable:4996)

//===========================
//Include
//===========================

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

//GLM
#include "Dependencies/GLM/glm/glm/vec3.hpp"
#include "Dependencies/GLM/glm/glm/vec4.hpp"
#include "Dependencies/GLM/glm/glm/mat4x4.hpp"
#include "Dependencies/GLM/glm/glm/gtc/matrix_transform.hpp"


//===========================
//Constants
//===========================

#define IMAGE_WIDTH  500//1920
#define IMAGE_HEIGHT 300//1080



struct Color3f
{
	float r;
	float g;
	float b;

	Color3f()
	{
		r = 0;
		g = 0;
		b = 0;
	}

	Color3f(float tr, float tg, float tb)
	{
		r = tr;
		g = tg;
		b = tb;
	}
};