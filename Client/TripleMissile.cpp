#include "pch.h"
#include "TripleMissile.h"
#include "CTimeMgr.h"

TripleMissile::TripleMissile()
{
}

TripleMissile::~TripleMissile()
{
}

void TripleMissile::update()
{
	Vec2 pos = GetPos();

	pos.y += m_fSpeed * fDT * m_fDir;

	SetPos(pos);
}

void TripleMissile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc, int(vPos.x - vScale.x / 2.f),
		int(vPos.y - vScale.y / 2.f),
		int(vPos.x + vScale.x / 2.f),
		int(vPos.y + vScale.y / 2.f));

	vPos.x -= 50.f;
	Ellipse(_dc, int(vPos.x - vScale.x / 2.f),
		int(vPos.y - vScale.y / 2.f),
		int(vPos.x + vScale.x / 2.f),
		int(vPos.y + vScale.y / 2.f));

	vPos.x += 100.f;
	Ellipse(_dc, int(vPos.x - vScale.x / 2.f),
		int(vPos.y - vScale.y / 2.f),
		int(vPos.x + vScale.x / 2.f),
		int(vPos.y + vScale.y / 2.f));
}