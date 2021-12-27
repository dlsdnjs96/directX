#include "stdafx.h"

struct VertexColor
{
	D3DXVECTOR3 position;
	D3DXCOLOR	color;
};

class Execute final
{
public: 
	Execute();
	~Execute();

	void Update();
	void Render();

private:
	class Graphics* graphics = nullptr;

	VertexColor* vertices = nullptr;
	ID3D11Buffer* vertex_buffer = nullptr;

	uint* indices = nullptr;
	ID3D11Buffer* index_buffer = nullptr;

	ID3D11InputLayout* input_layout = nullptr;

	ID3D11VertexShader* vertex_shader = nullptr;
	ID3DBlob* vs_blob = nullptr;

	ID3D11PixelShader* pixel_shader = nullptr;
	ID3DBlob* ps_blob = nullptr;

	D3DXMATRIX world;		// 4x4
	D3DXMATRIX view;
	D3DXMATRIX projection;

	// 좌표계
	// OpenGL  - Right Hand
	// DirectX - Left Hand
};


// Rendering Pipline
// IA - VS - RS - PS - OM

// IA : Input Assembler
//		- Vertext에 대한 정보

// VS : Vertex Shader
//		- Transform (정점들의 공간을 변환)

// RS : Rasterizer
//		- 3D데이터를 2D데이터로 바꿔주는 과정
//		- NDC(Normalized Device Coordinate) 좌표계

// (x, y, z, w)
// w값이 0일시 방향값
// w값이 0이 아닐시 위치값

// Local		: 설계상의 좌표				┐
// World		:							│
// View			: 시야에 보이는 공간			│
// Projection	: 3D를 2D로 변환시킨 공간		│
// Clip			: Homogeneous space - 동차	┘VS
// NDC			: Euclidean space			┐
// Viewport		:							┘RS