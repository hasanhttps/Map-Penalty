#pragma once

typedef unsigned short ushort;

struct DataTime {
	ushort _day;
	ushort _month;
	ushort _year;
	
	DataTime() = default;
	DataTime(ushort day, ushort month, ushort year) {
		_day = day;
		_month = month;
		_year = year;
	}

	// Operator Overloading

	friend ostream& operator<<(ostream& print, const DataTime& other) {
		cout << other._day << "/" << other._month << "/" << other._year;
		return print;
	}
};


class Penalty {
	static int id;
	int _id;
	string _text;
	double _price;
	DataTime _date;
public:

	Penalty() : _id(++id) { }
	Penalty(string text, DataTime date, double price) : Penalty() {
		_text = text;
		_price = price;
		setDate(date);
	}

	// Acsessors

	// Setters

	void setId(int id) { _id = id; }
	void setText(string text) { _text = text; }
	void setPrice(double price) { _price = price; }
	void setDate(DataTime date) { 
		_date._day = date._day;
		_date._month = date._month;
		_date._year = date._year;
	}

	// Getters

	int getId() { return _id; }
	string getText() { return _text; }
	double getPrice() { return _price; }
	DataTime getDate() { return _date; }

	// Operator Overloading

	friend ostream& operator<<(ostream& print, const Penalty& other) {
		cout << "Id : " << other._id << endl
			 << "Reason : " << other._text << endl
			 << "Price : " << other._price << endl
			 << "Penalty Date : " << other._date << endl;

		return print;
	}
};

int Penalty::id = 0;