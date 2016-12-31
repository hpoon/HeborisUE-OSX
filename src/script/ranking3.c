//������������������������������������������������������������������������������
//  �����L���O�֘A
//������������������������������������������������������������������������������

// �����L���O�p�O���[�o���ϐ�
// (3���~2) �~ 10���[�h(��\��) �~ 2��]���[���^�C�v
// ��y�[�W��2���[�h3������
//�r�M�A�}�X(1�A2)�A�}�X(3�A4)�A20G�A�f�r�A�g��(Ti�AEH)�A�g���i�j�G�X�iNO�AANO�j�A�G�X(HE)�A�G���h���X
bool	allocked3 = false;
str	rkname3[ 6*14*2];			// ���O
int		rkdata3[ 6*14*2];		// �ԉ΁^�i�ʁ^�X�e�[�W�^���C��
int		rktime3[ 6*14*2];		// �^�C��
int		rkclear3[ 6*14*2];		// 0=�r���Œ��� 1=���[�����s 2=���[���N���A
int		rkother3[ 6*14*2];		// ���̑��i���x����N���A���Ȃǁj
int		rkrots3[ 6*14*2];		// ��]���[��

int		rkac3[ 6*14*2];		// AC���_�� #LITE30.2
int		rkst3[ 6*14*2];		// ST���_�� #LITE30.2
int		rksk3[ 6*14*2];		// SK���_�� #LITE30.2
int		rkco3[ 6*14*2];		// CO���_�� #LITE30.2
int		rkre3[ 6*14*2];		// RE���_�� #LITE30.2
int		modecolor3[15] = {4,1,1,5,2,3,3,0,0,7,9,0};		// ���[�h���\���F
int		rkpage;
	
// �����L���O������
void RankingInit3() {
	int i;
	
	for(i = 0; i < ( 6*14*2); i++) {
		StrCpy(rkname3[i], "NOP");
		rkdata3[i] = 0;
		rktime3[i] = 1200*60;
		rkclear3[i] = 0;
		rkother3[i] = 0;
		rkrots3[i] = 0;
		rkac3[i] = 0;
		rkst3[i] = 0;
		rksk3[i] = 0;
		rkco3[i] = 0;
		rkre3[i] = 0;
	}
}

// ���ʂɓ��邩�`�F�b�N�i�����N�O�Ȃ�-1�j
int RankingCheck3(int rmode, int rex,int rrots, int rdata, int rtime, int rclear) {
	int i, j, rank;
	
	if(playback || demo) return -1;
//	if(rmode >= 8) return -1;
	
	rank = -1;
	
	for(i = 0; i < 3; i++) {
		j = RankingGet3(rmode,ARSSRSch(rrots), rex);
		
		if( (rdata > rkdata3[j + i]) ||  //�i�ʉԉΓ��B�X�e�[�W���C��
		((rdata == rkdata3[j + i]) && (rclear > rkclear3[j + i]))||//���[���N���A�����s�����[���ȑO
		((rdata == rkdata3[j + i]) && (rclear == rkclear3[j + i]) && (rtime < rktime3[j + i])) )
		{
			rank = i;
			break;
		}
	}
	return rank;
}

// �����L���O�ɓo�^
void RankingRegist3(int rmode, int rex,int rrots, int rdata, int rtime, int rclear, 
	int rother, char *rname, int rank, int rac, int rst, int rsk, int rco ,int rre) {
	
	int i, j, rcolor;
	
	if(playback || demo) return;
	if((rank < 0) || (rank > 2)) return;
	
	j = RankingGet3(rmode,ARSSRSch(rrots), rex );
	
	// �����L���O�����炷
	for(i = 2+((rmode==9)*3); i > rank ; i--) {
		StrCpy(rkname3[j + i], rkname3[j + i - 1]);
		rkdata3[j + i] = rkdata3[j + i - 1];
		rktime3[j + i] = rktime3[j + i - 1];
		rkclear3[j + i] = rkclear3[j + i - 1];
		rkother3[j + i] = rkother3[j + i - 1];
		rkrots3[j + i] = rkrots3[j + i - 1];
		rkac3[j + i] = rkac3[j + i - 1];
		rkst3[j + i] = rkst3[j + i - 1];
		rksk3[j + i] = rksk3[j + i - 1];
		rkco3[j + i] = rkco3[j + i - 1];
		rkre3[j + i] = rkre3[j + i - 1];
	}
	
	// ���ʂ̃f�[�^�����ɐV�����f�[�^��o�^
	StrCpy(rkname3[j + rank], rname);
	rkdata3[j + rank] = rdata;
	rktime3[j + rank] = rtime;
	rkclear3[j + rank] = rclear;
	rkother3[j + rank] = rother;
	rkrots3[j + rank] = rrots;
	
	// ���_����o�^ #LITE30.2
	rkac3[j + rank] = rac;
	rkst3[j + rank] = rst;
	rksk3[j + rank] = rsk;
	rkco3[j + rank] = rco;
	rkre3[j + rank] = rre;
}

// �����L���O�\��(�f����ʁA�v���C��ɕ\��)//2pages�̓����L���O��ʂ�2�y�[�W��
void RankingProc_3(int cat,int pages2) {
	count = 0;
	flag = 0;
	if(cat==0){	//�r�M�i�[
		rkpage = 0;
	}else if(cat==1){//�}�X�^�[
		if(pages2==0){	//1,2
			rkpage = 1;
		}else if(pages2==1){	//3,4
			rkpage = 2;
		}
	}else if(cat==2){//20G
		rkpage = 3;
	}else if(cat==3){//DE
		rkpage = 4;
	}else if(cat==6){//TO	
		if(pages2==0){	//TiEH
			rkpage = 5;
		}else if(pages2==1){//FP
			rkpage = 6;
		}
	}else if(cat==7){//ACE
		if(pages2==0){
			rkpage = 7;
		}else if(pages2==1){
			rkpage = 8;
		}
	}else if(cat==9){//STD
		if(pages2==0){
			rkpage = 10;
		}else if(pages2==1){
			rkpage = 11;
		}
	}else if(cat==10){//ori
			rkpage = 9;
	}
	
	while(!flag) {
//		count++;
		
		KeyInput();
		
			RankingView3();//3�ʂ܂ŕ\��
		// A��B�Ŗ߂�
		if( (count > 448) || getPushState(0,4) || getPushState(0,5) || getPushState(1,4) || getPushState(1,5) ) {
			flag = 1;
		}
		
		spriteTime();
	}
}
//�����L���O�\���i�����ō��ڑI�����ĕ\���j
void RankingProc2_3() {
	rkpage = 0;

	while(1) {
		KeyInput();
		
		RankingView3();
		// ��
		if( getPushState(0,2) ) {
			PlaySE( 5 );
			rkpage--;//�Q�[�����[�h
			if(rkpage < 0) rkpage = 11;
		}
		
		// ��
		if( getPushState(0,3) ) {
			PlaySE( 5 );
			rkpage++;
			if(rkpage > 11) rkpage = 0;
		}
		
		// ��
		if( getPushState(0,0) ) {
			PlaySE( 5 );
			rankingrule = !(rankingrule);//��]���[��
		}
		
		// ��
		if( getPushState(0,1) ) {
			PlaySE( 5 );
			rankingrule  = !(rankingrule);
		}
		
		// A��B�Ŗ߂�
		if( getPushState(0,4) || getPushState(0,5) || getPushState(1,4) || getPushState(1,5) ) {
			return;
		}
		
		spriteTime();
	}
}

void RankingView3() {//3�ʂ܂�
	int i, j, k, l, color;
	
	// �w�i�`��
	count++;
	if(background == 0) {
		for(i = 0; i <= 4; i++) {
			if(getDrawRate() == 1)
				BltFastRect(4, 96 * i - (count % 96) / 3, 0, 0, 0, 96, 240);
			else
				BltFastRect(4, 192 * i - (count % 32), 0, 0, 0, 192, 480);
		}
	} else if(background == 1) {
		for(i = 0; i <= 4; i++) {
			ExBltFastRect(4, 96 * i, 0, 0, 0, 96, 240);
		}
	} else {
		ExBltFast(30, 0, 0);
	}
	ExBltRect(77, 0, 24,  count % 320, 20, 320 - (count % 320), 8);
	ExBltRect(77, 320 - (count % 320), 24,  0, 20, count % 320, 8);
	
	ExBltRect(77, 0, 128,  count % 320, 20, 320 - (count % 320), 8);
	ExBltRect(77, 320 - (count % 320), 128,  0, 20, count % 320, 8);

	// ���[�����\��
	getRuleNameEx3(rankingrule, 0);
	StrCat(string[0], " TYPE RULE - ");
	
	// ���[�h���\��
	getModeNameEx3(rkpage, 1);
	StrCat(string[1], " MODE");
	
	StrCat(string[0], string[1]);
	printFont(1, 1, string[0], modecolor3[rkpage]);
	
	// �����L���O�\��
	if(rkpage == 0) {//beginner 
		printFont(1, 3, "HANABI RANKING", 1); 
		printFont(1, 16,"SCORE RANKING", 1); 
	} else if(rkpage == 1) {//�}�X�^�[
		printFont(1, 3, "GRANDMASTER RANKING GRADE1 ", 1);
		printFont(1, 16,"GRANDMASTER RANKING GRADE2 ", 1);
	} else if(rkpage == 2) {//�}�X�^�[
		printFont(1, 3, "GRANDMASTER RANKING GRADE3 ", 1);
		printFont(1, 16,"GRANDMASTER RANKING GRADE4 ", 1);
	} else if(rkpage == 3) {//20G
		printFont(1, 3, "GRANDMASTER RANKING GRADE1-GRADE3", 5);
		printFont(1, 16,"GRANDMASTER RANKING GRADE4", 5);
	}else if(rkpage == 4) {//d
		printFont(1, 3, "DOOM RANKING", 2);
		printFont(1, 16,"MINUS RANKING", 2);
	} else if(rkpage == 5) {//�Ƃ���TI EH
		printFont(1, 3, "TI COURSE RANKING", 3);
		printFont(1, 16,"E-HEART COURSE RANKING", 3);
	} else if(rkpage == 6) {//FP
		printFont(1, 3, "TGT RANKING", 3);
		printFont(1, 16,"F-POINT RANKING", 3);
	} else if(rkpage == 7) {//ace
		printFont(1, 3, "NORMAL RANKING", 0);
		printFont(1, 16,"ANOTHER RANKING", 0);
	} else if(rkpage == 8) {//ace2
		printFont(1, 3, "HELL RANKING", 2);
		printFont(1, 16,"OLD STYLE RANKING", 9);
	} else if(rkpage == 9) {//ORI
		printFont(1, 3, "ORIGINAL RANKING", 9);
	} else if(rkpage == 10) {//STANDARD
		printFont(1, 3, "40LINES RANKING", 9);
		printFont(1, 16,"ULTRA RANKING", 9);		
	}else if(rkpage == 11) {//STANDARD
		printFont(1, 3, "SQUARE RANKING", 9);
		printFont(1, 16,"MARATHON RANKING", 9);
		
	}

	if(rankingrule == 0){
		printFont(0, 29  , "HEBORIS TI-ARS ACE-ARS ACE-ARS2 D.R.S", 0);//ARS
	}else{
		printFont(0, 29  , "TI-WORLD ACE-SRS DS-WORLD SRS-X", 0);//SRS
	}	
		for(l = 0; l < 2 ; l++){//l==0���3�i l==1����3�i
			// ����
			if(rkpage!=9){//�I���ȊO
				sprintf(string[0], "1ST");
				printFont(1, 5 + (l * 13)  , string[0], 2);
				sprintf(string[0], "2ND");
				printFont(1, 9 + (l * 13), string[0], 9);
				sprintf(string[0], "3RD");
				printFont(1, 13+ (l * 13) , string[0], 4);
			}else if(rkpage==9){
				sprintf(string[0], "1ST");
				printFont(1, 5  , string[0], 2);
				sprintf(string[0], "2ND");
				printFont(1, 9, string[0], 9);
				sprintf(string[0], "3RD");
				printFont(1, 13 , string[0], 4);
				sprintf(string[0], "4TH");
				printFont(1, 18   , string[0], 0);
				sprintf(string[0], "5TH");
				printFont(1, 22, string[0], 0);
				sprintf(string[0], "6TH");
				printFont(1, 26 , string[0], 0);
			}
				ExBltRect(85, 8, 32 + ( l * 13) * 8, 35, 7*3, 21, 7);//RANK�̕���
				ExBltRect(85, 40 , 32 + (l * 13) * 8, 35, 0, 21, 7);//name�̕���,������u�����W,�؂�����W,�؂���T�C�Y
				ExBltRect(85, 190, 32 + (l * 13) * 8, 35, 7*12, 21, 7);//TIME�̕���
				ExBltRect(85, 260, 32 + ( l * 13) * 8, 35, 7*6, 21, 7);//ROTS�̕���

			if(rkpage==0){//�r�M�i�[
				if(l){//SCORE(sita)
				ExBltRect(85, 78 , 32 + (l * 13) * 8, 35, 7*7, 25, 7);//SCORE�̕���
				ExBltRect(85, 128, 32 + (l * 13) * 8, 0, 7*9, 26, 7);//LEVEL�̕���
				}else{//HANABI(ue)
				ExBltRect(85, 80 , 32 + (l * 13) * 8, 35, 7*11, 29, 7);//HANABI�̕���
				ExBltRect(85, 128, 32 + (l * 13) * 8, 0, 7*9, 26, 7);//LEVEL�̕���
				}
			}else if(rkpage==5){//TI EH
				ExBltRect(85, 80 , 32 + (l * 13) * 8, 35, 7*10, 27, 7);//STAGE�̕���
				ExBltRect(85, 128 , 32 + (l * 13) * 8, 0, 7*4, 25, 7);//CLEAR�̕���
			}else if(rkpage==6){//FP
				ExBltRect(85, 80 , 32 + (l * 13) * 8, 35, 7*10, 27, 7);//STAGE�̕���
				ExBltRect(85, 126 , 32 + (l * 13) * 8, 35, 7*7, 28, 7);//SCORE�̕���
			}else if((rkpage>=7)&&(rkpage<=8)){//ACE
				ExBltRect(85, 78 , 32 + (l * 13) * 8, 0, 7*10, 35, 7);//LINES�̕���
				ExBltRect(85, 128, 32 + (l * 13) * 8, 0, 7*9, 26, 7);//LEVEL�̕���
			}else if(rkpage==9){//ORIJINAL
				ExBltRect(85, 80, 32 + (l * 13) * 8, 35, 7*7, 28, 7);//LEVEL�̕���
				ExBltRect(85, 128 , 32 + (l * 13) * 8, 0, 14*7, 21, 7);//MODE�̕���
			}else if(rkpage==10){//STANDARD
				ExBltRect(85, 78 , 32 + (l * 13) * 8, 0, 7*10, 35, 7);//LINES�̕���
				ExBltRect(85, 128 , 32 + (l * 13) * 8, 0, 2*7, 30, 7);//BLOCK�̕���
			}else if(rkpage==11){
				if(l){//MARATHON(sita)
				ExBltRect(85, 78 , 32 + (l * 13) * 8, 0, 7*10, 35, 7);//LINES�̕���
				ExBltRect(85, 128, 32 + (l * 13) * 8, 0, 7*9, 26, 7);//LEVEL�̕���
				}else{//SQUARE(ue)
				ExBltRect(85, 78 , 32 + (l * 13) * 8, 35, 7*9, 35, 7);//SQUARE�̕���
				ExBltRect(85, 128, 32 + (l * 13) * 8, 0, 7*9, 26, 7);//LEVEL�̕���
				}
			}else{
				ExBltRect(85, 78 , 32 + (l * 13) * 8, 0, 3*7, 27, 7);//CLASS�̕���
				ExBltRect(85, 128, 32 + (l * 13) * 8, 0, 7*9, 26, 7);//LEVEL�̕���
			}
			
			for(i = 0; i < 3; i++) {
				j = RankingGet3(rkpage,rankingrule,l);
				
				// ���O
				printFont(5, 5 + (i * 4) + (l * 13), rkname3[j + i], digitc[rkrots3[j + i]]);
				
				if(rkpage == 0) {
					// �X�R�A
					sprintf(string[0], "%d", rkdata3[j + i]);
					printFont(10, 5 + (i * 4) + (l * 13), string[0],digitc[rkrots3[j + i]]);
					
					// ���x��
					sprintf(string[0], "%d", rkother3[j + i]);
        				printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]); 
	        	 	} else if( (rkpage >= 1) && (rkpage <= 4) ) { 
					if(rkpage == 4){//devil 
						//devil�͐�ɒi�ʂ�\��
						// �i�� 
               					sprintf(string[0], "%d", rkother3[j + i]); 
						printFont(10, 5 + (i * 4) + l * 13, dgname[rkother3[j + i]], digitc[rkrots3[j + i]]);
						sprintf(string[0], "%d", rkdata3[j + i]); //devil���x��
					}else{
						sprintf(string[0], "%d", rkdata3[j + i]); //mas 20G�i��
						printFont(10, 5 + (i * 4) + (l * 13), gname2[rkdata3[j + i]], digitc[rkrots3[j + i]]);
						// �i�� 
               					sprintf(string[0], "%d", rkother3[j + i]);
					}
            				// ���x�� 
            				printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]); 
         			}else if((rkpage == 5) || (rkpage == 6)) { 
					// �N���A��
					if(rkpage == 5){
						// �X�e�[�W 
						if(rkclear3[j + i] == 2){
							sprintf(string[0], "ALL");
						}else{
							if(rkdata3[j + i] <= 19)
								sprintf(string[0], "%d", rkdata3[j + i] + 1);
							else if((rkdata3[j + i] <= 26)&&(rkdata3[j + i] >= 20))
								sprintf(string[0], "EX%d", rkdata3[j + i] - 19);
							else if(rkdata3[j + i] >=27 )
								sprintf(string[0], "%d", rkdata3[j + i] - 26);
						}
						printFont(10, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
						sprintf(string[0], "%d%%", rkother3[j + i]);
						printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
					}else if(rkpage == 6){
						if(rkdata3[j+i]>100){
							sprintf(string[0], "%d", rkdata3[j + i] - 99);
							printFont(10, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
						}else{
							sprintf(string[0], "%d", rkdata3[j + i]);
							printFont(10, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
						}
						sprintf(string[0], "%d", rkother3[j + i]);
						printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
					}
				} else if((rkpage == 7)||(rkpage == 8)){//ace�n
					// ���C��
					sprintf(string[0], "%d", rkdata3[j + i]);
					printFont(10, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
				
					// ���x��
					sprintf(string[0], "%d", rkother3[j + i] + 1);
					printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
				} else if((rkpage == 10)||(rkpage == 11)){//STANDARD�n
					// ���C��
					sprintf(string[0], "%d", rkdata3[j + i]);
					printFont(10, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
						
					// ���x��
					sprintf(string[0], "%d", rkother3[j + i] + 1);
					printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
				}else {
				// �X�R�A
					sprintf(string[0], "%d", rkdata3[j + i]);
					printFont(10, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
					
					if(rkother3[j + i]==0)sprintf(string[0], "BEG");
					if(rkother3[j + i]==1)sprintf(string[0], "MAS");
					if(rkother3[j + i]==2)sprintf(string[0], "20G");
					if(rkother3[j + i]==3)sprintf(string[0], "DEV");
					printFont(16, 5 + (i * 4) + (l * 13), string[0], digitc[rkrots3[j + i]]);
				}
					
				// �^�C��
				getTime(rktime3[j + i]);
				printFont(22, 5 + (i * 4)+ l * 13, string[0], digitc[rkrots3[j + i]]);
				
				// ���C��
				if(rkclear3[j + i] == 1) {
					ExBltFastRect(77, 70, (6 + (i * 4) + (l * 13)) *8,  0, 2, 240, 2);
				}else if(rkclear3[j + i] == 2) {
					ExBltRect(77, 70, (6 + (i * 4) + (l * 13)) *8,  0, 0, 240, 2);
				}
					// ��]
				if(rkrots3[j + i]==0)sprintf(string[0], "HEBORIS");
				if(rkrots3[j + i]==1)sprintf(string[0], "TI-ARS");
				if(rkrots3[j + i]==2)sprintf(string[0], "TI-WORLD");
				if(rkrots3[j + i]==3)sprintf(string[0], "ACE-SRS");
				if(rkrots3[j + i]==4)sprintf(string[0], "ACE-ARS");
				if(rkrots3[j + i]==5)sprintf(string[0], "ACE-ARS2");
				if(rkrots3[j + i]==6)sprintf(string[0], "DS-WORLD");
				if(rkrots3[j + i]==7)sprintf(string[0], "SRS-X");
				if(rkrots3[j + i]==8)sprintf(string[0], "D.R.S");
				printFont(31, 5 + (i * 4) + (l * 13), string[0], fontc[rkrots3[j + i]]);
				
				// ���_��
				if((rkpage >= 1)&&(rkpage <= 4)) {
					ExBltRect(85, 16,  5 + ((6 + (i * 4) + (l * 13)) * 8), 0, 77, 27, 7);
					if(rkac3[j + i]) ExBltRect(0,  50, 3 + ((6 + (i * 4) + (l * 13)) * 8),  0, 52 - rkac3[j + i] * 13, 15, 12);
						else ExBltRect(0,  50, 3 + ((6 + (i * 4) + (l * 13)) * 8),  0, 52, 15, 12);
					if(rkst3[j + i]) ExBltRect(0,  70, 3 + ((6 + (i * 4) + (l * 13)) * 8), 16, 52 - rkst3[j + i] * 13, 15, 12);
						else ExBltRect(0,  70, 3 + ((6 + (i * 4) + (l * 13)) * 8), 16, 52 , 15, 12);
					if(rksk3[j + i]) ExBltRect(0,  90, 3 + ((6 + (i * 4) + (l * 13)) * 8), 32, 52 - rksk3[j + i] * 13, 15, 12);
						else ExBltRect(0,  90, 3 + ((6 + (i * 4) + (l * 13)) * 8), 32, 52, 15, 12);
					if(rkco3[j + i]) ExBltRect(0, 110, 3 + ((6 + (i * 4) + (l * 13)) * 8), 80, 52 - rkco3[j + i] * 13, 15, 12);
					 	else ExBltRect(0, 110, 3 + ((6 + (i * 4) + (l * 13)) * 8), 80, 52, 15, 12);
					if(rkre3[j + i]) ExBltRect(0, 130, 3 + ((6 + (i * 4) + (l * 13)) * 8), 48, 52 - rkre3[j + i] * 13, 15, 12);
						else ExBltRect(0, 130, 3 + ((6 + (i * 4) + (l * 13)) * 8), 48, 52, 15, 12);
				}
			}	
		}
}
// �����L���O��ۑ�
void RankingSave3() {
	int i, temp2[3];
	
	FillMemory(&saveBuf, 5000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424501;
	saveBuf[1] = 0x20534901;
	saveBuf[2] = 0x48474901;
	saveBuf[3] = 0x34764301;
	
	// �����L���O�f�[�^
	for(i = 0; i < ( 6*14*2); i++) {// 6*14*2=6*14*2
		// ���O
		StrCpy(&temp2, rkname3[i]);
		saveBuf[4 + i] = temp2[0];//1
		
		// �i��
		saveBuf[4 + i + ( 6*14*2) * 1] = rkdata3[i];//2
		
		// �^�C��
		saveBuf[4 + i + ( 6*14*2) * 2] = rktime3[i];//3
		
		// ���[���N���A
		saveBuf[4 + i + ( 6*14*2) * 3] = rkclear3[i];//4
		
		// ���̑�
		saveBuf[4 + i + ( 6*14*2) * 4] = rkother3[i];//5
		
		// ���_�� #LITE30.2
		saveBuf[4 + i + ( 6*14*2) * 5] = rkac3[i];//6
		saveBuf[4 + i + ( 6*14*2) * 6] = rkst3[i];//7
		saveBuf[4 + i + ( 6*14*2) * 7] = rksk3[i];//8
		saveBuf[4 + i + ( 6*14*2) * 8] = rkco3[i];//9
		saveBuf[4 + i + ( 6*14*2) * 9] = rkre3[i];//10
		saveBuf[4 + i + ( 6*14*2) * 10] = rkrots3[i];//11
	}
	
	SaveFile("RANKING3.SAV", &saveBuf, ( (6*14*2*11)+4) * 4);//
}

// �����L���O��ǂݍ���
int RankingLoad3() {
	int i, temp2[3];
	
	// �w�b�_�����ǂݍ���
	FillMemory(&saveBuf, 5000 * 4, 0);
	LoadFile("RANKING3.SAV", &saveBuf, 16);
	// 
	if(saveBuf[0] != 0x4F424501) return 1;
	if(saveBuf[1] != 0x20534901) return 1;
	if(saveBuf[2] != 0x48474901) return 1;
	if(saveBuf[3] != 0x34764301) return 1;
	
	// �S���ǂݍ���
	LoadFile("RANKING3.SAV", &saveBuf, ( 6*14*2*11+4) * 4);
	
	for(i = 0; i < ( 6*14*2); i++) {
		// ���O
		temp2[0] = saveBuf[4 + i];
		StrCpy(rkname3[i], &temp2);
		
		// �i��
		rkdata3[i]  = saveBuf[4 + i + ( 6*14*2) * 1];
		
		// �^�C��
		rktime3[i]  = saveBuf[4 + i + ( 6*14*2) * 2];
		
		// ���[���N���A
		rkclear3[i] = saveBuf[4 + i + ( 6*14*2) * 3];
		
		// ���̑�
		rkother3[i] = saveBuf[4 + i + ( 6*14*2) * 4];
		
		// ���_�� #LITE30.2
		rkac3[i] = saveBuf[4 + i + ( 6*14*2) * 5];
		rkst3[i] = saveBuf[4 + i + ( 6*14*2) * 6];
		rksk3[i] = saveBuf[4 + i + ( 6*14*2) * 7];
		rkco3[i] = saveBuf[4 + i + ( 6*14*2) * 8];
		rkre3[i] = saveBuf[4 + i + ( 6*14*2) * 9];
		rkrots3[i] = saveBuf[4 + i + ( 6*14*2) * 10];
	}
	
	return 0;
}

// �����L���O���������鎞�Ɏg�p
int RankingGet3(int rmode, int rrots,int rex) {//5*15*2*11,3*2*14*2*11
	// ���ʂ̃��[�h
	return ((rmode * 14)  + (rrots * 6)+ (rex * 3));
}
// 5�� �~ 15���[�h �~ 2��]���[���^�C�v
// ���O���i�[����ϐ�(rkname)�̃��������m��
void RankingAlloc3() {
	int i;
	if ( !allocked3 )
	{
		for(i = 0; i < ( 6*14*2 ); i++) rkname3[i] = new char[4];		/* C++ TODO: �����̂���? �����������? */
		allocked3 = true;
	}
}


void getModeNameEx3( int mode, int number ) {
	if(mode == 0)
		sprintf(string[number], "BEGINNER");
	else if(mode == 1)
		sprintf(string[number], "MASTER ");
	else if(mode == 2)
		sprintf(string[number], "MASTER ");
	else if(mode == 3)
		sprintf(string[number], "20G");
	else if(mode == 4)
		sprintf(string[number], "DEVIL");
	else if(mode == 5)
		sprintf(string[number], "TOMOYO");
	else if(mode == 6)
		sprintf(string[number], "TOMOYO");
	else if(mode == 7)
		sprintf(string[number], "ACE");
	else if(mode == 8)
		sprintf(string[number], "ACE");
	else if(mode == 9)
		sprintf(string[number], "ORIGINAL");
	else if(mode == 10)
		sprintf(string[number], "SIMPLE");
	else if(mode == 11)
		sprintf(string[number], "SIMPLE");
}

void getRuleNameEx3( int rule, int number ) {

		if(rule == 0)
			sprintf(string[number], "ARS");
		else if(rule == 1)
			sprintf(string[number], "SRS");
}	

void viewbesttimes3(int player,int x,int y,int type){
	int	tmp,color[2],cat[2],ex[2];
	if(ranking_type<2){
	return;
	}
	if(Isbesttime==0)return;
	
	if(gameMode[player]==7){
		if(anothermode[player]==0){
			cat[player] = 7;
			ex[player] = 0;
		}else if(anothermode[player]==1){
			cat[player] = 7;
			ex[player] = 1;
		}else if(anothermode[player]==2){
			cat[player] = 8;
			ex[player] = 0;
		}else if(anothermode[player]==3){
			cat[player] = 8;
			ex[player] = 1;
		}
	}else if(gameMode[player]==9){
		if(std_opt[player]==0){
			cat[player] = 10;
			ex[player] = 0;
		}else if(std_opt[player]==1){
			cat[player] = 10;
			ex[player] = 1;
		}else if(std_opt[player]==2){
			cat[player] = 11;
			ex[player] = 1;
		}else if(std_opt[player]==3){
			cat[player] = 11;
			ex[player] = 1;
		}
	}else{
		return;
	}
	color[player] = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	if(1) {
		tmp = RankingGet3(cat[player],ARSSRSch(rots[player]), ex[player] );
		if( (gameMode[player]==7)&&(anothermode[player] <= 1)){
			if(rkdata3[tmp] < 150){
			type = 1;//�܂��N���A���ĂȂ�����f�[�^��\��
			}else{
			type = 0;
			}
		}		
		if( (gameMode[player]==7)&&(anothermode[player] == 2)){
			if(rkdata3[tmp] < 200){
			type = 1;//�܂��N���A���ĂȂ�����f�[�^��\��
			}else{
			type = 0;
			}
		}
		if(gameMode[player]==9){
			if(ex[player]){
			type = 1;
			}else{
			type = 0;
			}
		}
		if(type==1){//�^�C�����f�[�^���H
			//�f�[�^
			ExBltRect(85, x-(player*12),y, 0, 0,35, 7);//best�̕���
			ExBltRect(85, x+22-(player*16),y, 35,7*4,35, 7);//
			sprintf(string[0], "%d", rkdata3[tmp]);
			
			printSMALLFont(x-(player*8), y+8, string[0], color[player]);
			ExBltRect(85, x+24-(player*12),y+8, 0,7*10,35, 7);//LINES
		}else{
			//�^�C��
			ExBltRect(85, x,y, 0, 0,35, 7);
			ExBltRect(85, x+22,y, 35,7*12,35, 7);
			getTime(rktime3[tmp]);
			printSMALLFont(x-(player*8), y+8, string[0], color[player]);
		}
			
	}
}

void viewbesttime3(int player,int x,int y,int type){
	int	tmp,color[2],cat[2],ex[2];
	if(ranking_type<2){
	return;
	}
	if(Isbesttime==0)return;
	
	if(gameMode[player]==7){
		if(anothermode[player]==0){
			cat[player] = 7;
			ex[player] = 0;
		}else if(anothermode[player]==1){
			cat[player] = 7;
			ex[player] = 1;
		}else if(anothermode[player]==2){
			cat[player] = 8;
			ex[player] = 0;
		}else if(anothermode[player]==3){
			cat[player] = 8;
			ex[player] = 1;
		}
	}else if(gameMode[player]==9){
		if(std_opt[player]==0){
			cat[player] = 10;
			ex[player] = 0;
		}else if(std_opt[player]==1){
			cat[player] = 10;
			ex[player] = 1;
		}else if(std_opt[player]==2){
			cat[player] = 11;
			ex[player] = 1;
		}else if(std_opt[player]==3){
			cat[player] = 11;
			ex[player] = 1;
		}
	}else{
		return ;
	}
	color[player] = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	/* �x�X�g�^�C��/�f�[�^ */
	if( (gameMode[player] >= 7) && ((!maxPlay)) ) {
			tmp = RankingGet3(cat[player],ARSSRSch(rots[player]), ex[player] );
			if( (gameMode[player]==7)&&(anothermode[player] <= 1)){
				if(rkdata3[tmp] < 150){
				type = 1;//�܂��N���A���ĂȂ�����f�[�^��\��
				}else{
				type = 0;//rkdata3[RankingGet3(cat[player],ARSSRSch(rots[player]), ex[player] )] < 200
				}
			}		
			if( (gameMode[player]==7)&&(anothermode[player] == 2)){
				if(rkdata3[tmp] < 200){
				type = 1;//�܂��N���A���ĂȂ�����f�[�^��\��
				}else{
				type = 0;
				}
			}
			if(type==1){//�^�C�����f�[�^���H
				printFont(x, y-1, "BEST SCORE", fontc[rots[player]]);
				sprintf(string[0], "%d", rkdata3[tmp]);
				printFont(x+3, y, "LINES", fontc[rots[player]]);
			}else{
				printFont(x, y-1, "BEST TIME", fontc[rots[player]]);
				getTime(rktime3[tmp]);
			}
			printFont(x, y, string[0], color[player]);

			printFont(x, y, string[0], color[player]);
	}
}
int viewgrade(int player){//master���[�h��grade4�̒i�ʂ�����
	int	tmp,color[2],cat[2],ex[2];
	if(ranking_type<2){
	return 0;
	}
	if(Isbesttime==0)return 0;
	tmp = RankingGet3(2,ARSSRSch(rots[player]), 1 );
	return rkdata3[tmp];
}