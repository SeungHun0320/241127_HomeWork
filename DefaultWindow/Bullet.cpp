#include "pch.h"
#include "Bullet.h"

CBullet::CBullet() : m_eDirect(ZERO)
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

void CBullet::Update()
{
	if(m_eDirect == UP)
		m_tInfo.fY -= 10;
	if (m_eDirect == DOWN)
		m_tInfo.fY += 10;
	if (m_eDirect == LEFT)
		m_tInfo.fX -= 10;
	if (m_eDirect == RIGHT)
		m_tInfo.fX += 10;

	__super::Update_Rect();
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{
}

DIRECTION CBullet::Get_Direct()
{
	return m_eDirect;
}

void CBullet::Set_Direct(DIRECTION eDirect)
{
	m_eDirect = eDirect;
}
