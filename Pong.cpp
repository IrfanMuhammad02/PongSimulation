#include <iostream>
#include <thread>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <mutex>
#include "Player.h"
#include "Score.h"

using namespace std;

Score score(0, 0);
mutex m;

void randomFirstTurn(int* player)
{

	int* i = new int;
	srand((int)i);
	delete i;
	*player = rand() % 2;
}

void PLayerHitRandoms(Player* pleyer, bool* isOver)
{

	int* i = new int;
	m.lock();

	srand((int)i);
	delete i;
	pleyer->SetHits(rand() % 101);
	m.unlock();

	//tampilan
	cout << "Hits (Point) : " << pleyer->GetHits();
	if (pleyer->GetPleyer() == 0) {
		cout << " Player X ";
	}
	else {
		cout << " Player Y ";
	}

	if (pleyer->GetHits() <= 50)
	{
		if (pleyer->GetPleyer() == 0)
		{
			cout << "Player Y Mendapat 1 Skor" << endl;
			score.AddSkorY();
		}
		else
		{
			cout << "Player X Mendapat 1 Skor" << endl;
			score.AddSkorX();
		}
		cout << "Meleset" << endl;

		*isOver = true;
	}
	else
	{
		cout << "Kena" << endl;
	}

	this_thread::sleep_for(chrono::seconds(1));
}


int main()
{
	srand(time(0));

	Player playerX(0);

	Player playerY = playerX;

	int mulaiRonde = 1;
	while (score.skorX() < 10 && score.skorY() < 10)
	{
		int mulaiRandom;
		thread RandomFirst(randomFirstTurn, &mulaiRandom);
		RandomFirst.join();
		bool roundOver = false;

		cout << "Match : " << mulaiRonde << endl;
		while (roundOver == false) {
			if (mulaiRandom == 0)
			{
				cout << "Player X Mendapat Giliran Pertama" << endl;

				thread playerXThread(PLayerHitRandoms, &playerX, &roundOver);
				playerXThread.join();

				if (roundOver == true) {
					mulaiRonde++;
					break;
				}

				thread playerYThread(PLayerHitRandoms, &playerY, &roundOver);
				playerYThread.join();

				if (roundOver == true) {
					mulaiRonde++;
					break;
				}
			}
			else if (mulaiRandom == 1)
			{
				cout << "Player Y Mendapat Giliran Pertama" << endl;

				thread playerYThread(PLayerHitRandoms, &playerY, &roundOver);
				playerYThread.join();

				if (roundOver == true)
				{
					mulaiRonde++;
					break;
				}

				thread playerXThread(PLayerHitRandoms, &playerX, &roundOver);
				playerXThread.join();

				if (roundOver == true) {
					mulaiRonde++;
					break;
				}
			}
		}
	}

	cout << "\nHsil" << endl;
	if (score.skorX() >= 10) {
		cout << "Player X Menang :  " << endl << score.skorX() << "-" << score.skorY() << endl;
	}
	else {
		cout << "Player Y Menang :  " <<endl  << score.skorY() << "-" << score.skorX() << endl;
	}

	return 0;
}