#include "pch.h"
#include "CTexture.h"

#include "CCore.h"

CTexture::CTexture()
{
}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void CTexture::Load(const wstring& _strFilePath)
{
	// ���Ϸ� ���� �ε��� �����͸� ��Ʈ������ ����
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	
	assert(m_hBit);
	// ��Ʈ�ʰ� ������ DC

	m_dc = CreateCompatibleDC(CCore::GetInstance()->GetMainDC());
	
	// ��Ʈ�ʰ� DC ����
	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(oldBitmap);

	// ���� ���� ����
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);

	
}