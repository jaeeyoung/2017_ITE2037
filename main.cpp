#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "contacts.h"


using namespace std;

class callInfo {
public:
	string type, when, who;
};

class Recents {
public:
	Recents() { scan(); }

	void scan() {
		ifstream file;

		file.open("recents.txt");

		while (!file.eof()) {
			callInfo tmp;
			file >> tmp.type >> tmp.who >> tmp.when;
			callList.push_back(tmp);
		}

		file.close();
	}

	void printAll() {
		for (int i = 0; i<callList.size(); ++i) {
			if (callList[i].type == "Missed") {
				cout << i + 1 << ". Missed call    From : " << callList[i].who << " When : " << callList[i].when << endl;
			}
			else if (callList[i].type == "Cancelled") {
				cout << i + 1 << ". Cancelled call To   : " << callList[i].who << " When : " << callList[i].when << endl;
			}
			else if (callList[i].type == "Incoming") {
				cout << i + 1 << ". Incoming call  From : " << callList[i].who << " When : " << callList[i].when << endl;
			}
			else if (callList[i].type == "Outgoing") {
				cout << i + 1 << ". Outgoing call  To   : " << callList[i].who << " When : " << callList[i].when << endl;
			}
		}
	}

	void printMissed() {
		int idx = 1;
		for (int i = 0; i<callList.size(); ++i) {
			if (callList[i].type == "Missed") {
				cout << idx++ << ". Missed    call From : " << callList[i].who << " When : " << callList[i].when << endl;
			}
		}
	}

private:
	vector<callInfo> callList;
};


int command0() {
	cout << endl << "-------------------------" << endl;
	cout << "1. Contacts" << endl;
	cout << "2. Messages" << endl;
	cout << "3. Recents" << endl;
	cout << "4. Exit" << endl;
	cout << "-------------------------" << endl;
	cout << "Input the number (1-4) : ";

	int output;
	cin >> output;
	return output;
}

int command1() {
	cout << endl << "-------------------------" << endl;
	cout << "1. Display" << endl;
	cout << "2. Add" << endl;
	cout << "3. Change" << endl;
	cout << "4. Delecte" << endl;
	cout << "5. Find" << endl;
	cout << "-------------------------" << endl;
	cout << "Input the number (1-5) : ";

	int output;
	cin >> output;
	return output;
}

int command3() {
	cout << "-------------------------" << endl;
	cout << "1. All" << endl;
	cout << "2. Missed" << endl;
	cout << "-------------------------" << endl;
	cout << "Input the number (1-2) : ";

	int output;
	cin >> output;
	return output;
}
int main() {
	Recents exam;
	Contacts contacts;

	while (true) {
		int cmd1 = command0();

		if (cmd1 == 1) {
			int cmd2 = command1();
			if (cmd2 == 1) 		contacts.Display();
			else if (cmd2 == 2) 	contacts.Add();
			else if (cmd2 == 3) 	contacts.Change();
			else if (cmd2 == 4) 	contacts.Delete();
			else if (cmd2 == 5) 	contacts.Find();
		}

		if (cmd1 == 3) {
			int cmd2 = command3();
			if (cmd2 == 1) 		exam.printAll();
			else if (cmd2 == 2) 	exam.printMissed();
		}
		else if (cmd1 == 4) return 0;
	}

	return 0;
}