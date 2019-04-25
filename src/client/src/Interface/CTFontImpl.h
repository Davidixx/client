#ifndef _CTFONTIMPL_
#define _CTFONTIMPL_
#include "tgamectrl/ITFont.h"

/**
* �������̽� ���̺귯��(TGameCtrl)���� �˷��� ITFont�� Implemented Class
*  : TGameCtrl���������� ���ڸ� �׸��� �� �������̽��� ���ؼ� znzin�� �ش� �������̽��� ȣ���Ѵ�. 
*
* @Author		������
*
* @Date			2005/9/5
*/

class CTFontImpl : public ITFont {
public:
  CTFontImpl(void );
  ~CTFontImpl(void);

  void Draw(int iFont, bool bUseSprite, RECT* pRect, D3DCOLOR Color, DWORD dwFormat, const char* pMsg) override;
  void Draw(int iFont, bool bUseSprite, int   x, int          y, D3DCOLOR  Color, const char*    pMsg) override;

  /// �ش� �ε����� ��Ʈ�� ���� �׸����� Height�� ���ϴ� Method
  int GetFontHeight(int iFont) override;

  /// �ش� �ε����� ��Ʈ�� ���� �ؽ�Ʈ ��½� �ʺ�� ���̸� ���ϴ� Method
  SIZE GetFontTextExtent(int iFont, const char* pszText) override;

  /// �ؽ�Ʈ�� ��µ� ���� ��ġ�� �����ϴ� Method
  void SetTransformSprite(float x, float y, float z) override;
};

extern CTFontImpl g_FontImpl;
#endif
