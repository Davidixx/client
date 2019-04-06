#ifndef _CUpgradeDlgStateResult_
#define _CUpgradeDlgStateResult_

#include "cupgradedlgstate.h"

class CGuage;
class CUpgradeDlg;

/**
* �����������̽� â�� State Class : �����κ��� ���ÿ�û�� ���� ������ �ް� ����ϴ� ����
*
* @Author		������
* @Date			2005/9/15
*/
class CUpgradeDlgStateResult : public CUpgradeDlgState {
public:
          CUpgradeDlgStateResult(CUpgradeDlg* pParent);
  virtual ~CUpgradeDlgStateResult(void        );

  void     Enter() override;
  void     Leave() override;
  void     Update(POINT ptMouse) override;
  void     Draw() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override { return 1; }
  void     MoveWindow(POINT ptMouse) override;
private:
  CUpgradeDlg* m_pParent;
  CGuage*      m_pResultGuage;
  DWORD        m_dwPrevTime;

  int m_iRedGuageImageID;
  int m_iGreenGuageImageID;
  int m_iVirtualSuccessPoint;

  bool m_bWaitUserinput;

};
#endif
