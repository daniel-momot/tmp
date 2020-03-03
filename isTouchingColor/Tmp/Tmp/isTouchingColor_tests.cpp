#include "isTouchingColor.h"
#include <stdexcept>
#include <iostream>

//////////////////////////////////////////////////////

void assert(bool should_be_true) {
	if (should_be_true == false)
		throw std::runtime_error("Unpassed test!");
}

void isTouchingColor_test_empty_drawable();					// must return false
void isTouchingColor_test_almost_empty_environment();		// must return false
void isTouchingColor_test_simple_touching();				// must return true
void isTouchingColor_test_simple_not_touching();			// must return true
void isTouchingColor_test_visibility();

//////////////////////////////////////////////////////

void isTouchingColor_fulltest() {
	isTouchingColor_test_empty_drawable();
	isTouchingColor_test_almost_empty_environment();
	isTouchingColor_test_simple_touching();
	isTouchingColor_test_simple_not_touching();
	isTouchingColor_test_visibility();

	std::cout << "Passed test: function Environment::isTouchingColor()\n";
}

//////////////////////////////////////////////////////

void isTouchingColor_test_empty_drawable() {
	// arrange
	Drawable empty(true);
	point p = { black, 0, 0 };
	Drawable some_drawable(true, { p });

	Environment e;
	e.AddDrawable(empty);
	e.AddDrawable(some_drawable);

	// act
	bool false_result = e.isTouchingColor(0, black);

	// assert
	assert(!false_result);
}

void isTouchingColor_test_almost_empty_environment() {
	// arrange
	point p = { black, 0, 0 };
	Drawable some_drawable(true, { p });

	Environment e;
	e.AddDrawable(some_drawable);

	// act
	bool false_result1 = e.isTouchingColor(0, black);
	bool false_result2 = e.isTouchingColor(0, white);
	bool false_result3 = e.isTouchingColor(0, red);

	// assert
	assert(!false_result1);
	assert(!false_result2);
	assert(!false_result3);
}

void isTouchingColor_test_simple_touching() {
	// arrange
	point p1 = { black, 0, 0 };
	point p2 = { black, 0, 1 };
	Drawable d1(true, { p1 });
	Drawable d2(true, { p2 });

	Environment e;
	e.AddDrawable(d1);
	e.AddDrawable(d2);

	// act
	bool true_result1 = e.isTouchingColor(0, black);
	bool true_result2 = e.isTouchingColor(1, black);

	// assert
	assert(true_result1);
	assert(true_result2);
}

void isTouchingColor_test_simple_not_touching() {
	// arrange
	point p1 = { black, 0, 0 };
	point p2 = { black, 0, 2 };
	Drawable d1(true, { p1 });
	Drawable d2(true, { p2 });

	Environment e;
	e.AddDrawable(d1);
	e.AddDrawable(d2);

	// act
	bool false_result1 = e.isTouchingColor(0, black);
	bool false_result2 = e.isTouchingColor(1, black);

	// assert
	assert(!false_result1);
	assert(!false_result2);
}

void isTouchingColor_test_visibility() {
	// arrange
	point p1 = { black, 0, 0 };
	point p2 = { black, 0, 1 };

	// both invisible -> false
	Environment e1;
	e1.AddDrawable(Drawable(false, { p1 }));
	e1.AddDrawable(Drawable(false, { p2 }));

	// both visible -> true
	Environment e2;
	e2.AddDrawable(Drawable(true, { p1 }));
	e2.AddDrawable(Drawable(true, { p2 }));

	// invisible touches visible -> true
	Environment e3;
	e3.AddDrawable(Drawable(false, { p1 }));
	e3.AddDrawable(Drawable(true, { p2 }));

	// visible touches invisible -> true
	Environment e4;
	e4.AddDrawable(Drawable(true, { p1 }));
	e4.AddDrawable(Drawable(false, { p2 }));

	// act
	bool false1 = e1.isTouchingColor(0, black);
	bool true2 = e2.isTouchingColor(0, black);
	bool true3 = e3.isTouchingColor(0, black);
	bool true4 = e4.isTouchingColor(0, black);

	// assert
	assert(!false1);
	assert(true2);
	assert(true3);
	assert(true4);
}


//////////////////////////////////////////////////////
