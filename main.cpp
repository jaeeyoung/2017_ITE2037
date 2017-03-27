#include "contacts.h"
#include "messages.h"
#include "recents.h"

string command0() {
	cout << "-home-------------------------" << endl;
	cout << "1. Contacts" << endl;
	cout << "2. Messages" << endl;
	cout << "3. Recents" << endl;
	cout << "4. Exit" << endl;
	cout << "-------------------------" << endl;
	cout << "Input the number (1-4) : ";

	string output;
	cin >> output;
	return output;
}

string command1() {
	cout << "-home/contacts----------------" << endl;
	cout << "1. Add " << endl;
	cout << "2. Edit" << endl;
	cout << "3. Remove" << endl;
	cout << "4. Show" << endl;
	cout << "5. Back" << endl;
	cout << "------------------------" << endl;

	string result;
	cout << "Input the number(1-5) : ";
	cin >> result;
	return result;
}

string command2() {
	cout << "-home/recents-----------------" << endl;
	cout << "1. New message" << endl;
	cout << "2. All messages" << endl;
	cout << "3. Sended messages" << endl;
	cout << "4. Received messages" << endl;
	cout << "5. Back" << endl;
	cout << "------------------------" << endl;

	string result;
	cout << "Input the number(1-5) : ";
	cin >> result;
	return result;
}

string command3() {
	cout << "-home/recents-----------------" << endl;
	cout << "1. All" << endl;
	cout << "2. Missed" << endl;
	cout << "3. Back" << endl;
	cout << "-------------------------" << endl;
	cout << "Input the number (1-2) : ";

	string output;
	cin >> output;
	return output;
}

void print_err() {
	cout << "Don't understand" << endl;
}

int main() {
	Contacts contacts;
	Messages messages;
	Recents recents;

	while (true) {
		string cmd1 = command0();
		if (cmd1 == "1") {
			string cmd2 = command1();
			if (cmd2 == "1") 			contacts.add_new_();
			else if (cmd2 == "2") 		contacts.edit_();
			else if (cmd2 == "3") 		contacts.remove_();
			else if (cmd2 == "4") 		contacts.print_();
			else if (cmd2 == "5");
			else print_err();
		}
		else if (cmd1 == "2") {
			string cmd2 = command2();
			if (cmd2 == "1");
			else if (cmd2 == "2")		messages.print_();
			else if (cmd2 == "3")		messages.print_out_();
			else if (cmd2 == "4")		messages.print_in_();
			else print_err();
		}
		else if (cmd1 == "3") {
			string cmd2 = command3();
			if (cmd2 == "1") 			recents.printAll();
			else if (cmd2 == "2") 		recents.printMissed();
			else if (cmd2 == "3");
			else print_err();
		}
		else if (cmd1 == "4") return 0;
		else print_err();
	}

	return 0;
}