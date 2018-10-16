#include "Garage.h"

ArrayStack<car> garage::search(car targetCar) {
	if (lane1.search(targetCar)) {
		return lane1;
	}
	else if (lane2.search(targetCar)) {
		return lane2;
	}
	else {
		throw "CAR NOT FOUND!";
	}
}

ArrayStack<car> garage::get_next_available_lane(ArrayStack<car> EXCLUDED_LANE) {

	//If lane1 is the excluded lane, then check lane2 and street.
	//Street will never be full, so there is no need to create exception for it.
	if (EXCLUDED_LANE.peek() == lane1.peek()) {
		if (lane2.isFull()) {
			street_flag = true;
			return street;
		}
		else {
			return lane2;
		}
	}

	//If lane2 is the excluded lane, then check lane1 and street
	//Street will never be full, so there is no need to create exception for it.
	else if (EXCLUDED_LANE.peek() == lane2.peek()) {
		if (lane1.isFull()) {
			street_flag = true;
			return street;
		}
		else {
			return lane1;
		}
	}

	//Else, it would be street; check lane1 and lane2.
	//If both are full, cout error.
	else {
		//If lane1 is not full, return lane1.
		if (!lane1.isFull()) {
			return lane1;
		}

		//Otherwise, if lane2 is not full, return lane2.
		else if (!lane2.isFull())
		{
			return lane2;
		}

		//In all other cases, throw error.
		else {
			throw "Both lanes are full. We cannot accept anymore customers, sorry!";
		}
	}

}
void garage::move_top_car_to_next_avaliable_lane(ArrayStack<car> LANE_TO_MOVE_FROM) {
		
	//LANE_TO_MOVE_TO.push(CAR_TO_MOVE)
	get_next_available_lane(LANE_TO_MOVE_FROM).push(LANE_TO_MOVE_FROM.peek());
		
	//Increase the CAR_TO_MOVE's move counter
	LANE_TO_MOVE_FROM.peek().increase_move_count();
		
	//Now that the car is present in the LANE_TO_MOVE_TO, we can pop this car from LANE_TO_MOVE_FROM
	LANE_TO_MOVE_FROM.pop();
}
bool return_from_street() {

}


bool garage::arrival(car targetCar) {
	try {
		ArrayStack<car> targetLane = get_next_available_lane(street);
		targetLane.push(targetCar);

		return true;
	}
	catch (string error) {
		cout << error << endl;
		return false;
	}
}
void garage::depart(car targetCar) {

	//Get lane of target car
	try {
		ArrayStack<car> LANE_TO_MOVE_FROM = search(targetCar);
	}
	catch (string error) {
		cout << error << endl;
	}

	//While the targetCar is not the top of the lane, continue to move cars to avaliable lanes.
	while (!(targetCar == LANE_TO_MOVE_FROM.peek())) {
		move_top_car_to_next_avaliable_lane(LANE_TO_MOVE_FROM);
	}

	//When targetCar is the top car of the lane, cout message containing move count
	cout << "Car " << targetCar.get_license() << ", which has moved " << targetCar.get_move_count() << " time(s) has departed." << endl;

	//Pop the targetCar
	LANE_TO_MOVE_FROM.pop();

}
