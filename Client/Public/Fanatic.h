#pragma once

#include "Client_Defines.h"
#include "BlendObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Cube;
class CSubTransform;
class CStatus;
class CVIBuffer_Knife;
class CVIBuffer_Pistol;
class CGameInstance;
END

BEGIN(Client)

class CFanatic final : public CBlendObject
{
public:
	enum STATE { STATE_STAY, STATE_WALK, STATE_RUN, STATE_FIND, STATE_MOVE, STATE_ATTACK, STATE_FALLING, STATE_DOWN, STATE_UP, STATE_END };
private:

	explicit CFanatic(LPDIRECT3DDEVICE9 pGraphic_Device);
	CFanatic(const CFanatic& rhs);
	virtual ~CFanatic() = default;
	typedef struct BulletType
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_int		BulltType = 0;

	}BULLETTYPE;
	typedef struct Effect4
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_float		Speed = 3.f;
		_int		BulltType = 0;

	}EFFECT4;
	typedef struct Effect3
	{
		CTransform* TargetTransform = nullptr;
		_float		Delay = 0.f;
		_int		BulltType = 0;

	}EFFECT3;
public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	CTransform*			pTargetTransform = nullptr;
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;
	CStatus*			m_pStatusCom = nullptr;
	CGameInstance*		pGameInstance = nullptr;
	//����(Timber)
	CSubTransform*			m_vTFTimber = nullptr;
	CVIBuffer_Knife*		m_vVITimber = nullptr;
	CTexture*				m_vTTTimber = nullptr;
	CRenderer*				m_vRDTimber = nullptr;
	//����(Pistol)
	CSubTransform*			m_vTFPistol = nullptr;
	CVIBuffer_Pistol*		m_vVIPistol = nullptr;
	CTexture*				m_vTTPistol = nullptr;
	CRenderer*				m_vRDPistol = nullptr;
	//CTransform*			pTargetTransform = nullptr;
	vector<CVIBuffer_Cube*>		m_vVI;
	vector<CSubTransform*>		m_vTF;
	vector<CTexture*>			m_vTT;
	vector<CRenderer*>			m_vRD;
	_float		AnTime = 0.f;
	_float		PTime = 0.f;
	_float		StandardAnTime = 0.f;
	_float		AnFrame;
	STATE		State = STATE_STAY;
	_bool		Action = false;
	_bool		AttackOn = true;
	_float3		vLook;
	_float3		TatgetPos;
	_float3		GunLook;
	_float3		GunPos;
	_int		iTexture = 0;
	_float		AttackDelay = 0;
	_float3		MyPos;

	_bool	MoveNo = false;
private:
	HRESULT SetUp_Components();
	HRESULT SetUp_OnTerrain();
	void Set_Part(int Part, int Local, _float3 Pos);
	void Set_Part2(CSubTransform* Part, _float3 Pos);
	void Set_Stay();

	void Falling(_float fTimeDelta);
	void Down(_float fTimeDelta);
	void Up(_float fTimeDelta);

	void Attack(_float fTimeDelta);
	void find(_float fTimeDelta);
	void Crawl(_float fTimeDelta);
	void Walk(_float fTimeDelta);
	void BackWard(_float fTimeDelta);
	void Move(_float fTimeDelta);
	void Stay(_float fTimeDelta);
	void Shot(_float fTimeDelta);
	void Summon(_float fTimeDelta);

public:
	static CFanatic* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END