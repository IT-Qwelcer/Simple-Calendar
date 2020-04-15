#include "Notes.h"
#include <iostream>
#include <algorithm>

void Notes::add_notes(const Event& e) {
	notes.push_back(e);
}

void Notes::show() {

	sort_event();

	for (auto it = notes.begin(); it != notes.end(); it++) {

		it->show();
	}
}

void Notes::sort_event() {

	sort(notes.begin(), notes.end(), compareTimeByHours);
	sort(notes.begin(), notes.end(), compareTimeByDay);
}

const vector<Event>& Notes::get_vector(const vector<Event>& v) const {

	return v;
}

void Notes::search_category(string s) {

	sort_event();

	for (auto it = notes.begin(); it != notes.end(); it++) {

		if (s == it->get_category()) {

			it->show();
		}
	}
	char o;
	cin >> o;
}

Notes::Notes() {}