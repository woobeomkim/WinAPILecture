#pragma once

struct Vec2
{
	float x;
	float y;

public:
	float Length()
	{
		return sqrt(x* x + y * y);
	}

	Vec2& Normalize()
	{
		float fLen = Length();
		
		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}


public:
	Vec2() : x(0),y(0){}
	Vec2(float _x, float _y) : x(_x) ,y(_y){}

	Vec2(int _x, int _y) :x((float)_x),y((float)_y){}

	Vec2(const POINT& _pt) : x((float)_pt.x),y((float)_pt.y) {}
	Vec2& operator=(POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	Vec2 operator+(Vec2 vOther)
	{
		return Vec2(x + vOther.x, y + vOther.y);
	}

	Vec2 operator-(Vec2 vOther)
	{
		return Vec2(x - vOther.x, y - vOther.y);
	}

	Vec2 operator*(Vec2 vOther)
	{
		return Vec2(x * vOther.x, y * vOther.y);
	}

	Vec2 operator/(Vec2 vOther)
	{
		assert(!(vOther.x == 0.f || vOther.y == 0.f));
		return Vec2(x / vOther.x, y / vOther.y);
	}
};