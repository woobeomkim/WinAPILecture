#pragma once

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);
public:
	void init();
	void update();
	void render(HDC _dc);

	CScene* GetCurScene() { return m_pCurScene; }

private:
	void ChangeScene(SCENE_TYPE _eNext);
	friend class CEventMgr;

private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END] = {}; // ��� �� ���
	CScene* m_pCurScene = nullptr; // ���� ��
};

