class Player
{
private:

	float Hits;
	enum Pleyer { playerX, playerY } player;

public:

	float GetHits()
	{
		return Hits;
	}

	void SetHits(float h)
	{
		Hits = h;
	}

	Pleyer GetPleyer()
	{
		return player;
	}

	Player(int p)
	{
		if (p == 0)
		{
			player = Pleyer::playerX;
		}
		else
		{
			player = Pleyer::playerY;
		}
		Hits = 0;
	}
	Player(Player& p)
	{
		if (p.player == Pleyer::playerX)
		{
			player = Pleyer::playerY;
		}
		else
		{
			player = Pleyer::playerX;
		}
		Hits = p.Hits;
	}

};
