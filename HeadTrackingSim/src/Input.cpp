#include "Input.h"

Input::Input()
{
	for (unsigned int i = 0; i < KEYS_ARRAY_SIZE; i++)
	{
		keys[i] = false;
	}
}

void Input::setKeyState(const int key, const bool state)
{
	keys[key] = state;
}

bool Input::isKeyDown(const int keycode) const
{
	return keys[keycode];
}
