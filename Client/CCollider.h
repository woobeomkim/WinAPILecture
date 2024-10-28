#pragma once

class CObject;

class CCollider
{
public:
	CCollider();
	~CCollider();

	CCollider(const CCollider& _origin);

	void finalupdate();
	void render(HDC _dc);

	void OnCollision(CCollider* _pOther); // 충돌 중인 경우 호출되는 함수
	void OnCollisionEnter(CCollider* _pOther); // 충돌 진입시
	void OnCollisionExit(CCollider* _pOther); // 충돌 해제시

	CCollider& operator=(CCollider& _orgin) = delete;

	void SetOffSetPos(Vec2 vPos) { m_vOffsetPos = vPos; }
	void SetScale(Vec2 vScale) { m_vScale = vScale;}

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }

	UINT GetID() { return m_iID; }

	CObject* GetObj() { return m_pOwner; }

private:
	static UINT g_iNextID;

	CObject* m_pOwner = nullptr; // collider를 소유하고 있는 오브젝트
	
	Vec2 m_vOffsetPos = {}; // 오브젝트로 부터 상대적인 위치

	Vec2 m_vFinalPos = {}; // finalupdate 에서 매 프레임마다 계산

	Vec2 m_vScale = {}; // 충돌체의 크기

	UINT m_iID = g_iNextID++; // 충돌체의 고유한 아이디값

	UINT m_iCol = 0;
	friend class CObject;
};

