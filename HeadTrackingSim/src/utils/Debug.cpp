#include "Debug.h"

#include <ctime>
#include <cstdlib>

void Debug::log(const std::string &message)
{
	std::cout << "[" << timestamp() << "][INFO] " << message << std::endl;
}

void Debug::error(const std::string &message)
{
	std::cout << "[" << timestamp() << "][ERROR] " << message << std::endl;
}

void Debug::warning(const std::string &message)
{
	std::cout << "[" << timestamp() << "][WARNING] " << message << std::endl;
}


void Debug::longLog(const std::string& description, const std::string& longMessage)
{
	std::cout << "[" << timestamp() << "] " << description << ":" << std::endl;
	std::cout << longMessage << std::endl;
}



std::string Debug::timestamp()
{
	tm t;
	time_t now = time(nullptr);
	localtime_s(&t, &now);
	return std::to_string(t.tm_hour) + ":" + std::to_string(t.tm_min) + ":" + std::to_string(t.tm_sec);
}
