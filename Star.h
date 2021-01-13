#pragma once
#include "Entity.h"
class Star : public Entity
{
public:
	Star(Vector2f pos, const string& file);
	virtual ~Star();
	virtual void Update();
	virtual void Render(RenderWindow* window);
};

