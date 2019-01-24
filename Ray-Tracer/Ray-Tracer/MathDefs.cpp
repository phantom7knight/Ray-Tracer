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
		return (( right.x * right.x) + (right.y * right.y) + (right.z * right.z));
	}


	float dotProduct(glm::vec3 A, glm::vec3 B)
	{
		return (A.x*B.x + A.y*B.y + A.z*B.z);
	}

	double getRandomNumber()
	{
		auto num = rand(); 
		return ((double)num / RAND_MAX);
	}

	glm::vec3 random_point_sphere()
	{
		glm::vec3 p;

		do
		{
			auto a = (float)getRandomNumber();
			auto b = (float)getRandomNumber();
			auto c = (float)getRandomNumber();
			p = 2.0f * glm::vec3(a, b, c) - glm::vec3(1, 1, 1);
		} while (vector_square(p) >= 1.0);

		return p;
	}

	float Length(glm::vec3 right)
	{
		return (sqrt(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]));
	}