#include <string>

using namespace std;

class car {
	string license;
	int move_count;

public:

	car();
	car(string);

	string get_license() const;
	int get_move_count() const;

	void increase_move_count();

	bool operator == (car);
};

car::car()
	:move_count(0)
{
	//Intentionally blank
}

car::car(string input_license)
	:license(input_license), move_count(0)
{
	//Intentionally blank
}


string car::get_license() const {
	return license;
}
int car::get_move_count() const {
	return move_count;
}




void car::increase_move_count() {
	move_count++;
}




bool car::operator == (car targetcar) {
	return (targetcar.license == this->license &&
		targetcar.move_count == this->move_count);
}
