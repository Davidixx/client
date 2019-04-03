#ifndef _CSeparateDlg_
#define _CSeparateDlg_
#include "tgamectrl/TDialog.h"
#include "../../GameCommon/IObserver.h"
#include "subclass/CSlot.h"
#include <vector>
class CIconItem;
class CDragItem;

/**
* �и�/���ؿ� ���Ǵ� ���̾�α�
*	- Observable : CSeparate
* 
* @Author		������
* @Date			2005/9/14
*/
class CSeparateDlg : public CTDialog, public IObserver {
public:
          CSeparateDlg(void );
  virtual ~CSeparateDlg(void);

  void     Update(POINT ptMouse) override;
  void     Show() override;
  void     Draw() override;
  void     MoveWindow(POINT pt) override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;

  void Update(CObservable* pObservable, CTObject* pObj) override;

protected:
  bool HasEnoughInventoryEmptySlot(CIconItem* pItemIcon, std::vector<CSlot>& OutputItems);

protected:
  enum {
    IID_TEXT_COST = 5,
    IID_BTN_START = 10,
    IID_BTN_CLOSE = 11,
  };

  CSlot              m_MaterialItemSlot; /// �и�/������ �������� �� ����
  std::vector<CSlot> m_OutputItemSlots;  /// �и�/������ �������� �� ���� 

  CDragItem* m_pDragItem;
};
#endif
