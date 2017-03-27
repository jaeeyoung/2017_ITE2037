#include "recents.h"

Recents::Recents()
{
	scan();
}

void Recents::scan()
{
	ifstream file;

	file.open("recents.txt");

	while (!file.eof()) {
		call tmp;
		file >> tmp.number >> tmp.when >> tmp.type;
		calls.push_back(tmp);
	}

	file.close();
}

void Recents::printAll()
{
	for (int i = 0; i<calls.size(); ++i) {
		if (calls[i].type == "Missed") {
			cout << i + 1 << ". Missed call    From : " << calls[i].number << " When : " << calls[i].when << endl;
		}
		else if (calls[i].type == "Cancelled") {
			cout << i + 1 << ". Cancelled call To   : " << calls[i].number << " When : " << calls[i].when << endl;
		}
		else if (calls[i].type == "Incoming") {
			cout << i + 1 << ". Incoming call  From : " << calls[i].number << " When : " << calls[i].when << endl;
		}
		else if (calls[i].type == "Outgoing") {
			cout << i + 1 << ". Outgoing call  To   : " << calls[i].number << " When : " << calls[i].when << endl;
		}
	}
}

void Recents::printMissed()
{
	int idx = 1;
	for (int i = 0; i<calls.size(); ++i) {
		if (calls[i].type == "Missed") {
			cout << idx++ << ". Missed    call From : " << calls[i].number << " When : " << calls[i].when << endl;
		}
	}
}