#ifndef _CTCmdSystem_
#define _CTCmdSystem_
#include "tcommand.h"

/// ������
class CTCmdChangeGameState : public CTCommand {
public:
          CTCmdChangeGameState(int  iState);
  virtual ~CTCmdChangeGameState(void) {};
  bool    Exec(CTObject*            ) override;
protected:
  int m_iState;
};
#endif
