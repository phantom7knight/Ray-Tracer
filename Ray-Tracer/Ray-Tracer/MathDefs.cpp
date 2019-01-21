#pragma once
#include "MathDefs.h"



	glm::vec3 Normalize(glm::vec3 right)
	{
		return  right / (sqrt(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]));
	}

	glm::vec3 Lerp(glm::vec3 A, glm::vec3 B, float t)
	{
		return (1 - t)*A + t * B;
	}

	float vector_square(glm::vec3 right)
	{
		return (right.x * right.x + right.y * right.y + right.z * right.z);
	}


	float dotProduct(glm::vec3 A, glm::vec3 B)
	{
		return (A.x*B.x + A.y*B.y + A.z*B.z);
	}

	double getRandomNumber()
	{
		return rand() / RAND_MAX;
	}