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
#include <random>
#include <cstdlib>



//GLM
#include "Dependencies/GLM/glm/glm/vec3.hpp"
#include "Dependencies/GLM/glm/glm/vec4.hpp"
#include "Dependencies/GLM/glm/glm/mat4x4.hpp"
#include "Dependencies/GLM/glm/glm/gtc/matrix_transform.hpp"

#include "MathDefs.h"

//===========================
//Constants
//===========================

//Test Width 1
#define testX_1 1920 
#define testX_2 200

//Test Width 2
#define testY_1 1080 
#define testY_2 100 

#define IMAGE_WIDTH  testX_1
#define IMAGE_HEIGHT testY_1

#define SAMPLE_COUNT 10



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
