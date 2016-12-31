/* TOMOYO���[�h�ł̕����I���������� #1.60c7l8 */
void tomoyoInitial(int player) {
	int sbak[20];

	// ����������Ă͍�����̂��o�b�N�A�b�v�ɃR�s�[
	sbak[0]  = stage[player];	// �X�e�[�W
	sbak[1]  = ltime[player];	// ���~�b�g�^�C��
	sbak[2]  = nextc[player];	// NEXT�J�E���g
	sbak[3]  = next[player];		// NEXT�u���b�N
	sbak[4]  = time[player];		// �^�C��
	sbak[5]  = clearnum[player];	// �N���A�X�e�[�W��
	sbak[6]  = clearp[player];	// �N���A��
	sbak[7]  = replay_save[player];	// �L�^�\�t���O
	sbak[8]  = time2[player];		// TOMOYO���v���C�p�v���C�^�C��
	sbak[9]  = bgmlv;			// BGM
	sbak[10] = t_training[player];	// �g���[�j���O���[�h
	sbak[11] = repversw;	//���������������Ă̓~���[������� c7t3.1
	sbak[12] = tomoyo_opt[player];
	sbak[13] = laststage[player];	//�����������������EH�AACE-TGT�̍ŏI�X�e�[�W���������ݒ肳��Ȃ� c7T3.2
	sbak[14] = sc[player];		// F-Point�̃X�R�A
	sbak[15] = fpbas_mode[player];  //FP�G���h���X���[�h
	sbak[16] = lv[player];		//FP�p���x��(�ꉞ�S�ăL�[�v)

	// ������
	playerInitial(player);

	// ����������Ă͍�����̂��o�b�N�A�b�v����߂�
	stage[player]       = sbak[0];
	ltime[player]       = sbak[1];
	nextc[player]       = sbak[2];
	next[player]        = sbak[3];
	time[player]        = sbak[4];
	clearnum[player]    = sbak[5];
	clearp[player]      = sbak[6];
	replay_save[player] = sbak[7];
	time2[player]       = sbak[8];
	bgmlv               = sbak[9];
	t_training[player]  = sbak[10];
	repversw            = sbak[11];
	tomoyo_opt[player]  = sbak[12];
	laststage[player]   = sbak[13];
	sc[player]          = sbak[14];
	fpbas_mode[player]  = sbak[15];
	
	if((tomoyo_opt[player]==4)&&(fpbas_mode[player])){
		lv[player] = sbak[16];	//FPBASIC�����߂����̃��[�h�͏�����
	}
	
	backno = 0;
	
	// �����X�s�[�h�l�Ə���wait�l�ǂݍ��� #1.60c7m2
	setStartLevel(player);

	// NEXT�u���b�N�̐F��ݒ� #1.60c7n1
	setNextBlockColors(player, 1);
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.17 - TOMOYO���[�h �X�e�[�W�N���A�^�^�C���I�[�o�[
//������������������������������������������������������������������������������
void statTomoyoNextStage(int player) {
	int i, j, ext, timelimit_tomoyo;	//laststage[player]��gamestart��
	int ltime_s[2],Stage_update;
	ext = 0;
	timelimit_tomoyo = 320*60;	//EX7�ւ̑��؂�
	
	statc[player * 10 + 0]++;
	
	StopSE(32);
	pinch[player] = 0;
	isxray[player] = 0;			// #1.60c7p9ex
	iscolor[player] = 0;		// #1.60c7p9ex
	Stage_update = 0;
	
	// EX�ʓ˓��O��BGM������ #1.60c7o8
	if( (stage[player] == 19) && (!t_training[player]) ) {
		StopAllBGM();
		fadelv[player] = 0;
		bgmlv = 9;		// EX��BGM
	}
	if( (stage[player] == 43) && (!t_training[player]) ) {
		StopAllBGM();
		fadelv[player] = 0;
		bgmlv = 19;
	}

	if(stage[player] <= 26){
	Stage_update = Stage_RankingCheck(player, 6);
	}
	
	// STAGE XX
	printFont(16-(1*((stage[player] >= 45) && (stage[player] <= 67) || (stage[player] >= 100)))-(1*((stage[player] >= 36) && (stage[player] <= 44))) + 24 * player - 12 * maxPlay, 6, "STAGE", 4);
	
	// 21�ʈȍ~��EX���ƕ\�� #1.60c7m4
	if( (stage[player] >= 20) && (stage[player] <= 26) ) {
		sprintf(string[0],"EX%d",stage[player] - 19);
	} else if( (stage[player] >= 27) && (stage[player] <= 44) ){
		sprintf(string[0],"EH%d",stage[player] - 26);
	} else if( (stage[player] >= 45) && (stage[player] <= 71) ){
		sprintf(string[0],"TGT%d",stage[player] - 44);
	} else if(stage[player] >= 100){
		sprintf(string[0],"FP%d",stage[player] - 99);
	} else {
		sprintf(string[0],"%d",stage[player] + 1);
	}
	printFont(22-(1*(stage[player] >= 45) && (stage[player] <= 67) || (stage[player] >= 100))-(1*(stage[player] >= 36) && (stage[player] <= 44)) + 24 * player - 12 * maxPlay, 6, string[0], 0);
	
	// CLEAR/TIME OVER
	if(sclear[player]) {
		printFont(17 + 24 * player - 12 * maxPlay, 8, "CLEAR", 0);
		if((stage[player] >= 0) && (stage[player] <= 26)){
		}
	} else if(stime[player] == 0) {
		printFont(16 + 24 * player - 12 * maxPlay, 8, "TIME OVER", 0);
		if((stage[player] >= 0) && (stage[player] <= 26)){
		}
	} else {
		printFont(17 + 24 * player - 12 * maxPlay, 8, "SKIPED", 0);
		if((stage[player] >= 0) && (stage[player] <= 26)){
		recFaultTime(player);//�X�e�[�WNOT�����L���O�p�^�C��
		}
		// ���v���C�L�^�s�\�ɂȂ�������\�� #1.60c7n8
		printFont(15 + 24 * player - 12 * maxPlay, 13, "THIS PLAY", 2);
		printFont(15 + 24 * player - 12 * maxPlay, 14, "  CAN'T BE", 2);
		printFont(15 + 24 * player - 12 * maxPlay, 15, "     SAVED", 2);
	}
	
	if(sclear[player]) {
		if(statc[player * 10 + 0] == 1){
		for(i = 0; i < 10; i++)	//�t�B�[���h���� C7T3.2
			for(j = 0; j < 22; j++) {
				fld[i + j * 10 + player * 220] = 0;
				fldt[i + j * 10 + player * 220] = 0;
				fldi[i + j * 10 + player * 220] = 0;
			}
		}
		// �ԉ�
		if((statc[player * 10 + 0] % 10 == 0) && (tomoyo_hanabi[player] < 10)) {
			PlaySE(35);
			objectCreate2(player, 7, Rand(80) + 72 + 192 * player - 96 * maxPlay, 32 + Rand(20), 0, 0, Rand(7)+1, 0);
			tomoyo_hanabi[player]++;
		}
		if(stage[player] < 100){
			// TIME EXTEND
			printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 13*8, "Time Extend", 3 );
			
			// ���~�b�g�^�C�������ʂ����߂�
			if(ctime[player] < 10 * 60) {
				ext = 10;
			}else if(ctime[player] < 20 * 60) {
				ext = 5;
			}
			
			sprintf(string[0],"%2d sec",ext);
			printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 14*8 + 1, string[0], 0 );
		}else{
			printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 13*8, "Score Bonus", 3 );
			sprintf(string[0],"%5d pts",FP_bonus[player]);
			printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 14*8 + 1, string[0], 0 );
		}
		// CLEAR TIME
		printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 16*8, "Clear Time", 3 );
		getTime(ctime[player]);
		printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 17*8 + 1, string[0], 0 );
		
		if(Stage_update) {
			printFont(15 + 24 * player - 12 * maxPlay, 22, "STAGE", 2);
			printFont(15 + 24 * player - 12 * maxPlay, 23, "   RECORD", 2);
		}
	}
	if(stage[player] < 100){
		// LIMIT TIME
		if(ext_s[player] < (ext*60)){
			ext_s[player] = ext_s[player]+4;
		}
		if((timeextend_snd_cnt[player] < ext) && ((statc[player * 10 + 0]-1) % 15 == 0)){
			PlaySE(42);
			timeextend_snd_cnt[player]++;
		}
		
		ltime_s[player] = ltime[player]+ext_s[player];
	}else{
		ltime_s[player] = ltime[player];
	}
	if(!fpbas_mode[player]){
		printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 10*8, "Limit Time", 3 );
		getTime(ltime_s[player]);
		printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 11*8 + 1, string[0], ((count % 4 / 2) * digitc[rots[player]])*(ext != 0) );
	}
	if(!hide_tomoyo_totaltime) {
		printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 19*8, "Total Time", 3);
		getTime(time[player]);
		printSMALLFont( (15 + 24 * player - 12 * maxPlay)*8 + 8, 20*8 + 1, string[0], 0);
	}

	// �N���A���v�Z
	if(!t_training[player]) clearp[player] = ((clearnum[player]*100) / (stage[player] + 1 - 27 *(start_stage[player] >= 27) ));
	
	// �{�^���������Ƒ������̃X�e�[�W��
	if( getPushState(player, 4) ) {
		statc[player * 10 + 0] = 300;
	}
	
	// ���̃X�e�[�W
	if(statc[player * 10 + 0] >= 300) {
		if(start_stage[player] >= 27) {
			// ����� #1.60c7r6
			if((start_stage[player] >= 27) && (start_stage[player] < 45))
				laststage[player] = 44;	// H-Heart
			else if((start_stage[player] >= 45) && (start_stage[player] < 72))
				laststage[player] = 71;	// ACE-Target
			else if((start_stage[player] >= 69) && (start_stage[player] < 100))
				laststage[player] = 99;	// Edit stage
			else
				laststage[player] = 199;// F-Point
		} else if(t_noborder[player]) {
			// ���؂�Ȃ����[�h�̏ꍇ�͏�Ƀ��X�g�X�e�[�W��EX7�ɂ��� #1.60c7m5
			laststage[player] = 26;
		} else {
			/* �N���A���Ń��X�g�X�e�[�W�����肷�� */
			if(clearp[player] < 90) {
				// 90%�ȉ���EX�Ȃ��i���X�g�X�e�[�W��20�j
				laststage[player] = 19;
			} else if(clearp[player] < 100) {
				// 90�`99%��EX3�܂�
				laststage[player] = 22;
			} else if((clearp[player] == 100)&(stage[player]==19)){
				// 100%�̏ꍇ�̓X�e�[�W20�܂ł̃^�C���Ō��߂�
				if (time[player] < timelimit_tomoyo) {
					// 5���ȓ��Ȃ�Ō�܂�
					laststage[player] = 26;
					//EX7�s�������܂�Η��ꐯ
					objectCreate2(player, 8, Rand(20) + 180 + 192 * player - 96 * maxPlay, 20 + Rand(10), 0, 0, 0, 0);
					PlaySE(43);
				}else {
					// 5�������Ă���ꍇ��EX5
					laststage[player] = 24;
				}
			}
		}
		// ���~�b�g�^�C������
		ltime[player] = ltime[player] + (ext * 60);
		
		if(stage[player] >= 100)
			sc[player] = sc[player] + FP_bonus[player];

		if( stage[player] == 19 ) ltime[player] = ltime[player] + (60 * 60);	// 20�ʃN���A��1������ #1.60c7l9
		
		if( !t_training[player] ) {
			stage[player]++;	// �g���[�j���O�łȂ��Ȃ玟�̃X�e�[�W��
		}
		// �g���[�j���OB�ł�NEXTC���J�n���ɖ߂� #1.60c7o8
		if( t_training[player] == 2 ) {
			nextc[player] = stage_nextc[player];
			next[player] = nextb[nextc[player] + player * 1400];
		}
		// ������
		tomoyoInitial(player);
		if((fpbas_mode[player]) || (repversw < 58)){
			if(lv[player] >= 7)lv[player] = 6;
			else if(lv[player] > 0)lv[player]--;
			sp[player] = lvTabletomoyohebo[lv[player]];
		}
		stat[player] = 3;					// Ready
		statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 0;			// 
		if((stage[player] >= 100) && (!t_training[player])){
			stat[player] = 36;				// F-Point�Z���N�g
			statc[player * 10] = 1;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
		}
		
		if( (stage[player] > laststage[player]) && (!t_training[player])) {
			// ���X�g�X�e�[�W�N���A�ŃG���f�B���O
			// �������g���[�j���O�ł͖��� #1.60c7o7
			PlayWave(28);
			stage[player] = laststage[player];
			ending[player] = 1;
			stat[player] = 13;
			if(laststage[player] == 199)
				sc[player] = sc[player] + 100000;
			end_f[player] = 1 + (stage[player] >= 26);
		} else {
			stage_nextc[player] = nextc[player];	// �X�e�[�W�X�^�[�g����NEXTC���L�� #1.60c7l9
		}
	}
}

// �X�e�[�W�N���A���� #1.60c7l8
void tomoyoCheckStageClear(int player) {
	if(gameMode[player] == 6) {
		// �c��v���`�i�u���b�N���𐔂���
		rest_pblock[player] = getPlatinumBlock(player);
		
		// �v���`�i�u���b�N��0�Ȃ�N���A�t���OON
		if( (!rest_pblock[player]) && (!sclear[player]) ) {
			sclear[player] = 1;
		}
	}
}

// �t�B�[���h���Ɏc���Ă���v���`�i�u���b�N�̐��𐔂���
int getPlatinumBlock(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < 10; i++)
		for(j = 0; j < 22; j++) {
			if(fld[i + j * 10 + player * 220] >= 11) {
				result++;
			}
		}
	if(tomoyo_rise[player]){	//���肠���肪ON�Ȃ�A�܂�����オ���Ă��Ȃ��������J�E���g
		for(i = 0; i < 10; i++)
			for(j = upLineNo[player]; j <= 20; j++) {
				if(tomoyo_rise_fld[i + j * 10 + player * 200] >= 11)
					result++;
			}
	}
	return result;
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.18 - TOMOYO���[�h �X�e�[�W�G�f�B�^
//������������������������������������������������������������������������������
// statc[player * 10]     : �J�[�\���ʒu
// statc[player * 10 + 1] : ���j���[�^�t�B�[���h
// statc[player * 10 + 2] : �߂��X�e�[�^�X
// statc[player * 10 + 3] : �t�B�[���h��ʂɓ������u�ԃu���b�N��u���Ă��܂��̂�h���t���O
void statTomoyoEditor(int player) {
	int tmp, bx1, by1;
	
	padRepeat(player);
	padRepeat2(player);
	
	/* �����j���[��ʁ� */
	if( statc[player * 10 + 1] == 0 ) {
		printFont(15 + 24 * player - 12 * maxPlay, 8 + statc[player * 10] +(1*(statc[player * 10] >= 13)) , "b", 1);
		
		sprintf(string[0],"STAGE:%2d",stage[player] + 1);
		printFont(16 + 24 * player - 12 * maxPlay, 8, string[0],  (statc[player * 10] == 0) );
		
		printFont(16 + 24 * player - 12 * maxPlay, 9, "FIELD",    (statc[player * 10] == 1) );
		
		printFont(16 + 24 * player - 12 * maxPlay,10, "MIRROR",   (statc[player * 10] == 2) + (isfmirror[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,11, "ROLL ROLL",(statc[player * 10] == 3) + (rollroll_flag[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,12, "X-RAY",    (statc[player * 10] == 4) + (xray_flag[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,13, "COLOR",    (statc[player * 10] == 5) + (color_flag[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,14, "BIG",      (statc[player * 10] == 6) + (IsBig[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,15, "BLIND",    (statc[player * 10] == 7) + (blind_flag[player] * 2) );
		sprintf(string[0],"SPEED:%4d",min_speed[player]);
		printFont(16 + 24 * player - 12 * maxPlay,16, string[0],   (statc[player * 10] == 8) );
		printFont(16 + 24 * player - 12 * maxPlay,17, "THUNDER",   (statc[player * 10] == 9) + (isthunder[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,18, "HIDE NEXT", (statc[player * 10] == 10) + (hnext_flag[player] * 2) );
		printFont(16 + 24 * player - 12 * maxPlay,19, "BOOST FIRE",(statc[player * 10] == 11) + (tomoyo_waits[player] * 2) );

		if(!tomoyo_rise[player])
			printFont(16 + 24 * player - 12 * maxPlay,20, "RISE:OFF",   (statc[player * 10] == 12));
		else{
			printFont(16 + 24 * player - 12 * maxPlay,20, "RISE:ON",   (statc[player * 10] == 12));
			sprintf(string[0],"INTER:%3d",tomoyo_rise[player]);
			printFont(16 + 24 * player - 12 * maxPlay,21, string[0],   (statc[player * 10] == 12) + 4);
		}
		printFont(16 + 24 * player - 12 * maxPlay,22, " [LOAD]",     (statc[player * 10] == 13) );
		printFont(16 + 24 * player - 12 * maxPlay,23, " [SAVE]",     (statc[player * 10] == 14) );
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 0) ) {
			PlayWave(5);
			statc[player * 10]--;
			if(statc[player * 10] < 0) statc[player * 10] = 14;
		}
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 1) ) {
			PlayWave(5);
			statc[player * 10]++;
			if(statc[player * 10] > 14) statc[player * 10] = 0;
		}
		
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
		if(getPressState(player, 2)) {
			PlayWave(3);
			
			// STAGE
			if(statc[player * 10] == 0) {
				stage[player]--;
				if(stage[player] < 0) stage[player] = 199;
			}
			// MIRROR
			if(statc[player * 10] == 2) {
				isfmirror[player] = !isfmirror[player];
			}
			// ROLL ROLL
			if(statc[player * 10] == 3) {
				rollroll_flag[player] = !rollroll_flag[player];
			}
			// X-RAY #1.60c7p9ex
			if(statc[player * 10] == 4) {
				xray_flag[player] = !xray_flag[player];
			}
			// COLOR #1.60c7p9ex
			if(statc[player * 10] == 5) {
				color_flag[player] = !color_flag[player];
			}
			// BIG #1.60c7l8
			if(statc[player * 10] == 6) {
				IsBig[player] = !IsBig[player];
			}
			// BLIND
			if(statc[player * 10] == 7) {
				blind_flag[player] = !blind_flag[player];
			}
			// �Œᑬ�x
			if(statc[player * 10] == 8) {
				min_speed[player]--;
				if(min_speed[player] < 0) min_speed[player] = 1200;
			}
			if(statc[player * 10] == 9) {
				isthunder[player] = !isthunder[player];
			}
			if(statc[player * 10] == 10) {
				hnext_flag[player] = !hnext_flag[player];
			}
			if(statc[player * 10] == 11) {
				tomoyo_waits[player] = !tomoyo_waits[player];
			}
			if(statc[player * 10] == 12) {
				tomoyo_rise[player]--;
				if(tomoyo_rise[player] < 0) tomoyo_rise[player] = 99;
			}
		}
		
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
		if(getPressState(player, 3)) {
			PlayWave(3);
			
			// STAGE
			if(statc[player * 10] == 0) {
				stage[player]++;
				if(stage[player] > 199) stage[player] = 0;
			}
			// MIRROR
			if(statc[player * 10] == 2) {
				isfmirror[player] = !isfmirror[player];
			}
			// ROLL ROLL
			if(statc[player * 10] == 3) {
				rollroll_flag[player] = !rollroll_flag[player];
			}
			// X-RAY #1.60c7p9ex
			if(statc[player * 10] == 4) {
				xray_flag[player] = !xray_flag[player];
			}
			// COLOR #1.60c7p9ex
			if(statc[player * 10] == 5) {
				color_flag[player] = !color_flag[player];
			}
			// BIG #1.60c7l8
			if(statc[player * 10] == 6) {
				IsBig[player] = !IsBig[player];
			}
			if(statc[player * 10] == 7) {
				blind_flag[player] = !blind_flag[player];
			}
			if(statc[player * 10] == 8) {
				min_speed[player]++;
				if(min_speed[player] > 1200) min_speed[player] = 0;
			}
			if(statc[player * 10] == 9) {
				isthunder[player] = !isthunder[player];
			}
			if(statc[player * 10] == 10) {
				hnext_flag[player] = !hnext_flag[player];
			}
			if(statc[player * 10] == 11) {
				tomoyo_waits[player] = !tomoyo_waits[player];
			}
			if(statc[player * 10] == 12) {
				tomoyo_rise[player]++;
				if(tomoyo_rise[player] > 99) tomoyo_rise[player] = 0;
			}
		}
		
		// A�{�^��
		if( getPushState(player, 4) ) {
			PlayWave(10);
			
			// STAGE
			if(statc[player * 10] == 0) {
				loadTomoyoStage(player, stage[player]);
			}
			// FIELD
			if(statc[player * 10] == 1) {
				bx[player] = 0;					// X���W
				by[player] = 1;					// Y���W
				blk[player] = 0;				// �z�u����u���b�N
				statc[player * 10 + 1] = 1;		// �X�e�[�^�X�J�E���^��1�ɂ��ăt�B�[���h��ʂ�
				statc[player * 10 + 3] = 1;		// ���̂܂܂��Ɖ�ʂ��؂�ւ�����u�ԁA�u���b�N��z�u���Ă��܂��̂�
												// �����������邽�߂̃t���O
			}
			// RISE
			if(statc[player * 10] == 12) {
				bx[player] = 0;					// X���W
				by[player] = 1;					// Y���W
				blk[player] = 0;				// �z�u����u���b�N
				statc[player * 10 + 1] = 2;		// �X�e�[�^�X�J�E���^��2�ɂ��Ă���オ��t�B�[���h��ʂ�
				statc[player * 10 + 3] = 1;		// ���̂܂܂��Ɖ�ʂ��؂�ւ�����u�ԁA�u���b�N��z�u���Ă��܂��̂�
												// �����������邽�߂̃t���O
			}
			// MIRROR
			if(statc[player * 10] == 2) {
				isfmirror[player] = !isfmirror[player];
			}
			// ROLL ROLL
			if(statc[player * 10] == 3) {
				rollroll_flag[player] = !rollroll_flag[player];
			}
			// X-RAY #1.60c7p9ex
			if(statc[player * 10] == 4) {
				xray_flag[player] = !xray_flag[player];
			}
			// COLOR #1.60c7p9ex
			if(statc[player * 10] == 5) {
				color_flag[player] = !color_flag[player];
			}
			// BIG #1.60c7l8
			if(statc[player * 10] == 6) {
				IsBig[player] = !IsBig[player];
			}
			if(statc[player * 10] == 7) {
				blind_flag[player] = !blind_flag[player];
			}
			if(statc[player * 10] == 9) {
				isthunder[player] = !isthunder[player];
			}
			if(statc[player * 10] == 10) {
				hnext_flag[player] = !hnext_flag[player];
			}
			if(statc[player * 10] == 11) {
				tomoyo_waits[player] = !tomoyo_waits[player];
			}
			// LOAD
			if(statc[player * 10] == 13) {
				loadTomoyoStage(player, stage[player]);
			}
			// SAVE
			if(statc[player * 10] == 14) {
				saveTomoyoStage(player, stage[player]);
			}
		}
		
		// B�{�^��
		if( getPushState(player, 5) ) {
			stat[player] = statc[player * 10 + 2];	// �߂���
			statc[player * 10] = 0;					// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 0;				// 
			statc[player * 10 + 2] = 0;
		}
	
	/* ���t�B�[���h��ʁ� */
	} else if( statc[player * 10 + 1] == 1 ){		// FIELD
		// �J�[�\���\��
		bx1 = (bx[player] + 15 + 24 * player - 12 * maxPlay) * 8;
		by1 = (by[player] + 3) * 8;
		
		ExBltFastRect(3,  bx1 - 1, by1 - 1, 0, 34, 10, 10);
		ExBltFastRect(getBlockPlaneNo(player, blk[player]), bx1, by1, blk[player] * 8 - (blk[player] >= 10) * 80, 0, 8, 8);
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 0) ) {
			PlayWave(5);
			by[player]--;
			if(by[player] < 1) by[player] = fldsizeh[player];
		}
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 1) ) {
			PlayWave(5);
			by[player]++;
			if(by[player] > fldsizeh[player]) by[player] = 1;
		}
		
		// ��
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
		if( getPressState(player, 2) ) {
			PlayWave(5);
			
			// �u���b�N�I��
			if( getPressState(player, 6) ) {
				blk[player]--;
				if(blk[player] < 0) blk[player] = 16;
			}
			// �J�[�\���ړ�
			else {
				bx[player]--;
				if(bx[player] < 0) bx[player] = fldsizew[player] - 1;
			}
		}
		
		// ��
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
		if( getPressState(player, 3) ) {
			PlayWave(5);
			
			// �u���b�N�I��
			if( getPressState(player, 6) ) {
				blk[player]++;
				if(blk[player] > 16) blk[player] = 0;
			}
			// �J�[�\���ړ�
			else {
				bx[player]++;
				if(bx[player] > fldsizew[player] - 1) bx[player] = 0;
			}
		}
		
		// A�{�^���Ŕz�u
		if( getPressState(player, 4) && !statc[player * 10 + 3] ) {
			if(fld[bx[player] + by[player] * fldsizew[player] + player * 220] != blk[player] + 1) {
				PlayWave(3);
			}
			fld[bx[player] + by[player] * fldsizew[player] + player * 220] = blk[player] + 1;
			fldt[bx[player] + by[player] * fldsizew[player] + player * 220] = -1;
		}
		if( !getPressState(player, 4) ) {
			statc[player * 10 + 3] = 0;
		}
		
		// HOLD�{�^���Ńu���b�N����
		if( getPressState(player, 7) ) {
			if(fld[bx[player] + by[player] * fldsizew[player] + player * 220] != 0) {
				PlayWave(3);
			}
			fld[bx[player] + by[player] * fldsizew[player] + player * 220] = 0;
			fldt[bx[player] + by[player] * fldsizew[player] + player * 220] = 0;
		}
		
		// B�{�^���Ŗ߂�
		if( getPushState(player, 5) ) {
			statc[player * 10 + 1] = 0;			// �X�e�[�^�X�J�E���^��0�ɂ��ă��j���[�ɖ߂�
			statc[player * 10 + 3] = 0;
		}
	} else if( statc[player * 10 + 1] == 2 ){		// RISE
		// �J�[�\���\��
		bx1 = (bx[player] + 15 + 24 * player - 12 * maxPlay) * 8;
		by1 = (by[player] + 4) * 8;
		
		ExBltFastRect(3,  bx1 - 1, by1 - 1, 0, 34, 10, 10);
		ExBltFastRect(getBlockPlaneNo(player, blk[player]), bx1, by1, blk[player] * 8 - (blk[player] >= 10) * 80, 0, 8, 8);
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 0) ) {
			PlayWave(5);
			by[player]--;
			if(by[player] < 1) by[player] = fldsizeh[player];
		}
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 1) ) {
			PlayWave(5);
			by[player]++;
			if(by[player] > fldsizeh[player]) by[player] = 1;
		}
		
		// ��
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
		if( getPressState(player, 2) ) {
			PlayWave(5);
			
			// �u���b�N�I��
			if( getPressState(player, 6) ) {
				blk[player]--;
				if(blk[player] < 0) blk[player] = 16;
			}
			// �J�[�\���ړ�
			else {
				bx[player]--;
				if(bx[player] < 0) bx[player] = fldsizew[player] - 1;
			}
		}
		
		// ��
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
		if( getPressState(player, 3) ) {
			PlayWave(5);
			
			// �u���b�N�I��
			if( getPressState(player, 6) ) {
				blk[player]++;
				if(blk[player] > 16) blk[player] = 0;
			}
			// �J�[�\���ړ�
			else {
				bx[player]++;
				if(bx[player] > fldsizew[player] - 1) bx[player] = 0;
			}
		}
		
		// A�{�^���Ŕz�u
		if( getPressState(player, 4) && !statc[player * 10 + 3] ) {
			if(tomoyo_rise_fld[bx[player] + (by[player]-1) * fldsizew[player] + player * 200] != blk[player] + 1) {
				PlayWave(3);
			}
			tomoyo_rise_fld[bx[player] + (by[player]-1) * fldsizew[player] + player * 200] = blk[player] + 1;
//			fldt[bx[player] + by[player] * fldsizew[player] + player * 210] = -1;
		}
		if( !getPressState(player, 4) ) {
			statc[player * 10 + 3] = 0;
		}
		
		// HOLD�{�^���Ńu���b�N����
		if( getPressState(player, 7) ) {
			if(tomoyo_rise_fld[bx[player] + (by[player]-1) * fldsizew[player] + player * 200] != 0) {
				PlayWave(3);
			}
			tomoyo_rise_fld[bx[player] + (by[player]-1) * fldsizew[player] + player * 200] = 0;
//			fldt[bx[player] + by[player] * fldsizew[player] + player * 210] = 0;
		}
		
		// B�{�^���Ŗ߂�
		if( getPushState(player, 5) ) {
			statc[player * 10 + 1] = 0;			// �X�e�[�^�X�J�E���^��0�ɂ��ă��j���[�ɖ߂�
			statc[player * 10 + 3] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.19 - TOMOYO���[�h �Z���N�g���
//������������������������������������������������������������������������������
// statc[player * 10]     : �J�[�\���ʒu
// statc[player * 10 + 1] : �v���C�^�g���[�j���OA�^�g���[�j���OB�^�G�f�B�b�g
void statTomoyoSelect(int player) {
	int i;
	
	padRepeat(player);
	padRepeat2(player);
	
	printFont(15 + 24 * player - 12 * maxPlay, 6, "SELECT", 4);
	
	// �X�e�[�W�ԍ�
	printFont(15 + 24 * player - 12 * maxPlay, 8, "STAGE", 3);
	
	// 21�ʈȍ~��EX���ƕ\�� #1.60c7m4
	if( (start_stage[player] >= 20) && (start_stage[player] <= 26) ) {
		sprintf(string[0],"EX%d",start_stage[player] - 19);
	} else if( (start_stage[player] >= 27) && (start_stage[player] <= 44) ){
		sprintf(string[0],"E-HEART%d",start_stage[player] - 26);
	} else if( (start_stage[player] >= 45) && (start_stage[player] <= 71) ){
		sprintf(string[0],"ACE-TGT%d",start_stage[player] - 44);
	} else if( start_stage[player] >= 100 ){
		sprintf(string[0],"F-POINT %d",start_stage[player] - 99);
	} else {
		sprintf(string[0],"%2d",start_stage[player] + 1);
	}
	
	printFont(15 + 24 * player - 12 * maxPlay, 9, string[0],  (statc[player * 10] == 0) * count % 9 );
	
	// NEXTC #1.60c7l7
	printFont(15 + 24 * player - 12 * maxPlay, 11, "NEXTC", 3);
	sprintf(string[0],"%d",start_nextc[player]);
	printFont(15 + 24 * player - 12 * maxPlay, 12, string[0],  (statc[player * 10] == 1) * count % 9 );

	// �Q�[�����[�h
	printFont(15 + 24 * player - 12 * maxPlay, 14, "MODE", 3);
	if(statc[player * 10 + 1] == 0)
		printFont(15 + 24 * player - 12 * maxPlay, 15, "PLAY", (statc[player * 10] == 2) * count % 9);
	if(statc[player * 10 + 1] == 1)
		printFont(15 + 24 * player - 12 * maxPlay, 15, "TRAINING-A", (statc[player * 10] == 2) * count % 9);
	if(statc[player * 10 + 1] == 2)
		printFont(15 + 24 * player - 12 * maxPlay, 15, "TRAINING-B", (statc[player * 10] == 2) * count % 9);
	if(statc[player * 10 + 1] == 3)
		printFont(15 + 24 * player - 12 * maxPlay, 15, "EDIT", (statc[player * 10] == 2) * count % 9);

	// �����_�����[�h #1.60c7l9
	// DUAL�Ή� #1.60c7m1
	printFont(15 + 24 * player - 12 * maxPlay, 17, "RANDOM", 3);
	if(randommode[player])
		printFont(15 + 24 * player - 12 * maxPlay, 18, "ON", (statc[player * 10] == 3) * count % 9);
	else
		printFont(15 + 24 * player - 12 * maxPlay, 18, "OFF", (statc[player * 10] == 3) * count % 9);
	
	// ���؂�ON/OFF #1.60c7m5
	printFont(15 + 24 * player - 12 * maxPlay, 20, "BORDER", 3);
	if(t_noborder[player])
		printFont(15 + 24 * player - 12 * maxPlay, 21, "OFF", (statc[player * 10] == 4) * count % 9);
	else
		printFont(15 + 24 * player - 12 * maxPlay, 21, "ON", (statc[player * 10] == 4) * count % 9);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlayWave(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 4;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlayWave(5);
		statc[player * 10]++;
		if(statc[player * 10] > 4) statc[player * 10] = 0;
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
	if( getPressState(player, 2) ) {
		PlayWave(3);
		
		// ��]�@��
		/*
		if(statc[player * 10] == 0) {
			rots[player]--;
			if(rots[player] < 0) rots[player] = 3;
		}
		*/
		// �X�e�[�W�ԍ�
		if(statc[player * 10] == 0) {
			start_stage[player]--;
			if(start_stage[player] < 0) start_stage[player] = 199;
			// �X�e�[�W�f�[�^�ǂݍ��� #1.60c7l9
			loadTomoyoStage(player, start_stage[player]);
		}
		// NEXTC #1.60c7l7
		if(statc[player * 10] == 1) {
			start_nextc[player]--;
			if(start_nextc[player] < 0) start_nextc[player] = 1399;
		}
		// ���[�h
		if(statc[player * 10] == 2) {
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 3;
		}
		// �����_�����[�h #1.60c7l9
		if(statc[player * 10] == 3) {
			randommode[player] = !randommode[player];
			versusInit(player);
		}
		// ���؂�ON/OFF #1.60c7m5
		if(statc[player * 10] == 4) {
			t_noborder[player] = !t_noborder[player];
		}
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
	if( getPressState(player, 3) ) {
		PlayWave(3);
		
		// ��]�@��
		/*
		if(statc[player * 10] == 0) {
			rots[player]++;
			if(rots[player] > 3) rots[player] = 0;
		}
		*/
		// �X�e�[�W�ԍ�
		if(statc[player * 10] == 0) {
			start_stage[player]++;
			if(start_stage[player] > 199) start_stage[player] = 0;
			// �X�e�[�W�f�[�^�ǂݍ��� #1.60c7l9
			loadTomoyoStage(player, start_stage[player]);
		}
		// NEXTC #1.60c7l7
		if(statc[player * 10] == 1) {
			start_nextc[player]++;
			if(start_nextc[player] > 1399) start_nextc[player] = 0;
		}
		// ���[�h
		if(statc[player * 10] == 2) {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 3) statc[player * 10 + 1] = 0;
		}
		// �����_�����[�h #1.60c7l9
		if(statc[player * 10] == 3) {
			randommode[player] = !randommode[player];
			versusInit(player);
		}
		// ���؂�ON/OFF #1.60c7m5
		if(statc[player * 10] == 4) {
			t_noborder[player] = !t_noborder[player];
		}
	}
	
	// B�{�^��
	if( getPushState(player, 5) ) {
		for(i=0;i<220;i++) {
			// �t�B�[���h�S���� #1.60c7m2
			fld[i + 220 * player] = 0;
			fldt[i + 220 * player] = 0;
		}
		stat[player] = 2;					// SOLO MODE���[�h�Z���N�g
		statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 0;			// 
	}
	
	// HOLD�{�^����nextc��0�ɖ߂�
	if( getPushState(player, 7) ) {
		PlayWave(3);
		start_nextc[player] = 0;
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		PlayWave(10);
		stage[player] = start_stage[player];
		if((start_stage[player] >= 27) && (start_stage[player] <= 44) )
			ltime[player] = 600 * 60;
		else if(start_stage[player] < 100)
			ltime[player] = 180 * 60;
		else
			ltime[player] = 1080 * 60;
		stage_nextc[player] = start_nextc[player];	// �X�e�[�W�X�^�[�g����NEXTC #1.60c7l9
		
		bgmlv = setstartBGM(gameMode[player], player);		// BGM�ݒ� #1.60c7o8
		
		if( statc[player * 10 + 1] == 3 ) {
			// �G�f�B�b�g
			stat[player] = 18;					// �X�e�[�W�G�f�B�^
			statc[player * 10] = 1;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 0;			// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 2] = 19;		// �߂��ݒ�
		} else if( statc[player * 10 + 1] == 2 ) {
			// �g���[�j���OB
			t_training[player] = 2;				// �g���[�j���OON
			stat[player] = 1;					// �u���b�N�V���b�^�[
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;			// Ready
		} else if( statc[player * 10 + 1] == 1 ) {
			// �g���[�j���OA
			t_training[player] = 1;				// �g���[�j���OON
			stat[player] = 1;					// �u���b�N�V���b�^�[
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;			// Ready
		} else {
			// �v���C
			t_training[player] = 0;				// �g���[�j���OOFF
			stat[player] = 1;					// �u���b�N�V���b�^�[
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;			// Ready
		}
	}
	// NEXT���܂Ƃ߂ăZ�b�g #1.60c7l9
	nextc[player] = start_nextc[player];
	next[player] = nextb[nextc[player] + player * 1400];
	setNextBlockColors(player, 1);		// NEXT�u���b�N�̐F��ݒ� #1.60c7m9
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.20 - TOMOYO���[�h ���ʕ\��
//������������������������������������������������������������������������������
// statc[player * 10]     : �R���e�B�j���[���邩
// statc[player * 10 + 1] : �R���e�B�j���[�c�莞��
// statc[player * 10 + 2] : 2�l�����Ńv���C���Ă��邩
// statc[player * 10 + 3] : ���v���C�Z�[�u�\��
void statTomoyoResult(int player) {
	int tmp;
	
	statc[player * 10 + 1]++;
	
	// ���y�𗬂�
	// 2�l�����ŏd�Ȃ�Ȃ��悤�ɏC�� #1.60c7m1
	if( (stat[1 - player] == 0) && (!IsPlayWave(63)) && (wavebgm >= 1) ) PlayWave(63);
	
	// �x���������Ă�����~�߂�
	StopSE(40);
	
	// ���v���C�ۑ�
	if((textguide) && (!playback) && (!demo)){
		if(!player) printFont(13+24 * player - 12 * maxPlay, 26, "0-9 KEY:REPLAY", 0);
		else printFont(13+24 * player - 12 * maxPlay, 26, "Q-P KEY:REPLAY", 0);
	}
	
	// ���v���C�Z�[�u #1.60c7n8
	ReplaySaveCheck(player, 3);
	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED : %02d", statc[player * 10 + 3]);
		printFont(15 + 24 * player - 12 * maxPlay, 24, string[0], 5);
	}
	
	printFont(15 + 24 * player - 12 * maxPlay, 6, "PLAY DATA", 4);
	
	// STAGE
	ExBltRect(3, 120 + 192 * player - 96 * maxPlay, 64, 228, 112, 26, 7);
		
	if((stage[player] >= 26) && (ending[player])) {
		// ALL�N���A
		printSMALLFont(182 + 192 * player - 96 * maxPlay, 64, "ALL", 0);
	} else if ((stage[player] > 19) && (stage[player] <= 26)) {
		// EX
		printSMALLFont(182 + 192 * player - 96 * maxPlay, 64, "EX", 0);
		sprintf(string[0], "%d", stage[player] - 19);
		printSMALLFont(194 + 192 * player - 96 * maxPlay, 64, string[0], 0);
	} else if ((stage[player] > 26) && (stage[player] <= 44)) {
		// E-Heart
		printSMALLFont(182-(6*(stage[player] - 26 >= 10)) + 192 * player - 96 * maxPlay, 64, "EH", 0);
		sprintf(string[0], "%d", stage[player] - 26);
		printSMALLFont(194-(6*(stage[player] - 26 >= 10)) + 192 * player - 96 * maxPlay, 64, string[0], 0);
	} else if ((stage[player] > 44) && (stage[player] <= 71)) {
		// ACE-Target
		printSMALLFont(176-(6*(stage[player] - 44 >= 10)) + 192 * player - 96 * maxPlay, 64, "TGT", 0);
		sprintf(string[0], "%d", stage[player] - 44);
		printSMALLFont(194-(6*(stage[player] - 44 >= 10)) + 192 * player - 96 * maxPlay, 64, string[0], 0);
	} else if (stage[player] >= 100) {
		// F-Point
		printSMALLFont(182-(6*(stage[player] - 99 >= 10))-(6*(stage[player] - 99 >= 100)) + 192 * player - 96 * maxPlay, 64, "FP", 0);
		sprintf(string[0], "%d", stage[player] - 99);
		printSMALLFont(194-(6*(stage[player] - 99 >= 10))-(6*(stage[player] - 99 >= 100)) + 192 * player - 96 * maxPlay, 64, string[0], 0);
	} else {
		// �ʏ�
		sprintf(string[0], "%2d", stage[player] + 1);
		printSMALLFont(188 + 192 * player - 96 * maxPlay, 64, string[0], 0);
	}
	
	// TIME
	ExBltRect(3, 120 + 192 * player - 96 * maxPlay, 75, 180, 119, 19, 7);
	getTime(time[player]);
	printSMALLFont(152 + 192 * player - 96 * maxPlay, 75, string[0], 0);
	
	// CLEAR #1.60c7m5
	if((!t_training[player]) && (tomoyo_opt[player] == 0) && (stage[player] <= 26)) {
		ExBltRect(3, 120 + 192 * player - 96 * maxPlay, 86, 254, 112, 26, 7);
		sprintf(string[0], "%3d>", clearp[player] );
		printSMALLFont(176 + 192 * player - 96 * maxPlay, 86, string[0], 0);
	}
	// SCORE(F-Point)
	if(stage[player] >= 100){
		ExBltRect(3, 120 + 192 * player - 96 * maxPlay, 86, 154, 112, 26, 7);
		sprintf(string[0], "%7d", sc[player]);
		printSMALLFont(158 + 192 * player - 96 * maxPlay, 86, string[0], 0);
	}
	// �R���e�B�j���[�I��
	if( (!playback) && (!ending[player]) ) {
		printSMALLFont(120 + 192 * player - 96 * maxPlay, 144, "CONTINUE", (statc[player * 10] == 0) * fontc[rots[player]]);
		printSMALLFont(120 + 192 * player - 96 * maxPlay, 154, "END", (statc[player * 10] == 1) * fontc[rots[player]]);
		
		sprintf(string[0], "%2d", 10 - (statc[player * 10 + 1] / 60));
		printFont(17 + 24 * player - 12 * maxPlay, 22, "TIME", 6);
		printFont(21 + 24 * player - 12 * maxPlay, 22, string[0], 0);
	}
	
	// ����
	if(getPushState(player, 0) || getPushState(player, 1)) {
		if(!ending[player]) {
			PlayWave(5);
			statc[player * 10] = !statc[player * 10];
		}
	}
	
	// A�{�^��
	if( (getPushState(player, 4)) || (statc[player * 10 + 1] >= 10 * 60) ) {
		StopAllBGM();
		
		if( playback ) {
			// ���v���C #1.60c7n8
			stat[player] = 0;	// �Q���҂��i�^�C�g���ցj
		} else if( (!statc[player * 10]) && (statc[player * 10 + 1] < 10 * 60) && (!ending[player]) ) {
			// YES
			PlayWave(10);
			
			if((stage[player] >= 27) && (stage[player] <= 44) )
				ltime[player] = 600 * 60;
			else
				ltime[player] = 180 * 60;

			nextc[player] = stage_nextc[player];
			next[player] = nextb[nextc[player] + player * 1400];

			clearnum[player] = 0;
			clearp[player] = 0;

			// ������
			tomoyoInitial(player);
			
			// �X�^�[�g���̃X�e�[�W��ݒ� #1.60c7n8
			start_stage[player] = stage[player];
			start_nextc[player] = stage_nextc[player];
			
			time2[player] = 0;					// TOMOYO�p�v���C�^�C�������Z�b�g
			replay_save[player] = 1;			// ���v���C�Z�[�u���\�ɂ���
			
			stat[player] = 1;					// �u���b�N�V���b�^�[
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;			// Ready
		} else {
			// NO
			stat[player] = 11;				// �l�[���G���g���\�� #1.60c7p1
			statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
			statc[player * 10 + 4] = 0;
			statc[player * 10 + 5] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.36 - TOMOYO���[�h F-Point�p�@�X�e�[�W�Z���N�g
//������������������������������������������������������������������������������
// statc[player * 10]     : ���[�h�i0=�ŏ� 1=�r���j
// statc[player * 10 + 1] : �^�C�}�[
// statc[player * 10 + 2] : �J�[�\���ʒu
// statc[player * 10 + 3] : ���݂̃X�e�[�W
void statTomoyoSelect_FP(int player) {
	int i;
	
	if(statc[player * 10 + 1] == 0){
		loadTomoyoStage(player, stage[player]);
		FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
		if(repversw <= 46) FP_bonus[player] = 10800;
		statc[player * 10 + 3] = stage[player] - 99;
		if(stage[player] == 190){	//�X�e�[�W90�˔j�ŗ��ꐯ
			StopAllBGM();
			PlayWave(43);
			objectCreate2(player, 8, Rand(20) + 180 + 192 * player - 96 * maxPlay, 20 + Rand(10), 0, 0, 0, 0);
		}
	}
	
	statc[player * 10 + 1]++;
	
	padRepeat(player);
	padRepeat2(player);
	
	printFont(15 + 24 * player - 12 * maxPlay, 6, "SELECT", 4);
	
	// �X�e�[�W�ԍ�
	printFont(15 + 24 * player - 12 * maxPlay, 8, "    STAGE", 4);
	
	if(statc[player * 10] == 0){	//�ŏ�
		printFont(15 + 24 * player - 12 * maxPlay, 7, "  FIRST", 4);
	
		sprintf(string[0],"F-POINT%3d",start_stage[player] - 99);
		printFont(15 + 24 * player - 12 * maxPlay, 14, string[0], 0);
		printFont(14 + 24 * player - 12 * maxPlay, 14, "<          >", count % 9);

		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
		if( getPressState(player, 2) ) {
			PlayWave(3);
			
			// �X�e�[�W�ԍ�
			start_stage[player]--;
			if(start_stage[player] < 100) start_stage[player] = 189;
			if(repversw >= 47) FP_bonus[player] = 1000 * (((start_stage[player]-100) / 4) + 1);
			// �X�e�[�W�f�[�^�ǂݍ��� #1.60c7l9
			loadTomoyoStage(player, start_stage[player]);
		}
	
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
		if( getPressState(player, 3) ) {
			PlayWave(3);
			
			// �X�e�[�W�ԍ�
			start_stage[player]++;
			if(start_stage[player] > 189) start_stage[player] = 100;
			if(repversw >= 47) FP_bonus[player] = 1000 * (((start_stage[player]-100) / 4) + 1);
			// �X�e�[�W�f�[�^�ǂݍ��� #1.60c7l9
			loadTomoyoStage(player, start_stage[player]);
		}
	} else {
		printFont(15 + 24 * player - 12 * maxPlay, 7, "   NEXT", 4);
		
		sprintf(string[0], "%2d", 10 - (statc[player * 10 + 1] / 60));
		printFont(17 + 24 * player - 12 * maxPlay, 23, "TIME", 6);
		printFont(21 + 24 * player - 12 * maxPlay, 23, string[0], 0);
		
		for(i=0;i<=3;i++){
			if(statc[player * 10 + 3] < 90){
				if(statc[player * 10 + 3] + FP_next[i] <= 90)
				sprintf(string[0], "%2d", statc[player * 10 + 3] + FP_next[i]);
				else sprintf(string[0], "90", 0);
			}else{
				if(statc[player * 10 + 3] + FP_next[i] <= 100)
					sprintf(string[0], "%2d", statc[player * 10 + 3] + FP_next[i]);
				else sprintf(string[0], "100", 0);
			}
			printFont(18 + 24 * player - 12 * maxPlay, 10 + (i * 2), string[0], 0);
		}
		
		printFont(15 + 24 * player - 12 * maxPlay, 10 + ( statc[player * 10 + 2] * 2), "b", fontc[rots[player]]);
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 0) ) {
			PlayWave(5);
			statc[player * 10 + 2]--;
			if(statc[player * 10 + 2] < 0) statc[player * 10 + 2] = 3;
			if(statc[player * 10 + 3] < 90){
				if(statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] <= 90)
				stage[player] = statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] + 99;
				else stage[player] = 189;
				if(repversw >= 47) FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
				loadTomoyoStage(player, stage[player]);
			}else{
				if(statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] <= 100)
					stage[player] = statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] + 99;
				else stage[player] = 199;
				if(repversw >= 47) FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
				loadTomoyoStage(player, stage[player]);
			}
		}
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		if( getPressState(player, 1) ) {
			PlayWave(5);
			statc[player * 10 + 2]++;
			if(statc[player * 10 + 2] > 3) statc[player * 10 + 2] = 0;
			if(statc[player * 10 + 3] < 90){
				if(statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] <= 90)
				stage[player] = statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] + 99;
				else stage[player] = 189;
				if(repversw >= 47) FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
				loadTomoyoStage(player, stage[player]);
			}else{
				if(statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] <= 100)
					stage[player] = statc[player * 10 + 3] + FP_next[statc[player * 10 + 2]] + 99;
				else stage[player] = 199;
				if(repversw >= 47) FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
				loadTomoyoStage(player, stage[player]);
			}
		}
	}

	// A�{�^��
	if( (getPushState(player, 4)) || ((statc[player * 10] != 0) && (statc[player * 10 + 1] > 600)) ) {
		PlayWave(10);
		if( statc[player * 10] == 0 ) {
			// �ŏ�
			stage[player] = start_stage[player];
			bgmlv = setstartBGM(gameMode[player], player);	//BGM�Z�b�g
			if(repversw >= 47) FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
			stat[player] = 1;					// �u���b�N�V���b�^�[
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;			// Ready
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
		}else{
			//�r��
			//BGM�؂�ւ�����
			if(stage[player] <= 129) i = 8;
			else if(stage[player] <= 159) i = 14;
			else if(stage[player] <= 189) i = 9;
			else i = 19;
			
			if(bgmlv != i){
				bgmlv = i;
				changeBGM(0);
			}
			if(repversw >= 47) FP_bonus[player] = 1000 * (((stage[player]-100) / 4) + 1);
			stat[player] = 3;					// Ready
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 0;			// 
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
		}
	}
	if(( statc[player * 10] == 0 ) && (getPushState(player, 5))) {		// B�{�^���Ń��[�h�I����ʂɖ߂�
		sp[player] = 1;
		PlayWave(5);
		randommode[player] = 1;
		versusInit(player);				// NEXT�𐶐�������
		randommode[player] = 0;
		stat[player] = 1;				// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 2;		// �V���b�^�[��̓X�e�[�^�XNo.2
		relaymode[player] = 0;
	}
}
//������������������������������������������������������������������������������
//  �X�e�[�W��̃v���`�i�u���b�N�z�u�������_���ɂ���
//������������������������������������������������������������������������������
void randPlatinum(int player, int tgtnum){
	int empty, i, j, put_flag[22], end_flag, put_num;
	
	if((tomoyo_rise[player]) || (tgtnum == 0)) return;
	for(i = 0; i < 22; i++) put_flag[i] = 0;
	put_num = 0;
	empty = 0;
	end_flag = 0;

	// �v���`�i�u���b�N�𕁒ʂ̃u���b�N�ɂ���
	for(i = 0; i < 220; i++) {
		if(fld[i + player * 220] >= 11) {
			fld[i + player * 220] = fld[i + player * 220] - 9;
		}
	}

	while(!end_flag){
		for(i = 0; i <= fldsizeh[player]; i++) {
			empty = 1;
			if((!put_flag[i]) || (tgtnum == 99)){
				for(j = 0; j < fldsizew[player]; j++) {
					if((fld[j + i * fldsizew[player] + player * 220] >= 2) && (fld[j + i * fldsizew[player] + player * 220] <= 8)) {
						empty = 0;
						if((tgtnum == 99) || (rand(10, player) == 0)) {
							fld[j + i * fldsizew[player] + player * 220] = fld[j + i * fldsizew[player] + player * 220] + 9;
							put_num++;
							put_flag[i] = 1;
							if((put_num >= tgtnum) && (tgtnum != 99)) return;
							if(tgtnum != 99) break;
						}
					}
				}
			}
			if(empty) put_flag[i] = 1;
		}
		end_flag = 1;
		for(i = 0; i < 22; i++){
			if(!put_flag[i]){
				end_flag = 0;
				break;
			}
		}
	}
}


//������������������������������������������������������������������������������
//  TOMOYO���[�h �X�e�[�W�ǂݍ��݁^�ۑ�
//������������������������������������������������������������������������������
// �t�@�C���t�H�[�}�b�g (4byte�P��)
//   0�`  209 �t�B�[���h�f�[�^�i��10 * �c21�}�X�j
// 210        MIRROR
// 211        ROLL ROLL
// 212        DEATH BLOCK
// 213        X-RAY
// 214        COLOR
// 215�`249   ���g�p�i���R�Ɏg�p�\�j
// 250�`449   ����オ��t�B�[���h

/* �X�e�[�W�f�[�^�����[�h */
void loadTomoyoStage(int player, int number) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	sprintf(string[0], "stage/stage%02d.sav", number);
	LoadFile(string[0], &saveBuf, 450 * 4);
	
	// �t�B�[���h�ǂݍ���
	for(i=0;i<210;i++) {
		fld[(i+10) + 220 * player] = saveBuf[i];
		// �����z�u��������悤�ɂ���
		fldt[(i+10) + 220 * player] = (fld[(i+10) + 220 * player] != 0) * -1;
	}
	
	for(i=0;i<200;i++)
		tomoyo_rise_fld[i + 200 * player] = saveBuf[i+250];
	
	if(gameMode[player] == 6) {
		// MIRROR
		isfmirror[player] = saveBuf[210]; // #1.60c7l7
		
		// ROLL ROLL
		rollroll_flag[player] = saveBuf[211]; // #1.60c7l7
		
		// DEATH BLOCK #1.60c7l8
		IsBig[player] = saveBuf[212];

		// X-RAY #1.60c7p9ex
		xray_flag[player] = saveBuf[213];

		// COLOR #1.60c7p9ex
		color_flag[player] = saveBuf[214];
		
		// BLIND C7T6.5
		blind_flag[player] = saveBuf[215];
		
		// �Œᗎ�����x
		min_speed[player] = saveBuf[216];
		
		// �T���_�[
		isthunder[player] = saveBuf[217];
		
		
		// NEXT�B��
		hnext_flag[player] = saveBuf[219];
		
		tomoyo_waits[player] = saveBuf[220];
	}
	// ����オ�� �i�~�b�V�����ł��g�p�j
	tomoyo_rise[player] = saveBuf[218];
}

/* �X�e�[�W�f�[�^���Z�[�u */
void saveTomoyoStage(int player, int number) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �t�B�[���h���Z�[�u�o�b�t�@�ɃR�s�[
	for(i=0;i<210;i++) {
		saveBuf[i] = fld[(i+10) + 220 * player];
	}
	
	for(i=0;i<200;i++)
		saveBuf[i+250] = tomoyo_rise_fld[i + 200 * player];
	
	// MIRROR
	//saveBuf[210] = fmirror;
	saveBuf[210] = isfmirror[player]; // #1.60c7l7
	
	// ROLL ROLL
	//saveBuf[211] = rollroll];
	saveBuf[211] = rollroll_flag[player]; // #1.60c7l7
	
	// DEATH BLOCK #1.60c7l8
	saveBuf[212] = IsBig[player];
	
	// X-RAY #1.60c7p9ex
	saveBuf[213] = xray_flag[player];
	
	// COLOR #1.60c7p9ex
	saveBuf[214] = color_flag[player];
	
	// BLIND C7T6.5
	saveBuf[215] = blind_flag[player];
	
	// �Œᗎ�����x
	saveBuf[216] = min_speed[player];
	
	// �T���_�[
	saveBuf[217] = isthunder[player];
	
	// ����オ��
	saveBuf[218] = tomoyo_rise[player];
	
	// NEXT�B��
	saveBuf[219] = hnext_flag[player];
	
	saveBuf[220] = tomoyo_waits[player];
	
	// �ۑ�����
	sprintf(string[0], "stage/stage%02d.sav", number);
	SaveFile(string[0], &saveBuf, 450 * 4);
}
