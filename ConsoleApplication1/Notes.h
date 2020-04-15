#include "Event.h"
#include <vector>
#include <utility>

class Notes {

public:
	Notes();
	void add_notes(const Event& e);
	void show();
	void sort_event();
	const vector<Event>& get_vector(const vector<Event>&) const;
	void search_category(string s);

private:
	vector<Event> notes;
};