#include "Garage.h"
#include <fstream>


int main() {

	garage main_garage;
	ifstream input_file;

	char temp_code; //Code to trigger switch
	string temp_license;
	car *temp_car = nullptr;

	input_file.open("file_input.txt");

	assert(!(input_file.fail()));

	//Go through file until end

	while (!input_file.eof()) {
		//temp_code = A
		//car temp = new car BLAHBLAH <- how are we going to do this?

		input_file >> temp_code >> temp_license;


		switch (temp_code) {
		case 'A':
			temp_car = new car(temp_license);
			main_garage.arrival(*temp_car);
			
			delete temp_car;
			temp_car = nullptr;
			break;
		case 'D':
			main_garage.depart(temp_license);
			break;
		}
	}



	input_file.close();

	return 0;
}
