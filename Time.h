# Time
basic operator overloading for class Time

#pragma once
#include<iostream>

class Time
{
public:
	Time(int h = 0, int m = 0);
	~Time() {};
	void Show() const { std::cout << hours << " : " << minutes << std::endl; };
	void Reset(int h = 0, int m = 0) { hours = h, minutes = m; };

	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(int mult) const;

	friend Time operator*(double m, const Time & t) { return t * m; }
	friend std::ostream & operator<<(std::ostream & os, const Time & t);

private:
	int hours;
	int minutes;
};
