#ifndef _CClanOrganizeDlg_
#include "tgamectrl/TDialog.h"

/**
* Ŭ�� â���� ���Ǵ� ���̾�α�
*	- Ŭ����ũ�� ó������ ������ �̹����� 2���� �����Ͽ� ��������� ���߿� ������ �̹����� ���� ��ϻ���Ҽ� �ִ�
* 
* @Author		������
* @Date			2005/9/12
* 
*/
class CClanOrganizeDlg : public CTDialog {
public:
           CClanOrganizeDlg(void );
  virtual  ~CClanOrganizeDlg(void);
  bool     Create(const char*    IDD) override;
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

private:
  void OnLButtonDown(unsigned uiMsg, WPARAM wParam, LPARAM lParam);
  void OrganizeClan();

  enum {
    IID_BTN_CONFIRM = 10,
    IID_BTN_CLOSE = 11,
    IID_BTN_CANCEL = 12,
    IID_EDIT_TITLE = 20,
    IID_EDIT_SLOGAN = 21,
    IID_TABLE_CLANCENTER = 30,
    IID_TABLE_CLANBACK = 40,
  };

  int m_iSelectedClanBack;   /// ������ ����̹��� ��ȣ
  int m_iSelectedClanCenter; /// ������ �����̹��� ��ȣ
};
#endif
