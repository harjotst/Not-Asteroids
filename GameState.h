#pragma once

#include "State.h"
#include "Entity.h"
#include "Player.h"
#include "SpaceObjects.h"

#include <iostream>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class GameState :public State
{
private:
	Entity* m_Player;
	SpaceObjects* m_SpaceObjects;
public:
	GameState(); 
	virtual ~GameState();
	virtual void Events(Event* event);
	virtual void Update(Clock* clock); 
	virtual void Render(RenderWindow* window);
};

