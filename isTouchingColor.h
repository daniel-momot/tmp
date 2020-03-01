#include <stdexcept>
#include <iostream>
#include <string>

bool isTouchingColor(unsigned int drawable_id, const unsigned char[] color);

void check_isTouchingColor(bool assumed_result, unsigned int drawable_id, const unsigned char[] color) {
	
	// arrange = empty
	
	// act
	bool result = isTouchingColor(drawable_id, color);
	
	// assert
	std::string str = "function: isTouchingColor, arguments:" + string(drawable_id) + ", [" + string(color[0]) + " " + string(color[1]) + " " + string(color[2]) + "]";
	if (result == assumed_result) {
		std::cout << "Passed test " << str << "\n";
	}
	else {
		std::cout << "Unpassed test " << str << "\n";
		throw std::runtime_error("Unpassed test: " + str + "!");
	}
}

bool isTouchingColor(unsigned int drawable_id, unsigned char[] color) {
	
	return false;
}

int main() {
	
}