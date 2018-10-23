//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-1
    @file ArrayStack.cpp */
#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;	
}  // end isEmpty



//Custom function added to ArrayStack.h
template<class ItemType>
bool ArrayStack<ItemType>::isFull() const
{
	return top == MAX_STACK - 1;
}

//Custom function added to ArrayStack.h
template<class ItemType>
bool ArrayStack<ItemType>::search(ItemType target) const
{
	bool sentinel = true; //becomes false when the appropriate conditions are met
	bool found_flag = false;
	int i = 0;

	while (sentinel) {
		if (target == items[i]) {
			found_flag = true;
		}

		i++;

		//Update sentinel
		if (i > top || found_flag) {
			sentinel = false;
		}
	}

	return found_flag;
}


template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool result = false;	
	if (top < MAX_STACK - 1) 
	{
		top++;
		items[top] = newEntry;
		result = true;
	}  // end if
   
	return result;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		top--;
		result = true;
	}  // end if
   
	return result;
}  // end pop


template<class ItemType> 
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition
   
	// Stack is not empty; return top
	return items[top];
}  // end peek
// End of implementation file.

/*

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 1 
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 2
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 3
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 10
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 11
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 12
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 13
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /


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

/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
SCREEN 14
/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

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