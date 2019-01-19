#include "../pch.h"
#include "../Source/Ray.h"



Ray::Ray(const glm::vec3 & origin, const glm::vec3 & direction)
{
	m_rayOrigin		= origin;
	m_rayDir		= direction;


}