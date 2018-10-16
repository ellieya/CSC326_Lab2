#include <string>

using namespace std;

class car {
	string license;
	int move_count;

public:
	string get_license();
	void increase_move_count();
	int get_move_count();
	bool operator == (car);
};


string car::get_license() {
	return license;
}

void car::increase_move_count() {
	move_count++;
}

int car::get_move_count() {
	return move_count;
}

bool car::operator == (car targetcar) {
	return (targetcar.license == this->license &&
		targetcar.move_count == this->move_count);
}