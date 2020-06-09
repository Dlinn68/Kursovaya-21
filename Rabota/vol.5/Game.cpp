
#include<iostream>
#include<fstream>
#include"Game.h"
#include"Card.h"

using namespace sf;

	
	Game::~Game() { delete[] koloda; }
	int kolvo;
	void Game::setScore_player(int score)
	{
		score_player = score;
	}

	int Game::getScore_player()
	{
		return score_player;
	}

	void Game::setScore_opponent1(int score)
	{
		score_opponent1 = score;
	}

	int Game::getScore_opponent1()
	{
		return score_opponent1;
	}

	void Game::setScore_opponent2(int score)
	{
		score_opponent2 = score;
	}

	int Game::getScore_opponent2()
	{
		return score_opponent2;
	}

	int Game::getGamers()
	{
		return gamers;
	}

	void Game::make_deck()
	{
		int vibor;
		std::cout << "1) Enter" << std::endl << "2) Enter from file" << std::endl;
		std::cin >> vibor;

		if (vibor == 1)
		{
			std::cout << "Vvedite kol-vo kart (ne men`we 14)" << std::endl;
			std::cin >> kolvo;
		}
		if (vibor == 2)
		{
			std::ifstream fin;
			fin.open("File.txt");
			if (!fin.is_open())
				std::cout << "Error open file" << std::endl;
			else
			{
				std::string str;

				str = "";
				std::getline(fin, str);
				kolvo = std::atoi(str.c_str());
				str = "";
				std::getline(fin, str);
				gamers = std::atoi(str.c_str());
			}
			fin.close();
		}
		if (kolvo < 14)
		{
			std::cout << "slishkom malen`kaya koloda ili vvedeni necorrektniye danniye" << std::endl;
			std::cout << "Pojalusta, zakroyte programmu" << std::endl;
			system("pause");
		}
		koloda = new Card[kolvo];
		for (int i = 0; i < kolvo; i++)
		{
			nominal = i;
			switch (nominal % 14)
			{
			case(0):
				koloda[i].setName('1');
				koloda[i].setScore(1);

				break;
			case(1):
				koloda[i].setName('2');
				koloda[i].setScore(2);

				break;
			case(2):
				koloda[i].setName('3');
				koloda[i].setScore(3);
				break;
			case(3):
				koloda[i].setName('4');
				koloda[i].setScore(4);
				break;
			case(4):
				koloda[i].setName('5');
				koloda[i].setScore(5);
				break;
			case(5):
				koloda[i].setName('6');
				koloda[i].setScore(6);
				break;
			case(6):
				koloda[i].setName('7');
				koloda[i].setScore(7);
				break;
			case(7):
				koloda[i].setName('8');
				koloda[i].setScore(8);
				break;
			case(8):
				koloda[i].setName('9');
				koloda[i].setScore(9);
				break;
			case(9):
				koloda[i].setName('10');
				koloda[i].setScore(10);
				break;
			case(10):
				koloda[i].setName('V');
				koloda[i].setScore(2);
				break;
			case(11):
				koloda[i].setName('D');
				koloda[i].setScore(3);
				break;
			case(12):
				koloda[i].setName('K');
				koloda[i].setScore(4);
				break;
			case(13):
				koloda[i].setName('T');
				koloda[i].setScore(11);
				break;
			}
		}
		for (int i = 0; i < kolvo; i++)
		{
			random = rand() % kolvo;
			tmp = koloda[i];
			koloda[i] = koloda[random];
			koloda[random] = tmp;
		}

		if (vibor == 1)
		{
			std::cout << "Vvedite kol-vo igrokov (2 ili 3)" << std::endl;
			std::cin >> gamers;
			if (gamers == 2 || gamers == 3)
			{

			}
			else
			{
				std::cout << "Vvedeni necorrektniye danniye" << std::endl;
				std::cout << "Pojalusta, zakroyte programmu" << std::endl;
				system("pause");
			}
		}


	}

	void Game::peremewat()
	{
		for (int i = 0; i < kolvo; i++)
		{
			random = rand() % kolvo;
			tmp = koloda[i];
			koloda[i] = koloda[random];
			koloda[random] = tmp;
		}
	}

	int Game::proverka(int player, int opponent, int diller)
	{
		if (player > opponent && player <= 21)
		{
			return 1;
		}
		if (player > opponent && player > 21)
		{
			return 0;
		}
		if (player < opponent && opponent <= 21)
		{
			return 0;
		}
		if (player < opponent && opponent > 21)
		{
			return 1;
		}
		if (player == opponent)
		{
			if (diller == 1)
			{
				return 1;
			}
			if (diller == 2)
			{
				return 0;
			}
			if (diller == 3)
			{
				return 2;
			}
		}

	}

	int Game::proverka(int player, int opponent1, int opponent2, int diller)
	{

		if ((player > opponent1) && (player <= 21))
		{
			if ((player > opponent2))
				return 1;
			if ((player == opponent2))
			{
				if (diller == 1)
				{
					return 1;
				}
				if (diller == 3)
				{
					return 0;
				}
				if (diller == 2 || diller == 4)
				{
					return 2;
				}
			}
			else
				return 0;
		}

		if ((player > opponent1) && (player > 21))
		{
			return 0;
		}

		if ((player < opponent1) && (opponent1 > 21))
		{
			if ((player > opponent2) && player <= 21)
				return 1;
			if ((player == opponent2))
			{
				if (diller == 1)
				{
					return 1;
				}
				if (diller == 3)
				{
					return 0;
				}
				if (diller == 2 || diller == 4)
				{
					return 2;
				}
			}
			else
				return 0;
		}

		if ((player < opponent1) && (opponent1 <= 21))
		{
			return 0;
		}

		if (player == opponent1)
		{
			if (diller == 1)
			{
				return 1;
			}
			if (diller == 2)
			{
				return 0;
			}
			if ((diller == 3 || diller == 4) && (player > opponent2))
			{
				return 2;
			}
			if ((diller == 3 || diller == 4) && (player < opponent2))
			{
				return 0;
			}
			if ((diller == 4) && (player = opponent2))
			{
				return 0;
			}
		}
	}

	char Game::takeCard(int cmp)
	{
		return koloda[cmp].getName();
	}

	void Game::setFlag(int tmp, int flag)
	{
		koloda[tmp].setFlag_vzali(flag);
	}

	int Game::getFlag(int tmp)
	{
		return koloda[tmp].getFlag_vzali();
	}

	Sprite Game::Game::showSprite(int cmp)
	{
		return koloda[cmp].getSprite();
	}
	void Game::settSprite(int i, Sprite sprit)
	{
		koloda[i].setSprite(sprit);
	}

	void Game::Position(int i, int x, int y)
	{
		showSprite(i).setPosition(x, y);
	}
