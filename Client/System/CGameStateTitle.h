#ifndef _CGAMESTATETITLE_
#define _CGAMESTATETITLE_
#include "cgamestate.h"

/**
* Ŭ���̾�Ʈ ������ �α��� ���� ����, Ÿ��Ʋ�� �����ָ� ����Ÿ�� �ε��ϴ� State Class
*
* @Author	������
* @Date		2005/9/15
*/
class CGameStateTitle : public CGameState {
  HANDLE m_hThread;
public:
  CGameStateTitle(int  iID);
  ~CGameStateTitle(void);

  int Update(bool bLostFocus) override;
  int Enter(int   iPrevStateID) override;
  int Leave(int   iNextStateID) override;

  void ServerDisconnected() override {}

  int ProcMouseInput(UINT    uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }
  int ProcKeyboardInput(UINT uiMsg, WPARAM wParam, LPARAM lParam) override { return 0; }

protected:
  static unsigned __stdcall ThreadFunc(void* pArguments);
  void                      Draw();

  ///
  /// system ��濡 ���� ����ȣ
  ///
  static int m_iBackGroundZone;
  HNODE      m_hTitleTexture;
};

#endif
