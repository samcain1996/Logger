#include <iostream>
#include "Logger.h"

int main() {
	NullableLoggette newLog = Logger::newStream("new.log");
	NullableLoggette otherLog = Logger::openStream("other.txt");
	NullableLoggette oldLog = Logger::openStream("old.log");

	StreamNames logGroup { oldLog->name, otherLog->name };

	newLog->Write("New!");
	oldLog->Write("Old!");

	Logger::LogToGroup(logGroup, "Group Log!");

	return 0;
}