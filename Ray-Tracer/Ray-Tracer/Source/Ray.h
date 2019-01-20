#pragma once


class Ray
{
public:
	Ray() {}

	Ray(const glm::vec3& origin, const glm::vec3& direction);
	
	~Ray()
	{
	}

	inline glm::vec3 getOrigin();
	inline glm::vec3 getDirection();

	glm::vec3 PointRayIntersection(float t);
private:

	glm::vec3 m_rayDir;
	glm::vec3 m_rayOrigin;

};


inline glm::vec3 Ray::getOrigin()
{
	return m_rayOrigin;
}

inline glm::vec3 Ray::getDirection()
{
	return m_rayDir;
}