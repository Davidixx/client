#ifndef _CTDRAWIMPL_
#define _CTDRAWIMPL_

#include "tgamectrl/ITDraw.h"
#include <d3dx9.h>

/**
* �������̽� ���̺귯��(TGameCtrl)���� �˷��� ITDraw�� Implemented Class
*  : TGameCtrl���������� 2D�̹����� �׸��� �� �������̽��� ���ؼ� znzin�� �ش� �������̽��� ȣ���Ѵ�. 
*
* @Author		�̵���,������
*
* @Date			2005/9/5
*/
class CTDrawImpl : public ITDraw {
public:
  CTDrawImpl();
  ~CTDrawImpl();

  void         Draw(int   iX, int   iY, int   iModuleID, int iGraphicID) override;
  void         Draw(int   iX, int   iY, int   iModuleID, int iGraphicID, D3DCOLOR color) override;
  void         Draw(int   iX, int   iY, int   iWidth, int    iModuleID, int       iGraphicID) override;
  void         Draw(int   iX, int   iY, int   iWidth, int    iModuleID, int       iGraphicID, D3DCOLOR color) override;
  void         Draw(float iX, float iY, float iZ, int        iModuleID, int       iGraphicID) override;
  virtual void Draw(float iX, float iY, float iZ, int        iModuleID, int       iGraphicID, D3DCOLOR color);
  virtual void Draw(float iX, float iY, float iZ, int        iWidth, int          iModuleID, int       iGraphicID);

  /// ����, ���� �ڵ� Ȯ��.
  void DrawFitW(int iX, int iY, int iModuleID, int iGraphicID, int iWidth, D3DCOLOR  color) override;
  void DrawFitH(int iX, int iY, int iModuleID, int iGraphicID, int iHeight, D3DCOLOR color) override;
  void DrawFit(int  iX, int iY, int iModuleID, int iGraphicID, int iWidth, int       iHeight, D3DCOLOR color) override;

  virtual int GetScreenWidth();
  virtual int GetScreenHeight();

  /// ����, ���� Ȯ��� 
  void Draw(int iX, int iY, int iModuleID, int iGraphicID, float fScaleWidth, float fScaleHeight, D3DCOLOR color) override;
  void Draw(int iX, int iY, int iModuleID, int iGraphicID, int   iWidth, float      fScaleWidth, float     fScaleHeight, D3DCOLOR color) override;

  /// Y���� �������� ȸ���� 
  virtual void DrawRotateY(float fX, float fY, float fZ, float fRotateY, int iModuleID, int iGraphicID);

  /// ���� ������(��Ÿ��)�� �ִ� ������
  void DrawCover(int iX, int iY, int iModuleID, int iGraphicID, D3DCOLOR color, D3DCOLOR coverColor, float value);
};

extern CTDrawImpl g_DrawImpl;
#endif // _CTDRAWIMPL_
