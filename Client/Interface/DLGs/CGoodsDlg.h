#ifndef _CGoodsDlg_
#define _CGoodsDlg_
#include "tdialog.h"
#include "subclass/CSlot.h"

/**
* ���λ����� ��ǰ ��Ͻ� ���Ǵ� UI Dialog
*
* @Author		������
* @Date			2005/9/12
*/
class CGoodsDlg : public CTDialog {
public:
           CGoodsDlg(int  iDlgType);
  virtual  ~CGoodsDlg(void);
  void     Draw() override;
  void     Show() override;
  void     MoveWindow(POINT pt) override;
  void     Update(POINT     ptMouse) override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void SetIcon(CIcon* pIcon);
  void SetType(int    iType);

  enum {
    ADD_SELLLIST,
    ADD_BUYLIST
  };

private:

  enum {
    IID_TEXT_BUY = 6,
    IID_TEXT_SELL = 7,
    IID_BTN_CLOSE = 10,
    IID_BTN_CONFIRM = 11,
    IID_EDIT_PRICE = 20,
    IID_EDIT_QUANTITY = 21,
  };

  int   m_iType; /// ������� or �Ǹ���� ����
  CSlot m_Slot;
};
#endif
