/*
Jiali Chen
Lab 2 - The Parking Garage
In this lab, we have a garage class containing 3 array-based stacks named 'lane1', 'lane2', and 'street'.
We must handle a list of arriving and departing cars from file input while considering the mechanics of a stack.
*/



#include <iostream>
#include <iomanip>
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

	ArrayStack<car> * garage_search(car CAR_ID);
	//Searches for car license.
		//POST: On succesful search, return lane address. Otherwise, throws error.

	ArrayStack<car> * get_next_available_lane(ArrayStack<car> EXCLUDED_LANE, char operation);
		//POST: Returns the next lane with avaliable space based on the lane that you do not want your target car going into.

	void move_top_car_to_next_avaliable_lane(ArrayStack<car> & LANE_TO_MOVE_FROM);
		//POST: Moves car at the top of the lane to either a free lane or the street, then increments the car's move_count by 1.

	void return_from_street();
	//Used by depart() to clean out the streets if any cars were moved to the street.
		//PRE: street_flag has to be true
		//POST: Goes through every single car in street and uses arrival() to place in next avaliable lane.
			//After the operation is completed, street_flag becomes false again.

public:
	bool arrival(car INCOMINGCAR);
	//Place incoming car into the next avaliable lane. Precedence: lane1 > lane2

	void depart(car targetCar);
	//Removes an existing car from its lane by moving other cars out of the way until it can leave.
	
	void print_lane(ArrayStack<car>, string);
	//Prints list of selected lane

	void print_all_lanes();
	//Prints list of all lanes


	

};

/* PRIVATE METHODS */

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
			throw 0;
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
		throw 99;
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


/* PUBLIC METHODS */

bool garage::arrival(car targetCar) {
	try {
		ArrayStack<car> * targetLane = get_next_available_lane(street,'A');
		targetLane->push(targetCar);

		return true;
	}
	catch (int error) {
		switch (error) {
		case 0:
			cout << "GARAGE IS FULL! Cannot accept any more cars." << endl;
			break;
		default:
			cout << "UNKNOWN ERROR." << endl;
			break;
		}

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
void garage::print_lane(ArrayStack<car> LANE_TO_PRINT, string LANE_ID) {


	cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
		<< LANE_ID
		<< "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n" << endl;

	if (LANE_TO_PRINT.isEmpty()) {
		cout << "NO CARS IN THIS LANE!!!\n" << endl;
	}
	else {
		ArrayStack<car> temp_stack = LANE_TO_PRINT;
		car temp_array[10];

		int i = 0;
		int array_size = 0;
		int true_index = 0;
		
		while (!temp_stack.isEmpty()) {
			temp_array[i] = temp_stack.peek();
			temp_stack.pop();
			i++;
			array_size++;
		}

		cout << setw(15) << "Slot NO." << setw(15) << "LICENSE" << setw(15) << "MOVE COUNT" << endl;

		//Logic here is flawed
		for (i = array_size; i > 0; i--, true_index++) {
			cout << setw(15) << array_size - true_index << setw(15) << temp_array[array_size-i].get_license() << setw(15) << temp_array[array_size-i].get_move_count() << endl;
		}

	}
}
void garage::print_all_lanes() {
	print_lane(lane1, "LANE 1");
	print_lane(lane2, "LANE 2");
	print_lane(street, "STREET");
}
