#ifndef _CClanRegistNotice_
#include "tgamectrl/TDialog.h"

/**
* 클랜 공지사항 등록에 사용되는 다이얼로그
*
* @Author		최종진
* @Date			2005/9/12
*/
class CClanRegistNotice : public CTDialog {
public:
           CClanRegistNotice(void );
  virtual  ~CClanRegistNotice(void);
  unsigned Process(unsigned       uiMsg, WPARAM wParam, LPARAM lParam) override;

private:
  enum {
    IID_BTN_CONFIRM = 10,
    IID_BTN_CLOSE = 11,
    IID_BTN_CANCEL = 12,
    IID_EDIT_NOTICE_CONTENT = 22,
  };

};
#endif
