#pragma once

#include "Entity.h"
#include "SpaceObjects.h"

#include <iostream>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Player : public Entity
{
private:
	SpaceObjects* m_SpaceObjects;
public:
	Player(Vector2f pos, SpaceObjects* spaceObject, const string& text);
	virtual ~Player();
	void Events(Event* event);
	virtual void Update();
	virtual void Render(RenderWindow* window);
};

