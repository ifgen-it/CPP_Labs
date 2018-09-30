#include "barrel.h"

Barrel::Barrel(int vol, double pct)
{
	m_Volume = vol;
	m_Pct = pct;
}

Barrel::~Barrel()
{
}

int Barrel::GetVolume()
{
	return m_Volume;
}

double Barrel::GetPct()
{
	return m_Pct;
}

void Barrel::SetPct(double pct)
{
	m_Pct = pct;
}

void Barrel::SetVolume(int vol)
{
	m_Volume = vol;
}

void Barrel::Reduce()
{
	m_Volume = m_Volume - 1;
}

void Barrel::Add(double pct)
{
	m_Pct = (m_Volume * m_Pct + 1 * pct) / (m_Volume + 1);
	m_Volume = m_Volume + 1;
}

void Barrel::Transfuse(Barrel& other)
{

	//========= FORWARD =========
	// Reduce from Spirt barrel
	other.Reduce();

	// Pint info
	double PintPct = other.GetPct();
	
	// Add to Water barrel
	Add(PintPct);

}