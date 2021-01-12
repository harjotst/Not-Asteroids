#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class State
{
public:
	// Constructors & Destructors
	State();
	virtual ~State();
	// Member Functions
	virtual void Events(Event* event) = 0;
	virtual void Update(Clock* clock) = 0;
	virtual void Render(RenderWindow* window) = 0;
};

#endif // !STATE_H
