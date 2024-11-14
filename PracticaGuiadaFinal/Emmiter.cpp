#include "Emmiter.h"
#include <iostream>

const double PI = 3.14159265358979;

void Emmiter::SetParticle(Solid* particle)
{
	config.setParticle(particle);
}

void Emmiter::AddParticle(Solid* particle)
{
	particles.push_back(particle);
}

void Emmiter::Render()
{
	for (auto& particle : particles)
	{
		particle->Render();
	}
}
void Emmiter::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	for (auto& particle : particles)
	{
		particle->Update();
	}

	if ((currentTime.count() - initialMilliseconds.count()) - this->lastUpdateTime > this->config.getEmissionPeriod())
	{
		if(particles.size() < config.getParticleNum())
		{
			Solid* newParticle = config.getParticle()->Clone();

			newParticle->SetCoordinates(Vector3D(0,0,-2));
			newParticle->SetColor(randColor());
			newParticle->SetOrientation(randVecBinary());
			newParticle->SetOrientationSpeed(randVecBinary());
			newParticle->SetSpeed(particleSpeeds[current]);

			AddParticle(newParticle);
			current++;
			std::cout << current << std::endl;
		}
	}

	this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
}

Emmiter* Emmiter::Clone()
{
	return new Emmiter(*this);
}

Vector3D randVecBinary()
{
	return Vector3D(rand() % 2, rand() % 2, rand() % 2);
}

Color randColor()
{
	return Color((rand() % 256) / 255, (rand() % 256) / 255, (rand() % 256) / 255);
}

std::vector<Vector3D> Emmiter::circleSpeeds()
{
	int numParticles = config.getParticleNum();
	std::vector<Vector3D> speeds;
	float angle = 2 * PI / numParticles;
	 
	for (int i = 0; i < numParticles; i++)
	{
		float theta = i * angle;
		
		speeds.push_back(Vector3D(0.1 * cos(theta), 0.1 * sin(theta), 0));
	}

	return speeds;
}