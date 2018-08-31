#ifndef _CGAMESTATEWARP_
#define _CGAMESTATEWARP_

#include "CGameState.h"

/**
* ���ӳ� �������� State Class
*
* @Author	������
* @Date		2005/9/14
*/
class CGameStateWarp : public CGameState {
  int    m_iPrevStateID;
  HANDLE m_hThread;
public:
      CGameStateWarp(int     iID);
      ~CGameStateWarp(void   );
  int Update(bool            bLostFocus) override;
  int Enter(int              iPrevStateID) override;
  int Leave(int              iNextStateID) override;
  int ProcMouseInput(UINT    uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }
  int ProcKeyboardInput(UINT uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }

protected:
  static unsigned __stdcall ThreadFunc(void* pArguments);
  void                      Draw();

};
#endif
