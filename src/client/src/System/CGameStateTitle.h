#ifndef _CGAMESTATETITLE_
#define _CGAMESTATETITLE_
#include "cgamestate.h"

/**
* 클라이언트 실행후 로그인 상태 이전, 타이틀을 보여주며 데이타를 로딩하는 State Class
*
* @Author	최종진
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
  /// system 배경에 사용될 존번호
  ///
  static int m_iBackGroundZone;
  HNODE      m_hTitleTexture;
};

#endif
