#include "Game.h"
#include <iostream>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	std::cout << "Tecla pulsada: " << key << std::endl;

	//GetCuboid().SetColor(Color()); LLAMA A UNA INSTANCIA

}

void Game::ProcessMouseMovement(int x, int y)
{
	std::cout << "Movimiento del mouse: " << x << ", " << y << std::endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	std::cout << "Clic: " << button << std::endl;

}

void Game::Init()
{
	srand(static_cast<unsigned int>(std::time(nullptr)));

	Cube CubePrototype = Cube(Vector3D(0,0,-2),Color(1,0,0),Vector3D(0,0,0),2);

	Cube* Particle = CubePrototype.Clone();
	
	emmiter.SetParticle(Particle);

}

void Game::Render()
{
	scene.Render();
	emmiter.Render();
}

void Game::Update()
{
	emmiter.Update();
	scene.Update();
}