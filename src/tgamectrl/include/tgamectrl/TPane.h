#ifndef _CTPane_
#define _CTPane_
#include "winctrl.h"
#include "JContainer.h"

/**
* Dialog�������� �������� child control���� �����ϱ� ���� Container class
*   - Ŭ���̾�Ʈ�� CChatRoomDlg���� ��/�Ʒ� ������ �� Container class�� ���еǾ� �ִ�.
*
* @Author		������
* @Data			2005/8/30
*/
class TGAMECTRL_API CTPane : public CWinCtrl {
public:
          CTPane(void );
  virtual ~CTPane(void);

  void     Update(POINT ptMouse) override;
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     MoveWindow(POINT pt) override;
  void     Show() override;
  void     Hide() override;

  void      AddChild(CWinCtrl* pCtrl);
  CWinCtrl* FindChild(unsigned iID);
  CWinCtrl* Find(const char*   szName) override;

protected:
  CJContainer m_Children;
};
#endif
