#ifndef _CClanMark_
#define _CClanMark_
#include "tgamectrl/WinCtrl.h"

/**
* Ŭ�� â���� ������ �����Ҽ� �ִ� Ŭ����ũǥ�� class
*
* @Author		������
* @Date			2005/9/15
*/
class CClanMark : public CWinCtrl {
public:
           CClanMark(void );
  virtual  ~CClanMark(void);
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     SetGraphicID(int iID);
  void     SetModuleID(int  iID);

protected:
  int m_iGraphicID;
  int m_iModuleID;
};
#endif
