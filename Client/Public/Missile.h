#pragma once

#include "Client_Defines.h"
#include "BlendObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
class CSubTransform;
END

BEGIN(Client)

class CMissile final : public CBlendObject
{
private:
	explicit CMissile(LPDIRECT3DDEVICE9 pGraphic_Device);
	CMissile(const CMissile& rhs);
	virtual ~CMissile() = default;
public:
	typedef struct Effect4
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_float		Speed = 3.f;
		_int		BulltType = 0;

	}EFFECT4;
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* 움직인다.(상태를 표현한다.) */
	CTransform*			m_pTransformCom = nullptr;

	CTransform*		m_pSubTransformCom = nullptr;
	/* 어떤모양으로 그릴건지?! (모델) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;	

	/* 저 모델위에 어떤 텍스쳐 올릴건지?! */
	CTexture*			m_pTextureCom = nullptr;

	/* 그린다!!! */
	CRenderer*			m_pRendererCom = nullptr;



private:
	_float				m_fFrame = 0.f;
	EFFECT4				MyType;
	
	_float				m_Texture = 0;
	_float				m_Length;
	_int				m_Type;
	_float3				m_DelayTarget;
	_float				m_Delay;
	_float				m_Speed;
	_int				Page = 1;
	
private:
	HRESULT SetUp_Components();



public:
	static CMissile* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END