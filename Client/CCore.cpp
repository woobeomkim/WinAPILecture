#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"
#include "CCollisionMgr.h"
#include "CEventMgr.h"

CCore::CCore() 
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hdc);
	DeleteDC(m_backdc);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// �ػ󵵿� �°� ������ ũ�� ����

	RECT windowRect = { 0,0,_ptResolution.x,_ptResolution.y };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, 0);

	m_hdc = GetDC(m_hWnd);

	// ���� ���۸� �뵿�� ��Ʈ�ʰ� dc�� �����
	m_hBit = CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	
	m_backdc = CreateCompatibleDC(m_hdc);
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_backdc, m_hBit);
	DeleteObject(hOldBit);

	// ���� ��� �� �� �� �귯�� ����
	CreateBrushPen();
	
	// Manager �ʱ�ȭ
	CPathMgr::GetInstance()->init();
	CTimeMgr::GetInstance()->init();
	CKeyMgr::GetInstance()->init();
	CSceneMgr::GetInstance()->init();

	Vec2 vPos = Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y / 2));

	return S_OK;
}


void CCore::progress()
{
	// Manager Update
	CTimeMgr::GetInstance()->update();
	CKeyMgr::GetInstance()->update();
	
	// �� ������Ʈ
	CSceneMgr::GetInstance()->update();
	
	// �浹üũ
	CCollisionMgr::GetInstance()->update();

	// ============
	// Rendering
	// ============

	Rectangle(m_backdc, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInstance()->render(m_backdc);

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_backdc, 0, 0, SRCCOPY);

	CTimeMgr::GetInstance()->render();

	// �̺�Ʈ ���� ó��
	CEventMgr::GetInstance()->update();
}

void CCore::CreateBrushPen()
{
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	//red pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

	//green pen
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

	//blue pen
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}


