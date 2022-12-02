#pragma once
#include "Logger.h"

bool Logger::openStream(const std::string& name, const std::ios::openmode mode) {

	std::ofstream* stream = new std::ofstream(name, mode);
	if (stream->good()) { 
		logStreams[name] = stream;
		return true; 
	}

	return false;
}

bool Logger::closeStream(const std::string& name) {

	for (const std::string& streamName : getStreamNames()) {

		if (name == streamName) {

			LogStream const stream = logStreams[streamName];

			stream->close();

			delete stream;

			logStreams.erase(streamName);

			return true;
		}
	}

	return false;

}

const StreamNames Logger::getStreamNames() {

	StreamNames streamNames;

	for (const auto& [streamName, dummy] : logStreams) { streamNames.insert(streamName); }

	return streamNames;
}

void Logger::Log(const std::string& streamName, const std::string& message, const bool addNewLine, const bool checkIfStreamExists) {

	// Check if stream exists before writing
	if (checkIfStreamExists) {

		const StreamNames streamNames = getStreamNames();

		bool exists = std::find(streamNames.begin(), streamNames.end(), streamName) != streamNames.end();

		if (!exists) { return; }

	}

	*logStreams[streamName] << message;

	if (addNewLine) { *logStreams[streamName] << "\n"; }

}

void Logger::LogToGroup(const StreamNames& streamNames, const std::string& message) {

	for (const auto& name : streamNames) { Log(name, message); }

}