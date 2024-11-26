#include "pch.h"
#include "Player.h"


CPlayer::CPlayer() : m_pBullet(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX * 0.5f, WINCY * 0.5f, 100.f, 100.f };
	m_fSpeed = 10.f;
}

void CPlayer::Update()
{
	Key_Input();
	CObject::Update_Rect();
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_W))
	{
		m_pBullet->push_back(Create_Bullet(UP));
	}

	if (GetAsyncKeyState(VK_A))
	{
		m_pBullet->push_back(Create_Bullet(LEFT));
	}

	if (GetAsyncKeyState(VK_S))
	{
		m_pBullet->push_back(Create_Bullet(DOWN));
	}

	if (GetAsyncKeyState(VK_D))
	{
		m_pBullet->push_back(Create_Bullet(RIGHT));
	}
}

CObject* CPlayer::Create_Bullet(DIRECTION eDirect)
{
	CObject* pBullet = new CBullet;

	if (CBullet* Temp = dynamic_cast<CBullet*>(pBullet))
	{
		Temp->Set_Direct(eDirect);
	}
	
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	return pBullet;
}
