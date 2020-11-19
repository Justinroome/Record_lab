#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "Record.h"
#include "FloatCompare.h"

using namespace std;

double Record::getCost()
{
	return cost;
}

unsigned int Record::getQuantity()
{
	return quantity;
}

int Record::getItemcode()
{
	return itemcode;
}

bool operator <(const Record &l, const Record &r){
		return(definitelyLessThan(l.itemcode, r.itemcode));
	}

Record::Record(string line) {
	quantity = 0;
	cost = 0;
	itemcode = 0;

	stringstream ss(line);
	vector<string> result;

	while(ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		result.push_back(substr);
	}

	string s = result[0];//item code
	string q = result[1];//quantity
	string c = result[2];//cost

	stringstream convert(s);
	stringstream convert2(q);
	stringstream convert3(c);

	convert >> itemcode;
	convert2 >> quantity;
	convert3 >> cost;

}

Record::~Record() {}
