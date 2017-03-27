#include "messages.h"

Messages::Messages()
{
	scan_();
}

void Messages::scan_()
{
	ifstream file;

	file.open("messages.txt");

	while (!file.eof()) {
		message tmp;
		file >> tmp.number >> tmp.type >> tmp.when;
		getline(file, tmp.text);
		messages.push_back(tmp);
	}

	file.close();
}

void Messages::sort_()
{
	sort(messages.begin(), messages.end());
}

void Messages::print_()
{
	cout << "-home/messages/all-----------------" << endl;
	for (int i = 0; i < messages.size(); ++i) {
		if (messages[i].type == "Sended") {
			cout << i + 1 << ". Sended    To   : " << messages[i].number << "  ";
		}
		else if (messages[i].type == "Received") {
			cout << i + 1 << ". Received  From : " << messages[i].number << "  ";
		}
		int max = messages[i].text.size() < 20 ? messages[i].text.size() : 20;
		for (int j = 0; j < max; ++j) {
			cout << messages[i].text[j];
		}
		if (messages[i].text.size() > 20) { cout << "..."; }
		cout << endl;
	}
}

void Messages::print_out_()
{
	cout << "-home/messages/sended-----------------" << endl;
	int j = 0;
	for (int i = 0; i<messages.size(); ++i) {
		if (messages[i].type == "Sended") {
			cout << j++ + 1 << ". Sended    To   : " << messages[i].number << "  ";

			int max = messages[i].text.size() < 20 ? messages[i].text.size() : 20;
			for (int j = 0; j < max; ++j) {
				cout << messages[i].text[j];
			}
			if (messages[i].text.size() > 20) { cout << "..."; }
			cout << endl;
		}
	}
}

void Messages::print_in_()
{
	cout << "-home/messages/received---------------" << endl;
	int j = 0;
	for (int i = 0; i<messages.size(); ++i) {
		if (messages[i].type == "Received") {
			cout << j++ + 1 << ". Received From   : " << messages[i].number << "  ";

			int max = messages[i].text.size() < 20 ? messages[i].text.size() : 20;
			for (int j = 0; j < max; ++j) {
				cout << messages[i].text[j];
			}
			if (messages[i].text.size() > 20) { cout << "..."; }
			cout << endl;
		}
	}
}