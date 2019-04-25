#ifndef _CTCandidateWindowHanja_
#define _CTCandidateWindowHanja_

#include "tcandidatewindow.h"
#include <string>
#include <vector>

/**
* �ѱ����ϰ�� ���� ��ȯ�� ���Ǵ� Candidate Window class 
* - ����Ŭ���� CTIme
*
* @Author		������
*
* @Date			2005/8/30		
*/
class CTCandidateWindowHanja : public CTCandidateWindow {
public:
          CTCandidateWindowHanja(void );
  virtual ~CTCandidateWindowHanja(void);
  void    Draw() override;
  void    AddCandidate(const char* pszCandidate) override;
  void    Clear() override;

protected:
  std::vector<std::string> m_Candidates;
};
#endif
