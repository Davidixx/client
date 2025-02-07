#include "StdAfx.h"
#include "./CMsgBoxSpecial.h"
#include "../it_mgr.h"
#include "../ExternalUI/ExternalUILobby.h"
#include "../../System/CGame.h"

CMsgBoxSpecial::CMsgBoxSpecial(void) {
  m_pCmdOk        = nullptr;
  m_pCmdCancel    = nullptr;
  m_iInvokerDlgID = 0;
}

CMsgBoxSpecial::~CMsgBoxSpecial(void) {
  ClearCommand();
}

void CMsgBoxSpecial::Hide() {
  CTMsgBox::Hide();
  //ClearCommand();
}

void CMsgBoxSpecial::ClearCommand() {
  if ( m_pCmdOk ) {
    delete m_pCmdOk;
    m_pCmdOk = nullptr;
  }
  if ( m_pCmdCancel ) {
    delete m_pCmdCancel;
    m_pCmdCancel = nullptr;
  }

}

unsigned int CMsgBoxSpecial::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam) {
  if ( !IsVision() ) return 0;

  unsigned iProcID = 0;
  if ( iProcID     = CTMsgBox::Process( uiMsg, wParam, lParam ) ) {
    if ( uiMsg == WM_LBUTTONUP ) {
      switch ( iProcID ) {
        case IID_BTN_OK: SendCommand( m_iInvokerDlgID, m_pCmdOk );
          m_pCmdOk = nullptr;
          ClearCommand();
          Hide();
          break;
        case IID_BTN_CANCEL: SendCommand( m_iInvokerDlgID, m_pCmdCancel );
          m_pCmdCancel = nullptr;
          ClearCommand();
          Hide();
          break;
        default: break;
      }
    }
    return uiMsg;
  }
  return 0;
}

void CMsgBoxSpecial::SetCommand(CTCommand* pCmdOk, CTCommand* pCmdCancel) {
  ClearCommand();

  m_pCmdOk     = pCmdOk;
  m_pCmdCancel = pCmdCancel;
}

void CMsgBoxSpecial::SetInvokerDlgID(unsigned int iDlgID) {
  m_iInvokerDlgID = iDlgID;
}

void CMsgBoxSpecial::SendCommand(unsigned int iDlgID, CTCommand* pCmd) {
  if ( pCmd ) {
    if ( CGame::GetInstance().GetCurrStateID() == CGame::GS_MAIN )
      g_itMGR.AddTCommand( iDlgID, pCmd );
    else
      g_EUILobby.AddTCommand( iDlgID, pCmd );
  }
}
