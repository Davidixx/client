#ifndef _CITStateAppraisal_
#define _CITStateAppraisal_
#include "citstate.h"

/**
* �����۰����� �����ؼ� ������ �Է�(���콺Ŭ��)�� ��� �ϴ� �������̽�(IT_MGR) ����
*
* @Author		������
*
* @Date			2005/9/6
*
*/
class CITStateAppraisal : public CITState {
public:
          CITStateAppraisal(void );
  virtual ~CITStateAppraisal(void);

  void     Enter() override;
  void     Leave() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Update(POINT     ptMouse) override {}
};
#endif
