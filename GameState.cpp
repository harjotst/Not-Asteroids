#include "GameState.h"

GameState::GameState()
{
	this->m_SpaceObjects = new SpaceObjects();
	this->m_Player = new Player(Vector2f(350.0f, 450.0f), this->m_SpaceObjects, "Textures/x-wing.png");
}

GameState::~GameState()
{
	// Deleting Player Object since it has Memory in Heap
	delete this->m_Player;
	this->m_Player = 0;
	// Deleting SpaceObjects Object since it has Memory in Heap
	delete this->m_SpaceObjects;
	this->m_SpaceObjects = 0;
}

void GameState::Events(Event* event)
{
	this->m_Player->Events(event);
}

void GameState::Update(Clock* clock)
{
	this->m_SpaceObjects->Update(clock); 
	this->m_Player->Update();
}

void GameState::Render(RenderWindow* window)
{
	this->m_Player->Render(window);
	this->m_SpaceObjects->Render(window);
}
