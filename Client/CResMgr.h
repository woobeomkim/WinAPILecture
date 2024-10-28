#pragma once

class CTexture;

class CResMgr
{
	SINGLE(CResMgr);
public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);

private:
	map<wstring, CTexture*> m_mapTex;
};

