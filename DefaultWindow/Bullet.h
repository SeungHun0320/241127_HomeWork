#pragma once
#include "Object.h"

enum DIRECTION {ZERO, UP, DOWN, LEFT, RIGHT};

class CBullet : public CObject
{
public:
	CBullet();
	~CBullet();

public:
	void Initialize() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	DIRECTION Get_Direct();
	void Set_Direct(DIRECTION eDirect);
private:
	DIRECTION m_eDirect;
};

