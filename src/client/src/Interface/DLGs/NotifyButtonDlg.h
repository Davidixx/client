#ifndef _CNotifyButtonDlg_
#define _CNotifyButtonDlg_
#include "tgamectrl/TDialog.h"
#include <list>
class CTButton;

/**
* �˸���ư���� �����ֱ� ���� �������̽�
*	- CTDialog�� ��ӹ޾����� TDialog�� ����� ���� �Ⱦ��� �ִ�
*
* @Author		������
* @Date			2005/9/15
*/
class CNotifyButtonDlg : public CTDialog {
public:
          CNotifyButtonDlg(void );
  virtual ~CNotifyButtonDlg(void);

  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Draw() override;
  void     Update(POINT ptMouse) override;

  void Clear();
  void AddButton(CTButton* pBtn);
  void UpdatePosition();

protected:

  std::list<CTButton*> m_Children;
};
#endif
