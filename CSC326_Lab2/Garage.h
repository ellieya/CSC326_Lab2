/*
To-do:
-Check on some more exceptions, e.g.:
	lane 1 has some + lane 2 has some
	lane 1 = full + lane 2 = full what happens to street? - STREET & STREET CLEAN CONFIRMED WORKING
-Debug the print function
-Clean-up on documentation + clearer documentation
-I think that get_next_avaliable_lane can be condensed <- THIS IS ONLY IF YOU HAVE A MAD AMOUNT OF TIME!!!
*/


/*

void print_lane(ArrayStack<car> LANE_TO_PRINT) {
	if (LANE_TO_PRINT.isEmpty())
		cout << "NO CARS IN THIS LANE!!!" << endl;
	else {
		ArrayStack<car> temp_stack = LANE_TO_PRINT;
		car temp_array[10];

		int i;
		while (!temp_stack.isEmpty()) {
			temp_array[i] = temp_stack.peek();
			temp_stack.pop();
			i++;
		}

		for (i = sizeof(temp_array); i > sizeof(temp_array); i--) {
			cout << sizeof(temp_array) - i << temp_array[i].get_license() << temp_array[i].get_move_count << endl;
		}
		
	}
}

*/


#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

#include "ArrayStack.h"
#include "car.h"

class garage {
	ArrayStack<car> lane1;
	ArrayStack<car> lane2;
	ArrayStack<car> street;

	bool street_flag = false;

	/* DONE */
	ArrayStack<car> * garage_search(car CAR_ID);
	//Searches for car license.
	//POST: On succesful search, return lane address. Otherwise, throws error.
	
	/* DONE */
	ArrayStack<car> * get_next_available_lane(ArrayStack<car> EXCLUDED_LANE, char operation);
	//POST: Returns the next lane with avaliable space based on the lane that you do not want your target car going into.



	/* DONE */
	void move_top_car_to_next_avaliable_lane(ArrayStack<car> & LANE_TO_MOVE_FROM);
	//POST: Moves car at the top of the lane to either a free lane or the street, then increments the car's move_count by 1.

	/* DONE */
	void return_from_street();
	//Used by depart to clean out the streets if any cars were moved to the street.
	//PRE: street_flag has to be true
	//POST: Goes through every single car in street and uses arrival() to place in next avaliable lane.
	//After the operation is completed, street_flag becomes false again.

public:
	/* DONE */
	bool arrival(car INCOMINGCAR);
	//Place incoming car into the next avaliable lane. Precedence: lane1 > lane2

	/* DONE */
	void depart(car targetCar);

	

};



ArrayStack<car>* garage::garage_search(car targetCar) {

	//Search for car by license string.
	if (lane1.search(targetCar)) {
		return &lane1;
	}
	else if (lane2.search(targetCar)) {
		return &lane2;
	}

	//Needed in order to avoid second search
	else {
		throw 0;
	}
}

ArrayStack<car>* garage::get_next_available_lane(ArrayStack<car> EXCLUDED_LANE, char operation) {

	switch (operation) {
	case 'A':
		if (!lane1.isFull()) {
			return &lane1;
		}
		else if (!lane2.isFull()) {
			return &lane2;
		}
		else {
			throw "No more cars can be accepted";
		}
	case 'D':
		if (!lane1.isFull() && ( ( !(lane1.isEmpty())) && !(lane1.peek() == EXCLUDED_LANE.peek()) ) || (lane1.isEmpty()) ) {
			return &lane1;
		} //we can use this even if it's empty actually...
		else if (!lane2.isFull() && ((!(lane2.isEmpty())) && !(lane2.peek() == EXCLUDED_LANE.peek())) || (lane2.isEmpty())) {
			return &lane2;
		}
		else {
			street_flag = true;
			return &street;
		}
	default:
		throw "UNKNOWN ERROR";
	}
	

}
void garage::move_top_car_to_next_avaliable_lane(ArrayStack<car> & LANE_TO_MOVE_FROM) {

	car temp_car;

	//Increase the CAR_TO_MOVE's move counter
	temp_car = LANE_TO_MOVE_FROM.peek();
	temp_car.increase_move_count();

	//Push the car from LANE_TO_MOVE_FROM's top to the next avaliable lane
	get_next_available_lane(LANE_TO_MOVE_FROM, 'D')->push(temp_car);


	//Now that the car is present in the LANE_TO_MOVE_TO, we can pop this car from LANE_TO_MOVE_FROM
	LANE_TO_MOVE_FROM.pop();
}
void garage::return_from_street() {

	while (!street.isEmpty()) {
		move_top_car_to_next_avaliable_lane(street);
	}
	street_flag = false;
}

bool garage::arrival(car targetCar) {
	try {
		ArrayStack<car> * targetLane = get_next_available_lane(street,'A');
		targetLane->push(targetCar);

		return true;
	}
	catch (string error) {
		cout << error << endl;
		return false;
	}
}

void garage::depart(car targetCar) {

	//Function cannot properly execute if target car is not found.
	try {
		//Get lane of target car using a dummy!targetCar with the same license as the targetCar
		ArrayStack<car> *LANE_TO_MOVE_FROM = garage_search(targetCar);

		//While the targetCar is not the top of the lane, continue to move cars to avaliable lanes.
		while (!(LANE_TO_MOVE_FROM->peek() == targetCar)) {
			move_top_car_to_next_avaliable_lane(*LANE_TO_MOVE_FROM);
		}

		//When targetCar is the top car of the lane, cout message containing move count
		cout << "Car " << targetCar.get_license() << ", which has moved " << LANE_TO_MOVE_FROM->peek().get_move_count() << " time(s) has departed." << endl;

		//Pop the targetCar
		LANE_TO_MOVE_FROM->pop();

		//Put cars in street back into lanes if cars were ever moved to the street.
		if (street_flag) {
			return_from_street();
		}
	}
	catch (int error) {
		cout << error << endl;
	}
}
