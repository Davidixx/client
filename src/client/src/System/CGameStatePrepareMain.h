#ifndef _CGAMESTATEPREPAREMAIN_
#define _CGAMESTATEPREPAREMAIN_

#include "CGameState.h"

/**
* 캐릭터 선택후 CGameStateMain전 처리를 하는 State Class
*	- CGameStateWarp와 비슷하지만 다른 부분이 있어 분리되었다.
*
* @Author		최종진
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
