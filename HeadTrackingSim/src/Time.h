#pragma once

class Time
{
public:
	Time() = delete;
	static float deltaTime();
	static float time();

	static void start(double now);
	static void frame(double now);

	static void frameCap(double spf);
private:
	static double now;
	static double lastTime;
	static double frameTime;
};