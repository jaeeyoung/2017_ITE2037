#pragma once
#include "contacts.h"

class message {
public:
	string number, type, when, text;

	bool operator <(const message &a) const {
		return this->when < a.when;
	}
};

class Messages {
public:
	Messages();
	void scan_();
	void sort_();
	void print_();
	void print_out_();
	void print_in_();
private:
	vector<message> messages;
};