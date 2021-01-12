#include "Asteroid.h"

Asteroid::Asteroid(Vector2f pos, const string& text) : Entity(pos, text)
{}

Asteroid::~Asteroid()
{
	cout << "Asteroid Destroyed\n";
}


void Asteroid::Update()
{
	this->m_Pos.y += 0.04f;
	this->m_Sprite.setPosition(this->m_Pos);
}

void Asteroid::Render(RenderWindow* window)
{
	window->draw(this->m_Sprite);
}
