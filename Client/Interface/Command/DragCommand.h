#ifndef _DragCommand_
#define _DragCommand_
#include "tcommand.h"

#include "../InterfaceType.h"

/// �κ��丮���� �и�/���� â���� ������ �̵�
class CTCmdDragItem2SeparateDlg : public CTCommand {
public:
          CTCmdDragItem2SeparateDlg(void ) {}
  virtual ~CTCmdDragItem2SeparateDlg(void) {}
  bool    Exec(CTObject*                 pObj) override;
};

/// �������� ���ٿ� ���
class CTCmdDragInven2QuickBar : public CTCommand {
public:
          CTCmdDragInven2QuickBar(void ) {};
  virtual ~CTCmdDragInven2QuickBar(void) {};
  bool    Exec(CTObject*               pObj) override;
};

/// ��ų�� ���ٿ� ���
class CTCmdDragSkill2QuickBar : public CTCommand {
public:
          CTCmdDragSkill2QuickBar(void  ) { m_nType      = DLG_TYPE_QUICKBAR; };
          CTCmdDragSkill2QuickBar(short nType) { m_nType = nType; }
  virtual ~CTCmdDragSkill2QuickBar(void ) {}
  bool    Exec(CTObject*                pObj) override;
  short   m_nType;
};

/// Ŭ�� ��ų��  ���ٿ� ��ų ���
class CTCmdDragClanSkill2QuickBar : public CTCommand {
public:
          CTCmdDragClanSkill2QuickBar(void ) {};
  virtual ~CTCmdDragClanSkill2QuickBar(void) {}
  bool    Exec(CTObject*                   pObj) override;
};

/// ���ٿ��� ������(��ų�� ����)�� ����.
class CTCmdDragItemFromQuickBar : public CTCommand {
public:
          CTCmdDragItemFromQuickBar(void ) {};
  virtual ~CTCmdDragItemFromQuickBar(void) {};
  bool    Exec(CTObject*                 pObj) override;
};

/// ���پȿ��� ��ϵ� ������(��ų�� ����)�� ��ġ �̵��Ѵ�.
class CTCmdMoveIconInQuickBar : public CTCommand {
public:
          CTCmdMoveIconInQuickBar(void ) {};
  virtual ~CTCmdMoveIconInQuickBar(void) {};
  bool    Exec(CTObject*               pObj) override;
};

/// �κ��丮���� ĳ���� â������ ����
class CTCmdDragItemEquipFromInven : public CTCommand {
public:
          CTCmdDragItemEquipFromInven(void ) {}
  virtual ~CTCmdDragItemEquipFromInven(void) {}
  bool    Exec(CTObject*                   pObj) override;
};

/// ������â �ȿ��� ������ �������� Drag�ؼ� Ż��
class CTCmdDragItemFromEquipInItemDlg : public CTCommand {
public:
          CTCmdDragItemFromEquipInItemDlg(void ) {}
  virtual ~CTCmdDragItemFromEquipInItemDlg(void) {}
  bool    Exec(CTObject*                       pObj) override;
};

/// ������â �ȿ��� �κ��丮�� �ִ� �������� Drag�ϴ� Command
class CTCmdDragItemFromInvenInItemDlg : public CTCommand {
public:
          CTCmdDragItemFromInvenInItemDlg(void ) {}
  virtual ~CTCmdDragItemFromInvenInItemDlg(void) {}
  bool    Exec(CTObject*                       pObj) override;

};

/// ������â�� �κ��丮���� ���� ������ ���λ������� �������� �̵��ϴ� Command
class CTCmdDragItem2PrivateStoreDlg : public CTCommand {
public:
          CTCmdDragItem2PrivateStoreDlg(void ) {}
  virtual ~CTCmdDragItem2PrivateStoreDlg(void) {}
  bool    Exec(CTObject*                     pObj) override;
};

/// WishList�� ������ �߰�
class CTCmdDragItem2WishList : public CTCommand {
public:
          CTCmdDragItem2WishList(void ) {}
  virtual ~CTCmdDragItem2WishList(void) {}
  bool    Exec(CTObject*              pObj) override;
};

/// ���� ������ ���λ������� �Ǹ� ��ǰ�� ���� Command
class CTCmdDragSellItemFromPrivateStoreDlg : public CTCommand {
public:
          CTCmdDragSellItemFromPrivateStoreDlg(void ) {}
  virtual ~CTCmdDragSellItemFromPrivateStoreDlg(void) {}
  bool    Exec(CTObject*                            pObj) override;
};

/// ���� ������ ���λ������� ���� ��ǰ�� ���� Command
class CTCmdDragBuyItemFromPrivateStoreDlg : public CTCommand {
public:
          CTCmdDragBuyItemFromPrivateStoreDlg(void ) {}
  virtual ~CTCmdDragBuyItemFromPrivateStoreDlg(void) {}
  bool    Exec(CTObject*                           pObj) override;
};

/// �ٸ� �ƹ�Ÿ�� ���λ������� ��ǰ�� �춧 �巡���ϴ�   Command
class CTCmdDragSellItemFromAvatarStoreDlg : public CTCommand {
public:
          CTCmdDragSellItemFromAvatarStoreDlg(void ) {}
  virtual ~CTCmdDragSellItemFromAvatarStoreDlg(void) {}
  bool    Exec(CTObject*                           pObj) override;
};

/// ���ÿ��� �巡�׾ص������ Ÿ�� �������� ���� Command
class CTCmdDragTakeoutTargetItemFromUpgradeDlg : public CTCommand {
public:
          CTCmdDragTakeoutTargetItemFromUpgradeDlg() {}
  virtual ~CTCmdDragTakeoutTargetItemFromUpgradeDlg() {}
  bool    Exec(CTObject* pObj) override;
};

/// ���ÿ��� �巡�׾ص������ ��� �������� ���� Command
class CTCmdDragTakeoutMaterialItemFromUpgradeDlg : public CTCommand {
public:
          CTCmdDragTakeoutMaterialItemFromUpgradeDlg() {}
  virtual ~CTCmdDragTakeoutMaterialItemFromUpgradeDlg() {}
  bool    Exec(CTObject* pObj) override;
};

/// ������ â���� ����â���� �������� �巡�׾ص���ϴ� Command
class CTCmdDragTakeinItem2UpgradeDlg : public CTCommand {
public:
          CTCmdDragTakeinItem2UpgradeDlg() {}
  virtual ~CTCmdDragTakeinItem2UpgradeDlg() {}
  bool    Exec(CTObject* pObj) override;
};
#endif
