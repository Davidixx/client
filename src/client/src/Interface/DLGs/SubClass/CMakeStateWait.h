#ifndef _CMAKESTATEWAIT_
#define _CMAKESTATEWAIT_
#include "cmakestate.h"

/**
* �����������̽� â�� State Class : ���������� ������ ��û�ϰ� ����� ����ϴ� ����
*
* @Warning		�� ������ ���� ������ �Է¿� ���� ó���� ���� �ʵ��� �Ѵ�.
* @Author		������
* @Date			2005/9/15
*/
class CMakeStateWait : public CMakeState {
public:

          CMakeStateWait(CMakeDLG* pParent);
  virtual ~CMakeStateWait();

  void         Draw() override;
  void         Update(POINT ptMouse) override;
  void         Show() override;
  void         Hide() override;
  void         Init() override;
  unsigned int Process(UINT     uiMsg, WPARAM wParam, LPARAM lParam) override;
  void         MoveWindow(POINT ptPos) override {}
  bool         IsModal() override;
};
#endif
