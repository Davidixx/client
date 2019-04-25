#ifndef _CCursorStateSprite_
#define _CCursorStateSprite_

#include "ccursorstate.h"

/**
* �������� �̹����� Draw�ϴ� State Class( �⺻ Ŀ���� ���� )
* 
*
* @Author		������
*
* @Date			2005/9/6
*/

class CCursorStateSprite : public CCursorState {
public:
          CCursorStateSprite(void );
  virtual ~CCursorStateSprite(void);
  void    Enter() override;
  void    Leave() override;
  void    Draw(POINT        ptMouse) override;
  int     SetCursorType(int iType) override;

private:
  HNODE m_hTexture;
};
#endif
