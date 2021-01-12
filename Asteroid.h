#pragma once

#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid(Vector2f pos, const string& text);
	virtual ~Asteroid();
	virtual void Update();
	virtual void Render(RenderWindow* window);
};

