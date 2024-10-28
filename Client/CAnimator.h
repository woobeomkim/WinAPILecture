#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
public:
	CAnimator();
	~CAnimator();

public:

	void CreateAnimation(const wstring& _strName , CTexture* _pTex,Vec2 _vLT,Vec2 _vSliceSize,Vec2 _vStep, UINT _iFrameCount);
	CAnimation* FindAnimation(const wstring& _strName);
	void Play();

	void update();
	void render(HDC _dc);
private:
	CObject* m_pOwner = nullptr; // 애니메이션 소유 오브젝트
	map<wstring, CAnimation*> m_mapAnim = {}; // 모든 애니메이션
	CAnimation* m_pCurAnim = nullptr; // 현재 재생중인 애니메이션
	friend class CObject;
};

