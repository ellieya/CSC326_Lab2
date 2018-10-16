#include <iostream>
#include <fstream>

using namespace std;

#include "ArrayStack.h"
#include "car.h"

class garage {
	ArrayStack<car> lane1;
	ArrayStack<car> lane2;
	ArrayStack<car> street;


	int search(string CAR_ID);
	//Look for CAR_ID for match case.
	//POST: On succesful search, return INDEX NO. On failed search, return -1.

	bool is_full(ArrayStack<car> LANENAME);
	//POST: Return true if lane is full.
	//We probably don't need this actually, pretty redundant

	bool return_from_street();
	//POST: Goes through every single car in street and uses arrival() to place in next avaliable lane.

public:
	bool arrival(car INCOMINGCAR);
	//Place incoming car into the next avaliable lane. Precedence: lane1 > lane2

	bool move(car INCOMINGCAR, ArrayStack<car> TARGET_LANE);
	//Place incoming car into the desired lane.

	bool move_car(ArrayStack<car> LANE_TO_MOVE_FROM);
	//POST: Moves car at the top of the lane to either a free lane or the street, then increments the car's move_count by 1.

	


};

bool garage::is_full(ArrayStack<car> targetLane) {
	return targetLane.isFull();
}

bool return_from_street() {

}

bool garage::arrival(car targetCar) {

	if (!is_full(lane1)) {
		//If lane isn't full
		lane1.push(targetCar);
	}
	else if (!is_full(lane2)) {
		lane2.push(targetCar);
	}
	else {
		cout << "Sorry! All lanes are full! We cannot accept new cars." << endl;
	}
	
}

bool garage::move(car INCOMINGCAR, ArrayStack<car> TARGET_LANE) {
	//We might not need this
}

bool garage::move_car(ArrayStack<car> LANE_TO_MOVE_FROM) {

	//If lane_to_move_from is lane1, go to lane2
	if (LANE_TO_MOVE_FROM.peek() == lane1.peek()) {

	}
	
	//If lane_to_move_from is lane2, go to lane1

	if (LANE_TO_MOVE_FROM.peek() == lane2.peek()) {
		if (is_full(lane1)) {
			//Do this if lane1 is full
				// move TOP CAR from LANE2 to STREET
		}
		else {
			//Do this if lane1 is not full
				//move TOP CAR from LANE 

		}
	}

	LANE_TO_MOVE_FROM.peek().increase_move_count();
}




/*
To-Do:
-Search function on Array
-


*/