#include <iostream>
#include "Logger.h"

int main() {
	Logger::openStream("Log.log");
	Logger::Log("Log.log", "Hello", true);
	Logger::closeStream("Log.log");
	return 0;
}