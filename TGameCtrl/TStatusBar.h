#ifndef _CTStatusBar_
#define _CTStatusBar_
#include "winctrl.h"
class CTImage;

/**
* ������:CTDialog�ϴܿ� �����Ǵ� Class
* @Author	������
* @Date		2005/8/30
*/
class TGAMECTRL_API CTStatusBar : public CWinCtrl {
public:
          CTStatusBar(void );
  virtual ~CTStatusBar(void);
  void    Draw() override;
  void    Update(POINT     pt) override;
  void    MoveWindow(POINT pt) override;

  void SetImage(CTImage* pImage);
protected:

  CTImage* m_pImage;
};
#endif
