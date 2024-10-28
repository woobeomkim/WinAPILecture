#pragma once

class CAnimator;

class CAnimation
{
public:
	CAnimation();
	~CAnimation();

	const wstring& GetName() { return m_strName; }

	void update();
	void render(HDC _dc);

private:
	void SetName(const wstring& _strName) { m_strName = _strName; }
private:
	wstring m_strName = {};
	CAnimator* m_pAnimator = nullptr;

	friend class CAnimator;
};

