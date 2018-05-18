# Time
basic operator overloading for class Time

#include "Time.h"
#include <assert.h>


Time::Time(int h, int m) :hours(h), minutes(m){}

Time Time::operator+(const Time & t) const
{
	Time sum;
	int extra = 0;

	sum.minutes = minutes + t.minutes;
	if (sum.minutes >= 60) {
		sum.minutes -= 60;
		extra = 1;
	}
	sum.hours = extra + t.hours + hours;

	return sum;
}


Time Time::operator-(const Time & t) const 
{
	Time diffference;
	int totalMins1, totalMins2;

	totalMins1 = t.minutes + 60 * t.hours;
	totalMins2 = minutes + 60 * hours;

	assert(totalMins2 >= totalMins1);

	diffference.minutes = (totalMins2 - totalMins1) % 60;
	diffference.hours = (totalMins2 - totalMins1) / 60;

	return diffference;
}


Time Time::operator*(int mult) const 
{
	Time result;
	int totalMinutes = hours * 60 * mult + minutes * mult;
	result.hours = totalMinutes / 60;
	result.minutes = totalMinutes % 60;
	return result;
}


std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " : " << t.minutes;
	return os;
}
