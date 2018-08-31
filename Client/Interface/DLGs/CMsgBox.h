#ifndef _CMSGBOX_
#define _CMSGBOX_
#include "TMsgBox.h"
#include "subclass/cslot.h"
class CTCommand;
class CIcon;

/**
* �޼��� �ڽ��� ���̾�α�
*
* @Author		������
* @Date			2005/9/12
*/
class CMsgBox : public CTMsgBox {
public:
          CMsgBox(void );
  virtual ~CMsgBox(void);

  void         Draw() override;
  void         Hide() override;
  void         Update(POINT          ptMouse) override;
  void         MoveWindow(POINT      pt) override;
  void         SetString(const char* szString) override;
  unsigned int Process(UINT          uiMsg, WPARAM wParam, LPARAM lParam) override;

  void SetCommand(CTCommand*        pCmdOk, CTCommand* pCmdCancel);
  void SetInvokerDlgID(unsigned int iDlgID);
  void SetIcons(std::list<CIcon*>&  Icons);

  ///�ߺ��Ǿ ���� MsgBox���� ���� Type���� ��� �ݰ� ������ Type�� �����ϰ� OpenMsgBox���� �� Type�� ���ڷ� �Ѱ��ش�.
  enum {
    MSGTYPE_NONE,
    MSGTYPE_RECV_TRADE_REQ,
    MSGTYPE_RECV_PARTY_REQ,
    MSGTYPE_RECV_CLANJOIN_REQ,
    MSGTYPE_RECV_CART_RIDE_REQ,
    //2�ν� īƮ
  };

  enum {
    IID_BTN_OK = 255,
    IID_BTN_CANCEL = 256
  };

protected:
  void SendCommand(unsigned int iDlgID, CTCommand* pCmd);
  void ClearCommand();

protected:
  CTCommand*         m_pCmdOk;        /// Ok Btn�� �������� ó���� Command
  CTCommand*         m_pCmdCancel;    /// Cancel Btn�� �������� ó���� Command
  unsigned int       m_iInvokerDlgID; /// Command �� ó���� TDialogID
  std::vector<CSlot> m_Slots;         /// �޼��� �ڽ��� �������� �������� ���Ǵ� ���� �����̳�
};
#endif
