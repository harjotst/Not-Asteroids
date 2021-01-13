#include "Star.h"

Star::Star(Vector2f pos, const string& file): Entity(pos, file)
{}

Star::~Star()
{
	cout << "Star Destroyed\n";
}

void Star::Update()
{
	this->m_Pos.y += 0.08f;
	this->m_Sprite.setPosition(this->m_Pos);
}

void Star::Render(RenderWindow* window)
{
	window->draw(this->m_Sprite);
}
