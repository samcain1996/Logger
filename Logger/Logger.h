#pragma once
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using LogStream = std::ofstream;
using LogStreamPtr = std::shared_ptr<std::ofstream>;

using StreamNames = std::set<std::string>;
using NameToStreamMap = std::unordered_map<std::string, LogStreamPtr>;

class Logger {

private:

	static inline NameToStreamMap logStreams;
	static inline StreamNames streamNames;

public:

	static bool streamExists(const std::string& name);

	static bool openStream(const std::string& name, const std::ios::openmode mode = std::ios::out);
	static bool closeStream(const std::string& name);

	static void Log(const std::string& streamName, const std::string& message,
		const bool checkIfStreamExists = true);
	static void LogLine(const std::string& streamName, const std::string& message,
		const bool checkIfStreamExists = true);

	static void LogToGroup(const StreamNames& streamNames, const std::string& message);
};