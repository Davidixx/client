#ifndef _CIconItemDelivery_
#define _CIconItemDelivery_
#include "CIconItem.h"

/**
* ���ϸ��� ������ â���� ���Ǵ� Item Icon
*
* @Author		������
* @Date			2005/9/6
*/
class CIconItemDelivery : public CIconItem {
public:
          CIconItemDelivery(void     );
          CIconItemDelivery(tagITEM* pItem, const char* pszFrom);
  virtual ~CIconItemDelivery(void    );

  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Draw() override;
  void     ExecuteCommand() override {}
  void     GetToolTip(CInfo& strToolTip, DWORD dwDialogType, DWORD dwType) override;

  static int s_selected_icon; /// ���õ� �����ܿ� ���� �ε����� static���� ������ �ִ´�

protected:
  int         m_border_grahicid;
  std::string m_from;
};
#endif
