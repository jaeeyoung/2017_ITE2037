#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class person {
public:
	string name, number;
	bool operator <(const person &a) const {
		return this->name < a.name;
	}
};

class Contacts {
public:
	Contacts();
	void scan_();
	void sort_();
	int find_by_name_(string target);
	int find_by_number(string target);
	void print_();
	void add_new_();
	void remove_();
	void edit_();
private:
	vector<person> people;
};
