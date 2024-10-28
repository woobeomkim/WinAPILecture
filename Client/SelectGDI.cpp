#include "pch.h"
#include "SelectGDI.h"
#include "CCore.h"

SelectGDI::SelectGDI(HDC _dc, PEN_TYPE _ePenType)
	: m_hDC(_dc) , m_hDefaultPen(nullptr), m_hDefaultBrush(nullptr)
{
	HPEN hPen = CCore::GetInstance()->GetPen(_ePenType);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen);

}

SelectGDI::SelectGDI(HDC _dc, BRUSH_TYPE _eBrushType)
	: m_hDC(_dc), m_hDefaultPen(nullptr), m_hDefaultBrush(nullptr)
{

	HBRUSH hBrush = CCore::GetInstance()->GetBrush(_eBrushType);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hBrush);

}

SelectGDI::~SelectGDI()
{
	SelectObject(m_hDC, m_hDefaultPen);
	SelectObject(m_hDC, m_hDefaultBrush);

}