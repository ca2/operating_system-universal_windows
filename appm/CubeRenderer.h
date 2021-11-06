#pragma once

#include <wrl/client.h>
#include <memory>

#include "DirectXBase.h"
#include <DirectXMath.h>

struct ModelViewProjectionConstantBuffer
{
    DirectX::XMMATRIX model;
    DirectX::XMMATRIX impact;
    DirectX::XMMATRIX projection;
};

struct VertexPositionColor
{
    DirectX::XMFLOAT3 pos;
    DirectX::XMFLOAT3 color;
};

ref class CubeRenderer sealed : public DirectXBase
{
public:
	CubeRenderer();
	virtual ~CubeRenderer();
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	virtual void Render() override;
	void Update(float timeTotal, float timeDelta);

private:
	bool m_loadingComplete;

	comptr<ID3D11InputLayout> m_inputLayout;
	comptr<ID3D11Buffer> m_vertexBuffer;
	comptr<ID3D11Buffer> m_indexBuffer;
	comptr<ID3D11VertexShader> m_vertexShader;
	comptr<ID3D11PixelShader> m_pixelShader;
	comptr<ID3D11Buffer> m_constantBuffer;

	uint32 m_indexCount;
	ModelViewProjectionConstantBuffer m_constantBufferData;
};
