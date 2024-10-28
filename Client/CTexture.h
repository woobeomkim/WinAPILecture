#pragma once
#include "CRes.h"
class CTexture :
    public CRes
{
private:
    HBITMAP m_hBit = nullptr;
    HDC m_dc = nullptr;
    BITMAP m_bitInfo = {};
private:
    CTexture();
    ~CTexture();

    friend class CResMgr;
public:
    void Load(const wstring& _strFilePath);
    
    UINT Width() { return m_bitInfo.bmWidth; }
    UINT Height() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_dc; }
};

