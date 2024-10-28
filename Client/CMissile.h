#pragma once
#include "CObject.h"
class CMissile : public CObject
{
public:
	CMissile();
	~CMissile();

	virtual void update();
	virtual void render(HDC _dc);

	void SetDir(float _fTheta) { m_fTheta = _fTheta; }
	void SetDir(Vec2 _vDir) 
	{
		m_vDir = _vDir;
		m_vDir.Normalize();
	}
public:

	virtual void OnCollisionEnter(CCollider* _pOther);

private:
	CLONE(CMissile);

private:
	float m_fTheta = float(PI / 4.f); // 이동방향

	Vec2 m_vDir = Vec2{1.f,1.f};

};

