#include "juego.h"

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

using namespace sf;

namespace Juego
{
	Texture texture;
	Sprite sprite;

	static void cargarTextura()
	{
		texture.loadFromFile("res/xd.png");
		sprite.setTexture(texture);
	}

	static void setSpriteConf()
	{
		sprite.setPosition(90.f, 90.f);
	}

	void initSprite()
	{
		cargarTextura();
		setSpriteConf();
	}

	Sprite drawSprite()
	{
		return sprite;
	}
}