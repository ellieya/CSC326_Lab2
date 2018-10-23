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

		//Take values from file
		input_file >> temp_code >> temp_license;

		//Set temporary car's license to equal userInput
		temp_car.set_car(temp_license);

		switch (temp_code) {
		case 'A':
			if (main_garage.arrival(temp_car)) {
				cout << temp_license << " has arrived." << endl;
				main_garage.print_all_lanes();
				system("pause");
				system("cls");
			}
			else {
				cout << temp_license << " has failed to arrive." << endl;
			}
			break;
		case 'D':
			cout << "\n" << temp_license << " wishes to depart." << endl;
			main_garage.depart(temp_car);
			main_garage.print_all_lanes();
			system("pause");
			system("cls");
			break;
		}
	}

	input_file.close();

	return 0;
}
