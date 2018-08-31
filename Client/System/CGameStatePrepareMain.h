#ifndef _CGAMESTATEPREPAREMAIN_
#define _CGAMESTATEPREPAREMAIN_

#include "CGameState.h"

/**
* ĳ���� ������ CGameStateMain�� ó���� �ϴ� State Class
*	- CGameStateWarp�� ��������� �ٸ� �κ��� �־� �и��Ǿ���.
*
* @Author		������
* @Date			2005/9/15
*/
class CGameStatePrepareMain : public CGameState {
  int    m_iPrevStateID;
  HANDLE m_hThread;
public:
      CGameStatePrepareMain(int  iID);
      ~CGameStatePrepareMain(void);
  int Update(bool                bLostFocus) override;
  int Enter(int                  iPrevStateID) override;
  int Leave(int                  iNextStateID) override;
  int ProcMouseInput(UINT        uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }
  int ProcKeyboardInput(UINT     uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }

protected:
  static unsigned __stdcall ThreadFunc(void* pArguments);
  void                      Draw();

};
#endif
