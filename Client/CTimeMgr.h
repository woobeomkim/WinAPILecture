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
	
	double m_dDT = 0.; // ������ ���� �ð���
	double m_dAcc = 0.;
	UINT m_iCallCount = 0; // �ʴ� ȣ�� Ƚ��
	UINT m_iFPS = 0;
	// FPS
	// 1 �����Ӵ� �ð� (delta time)

};

