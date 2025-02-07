// This file is included by zz_error.cpp
//
// CAUSION: Do not modify or save in Visual Studio IDE. It can cause abnormal code conversion.
//
// 1. Open in Ultraedit.
// 2. Copy by custom user clipboard (Ctrl+1)

//-----------------------------------------------------------------------------
// error/message code and text definition here.
//-----------------------------------------------------------------------------
// CAUTION: before creating new message text, define new enum code in zz_error::zz_error_code.

// sample for cut and paste
//ZZ_REG_ERROR (XXXXXX, KOREAN, "");
//ZZ_REG_ERROR (XXXXXX, ENGLISH, "");

ZZ_REG_ERROR (MSG_ERROR, KOREAN, "����");
ZZ_REG_ERROR (MSG_ERROR, ENGLISH, "error");
ZZ_REG_ERROR (MSG_ERROR, JAPANESE, "�G���[");

ZZ_REG_ERROR (INIT_FAIL, KOREAN, "�ʱ�ȭ ����");
ZZ_REG_ERROR (INIT_FAIL, ENGLISH, "Iniitalization failed");
ZZ_REG_ERROR (INIT_FAIL, JAPANESE, "�������Ɏ��s���܂����B");

ZZ_REG_ERROR (CREATE_D3D_FAIL, KOREAN, "Direct3D ��ü�� ������ �� �����ϴ�.");
ZZ_REG_ERROR (CREATE_D3D_FAIL, ENGLISH, "cannot create direct3d.");
ZZ_REG_ERROR (CREATE_D3D_FAIL, JAPANESE, "DirectX�̃o�[�W�������m�F���Ă��������B");

ZZ_REG_ERROR (CREATE_FONT_FAIL, KOREAN, "��Ʈ�� ������ �� �����ϴ�.");
ZZ_REG_ERROR (CREATE_FONT_FAIL, ENGLISH, "cannot create font.");
ZZ_REG_ERROR (CREATE_FONT_FAIL, JAPANESE, "�t�H���g���쐬�ł��܂���B");

ZZ_REG_ERROR (CREATE_TEXTURE_FAIL, KOREAN, "�ؽ��ĸ� ������ �� �����ϴ�.");
ZZ_REG_ERROR (CREATE_TEXTURE_FAIL, ENGLISH, "cannot create texture.");
ZZ_REG_ERROR (CREATE_TEXTURE_FAIL, JAPANESE, "�e�N�X�`���[���쐬�ł��܂���B");

ZZ_REG_ERROR (MSG_EXIT_D3DERROR, KOREAN,
"���� ����ϰ� ��� �׷��� ī��� %s  �Դϴ�.\n"
"�׷���ī�忡�� ���ӿ� �� �ʿ��� �Ϻ� ����� �������� �ʾ� ���̻� ������ �Ұ����մϴ�.\n"
"Ȩ���������� ������� �̻��� �ý������� Ȯ���Ͻñ� �ٶ��ϴ�.\n"
"�׷��� ī�� ����̹��� �ֽŹ������� ������Ʈ�Ͻø� �� ������ �ذ�� ���� �ֽ��ϴ�.\n");
ZZ_REG_ERROR (MSG_EXIT_D3DERROR, ENGLISH,
"Your graphics card is %s.\n"
"Some mandatory features are missing, so the application will be terminated.\n"
"Please, check the minimum system requirements in our website.\n"
"In some cases, this problem may be solved just after updating your graphics card driver.\n");
ZZ_REG_ERROR (MSG_EXIT_D3DERROR, JAPANESE,
"�M���̃O���t�B�b�N�J�[�h��%s�ł��B\n"
"�Q�[�����v���[���邽�߂ɕK�v�ȋ@�\���A�O���t�B�b�N�J�[�h���T�|�[�g���Ă���܂���B\n"
"�����z�[���y�[�W����A�K�v�X�y�b�N���ēx���m�F���������B\n"
"�O���t�B�b�N�J�[�h�̃h���C�o���A�ŐV�̃o�[�W�����ɂ���Ζ�肪���������\��������܂��B\n");

/*
// source: doc/msg_jp.txt
1. "??"
1. "error"
1. "�G���["

2. "??? ??"
2. "Iniitalization failed"
2. "�������Ɏ��s���܂����B"

3. "Direct3D ??? ??? ? ????."
3. "cannot create direct3d."
3. "DirectX�̃o�[�W�������m�F���Ă��������B"

4. "??? ??? ? ????."
4. "cannot create font."
4. "�t�H���g���쐬�ł��܂���B"

5. "???? ??? ? ????."
5. "cannot create texture."
5. "�e�N�X�`���[���쐬�ł��܂���B"

6. "?? ???? ?? ??? ??? %s  ???."
6. "Your graphics card is %s."
6. "�M���̃O���t�B�b�N�J�[�h��%s�ł��B"

7. "??????? ??? ? ??? ?? ??? ???? ?? ??? ??? ??????."
7. "Some mandatory features are missing, so the application will be terminated."
7. "�Q�[�����v���[���邽�߂ɕK�v�ȋ@�\���A�O���t�B�b�N�J�[�h���T�|�[�g���Ă���܂���B"

8. "?????? ???? ??? ????? ????? ????."
8. "Please, check the minimum system requirements in our website."
8. "�����z�[���y�[�W����A�K�v�X�y�b�N���ēx���m�F���������B"

9. "??? ?? ????? ?????? ??????? ? ??? ??? ?? ????."
9. "In some cases, this problem may be solved just after updating your graphics card driver."
9. "�O���t�B�b�N�J�[�h�̃h���C�o���A�ŐV�̃o�[�W�����ɂ���Ζ�肪���������\��������܂��B"

10. "?? ??? ??"
10. "Launch Rose Online"
10. "���[�Y�I�����C���̎��s"

11. "?? ??? ??"
11. "Uninstall Rose Online"
11. "���[�Y�I�����C���̍폜"

12. "????"
12. "Configuration"
12. "���[�Y�I�����C���̐ݒ�"

*/

//------------------------------------------------------------------------------