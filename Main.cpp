#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Record.h"
#include <algorithm>
using namespace std;
#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	vector<Record> records;
	ofstream report;

	string filename;
	string line;

	cout << "Enter the full file path: ";
	cin >> filename;

	ifstream ifs(filename.c_str());
	if (!ifs) {
		cout << "Unable to open file" << filename << endl;
		return 1;
	}

	int totalRecords = 0;
	int tossedRecords = 0;

	vector<Record> removedRecords;
	vector<Record> itemCode;

	while (getline(ifs, line)) {
		Record newRecord(line);
		if (newRecord.getQuantity() != 0) {
			records.push_back(Record(line));
			Record itemCodeRecord(line);
			if (itemCodeRecord.getItemcode() != 0) {
				itemCode.push_back(Record(line));
				sort(itemCode.begin(), itemCode.end());
			}
		} else {
			removedRecords.push_back(Record(line));
			tossedRecords++;
		}
		totalRecords++;
	}
	ifs.close();
	report.open("report.txt", ofstream::out | ofstream::trunc);

	report << "Item code";
	report.setf(ios::right);
	report.width(14);
	report << "Quantity";
	report.setf(ios::left);
	report.width(9);
	report << "Cost";
	report.setf(ios::left);
	report.width(14);
	report << "Total" << endl;
	report << "-----------------------------------------------" << endl;


	for(unsigned int i = 0; i < itemCode.size(); i++){
		report << itemCode[i].getItemcode();
		report.setf(ios::right);
		report.width(14);
		report << itemCode[i].getQuantity();
		report.setf(ios::right);
		report.width(14);
		report << itemCode[i].getCost();
		report.setf(ios::right);
		report.width(14);
		report << (itemCode[i].getCost() * itemCode[i].getQuantity());
		report << endl;
	}
	report.close();
	return -1;
}