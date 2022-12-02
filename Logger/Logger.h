#pragma once
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using LogStream = std::ofstream*;

using StreamNames = std::set<std::string>;
using NameToStreamMap = std::unordered_map<std::string, LogStream>;

class Logger {

private:

	static inline NameToStreamMap logStreams;

public:

	static bool openStream(const std::string& name, const std::ios::openmode mode = std::ios::out);
	static bool closeStream(const std::string& name);

	static const StreamNames getStreamNames();

	static void Log(const std::string& streamName, const std::string& message,
		const bool addNewLine = false, const bool checkIfStreamExists = true);

	static void LogToGroup(const StreamNames& streamNames, const std::string& message);
};