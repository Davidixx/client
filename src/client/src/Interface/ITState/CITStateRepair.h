#ifndef _CITStateRepair_
#define _CITStateRepair_
#include "citstate.h"

/**
* ������(item��� or npc�̿�) Interface(IT_MGR) State
*
* @Author		������
* @Date			2005/9/6
*
*/
class CITStateRepair : public CITState {
public:
          CITStateRepair(void );
  virtual ~CITStateRepair(void);

  void     Enter() override;
  void     Leave() override;
  unsigned Process(unsigned uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     Update(POINT     ptMouse) override {}
};
#endif
