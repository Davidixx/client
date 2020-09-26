/*
	$Header: /Client/Network/CNetwork.h 14    05-05-24 2:46p Gioend $
*/
#ifndef	__CNETWORK_H
#define	__CNETWORK_H
#include "Net_Prototype.h"
#include "../Util/CshoSOCKET.h"
#include "OBJECT.h"
#include "RecvPACKET.h"
#include "SendPACKET.h"

//-------------------------------------------------------------------------------------------------

enum {
  NS_NULL=0,
  NS_CON_TO_LSV,
  NS_DIS_FORM_LSV,
  NS_CON_TO_WSV
};

class CNetwork : public CRecvPACKET, public CSendPACKET {
private :
  bool bAllInONE; /// 占쏙옙占쏙옙/占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙?
  void Send_PACKET(t_PACKET* pSendPacket, bool bSendToWorld = false) override;

  short m_nProcLEVEL;
  bool  m_bMoveingZONE;
  BYTE  m_btZoneSocketSTATUS;

  static CNetwork* m_pInstance;
                   CNetwork(HINSTANCE hInstance);
                   ~CNetwork();

  void Proc_WorldPacket();
  void Proc_ZonePacket(t_PACKET* packet);

  void MoveZoneServer(bool reconnect = false);

public :
#ifdef	__VIRTUAL_SERVER
	CClientSOCKET	m_SOCKET;
#else
  CshoClientSOCK m_WorldSOCKET;
  CshoClientSOCK m_ZoneSOCKET;
#endif
  bool m_bWarping; // 占쏙옙 占쏙옙占쏙옙 占쏙옙占싸곤옙...

  static CNetwork* Instance(HINSTANCE hInstance);
  void             Destroy();

  void Send_PACKET(RoseCommon::CRosePacket&& packet, bool sendToWorld = false) override;

  bool ConnectToServer(char*      szServerIP, WORD wTcpPORT, short nProcLEVEL = 0);
  void DisconnectFromServer(short nProcLEVEL                                  = 0) override;
  // 占쏙옙 占쏙옙호 
  void Send_AuthMsg(void);

  // Playing packet ..
  //	void Send_Damage (int iServerObjectIndex, short nDamage);
  //	void Recv_Damage (t_PACKET *pPacket);

  void Proc();
};

extern CNetwork* g_pNet;
//-------------------------------------------------------------------------------------------------
#endif
