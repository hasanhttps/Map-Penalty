#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

#include "Penalty.h"

int main() {
	string number = "96-AZ-02";
	string number1 = "85-TR-08";

	DataTime date(23, 3, 2023);
	DataTime date1(24, 1, 2022);

	list<Penalty> penalties;
	list<Penalty> penalties1;

	Penalty p("Qosha xett", date, 50);
	date._day = 12;
	date._month = 4;
	Penalty p1("Qirmizi ishiq", date, 100);
	Penalty p2("Dayanma durma", date1, 200);
	date1._day = 2;
	Penalty p3("Qirmizi ishiq", date1, 100);
	date1._day = 15;
	date1._month = 7;
	Penalty p4("Qirmizi ishiq", date1, 100);
	penalties1.push_back(p2);
	penalties1.push_back(p3);
	penalties1.push_back(p4);
	penalties.push_back(p);
	penalties.push_back(p1);


	map<string, list<Penalty>> database;
	database[number] = penalties;
	database[number1] = penalties1;
	date._day = 27;
	date._month = 6;
	Penalty p5("Qirmizi ishiq", date, 100);
	database[number1].push_back(p5);

	for (auto i = database.rbegin(); i != database.rend(); i++) {
		cout << (*i).first << endl;
		for (auto& j : (*i).second) cout << j << endl;
	}

}