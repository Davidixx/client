#ifndef _CIndicate_
#define _CIndicate_
#include "winctrl.h"

//*----------------------------------------------------------------------------------/
/// �� ���Խ� Ȥ�� ����Ʈ ����, ����� ȭ�鿡 ǥ���ϴ� Class
//*----------------------------------------------------------------------------------/
class CIndicate : public CWinCtrl {
public:
          CIndicate(void );
  virtual ~CIndicate(void);

  void Draw() override;
  void Update(POINT ptMouse) override;
  void Show() override;
  void Hide() override;
  void SetTitle(const char*       pszTitle, const char* pszSubTitle);
  void AddDescription(const char* pszDescription);
  void ResetDescription();

protected:
  std::string       m_strTitle;
  std::string       m_strSubTitle;
  std::list<string> m_Descriptions;

  DWORD m_dwShowTime;    ///���̱� ������ �ð�
  DWORD m_dwDisplayTime; ///������ �ð�

  int m_iLineSpace;  ///������ ���ΰ���
  int m_iLineHeight; ///������ �Ѷ����� ����
  int m_iTitleHeight;
};
#endif
