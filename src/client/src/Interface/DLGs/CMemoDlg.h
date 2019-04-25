#ifndef _MemoDlg_
#define _MemoDlg_
#include "tgamectrl/TDialog.h"

/**
* ���������� ģ������ �޸𺸳���� ���̾�α�
*
* @Author		������
* @Date			2005/9/12
*/
class CMemoDlg : public CTDialog {
public:
          CMemoDlg(int  iDlgType);
  virtual ~CMemoDlg(void);

  void     Draw() override;
  bool     Create(const char* IDD) override;
  unsigned Process(unsigned   uiMsg, WPARAM wParam, LPARAM lParam) override;

  void SetTargetName(const char* pszName);

private:
  void SendMemo();

private:
  enum {
    IID_BTN_CLOSE = 10,
    IID_BTN_SEND = 11,
    IID_EDITBOX = 20,
  };

  std::string m_strName;
};
#endif
