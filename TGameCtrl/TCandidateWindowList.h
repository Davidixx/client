#ifndef _CTCandidateWindowList_
#define _CTCandidateWindowList_

#include "tcandidatewindow.h"
#include "TListBox.h"

/**
* �ѱ����̿��� �Ͼ�, �߱����ϰ�� ���Ǵ� Candidate Window class 
*	* ����Ʈ ����
*	* ���� Class	: CTIme
*
* @Author	������
* @Date		2005/8/30
*/
class CTCandidateWindowList : public CTCandidateWindow {
public:
           CTCandidateWindowList(void );
  virtual  ~CTCandidateWindowList(void);
  void     Draw() override;
  unsigned Process(unsigned         uiMsg, WPARAM wParam, LPARAM lParam) override;
  void     AddCandidate(const char* pszCandidate) override;
  void     Clear() override;
  void     MoveWindow(POINT pt) override;
  void     Show() override;
  void     Hide() override;
  void     SetSelection(short n) override;
protected:

  CTListBox m_Candidats;
  int       m_iMaxWidth;
};
#endif
