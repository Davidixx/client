#ifndef _CGameStateLoginVirtual_
#define _CGameStateLoginVirtual_
#include "cgamestate.h"

/**
* CGameStateSelectAvatar���� CGameStateSelectSvr�� �̵��ϱ� ���� �߰� State Class
*	- �α��μ����� �ٽ� �����ؾ��ϱ� ������ ���̵�� �н����带 �����Ͽ��ٰ� �ڵ����� ��������â���� ����Ǵ� �����̴�
*
* @Author		������
* @Date			2005/9/15
*/
class CGameStateLoginVirtual : public CGameState {
public:
          CGameStateLoginVirtual(int  iID);
  virtual ~CGameStateLoginVirtual(void);
  int     Update(bool                 bLostFocus) override;
  int     Enter(int                   iPrevStateID) override;
  int     Leave(int                   iNextStateID) override;
  int     ProcMouseInput(UINT         uiMsg, WPARAM wParam, LPARAM lParam) override;
  int     ProcKeyboardInput(UINT      uiMsg, WPARAM wParam, LPARAM lParam) override;
  void    ServerDisconnected() override;
  void    WorldServerDisconnected() override;
  void    AcceptedConnectLoginSvr() override;
};
#endif
