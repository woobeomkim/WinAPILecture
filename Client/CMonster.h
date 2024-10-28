#pragma once

#include "CObject.h"

class CMonster : public CObject
{
public:
	virtual void update();
	
	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float _speed) { m_fSpeed = _speed; }
	void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
	void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }

	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
public:
	CMonster();
	~CMonster();

private:
	virtual CMonster* Clone() { return new CMonster(*this); }

private:
	float m_fSpeed = 100.f;
	float m_fMaxDistance = 50.f;
	Vec2 m_vCenterPos = {0.f,0.f};
	int m_iDir = 1; // 1, -1
	float m_Acc = 0.0f;
	int miHp = 5;
};

