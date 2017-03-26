#include "contacts.h"

void Contacts::Display()
{
	ifstream file;
	string temp;

	file.open("address.txt");
	while (!file.eof()) {
		file.seekg(0, ios::end);
		int size = file.tellg();
		temp.resize(size);
		file.seekg(0, ios::beg);
		file.read(&temp[0], size);
	}

	replace(temp.begin(), temp.end(), '\t', '\n');

	vector<string> vtemp;
	stringstream ss(temp);
	string tok;

	while (getline(ss, tok, '\n')) {
		vtemp.push_back(tok);
	}

	int i, nv;
	int t = 0, s = 0;
	nv = vtemp.size();

	for (i = 0;i < nv; ++i) {
		if (i % 2 == 0) {
			name.push_back(vtemp[i]);
			++t;
		}
		else {
			number.push_back(vtemp[i]);
			++s;
		}
	}

	file.close();

	vector<string> tempName;
	vector<string> tempNumber;
	int j, n, n2;
	n = name.size();
	n2 = number.size();

	for (i = 0;i < n;++i) {
		tempName.push_back(name[i]);
	}

	for (i = 0;i < n2;++i) {
		tempNumber.push_back(number[i]);
	}

	sort(name.begin(), name.end());

	for (i = 0;i < n;++i) {
		for (j = 0;j < n;++j) {
			if (name[i].compare(tempName[j]) == 0) {
				number.insert(number.begin() + i, tempNumber[j]);
			}
		}
	}

	cout << "__name_____number__" << endl;
	for (i = 0; i < n; ++i) {
		cout << name[i] << "\t" << number[i] << endl;
	}

	ofstream sfile;

	sfile.open("address.txt");
	for (i = 0;i < n;++i) {
		sfile << name[i] << "\t" << number[i] << endl;
	}
	sfile.close();
}

void Contacts::Add()
{
	ifstream file;
	string temp;

	file.open("address.txt");
	while (!file.eof()) {
		file.seekg(0, ios::end);
		int size = file.tellg();
		temp.resize(size);
		file.seekg(0, ios::beg);
		file.read(&temp[0], size);
	}

	replace(temp.begin(), temp.end(), '\t', '\n');

	vector<string> vtemp;
	stringstream ss(temp);
	string tok;

	while (getline(ss, tok, '\n')) {
		vtemp.push_back(tok);
	}

	int i, nv;
	int t = 0, s = 0;
	nv = vtemp.size();

	for (i = 0;i < nv; ++i) {
		if (i % 2 == 0) {
			name.push_back(vtemp[i]);
			++t;
		}
		else {
			number.push_back(vtemp[i]);
			++s;
		}
	}

	file.close();

	int n, n2;
	n = name.size();
	n2 = number.size();

	cout << "Insert name and number to add" << endl;
	string tName, tNumber;
	cin >> tName >> tNumber;

	name.push_back(tName);
	number.push_back(tNumber);
	++n;
	++n2;

	vector<string> tempName;
	vector<string> tempNumber;
	int j;

	for (i = 0;i < n;++i) {
		tempName.push_back(name[i]);
	}

	for (i = 0;i < n2;++i) {
		tempNumber.push_back(number[i]);
	}

	sort(name.begin(), name.end());

	for (i = 0;i < n;++i) {
		for (j = 0;j < n;++j) {
			if (name[i].compare(tempName[j]) == 0) {
				number.insert(number.begin() + i, tempNumber[j]);
			}
		}
	}

	cout << "__name_____number__" << endl;
	for (i = 0; i < n; ++i) {
		cout << name[i] << "\t" << number[i] << endl;
	}

	ofstream sfile;

	sfile.open("address.txt");
	for (i = 0;i < n;++i) {
		sfile << name[i] << "\t" << number[i] << endl;
	}
	sfile.close();
}

void Contacts::Change()
{
	ifstream file;
	string temp;

	file.open("address.txt");
	while (!file.eof()) {
		file.seekg(0, ios::end);
		int size = file.tellg();
		temp.resize(size);
		file.seekg(0, ios::beg);
		file.read(&temp[0], size);
	}

	replace(temp.begin(), temp.end(), '\t', '\n');

	vector<string> vtemp;
	stringstream ss(temp);
	string tok;

	while (getline(ss, tok, '\n')) {
		vtemp.push_back(tok);
	}

	int i, nv;
	int t = 0, s = 0;
	nv = vtemp.size();

	for (i = 0;i < nv; ++i) {
		if (i % 2 == 0) {
			name.push_back(vtemp[i]);
			++t;
		}
		else {
			number.push_back(vtemp[i]);
			++s;
		}
	}

	file.close();

	int op, n, n2, sel;
	n = name.size();
	n2 = number.size();
	string tName, tNumber;
	cout << "Choose either name or number to change" << endl;
	cout << "1 : Change name 2 : Change number" << endl;
	cin >> op;
	cout << "Insert name and number to change" << endl;
	cin >> tName >> tNumber;

	switch (op) {
	case 1:
		for (sel = 0;sel < n2;++sel) {
			if (number[sel].compare(tNumber) == 0) {
				break;
			}
		}

		name.erase(name.begin() + sel);
		name.insert(name.begin() + sel, tName);

		break;
	case 2:
		for (sel = 0;sel < n2;++sel) {
			if (name[sel].compare(tName) == 0) {
				break;
			}
		}

		number.erase(number.begin() + sel);
		number.insert(number.begin() + sel, tNumber);

		break;
	}

	vector<string> tempName;
	vector<string> tempNumber;
	int j;

	for (i = 0;i < n;++i) {
		tempName.push_back(name[i]);
	}

	for (i = 0;i < n2;++i) {
		tempNumber.push_back(number[i]);
	}

	sort(name.begin(), name.end());

	for (i = 0;i < n;++i) {
		for (j = 0;j < n;++j) {
			if (name[i].compare(tempName[j]) == 0) {
				number.insert(number.begin() + i, tempNumber[j]);
			}
		}
	} // sort

	cout << "__name_____number__" << endl;
	for (i = 0; i < n; ++i) {
		cout << name[i] << "\t" << number[i] << endl;
	}

	ofstream sfile;

	sfile.open("address.txt");
	for (i = 0;i < n;++i) {
		sfile << name[i] << "\t" << number[i] << endl;
	}
	sfile.close();
}

void Contacts::Delete()
{
	ifstream file;
	string temp;

	file.open("address.txt");
	while (!file.eof()) {
		file.seekg(0, ios::end);
		int size = file.tellg();
		temp.resize(size);
		file.seekg(0, ios::beg);
		file.read(&temp[0], size);
	}

	replace(temp.begin(), temp.end(), '\t', '\n');

	vector<string> vtemp;
	stringstream ss(temp);
	string tok;

	while (getline(ss, tok, '\n')) {
		vtemp.push_back(tok);
	}

	int i, nv;
	int t = 0, s = 0;
	nv = vtemp.size();

	for (i = 0;i < nv; ++i) {
		if (i % 2 == 0) {
			name.push_back(vtemp[i]);
			++t;
		}
		else {
			number.push_back(vtemp[i]);
			++s;
		}
	}

	file.close();

	int n;
	n = name.size();

	cout << "Insert name to delete" << endl;
	string tName;
	cin >> tName;

	for (i = 0;i < n;++i) {
		if (name[i].compare(tName) == 0) {
			break;
		}
	}

	if (i == n - 1) {
		if (name[i].compare(tName) != 0) {
			i = n;
		}
	}

	if (i < n) {
		name.erase(name.begin() + i);
		number.erase(number.begin() + i);
	}
	else {
		cout << tName << " is not in address" << endl;
	}

	ofstream sfile;

	sfile.open("address.txt");
	for (i = 0;i < n;++i) {
		sfile << name[i] << "\t" << number[i] << endl;
	}
	sfile.close();
}

void Contacts::Find()
{
	ifstream file;
	string temp;

	file.open("address.txt");
	while (!file.eof()) {
		file.seekg(0, ios::end);
		int size = file.tellg();
		temp.resize(size);
		file.seekg(0, ios::beg);
		file.read(&temp[0], size);
	}

	replace(temp.begin(), temp.end(), '\t', '\n');

	vector<string> vtemp;
	stringstream ss(temp);
	string tok;

	while (getline(ss, tok, '\n')) {
		vtemp.push_back(tok);
	}

	int i, nv;
	int t = 0, s = 0;
	nv = vtemp.size();

	for (i = 0;i < nv; ++i) {
		if (i % 2 == 0) {
			name.push_back(vtemp[i]);
			++t;
		}
		else {
			number.push_back(vtemp[i]);
			++s;
		}
	}

	file.close();

	int op, n;
	string tName, tNumber;
	n = name.size();

	cout << "Choose either name or number to find" << endl;
	cout << "1 : Find name 2 : Find number" << endl;
	cin >> op;
	switch (op) {
	case 1:
		cout << "Name to find : " << endl;
		cin >> tName;

		for (i = 0;i < n;++i) {
			if (name[i].compare(tName) == 0) {
				break;
			}
		}
		cout << name[i] << "\t" << number[i] << endl;

		break;
	case 2:
		cout << "Number to find : " << endl;
		cin >> tNumber;

		for (i = 0;i < n;++i) {
			if (number[i].compare(tNumber) == 0) {
				break;
			}
		}
		cout << name[i] << "\t" << number[i] << endl;

		break;
	}
}