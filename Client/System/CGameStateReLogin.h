#ifndef _CGAMESTATERELOGIN_
#define _CGAMESTATERELOGIN_
#include "cgamestate.h"

/**
* CGameStateMain���� CGameStateLogin�� �ٲ�� �߰� State Class
*	- Next State : CGameStateLogin
*
* @Author		������
* @Date			2005/10/20
*/
class CGameStateReLogin : public CGameState {
  HANDLE m_hThread;
public:
  CGameStateReLogin(int  iID);
  ~CGameStateReLogin(void);

  int Update(bool bLostFocus) override;
  int Enter(int   iPrevStateID) override;
  int Leave(int   iNextStateID) override;

  void ServerDisconnected() override {} ////�� ���¿����� ������ ���ܵ� �ƹ��͵� ���� �ʴ´�.

  int ProcMouseInput(UINT    uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }
  int ProcKeyboardInput(UINT uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }

protected:
  static unsigned __stdcall ThreadFunc(void* pArguments);
  void                      Draw();

  ///
  /// system ��濡 ���� ����ȣ
  ///
  static int m_iBackGroundZone;
};

#endif
