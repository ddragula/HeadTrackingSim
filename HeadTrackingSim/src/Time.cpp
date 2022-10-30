#include "Time.h"

#ifdef _WIN32
#include <windows.h>
#define delay(ms) Sleep(ms)
#else
#include <unistd.h>
#define delay(ms) usleep(ms * 1000)
#endif

double Time::now = 0.0;
double Time::lastTime = 0.0;
double Time::frameTime = 0.0;

float Time::deltaTime()
{
	return static_cast<float>(frameTime);
}

float Time::time()
{
	return static_cast<float>(now);
}

void Time::start(double now)
{
	lastTime = now;
}

void Time::frame(double now)
{
	Time::now = now;
	frameTime = now - lastTime;
	lastTime = now;
}

void Time::frameCap(double spf)
{
	if (frameTime < spf)
	{
		delay(static_cast<unsigned long>((spf - frameTime) * 1000.0));
	}
}
