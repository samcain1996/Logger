#pragma once
#include "Logger.h"

bool Logger::streamExists(const std::string& name) {
	return std::find(streamNames.begin(), streamNames.end(), name) != streamNames.end();
}

bool Logger::openStream(const std::string& name, const std::ios::openmode mode) {

	LogStreamPtr stream = std::make_shared<LogStream>(name, mode);
	if (stream->good() && streamNames.insert(name).second) {
		logStreams[name] = stream;
		return true; 
	}

	return false;
}

bool Logger::closeStream(const std::string& name) {

	// Check if stream exists
	if (!streamExists(name)) { return false; }

	// Close and delete stream
	logStreams[name]->close();
	logStreams.erase(name);

	return true;

}

void Logger::Log(const std::string& streamName, const std::string& message, const bool checkIfStreamExists) {

	// Check if stream exists before writing
	if (checkIfStreamExists) {

		if (!streamExists(streamName)) { return; }
	}

	*logStreams[streamName] << message;

}

void Logger::LogLine(const std::string& streamName, const std::string& message, const bool checkIfStreamExists) {
	Log(streamName, message + "\n", checkIfStreamExists);
}

void Logger::LogToGroup(const StreamNames& streamNames, const std::string& message) {
	for (const std::string& name : streamNames) { Log(name, message); }
}