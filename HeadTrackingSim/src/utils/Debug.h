#pragma once

#include <iostream>
#include <string>

class Debug
{
public:
	Debug() = delete;

	static void log(const std::string &message);
	static void error(const std::string &message);
	static void warning(const std::string &message);

	static void longLog(const std::string& description, const std::string& longMessage);
private:
	static std::string timestamp();
};
