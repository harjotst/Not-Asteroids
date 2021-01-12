#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Entity
{
protected:
	Texture m_Texture;
	Sprite m_Sprite;
	Vector2f m_Pos;
	void InitTexture(const string& file); 
	void InitSprite(); 
public:
	// Constructors & Destructors
	Entity(Vector2f pos, const string& file);
	virtual ~Entity();
	// Member Functions
	void virtual Events(Event* event);
	virtual void Update() = 0;
	virtual void Render(RenderWindow* window) = 0;
	Vector2f& GetPos();
};

#endif // !ENTITY_H
