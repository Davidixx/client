#ifndef _EXUICOMMAND_
#define _EXUICOMMAND_
#include "../../../tgamectrl/tcommand.h"
#include <string>

/// ���Ӽ���â���� ĳ���� ������û
class CTCmdDeleteCharacter : public CTCommand {
public:
          CTCmdDeleteCharacter(int  iSelectListID, const char* pszName);
  virtual ~CTCmdDeleteCharacter(void) {}
  bool    Exec(CTObject*            pObj) override;
protected:
  int         m_iSelectListID;
  std::string m_strName;

};

/// ���Ӽ���â���� ���� ������� ĳ���� �ǻ츮�� ��û
class CTCmdReviveCharacter : public CTCommand {
public:
          CTCmdReviveCharacter(int  iSelectListID, const char* pszName);
  virtual ~CTCmdReviveCharacter(void) {}
  bool    Exec(CTObject*            pObj) override;
protected:
  int         m_iSelectListID;
  std::string m_strName;
};
#endif
