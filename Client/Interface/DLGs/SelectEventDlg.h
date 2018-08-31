#ifndef _CSelectEventDlg_
#define _CSelectEventDlg_

#include "TDialog.h"

/**
* �糪�༺�� ��������Ʈ ó�� ������ ���ø��� �Է¹޴� ���̾�α�
*	- �⺻ ������ CDialogDlg�� �����ϴ�
* 
* @Warning		�븸������ ������������ ǥ�� ����� �ٸ���(XML����Ÿ�� Ʋ���� �����ڵ�� �ڵ尡 ���еȴ�)
* @Author		������
* @Date			2005/9/14
*/
class CSelectEventDlg : public CTDialog {
public:
           CSelectEventDlg(void );
  virtual  ~CSelectEventDlg(void);
  bool     Create(const char*   IDD) override;
  void     Hide() override;
  void     Show() override;
  void     Update(POINT ptMouse) override;
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void SetTitle(const char*             pszTitle);
  void AddEvent(char*                   pszScript, int iEventID, void (*fpEventHandle)(int iEventID));
  void SetTargetClientObjectIndex(short iIndex);

private:
  enum {
    IID_BG_IMAGE = 1,
    IID_BTN_CLOSE = 10,
    IID_ZLISTBOX_EVENT = 20,
  };

  short       m_nTargetClientIdx;
  std::string m_strTitle;
};
#endif
