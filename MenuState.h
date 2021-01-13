#pragma once
#include "State.h"

#include <iostream>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class MenuState : public State
{
public:
	MenuState();
	virtual ~MenuState();
	virtual void Events(Event* event);
	virtual void Update(Clock* clock);
	virtual void Render(RenderWindow* window);
};

