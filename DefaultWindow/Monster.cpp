#include "pch.h"
#include "Monster.h"

CMonster::CMonster() : bCheck(true)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo = { 100.f, 150.f, 125.f, 125.f };
	m_fSpeed = 3;
}

void CMonster::Update()
{
	if (bCheck == true)
	{
		m_tInfo.fX += 10;
		if (750 < m_tInfo.fX)
			bCheck = false;
	}

	if (bCheck == false)
	{
		m_tInfo.fX -= 10;
		if (50 > m_tInfo.fX)
			bCheck = true;
	}

	__super::Update_Rect();
}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CMonster::Release()
{
}

