#ifndef _CIconSkillDummy_
#define _CIconSkillDummy_
#include "ciconskill.h"

/**
* ��ų Ʈ��â���� ���Ǵ� Skill Icon 
*	- ���� ��� ��ų�� �ƴ� ��ü ��ų�� �����ֱ����Ͽ� ���� ����Ÿ�� ���� ��ų ������
*
* @Author	������
* @Date		2005/9/12
*/
class CIconSkillDummy : public CIconSkill {
public:
          CIconSkillDummy(void );
          CIconSkillDummy(int  skillindex);
  virtual ~CIconSkillDummy(void);
  void    Draw() override;
  int     GetSkillIndex() override;
  int     GetSkillLevel() override;
private:
  int m_skillindex;
};
#endif
