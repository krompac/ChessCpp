#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int x, int y, Color color) : x(x), y(y), color(color), width(-1), height(-1)
{
}

GameObject::GameObject(int x, int y, int width, int height, Color color) : x(x), y(y), width(width), height(height), color(color)
{
}

GameObject::~GameObject()
{
}

