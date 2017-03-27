#pragma once
#include "contacts.h"

class call {
public:
	string number, type, when;
};

class Recents {
public:
	Recents();
	void scan();
	void printAll();
	void printMissed();
private:
	vector<call> calls;
};
