#pragma once

class CCar
{
public:
	bool IsEngineTurnedOn() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	int GetGear()const;
	bool SetSpeed(int speed);
	int GetSpeed()const;
	enum class Direction; 
	Direction GetDirection() const;


private:
	bool m_engineIsTurnedOn = false;
	int m_gear = 0;
	int m_speed = 0;
	enum class Gear;

};

enum class CCar::Gear
{
	Reverse = -1,
	Neutal = 0,
	First = 1,
	Second = 2,
	Third = 3,
	Fourth = 4,
	Fifth = 5
};

enum class CCar::Direction
{
	Back,
	Stop,
	Forward
};


