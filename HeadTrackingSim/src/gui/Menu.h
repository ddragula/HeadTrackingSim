#pragma once

class Menu
{
public:
	Menu();
	void initialize(bool* showTestWindow);
	void update();
	void terminate();
private:
	bool* showTestWindow;
};
