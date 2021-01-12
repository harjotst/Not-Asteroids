#include "Player.h"

Player::Player(Vector2f pos, SpaceObjects* spaceObject, const string& text) : Entity(pos, text)
{
	this->m_SpaceObjects = spaceObject;
}

Player::~Player()
{}

void Player::Events(Event* event)
{
	if (event->key.code == Keyboard::Up)
	{
		this->m_Pos.y -= 12.0f;
		cout << "Up\n";
	}
	if (event->key.code == Keyboard::Down)
	{
		this->m_Pos.y += 12.0f;
		cout << "Down\n";
	}
	if (event->key.code == Keyboard::Left)
	{
		this->m_Pos.x -= 12.0f;
		cout << "Left\n";
	}
	if (event->key.code == Keyboard::Right)
	{
		this->m_Pos.x += 12.0f;
		cout << "Right\n";
	}
	if (event->key.code == Keyboard::Space)
	{
		this->m_SpaceObjects->AddLaser(Vector2f(this->m_Pos.x + 20.0f, this->m_Pos.y - 65.0f)); 
	}
}

void Player::Update() 
{
	this->m_Sprite.setPosition(this->m_Pos);
}

void Player::Render(RenderWindow* window)
{
	window->draw(this->m_Sprite);
}
