#ifndef _CTARGETMENU_
#define _CTARGETMENU_
#include "tgamectrl/TDialog.h"

class CTargetMenu : public CTDialog {
public:
          CTargetMenu(void );
  virtual ~CTargetMenu(void);

  void         Update(POINT ptMouse) override;
  void         Hide() override;
  void         Show() override;
  unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

  enum {
    IID_BTN_FRIEND = 1,
    IID_BTN_EXCHANGE,
    IID_BTN_PARTY,
    IID_BTN_INFORMATION
  };

  ///현재 다른 아바타가 타겟으로 선택되어져 있을때 그 아바타의 Idx
  int  GetTargetAvatarID() { return m_iTargetAvatarID; }
  void SetTargetAvatarID(int iTargetAvatarID) { m_iTargetAvatarID = iTargetAvatarID; }
protected:
  bool OnLButtonUp(unsigned iProcID);

protected:
  int m_iTargetAvatarID;

};
#endif
