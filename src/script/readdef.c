namespace readdef
{
	//#include "option.def"
	#include "keyconf.def"

	int	fontc[12]  = {9,1,2,3,8,4,3,6,7};	//�莚�̐F	0:�� 1:�� 2:�� 3:�� 4:�� 5:�� 6:�� 7:�� 8:�� 9:��
	int	digitc[12] = {5,5,7,7,5,5,7,7,5};	//�����̐F	���ꂼ��ATGMRule�ETiRule�EWorldRule�EWorld2Rule
	int	giveupKey = 0x10;		//�̂ăQ�[�L�[ (�f�t�H���g��Q)
	int	ssKey = 0xC7;			//�X�i�b�v�V���b�g�L�[ (�f�t�H���g��Home)
	int pausekey[2] = { 0x3B,0x3C };	//�|�[�Y�L�[(�f�t�H���g��F1,F2)		#1.60c7g7
	int dispnextkey[2] = { 0x3D,0x3E };	//NEXT�\���L�[(�f�t�H���g��F3,F4)	#1.60c7g7
	int	dtc = 1;				//tgmlv�̕\��	0:off  1:on  (lvtype = 1�̎��͏�ɕ\��)
	int	fldtr = 96;				//�t�B�[���h�w�i��\�����̃t�B�[���h���ߓx(0-256)
	int	dispnext = 3;			//�l�N�X�g�u���b�N�\�����̑I���i�O�`�R�j
	int	movesound = 1;			//�u���b�N�ړ����̑I��	0:OFF 1:ON
	int	wavebgm = 0;			//BGM�̑I��
	int	maxPlay = 0;			//�v���C���[�l���̑I��	0:�V���O�� 1:�f���A��

	int	breakeffect = 1;	//���C�������낦���Ƃ��A�u���b�N��e�������邩 0:off 1:on
	int	showcombo = 0;		//�R���{�̕\��(SINGLE�Ƃ�HEBORIS�Ƃ�) 0:off 1:on
	int	top_frame = 0;		//�u���b�N�̍������� 0:�u���b�N��������E�֏��� 1:�����ɏ���

	int	w_reverse = 1;		//���[���h���[���ŉ�]���@���t�]������ 0:off 1:on #1.60c7f8

	int	downtype = 1;		//������^�C�v 0:HEBORIS 1:Ti #1.60c7f9

	int	lvupbonus = 0;		//���x���A�b�v�{�[�i�X 0:TI 1:TGM/TAP #1.60c7g3

	int	fontsize = 1;			//�t�H���g�T�C�Y 0:DEFAULT 1:SMALL �錾���Y��C��#1.60c6.1a

	int	joykeyAssign[10 * 2] = {		//�W���C�X�e�B�b�N�{�^�����蓖��
	0, 1, 2, 3,   4, 5, 6, 7, -1, -1,		//default={0,1,2,3,10,7,4,8,-1,-1} ��pause��giveup��ǉ� 1.60c7g7
	0, 1, 2, 3,   4, 5, 6, 7, -1, -1
	};
	//Hold�{�^��(�L�[�{�[�h)���蓖��
	int	holdkey[2] = { 0x32, 0x52 };	//default 1p��:M(0x32) 2p��:�e���L�[0(0x52)

	int rots[2] = {2, 1};
	int lvup[2] = {1, 1};

	int		screenMode = 1;
	int		systemmem =0;
	int		nextblock =8;
	int		smooth =0;
	int		nanameallow =1;
	int		sonicdrop =0;
	int		blockflash =3;
	int		fastlrmove =1;
	int		background =2;


	int readdef()
	{
		int i,j, cfgbuf[100];
		

		keyAssign[7] = holdkey[0];
		keyAssign[17] = holdkey[1];	

		FillMemory(&cfgbuf, 100 * 4, 0);
		cfgbuf[0] = 0x4F424550;
		cfgbuf[1] = 0x20534953;
		cfgbuf[2] = 0x464E4F44;
		cfgbuf[3] = 0x31764750;

		cfgbuf[4] = screenMode;
		cfgbuf[5] = systemmem;
		cfgbuf[6] = nextblock;
		//cfgbuf[7] = blockkind;
		cfgbuf[8] = smooth;
		cfgbuf[9] = nanameallow;
		cfgbuf[10] = sonicdrop;
		cfgbuf[11] = blockflash;
		cfgbuf[12] = fastlrmove;
		cfgbuf[13] = background;

		for (i = 0; i < 20; i++) {
			cfgbuf[14 + i] = keyAssign[i];
		}
		cfgbuf[38] = giveupKey;
		cfgbuf[39] = ssKey;

		cfgbuf[40] = rots[0];
		cfgbuf[41] = rots[1];
		//cfgbuf[42] = lvup[0];
		//cfgbuf[43] = lvup[1];
		cfgbuf[44] = dtc;
		cfgbuf[45] = dispnext;
		cfgbuf[53] = fldtr;
		cfgbuf[54] = fontsize;
		cfgbuf[55] = maxPlay;
		cfgbuf[60] = movesound;
		cfgbuf[61] = wavebgm;
		cfgbuf[62] = breakeffect;
		cfgbuf[63] = showcombo;
		cfgbuf[64] = top_frame;
		cfgbuf[65] = w_reverse;
		cfgbuf[66] = downtype;
		cfgbuf[67] = lvupbonus;
		cfgbuf[68] = pausekey[0];
		cfgbuf[69] = pausekey[1];
		cfgbuf[70] = dispnextkey[0];
		cfgbuf[71] = dispnextkey[1];

		
		cfgbuf[74] = fontc[0] + fontc[1] * 0x100 + fontc[2] * 0x10000 + fontc[3] * 0x1000000;
		cfgbuf[75] = digitc[0] + digitc[1] * 0x100 + digitc[2] * 0x10000 + digitc[3] * 0x1000000;
		cfgbuf[76] = fontc[4] + fontc[5] * 0x100 + fontc[6] * 0x10000 + fontc[7] * 0x1000000 ;
		cfgbuf[77] = digitc[4] + digitc[5] * 0x100 + digitc[6] * 0x10000 + digitc[7] * 0x1000000 ;
		cfgbuf[78] = fontc[8] + fontc[9] * 0x100 + fontc[10] * 0x10000 + fontc[11] * 0x1000000 ;
		cfgbuf[79] = digitc[8] + digitc[9] * 0x100 + digitc[10] * 0x10000 + digitc[11] * 0x1000000 ;

		for(j=0;j<=1;j++)
		for(i=0;i<6;i++){
			if(!cfgbuf[i + 80 + (j * 6)]) cfgbuf[i + 80 + (j * 6)] = -1;
			cfgbuf[i + 80 + (j * 6)] = joykeyAssign[i + 4 + (4 * j) + (j * 6)];
		}

		SaveFile("CONFIG.SAV", &cfgbuf, 400);

		return (0);
	}
}