#ifndef _CPartyOptionDlg_
#define _CPartyOptionDlg_
#include "tdialog.h"
#include "../../GameCommon/IObserver.h"

/**
* ��Ƽ�� ��Ƽ�ɼ��� ���ų� �ٲܼ�(��Ƽ�常) �ִ� ���̾�α�
*	- ��Ƽâ���� ��ư�� ���� �����Ѵ�.
*	- Observable : CParty
*
* @Author		������
* @Date			2005/9/15
*/
class CPartyOptionDlg : public CTDialog, public IObserver {
public:
           CPartyOptionDlg(void );
  virtual  ~CPartyOptionDlg(void);
  unsigned Process(unsigned     uiMsg, WPARAM wParam, LPARAM lParam) override;
  bool     Create(const char*   IDD) override;
  void     Draw() override;
  void     Show() override;
  void     Update(CObservable* pObservable, CTObject* pObj) override;

  enum {
    IID_BTN_CLOSE = 10,
    IID_BTN_CONFIRM = 11,

    IID_RADIOBOX_ITEM = 34,
    IID_RADIOBUTTON_ITEM_PICK = 35,
    ///�ݴ»���� ���� ��ư
    IID_RADIOBUTTON_ITEM_SEQUENCE = 36,
    ///����������� ���ư���( ���� �ݴ��� ���� )
    IID_RADIOBOX_EXP = 37,
    IID_RADIOBOX_EXP_EQUALITY = 38,
    ///�յ��ϰ� �й�
    IID_RADIOBOX_EXP_RATIO_LEVEL = 39,
    ///�������� ����ġ �й�
    IID_CHECKBOX_SHOW_PARTYMEMBER_HPGUAGE = 40,
  };

private:
  void OnLButtonUp(unsigned uiProcID);

  BYTE m_party_rule;
};
#endif
