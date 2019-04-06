#ifndef _PrivateChatDlg_
#define _PrivateChatDlg_
#include "tgamectrl/TDialog.h"
#include "tgamectrl/IActionListener.h"

/**
* 1:1��ȭ�� ���Ǵ� ���̾�α�
*
* @Author		������
* @Date			2005/9/12
*/
class CPrivateChatDlg : public CTDialog, public IActionListener {
public:
          CPrivateChatDlg(int  iDlgType);
  virtual ~CPrivateChatDlg(void);

  void     Draw() override;
  void     Hide() override;
  bool     Create(const char* IDD) override;
  unsigned Process(unsigned   uiMsg, WPARAM wParam, LPARAM lParam) override;

  unsigned ActionPerformed(CActionEvent* e) override;

  void SetOther(DWORD    dwUserTag, BYTE        btStatus, const char* pszName);
  void RecvChatMsg(DWORD dwUserTag, const char* pszMsg);

private:
  void SendChatMsg();
  void AddChatMsg(const char* pszMsg);

private:
  enum {
    IID_BTN_CLOSE = 10,
    IID_EDITBOX = 20,
    IID_LISTBOX = 30,
    IID_SCROLLBAR = 31,
  };

  DWORD       m_dwUserTag; /// ������ ���� �±�
  std::string m_strName;   /// ������ �̸�
  BYTE        m_btStatus;  /// ������ ����
};
#endif
