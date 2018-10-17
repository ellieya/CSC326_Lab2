#include "Garage.h"

int main() {

	garage main_garage;

	char temp_code; //Code to trigger switch
	string temp_license;
	car *temp_car = nullptr;

	ifstream input_file;
	input_file.open("file_input.txt");

	assert(!(input_file.fail()));

	//Go through file until end

	while (!input_file.eof()) {

		input_file >> temp_code >> temp_license;

		switch (temp_code) {
		case 'A':
			temp_car = new car(temp_license);
			main_garage.arrival(*temp_car);

			cout << temp_license << "has arrived." << endl;

			//Data is now stored in an ArrayStack, so temp_car no longer needed.
			delete temp_car;
			temp_car = nullptr;
			break;
		case 'D':
			temp_car = new car(temp_license);
			main_garage.depart(*temp_car);
			break;
		}
	}

	input_file.close();

	return 0;
}
