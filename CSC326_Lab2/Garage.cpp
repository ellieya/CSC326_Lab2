#include "Garage.h"

 void garage::garage_search(car targetCar, ArrayStack<car> * target_holder) {

	//Search for car by license string.
	if (lane1.search(targetCar)) {
		target_holder = lane1;
	}
	else if (lane2.search(targetCar)) {
		target_holder = lane2;
	}
	else {
		throw 0;
	}
}

ArrayStack<car>* garage::get_next_available_lane(ArrayStack<car> EXCLUDED_LANE) {

	if (!lane1.isFull()) {
		return &lane1;
	} else if (!lane2.isFull()) {
		return &lane2;
	}
	else {
		street_flag = true;
		return &street;
	}

}
void garage::move_top_car_to_next_avaliable_lane(ArrayStack<car> LANE_TO_MOVE_FROM) {
		
	//LANE_TO_MOVE_TO.push(CAR_TO_MOVE)
	get_next_available_lane(LANE_TO_MOVE_FROM)->push(LANE_TO_MOVE_FROM.peek());
		
	//Increase the CAR_TO_MOVE's move counter
	LANE_TO_MOVE_FROM.peek().increase_move_count();
		
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
		ArrayStack<car> * targetLane = get_next_available_lane(street);
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
		ArrayStack<car> * LANE_TO_MOVE_FROM = new ArrayStack<car>;
		garage_search(targetCar, LANE_TO_MOVE_FROM);

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
