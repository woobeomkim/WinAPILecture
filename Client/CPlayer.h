#pragma once
#include "CObject.h"

class CTexture;

class CPlayer : public CObject
{
public:
	CPlayer();
	~CPlayer();

	virtual void update();
	virtual void render(HDC _dc);

private:
	void CreateMissile();
	void CreateTripleMissile();

	CPlayer* Clone() { return new CPlayer(*this); }
private:
	CTexture* m_pTex = nullptr;
};

