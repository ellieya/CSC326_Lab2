#include <iostream>
#include <fstream>

using namespace std;

#include "ArrayStack.h"
#include "car.h"

class garage : public ArrayStack<car> {
	int MAX_STACK = 10;
};