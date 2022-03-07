#pragma once
class Oval
{
public:
	int width;
	int height;

public:
	Oval();
	Oval(int _width, int _height);
	~Oval();
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};

