#pragma once


class CCore
{
public:
	SINGLE(CCore);

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void CreateBrushPen();
public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hdc; }
	POINT GetResolution() { return m_ptResolution; }

	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
private:
	HWND m_hWnd = 0; // ���� ������ �ڵ�
	POINT m_ptResolution = {}; // ���� ������ �ػ�
	HDC m_hdc = 0; // ���� �����쿡 Draw �� DC

	HBITMAP m_hBit = 0;
	HDC m_backdc = 0;

	// ���� ����ϴ� GDI Object
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END] = {};
	HPEN m_arrPen[(UINT)PEN_TYPE::END] = {};

};

