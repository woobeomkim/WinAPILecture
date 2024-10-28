#pragma once
#include "CObject.h"

class TripleMissile : public CObject
{
public:
	TripleMissile();
	~TripleMissile();

	virtual void update() ;
	virtual void render(HDC _dc);

	void SetDir(bool _bUp)
	{
		if (_bUp)
			m_fDir = -1.f;
		else
			m_fDir = 1.f;
	}

private:
	CLONE(TripleMissile);

private:
	float m_fDir = 1;  // 1 위쪽 -1 아래쪽
	float m_fSpeed = 600.0f;

};

