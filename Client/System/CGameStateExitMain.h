#ifndef _CGAMESTATEEXITMAIN_
#define _CGAMESTATEEXITMAIN_
#include "cgamestate.h"

/**
* CGameStateMain���� CGameStateSelectAvatar�� �ٲ�� �߰� State Class
*	- Next State : CGameStateSelectAvatar
*
* @Author		������
* @Date			2005/9/15
*/
class CGameStateExitMain : public CGameState {
  HANDLE m_hThread;
public:
  CGameStateExitMain(int  iID);
  ~CGameStateExitMain(void);

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
