#include <string>

class car {
public:
	string license;
	int move_count;

	car();
	car(string);

	string get_license() const;
	int get_move_count() const;

	void increase_move_count();
	void set_car(string);

	bool operator == (car);
	car operator = (car);
	//WARNING: ONLY COMPARES LICENSE
};
car::car()
	:license("DUMMYN0"), move_count(0)
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
void car::set_car(string new_license) {
	license = new_license;
}
bool car::operator == (car targetcar) {
	return (license == targetcar.license);
}
car car::operator = (car other) {
	license = other.license;
	move_count = other.move_count;

	return *this;
}