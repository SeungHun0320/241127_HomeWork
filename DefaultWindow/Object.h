#pragma once
#include "define.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();

public:
	INFO Get_Info() { return m_tInfo; }
	RECT* Get_Rect() { return &m_tRect; }

	void Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC hDC)PURE;
	virtual void Release()PURE;

public:
	void Update_Rect();

protected:
	INFO m_tInfo;   // 위치 정보를 저장할 구조체?
	RECT m_tRect;   // 그리기용 렉트

	float m_fSpeed; // 속도
};

