#ifndef _CITStateDead_
#define _CITStateDead_
#include "citstate.h"

/**
* �׾������� �������̽�(IT_MGR) ����
*
* @Author		������
*
* @Date			2005/9/6
*/
class CITStateDead : public CITState {
public:
          CITStateDead(void );
  virtual ~CITStateDead(void);

  void     Enter() override;
  void     Leave() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Update(POINT     ptMouse) override {}

};
#endif
