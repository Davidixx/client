#ifndef _CMemoViewDlg_
#define _CMemoViewDlg_
#include "tgamectrl/TDialog.h"

/**
* ���� ���� ����� ���̾�α�
*
* @Author		������
* @Date			2005/9/12
*/
class CMemoViewDlg : public CTDialog {
public:
           CMemoViewDlg(void  );
  virtual  ~CMemoViewDlg(void );
  bool     Create(const char* IDD) override;
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void SetTargetName(const char* pszName);
  void SetContent(const char*    pszContent);
  void SetID(int                 iID);

private:
  enum {
    IID_BTN_CLOSE = 10,
    IID_BTN_OK = 11,
    IID_BTN_DELETE = 12,
  };

  int         m_iID;        /// �������� ������ ���� �ε���
  std::string m_strName;    /// ���� ��� �̸�
  std::string m_strContent; /// ���� ����

};
#endif
