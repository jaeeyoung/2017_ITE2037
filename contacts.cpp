#include "contacts.h"

Contacts::Contacts()
{
	scan_();
}

void Contacts::scan_()
{
	ifstream file;

	file.open("contacts.txt");

	while (!file.eof()) {
		person tmp;
		file >> tmp.name >> tmp.number;
		people.push_back(tmp);
	}

	file.close();
}

void Contacts::sort_()
{
	sort(people.begin(), people.end());
}

int Contacts::find_by_name_(string target)
{
	for (int i = 0; i<people.size(); ++i) {
		if (people[i].name == target) return i;
	}
	return -1;
}

int Contacts::find_by_number(string target)
{
	for (int i = 0; i<people.size(); ++i) {
		if (people[i].number == target) return i;
	}
	return -1;
}

void Contacts::print_()
{
	sort_();
	cout << "-home/contacts/show-----------------" << endl;
	for (int i = 0; i<people.size(); i++) {
		cout << i + 1 << ". " << people[i].name << " " << people[i].number << endl;
	}
}

void Contacts::add_new_()
{
	person tmp;
	cout << "-home/contacts/add------------" << endl;
	cout << "Input the name to add : ";
	cin >> tmp.name;
	int idx1 = find_by_name_(tmp.name);
	if (idx1 == -1) {
		cout << "Input the number to add : ";
		cin >> tmp.number;
		int idx2 = find_by_number(tmp.number);
		if (idx2 == -1) {
			people.push_back(tmp);
			sort_();
		}
		else cout << "Already has the same number." << endl;
	}
	else cout << "Already has the same name." << endl;
}

void Contacts::remove_()
{
	string name;
	cout << "-home/contacts/remove------------" << endl;
	cout << "Input the name to remove : ";
	cin >> name;
	int idx = find_by_name_(name);
	if (idx != -1) {
		people.erase(people.begin() + idx);
		cout << "Successfully Removed." << endl;
	}
	else
		cout << "No such person." << endl;
}

void Contacts::edit_()
{
	string name;
	cout << "-home/contacts/edit------------" << endl;
	cout << "Input the name to edit : ";
	cin >> name;
	int idx = find_by_name_(name);
	if (idx != -1) {
		string number;
		cout << "Input the number to change : ";
		cin >> number;
		people[idx].number = number;
		cout << "Successfully Changed." << endl;
	}
	else cout << "No such person." << endl;
}