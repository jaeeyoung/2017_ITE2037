#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Contacts
{
public:
	void Display();
	void Add();
	void Change();
	void Delete();
	void Find();
private:
	vector<string> name;
	vector<string> number;
};