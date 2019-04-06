#ifndef _CMailBoxListItem_
#define _CMailBoxListItem_
#include "tgamectrl/WinCtrl.h"

/**
* Ŀ�´�Ƽ â�� ������ List�� ���Ǵ� item class
*
* @Author		������
* @Date			2005/9/15
*/

class CMailBoxListItem : public CWinCtrl {
public:
           CMailBoxListItem(const char* pszName, const char* pszMemo, DWORD dwRecvTime);
  virtual  ~CMailBoxListItem(void       );
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     SetSelected() override;

protected:
  std::string m_strName;
  std::string m_strMemo;
  SYSTEMTIME  m_RecvTime;
};
#endif
