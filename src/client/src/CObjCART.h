#ifndef _COBJCART_
#define _COBJCART_

#include "cobjchar.h"

enum enumCART_ANI {
  CART_ANI_STOP1 = 0,
  CART_ANI_MOVE,
  CART_ANI_ATTACK01,
  CART_ANI_ATTACK02,
  CART_ANI_ATTACK03,
  CART_ANI_DIE,
  CART_ANI_SPECIAL01,
  CART_ANI_SPECIAL02,
};

enum enumPETMODE_AVATAR_ANI {
  PETMODE_AVATAR_ANI_STOP1 = 0,
  PETMODE_AVATAR_ANI_MOVE,
  PETMODE_AVATAR_ANI_ATTACK01,
  PETMODE_AVATAR_ANI_ATTACK02,
  PETMODE_AVATAR_ANI_ATTACK03,
  PETMODE_AVATAR_ANI_DIE,
  PETMODE_AVATAR_ANI_SPECIAL01,
  PETMODE_AVATAR_ANI_SPECIAL02,
};

class CObjCHAR;

///
/// class for cart object
///

class CObjCART : public CObjCHAR {
protected:
  CObjCHAR* m_pObjParent;

  int     m_iCartType;
  CStrVAR m_Name;

  CCharMODEL m_CharMODEL;

  //------------------------------------------------------------------------------------
  //����ȣ:: ���� ���� 
#if defined(_GBC)
  union {
    short m_nPartItemIDX[ MAX_RIDING_PART ];

    struct {
      // ������ t_CharPART�� ����...			
      short m_nBodyIDX;
      short m_nEngineIDX;
      short m_nLegIDX;
      short m_nAbilIDX;
      short m_nWeaponIDX;
    };
  };

#else
	union 
	{
		short				m_nPartItemIDX[ MAX_RIDING_PART ];

		struct 
		{
			// ������ t_CharPART�� ����...			
			short			m_nBodyIDX;
			short			m_nEngineIDX;
			short			m_nLegIDX;
			short			m_nAbilIDX;
		} ;
	} ;
#endif
  //------------------------------------------------------------------------------------

public:
          CObjCART(void );
  virtual ~CObjCART(void);

  int m_iCurrentCartState;
  int m_iOldCartState;

  enum CART_STATE {
    CART_STATE_STOP = 0,
    CART_STATE_MOVE = 1,
    CART_STATE_ATTACK = 2,
  };

  void UnLinkChild(int iStart = 0);

  CObjCHAR* GetParent() { return m_pObjParent; }

  void SetPetParts(unsigned int iPartIDX, unsigned int iItemIDX);
  int  GetCartType() { return m_iCartType; }
  int  GetPetParts(int iPartIDX) { return m_nPartItemIDX[iPartIDX]; }

  ///
  /// īƮ�� ����Ʈ ����
  ///
  void SetEffect();
  void SetPartEffect(int         iPart);
  void SetEffectByMoveState(bool bShow = true);

  ///
  /// īƮ�� ���� ����
  ///
  void PlaySound(int     iCurrentState);
  void PlayPartSound(int iPart, int iCurrentState);
  void StopSound(int     iCurrentState);
  void StopPartSound(int iPart, int iCurrentState);

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CGameOBJ virtual functions
  /// <

  /*override*/
  int   Get_TYPE() override { return OBJ_CART; }
  char* Get_NAME() override { return m_Name.Get(); }

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CAI_OBJ virtual functions
  /// <

  /*override*/
  int Get_LEVEL() override { return 0; };
  /*override*/
  int Get_ATK() override { return 0; };
  /*override*/
  int Get_DEF() override { return 0; };
  /*override*/
  int Get_RES() override { return 0; };
  /*override*/
  int Get_HIT() override { return 0; };
  /*override*/
  int Get_CHARM() override { return 0; };
  /*override*/
  int Get_AVOID() override { return 0; };
  /*override*/
  int Get_SENSE() override { return 0; };
  /*override*/
  int Get_GiveEXP() override { return 0; };
  /*override*/
  int Get_CRITICAL() override { return 0; };

  /// <
  /// < End
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CObjAI virtual functions
  /// <

  /*override*/
  int GetANI_Stop() override;
  /*override*/
  int GetANI_Move() override;
  /*override*/
  int GetANI_Attack() override;
  /*override*/
  int GetANI_Die() override;
  /*override*/
  int GetANI_Hit() override;
  /*override*/
  int GetANI_Casting() override;
  /*override*/
  int GetANI_CastingRepeat() override;
  /*override*/
  int GetANI_Skill() override;

  /*override*/
  int Get_MP() override { return 32767; }
  /*override*/
  int Get_R_WEAPON() override { return 0; }
  /*override*/
  int Get_L_WEAPON() override { return 0; }

  /// �ִ� �����
  /*override*/
  int Get_MaxHP() override { return m_pObjParent->Get_MaxHP(); }
  /// �ִ� ����
  /*override*/
  int Get_MaxMP() override { return m_pObjParent->Get_MaxMP(); }

  /*override*/
  int Def_AttackRange() override { return 0; }

  /*override*/
  bool SetCMD_MOVE(const D3DVECTOR& PosTO, BYTE btRunMODE) override;
  /*override*/
  void SetCMD_MOVE(WORD wSrvDIST, const D3DVECTOR& PosTO, int iServerTarget) override;
  /*override*/
  bool SetCMD_STOP(void) override;
  /*override*/
  void SetCMD_ATTACK(int iServerTarget, WORD wSrvDIST, const D3DVECTOR& PosGOTO) override;

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CObjCHAR virtual functions
  /// <

public:
  /*override*/
  bool IsFemale() override { return true; }
  /*override*/
  short IsMagicDAMAGE() override { return false; }

  /*override*/
  tagMOTION* Get_MOTION(short nActionIdx) override;

  /*override*/
  void Add_EXP(short nExp) override {}
  /*override*/
  short GetOri_WalkSPEED() override { return ((m_pObjParent) ? m_pObjParent->GetOri_WalkSPEED() : 10); }
  /*override*/
  short GetOri_ATKSPEED() override { return ((m_pObjParent) ? m_pObjParent->GetOri_ATKSPEED() : 10); }
  /*override*/
  short GetOri_RunSPEED() override { return ((m_pObjParent) ? m_pObjParent->GetOri_RunSPEED() : 10); }

  //----------------------------------------------------------------------------------------------------	
  /// @brief īƮ�迭�� LIST_PAT ���� ���ݰ��� �����ʹ� ���´�.
  ///        Move Speed ���� ���� ſ�ٴ� �����Ͽ� ����� �θ𿡰� ����� �ȴ�. �ᱹ �θ��� ���ǵ带 �̿��ϸ�ȴ�.
  ///			�̴� �θ��� SpeedUpdate �� �Ҷ� �� ž�¿��ΰ� ����Ǿ ���Ǳ� �����̴�.
  ///			�׷��� Attack Speed ������ Ʋ����. �̴� ���̺��� ���;��Ѵ�.( �ƹ�Ÿ�� ���⿡ �����ϰ� ��Ÿ���..
  //----------------------------------------------------------------------------------------------------

  /*override*/
  float Get_MoveSPEED() override;
  float Get_DefaultSPEED() override;

  /*override*/
  short Get_nAttackSPEED() override;
  /*override*/
  float Get_fAttackSPEED() override;
  /*override*/
  int Get_AttackRange() override;

private:

  /*override*/
  HNODE Get_SKELETON() override { return g_DATA.Get_PetSKELETON( m_iCartType ); }

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

public:

  int GetRideAniPos();

  virtual bool Create(CObjCHAR* pParent, int iCartType, D3DVECTOR& Position);
  /// �浹�� �ʿ��� ��ġ������ �����Ѵ�.
  void CopyCollisionInformation(bool bRiding = true);

  //------------------------------------------------------------------------------
  //����ȣ::...
  CObjCHAR* m_pRideUser; //2�ν� ž���� 

  bool Create(CObjCHAR*         pTarget);
  void SetCartPartVisible(float fv);
  //------------------------------------------------------------------------------

};

#endif //_COBJCART_
