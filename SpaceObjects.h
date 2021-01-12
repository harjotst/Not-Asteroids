#pragma once

#include <ctime>
#include <cstdlib>

#include "Entity.h"
#include "Star.h"
#include "Asteroid.h"
#include "Laser.h"

class SpaceObjects
{
private:
	// Data Members & Functions
	vector<Entity*> m_Asteroids;
	vector<Entity*> m_Lasers;
public:
	// Constructors & Destructors
	SpaceObjects();
	~SpaceObjects();
	void Update(Clock* clock);
	void Render(RenderWindow* window);
	void AddSpaceObjects(Clock* clock);
	void DestroySpaceObjects(vector<Entity*>& m_Objects);
	// void AddStar();
	void AddAsteroid();
	void AddLaser(Vector2f pos);
	void CheckCollisions();
};

