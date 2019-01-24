#pragma once
#include "pch.h"


double getRandomNumber();
glm::vec3 Normalize(glm::vec3 right);
glm::vec3 Lerp(glm::vec3 A, glm::vec3 B, float t);
float vector_square(glm::vec3 right);
float dotProduct(glm::vec3 A, glm::vec3 B);
glm::vec3 random_point_sphere();