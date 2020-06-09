#pragma once
#include <SFML\Graphics.hpp>
#include "Card.h"

class Game
{
	int score_player = 0;
	int	score_opponent1 = 0;
	int	score_opponent2 = 0;
	Card* koloda;
	int nominal;
	int gamers;
	int random;
	Card tmp;
public:
	~Game();
	int kolvo;
	void setScore_player(int score);


		int getScore_player();


		void setScore_opponent1(int score);

		int getScore_opponent1();

		void setScore_opponent2(int score);

		int getScore_opponent2();

		int getGamers();

		void make_deck();

		void peremewat();

		int proverka(int player, int opponent, int diller);

		int proverka(int player, int opponent1, int opponent2, int diller);

		char takeCard(int cmp);

		void setFlag(int tmp, int flag);

		int getFlag(int tmp);

		Sprite showSprite(int cmp);
		void settSprite(int i, Sprite sprit);

		void Position(int i, int x, int y);
};
