#ifndef _CEventDialog_
#define _CEventDialog_

#include "tgamectrl/TDialog.h"
#include "tgamectrl/JStringParser.h"

/**
* �����ۻ��� ������ ��ȭâ�� Event �� ������ ���̾�α�
*	- �⺻ ������ CDialogDlg�� �����ϴ�
* 
* @Warning		�븸������ ������������ ǥ�� ����� �ٸ���(XML����Ÿ�� Ʋ���� �����ڵ�� �ڵ尡 ���еȴ�)
* @Author		������
* @Date			2005/9/14
*/

class CEventDialog : public CTDialog {
public:
          CEventDialog(void );
  virtual ~CEventDialog(void);

  void Hide() override;
  void Draw() override;
  bool Create(const char* IDD) override;
  void Show() override;

  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void SetScript(char*                     pszScript);
  void AddAnswerExample(char*              pszScript, int iEventID, void (*fpEventHandle)(int iEventID));
  void SetTargetNpcClientObjectIndex(short iIndex);
  int  IsInValidShow() override;

protected:
  enum {
    IID_BG_IMAGE = 1,
    IID_BTN_CLOSE = 10,
    IID_ZLISTBOX_NPCSCRIPT = 20,
    IID_ZLISTBOX_ANSWER_EXAMPLE = 21
  };

  short       m_nTargetClientIdx;
  std::string m_strNpcName;
  std::string m_strTempScript;
  HNODE       m_hNpcFace;
  int         m_widthNpcFace;
  int         m_heightNpcFace;

  CJStringParser m_Script;

};
#endif
