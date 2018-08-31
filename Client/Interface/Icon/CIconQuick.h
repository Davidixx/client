#ifndef _CIconQuick_
#define _CIconQuick_
#include "cicon.h"

/**
* ���ٿ� ���Ǵ� Icon, ���������� �ٸ� �������� ������ �ִ�.
* 
* @Warning		�׻� CIcon�� virtual method�� �������־�� �Ѵ�.( ����� ������ �ִ� CIcon�� �����ϵ��� )
* @Author		������
* @Date			2005/9/6
*/
class CIconQuick : public CIcon {
public:
          CIconQuick(CIcon* pIcon);
  virtual ~CIconQuick(void  );

  void   Draw() override;
  void   Update(POINT ptMouse) override;
  void   ExecuteCommand() override;
  CIcon* Clone() override;
  void   Clear() override;
  void   SetPosition(POINT pt) override;
  void   GetToolTip(CInfo& ToolTip, DWORD dwDialogType, DWORD dwType) override;
  int    GetIndex() override;

  void         SetQuickBarSlotIndex(int iIndex);
  int          GetQuickBarSlotIndex();
  const CIcon* GetIcon();

protected:
  CIcon* m_pIcon;              /// ���� ��� ó���� �� �����ܿ� ���� ������
  int    m_iQuickBarSlotIndex; /// ���ٿ����� ���� �ε���
};
#endif
