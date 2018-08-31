#ifndef _CITStateNpcDialog_
#define _CITStateNpcDialog_
#include "citstate.h"

/**
* NPC��ȭ�� �������̽�(IT_MGR)����
* - 2005/9/6�� ���� �븸 ���������� ����Ѵ�.
* - DLG_TYPE_DIALOG,  DLG_TYPE_SELECTEVENT , DLG_TYPE_EVENTDIALOG  ���߿� �Ѱ��� Show�Ǿ� ����
*
* @Author		������
*
* @Date			2005/9/6
*/
class CITStateNpcDialog : public CITState {
public:
          CITStateNpcDialog(void );
  virtual ~CITStateNpcDialog(void);

  void Enter() override;
  void Leave() override;

  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Update(POINT     ptMouse) override;
  bool     Draw() override;
};
#endif
