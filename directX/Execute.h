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
	ID3D11InputLayout* input_layout = nullptr;

	ID3D11VertexShader* vertex_shader = nullptr;
	ID3DBlob* vs_blob = nullptr;

	ID3D11PixelShader* pixel_shader = nullptr;
	ID3DBlob* ps_blob = nullptr;
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

//