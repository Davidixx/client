#ifndef _TARGETOBJECTDLG_
#define _TARGETOBJECTDLG_

#include "../../../TGameCtrl/TDialog.h"

/**
* ���� Ŭ���� Ÿ�ٿ� ���� ������ �����ִ� ���̾�α�
*
* @Warning		����( 2005/9/15)������� �ʰ� �ִ�.
* @Author		������
* @Date			2005/9/15
*/
class CTargetObjectDLG : public CTDialog {

public:
          CTargetObjectDLG();
  virtual ~CTargetObjectDLG();

  // *---------------------------------------------------* //
  // Overrided function
  // *---------------------------------------------------* //
  void         Draw() override;
  unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;
  // *---------------------------------------------------* //

};

#endif //_TARGETOBJECTDLG_
