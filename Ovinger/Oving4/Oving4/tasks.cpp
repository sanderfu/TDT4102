#include <iostream>
#include "tasks.h"
#include "tests.h"

void taskOne() {
	std::cout << "Kj�rer testCallByValue():" << std::endl;
	testCallByValue();
	std::cout << "Kj�rer testCallByPointer():" << std::endl;
	testCallByPointer();
	std::cout << "Kj�rer testSwapNumbers():" << std::endl;
	testSwapNumbers();
}
