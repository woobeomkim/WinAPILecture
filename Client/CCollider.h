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

	void OnCollision(CCollider* _pOther); // �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther); // �浹 ���Խ�
	void OnCollisionExit(CCollider* _pOther); // �浹 ������

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

	CObject* m_pOwner = nullptr; // collider�� �����ϰ� �ִ� ������Ʈ
	
	Vec2 m_vOffsetPos = {}; // ������Ʈ�� ���� ������� ��ġ

	Vec2 m_vFinalPos = {}; // finalupdate ���� �� �����Ӹ��� ���

	Vec2 m_vScale = {}; // �浹ü�� ũ��

	UINT m_iID = g_iNextID++; // �浹ü�� ������ ���̵�

	UINT m_iCol = 0;
	friend class CObject;
};

