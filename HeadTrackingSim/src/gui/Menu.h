#pragma once

class Menu
{
public:
	Menu();
	void initialize(bool* showTestWindow, bool* showCameraWindow);
	void update();
	void terminate();
private:
	bool* showTestWindow;
	bool* showCameraWindow;
};
