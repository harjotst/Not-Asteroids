#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stack>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "State.h"
#include "MenuState.h"
#include "GameState.h"

using namespace std;
using namespace sf;

class Game 
{
private: 
	// This is the SFML RenderWindow Object the Game Uses to Render Graphics
	RenderWindow* m_Window;
	// This is the SFML Event used to Keep Track of Events
	Event m_Event;
	// This is the SFML Clock used to Keep Track of Time
	Clock m_Clock; 
	// States Stack
	stack<State*> m_States;
	// Menu State
	State* m_MenuState;  
	// Game State
	State* m_GameState;
	// InitWindow Initializes the Render Window
	void InitWindow();
	// InitStates Initializes the States of the Game
	void InitStates();
public:
	// Constructor & Destructor
	Game();
	~Game();
	// Member Functions
	void Run();
	void Update();
	void Render();
	void Events();
};

#endif 