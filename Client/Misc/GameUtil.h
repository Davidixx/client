#ifndef _GAME_UTIL_
#define _GAME_UTIL_

//----------------------------------------------------------------------------------------------------
/// ���ӿ� �ʿ��� ����� ��ƿ �Լ���
/// class CGameUtil
//----------------------------------------------------------------------------------------------------

class CGameUtil {
public:
  CGameUtil(void );
  ~CGameUtil(void);

  static D3DXCOLOR GetRGBFromString(unsigned int iColor);
  static WORD      GetPrimaryLanguage();
  static WORD      GetSubLanguage();
  static void      ConvertMoney2String(int64_t money, char* buffer, int buffer_size);

};

#endif //_GAME_UTIL_
