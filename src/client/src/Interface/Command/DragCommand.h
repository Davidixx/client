#ifndef _DragCommand_
#define _DragCommand_
#include "tgamectrl/tcommand.h"

#include "../InterfaceType.h"

/// 인벤토리에서 분리/분해 창으로 아이템 이동
class CTCmdDragItem2SeparateDlg : public CTCommand {
public:
          CTCmdDragItem2SeparateDlg(void ) {}
  virtual ~CTCmdDragItem2SeparateDlg(void) {}
  bool    Exec(CTObject*                 pObj) override;
};

/// 아이템을 퀵바에 등록
class CTCmdDragInven2QuickBar : public CTCommand {
public:
          CTCmdDragInven2QuickBar(void ) {};
  virtual ~CTCmdDragInven2QuickBar(void) {};
  bool    Exec(CTObject*               pObj) override;
};

/// 스킬을 퀵바에 등록
class CTCmdDragSkill2QuickBar : public CTCommand {
public:
          CTCmdDragSkill2QuickBar(void  ) { m_nType      = DLG_TYPE_QUICKBAR; };
          CTCmdDragSkill2QuickBar(short nType) { m_nType = nType; }
  virtual ~CTCmdDragSkill2QuickBar(void ) {}
  bool    Exec(CTObject*                pObj) override;
  short   m_nType;
};

/// 클랜 스킬을  퀵바에 스킬 등록
class CTCmdDragClanSkill2QuickBar : public CTCommand {
public:
          CTCmdDragClanSkill2QuickBar(void ) {};
  virtual ~CTCmdDragClanSkill2QuickBar(void) {}
  bool    Exec(CTObject*                   pObj) override;
};

/// 퀵바에서 아이템(스킬등 포함)을 뺀다.
class CTCmdDragItemFromQuickBar : public CTCommand {
public:
          CTCmdDragItemFromQuickBar(void ) {};
  virtual ~CTCmdDragItemFromQuickBar(void) {};
  bool    Exec(CTObject*                 pObj) override;
};

/// 퀵바안에서 등록된 아이템(스킬등 포함)을 위치 이동한다.
class CTCmdMoveIconInQuickBar : public CTCommand {
public:
          CTCmdMoveIconInQuickBar(void ) {};
  virtual ~CTCmdMoveIconInQuickBar(void) {};
  bool    Exec(CTObject*               pObj) override;
};

/// 인벤토리에서 캐릭터 창으로의 장착
class CTCmdDragItemEquipFromInven : public CTCommand {
public:
          CTCmdDragItemEquipFromInven(void ) {}
  virtual ~CTCmdDragItemEquipFromInven(void) {}
  bool    Exec(CTObject*                   pObj) override;
};

/// 아이템창 안에서 장착된 아이템을 Drag해서 탈착
class CTCmdDragItemFromEquipInItemDlg : public CTCommand {
public:
          CTCmdDragItemFromEquipInItemDlg(void ) {}
  virtual ~CTCmdDragItemFromEquipInItemDlg(void) {}
  bool    Exec(CTObject*                       pObj) override;
};

/// 아이템창 안에서 인벤토리에 있는 아이템을 Drag하는 Command
class CTCmdDragItemFromInvenInItemDlg : public CTCommand {
public:
          CTCmdDragItemFromInvenInItemDlg(void ) {}
  virtual ~CTCmdDragItemFromInvenInItemDlg(void) {}
  bool    Exec(CTObject*                       pObj) override;

};

/// 아이템창의 인벤토리에서 내가 개설한 개인상점으로 아이템을 이동하는 Command
class CTCmdDragItem2PrivateStoreDlg : public CTCommand {
public:
          CTCmdDragItem2PrivateStoreDlg(void ) {}
  virtual ~CTCmdDragItem2PrivateStoreDlg(void) {}
  bool    Exec(CTObject*                     pObj) override;
};

/// WishList에 아이템 추가
class CTCmdDragItem2WishList : public CTCommand {
public:
          CTCmdDragItem2WishList(void ) {}
  virtual ~CTCmdDragItem2WishList(void) {}
  bool    Exec(CTObject*              pObj) override;
};

/// 내가 개설한 개인상점에서 판매 물품을 빼는 Command
class CTCmdDragSellItemFromPrivateStoreDlg : public CTCommand {
public:
          CTCmdDragSellItemFromPrivateStoreDlg(void ) {}
  virtual ~CTCmdDragSellItemFromPrivateStoreDlg(void) {}
  bool    Exec(CTObject*                            pObj) override;
};

/// 내가 개설한 개인상점에서 매입 물품을 빼는 Command
class CTCmdDragBuyItemFromPrivateStoreDlg : public CTCommand {
public:
          CTCmdDragBuyItemFromPrivateStoreDlg(void ) {}
  virtual ~CTCmdDragBuyItemFromPrivateStoreDlg(void) {}
  bool    Exec(CTObject*                           pObj) override;
};

/// 다른 아바타의 개인상점에서 물품을 살때 드래그하는   Command
class CTCmdDragSellItemFromAvatarStoreDlg : public CTCommand {
public:
          CTCmdDragSellItemFromAvatarStoreDlg(void ) {}
  virtual ~CTCmdDragSellItemFromAvatarStoreDlg(void) {}
  bool    Exec(CTObject*                           pObj) override;
};

/// 제련에서 드래그앤드랍으로 타겟 아이템을 빼는 Command
class CTCmdDragTakeoutTargetItemFromUpgradeDlg : public CTCommand {
public:
          CTCmdDragTakeoutTargetItemFromUpgradeDlg() {}
  virtual ~CTCmdDragTakeoutTargetItemFromUpgradeDlg() {}
  bool    Exec(CTObject* pObj) override;
};

/// 제련에서 드래그앤드랍으로 재료 아이템을 빼는 Command
class CTCmdDragTakeoutMaterialItemFromUpgradeDlg : public CTCommand {
public:
          CTCmdDragTakeoutMaterialItemFromUpgradeDlg() {}
  virtual ~CTCmdDragTakeoutMaterialItemFromUpgradeDlg() {}
  bool    Exec(CTObject* pObj) override;
};

/// 아이템 창에서 제련창으로 아이템을 드래그앤드랍하는 Command
class CTCmdDragTakeinItem2UpgradeDlg : public CTCommand {
public:
          CTCmdDragTakeinItem2UpgradeDlg() {}
  virtual ~CTCmdDragTakeinItem2UpgradeDlg() {}
  bool    Exec(CTObject* pObj) override;
};
#endif
