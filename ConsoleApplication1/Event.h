#ifndef EVENT_H
#define EVENT_H
#include "Time.h"
#include <string>
#include <ctime>

using namespace std;

enum class Priority {

	green = 1, orange, red
};

class Event {

public:
	Event();
	const string& get_title() const;
	void set_title(const string&);
	const string& get_description() const;
	void set_description(const string&);
	const Time& get_time() const;
	void set_time(const Time&);
	const Priority& get_priority() const;
	void set_priority(const Priority&);
	void show();
	const string& get_category() const;
	void set_category(const string&);

private:
	Time time;
	Priority priority;
	string description;
	string title;
	string category;
};

bool compareTimeByDay(const Event& t, const Event& t1);
bool compareTimeByHours(const Event& d, const Event& d1);

#endif