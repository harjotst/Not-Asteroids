#include "Game.h"

// Initializer Functions
void Game::InitWindow()
{

	this->m_Window = new RenderWindow(VideoMode(800, 600), "Asteroid Clone");
}

void Game::InitStates()
{
	this->m_MenuState = new MenuState();
	this->m_GameState = new GameState();

	this->m_States.push(this->m_MenuState);
	this->m_States.push(this->m_GameState);
}

// Constructor & Destructor
Game::Game()
{
	this->InitWindow();
	this->InitStates();
}

Game::~Game()
{
	// We are Deleting the Render Window Object since it's Memory is on the Heap
	delete this->m_Window;
	this->m_Window = 0;

	// We are Deleting the Menu State Object since it's Memory is on the Heap
	delete this->m_MenuState;
	this->m_MenuState = 0;

	// We are Deleting the Game State Object since it's Memory is on the Heap
	delete this->m_GameState;
	this->m_GameState = 0;
}

// Member Function

void Game::Run()
{
	while (this->m_Window->isOpen())
	{
		this->Update();
		this->Render();
	}
}

void Game::Update()
{
	this->Events();
	if (!this->m_States.empty())
		this->m_States.top()->Update(&this->m_Clock); 
}

void Game::Render()
{
	// Clear Render Window for Redraw
	this->m_Window->clear();

	// Draw on RenderWindow
	if (!this->m_States.empty())
		this->m_States.top()->Render(this->m_Window);

	// Display Render Window
	this->m_Window->display();
}

void Game::Events()
{
	while (this->m_Window->pollEvent(m_Event))
	{
		if (this->m_Event.type == Event::Closed)
		{
			if (this->m_States.top() == this->m_GameState)
			{
				this->m_States.pop(); 
			}
			else
			{
				this->m_Window->close();
			}
		}

		if (this->m_Event.type == Event::KeyPressed)
		{
			this->m_GameState->Events(&this->m_Event);
		}
	}
}