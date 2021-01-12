#include "SpaceObjects.h"

SpaceObjects::SpaceObjects()
{
	time(0);
}

SpaceObjects::~SpaceObjects()
{
	vector<Entity*>::iterator iter;
	
	for (iter = this->m_Asteroids.begin(); iter != this->m_Asteroids.end(); ++iter)
	{
		delete *iter;
		*iter = 0;
	}

	this->m_Asteroids.erase(this->m_Asteroids.begin(), this->m_Asteroids.end());

	for (iter = this->m_Lasers.begin(); iter != this->m_Lasers.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}

	this->m_Lasers.erase(this->m_Lasers.begin(), this->m_Lasers.end());
}

//void SpaceObjects::AddStar()
//{
//	float randX = float(rand() % 700);
//	Entity* star = new Star(Vector2f(randX, -100.0f), "Textures/star.png");
//	this->m_Objects.push_back(star); 
//}

void SpaceObjects::AddAsteroid()
{
	float randX = float(rand() % 700);
	Entity* asteroid = new Asteroid(Vector2f(randX, -100.0f), "Textures/asteroid.png");
	this->m_Asteroids.push_back(asteroid); 
} 

void SpaceObjects::AddLaser(Vector2f pos)
{
	Entity* laser = new Laser(pos, "Textures/laser.png");
	this->m_Lasers.push_back(laser);
}

void SpaceObjects::AddSpaceObjects(Clock* clock)
{
	if (clock->getElapsedTime().asSeconds() > 1.5f)
	{
		AddAsteroid();
		clock->restart();
	}
}

void SpaceObjects::DestroySpaceObjects(vector<Entity*>& m_Objects)
{
	vector<Entity*>::iterator iter;

	for (iter = m_Objects.begin(); iter != m_Objects.end(); ++iter)
	{
		if ((*iter)->GetPos().y > 800.0f || (*iter)->GetPos().y < -100.0f)
		{
			delete* iter;
			*iter = 0;
		}
	}

	while (true)
	{
		iter = find(m_Objects.begin(), m_Objects.end(), nullptr);
		if (iter != m_Objects.end())
			m_Objects.erase(iter);
		else
			break;
	}
}

void SpaceObjects::Update(Clock* clock)
{	
	vector<Entity*>::iterator iter;

	this->DestroySpaceObjects(this->m_Asteroids);
	this->DestroySpaceObjects(this->m_Lasers);
	this->CheckCollisions();
	this->AddSpaceObjects(clock);

	for (iter = this->m_Asteroids.begin(); iter != this->m_Asteroids.end(); ++iter)
	{
		(*iter)->Update();
	}

	for (iter = this->m_Lasers.begin(); iter != this->m_Lasers.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void SpaceObjects::Render(RenderWindow* window)
{
	vector<Entity*>::iterator iter;

	for (iter = this->m_Asteroids.begin(); iter != this->m_Asteroids.end(); ++iter)
	{
		(*iter)->Render(window);
	}

	for (iter = this->m_Lasers.begin(); iter != this->m_Lasers.end(); ++iter)
	{
		(*iter)->Render(window);
	}
}

void SpaceObjects::CheckCollisions()
{
	vector<Entity*>::iterator laser;
	vector<Entity*>::iterator asteroid;

	for (laser = this->m_Lasers.begin(); laser != this->m_Lasers.end(); ++laser)
	{
		for (asteroid = this->m_Asteroids.begin(); asteroid != this->m_Asteroids.end(); ++asteroid)
		{
			if (((*laser)->GetPos().x > (*asteroid)->GetPos().x) && ((*laser)->GetPos().x < ((*asteroid)->GetPos().x + 100.0f)) &&
 				((*laser)->GetPos().y > (*asteroid)->GetPos().y) && ((*laser)->GetPos().y < ((*asteroid)->GetPos().y + 100.0f)))
			{
				delete *laser;
				*laser = 0;
				delete *asteroid;
				*asteroid = 0;
				break;
			}
		}
	}

	while (true)
	{
		laser = find(this->m_Lasers.begin(), this->m_Lasers.end(), nullptr);
		if (laser != this->m_Lasers.end())
			this->m_Lasers.erase(laser);
		else
			break;
	}

	while (true)
	{
		asteroid = find(this->m_Asteroids.begin(), this->m_Asteroids.end(), nullptr);
		if (asteroid != this->m_Asteroids.end())
			this->m_Asteroids.erase(asteroid);
		else
			break;
	}
}