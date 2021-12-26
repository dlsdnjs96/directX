#pragma once
#include "stdafx.h"

class Graphics final { // final : 상속 불가
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
	ID3D11Device* device						= nullptr; // 자원을 생성하는 역할
	ID3D11DeviceContext* device_context			= nullptr; // 파이프라인에 세팅하는 역할
	IDXGISwapChain* swap_chain					= nullptr; // 백버퍼 관리
	ID3D11RenderTargetView* render_target_view	= nullptr; // 도화지 역할

	D3D11_VIEWPORT viewport						= { 0 };		// 그려지는 범위
	D3DXCOLOR clear_color						= 0xff555566;	// 화면 초기화
};

// Com Interface : 직접 할당 불가, Desc필요, Release로 할당해제

// DirectX - API
// OpenGL : DirectX보다 좀 더 다양한 플랫폼에 사용 가능(모바일등..)