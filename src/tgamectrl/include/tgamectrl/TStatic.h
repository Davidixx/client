#ifndef	_TSTATIC_
#define _TSTATIC_

#include "winctrl.h"
#include <string>
#include "ITFont.h"
class CTImage;

/**
*	�̹����� ��Ʈ���� �����ټ� �ִ� �Ϲ����� Class
*		- ���̴°��� ���� ����
*		- ����Class	: CTDefaultlistCellRenderer, CTListCellRenderer
*
* @Author		������
* @Date			2005/9/1
*/
class TGAMECTRL_API CTStatic : public CWinCtrl {
public:
          CTStatic(void );
  virtual ~CTStatic(void);

  bool                Create(int   iScrX, int    iScrY, int     iWidth, int iHeight);
  unsigned int        Process(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;
  void                Update(POINT ptMouse) override;
  void                Draw() override;
  virtual const char* toString();

  const char* GetString() { return m_strText.c_str(); }
  void        SetString(const char* szString);
  void        SetImage(CTImage*     pImage);
  void        SetColor(DWORD        dwColor);

  void SetFont(int iFont);
  int  GetFont();

  enum eTextAlign {
    LEFT,
    CENTER,
    RIGHT
  };

protected:
  CTImage*    m_pImage;
  DWORD       m_dwFormat;
  D3DCOLOR    m_dwColor;
  std::string m_strText;
  ITFont*     m_pFontImpl;
  int         m_iFont;
};
#endif ///TSTATIC
