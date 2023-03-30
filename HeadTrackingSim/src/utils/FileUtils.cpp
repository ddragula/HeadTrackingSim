#include "FileUtils.h"

#include <fstream>
#include <sstream>

#include "Debug.h"

std::string FileUtils::loadToString(const std::string &file)
{
	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
	{
		Debug::error("Can't open the file \"" + file + "\"");
		return "";
	}

	return { std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>() };
}