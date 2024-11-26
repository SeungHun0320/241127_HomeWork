#pragma once
#include "define.h"
#include "Object.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

public:
	void OutRange_Bullet();
	void Hit_Bullet();

private:
	HDC m_hDC;

	CObject* m_pPlayer;
	CObject* m_pMob;
	list<CObject*> m_BulletList;

	ULONG64 m_dwTime;
	int   m_iFPS;
	TCHAR m_szFPS[16];

	RECT m_tRect;
};

