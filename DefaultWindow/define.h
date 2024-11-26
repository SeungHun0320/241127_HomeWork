#pragma once

#define WINCX 800
#define WINCY 600

#define PURE = 0
#define PI   3.141592f

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

extern HWND g_hWnd;

typedef struct tagInfo
{
	float fX, fY;    // �߽����� ����ϱ� ���� ��ǥ
	float fCX, fCY;  // ����, ���� ����

}INFO;

template<typename T>
void Safe_Delete(T& p)
{
	if (p != nullptr)
	{
		delete p;
		p = nullptr;
	}
}