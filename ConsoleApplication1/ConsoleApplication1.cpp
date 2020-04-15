#include "Event.h"
#include "Time.h"
#include "Notes.h"
#include <iostream>

using namespace std;

int main()
{
	Event x;
	Notes y;
	Time z;

	for (;;) {

		system("cls");

		cout << "\n\t 1. Add category \n";
		cout << "\t 2. Show events \n";
		cout << "\t 3. View events by category \n";
		cout << "\t 4. Exit \n\n";
		cout << "\t 4. Select an action: ";

		int chose;
		cin >> chose;

		switch (chose) {
		case 1: {
			for (;;) {

				system("cls");

				cout << "\n\t Enter category for event \n\t ";
				string category_name;
				cin >> category_name;
				x.set_category(category_name);

				cout << "\n\t Enter new event \n\t ";
				string s;
				cin.ignore();
				getline(cin, s);
				x.set_title(s);

				cout << "\n\t Enter description for event \n\t ";
				string d;
				cin.ignore(0);
				getline(cin, d);
				x.set_description(d);

				cout << "\n\t Enter day, hours, minutes for event \n\t ";
				cin >> z.day;
				cout << "\t ";
				cin >> z.hours;
				cout << "\t ";
				cin >> z.minutes;
				x.set_time(z);

				cout << "\n\t Enter priority for ivent (1, 2, 3) \n\t ";
				int value;
				cin >> value;

				switch (value)
				{
				case 1:
					x.set_priority(Priority::green);
					break;
				case 2:
					x.set_priority(Priority::orange);
					break;
				case 3:
					x.set_priority(Priority::red);
				default:
					break;
				}
				y.add_notes(x);
				cout << "\n\t If you want to exit, press 'q' \n\t ";
				char a;
				cin >> a;

				if ('q' == a) {
					break;
				}
			}

			break;
		}
		case 2: {
			system("cls");
			y.show();
			char o;
			cin >> o;
			break;
		}
		case 3: {
			for (;;) {

				system("cls");

				cout << "\n\t Enter category - ";
				string cat;
				cin >> cat;
				y.search_category(cat);
				cout << "\n\t if you want to exit press 'q' \n";
				char o;
				cin >> o;

				if (o == 'q') {
					break;
				}
			}
		}
		case 4: {
			return 0;
		}
		default:
			break;
		}
	}
	return 0;
}