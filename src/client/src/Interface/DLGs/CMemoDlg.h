#ifndef _MemoDlg_
#define _MemoDlg_
#include "tgamectrl/TDialog.h"

/**
* 오프라인인 친구에게 메모보내기용 다이얼로그
*
* @Author		최종진
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
