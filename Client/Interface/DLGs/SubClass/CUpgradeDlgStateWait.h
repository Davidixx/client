#ifndef _CUpgradeDlgStateWait_
#define _CUpgradeDlgStateWait_

#include "cupgradedlgstate.h"

/**
* �����������̽� â�� State Class : ����ڰ� �������� ������ ��û�ϰ� ������ ����ϴ� ����
*	
* @Warning		�̻����� ��� ��� ������ �Է��� �����Ѵ�.
* @Author		������
* @Date			2005/9/15
*/
class CUpgradeDlgStateWait : public CUpgradeDlgState {
public:
          CUpgradeDlgStateWait(void );
  virtual ~CUpgradeDlgStateWait(void);

  void     Enter() override {}
  void     Leave() override {}
  void     Update(POINT ptMouse) override {}
  void     Draw() override {}
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override { return 1; }

};
#endif
