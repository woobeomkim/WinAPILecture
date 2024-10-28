#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CMissile.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CCollider.h"

void CMonster::update()
{
	Vec2 vCurPos = GetPos();
	
	// ���� �������� �ð��� m_fSpeed ��ŭ �̵�
	vCurPos.x += m_fSpeed * m_iDir * fDT;
	
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;
	// ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
	if (0.f < fDist)
	{
		// ���� ����
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}
	SetPos(vCurPos);
	m_vCenterPos;

	m_Acc += fDT;

	if (m_Acc >= 3.0f)
	{
		Vec2 MissilePos = GetPos();
		MissilePos.y += GetScale().y / 2.0f;

		CMissile* missile = new CMissile();
		missile->SetDir(false);
		missile->SetPos(MissilePos);
		missile->SetScale(Vec2(25.f, 25.f));

		CScene* curScene = CSceneMgr::GetInstance()->GetCurScene();
		curScene->AddObject(missile, GROUP_TYPE::DEFAULT);

		m_Acc = 0.0f;
	}


}

void CMonster::OnCollision(CCollider* _pOther)
{
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Missile_Player")
	{
		miHp -= 1;

		if(miHp<=0)
			DeleteObject(this);
	}
}

void CMonster::OnCollisionExit(CCollider* _pOther)
{
}

CMonster::CMonster()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

CMonster::~CMonster()
{
}
