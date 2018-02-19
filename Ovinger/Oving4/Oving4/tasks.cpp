#include <iostream>
#include "tasks.h"
#include "tests.h"

void taskOne() {
	std::cout << "Kjører testCallByValue():" << std::endl;
	testCallByValue();
	std::cout << "Kjører testCallByPointer():" << std::endl;
	testCallByPointer();
	std::cout << "Kjører testSwapNumbers():" << std::endl;
	testSwapNumbers();
}
