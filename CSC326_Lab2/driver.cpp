#include "Garage.h"


int main() {

	garage lane1;
	garage lane2;
	garage street;


/*
To-Do:

-Figure out which functions very specifically need to happen in class, and which functions can stay in main.
We more or less have algorithm down for main.


*/

	void process_input(char INPUT) {
		switch (INPUT) {
		case A:
			arrival();
			break;
		case B:
			departure();
			break;
		}
	}

	void arrival() {
		if (lane1.full()) {
			if (lane2.full()) {
				cout << "All garages are full. Cannot take this car!" << endl;
			}
			else {
				//Condition if lane1 full but lane2 still have room
				lane2.push(THISCAR);
				cout << "Lane 1 is full! Car has been stored in lane 2!" << endl;
			}
		}
		else {
			//Condition if both lanes still have room
			cout << "Car has been stored in lane 1!" << endl;
		}
	}


	void departure() {
		int lane1 = lane1.search(CARNAME);
		int lane2 = lane2.search(CARNAME);
		bool street_flag = false;

		if (lane1 > 0) {
			//Is CARNAME == TOP?
				//NO: Ok let's move TOP
				//Is lane2 FULL?
					//NO: OK lane2.top() = lane1.top().
					//YES: OK street_flag = true. street.top() = lane1.top()
			// ^ Loop this
		}
		else if (lane2 > 0) {

		}

		//If street was used at all, run this:
		if (street_flag) {
			street.clean();
		}
	}
}
