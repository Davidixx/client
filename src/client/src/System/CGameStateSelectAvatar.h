#ifndef _CGAMESTATESELECTAVATAR_
#define _CGAMESTATESELECTAVATAR_
#include "CGameState.h"

/**
* ĳ���� ���� State Class
*	- Next State : CGameStateCreateAvatar, CGameStateMoveMain, CGameStateLoginVirtual
*
* @Author	������	
* @Date		2005/9/15
*/
class CGameStateSelectAvatar : public CGameState {
public:
  CGameStateSelectAvatar(int  iID);
  ~CGameStateSelectAvatar(void);

  int Update(bool bLostFocus) override;
  int Enter(int   iPrevStateID) override;
  int Leave(int   iNextStateID) override;

  void ServerDisconnected() override;

  int ProcMouseInput(UINT    uiMsg, WPARAM wParam, LPARAM lParam) override;
  int ProcKeyboardInput(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

};
#endif
