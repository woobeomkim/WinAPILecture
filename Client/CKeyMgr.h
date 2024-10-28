#pragma once

// 1.������ ����ȭ
// ���� ������ ������ ���� Ű�� ����, ������ �̺�Ʈ�� ��������.

// 2. Ű �Է� �̺�Ʈ ó��
// tap, hold , away

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,


};

enum class KEY_STATE
{
	NONE, // ������ �ʾҰ�, �������� ������ ���� ����
	TAP, // �� ���� ����
	HOLD, // ������ �ִ�
	AWAY, // �� �� ����
};

struct tKeyInfo
{
	KEY_STATE eState; // Ű�� ���°�
	bool bPrevPush; // ���� �����ӿ��� ���ȴ��� ����
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
public:
	void init();
	void update();

	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
private:
	vector<tKeyInfo> m_vecKey;
};

