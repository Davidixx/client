#ifndef _CMAKESTATERESULT_
#define _CMAKESTATERESULT_
#include "cmakestate.h"
#include <vector>
class CGuage;

/**
* �����������̽� â�� State Class : ������ ���� ���� ��������� ����ϴ� ����
*
* @Author		������
* @Date			2005/9/15
*/
class CMakeStateResult : public CMakeState {
public:

               CMakeStateResult(CMakeDLG* pParent);
  virtual      ~CMakeStateResult(void     );
  void         Draw() override;
  void         Update(POINT ptMouse) override;
  void         Show() override;
  void         Hide() override;
  void         Init() override;
  unsigned int Process(UINT     uiMsg, WPARAM wParam, LPARAM lParam) override;
  void         MoveWindow(POINT ptPos) override;
  bool         IsModal() override;

protected:
  std::vector<CGuage*> m_listGuage;
  int                  m_iRedGuageImageID;
  int                  m_iGreenGuageImageID;
  int                  m_dwPrevTime;
  bool                 m_bWaitState; ///�޼��� �ڽ��� ���������� ��ٸ���.

};
#endif
