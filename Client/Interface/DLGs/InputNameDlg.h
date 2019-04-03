#ifndef _CInputNameDlg_
#define _CInputNameDlg_

#include "tgamectrl/TDialog.h"

class CTCmdInputName;

/**
* �̸��� ��Ʈ�� �Է½� �������� ���Ǵ� ���̾�α�
* 
* @Warning		�׻� �� ���̾�α׸� ����ϰ� ������ �ʴ�.
* @Author		������
* @Date			2005/9/14
*/
class CInputNameDlg : public CTDialog {
public:
          CInputNameDlg(void );
  virtual ~CInputNameDlg(void);

  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void Hide() override;
  void SetCommand(CTCmdInputName* m_command);
private:
  bool ExecuteCommand();

  enum {
    IID_BTN_CLOSE = 10,
    IID_BTN_CONFIRM = 11,
    IID_EDITBOX = 20
  };

  CTCmdInputName* m_command;
};

#endif
