#include <iostream>
#include "Logger.h"

int main() {
	Logger::openStream("Log.log");
	Logger::Log("Log.log", "Bye");
	Logger::closeStream("Log.log");
	return 0;
}