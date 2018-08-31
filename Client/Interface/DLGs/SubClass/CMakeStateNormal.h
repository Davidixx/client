#ifndef _CMAKESTATENORMAL_
#define _CMAKESTATENORMAL_

#include "cmakestate.h"
#include "../../../Common/CItem.h"
#include <vector>
class CTComboBox;

/**
* �����������̽� â�� State Class : ������ �������� ���ù� ��Ḧ �غ��ϴ� ����
*
* @Author		������
* @Date			2005/9/15
*/
class CMakeStateNormal : public CMakeState {
public:
          CMakeStateNormal(CMakeDLG* pParent);
  virtual ~CMakeStateNormal() {}

  void         Draw() override;
  void         Update(POINT ptMouse) override;
  void         Show() override;
  void         Hide() override;
  unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;
  void         Init() override;
  void         MoveWindow(POINT ptPos) override {}
  bool         IsModal() override;

private:
  void OnLButtonUp(unsigned   iProcID, WPARAM wParam, LPARAM lParam);
  void OnLButtonDown(unsigned iProcID, WPARAM wParam, LPARAM lParam);

  //private:
  //	int		m_iSelectedItemIdx;

};
#endif
