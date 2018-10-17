#include <string>

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

	car operator = (car);
	//WARNING: ONLY COMPARES LICENSE
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
	return (this->license == targetcar.license);
}
car car::operator = (car other) {
	license = other.license;
	move_count = other.move_count;

	return *this;
}