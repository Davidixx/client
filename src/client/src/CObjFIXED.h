/*
	$Header: /Client/CObjFIXED.h 22    04-08-26 12:11p Jeddli $
*/
#ifndef	__COBJFIXED_H
#define	__COBJFIXED_H
#include "CGameOBJ.h"
#include "IO_Model.h"
#include "IO_Effect.h"

///
/// �ǹ�, ����, Ǯ, ����, �Ѿ�.....
/// inherited from CGameOBJ 
///

class CObjFIXED : public CGameOBJ {
protected:
  CMODEL<CFixedPART>* m_pMODEL;
  HNODE*              m_pHNODES;

  t_HASHKEY* m_pLightMapMaterial;
  CEffect**  m_ppEFFECT;

  ///
  /// ..txt ���Ͽ��� �θ�, ���ϵ�. .. ��.. ���ĵ� ����Ʈ�� �����Ϳ� ���� ������ �԰��Ͽ�, ���� ��Ʈ�� ���Ѵ�.
  ///
  short GetPartIndex(short nPartSeq);
  bool  CreatePart(int     iCreateOrder, D3DVECTOR& Position, short nPartIdx);

public :
  CObjFIXED() {
    m_pMODEL            = nullptr, m_pHNODES  = nullptr, m_bIsVisible = false;
    m_pLightMapMaterial = nullptr, m_ppEFFECT = nullptr;
  }

  virtual ~CObjFIXED() { this->Delete(); }

  static DWORD m_dwCreateOrder;

  union {
    short m_nCnstIdx;
    short m_nTreeIdx;
  };

  /////////////////////////////////////////////////////////////////////////////////////////
  /// < Inherited form GameObj virtual functions	

  /// ���� view frustum �ȿ� �ִ°�?
  /*override*/
  bool IsInViewFrustum() override;
  /*override*/
  void InsertToScene(void) override;
  /*override*/
  void RemoveFromScene(bool bIncludeEFFECT = true) override;

  /// < end
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////
  /// > item �̳� ��Ÿ ���� ��ü�鿡�� ���� �߰������� ������ �ִ�.
  ///
  virtual char* Make_ZNAME(int iCreateOrder, short nPartIdx) =0 { *(int*)nullptr = 10; };

  virtual void Delete();

  /// > end
  //////////////////////////////////////////////////////////////////////////////////////////

  /// ��Ʈ ��� �ڵ��� ���Ѵ�.
  HNODE GetRootZNODE() { return m_pHNODES[m_pMODEL->m_nRootPART]; }

  void LinkNODE(HNODE         hTarget, CPointPART* pDummyPoint);
  void UnlinkVisibleWorld(void);
  void LinkToModel(HNODE      hModel);

  void GetScreenPOS(D3DVECTOR& PosSCR);

  void Scale(D3DVECTOR&            Scale);
  void Rotate(D3DXQUATERNION&      Rotate);
  bool IsIntersect(float&          fCurDistance) override;
  bool IsIntersectForCamera(float& fCurDistance) override;

  /// ����Ʈ�� ����..
  void SetLightMap(short nPartIdx, char* szLightMapFile, int iXPos, int iYPos, int iWidth, int iHeight);

  /// �̺�Ʈ ������Ʈ���� �������̵� �Ѵ�.
  virtual void SetPOSITION(D3DVECTOR&     Position);
  virtual bool Create(CMODEL<CFixedPART>* pMODEL, D3DVECTOR& Position, bool bCreateEffect = false);
};

//-------------------------------------------------------------------------------------------------
#endif
