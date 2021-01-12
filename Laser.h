#pragma once
#include "Entity.h"
class Laser : public Entity
{
public:
	Laser(Vector2f pos, const string& file);
	virtual ~Laser();
	virtual void Update();
	virtual void Render(RenderWindow* window);
};
