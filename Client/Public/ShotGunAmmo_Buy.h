#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
END

BEGIN(Client)

class CShotGunAmmo_Buy final : public CGameObject
{
private:
	explicit CShotGunAmmo_Buy(LPDIRECT3DDEVICE9 pGraphic_Device);
	CShotGunAmmo_Buy(const CShotGunAmmo_Buy& rhs);
	virtual ~CShotGunAmmo_Buy() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* 움직인다.(상태를 표현한다.) */
	CTransform*			m_pTransformCom = nullptr;
	
	/* 어떤모양으로 그릴건지?! (모델) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;	

	/* 저 모델위에 어떤 텍스쳐 올릴건지?! */
	CTexture*			m_pTextureCom = nullptr;

	/* 그린다!!! */
	CRenderer*			m_pRendererCom = nullptr;

private:
	_float4x4			m_ProjMatrix;
	_float				m_fX, m_fY, m_fSizeX, m_fSizeY;

	RECT				m_rShotGunStock;
	LPD3DXFONT			m_pd3dxFont;

	_int				m_iShotGunStock;
	_int				m_iMaxShotGunStock;

	RECT				m_BuyRect;

	_bool				m_bButton;

private:
	HRESULT SetUp_Components();



public:
	static CShotGunAmmo_Buy* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END