#pragma once

	using namespace sf;
	class Card
	{
		char name;
		int score;
		int number;
		int flag_vzali = 0;
		Sprite sprite;
	public:
		Sprite getSprite();
		void setSprite(Sprite spr);

		int getScore();
		void setScore(int score);

		char getName();
		void setName(char name);

		int getFlag_vzali();
		void setFlag_vzali(int flag);
	};
