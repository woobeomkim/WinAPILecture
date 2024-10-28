#include "pch.h"
#include "CPathMgr.h"
#include "CCore.h"

CPathMgr::CPathMgr()
{
}

CPathMgr::~CPathMgr()
{
}

void CPathMgr::init()
{
	GetCurrentDirectory(255, m_szContentPath);

	int iLen = (int)wcslen(m_szContentPath);

	for (int i = iLen - 1; i >= 0; i--)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");
	// 상위 폴더로
	// + bin\\content\\

	// asfa\\awegawegaweg\\awegwaeg\0aegwsdafasd

	SetWindowText(CCore::GetInstance()->GetMainHwnd(), m_szContentPath);
}
