#include "Entity.h"

// Initilizer Functions
void Entity::InitTexture(const string& file)
{
	if (!this->m_Texture.loadFromFile(file))
	{
		cout << "Failed to Load File: " << file << "\n";
	}
	else
	{
		this->m_Texture.setRepeated(false);
		this->m_Texture.setSmooth(true);
	}
}

void Entity::InitSprite()
{ 
	this->m_Sprite.setTexture(this->m_Texture);
	this->m_Sprite.setPosition(this->m_Pos); 
}

// Constructor
Entity::Entity(Vector2f pos, const string& file)
{
	this->m_Pos.x = pos.x;
	this->m_Pos.y = pos.y;

	this->InitTexture(file);
	this->InitSprite();
}

Entity::~Entity()
{
	cout << "Entity Destroyed\n";
}

void Entity::Events(Event* event)
{
}

Vector2f& Entity::GetPos()
{
	return this->m_Pos;
}
