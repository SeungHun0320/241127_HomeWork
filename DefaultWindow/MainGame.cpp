#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

CMainGame::CMainGame()
	: m_hDC(nullptr), m_pPlayer(nullptr),
	m_pMob(nullptr),
	m_dwTime(0), m_iFPS(0)
{
	ZeroMemory(&m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	if (m_pMob == nullptr)
	{
		m_pMob = new CMonster;
		m_pMob->Initialize();
	}

	if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
	{
		Temp->Set_Bullet(&m_BulletList);
	}
}

void CMainGame::Update()
{
	if(m_pPlayer != nullptr)
		m_pPlayer->Update();

	if (m_pMob != nullptr)
		m_pMob->Update();

	for (auto& pBullet : m_BulletList)
	{
		pBullet->Update();
	}

	Hit_Bullet();
		
}

void CMainGame::Render()
{
	++m_iFPS;

	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 50, 50, WINCX - 50, WINCY - 50);

	if (m_dwTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		
		m_iFPS = 0;
		m_dwTime = GetTickCount64();
	}
	TextOut(m_hDC, 0, 0, m_szFPS, lstrlen(m_szFPS));

	TCHAR szBuf[32] = L"";
	wsprintf(szBuf, L"Bullet : %d", m_BulletList.size());
	TextOut(m_hDC, 0, 20, szBuf, lstrlen(szBuf));

	if (m_pPlayer != nullptr)
		m_pPlayer->Render(m_hDC);

	if (m_pMob != nullptr)
		m_pMob->Render(m_hDC);

	for (auto& pBullet : m_BulletList)
	{
		pBullet->Render(m_hDC);
	}
	
	OutRange_Bullet();
}

void CMainGame::Release()
{
	Safe_Delete<CObject*>(m_pPlayer);
	Safe_Delete<CObject*>(m_pMob);

	for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObject*>);
	m_BulletList.clear();

	ReleaseDC(g_hWnd, m_hDC);
}

void CMainGame::OutRange_Bullet()
{
	for (auto iter = m_BulletList.begin();
		iter != m_BulletList.end();)
	{
		if (750 < (*iter)->Get_Info().fX || 50 > (*iter)->Get_Info().fX ||
			50 > (*iter)->Get_Info().fY || 550 < (*iter)->Get_Info().fY)
		{
			Safe_Delete<CObject*>(*iter);
			iter = m_BulletList.erase(iter);
			continue;
		}
		else
			iter++;
	}
}

void CMainGame::Hit_Bullet()
{
	for (auto iter = m_BulletList.begin();
		iter != m_BulletList.end();)
	{
		if (m_pMob == nullptr)
			break;

		if (IntersectRect(&m_tRect, (*iter)->Get_Rect(), m_pMob->Get_Rect()))
		{
			Safe_Delete<CObject*>(m_pMob);
			Safe_Delete<CObject*>(*iter);
			iter = m_BulletList.erase(iter);
			continue;
		}
		else
			iter++;
	}

}
