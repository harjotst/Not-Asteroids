#include "Laser.h"

Laser::Laser(Vector2f pos, const string& file) : Entity(pos, file)
{}

Laser::~Laser()
{
	cout << "Destroyed Laser\n";
}

void Laser::Update()
{
	this->m_Pos.y -= 0.7f;
	this->m_Sprite.setPosition(this->m_Pos);
}

void Laser::Render(RenderWindow* window)
{
	window->draw(this->m_Sprite);
}
