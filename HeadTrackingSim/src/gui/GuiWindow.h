#pragma once

class GuiWindow
{
protected:
	GuiWindow();
	virtual void update() = 0;
public:
	virtual void initialize(bool show = false);
	bool show;
};