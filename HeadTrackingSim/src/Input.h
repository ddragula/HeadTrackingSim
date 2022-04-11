#pragma once

#include <GLFW/glfw3.h>

constexpr unsigned int KEYS_ARRAY_SIZE = 65536;

class Input
{
public:
	Input();
	void setKeyState(int key, bool state);
	bool isKeyDown(int keycode) const;
private:
	bool keys[KEYS_ARRAY_SIZE];
};