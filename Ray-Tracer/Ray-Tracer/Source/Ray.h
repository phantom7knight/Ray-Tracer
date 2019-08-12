#pragma once


class Ray
{
public:
	Ray() {}

	Ray(const glm::vec3& origin, const glm::vec3& direction);
	
	~Ray()
	{
	}

	inline glm::vec3 getOrigin() const ;
	inline glm::vec3 getDirection()const;

	glm::vec3 PointRayIntersection(float t)const;

private:

	glm::vec3 m_rayDir;
	glm::vec3 m_rayOrigin;

};


inline glm::vec3 Ray::getOrigin() const
{
	return m_rayOrigin;
}

inline glm::vec3 Ray::getDirection()const
{
	return m_rayDir;
}