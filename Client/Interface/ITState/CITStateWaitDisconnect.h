#ifndef _CITStateWaitDisconnect_
#define _CITStateWaitDisconnect_
#include "citstate.h"

/**
* �������� �α׾ƿ��� �˸��� Disconnect �ɶ����� ����ϴ� Interface State Class
*
* @Author		������
* @Date			2005/9/6
*/
class CITStateWaitDisconnect : public CITState {
public:
          CITStateWaitDisconnect(void );
  virtual ~CITStateWaitDisconnect(void);

  void     Enter() override;
  void     Leave() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Update(POINT     ptMouse) override;
protected:
  DWORD m_dwEnterTime;
  DWORD m_dwPrevUpdateTime;
  int   m_iWaitDisconnectedTime;
};
#endif
