/*
	$Header: /Client/CObjUSER.h 151   05-09-01 6:32p Raning $
*/
#ifndef	__COBJUSER_H
#define	__COBJUSER_H
#include "CObjCHAR.h"
#include "Common/CInventory.h"
#include "Common/CUserDATA.h"
#include "Interface//TypeResource.h"
#include "Interface/SlotContainer/CSkillSlot.h"
#include "Interface/SlotContainer/CItemSlot.h"
#include "Interface/SlotContainer/HotIconSlot.h"
#include "CObjCART.h"
#include <list>
#include <algorithm>

struct SummonMobInfo {
  int iIndex;
  int iCapacity;

  int iSkillIDX;

  SummonMobInfo() {
    iIndex    = 0;
    iCapacity = 0;
    iSkillIDX = 0;
  }
};

///
///	User class( for main user? )
///

class CObjUSER : public CObjAVT, public CUserDATA {
private:
          CObjUSER();
  virtual ~CObjUSER();

  static CObjUSER* m_pInstance;

public :
  static CObjUSER* Instance();
  void             Destroy();

public:

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CGameOBJ virtual functions
  /// <

  /*override*/
  int Get_TYPE() override { return OBJ_USER; }

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CAI_OBJ virtual functions
  /// <

  /*override*/
  int Get_HP() override { return GetCur_HP(); } // �����

  /*override*/
  int Get_LEVEL() override { return GetCur_LEVEL(); }
  /*override*/
  int Get_ATK() override { return GetCur_ATK(); } // ���ݷ�
  /*override*/
  int Get_DEF() override { return GetCur_DEF(); } // ����
  /*override*/
  int Get_RES() override { return GetCur_RES(); } // �׸���
  /*override*/
  int Get_HIT() override { return GetCur_HIT(); }
  /*override*/
  int Get_CHARM() override { return GetCur_CHARM(); } // �ŷ�
  /*override*/
  int Get_AVOID() override { return GetCur_AVOID(); } // ȸ�Ƿ�
  /*override*/
  int Get_SENSE() override { return GetCur_SENSE(); } // ����
  /*override*/
  int Get_CRITICAL() override { return GetCur_CRITICAL(); }

  /*override*/
  int Get_TeamNO() override { return CObjAVT::Get_TeamNO(); }

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CObjAI virtual functions
  /// <

  /*override*/
  int Get_MP() override { return GetCur_MP(); }
  /*override*/
  void Set_HP(int iHP) override;
  /*override*/
  void Set_MP(int iMP) override;

  /*override*/
  int Get_MaxHP() override { return GetCur_MaxHP(); }
  /*override*/
  int Get_MaxMP() override { return GetCur_MaxMP(); }

  /*override*/
  int Get_CON() override { return GetCur_CON(); } // ����

  /*override*/
  int GetAdd_RecoverHP() override { return this->m_btRecoverHP; }
  /*override*/
  int GetAdd_RecoverMP() override { return this->m_btRecoverMP; }

  short GetPsv_ATKSPEED() override { return this->GetPassiveSkillAttackSpeed(); }
  short GetPsv_ATKSPEED(float fCurSpeed, short nRightWeaponItemNo) override;

  int GetOri_MaxHP() override;
  int GetOri_MaxMP() override;
  /*override*/
  void RideCartToggle(bool bRide) override;

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CObjCHAR virtual functions
  /// <

  /*override*/
  int Get_INT() override { return GetCur_INT(); } // ����

  /*override*/
  int Add_HP(int iValue) override { return AddCur_HP( iValue ); }
  /*override*/
  int Add_MP(int iValue) override { return AddCur_MP( iValue ); }

  /*override*/
  int Sub_HP(int iValue) override { return SubCur_HP( iValue ); }
  /*override*/
  int Sub_MP(int iValue) override { return SubCur_MP( iValue ); }

  /*override*/
  void Add_EXP(short nExp) override;

  /*override*/
  int Get_BulletNO() override;

  /// �������� �����ġ ������ ���ؼ� ���� ����Ǿ��ִ� �ɷ¼�ġ( �нú� ��ų ���� )
  /*override*/
  int Get_DefaultAbilityValue(int iType) override { return GetCur_AbilityValue( iType ); }

  /*override*/
  int Proc(void) override;

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CObjAVT virtual functions
  /// <

  /*override*/
  void Set_SEX(BYTE btRace) override { CObjAVT::Set_SEX( btRace ); }
  /*override*/
  void Set_CON(int iValue) { SetDef_CON( iValue ); }

  /*override*/
  void Update_SPEED() override;
  /*override*/
  void Update(bool bUpdateBONE = false) override;
  /*override*/
  short GetStamina() override;
  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////	

  //////////////////////////////////////////////////////////////////////////////////////////	
  /// < Inherited from CUserDATA virtual functions
  /// <
  BYTE GetCur_MOVE_MODE() override;

private:
  /*override*/
  void SetCur_PartITEM(short nPartIdx, tagITEM& sITEM) override { this->SetPartITEM( nPartIdx, sITEM ); }
  /*override*/
  short GetCur_PartITEM(short nPartIdx) override { return GetPartITEM( nPartIdx ); }

public:

  /// ���� ��ų�� ���� ������ ���� ������ �Լ�...
  /*override*/
  short GetCur_RACE() override { return this->m_btRace; };
  /*override*/
  short GetCur_ATK_SPD() override { return Get_nAttackSPEED(); }
  /*override*/
  float GetCur_MOVE_SPEED() override { return Get_DefaultSPEED(); }
  /*override*/
  int GetCur_ATK() override;
  /*override*/
  int GetCur_DEF() override;
  /*override*/
  int GetCur_RES() override { return GetDef_RES() + m_EndurancePack.GetStateValue( ING_INC_RES ) - m_EndurancePack.GetStateValue( ING_DEC_RES ); }
  /*override*/
  int GetCur_HIT() override { return GetDef_HIT() + m_EndurancePack.GetStateValue( ING_INC_HIT ) - m_EndurancePack.GetStateValue( ING_DEC_HIT ); }
  /*override*/
  int GetCur_AVOID() override { return GetDef_AVOID() + m_EndurancePack.GetStateValue( ING_INC_AVOID ) - m_EndurancePack.GetStateValue( ING_DEC_AVOID ); }
  /*override*/
  int GetCur_CRITICAL() override;

  /*ov...   */
  void UpdateCur_Ability() override { this->UpdateAbility(); }

  /*override*/
  int GetCur_MaxHP() override;
  /*override*/
  int GetCur_MaxMP() override;
  /*override*/
  int GetCur_MaxSTAMINA() override { return 5000; }

  /*override*/
  DWORD GetCur_IngStatusFLAG() override { return this->GetIngDurationStateFLAG(); }

  /*override*/
  int GetCur_R_WEAPON() override { return this->Get_R_WEAPON(); }
  /*override*/
  int GetCur_L_WEAPON() override { return this->Get_L_WEAPON(); }

  /*override*/
  bool Quest_IsPartyLEADER() override;
  /*override*/
  int Quest_GetPartyLEVEL() override;
  /*override*/
  int Quest_GetZoneNO() override;
  /*override*/
  int Quest_DistanceFrom(int iX, int iY, int iZ) override;
  /*override*/
  int Quest_PartyMemberCNT() override;

  /*override*/
  void SetCur_TeamNO(short nTeamNO) override { SetTeamInfo( nTeamNO ); }

  /// <
  /// < end	
  //////////////////////////////////////////////////////////////////////////////////////////

  short GetCur_STAMINA();
  void  SetCur_STAMINA(short nStamina);
  //-------------------------------------------------------------------------------------
private:
  std::list<SummonMobInfo> m_SummonedMobList;
  int                      m_iSummonMobCapacity;

public:
  int  GetCur_SummonMaxCapacity();
  int  GetCur_SummonUsedCapacity() { return m_iSummonMobCapacity; }
  int  GetCur_SummonCNT() { return m_SummonedMobList.size(); }; /// ���� ���� ��ȯ�Ǿ� �ִ� NPC����(������, �� ������ 0���� ������)
  void ClearSummonedMob() {
    m_SummonedMobList.clear();
    m_iSummonMobCapacity = 0;
  }

  void AddSummonedMob(int     iIndex, int iSkillIDX);
  void SubSummonedMob(int     iIndex);
  bool GetSummonedMobInfo(int iIndex, SummonMobInfo& mobInfo);
  //-------------------------------------------------------------------------------------

  //-------------------------------------------------------------------------------------------------
  /// Get/Set property for user property
  //-------------------------------------------------------------------------------------------------	
  char Get_SEX() { return (this->m_bIsFemale) ? 1 : 0; }

  //	short							Get_WEIGHT ()				{	return	GetCur_WEIGHT ();			}

  void Set_FAME(int  iValue) { SetCur_FAME( iValue ); }
  void Set_UNION(int iValue) { SetCur_UNION( iValue ); }
  void Set_RANK(int  iValue) { SetCur_RANK( iValue ); }
  void Set_JOB(int   iValue);

  void Set_LEVEL(int        iValue) { SetCur_LEVEL( iValue ); }
  void Set_EXP(int64_t      lValue) { SetCur_EXP( lValue ); }
  void Set_BonusPOINT(short nValue) { SetCur_BonusPOINT( nValue ); }
  void Set_SkillPOINT(short nValue) { SetCur_SkillPOINT( nValue ); }

  void Set_STR(int   iValue) { SetDef_STR( iValue ); }
  void Set_DEX(int   iValue) { SetDef_DEX( iValue ); }
  void Set_INT(int   iValue) { SetDef_INT( iValue ); }
  void Set_CHARM(int iValue) { SetDef_CHARM( iValue ); }
  void Set_SENSE(int iValue) { SetDef_SENSE( iValue ); }

  int Get_BIRTH() { return GetCur_BIRTH(); } // ź����
  int Get_RANK() { return GetCur_RANK(); }   // ���
  int Get_UNION() { return GetCur_UNION(); } // �Ҽ�
  int Get_FAME() { return GetCur_FAME(); }   // ��
  int Get_JOB() { return GetCur_JOB(); }     // ����

  int Get_EXP() { return GetCur_EXP(); }
  int Get_BonusPOINT() { return GetCur_BonusPOINT(); }
  int Get_SkillPOINT() { return GetCur_SkillPOINT(); }

  BYTE Get_HeadSIZE() { return GetCur_HeadSIZE(); }
  BYTE Get_BodySIZE() { return GetCur_BodySIZE(); }

  int Get_STR() { return GetCur_STR(); } // �ٷ�
  int Get_DEX() { return GetCur_DEX(); } // ��ø

  short Get_MaxWEIGHT() { return GetCur_MaxWEIGHT(); }
  int   Get_MAG() { return GetCur_MAG(); } // ������

  void    Set_MONEY(int64_t iMoney) { SetCur_MONEY( iMoney ); }
  int64_t Get_MONEY() { return GetCur_MONEY(); } // ��
  void    Add_MONEY(int iMoney) { Add_CurMONEY( iMoney ); }

  short Add_ITEM(short nListRealNO, tagITEM& sITEM) override;
  void  Sub_ITEM(short nListRealNO, tagITEM& sITEM) override;

  short Add_CatchITEM(short nListRealNO, tagITEM& sITEM) override;
  short Add_ITEM(tagITEM&   sITEM) override;
  void  Set_ITEM(short      nListRealNO, tagITEM& sITEM) override;
  void  ClearITEM(WORD      wListRealNO) override;

  //-------------------------------------------------------------------------------------------------
  /// Update user states
  //-------------------------------------------------------------------------------------------------
  void UpdateAbility();
  void UpdateModelData() override { Update(); }; /// �� ������ ����..
  void UpdateInventory();

  void Init_DefaultValue(void);

  void LevelUP() {
    this->UpdateAbility();
    this->Set_HP( this->GetCur_MaxHP() );
    this->Set_MP( this->GetCur_MaxMP() );

    g_pSoundLIST->IDX_PlaySound3D( SOUND_LEVEL_UP, this->Get_CurPOS() );
  }

  CInventory* GetInventory() { return &m_Inventory; }
  short       GetEmptyInventory(short nInvPAGE) { return m_Inventory.GetEmptyInventory( nInvPAGE ); }

  //-------------------------------------------------------------------------------------------------
  /// ���� ������ ������ ��Ȱ �� ��ȣ.
  //-------------------------------------------------------------------------------------------------
  short m_nReviveZoneNO;

  //----------------------------------------------------------------------------------------------------	
  /// @brief ���� ������ ��ǲ����� �޾Ƶ��ϼ� �ִ°�?
  //----------------------------------------------------------------------------------------------------	
  bool bCanUserInput() {
    /// ���� ��ų ������ �ƴϰ�, ��ų �׼����� �ƴҶ���..
    if ( !(this->m_bCastingSTART) && (this->m_nDoingSkillIDX == 0) )
      return true;
    return false;
  }

  //-------------------------------------------------------------------------------------------------
  /// ���� ĳ������ ���������� �������� ���´�.
  /// ȸ������
  //-------------------------------------------------------------------------------------------------
  float GetDirection() {
    if ( GetPetMode() >= 0 )
      return getModelDirection( this->m_pObjCART->GetZMODEL() );
    return getModelDirection( this->m_hNodeMODEL );
  };

  //-------------------------------------------------------------------------------------------------
  /// ���� �����̳�
private:

  CSkillSlot   m_SkillSlot;
  CItemSlot    m_ItemSlot;
  CHotIconSlot m_HotIconSlot;
  short        m_nCurrWeight;
public:
  CSkillSlot*   GetSkillSlot() { return &m_SkillSlot; }
  CItemSlot*    GetItemSlot() { return &m_ItemSlot; }
  CHotIconSlot* GetHotIconSlot() { return &m_HotIconSlot; }
  /// ���ο� ��ų �߰�.
  bool AddNewSkill(int   iSkillIDX, int    iSkillSlotNO, int iSkillLevel = 0, bool bSubPOINT = false);
  bool Skill_LevelUp(int iSkillSlotNo, int iSkillIndex);
  //-------------------------------------------------------------------------------------------------

  //-------------------------------------------------------------------------------------------------
  ///Bank( ����â�� )����
  void SetBankItem(int iIndex, tagITEM& Item);
  void InitBank();
  ///���� Ȱ��ȭ�� �Ѿ��� ������ 1���ҽ�Ų��.
  void SubActiveBulletQuantity();
  //-------------------------------------------------------------------------------------------------

  //-------------------------------------------------------------------------------------------------
  /// ���ϸ��� �����ۿ� ���ؼ� ĳ������ ����, �󱼸��, �Ӹ�ī���� ��ȭ..
  void ChangeModelInfo(short nType, int iValue) override;
  //-------------------------------------------------------------------------------------------------

  //-------------------------------------------------------------------------------------------------
  /// PET ����	
  /// ���� ���� ������ �ٵǾ� Ż�� �ִ°�?
  bool CanRidePET();
  bool IsRideItem(int iIndex_);
  //-------------------------------------------------------------------------------------------------

  short GetCur_WEIGHT() override;

  void SetCurrWeight(short nWeight);

private:
  DWORD m_dwUniqueTag;           ///��ü ���忡�� ����ũ�� ID(��Ƽ���� ���)
  int   m_iServerSavedMemoCount; ///������ ����Ǿ� �ִ� ������ ����
public:
  void  SetUniqueTag(DWORD dwUniqueTag);
  DWORD GetUniqueTag();
  void  SetServerSavedMemoCount(int iCount);
  int   GetServerSavedMemoCount();
  void  DecreaseServerSavedMemoCount();

private:
  bool m_bWaitUpdateInventory;
  /// �κ��丮�� ������ ���°� ������ ���ϴ� ���̴�... 
  /// ����/Ż���� ��� ���԰����� ����� 2���Ǹ鼭 �ٱⰡ->�ȱ�� ����ȴ�.
  /// default : false

  DWORD m_dwLastBattleTime;
public:
  void SetWaitUpdateInventory(bool bWait);

  /// �������� �κ��丮 ������� ��Ŷ�� ������ ���� ������ �κ��丮�� �ٵ��� �ִ��� üũ�Ѵ�.
  bool  IsInventoryFull(std::list<tagITEM>& appendItems, std::list<pair<int,tagITEM>>& removeItems);
  bool  IsInventoryFull(std::list<tagITEM>& appendItems);
  void  SetBattleTime(DWORD                 dwTime);
  DWORD GetLastBattleTime();

  //-------------------------------------------------------------------------------------------------
  // 05.05.19 icarus::  �Ϳ� ��Ÿ���� NPC ����Ʈ ���� �۾�...
public:
  // �ڽ��� �ƹ�Ÿ�� ����Ʈ�� ���ŵǾ����� ���θ� �Ǵ�.
  // �⺻�� false, �� ���Ž� false�� ����. Object Loop���� �������� true�� ����.
  // �������� ����Ʈ ���� ��Ŷ�� ������ false�� ����.
  bool m_bQuestUpdate;

  //------------------------------------------------------------------------------------
  /// �Ʒ�� ���� �ɸ� ���¿� ���� �߰����� �ɷ�ġ ���� ����
  ///
  //------------------------------------------------------------------------------------
public:
  void Calc_AruaAddAbility() override;

protected:
  int m_AruaAddHp;
  int m_AruaAddMp;
  int m_AruaAddCritical;
  int m_AruaAddAttackPower;
  int m_AruaAddDefence;

  //------------------------------------------------------------------------------------
  /// īƮ ���� ����/�߰� : 2005/7/26 - nAvy
  //------------------------------------------------------------------------------------
protected:
  int m_PatGuageMax;

public:
  bool SetCMD_Skill2OBJ(WORD             wSrvDIST, const D3DVECTOR& PosTO, int iServerTarget, short nSkillIDX) override;
  void SetCMD_Skill2SELF(short           nSkillIDX) override;
  void SetCMD_Skill2POS(const D3DVECTOR& PosGOTO, short nSkillIDX) override;

  int  GetPatGuageMax();
  int  GetPatGuageCurrent();
  void SetPatGuageMax(int     guage);
  void SetPatGuageCurrent(int guage);
protected:
  //void			SubPatGuagePerPatSkillExcute( short nSkillIDX );
  void Cal_PatAbility();

  //------------------------------------------------------------------------
  //����ȣ::
public:
  BOOL m_PushskillIcon;
  BOOL m_PushUseItemIcon;

  DWORD m_sSkillTick, m_sPushTick;

  BOOL SetCoolTimeUseItem(char* uName, short iItem);
  BOOL SetCoolTimeSkill(char*   uName, int   iSkill);
  //------------------------------------------------------------------------

  void Set_Block_CartRide(bool ride);

};

#endif
