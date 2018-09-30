#pragma once

class Barrel
{
	int m_Volume;
	double m_Pct;

public:
	Barrel(int vol, double pct);

	int GetVolume();
	double GetPct();
	void SetVolume(int vol);
	void SetPct(double pct);

	void Reduce();
	void Add(double pct);

	void Transfuse(Barrel& other);

	~Barrel();



};


