//������������������������������������������������������������������������������
//  �L�[��������Ă��烊�v���C��ۑ�����#1.60c7i9
//������������������������������������������������������������������������������
void ReplaySaveCheck(int player, int statnumber) {
	int i;

	//���x�����i�e�X�g�j
	if(abs_YGS2K(GetRealFPS() - max_fps_2) >= 10) return;
	
	if((time2[player] <= 72000) && !playback && replay_save[player]) {
		for(i = 0; i < 10; i++) {
			if(IsPushKey(2 + i + player * 14)) {
				saveReplayData(player, i + player * 10 + 1);
				statc[player * 10 + statnumber] = i + player * 10 + 1;
			}
		}
	}
}

//������������������������������������������������������������������������������
//  ���v���C�f�[�^���Z�[�u
//������������������������������������������������������������������������������
void saveReplayData(int pl, int number) {
	int i, j, temp1, temp2, max;
	
	if(gameMode[pl] == 4){	// VS�̓t�H�[�}�b�g���ꕔ�قȂ�
		saveReplay_VS(number);
		return;
	}
	FillMemory(&saveBuf, 50000 * 4, 0);

	// �t�@�C���t�H�[�}�b�g (4byte�P��)
	//   0�`    3 �w�b�_
	//   4        �t�@�C���T�C�Y
	//   5�`  179 �l�N�X�g�u���b�N
	// 200        �^�C��
	// 201        �Q�[�����[�h
	// 202        �X�R�A
	// 203        ���x��
	// 204        ���C��
	// 206        ������g���܂킵�ݒ�#1.60c7f9
	// 207		�@���x���A�b�v�{�[�i�X
	// 208�@�@�@�@������^�C��
	// 209�@�@�@�@15�����[�h

	// 234�`289   ��
	// 290        �X���[�Y���[�h
	// 291        �i�i���ړ�����
	// 292        �����������[�h
	// 293        ��������s����
	// 294        �Ԗ_���R��
	// 300�`44299 ���v���C�f�[�^

	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x20534952;
	saveBuf[2] = 0x4C504552;
	saveBuf[3] = 0x31765941;

	for(i = 0; i < 175; i++) {
		temp1 = 0;
		for(j = 0; j < 8; j++) {
			temp1 = temp1 | (nextb[(i << 3) + j + pl * 1400] << (j * 4));
		}
		saveBuf[i + 5] = temp1;
	}

	saveBuf[200] = time[pl];
	saveBuf[201] = gameMode[pl];
	saveBuf[202] = sc[pl];
	saveBuf[203] = lv[pl];
	saveBuf[204] = li[pl];
	saveBuf[205] = start[pl];	// �J�n���x���̕ۑ� #1.60c3
	saveBuf[206] = downtype;	// ������#1.60c7f9
	saveBuf[207] = lvupbonus;	// ���x���A�b�v�{�[�i�X #1.60c7g3
	saveBuf[208] = timelimit[pl];	// ������^�C�� #1.60c7g7
	saveBuf[209] = limit15;		// 15�����[�h#1.60c7h3
	saveBuf[210] = mps[pl * 2    ];
	saveBuf[211] = mps[pl * 2 + 1];
	saveBuf[212] = spawn_y_type;		// �o���ʒu�^�C�v #1.60c7s2
	saveBuf[213] = BigMove[pl];			// BIG���[�h�̈ړ��P�� #1.60c7m6
	saveBuf[214] = disable_hold;		// HOLD�L�� #1.60c7n7
	saveBuf[215] = disable_irs;			// IRS�L�� #1.60c7n7
	saveBuf[216] = start_stage[pl];		// �X�^�[�g���̃X�e�[�W�iTOMOYO�p�j#1.60c7n8
	saveBuf[217] = start_nextc[pl];		// �X�^�[�g����nextc�iTOMOYO�p�j#1.60c7n8
	saveBuf[218] = t_noborder[pl];		// ���؂�Ȃ����[�h�iTOMOYO�j #1.60c7n8
	saveBuf[219] = clearnum[pl];		// �X�L�b�v�����ɃN���A�������iTOMOYO�j #1.60c7o3
	saveBuf[220] = clearp[pl];			// �N���A���iTOMOYO�j #1.60c7o3
	saveBuf[221] = t_training[pl];		// �g���[�j���O���[�h�iTOMOYO�j#1.60c7o7
	saveBuf[222] = disable_wallkick;	// �ǏR��֎~ #1.60c7q2ex
	saveBuf[223] = r_irs;				// IRS� #1.60c7q6
	saveBuf[224] = big_rise;			// BIG���̂���オ��2�{ #1.60c7r2
	saveBuf[225] = anothermode[pl];		// �A�i�U�[���[�h
	saveBuf[226] = randommode[pl];		// �����_�����ǂ���
	saveBuf[227] = timelimit2[pl];		// LEVEL1000���؂�^�C��
	saveBuf[228] = timelimitw[pl];		// ���[���h�p���؂�^�C��
	saveBuf[229] = world_i_rot;			// ���[���h����I�^��]�@�� #1.60c7r7
	saveBuf[230] = ybigtype;			// BIG���̏c�ړ��^�C�v
	saveBuf[231] = upLineT[pl];			// ����オ��^�C�v #1.60c7s6
	saveBuf[232] = enable_grade[pl];	// �i�ʃV�X�e����2��ނɂȂ������ߒǉ� C7T6.4
	saveBuf[233] = tspin_type;			// �X�R�A�ɉe�� C7T6.4
	saveBuf[234] = mission_file;		// �~�b�V�����t�@�C���ԍ�
	saveBuf[235] = start_mission;		// �J�n���̃~�b�V�����ԍ�
	saveBuf[236] = first_seed[pl];		// �����V�[�h�@���d�v
	saveBuf[237] = max_hnext[pl];		// NEXT�ő�\����
	saveBuf[238] = death_plus[pl];
	saveBuf[239] = max_fps_2;			// FPS
	saveBuf[240] = enable_minspeed;		// TOMOYO�Œᑬ�x�ݒ�̗L��
	saveBuf[241] = nanamedown;
	saveBuf[242] = item_mode[pl];		// �A�C�e�����[�h
	saveBuf[243] = hebo_plus[pl];		// HEBO+
	saveBuf[244] = item_num;			// ���^���_�ł̃A�C�e����
	saveBuf[245] = examination[pl];		// �i�ʔF�莎��
	saveBuf[246] = exam_grade[pl];		// �����i��
	saveBuf[247] = ace_irs;				// IRS��ACE����
	saveBuf[248] = ready_go_style;		// READY��GO�̎��
	saveBuf[249] = r_start[pl];
	saveBuf[250] = r_end[pl];
	saveBuf[251] = g_start[pl];
	saveBuf[252] = g_end[pl];
	saveBuf[253] = item_interval;
	saveBuf[254] = devil_minus[pl];		// DEVIL-
	saveBuf[255] = devil_randrise;
		// 256-258�Ԗڂ�SHIRASE�֌W(�e�ʂ̐ߖ�̂��߁A2�̒l���l�ߍ���ł���) #1.60c7f4
	// 256 �ǂ̃o�[�W�����ŋL�^���ꂽ���H
	// 257 HI = SHIRASE�̗L��/����
	// 257 LO = SHIRASE�̊J�n���x��
	// 258 HI = ����オ��̒i��
	// 258 LO = ����オ��̊Ԋu
	// �����̒l�͐ݒ�t�@�C���܂��͊J�n�O�̃��j���[����ݒ肳���
	saveBuf[256] = repversw;
	saveBuf[257] = (p_shirase[pl] << 16) | level_shirase_start;
	saveBuf[258] = (raise_shirase_lines << 16) | raise_shirase_interval;
	saveBuf[259] = novice_mode[pl];
	saveBuf[260] = std_opt[pl];//262�܂�STANDARD�p�̐ݒ�
	saveBuf[261] = sp[pl];
	saveBuf[262] = wait1[pl] + wait2[pl] * 0x100 + wait3[pl] * 0x10000 + waitt[pl] * 0x1000000;
	saveBuf[263] = timelimitm[pl];			// devilminus�p���؂�^�C��
	saveBuf[264] = timelimitmw[pl];			// devilminus�p���؂�^�C��
	saveBuf[265] = b2bcheck;		// Back to Back
	saveBuf[266] = p_bgmlv;
	saveBuf[267] = relaymode[pl];

	
	saveBuf[290] = smooth;
	saveBuf[291] = nanameallow;
	saveBuf[292] = sonicdrop;
	saveBuf[293] = fastlrmove;
	if(relaymode[pl])
		saveBuf[294] = first_rot[pl];			// ��]�����̃Z�[�u #1.60c
	else
		saveBuf[294] = rots[pl];
	//saveBuf[295] = lvup[pl];
	saveBuf[296] = ori_opt[pl];		// �̃Z�[�u #1.60c6
	saveBuf[297] = IsBigStart[pl];
	//saveBuf[298] = startnextc[pl];
	saveBuf[299] = w_reverse;			// ���[���h����]�����t�]#1.60c7f8


	
	// TOMOYO���[�h�ł̓X�R�A�ɓ��B�X�e�[�W������i�蔲�����b��I�j#1.60c7n8
	if((gameMode[pl] == 6) && (stage[pl] < 100)) {
		saveBuf[202] = stage[pl] + 1;
	}
	
	temp1 = pl * 60 * 60 * 20;
	
	max = time2[pl] / 2;
	
	if(max > 60 * 60 * 20 / 2) max = 60 * 60 * 20 / 2;
	for(i = 0; i < max; i++) {
		saveBuf[i + 300] = replayData[(i << 1) + temp1] | (replayData[(i << 1) + 1 + temp1] << 16);
	}

	saveBuf[4] = (max + 300) * 4;

	if(number <= 40)
		sprintf(string[0], "REPLAY/REPLAY%02d.SAV", number);
	else
		sprintf(string[0], "DEMO/DEMO%02d.SAV", number - 40);

	SaveFile(string[0], &saveBuf, saveBuf[4]);
}

//������������������������������������������������������������������������������
//  VS���[�h�̃��v���C�f�[�^���Z�[�u
//������������������������������������������������������������������������������
void saveReplay_VS(int number) {
	int i, j, temp1, temp2, max, pl;
	pl = 0;

	FillMemory(&saveBuf, 50000 * 4, 0);

	// 300�`22299 �@1P���v���C�f�[�^
	// 22300�`44299 2P���v���C�f�[�^

	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x20534952;
	saveBuf[2] = 0x4C504552;
	saveBuf[3] = 0x31765941;

	for(i = 0; i < 175; i++) {
		temp1 = 0;
		for(j = 0; j < 8; j++) {
			temp1 = temp1 | (nextb[(i << 3) + j] << (j * 4));
		}
		saveBuf[i + 5] = temp1;
	}

	saveBuf[200] = time[0];
	saveBuf[201] = gameMode[0];
	saveBuf[204] = time2[0];	// ���v���C���ԁ@�v���C���[��
	saveBuf[205] = time2[1];	// 
	saveBuf[206] = downtype;	// ������#1.60c7f9
	saveBuf[207] = lvupbonus;	// ���x���A�b�v�{�[�i�X #1.60c7g3
//	saveBuf[208]
	saveBuf[209] = limit15;		// 15�����[�h#1.60c7h3

	saveBuf[210] = mps[0 * 2    ];
	saveBuf[211] = mps[0 * 2 + 1];
	saveBuf[202] = mps[1 * 2    ];
	saveBuf[203] = mps[1 * 2 + 1];

	saveBuf[212] = spawn_y_type;		// �o���ʒu�^�C�v #1.60c7s2

	saveBuf[213] = BigMove[0];			// BIG���[�h�̈ړ��P�� #1.60c7m6
	saveBuf[234] = BigMove[1];

	saveBuf[214] = disable_hold;		// HOLD�L�� #1.60c7n7
	saveBuf[215] = disable_irs;			// IRS�L�� #1.60c7n7
	saveBuf[222] = disable_wallkick;	// �ǏR��֎~ #1.60c7q2ex
	saveBuf[223] = r_irs;				// IRS� #1.60c7q6
	saveBuf[224] = big_rise;			// BIG���̂���オ��2�{ #1.60c7r2
	saveBuf[229] = world_i_rot;			// ���[���h����I�^��]�@�� #1.60c7r7
	saveBuf[230] = ybigtype;			// BIG���̏c�ړ��^�C�v
	saveBuf[231] = upLineT[0];			// ����オ��^�C�v #1.60c7s6
	saveBuf[232] = upLineT[1];
	saveBuf[233] = tspin_type;			// �X�R�A�ɉe�� C7T6.4

	saveBuf[235] = first_seed[0];
	saveBuf[236] = first_seed[1];		// �����V�[�h�@���d�v
	saveBuf[237] = max_hnext[0];		// NEXT�ő�\����
	saveBuf[238] = max_hnext[1];
	saveBuf[239] = max_fps_2;			// FPS
//	saveBuf[240]
	saveBuf[241] = nanamedown;
//	saveBuf[242]
//	saveBuf[243]
	saveBuf[244] = item_num;			// ���^���_�ł̃A�C�e����
//	saveBuf[245]
//	saveBuf[246]
	saveBuf[247] = ace_irs;				// IRS��ACE����
	saveBuf[248] = ready_go_style;		// READY��GO�̎��
	saveBuf[249] = r_start[0];
	saveBuf[250] = r_end[0];
	saveBuf[251] = g_start[0];
	saveBuf[252] = g_end[0];
	saveBuf[253] = item_interval;
//	saveBuf[254]
//	saveBuf[255]
	saveBuf[256] = repversw;
	saveBuf[257] = (p_shirase[pl] << 16) | level_shirase_start;
	saveBuf[258] = (raise_shirase_lines << 16) | raise_shirase_interval;
//	saveBuf[259]
	saveBuf[260] = sp[0];
	saveBuf[261] = sp[1];
	saveBuf[262] = wait1[0] + wait2[0] * 0x100 + wait3[0] * 0x10000 + waitt[0] * 0x1000000;
	saveBuf[263] = wait1[1] + wait2[1] * 0x100 + wait3[1] * 0x10000 + waitt[1] * 0x1000000;
//	saveBuf[264]
	saveBuf[265] = b2bcheck;		// Back to Back
//	saveBuf[266]
//	saveBuf[267]

	saveBuf[290] = smooth;
	saveBuf[291] = nanameallow;
	saveBuf[292] = sonicdrop;
	saveBuf[293] = fastlrmove;
	saveBuf[294] = first_rot[0];			// ��]�����̃Z�[�u #1.60c
	saveBuf[295] = first_rot[1];
//	saveBuf[296]
	saveBuf[297] = IsBigStart[0];
	saveBuf[298] = IsBigStart[1];
	saveBuf[299] = w_reverse;			// ���[���h����]�����t�]#1.60c7f8

	// VS��p����
	saveBuf[216] = use_item[0];
	saveBuf[217] = use_item[1];
	saveBuf[218] = versus_rot[0];
	saveBuf[219] = versus_rot[1];
	saveBuf[220] = vs_time;
	saveBuf[221] = wintype;
	saveBuf[225] = vs_goal;
	saveBuf[226] = noitem;
	saveBuf[227] = disrise;
	saveBuf[228] = winpoint;


	for(pl = 0; pl <= 1; pl++){
		temp1 = pl * 60 * 60 * 20;
		
		max = time2[pl] / 2;
		
		if(max > 60 * 60 * 10 / 2) max = 60 * 60 * 10 / 2;
		for(i = 0; i < max; i++) {
			saveBuf[i + 300 + (22000 * pl)] = replayData[(i << 1) + temp1] | (replayData[(i << 1) + 1 + temp1] << 16);
		}
	}

	saveBuf[4] = (300 + 22000 + (time2[1] / 2)) * 4;

	if(number <= 40)
		sprintf(string[0], "REPLAY/REPLAY%02d.SAV", number);
	else
		sprintf(string[0], "DEMO/DEMO%02d.SAV", number - 40);

	SaveFile(string[0], &saveBuf, saveBuf[4]);
}

//������������������������������������������������������������������������������
//  ���v���C�f�[�^�����[�h
//������������������������������������������������������������������������������
int loadReplayData(int pl, int number) {
	int i, j, temp1, temp2, max,k,sptemp[3];

	FillMemory(&saveBuf, 50000 * 4, 0);

	if(number <= 40)
		sprintf(string[0], "REPLAY/REPLAY%02d.SAV", number);
	else
		sprintf(string[0], "DEMO/DEMO%02d.SAV", number - 40);

	LoadFile(string[0], &saveBuf, 820);
	
	if(saveBuf[201] == 4)	// VS�̓t�H�[�}�b�g���ꕔ�قȂ�
		return(loadReplay_VS(number));

	if(saveBuf[4] > 200000) saveBuf[4] = 200000;
	if(saveBuf[4] < 800) return (1);
	

	LoadFile(string[0], &saveBuf, saveBuf[4]);

	if(saveBuf[0] != 0x4F424548) return (1);
	if(saveBuf[1] != 0x20534952) return (1);
	if(saveBuf[2] != 0x4C504552) return (1);
	if(saveBuf[3] != 0x31765941) return (1);

	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j] = ((saveBuf[5 + i]) >> (j * 4)) & 15;
		}
	}

//	max = (saveBuf[200] + 3730) / 2 + 1;
	max = saveBuf[4] /2 + 1;
	gameMode[pl] = saveBuf[201];
	start[pl] = saveBuf[205];		// �J�n���x���̃��[�h #1.60c3

	// �w�i�ݒ�#1.60c7h6
	if(start[pl] > 1100)
		backno = 11;
	else
		backno = start[pl] / 100;

	downtype  = saveBuf[206];		// ������#1.60c7f9
	lvupbonus = saveBuf[207];		// ���x���A�b�v�{�[�i�X #1.60c7g3
	timelimit[pl] = saveBuf[208];		// ������^�C�� #1.60c7g7
	limit15   = saveBuf[209];		// 15�����[�h#1.60c7h3

	mps[pl * 2    ] = saveBuf[210];
	mps[pl * 2 + 1] = saveBuf[211];
	spawn_y_type = saveBuf[212];		// �o���ʒu�^�C�v #1.60c7s2
	BigMove[pl] = saveBuf[213];			// BIG���[�h�̈ړ��P�� #1.60c7m6
	disable_hold = saveBuf[214];		// HOLD�L�� #1.60c7n7
	disable_irs = saveBuf[215];			// IRS�L�� #1.60c7n7
	start_stage[pl] = saveBuf[216];		// �X�^�[�g���̃X�e�[�W�iTOMOYO�p�j#1.60c7n8
	start_nextc[pl] = saveBuf[217];		// �X�^�[�g����nextc�iTOMOYO�p�j#1.60c7n8
	t_noborder[pl] = saveBuf[218];		// ���؂�Ȃ����[�h�iTOMOYO�j #1.60c7n8
	t_training[pl] = saveBuf[221];		// �g���[�j���O���[�h�iTOMOYO�j#1.60c7o7
	disable_wallkick = saveBuf[222];	// �ǏR��֎~ #1.60c7q2ex
	r_irs = saveBuf[223];				// IRS� #1.60c7q6
	big_rise = saveBuf[224];			// BIG���̂���オ��2�{ #1.60c7r2
	anothermode[pl] = saveBuf[225];		// �A�i�U�[���[�h
	randommode[pl] = saveBuf[226];  	// �����_�����ǂ���
	timelimit2[pl] = saveBuf[227];			// LEVEL1000���؂�^�C��
	timelimitw[pl] = saveBuf[228];			// ���[���h�p���؂�^�C��
	world_i_rot = saveBuf[229];			// ���[���h����I�^��]�@�� #1.60c7r7
	ybigtype = saveBuf[230];			// BIG���̏c�ړ��^�C�v
	upLineT[pl] = saveBuf[231];			// ����オ��^�C�v #1.60c7s6
	timelimitm[pl] = saveBuf[263];			// devilm�p���؂�^�C��
	timelimitmw[pl] = saveBuf[264];			// devilm�p���؂�^�C��
	smooth = saveBuf[290];
	nanameallow = saveBuf[291];
	sonicdrop = saveBuf[292];
	fastlrmove = saveBuf[293];
	rots[pl] = saveBuf[294];			// ��]�����̃��[�h #1.60c
	//lvup[pl] =saveBuf[295];
	ori_opt[pl] = saveBuf[296];		// ���[�h #1.60c6
	IsBigStart[pl] = saveBuf[297];
	w_reverse = saveBuf[299];			// ���[���h����]�����t�]#1.60c7f8
	
	// �X�^�[�g����nextc
	if(gameMode[pl] == 6) {
		nextc[pl] = saveBuf[217];	// TOMOYO�p #1.60c7n8
	} else {
		nextc[pl] = saveBuf[298];	// �ʏ�
	}
	
	// 256-257�Ԗڂ�SHIRASE�֌W(�e�ʂ̐ߖ�̂��߁A2�̒l��1�̕ϐ��ɋl�ߍ���ł���) #1.60c7f4
	if(saveBuf[256] == 0) {
		p_shirase[pl] = (saveBuf[201] ==3);
		level_shirase_start = p_shirase_start_level;
		raise_shirase_lines = p_shirase_line;
		raise_shirase_interval = p_shirase_interval;
	} else {
		p_shirase[pl] = saveBuf[257] >> 16;
		level_shirase_start = saveBuf[257] & 0xffff;
		raise_shirase_lines = saveBuf[258] >> 16;
		raise_shirase_interval = saveBuf[258] & 0xffff;
	}
	repversw = saveBuf[256];		// ���o�[�W�����̃��v���C�f�[�^���Đ����邽�߂̃X�C�b�` #1.60c7h2
	
	if(repversw >= 19){	//���̃o�[�W��������V���ɒǉ�
		enable_grade[pl] = saveBuf[232];		// �i�ʃV�X�e����2��ނɂȂ������ߒǉ� C7T6.4
		if(repversw<52){
			tspin_type = saveBuf[233]+1;			// �X�R�A�ɉe�� C7T6.4
		}else{
			tspin_type = saveBuf[233];
		}
	}
	if(repversw >= 21){
		 mission_file = saveBuf[234];		// �~�b�V�����t�@�C���ԍ�
		 start_mission = saveBuf[235];		// �J�n���̃~�b�V�����ԍ�
		 first_seed[pl] = saveBuf[236];		// �����V�[�h�@���d�v
		 randseed[pl] = first_seed[pl];
	}
	if(repversw >= 22){
		max_hnext[pl] = saveBuf[237];		// NEXT�ő�\����
		death_plus[pl] = saveBuf[238];
	} else {
		death_plus[pl] = 0;
		max_hnext[pl] = dispnext;
	}
	if(repversw >= 26){
		enable_minspeed = saveBuf[240];		// TOMOYO�Œᑬ�x�l��L���ɂ��邩
	} else if(repversw == 25){
		enable_minspeed = 1;
	}
	if(repversw >= 28) {
		nanamedown = saveBuf[241];	//�΂ߓ��͂ł̌Œ��L���ɂ��邩 #C7T9.6EX
		item_mode[pl] = saveBuf[242];
		hebo_plus[pl] = saveBuf[243];
		item_num = saveBuf[244];
	} else if(repversw == 27) {
		nanamedown = 0;
		item_mode[pl] = 0;
		hebo_plus[pl] = 0;
	} else {
		nanamedown = 1;
		item_mode[pl] = 0;
		hebo_plus[pl] = 0;
	}
	if(repversw >= 32){
		examination[pl] = saveBuf[245];
		exam_grade[pl] = saveBuf[246];
		ace_irs = saveBuf[247];
	} else {
		examination[pl] = 0;
		ace_irs = 0;
	}
	if(repversw >= 37){
		ready_go_style = saveBuf[248];
		r_start[pl] = saveBuf[249];
		r_end[pl] = saveBuf[250];
		g_start[pl] = saveBuf[251];
		g_end[pl] = saveBuf[252];
	} else {
		ready_go_style = 0;
	}
	if(repversw >= 38)
		item_interval = saveBuf[253];
	else item_interval = 20;
	
	if(repversw >= 42)
		devil_minus[pl] = saveBuf[254];
	else devil_minus[pl] = 0;
	
	if(repversw >= 44)
		devil_randrise = saveBuf[255];
	else devil_randrise = 0;
	
	if(repversw >= 45)
		novice_mode[pl] = saveBuf[259];
	else novice_mode[pl] = 0;
	
	std_opt[pl] = saveBuf[260];
	
	if(repversw >= 54)
		b2bcheck = saveBuf[265];
	else
		b2bcheck = (tspin_type == 2);

	setStartLevel(pl);		// start[pl]����e�푬�x�ݒ�
	
	if(saveBuf[201] ==9){	
		if(std_opt[pl] <= 1){
			sp[pl] = saveBuf[261];
			for(k = 0; k <= 3; k++) {
				sptemp[k] = (saveBuf[262] >> (k * 8)) & 0xff;
			}
			wait1[pl] = sptemp[0];
			wait2[pl] = sptemp[1];
			wait3[pl] = sptemp[2];
			waitt[pl] = sptemp[3];
			p_bgmlv = saveBuf[266];
			relaymode[pl] = saveBuf[267];
		}
	}

	if(IsBigStart[pl]) {
		IsBig[pl] = 1;
	}
	
	temp1 = pl * 60 * 60 * 20;

	if(max > 60 * 60 * 20 / 2) max = 60 * 60 * 20 / 2;
	for(i = 0; i < max; i++) {
		replayData[(i << 1) + temp1    ] =  saveBuf[i + 300] & 0xFFFF;
		replayData[(i << 1) + temp1 + 1] = (saveBuf[i + 300] & 0xFFFF0000) >> 16;
	}
	
	next[pl] = nextb[nextc[pl] + pl * 1400];	// #1.60c7n7
	setNextBlockColors(pl, 1);	// #1.60c7n2
	
	stage[pl] = start_stage[pl];	// �J�n�X�e�[�W #1.60c7n8
	
	return (0);
}
//������������������������������������������������������������������������������
//  VS�̃��v���C�f�[�^�����[�h
//������������������������������������������������������������������������������
int loadReplay_VS(int number) {
	int i, j, temp1, temp2, max[2],k,sptemp[3],pl;
	pl = 0;

	FillMemory(&saveBuf, 50000 * 4, 0);

	if(number <= 40)
		sprintf(string[0], "REPLAY/REPLAY%02d.SAV", number);
	else
		sprintf(string[0], "DEMO/DEMO%02d.SAV", number - 40);

	LoadFile(string[0], &saveBuf, 820);
	
	if(saveBuf[4] > 200000) saveBuf[4] = 200000;
	if(saveBuf[4] < 800) return (1);
	

	LoadFile(string[0], &saveBuf, saveBuf[4]);

	if(saveBuf[0] != 0x4F424548) return (1);
	if(saveBuf[1] != 0x20534952) return (1);
	if(saveBuf[2] != 0x4C504552) return (1);
	if(saveBuf[3] != 0x31765941) return (1);

	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j] = ((saveBuf[5 + i]) >> (j * 4)) & 15;
		}
	}
	// 1P��NEXT��2P�ɃR�s�[ #1.60c7m1
	for(i=0;i<1400;i++) {
		nextb[i + 1400] = nextb[i];
	}

//	max = (saveBuf[200] + 3730) / 2 + 1;
	max[0] = saveBuf[4] /2 + 1;
	gameMode[0] = saveBuf[201];
	gameMode[1] = saveBuf[201];
	start[0] = 0;
	start[1] = 0;

	backno = 61;

	downtype  = saveBuf[206];		// ������#1.60c7f9
	lvupbonus = saveBuf[207];		// ���x���A�b�v�{�[�i�X #1.60c7g3
//	timelimit[pl] = saveBuf[208];		// ������^�C�� #1.60c7g7
	limit15   = saveBuf[209];		// 15�����[�h#1.60c7h3

	mps[0 * 2    ] = saveBuf[210];
	mps[0 * 2 + 1] = saveBuf[211];
	mps[1 * 2    ] = saveBuf[202];
	mps[1 * 2 + 1] = saveBuf[203];
	spawn_y_type = saveBuf[212];		// �o���ʒu�^�C�v #1.60c7s2
	BigMove[0] = saveBuf[213];			// BIG���[�h�̈ړ��P�� #1.60c7m6
	BigMove[1] = saveBuf[234];
	disable_hold = saveBuf[214];		// HOLD�L�� #1.60c7n7
	disable_irs = saveBuf[215];			// IRS�L�� #1.60c7n7
	disable_wallkick = saveBuf[222];	// �ǏR��֎~ #1.60c7q2ex
	r_irs = saveBuf[223];				// IRS� #1.60c7q6
	big_rise = saveBuf[224];			// BIG���̂���オ��2�{ #1.60c7r2
	world_i_rot = saveBuf[229];			// ���[���h����I�^��]�@�� #1.60c7r7
	ybigtype = saveBuf[230];			// BIG���̏c�ړ��^�C�v
	upLineT[0] = saveBuf[231];			// ����オ��^�C�v #1.60c7s6
	upLineT[1] = saveBuf[232];

	smooth = saveBuf[290];
	nanameallow = saveBuf[291];
	sonicdrop = saveBuf[292];
	fastlrmove = saveBuf[293];

	rots[0] = saveBuf[294];			// ��]�����̃��[�h #1.60c
	rots[1] = saveBuf[295];

	IsBigStart[0] = saveBuf[297];
	IsBigStart[1] = saveBuf[298];
	w_reverse = saveBuf[299];			// ���[���h����]�����t�]#1.60c7f8
	

	nextc[0] = 0;
	nextc[1] = 0;
	
	// 256-257�Ԗڂ�SHIRASE�֌W(�e�ʂ̐ߖ�̂��߁A2�̒l��1�̕ϐ��ɋl�ߍ���ł���) #1.60c7f4
	p_shirase[pl] = saveBuf[257] >> 16;
	level_shirase_start = saveBuf[257] & 0xffff;
	raise_shirase_lines = saveBuf[258] >> 16;
	raise_shirase_interval = saveBuf[258] & 0xffff;

	repversw = saveBuf[256];		// ���o�[�W�����̃��v���C�f�[�^���Đ����邽�߂̃X�C�b�` #1.60c7h2
	
	tspin_type = saveBuf[233];

	max_hnext[0] = saveBuf[237];		// NEXT�ő�\����
	max_hnext[1] = saveBuf[238];
	
	 first_seed[0] = saveBuf[235];		// �����V�[�h�@���d�v
	 randseed[0] = first_seed[0];
	 
	 first_seed[1] = saveBuf[236];
	 randseed[1] = first_seed[1];
	 
	nanamedown = saveBuf[241];	//�΂ߓ��͂ł̌Œ��L���ɂ��邩 #C7T9.6EX
	item_num = saveBuf[244];

	ace_irs = saveBuf[247];

	ready_go_style = saveBuf[248];
	r_start[0] = saveBuf[249];
	r_end[0] = saveBuf[250];
	g_start[0] = saveBuf[251];
	g_end[0] = saveBuf[252];
	
	r_start[1] = saveBuf[249];
	r_end[1] = saveBuf[250];
	g_start[1] = saveBuf[251];
	g_end[1] = saveBuf[252];

	use_item[0] = saveBuf[216];
	use_item[1] = saveBuf[217];
	versus_rot[0] = saveBuf[218];
	versus_rot[1] = saveBuf[219];
	vs_time  = saveBuf[220];
	wintype = saveBuf[221];
	vs_goal = saveBuf[225];
	noitem = saveBuf[226];
	disrise = saveBuf[227];
	winpoint = saveBuf[228];

	item_interval = saveBuf[253];
	
	b2bcheck = saveBuf[265];

//	setStartLevel(pl);		// start[pl]����e�푬�x�ݒ�
	
	sp[0] = saveBuf[260];
	for(k = 0; k <= 3; k++) {
		sptemp[k] = (saveBuf[262] >> (k * 8)) & 0xff;
	}
	wait1[0] = sptemp[0];
	wait2[0] = sptemp[1];
	wait3[0] = sptemp[2];
	waitt[0] = sptemp[3];
	
	sp[1] = saveBuf[261];
	for(k = 0; k <= 3; k++) {
		sptemp[k] = (saveBuf[263] >> (k * 8)) & 0xff;
	}
	wait1[1] = sptemp[0];
	wait2[1] = sptemp[1];
	wait3[1] = sptemp[2];
	waitt[1] = sptemp[3];

	if(IsBigStart[0]) {
		IsBig[0] = 1;
	}
	
	if(IsBigStart[1]) {
		IsBig[1] = 1;
	}
	for(pl = 0; pl <= 1; pl++){
		temp1 = pl * 60 * 60 * 20;
		
		max[pl] = 60 * 60 * 10 / 2;

		if(max[pl] > 60 * 60 * 10 / 2) max[pl] = 60 * 60 * 10 / 2;
		for(i = 0; i < max[pl]; i++) {
			replayData[(i << 1) + temp1    ] =  saveBuf[i + 300 + (22000 * pl)] & 0xFFFF;
			replayData[(i << 1) + temp1 + 1] = (saveBuf[i + 300 + (22000 * pl)] & 0xFFFF0000) >> 16;
		}
		
		next[pl] = nextb[nextc[pl] + pl * 1400];	// #1.60c7n7
		setNextBlockColors(pl, 1);	// #1.60c7n2
	}
	
	
	return (0);
}

//������������������������������������������������������������������������������
//  ���v���C�֘A
//������������������������������������������������������������������������������
int ReplaySelectProc(void) {
	int i,bgmmode;
	
	ReplaySelectInitial();
	flag = 0;
	
	while(!flag) {
		count++;
		ReplaySelect();
		if(IsPushEscKey()) restoreSetups();
		spriteTime();
	}

	if(flag > 0) {
		demo = 0;
		playback = 1;
		domirror = 1;	// ������L��

		gameAllInit();
		playerInitial(0);
		playerInitial(1);
		loadReplayData(0, flag);

		timeOn[0] = 0;
		onRecord[0] = 0;
		stat[0] = 1;					// �u���b�N�V���b�^�[���s
		statc[0] = 0;					// �X�e�[�^�X�J�E���^��0��
		statc[1] = 3;					// �V���b�^�[��̓X�e�[�^�XNo.3
		if(examination[0])
		statc[1] = 30;
		//next[0] = nextb[nextc[0]];		// #1.60c7
		if(gameMode[0] == 6){
			if((start_stage[0] >= 27) && (start_stage[0] <= 44))
				ltime[0] = 600 * 60;
			else if(start_stage[0] >= 100)
				ltime[0] = 1080 * 60;
		}
		if((gameMode[0] == 9)&&(std_opt[0] == 1)){
			ltime[0] = 120 * 60;
		}
		// �i�ʐݒ肪�L�^����Ă��Ȃ����v���C��
		// 4�ݒ�ōĐ�����Ɗm���ɂ����̂ŁB
		if((repversw < 19) && (enable_grade[0] == 4))
			enable_grade[0] = 2;
		bgmlv = setstartBGM(gameMode[0], 0);
		dispLinfo = 1;
		hnext[0] = max_hnext[0];
		if(gameMode[0] == 8){
			c_mission = start_mission;
			loadMissionData(mission_file);
			if(mission_type[c_mission] == 19)
				backno = 10;
			else if((mission_type[c_mission] == 20) || (mission_type[c_mission] == 22))
				backno = 11;
			else {
			backno = ((c_mission+1) % 10)-1;
			if(backno < 0)
				backno = 9;
			}
			if(backno >= bg_max) backno = bg_max;
			bgmlv = mission_bgm[c_mission];
			if(repversw < 54) missionSetStatus();
			if(((mission_file == 6) || (mission_file == 18) || (mission_file == 24)) && (start_mission == 0)) PlaySE(18);
		}
		if(gameMode[0] == 4){
			timeOn[1] = 0;
			onRecord[1] = 0;
			hnext[1] = max_hnext[1];
			gameMode[1] = 4;		// 2P �ݒ�
			stat[1] = 1;			// �u���b�N�V���b�^�[���s
			statc[0 + 10] = 0;		// �X�e�[�^�X�J�E���^��0��
			statc[1 + 10] = 3;		// �V���b�^�[��̓X�e�[�^�XNo.3
			if(!tmp_maxPlay)
				maxPlay = 1;
			domirror = 0;
		}
		if(((gameMode[0] == 3) && (!devil_minus[0])) || ((gameMode[0] == 7) && (anothermode[0] == 2))){
			PlaySE(18);//����
			gflash[0]=120;
		}
		return (2);
	} else
		return (0);
}
//BGM������
int ReplayBgmModeDecide(int pl,int mode,int nv,int dm,int eg){
	if(mode==0){
		if(!nv){//HANABI
			return 0;
		}else{
			return 1;//SCORE
		}
	}else if(mode==3){
		if(!dm){
			return 5;
		}else{
			return 6;
		}
	}else{
		if(eg==1){
			return 2;
		}else if(eg==4){
			return 4;
		}else{
			return 3;
		}
	}
}
int getModeAddRep(void){
	if(saveBuf[201] == 0) return saveBuf[259];
	else if((saveBuf[201] == 1) || (saveBuf[201] == 2)) return saveBuf[232];
	else if(saveBuf[201] == 3) return saveBuf[254];
	else if(saveBuf[201] == 6) return (saveBuf[216] >= 27)+(saveBuf[216] >= 45)+(saveBuf[216] >= 69)+(saveBuf[216] >= 100);
	else if(saveBuf[201] == 7) return saveBuf[225];
	else if(saveBuf[201] == 9){
		if(saveBuf[267]) return 4;
		else return saveBuf[260];
	}else if(saveBuf[201] == 10) return saveBuf[296];
	else return 0;
}
void ReplaySelectInitial(void) {
	int		i;

	cnt = 0;
	csr = 0;

	for(i = 0; i < 40; i++) {

		if(!loadReplayData(0, i + 1)) {
			enable[i] = saveBuf[201];
			enable[i + 40] = getModeAddRep();
			cnt++;
			getTime(saveBuf[200]);
			// �t�@�C���ԍ��\���ǉ� #1.60c7i5
			if(saveBuf[201] == 6) {
				// TOMOYO
				if(saveBuf[216] <= 26)
					sprintf(string[1], "%3d>", saveBuf[220]);	// �N���A��
				else
					sprintf(string[1], "    ", saveBuf[220]);
				sprintf(string[10 + i], "%2d %7d  %s        %s", i + 1, saveBuf[202], string[1], string[0]);
			} else if(saveBuf[201] == 7) {
				// ACE
				sprintf(string[10 + i], "%2d          %4d  %4d  %s", i + 1, saveBuf[203], saveBuf[204], string[0]);
			} else if(saveBuf[201] == 9){
				if(saveBuf[260] == 0)
					sprintf(string[10 + i], "%2d                      %s", i + 1, string[0]);
				else if(saveBuf[260] == 1)
					sprintf(string[10 + i], "%2d                %4d  ", i + 1, saveBuf[204]);
				else
					sprintf(string[10 + i], "%2d %7d  %4d  %4d  %s", i + 1, saveBuf[202], saveBuf[203], saveBuf[204], string[0]);
			} else if((saveBuf[201] != 8) && (saveBuf[201] != 4)){
				// �ʏ�
				sprintf(string[10 + i], "%2d %7d  %4d  %4d  %s", i + 1, saveBuf[202], saveBuf[203], saveBuf[204], string[0]);
			} else
				sprintf(string[10 + i],"%2d                      %s ", i + 1,string[0]);
		} else {
			enable[i] = -1;
			StrCpy(string[10 + i], "");
		}
	}

	if(cnt) {
		while(enable[csr] == -1) {
			csr++;
			if(csr >= 40) csr = 0;
		}
	}
}

void ReplaySelect(void) {
	int		i,start,end;

	KeyInput();
	
	// �w�i�`��
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
	
	// B�Ŗ߂�
	if(getPushState(0, 5)) {
		restoreSetups();
		if(gameMode[0] == 8) gameMode[0] = 0;
		if(gameMode[0] == 4){
			gameMode[0] = 0;
			gameMode[1] = 0;
		}
		flag = -1;
	}
	
	if(!cnt) {
		printFont(13, 14, "NO REPLAY DATA", 2);
		return;
	}
	
	ExBltRect(77, 0, 232,  count % 320, 20, 320 - (count % 320), 8);
	ExBltRect(77, 320 - (count % 320), 232,  0, 20, count % 320, 8);
	
	ExBltRect(77, count % 320, 0,  0, 28, 320 - (count % 320), 8);
	ExBltRect(77, 0, 0, 320 - (count % 320), 28, count % 320, 8);
	
	printFont(9, 2, "- SELECT REPLAY DATA -", 4);
	printFont(6, 3, "PRESS C BUTTON TO VIEW DETAIL", 5);
	
	// �����J�[�\�����s�[�h #1.60c7o6
	padRepeat2(0);
	
	// ��
	if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
	if(getPressState(0, 0)) {
		PlaySE(5);
		do {
			csr--;
			if(csr < 0) csr = 39;
		} while(enable[csr] == -1);
	}
	
	// ��
	if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
	if(getPressState(0, 1)) {
		PlaySE(5);
		do {
			csr++;
			if(csr > 39) csr = 0;
		} while(enable[csr] == -1);
	}

	// A�ŊJ�n
	if(getPushState(0, 4)) {
		PlaySE(10);
		flag = csr + 1;
	}

//	printFont(1, 5, "FILE   SCORE  LV LINES TIME     MODE", 2);
	ExBltRect(3,  48, 40, 154, 112, 26, 7);//SCORE�̕���
	ExBltRect(3,  95, 40, 180, 112, 26, 7);
	ExBltRect(3, 134, 40, 154, 119, 26, 7);
	ExBltRect(3, 180, 40, 180, 119, 26, 7);
	ExBltRect(3, 232, 40, 206, 119, 22, 7);//Mode

	for(i = 0; i < 40; i++) ExBltRect(3, 8 * i, (csr - (20 * (csr >= 20))) * 9 + 53, 20, 34, 8, 4);
	
	if(csr >= 20) {
		printFont(7, 29, "PAGE 2/2 (NO.21 - NO.40)", 7);
		start = 20;
		end = 40;
	} else {
		printFont(7, 29, "PAGE 1/2 (NO.01 - NO.20)", 7);
		start = 0;
		end = 20;
	}
	for(i = start; i < end; i++) {
		printSMALLFont(25, 48 + 9 * (i - 20 * (i >= 20)), string[10 + i], 0); // �ԍ��\���ɏ]���ύX #1.60c7i5
		if(enable[i] > -1){
			ExBltRect(86, 232, 48 + 9 * (i - 20 * (i >= 20)), 72 * enable[i + 40], enable[i] * 9, 72, 9);
		}
	}
	
	// C�ŏڍ�
	if(getPushState(0, 6)) {
		PlaySE(10);
		ReplayDetail(csr + 1);
	}
}

// ���v���C�ڍ� #1.60c7p5
void ReplayDetail(int number) {
	int i,k,sptemp[3];
	
	// ���v���C�f�[�^�ǂݍ���
	loadReplayData(0, number);
	
	while(1) {
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
		ExBltRect(77, 0, 232,  count % 320, 20, 320 - (count % 320), 8);
		ExBltRect(77, 320 - (count % 320), 232,  0, 20, count % 320, 8);
	
		ExBltRect(77, count % 320, 0,  0, 28, 320 - (count % 320), 8);
		ExBltRect(77, 0, 0, 320 - (count % 320), 28, count % 320, 8);
		// �ڍׂ�\��
		printFont(1, 1,  "REPLAY DETAIL", 5);
		
		/* ��{��� */
		printFont(1, 3,  "NUMBER      :", 0);
		sprintf(string[0],"%d",number);
		printFont(15, 3, string[0], 0);
		
		printFont(1, 4,  "GAME MODE   :", 0);
		if(gameMode[0] == 0) printFont(15, 4, "BEGINNER", 4);
		else if(gameMode[0] == 1) printFont(15, 4, "MASTER", 1);
		else if(gameMode[0] == 2) printFont(15, 4, "20G", 5);
		else if(gameMode[0] == 3) printFont(15, 4, "DEVIL", 2);
		else if(gameMode[0] == 4) printFont(15, 4, "VERSUS", 7);
		else if(gameMode[0] == 6) printFont(15, 4, "TOMOYO", 3);
		else if(gameMode[0] == 7) printFont(15, 4, "ACE", 0);
		else if(gameMode[0] == 8) printFont(15, 4, "MISSION", 8);
		else if(gameMode[0] == 9) printFont(15, 4, "SIMPLE", 9);
		else if(gameMode[0] == 10) printFont(15, 4, "ORIGINAL", 0);
		else printFont(15, 4, "INVALID MODE", 0);
		
		if(death_plus[0]) printFont(21, 4, "DEATH+", 2);
		if(devil_minus[0]) printFont(28-(7*(!death_plus[0])), 4, "MINUS", 2);
		if(item_mode[0]) printFont(22, 4, "ITEM MODE", 5);
		if(hebo_plus[0]) printFont(22, 4, "HEBO+", 9);
		if(examination[0]) printFont(22, 4, "EXAMINATION", 7);
		if(gameMode[0] == 7){
			if(anothermode[0] == 1) printFont(18, 4, " ANOTHER", 0);
			if(anothermode[0] == 2) printFont(18, 4, " HELL", 2);
			else printFont(18, 4, " OLD STYLE", 9);
		}
		if(gameMode[0] == 0){
			if(novice_mode[0]) printFont(24, 4, "SCORE TRIAL", 4);
			else printFont(24, 4, "TAMAYA TRIAL", 4);
		}
		if(gameMode[0] == 9){
			if(relaymode[0]){
				if(std_opt[0]==0)printFont(24, 4, "ROT.RELAY 40L", 9);
				else printFont(24, 4, "ROT.RELAY 2MIN", 9);
			}else{
				if(std_opt[0]==0) printFont(24, 4, "40LINES", 9);
				else if(std_opt[0]==1) printFont(24, 4, "ULTRA2MIN", 9);
				else if(std_opt[0]==2) printFont(24, 4, "SQUARE", 9);
				else printFont(24, 4, "MARATHON", 4);
			}
		}
		
		if(gameMode[0] != 4){
			printFont(1, 5,  "ROTATE RULE :", 0);
			if(rots[0] == 0) printFont(15, 5, "HEBORIS", fontc[0]);
			else if(rots[0] == 1) printFont(15, 5, "TI-ARS", fontc[1]);
			else if(rots[0] == 2) printFont(15, 5, "TI-WORLD", fontc[2]);
			else if(rots[0] == 3) printFont(15, 5, "ACE-SRS", fontc[3]);
			else if(rots[0] == 4) printFont(15, 5, "ACE-ARS", fontc[4]);
			else if(rots[0] == 5) printFont(15, 5, "ACE-ARS2", fontc[5]);
			else if(rots[0] == 6) printFont(15, 5, "DS-WORLD", fontc[6]);
			else if(rots[0] == 7) printFont(15, 5, "SRS-X", fontc[7]);
			else if(rots[0] == 8) printFont(15, 5, "D.R.S", fontc[8]);
		}
		
		/* �ݒ� */
		if((gameMode[0] != 4) && (gameMode[0] != 8) && (gameMode[0] != 9)){
			printFont(1, 6,  "LVUP RULE   :", 0);
			if((gameMode[0] <= 3) || (gameMode[0] == 6))
				printFont(15, 6, "BLOCK+ERASE", 0);
			else
				printFont(15, 6, "ERASE LINES", 0);
		}
		
		
		printFont(1, 8,  "8WAY INPUT  :", 0);
		if(nanameallow) printFont(15, 8, "e", 0);
		else printFont(15, 8, "c", 0);
		
		printFont(1, 9,  "SONIC DROP  :", 0);
		if(sonicdrop) printFont(15, 9, "e", 0);
		else printFont(15, 9, "c", 0);
		
		printFont(1, 10, "INIT LR MOVE:", 0);
		if(fastlrmove) printFont(15, 10, "e", 0);
		else printFont(15, 10, "c", 0);
		
		printFont(1, 11, "WORLDREVERSE:", 0);
		if(w_reverse) printFont(15, 11, "c", 0);
		else printFont(15, 11, "e", 0);
		
		printFont(1, 12, "DOWN RESET  :", 0);
		if(downtype) printFont(15, 12, "c", 0);
		else printFont(15, 12, "e", 0);
		
		printFont(1, 13, "LVUP BONUS  :", 0);
		if(lvupbonus==2) printFont(15, 13, "AUTO", 0);
		else if(lvupbonus==1) printFont(15, 13, "e", 0);
		else printFont(15, 13, "c", 0);
		
		/* �X�R�A�� */
		if(gameMode[0] == 6) {
			// TOMOYO
			printFont(1, 15, "STAGE       :", 0);
			sprintf(string[0],"%d",saveBuf[202]);
			printFont(15, 15, string[0], 0);
			
			printFont(1, 16, "START STAGE :", 0);
			sprintf(string[0],"%d",start_stage[0] + 1);
			printFont(15, 16, string[0], 0);
			
			printFont(1, 17, "START NEXTC :", 0);
			sprintf(string[0],"%d",start_nextc[0]);
			printFont(15, 17, string[0], 0);
			
			printFont(1, 18, "BORDER      :", 0);
			if(t_noborder[0]) printFont(15, 18, "e", 0);
			else printFont(15, 18, "c", 0);
			
			printFont(1, 19, "TRAINING    :", 0);
			if(t_training[0] == 2) printFont(15, 19, "B", 0);
			else if(t_training[0] == 1) printFont(15, 19, "A", 0);
			else printFont(15, 19, "e", 0);
			
			printFont(1, 20, "CLEAR STAGE :", 0);
			sprintf(string[0],"%d",saveBuf[219]);
			printFont(15, 20, string[0], 0);
			if(start_stage[0] <= 26){
				printFont(1, 21, "CLEAR PER.  :", 0);
				sprintf(string[0],"%d%%",saveBuf[220]);
				printFont(15, 21, string[0], 0);
			}
			
			printFont(1, 22, "RANDOM      :", 0);
			if(saveBuf[226]) printFont(15, 22, "c", 0);
			else printFont(15, 22, "e", 0);

			printFont(1, 23, "ENABLE SPEED:", 0);
			if((saveBuf[240]) || (repversw == 25)) printFont(15, 23, "c", 0);
			else printFont(15, 23, "e", 0);
		} else if(gameMode[0] == 4){
			//VERSUS
			printFont(1, 15,  "ROTATE RULE", 0);
			printFont(3, 16,  "1P :", 0);
			if(versus_rot[0] == 0) printFont(8, 16, "HEBORIS", fontc[0]);
			else if(versus_rot[0] == 1) printFont(8, 16, "TI-ARS", fontc[1]);
			else if(versus_rot[0] == 2) printFont(8, 16, "TI-WORLD", fontc[2]);
			else if(versus_rot[0] == 3) printFont(8, 16, "ACE-SRS", fontc[3]);
			else if(versus_rot[0] == 4) printFont(8, 16, "ACE-ARS", fontc[4]);
			else if(versus_rot[0] == 5) printFont(8, 16, "ACE-ARS2", fontc[5]);
			else if(versus_rot[0] == 6) printFont(8, 16, "DS-WORLD", fontc[6]);
			else if(versus_rot[0] == 7) printFont(8, 16, "SRS-X", fontc[7]);
			else if(versus_rot[0] == 8) printFont(8, 16, "D.R.S", fontc[8]);
			else printFont(8, 16, "RANDOM", 0);

			printFont(3, 17,  "2P :", 0);
			if(versus_rot[1] == 0) printFont(8, 17, "HEBORIS", fontc[0]);
			else if(versus_rot[1] == 1) printFont(8, 17, "TI-ARS", fontc[1]);
			else if(versus_rot[1] == 2) printFont(8, 17, "TI-WORLD", fontc[2]);
			else if(versus_rot[1] == 3) printFont(8, 17, "ACE-SRS", fontc[3]);
			else if(versus_rot[1] == 4) printFont(8, 17, "ACE-ARS", fontc[4]);
			else if(versus_rot[1] == 5) printFont(8, 17, "ACE-ARS2", fontc[5]);
			else if(versus_rot[1] == 6) printFont(8, 17, "DS-WORLD", fontc[6]);
			else if(versus_rot[1] == 7) printFont(8, 17, "SRS-X", fontc[7]);
			else if(versus_rot[1] == 8) printFont(8, 17, "D.R.S", fontc[8]);
			else printFont(8, 17, "RANDOM", 0);
			
			printFont(1, 18, "MODE        :", 0);
			if((disrise) && (noitem)) printFont(15, 18, "CEMENT", 0);
			else if((!disrise) && (noitem)) printFont(15, 18, "NO ITEM", 0);
			else if((disrise) && (!noitem)) printFont(15, 18, "ITEM ONLY", 0);
			else printFont(15, 18, "NORMAL", 0);
			
			printFont(1, 19, "GOAL TYPE   :", 0);
			if(vs_goal == 0) sprintf(string[0], "SURVIVAL", 0);
			else if(wintype == 0) sprintf(string[0], "LV %d", vs_goal);
			else if(wintype == 1) sprintf(string[0], "%d LINES", vs_goal / 10);
			else sprintf(string[0], "SURVIVAL", 0);
			printFont(15, 19, string[0], 0);
			
			if(!noitem){
				printFont(1, 21, "ITEMS", 0);
				
				printFont(3, 22, "1P :", 0);
				if(use_item[0] == 0) sprintf(string[0], "ALL", 0);
				else if(use_item[0] == item_num + 1) sprintf(string[0], "FEW", 0);
				else if(use_item[0] == item_num + 2) sprintf(string[0], "DS", 0);
				else if(use_item[0] == item_num + 3) sprintf(string[0], "TGM", 0);
				else sprintf(string[0], "%d", use_item[0]);
				printFont(8, 22, string[0], 0);
				
				printFont(3, 23, "2P :", 0);
				if(use_item[1] == 0) sprintf(string[0], "ALL", 0);
				else if(use_item[1] == item_num + 1) sprintf(string[0], "FEW", 0);
				else if(use_item[1] == item_num + 2) sprintf(string[0], "DS", 0);
				else if(use_item[1] == item_num + 3) sprintf(string[0], "TGM", 0);
				else sprintf(string[0], "%d", use_item[1]);
				printFont(8, 23, string[0], 0);
			}
		
		} else if((gameMode[0] != 8)&&(gameMode[0] != 9)) {
			// NORMAL
			if(gameMode[0] != 7) {
				printFont(1, 15, "SCORE       :", 0);
				sprintf(string[0],"%d",saveBuf[202]);
				printFont(15, 15, string[0], 0);
			}
			
			printFont(1, 16, "LEVEL       :", 0);
			sprintf(string[0],"%d",saveBuf[203]);
			printFont(15, 16, string[0], 0);
			
			printFont(1, 17, "LINES       :", 0);
			sprintf(string[0],"%d",saveBuf[204]);
			printFont(15, 17, string[0], 0);
			
			printFont(1, 18, "BIG         :", 0);
			if(IsBigStart[0]) printFont(15, 18, "c", 0);
			else printFont(15, 18, "e", 0);
			
			printFont(1, 19, "START LEVEL :", 0);
			sprintf(string[0],"%d",start[0]);
			printFont(15, 19, string[0], 0);
			
			printFont(1, 20, "RISE ON/OFF :", 0);
			if((p_shirase[0]) || ((devil_randrise) && (gameMode[0] == 3) && (!devil_minus))) printFont(15, 20, "c", 0);
			else printFont(15, 20, "e", 0);
			
			printFont(1, 21, "RISE START  :", 0);
			if((devil_randrise) && (gameMode[0] == 3) && (!devil_minus))
				sprintf(string[0],"500",1);
			else sprintf(string[0],"%d",level_shirase_start);
			printFont(15, 21, string[0], 0);
			
			printFont(1, 22, "RISE LINES  :", 0);
			sprintf(string[0],"%d",raise_shirase_lines);
			printFont(15, 22, string[0], 0);
			
			printFont(1, 23, "RISE INTER  :", 0);
			if((devil_randrise) && (gameMode[0] == 3) && (!devil_minus))
				sprintf(string[0],"RANDOM BY SECTION",1);
			else
				sprintf(string[0],"%d",raise_shirase_interval);
			printFont(15, 23, string[0], 0);
		} else if(gameMode[0] == 8){	// MISSION
			printFont(1, 15, "FILE NAME.  :", 0);
			if(mission_file == 0)
				sprintf(string[0], "BIG ROAD", 0);
			else if(mission_file == 1)
				sprintf(string[0], "TRICKY ROAD", 0);
			else if(mission_file == 2)
				sprintf(string[0], "GRAND ROAD", 0);
			else if(mission_file == 3)
				sprintf(string[0], "STAR ROAD", 0);
			else if(mission_file == 4)
				sprintf(string[0], "ANOTHER ROAD", 0);
			else if(mission_file == 5)
				sprintf(string[0], "DS ROAD", 0);
			else if(mission_file == 6)
				sprintf(string[0], "DEVIL ROAD", 0);
			else if(mission_file <= 16)
				sprintf(string[0], "TRIAL S%d", mission_file - 6);
			else if(mission_file == 17)
				sprintf(string[0], "TRIAL HM", 0);
			else if(mission_file == 18)
				sprintf(string[0], "TRIAL GOD", 0);
			else if(mission_file == 19)
				sprintf(string[0], "HEBO AMATEUR", 0);
			else if(mission_file == 20)
				sprintf(string[0], "HEBO PRO", 0);
			else if(mission_file == 21)
				sprintf(string[0], "HEBO BRONZE", 0);
			else if(mission_file == 22)
				sprintf(string[0], "HEBO SILVER ", 0);
			else if(mission_file == 23)
				sprintf(string[0], "HEBO GOLD", 0);
			else if(mission_file == 24)
				sprintf(string[0], "HEBO PLATINUM", 0);
			else
				sprintf(string[0], "NO.%02d", mission_file);
			printFont(15, 15, string[0], 0);
			
			printFont(1, 16, "START MISSION:", 0);
			sprintf(string[0],"%d",start_mission);
			printFont(15, 16, string[0], 0);
		}else if((gameMode[0] == 9) && (saveBuf[260] < 2)){	// STANDARD

			
			printFont(1, 16, "SPEED     :", 0);
			sprintf(string[0],"%d",saveBuf[261]);
			printFont(15, 16, string[0], 0);
			
			printFont(1, 17, "ARE       :", 0);
			
			printFont(1, 18, "LINE CLEAR:", 0);
			
			printFont(1, 19, "LOCK DELAY:", 0);
			
			printFont(1, 20, "DAS       :", 0);
			for(k = 0; k <= 3; k++) {
				sprintf(string[0],"%4d",(saveBuf[262] >> (k * 8)) & 0xff);
				printFont(15, 17+k, string[0], 0);
			}
			sprintf(string[0], "BGM       :%2d", saveBuf[266]);
			printFont(1, 22, string[0], 0);
		}
		/* �^�C���� */
		printFont(1, 25, "TIME        :", 0);
		getTime(saveBuf[200]);
		printFont(15, 25, string[0], 0);
		
		printFont(1, 26, "LENGTH      :", 0);
		sprintf(string[0],"%d",saveBuf[4] /2 + 1);
		printFont(15, 26, string[0], 0);
		
		/* �o�[�W���� */
		printFont(1, 28, "VERSION     :", 0);
		sprintf(string[0],"%d",repversw);
		printFont(15, 28, string[0], 0);
		
//		�i��
	if((gameMode[0] <= 2) && (gameMode[0] != 0)){
		printFont(20, 8, "GRADE TYPE :", 0);
		if(repversw < 19) printFont(32, 8, "N/A", 0);
		else if(enable_grade[0] == 0) printFont(33, 8, "NO USE", 0);
		else if(enable_grade[0] == 1) printFont(33, 8, "1", 0);
		else if(enable_grade[0] == 2) printFont(33, 8, "2+", 0);
		else if(enable_grade[0] == 3) printFont(33, 8, "2", 0);
		else if(enable_grade[0] == 4) printFont(33, 8, "3", 0);
	}
//		T-SPIN
		printFont(20, 9, "T-SPIN TYPE:", 0);
		if(repversw < 19) printFont(33, 9, "N/A", 0);
		else if(tspin_type == 0) printFont(32, 9, "NO CHECK", 0);
		else if(tspin_type == 1) printFont(33, 9, "SLIDE", 0);
		else if(tspin_type == 2) printFont(32, 9, "3-CORNER", 0);
		else if(tspin_type == 3) printFont(33, 9, "BOTH", 0);
		
		if(gameMode[0] != 4){
			printFont(20, 10, "NEXT NUM   :", 0);
			if(repversw < 22) printFont(33, 10, "N/A", 0);
			else if(((death_plus[0]) || (hebo_plus[0])) && (max_hnext[0] >= 1))
				printFont(33, 10, "1", 0);
			else{ 
				sprintf(string[0],"%d",max_hnext[0]);
				printFont(33, 10, string[0], 0);
			}
		}
		
		printFont(20, 11, "FRAME RATE :", 0);
		if(repversw < 25) printFont(33, 11, "N/A", 0);
		else{ 
			sprintf(string[0],"%2dFPS",saveBuf[239]);
			printFont(33, 11, string[0], 0);
		}
//		IRS
		if(disable_irs){
			printFont(20, 12, "IRS DISABLED", 0);
		}else{
			printFont(20, 12, "IRS STYLE  :", 0);
			if((repversw < 32) || (ace_irs == 0)) printFont(33, 12, "HEBORIS", 0);
			else if(ace_irs == 1) printFont(33, 12, "ACE", 0);
			else if(ace_irs == 2) printFont(33, 12, "ACE+", 0);
		}
		
//		Back to Back
		printFont(20, 13, "BACK TO BACK:", 0);
		if(b2bcheck) printFont(33, 13, "c", 0);
		else printFont(33, 13, "e", 0);
		
//		SPAWN Y TYPE
		printFont(20, 14, "SPAWN Y POS:", 0);
		if(spawn_y_type) printFont(33, 14, "21/22", 0);
		else printFont(33, 14, "19/20", 0);
		
		// AorB�Ŗ߂�
		KeyInput();
		
		if(getPushState(0, 4) || getPushState(0, 5)) {
			PlaySE(5);
			return;
		}
		if(IsPushEscKey()) restoreSetups();
		spriteTime();
	}
}
//������������������������������������������������������������������������������
//  ���v���C�f�[�^�����[�h�i�ۑ����j���[�p�j
//������������������������������������������������������������������������������
int loadReplayData2(int pl, int number) {
	int i, j, temp1, temp2, max,k,sptemp[3], tmpBuf[300];

	FillMemory(&tmpBuf, 300 * 4, 0);

	if(number <= 40)
		sprintf(string[0], "REPLAY/REPLAY%02d.SAV", number);
	else
		sprintf(string[0], "DEMO/DEMO%02d.SAV", number - 20);

	LoadFile(string[0], &tmpBuf, 1200);

	if(tmpBuf[0] != 0x4F424548) return (1);
	if(tmpBuf[1] != 0x20534952) return (1);
	if(tmpBuf[2] != 0x4C504552) return (1);
	if(tmpBuf[3] != 0x31765941) return (1);
//����
	repdata[0 + pl * 20] = tmpBuf[201];	// gameMode
	repdata[1 + pl * 20] = getModeAddRep2(tmpBuf);	// (modeAdd)
	repdata[2 + pl * 20] = tmpBuf[294];	// rots
	repdata[3 + pl * 20] = tmpBuf[256];	// repversw
	repdata[9 + pl * 20] = tmpBuf[297];	// BIG
	
//TOMOYO
	if(repdata[0 + pl * 20] == 6){
		repdata[4 + pl * 20] = tmpBuf[202];// stage
		repdata[5 + pl * 20] = tmpBuf[200];// time
//VERSUS
	}else if(repdata[0 + pl * 20] == 4){
		repdata[2 + pl * 20] = tmpBuf[218];// 1P_rots
		repdata[4 + pl * 20] = tmpBuf[219];// 2P_rots
		repdata[5 + pl * 20] = tmpBuf[228];// winpoint
		repdata[6 + pl * 20] = tmpBuf[200];// time
		repdata[9 + pl * 20] = 0;
//ACE
	}else if(repdata[0 + pl * 20] == 7){
		repdata[4 + pl * 20] = tmpBuf[203];// level
		repdata[5 + pl * 20] = tmpBuf[204];// lines
		repdata[6 + pl * 20] = tmpBuf[200];// time
//MISSION
	}else if(repdata[0 + pl * 20] == 8){
		repdata[4 + pl * 20] = tmpBuf[234];// mission_file
		repdata[5 + pl * 20] = tmpBuf[200];// time
//SIMPLE
	}else if(repdata[0 + pl * 20] == 9){
		repdata[4 + pl * 20] = tmpBuf[260];// std_opt
		repdata[5 + pl * 20] = tmpBuf[202];// score
		repdata[6 + pl * 20] = tmpBuf[204];// lines
		repdata[7 + pl * 20] = tmpBuf[200];// time
//�ʏ�
	}else{
		repdata[4 + pl * 20] = tmpBuf[203];// level
		repdata[5 + pl * 20] = tmpBuf[200];// time
		repdata[6 + pl * 20] = tmpBuf[202];// score
		repdata[7 + pl * 20] = tmpBuf[204];// lines
	}
	return (0);
}

int getModeAddRep2(int *tmpBuf){
	if(tmpBuf[201] == 0) return tmpBuf[259];
	else if((tmpBuf[201] == 1) || (tmpBuf[201] == 2)) return tmpBuf[232];
	else if(tmpBuf[201] == 3) return tmpBuf[254];
	else if(tmpBuf[201] == 6) return (tmpBuf[216] >= 27)+(tmpBuf[216] >= 45)+(tmpBuf[216] >= 69)+(tmpBuf[216] >= 100);
	else if(tmpBuf[201] == 7) return tmpBuf[225];
	else if(tmpBuf[201] == 9){
		if(tmpBuf[267]) return 4;
		else return tmpBuf[260];
	}else if(tmpBuf[201] == 10) return tmpBuf[296];
	else return 0;
}
