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


/*

////////////////////////////////////////////////////////
OUTPUT
////////////////////////////////////////////////////////

FIRST1 has arrived.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
1         FIRST1              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

////////////////////////////////////////////////////////

SECOND has arrived.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
2         SECOND              0
1         FIRST1              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

/////////////////////////////////////////////////////////

THIRD3 has arrived.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
3         THIRD3              0
2         SECOND              0
1         FIRST1              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

/////////////////////////////////////////////////////////
SKIPPING SIMILAR OUTPUTS UNTIL 10
/////////////////////////////////////////////////////////

TEN010 has arrived.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
10         TEN010              0
9         NINE99              0
8         EIGHT8              0
7         SEVEN7              0
6         SIXTH6              0
5         FIFTH5              0
4         FOURTH              0
3         THIRD3              0
2         SECOND              0
1         FIRST1              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

/////////////////////////////////////////////////////////

2NDLAN has arrived.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
10         TEN010              0
9         NINE99              0
8         EIGHT8              0
7         SEVEN7              0
6         SIXTH6              0
5         FIFTH5              0
4         FOURTH              0
3         THIRD3              0
2         SECOND              0
1         FIRST1              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
1         2NDLAN              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

/////////////////////////////////////////////////////////

FIRST1 wishes to depart.
Car FIRST1, which has moved 0 time(s) has departed.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
10         SECOND              1
9         THIRD3              1
8         FOURTH              1
7         FIFTH5              1
6         SIXTH6              1
5         SEVEN7              1
4         EIGHT8              1
3         NINE99              1
2         TEN010              1
1         2NDLAN              0

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

/////////////////////////////////////////////////////////

2NDLAN wishes to depart.
Car 2NDLAN, which has moved 0 time(s) has departed.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
9         TEN010              2
8         NINE99              2
7         EIGHT8              2
6         SEVEN7              2
5         SIXTH6              2
4         FIFTH5              2
3         FOURTH              2
2         THIRD3              2
1         SECOND              2

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .

/////////////////////////////////////////////////////////

SECOND wishes to depart.
Car SECOND, which has moved 2 time(s) has departed.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!


* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
LANE 2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Slot NO.        LICENSE     MOVE COUNT
8         THIRD3              3
7         FOURTH              3
6         FIFTH5              3
5         SIXTH6              3
4         SEVEN7              3
3         EIGHT8              3
2         NINE99              3
1         TEN010              3

* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
STREET
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *

NO CARS IN THIS LANE!!!

Press any key to continue . . .



*/