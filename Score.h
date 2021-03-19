class Score
{
private:
	int SkorplayerX;
	int SkorplayerY;

public:
	Score(int x, int y)
	{
		SkorplayerX = x;
		SkorplayerY = y;
	}

	int skorX()
	{
		return SkorplayerX;
	}

	int skorY()
	{
		return SkorplayerY;
	}

	void SetSkor(int x, int y)
	{
		SkorplayerX = x;
		SkorplayerY = y;
	}

	void AddSkorX()
	{
		SkorplayerX++;
	}

	void AddSkorY()
	{
		SkorplayerY++;
	}

};
