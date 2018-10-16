/*
To-do:
-Ok think about how the we're going to stick the cars from file
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
	ArrayStack<car> search(car CAR_ID);
	//Searches for car license.
	//POST: On succesful search, return lane. Otherwise, throws error.
	
	/* DONE */
	ArrayStack<car> get_next_available_lane(ArrayStack<car> EXCLUDED_LANE);
	//POST: Returns the next lane with avaliable space based on the lane that you do not want your target car going into.

	/* DONE */
	void move_top_car_to_next_avaliable_lane(ArrayStack<car> LANE_TO_MOVE_FROM);
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