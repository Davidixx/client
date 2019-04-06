#ifndef _CIconItem_
#define _CIconItem_
#include "cicon.h"

struct tagITEM;
class CItem;

/**
* Item Icon Class
*	- CTRL + MOUSE LBUTTONDOWN ��  ���ø���Ʈ�� �߰��ϴ� ��� ~ CIconItem::Process
*
*
* @Warning		�����̹��� Texture�� load�� unload�� ���۷��� ī�������� ó���Ѵ�.
* @Author		������
* @Date			2005/9/6
*/
class CIconItem : public CIcon {
public:
          CIconItem(void     );
          CIconItem(tagITEM* pItemData);
          CIconItem(CItem*   pItem);
  virtual ~CIconItem(void    );

  void     Draw() override;
  void     Update(POINT ptMouse) override;
  void     ExecuteCommand() override;
  void     GetToolTip(CInfo& strToolTip, DWORD dwDialogType, DWORD dwType) override;
  unsigned Process(unsigned  uiMsg, WPARAM     wParam, LPARAM      lParam) override;

  CIcon* Clone() override;
  void   Clear() override;

  virtual int      GetQuantity();
  virtual tagITEM& GetItem();
  bool             IsEnable() override;
  const char*      GetName() override;
  int              GetIndex() override;

  CItem* GetCItem();
  int    GetItemNo();

  bool IsEmpty();

protected:
  CItem*       m_pItem;                  /// �������� ������ ���������ۿ� ���� ������ < CItem�� �ִ� ��� : ��) �κ��丮�� ������ >
  bool         m_bDeleteItemData;        /// ���� �������� ������� ����� �����۵���Ÿ
  static HNODE m_hSocketTexture;         /// ������ ���� �������� ��� ���� ǥ���ϱ� ���� Texture�� ���
  static int   m_iSocketTextureRefCount; /// ���۷��� ī������ ���ؼ� 0�ϰ�� �����Ѵ�.
};

#endif
