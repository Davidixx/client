#ifndef _CIconSkillClan_
#define _CIconSkillClan_
#include "ciconskill.h"

/**
* Ŭ����ųǥ�ÿ� ���Ǵ�  Icon
*
* @Author	������
* @Date		2005/9/12
*/
class CIconSkillClan : public CIconSkill {
  int m_iSkillSlot;
public:
          CIconSkillClan(void );
          CIconSkillClan(int  iSkillSlot);
  virtual ~CIconSkillClan(void);

  int     GetIndex() override; /// GetSkillSlotFromIcon()
  void    SetSkillSlotToIcon(int iSkillSlot);
  int     GetSkillSlotFromIcon(); /// SetSkillSlotToIcon���� �����صξ��� ��ų���� �ε����� �����Ѵ�.
  int     GetSkillLevel() override;
  int     GetSkillIndex() override; /// CSkill���� ��ų�ε���(STB���γѹ�)�� ���ؼ� �����Ѵ�.
  CSkill* GetSkill();

  //----------------------------------------------------------------------------------------------------
  /// Overrided from CIcon
  //----------------------------------------------------------------------------------------------------
  void        Draw() override;
  void        ExecuteCommand() override;
  CIcon*      Clone() override;
  void        GetToolTip(CInfo& ToolTip, DWORD dwDialogType, DWORD dwType) override;
  const char* GetName() override;
};
#endif
