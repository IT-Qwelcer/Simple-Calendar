#include "Event.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

Event::Event() :
	priority(Priority::green),
	description(""),
	title("") {}

const string& Event::get_title() const {
	return title;
}
void Event::set_title(const string& s) {
	title = s;
}

const string& Event::get_description() const {
	return description;
}
void Event::set_description(const string& d) {
	description = d;
}

const Time& Event::get_time() const {
	return time;
}
void Event::set_time(const Time& t) {
	time.day = t.day;
	time.hours = t.hours;
	time.minutes = t.minutes;
}

const Priority& Event::get_priority() const {
	return priority;
}
void Event::set_priority(const Priority& p) {
	priority = p;
}

void Event::show() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (priority) {
	case Priority::green: {
		SetConsoleTextAttribute(hConsole, 10);
		break;
	}
	case Priority::orange: {
		SetConsoleTextAttribute(hConsole, 14);
		break;
	}
	case Priority::red: {
		SetConsoleTextAttribute(hConsole, 12);
		break;
	}

	}
	cout << "\n\tCategory - " << category << endl;
	cout << "\tTilte - " << title << endl;
	cout << "\tDescription - " << description << endl;
	cout << "\tTime - " << time.day << " number, at " <<
		time.hours << " : " << setw(2) << setfill('0') <<
		time.minutes << " o'clock" << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

bool compareTimeByDay(const Event& t, const Event& t1) {
	return t.get_time().day < t1.get_time().day;
}

bool compareTimeByHours(const Event& d, const Event& d1) {
	return d.get_time().hours < d1.get_time().hours;
}

const string& Event::get_category() const {
	return category;
}
void Event::set_category(const string& n) {
	category = n;
}