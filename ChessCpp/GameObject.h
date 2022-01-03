#pragma once
#include "raylib.h"

class GameObject
{
	protected:
		int x;
		int y;
		int width;
		int height;
		Color color;

	public:
		GameObject();
		GameObject(int x, int y, Color color);
		GameObject(int x, int y, int width, int height, Color color);

		~GameObject();
};

