#ifndef _CIconDialog_
#define _CIconDialog_
#include "cicon.h"
class CDragItem;

/**
* �������̽��� ���̾�αװ� ������ȭ �Ǿ����� ���Ǵ� Icon
*
* @Warning		CreateIcon���� ������ �ı��� �˾Ƽ�;
* @Author		������
* @Date			2005/9/6
*/
class CIconDialog : public CIcon {
public:
          CIconDialog();
  virtual ~CIconDialog(void);

  void                Update(POINT     ptMouse) override;
  unsigned            Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void                ExecuteCommand() override;
  CIcon*              Clone() override;
  void                GetToolTip(CInfo& ToolTip, DWORD dwDialogType, DWORD dwType) override;
  void                SetPosition(POINT pt) override;
  int                 GetIndex() override;
  static CIconDialog* CreateIcon(int iDialogType, bool bCreateDragItem);

  void SetDialogType(int iDialogType);
  int  GetDialogType();

  void       SetDragItem(CDragItem* pDragItem);
  CDragItem* GetDragItem();

protected:
  int        m_iDialogType;
  CDragItem* m_pDragItem;
  bool       m_bClicked;
  POINT      m_ptClicked;
};
#endif
