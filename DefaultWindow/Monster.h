#pragma once
#include "Object.h"
class CMonster : public CObject
{
public:
	CMonster();
	~CMonster();

public:
	void Initialize() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	bool bCheck;
	int iHp;
};

