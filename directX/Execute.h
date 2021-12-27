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

	// ��ǥ��
	// OpenGL  - Right Hand
	// DirectX - Left Hand
};


// Rendering Pipline
// IA - VS - RS - PS - OM

// IA : Input Assembler
//		- Vertext�� ���� ����

// VS : Vertex Shader
//		- Transform (�������� ������ ��ȯ)

// RS : Rasterizer
//		- 3D�����͸� 2D�����ͷ� �ٲ��ִ� ����
//		- NDC(Normalized Device Coordinate) ��ǥ��

// (x, y, z, w)
// w���� 0�Ͻ� ���Ⱚ
// w���� 0�� �ƴҽ� ��ġ��

// Local		: ������� ��ǥ				��
// World		:							��
// View			: �þ߿� ���̴� ����			��
// Projection	: 3D�� 2D�� ��ȯ��Ų ����		��
// Clip			: Homogeneous space - ����	��VS
// NDC			: Euclidean space			��
// Viewport		:							��RS