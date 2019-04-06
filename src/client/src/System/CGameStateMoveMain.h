#ifndef _CGAMESTATEMOVEMAIN_
#define _CGAMESTATEMOVEMAIN_

#include "CGameState.h"

/**
* ĳ���� ������ ���ӿ� ������ ī�޶� �̵����� State Class
*	- Next State : CGameStatePrepareMain
*
* @Author		������
* @Date			2005/9/15
*/
class CGameStateMoveMain : public CGameState {
public:
  CGameStateMoveMain(int  iID);
  ~CGameStateMoveMain(void);

  int Update(bool bLostFocus) override;
  int Enter(int   iPrevStateID) override;
  int Leave(int   iNextStateID) override;

  ///CGame�� Msg Queue�� �ֱ� ���� ��� ó���ؾ��� Msg�� ó���ϴ� Method
  ///�� State�� Method�� Overriding�Ͽ� ó���ؾ��� Message�� ó���Ѵ�
  int ProcWndMsgInstant(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void ServerDisconnected() override;

  int ProcMouseInput(UINT    uiMsg, WPARAM wParam, LPARAM lParam) override;
  int ProcKeyboardInput(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

};
#endif
