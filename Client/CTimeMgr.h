#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);

public:
	void init();
	void update();
	void render();

	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
private:
	LARGE_INTEGER m_llCurCount = {};
	LARGE_INTEGER m_llPrevCount = {};
	LARGE_INTEGER m_llFrequency = {};
	
	double m_dDT = 0.; // 프레임 간의 시간값
	double m_dAcc = 0.;
	UINT m_iCallCount = 0; // 초당 호출 횟수
	UINT m_iFPS = 0;
	// FPS
	// 1 프레임당 시간 (delta time)

};

