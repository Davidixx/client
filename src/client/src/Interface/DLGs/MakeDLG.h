#ifndef _MAKE_DLG_H
#define _MAKE_DLG_H

#include "tgamectrl/TDialog.h"
#include "tgamectrl/TContainerItem.h"
#include "../../Common/CItem.h"
#include "../../GameData/CManufacture.h"
#include "../../Common/DataTYPE.h"
#include "../../GameCommon/Item.h"
#include "../../GameCommon/IObserver.h"
#include "SubClass/CSlot.h"
#include "tgamectrl/SinglelineString.h"

class CMakeState;
class CMakeStateNormal;
class CMakeStateWait;
class CMakeComboItem;
class CMakeComboClass;

struct t_PACKET;
class CDragItem;

/**
* 제조시에 사용되는 다이얼로그

*
* @Author		최종진

* @Date			2005/9/14
*/
class CMakeDLG : public CTDialog, public IObserver {
  ///State
  friend class CMakeStateNormal;
  friend class CMakeStateWait;
  friend class CMakeStateResult;
  ///Command
  friend class CTCmdTakeInItem2MakeDlg;
  friend class CTCmdTakeOutItemFromMakeDlg;
public:

               CMakeDLG(int iType);
  virtual      ~CMakeDLG();
  void         Draw() override;
  void         Update(POINT ptMouse) override;
  void         Show() override;
  void         Hide() override;
  unsigned int Process(UINT     uiMsg, WPARAM wParam, LPARAM lParam) override;
  void         MoveWindow(POINT pt) override;
  int          IsInValidShow() override;
  bool         IsVision() override;
  bool         Create(const char* IDD) override;
  bool         IsModal() override;

  void Update(CObservable* pObservable, CTObject* pObj) override;

  enum CTRL_ID {

    IID_BTN_START = 10,
    IID_BTN_CLOSE = 11,
    IID_COMBOBOX_CLASS = 25,
    IID_COMBOBOX_ITEM = 20
  };

  void RecvResult(t_PACKET* pRecvPacket);
  void ChangeState(int      iState);

private:
  enum STATE_TYPE {
    STATE_NORMAL,
    STATE_WAIT,
    STATE_RESULT,
    STATE_MAX
  };

  ///첫번째 슬롯에 아이템이 등록된후 계산된다.
  ///만약 첫번째 아이템이 없다면 예상확률을 계산할수 없다( fMatQuality );
  void DrawSuccessPoints();
  void ReloadItemList();

private:

  BYTE    m_btRESULT;
  short   m_nStepORInvIDX;
  tagITEM m_CreateITEM;
  short   m_nPRO_POINT[g_iMaxCountMaterial];

  CDragItem*  m_pDragItem;
  CMakeState* m_pCurrState;
  CMakeState* m_pMakeState[STATE_MAX];

  CSlot              m_MakeItemSlot;     ///제조할 아이템 아이콘이 들어갈 슬롯
  std::vector<CSlot> m_listMaterialSlot; ///제조창에 올려진 아이템의 아이콘이 자리할 슬롯

  std::vector<CSinglelineString> m_vecSingleString;
};

/**
* 제조 Dialog에서 Combo에 넣어지는 item Class
*/
class CMakeComboItem : public CTContainerItem {
public:
           CMakeComboItem(tagITEM& Item);
  virtual  ~CMakeComboItem(void    ) {}
  tagITEM& GetItem();
protected:
  tagITEM m_Item;
};

class CMakeComboClass : public CTContainerItem {
public:
          CMakeComboClass(int  iClass);
  virtual ~CMakeComboClass(void) {}
  int     GetClass();
protected:
  int         m_iClass;
  std::string m_strName;
};

#endif
