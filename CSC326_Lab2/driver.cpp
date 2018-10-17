#include "Garage.h"

int main() {

	garage main_garage;

	char temp_code; //Code to trigger switch
	string temp_license;
	car temp_car;

	ifstream input_file;
	input_file.open("file_input.txt");

	assert(!(input_file.fail()));

	//Go through file until end

	while (!input_file.eof()) {

		input_file >> temp_code >> temp_license;

		switch (temp_code) {
		case 'A':
			
			
			main_garage.arrival(temp_car);

			cout << temp_license << "has arrived." << endl;

			//Data is now stored in an ArrayStack, so temp_car no longer needed.
			delete temp_car_pointer;
			temp_car_pointer = nullptr;
			break;
		case 'D':
			//Must be stored in temp_car_pointer, then stored into temp_car or else C2102 occurs
			temp_car_pointer = new car(temp_license);
			temp_car = *temp_car_pointer;

			main_garage.depart(temp_car);

			delete temp_car_pointer;
			temp_car_pointer = nullptr;
			break;
		}
	}

	input_file.close();

	return 0;
}
