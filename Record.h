#ifndef RECORD_H_
#define RECORD_H_
#include <string>
using namespace std;

class Record {
public:
	Record(std::string line);
	virtual ~Record();

	int getItemcode();

	unsigned int getQuantity();

	double getCost();

	friend bool operator <(const Record &l, const Record &r);

private:
	int itemcode;
	unsigned int quantity;
	double cost;
};

#endif /* RECORD_H_ */
