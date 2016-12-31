//������������������������������������������������������������������������������
//
//    HEBORIS [�w�{���X] 2001 Ver0.00 / 2000.11.05 (Sun) �` ????.??.?? (????)
//
//                         (c) 1998-2000 Kenji Hoshimoto
//
//������������������������������������������������������������������������������

import "string.dll"
int screenMode, colorMode, systemmem;

//������������������������������������������������������������������������������
//   �����ݒ�
//������������������������������������������������������������������������������
void main() {
	if(LoadConfig()) {	//CONFIG.SAV���ݒ�����[�h
		CallScript("script/readdef.c");	//�ǂݍ��ݎ��s������option.def�Ekeyconf.def����CONFIG.SAV�쐬
		halt;
		LoadConfig();
	}

	/* 050825 ��ʃ��[�h�g���������� -- �������� */
	if(screenMode == 0)
		SetWindow (0, 320, 240, colorMode);
	else if(screenMode == 1)
		SetWindow (1, 320, 240, colorMode);
	else if(screenMode == 2)
		SetWindow (1, 640, 480, colorMode);
	else if(screenMode == 3)
		SetWindow (0, 640, 480, colorMode);
	else if(screenMode == 4)
		SetWindow (1, 800, 600, colorMode);
	else if(screenMode == 5)
		SetWindow (1, 1024, 768, colorMode);
	else if(screenMode == 6)
		SetWindow (1, 1280, 960, colorMode);
	else
		SetWindow (1, 640, 480, colorMode);
	/* �����܂� */

	// 60fps
	SetFPS (60);

	// YGS2000�ŗL�̐ݒ�
	SetConstParam("Caption", "Please Wait...");
	SetConstParam("EnablePause", 0);		//���������I���܂Ń|�[�Y���Ȃ�#1.60c7p9ex
	SetConstParam("USE_XZ_FOR_BUTTON", 1);
	SetConstParam("StringMax", 123);

	SetDebugMode(0);

	// �V�X�e�����������g����?
	SetSystemMemoryUse(systemmem);
}


int LoadConfig(void) {
	int i, cfgbuf[24];

	FillMemory(&cfgbuf, 24, 0);
	LoadFile("CONFIG.SAV", &cfgbuf, 24);
	if(cfgbuf[0] != 0x4F424550) return (1);
	if(cfgbuf[1] != 0x20534953) return (1);
	if(cfgbuf[2] != 0x464E4F44) return (1);
	if(cfgbuf[3] != 0x31764750) return (1);

	screenMode = cfgbuf[4] & 0xff;
	colorMode = (cfgbuf[4] >> 8 + 1) * 16;
	systemmem = cfgbuf[5];
	return (0);
}