#pragma once
#include "stdafx.h"

class Graphics final { // final : ��� �Ұ�
public:
	Graphics();
	~Graphics();

	void Initialize();
	void CreateBackBuffer(const uint& width, const uint& height);

	auto GetDevice() -> ID3D11Device* { return device; }
	auto GetDeviceContext() -> ID3D11DeviceContext* { return device_context; }

	void Begin();
	void End();

private:
	ID3D11Device* device						= nullptr; // �ڿ��� �����ϴ� ����
	ID3D11DeviceContext* device_context			= nullptr; // ���������ο� �����ϴ� ����
	IDXGISwapChain* swap_chain					= nullptr; // ����� ����
	ID3D11RenderTargetView* render_target_view	= nullptr; // ��ȭ�� ����

	D3D11_VIEWPORT viewport						= { 0 };		// �׷����� ����
	D3DXCOLOR clear_color						= 0xff555566;	// ȭ�� �ʱ�ȭ
};

// Com Interface : ���� �Ҵ� �Ұ�, Desc�ʿ�, Release�� �Ҵ�����

// DirectX - API
// OpenGL : DirectX���� �� �� �پ��� �÷����� ��� ����(����ϵ�..)