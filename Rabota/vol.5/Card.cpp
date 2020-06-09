
#include <SFML\Graphics.hpp>
#include"Card.h"

sf::Sprite Card::getSprite()
{
	return sprite;
}
void Card::setSprite(sf::Sprite spr)
{
	sprite = spr;
}

int Card::getScore()
{
	return score;
}
void Card::setScore(int score)
{
	this->score = score;
}

char Card::getName()
{
	return name;
}
void Card::setName(char name)
{
	this->name = name;
}

int Card::getFlag_vzali()
{
	return flag_vzali;
}
void Card::setFlag_vzali(int flag)
{
	this->flag_vzali = flag;
}
