#include "GuiWindow.h"

GuiWindow::GuiWindow() : show(false)
{
}

void GuiWindow::initialize(bool show)
{
	this->show = show;
}
