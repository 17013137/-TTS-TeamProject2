#pragma once

#include "Base.h"

BEGIN(Engine)

class CLayer final : public CBase
{
public:
	CLayer();
	virtual ~CLayer() = default;

public:
	class CComponent* Get_Component(const _tchar* pComponentTag, _uint iIndex = 0);

public:
	HRESULT Add_GameObject(class CGameObject* pGameObject);
	void Tick(_float fTimeDelta);
	void LateTick(_float fTimeDelta);
	list<class CGameObject*>* Get_ObjList() { return &m_ObjectList; }

private:
	list<class CGameObject*>			m_ObjectList;
	typedef list<class CGameObject*>	OBJECTLIST;

public:
	static CLayer* Create();
	virtual void Free() override;
};

END