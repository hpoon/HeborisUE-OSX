//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.23 - MISSION���[�h �Z���N�g���
//������������������������������������������������������������������������������
void statMissionSelect(int player) {
	padRepeat(player);
	padRepeat2(player);
	if( (!IsPlayWave(62)) && (wavebgm >= 1) ) {
		PlayWave(62);
	}
	if(statc[player * 10 + 4] > 0){
		statc[player * 10 + 4]--;
		if(statc[player * 10 + 4] == 0) PlaySE(5);
	} else if(statc[player * 10 + 4] < 0){
		statc[player * 10 + 4]++;
		if(statc[player * 10 + 4] == 0) PlaySE(5);
	}
	
	printFont(15 + 24 * player - 12 * maxPlay, 5, "START!", (vslevel[0] <= 1) * count % 9);
	ExBltRect(77, 120 + 192 * player -96 * maxPlay , 52,  (count % 40) * 3, 28, 60, 8);
	
		printFont(15 + 24 * player - 12 * maxPlay, 10, "<        >", (vslevel[0] == 0) * count % 9);
		if(statc[player * 10 + 4] < 0){
			ExBltRect(55,128 + ((16+statc[player * 10 + 4]) * 4) + 192 * player -96 * maxPlay , 63, 
				(64*(rots[player]+1))*(rots[player]<8),32*(fontc[(rots[player]+1)*(rots[player]<8)]),
				(statc[player * 10 + 4]* -4),32);
			ExBltRect(55,128 + 192 * player -96 * maxPlay , 63, 
				(64*rots[player])+(statc[player * 10 + 4] * -4),32*fontc[rots[player]],((16+statc[player * 10 + 4])* 4),32);
		} else if(statc[player * 10 + 4] > 0){
			ExBltRect(55,128 + (statc[player * 10 + 4] * 4) + 192 * player -96 * maxPlay , 63, 
				(64*rots[player]),32*fontc[rots[player]],((16-statc[player * 10 + 4])* 4),32);
			ExBltRect(55,128 + 192 * player -96 * maxPlay , 63, 
				(64*(rots[player]-1))+576*(rots[player]==0)+((16-statc[player * 10 + 4]) * 4),
				32*fontc[rots[player]-1+(9*(rots[player]==0))],(statc[player * 10 + 4] * 4),32);
		} else ExBltRect(55,128 + 192 * player -96 * maxPlay , 63, 64*rots[player] ,32*fontc[rots[player]],64,32);
		ExBltRect(55,158 + 192 * player -96 * maxPlay , 40, (64*rots[player]) ,384,64,21);

//		ExBltRect(55,128 + 192 * player -96 * maxPlay , 55, 64*rots[player] ,32*fontc[rots[player]],64,32);
		if(!english)	//���������i���{��j
			ExBltRect(55,128 + 192 * player -96 * maxPlay , 96, 64*rots[player] ,320,64,32);
		else			//���������iEnglish�j
			ExBltRect(55,128 + 192 * player -96 * maxPlay , 96, 64*rots[player] ,352,64,32);
	printFont(15 + 24 * player - 12 * maxPlay, 16, "FILE", fontc[rots[player]]);

	getRoadName(mission_file);
	printFont(14 + 24 * player - 12 * maxPlay, 17, string[0], (vslevel[0] == 1) * count % 9 );

	printFont(15 + 24 * player - 12 * maxPlay, 19, "STAGE", fontc[rots[player]]);
	sprintf(string[0], "NO.%02d", c_mission);
	printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (vslevel[0] == 2) * count % 9 );
	
	if((mission_file >= 25) || (debug)){
		printFont(15 + 24 * player - 12 * maxPlay, 22, "LOAD", (vslevel[0] == 3) * count % 9);
		printFont(15 + 24 * player - 12 * maxPlay, 24, "SAVE", (vslevel[0] == 4) * count % 9);
	}else{
		ExBltRect(77, 120 + 192 * player -96 * maxPlay , 176,  160 - ((count % 40) * 3), 20, 80, 8);
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		vslevel[0]--;
		if(vslevel[0] < 0) vslevel[0] = 4 - (2 * ((mission_file < 25) && (!debug)));
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		vslevel[0]++;
		if(vslevel[0] > 4 - (2 * ((mission_file < 25) && (!debug)))) vslevel[0] = 0;
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		if(vslevel[0] == 0) {
			rots[player]--;
			if(rots[player] < 0) rots[player] = 8;
			statc[player * 10 + 4] = -16;
			setNextBlockColors(player, 1);
		}
		if(vslevel[0] == 1) {
			mission_file--;
			if(mission_file < 0) mission_file = 99;
			loadMissionData(mission_file);
		}
		if(vslevel[0] == 2) {
			c_mission--;
			if(c_mission < 0) c_mission = 29;
		}
		
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		if(vslevel[0] == 0) {
			rots[player]++;
			if(rots[player] > 8) rots[player] = 0;
			statc[player * 10 + 4] = 16;
			setNextBlockColors(player, 1);
		}
		if(vslevel[0] == 1) {
			mission_file++;
			if(mission_file > 99) mission_file = 0;
			loadMissionData(mission_file);
		}
		if(vslevel[0] == 2) {
			c_mission++;
			if(c_mission > 29) c_mission = 0;
		}
	}
	
	// B�{�^��
	if( getPushState(player, 5) ) {
		gameMode[0] = 0;
		vslevel[0] = 0;
		flag = 1;	// �^�C�g����
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		PlaySE(10);
		
		if(vslevel[0] <= 1) {
			// START!
			start_mission = c_mission;
			if(((mission_file == 6) || (mission_file == 18) || (mission_file == 24)) && (start_mission == 0)) PlaySE(18);
			StopAllBGM();
			//�w�i��ݒ�
			if(mission_type[c_mission] == 19)
				backno = 10;
			else if((mission_type[c_mission] == 20) || (mission_type[c_mission] == 22) || (mission_type[c_mission] == 29))
				backno = 11;
			else {
			backno = ((c_mission+1) % 10)-1;
			if(backno < 0)
				backno = 9;
			}
			if(backno >= bg_max) backno = bg_max;
			if(mission_bgm[c_mission] != -1)
				bgmlv = mission_bgm[c_mission];
			else fadelv[0] = 10;
			if(repversw < 54)missionSetStatus();
			stat[player] = 1;				// �u���b�N�V���b�^�[���s
			statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;		// �V���b�^�[��̓X�e�[�^�XNo.3
			statc[player * 10 + 4] = 0;
			return;
		}
		if((vslevel[0] == 2) && ((mission_file >= 25) || (debug))) {
			// EDIT
			StopAllBGM();
			statc[player * 10 + 4] = 0;
			stat[player] = 24;
		}
		if(vslevel[0] == 3) {
			// LOAD
			loadMissionData(mission_file);
		}
		if(vslevel[0] == 4) {
			// SAVE
			saveMissionData(mission_file);
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.24 - MISSION���[�h �G�f�B�b�g���
//������������������������������������������������������������������������������
void statMissionEditor(int player) {
	padRepeat(player);
	padRepeat2(player);
	
	// ���̎��
	printFont(15 + 24 * player - 12 * maxPlay, 5, "TYPE", fontc[rots[player]]);

	printFont(15 + 24 * player - 12 * maxPlay, 6, mission_name_editor[mission_type[c_mission]], (statc[0 + player * 10] == 0) * count % 9);

	// �m���}
	printFont(15 + 24 * player - 12 * maxPlay, 7, "NORM", fontc[rots[player]]);
	sprintf(string[0], "%d", mission_norm[c_mission]);
	printFont(15 + 24 * player - 12 * maxPlay, 8, string[0], (statc[0 + player * 10] == 1) * count % 9);
	
	// ��������
	printFont(15 + 24 * player - 12 * maxPlay, 9, "TIME", fontc[rots[player]]);
	getTime(mission_time[c_mission]);
	printFont(15 + 24 * player - 12 * maxPlay, 10, string[0], (statc[0 + player * 10] == 2) * count % 9);
	
	// ���x��
	printFont(15 + 24 * player - 12 * maxPlay, 11, "LEVEL", fontc[rots[player]]);
	if(mission_lv[c_mission] >= 15)
		sprintf(string[0], "PLUS %d", mission_lv[c_mission] + 1 - 15);
	else
		sprintf(string[0], "%d", mission_lv[c_mission] + 1);
	printFont(15 + 24 * player - 12 * maxPlay, 12, string[0], (statc[0 + player * 10] == 3) * count % 9);
	
	// �G���f�B���O
	printFont(15 + 24 * player - 12 * maxPlay, 13, "ENDING", fontc[rots[player]]);
	if(mission_end[c_mission] == 0) {
		sprintf(string[0], "NO");
	} else if(mission_end[c_mission] == 1) {
		sprintf(string[0], "END");
	} else if(mission_end[c_mission] == 2) {
		sprintf(string[0], "EXTRA");
	} else if(mission_end[c_mission] == 3) {
		sprintf(string[0], "EXTRA+");
	} else if(mission_end[c_mission] == 4) {
		sprintf(string[0], "STAFF ROLL");
	} else if(mission_end[c_mission] == 5) {
		sprintf(string[0], "M ROLL");
	} else if(mission_end[c_mission] == 6) {
		sprintf(string[0], "DEVIL+M ROLL");
	}
	printFont(15 + 24 * player - 12 * maxPlay, 14, string[0], (statc[0 + player * 10] == 4) * count % 9);
	
	// �������C����
	if(mission_erase[c_mission] < -20){
		printFont(15 + 24 * player - 12 * maxPlay, 15, "RISEE LINE", fontc[rots[player]]);
		sprintf(string[0], "%d", abs_YGS2K(mission_erase[c_mission]+20));
	}else if(mission_erase[c_mission] < 0){
		printFont(15 + 24 * player - 12 * maxPlay, 15, "RISEH LINE", fontc[rots[player]]);
		sprintf(string[0], "%d", abs_YGS2K(mission_erase[c_mission]));
	}else{
		printFont(15 + 24 * player - 12 * maxPlay, 15, "ERASE LINE", fontc[rots[player]]);
		sprintf(string[0], "%d", mission_erase[c_mission]);
	}
	printFont(15 + 24 * player - 12 * maxPlay, 16, string[0], (statc[0 + player * 10] == 5) * count % 9);
	// �ǉ����
	// 18�s��MAX 19�s��MIN 20�s��OPT(�^�[�Q�b�g���Ɖ��)�@21�s�ډ��
	printFont(15 + 24 * player - 12 * maxPlay, 17, "OPTIONS", fontc[rots[player]]);
	if((mission_type[c_mission] == 2)||(mission_type[c_mission] == 3)){
		sprintf(string[0], "GRADE:%d",mission_opt_1[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "0=N1=E2=H");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);

	}
	else if(mission_type[c_mission] == 6){   //�^�[�Q�b�g
		sprintf(string[0], "MINSTAGE:%d", mission_opt_1[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "MAXSTAGE:%d", mission_opt_2[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		if((statc[0 + player * 10] == 6) || (statc[0 + player * 10] == 7)){
			sprintf(string[0], "0-26=TI ");
			printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], 3);
			sprintf(string[0], "27-44=EH");
			printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], 3);
			sprintf(string[0], "45-71=ACE");
			printFont(15 + 24 * player - 12 * maxPlay, 22, string[0], 3);
			sprintf(string[0], "100-199=FP");
			printFont(15 + 24 * player - 12 * maxPlay, 23, string[0], 3);
		}else{
			if(!mission_opt_3[c_mission]){
				sprintf(string[0], "RANDTGT:OFF", 0);
			}else if(mission_opt_3[c_mission] == 99){
				sprintf(string[0], "RANDTGT:FULL", 0);
			}else{
				sprintf(string[0], "RANDTGT:%d", mission_opt_3[c_mission]);
			}
			printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
		}
	}
	else if((mission_type[c_mission] == 7)||(mission_type[c_mission] == 39)){   //�C���C���[
		sprintf(string[0], "MINLINE:%d", mission_opt_1[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "MAXLINE:%d", mission_opt_2[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "VIEWLINE:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "MAX:3");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "MIN:0");
		printFont(15 + 24 * player - 12 * maxPlay, 22, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	else if(mission_type[c_mission] == 10){  //�A�i�U�[
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "BLINDON:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "0:OFF 1:ON");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	else if(mission_type[c_mission] == 19){  //DEVIL 800
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "RISEPACE:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "MAX:20");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "MIN:1");
		printFont(15 + 24 * player - 12 * maxPlay, 22, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	else if(mission_type[c_mission] == 20){  //DEVIL 1200
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "SPEED:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "0:OLD");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "1:DOOM");
		printFont(15 + 24 * player - 12 * maxPlay, 22, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	else if(mission_type[c_mission] == 21){  //GARBAGE
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "RISELINE:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "MAX:18");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	else if(mission_type[c_mission] == 26){  //ALLCLEAR
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "NOBIG:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "0:OFF 1:ON");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	else if(mission_type[c_mission] == 27){  //COMBO
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "NOT1LINE:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		sprintf(string[0], "0:OFF 1:ON");
		printFont(15 + 24 * player - 12 * maxPlay, 21, string[0], (statc[0 + player * 10] == 8) * count % 9);	
	}
	else if((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)||(mission_type[c_mission] == 38)){
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "HOLD USE:%d",mission_opt_2[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "BLOCK:%d", mission_opt_3[c_mission]);
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
		printFont(15 + 24 * player - 12 * maxPlay, 21, "(0-8)", (statc[0 + player * 10] == 8) * count % 9);
	}
	// ���̑�
	else {
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 18, string[0], (statc[0 + player * 10] == 6) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 19, string[0], (statc[0 + player * 10] == 7) * count % 9);
		sprintf(string[0], "NO OPTION");
		printFont(15 + 24 * player - 12 * maxPlay, 20, string[0], (statc[0 + player * 10] == 8) * count % 9);
	}
	printFont(15 + 24 * player - 12 * maxPlay, 24, "BGM", fontc[rots[player]]);
	if(mission_bgm[c_mission] == -1)
		sprintf(string[0], "FADE", mission_bgm[c_mission]);
	else
		sprintf(string[0], "%d", mission_bgm[c_mission]);	
	printFont(19 + 24 * player - 12 * maxPlay, 24, string[0], (statc[0 + player * 10] == 9) * count % 9);

	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[0 + player * 10]--;
		if(statc[0 + player * 10] < 0) statc[0 + player * 10] = 9;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[0 + player * 10]++;
		if(statc[0 + player * 10] > 9) statc[0 + player * 10] = 0;
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// TYPE
		if(statc[0 + player * 10] == 0) {
			mission_type[c_mission]--;
			if(mission_type[c_mission] < 0) mission_type[c_mission] = 41;
		}
		// NORM
		if(statc[0 + player * 10] == 1) {
			mission_norm[c_mission]--;
			if(mission_norm[c_mission] < 0) mission_norm[c_mission] = 99;
		}
		// TIME
		if(statc[0 + player * 10] == 2) {
			mission_time[c_mission] = mission_time[c_mission] - 60;
			if(mission_time[c_mission] < 0) mission_time[c_mission] = 60 * 60 * 20;
		}
		// LEVEL
		if(statc[0 + player * 10] == 3) {
			mission_lv[c_mission]--;
			if(mission_lv[c_mission] < 0) mission_lv[c_mission] = 29;
		}
		// ENDING
		if(statc[0 + player * 10] == 4) {
			mission_end[c_mission]--;
			if(mission_end[c_mission] < 0) mission_end[c_mission] = 6;
		}
		// ERASE LINE
		if(statc[0 + player * 10] == 5) {
			mission_erase[c_mission]--;
			if(mission_erase[c_mission] < -40) mission_erase[c_mission] = 21;
		}
		// OPTIONS
		if(statc[0 + player * 10] == 6) {
			mission_opt_1[c_mission]--;
			if(mission_opt_1[c_mission] < 0) mission_opt_1[c_mission] = 199;
		}
		if(statc[0 + player * 10] == 7) {
			mission_opt_2[c_mission]--;
			if(mission_opt_2[c_mission] < 0) mission_opt_2[c_mission] = 199;
		}
		if(statc[0 + player * 10] == 8) {
			mission_opt_3[c_mission]--;
			if(mission_opt_3[c_mission] < 0) mission_opt_3[c_mission] = 99;
		}
		if(statc[0 + player * 10] == 9) {
			mission_bgm[c_mission]--;
			if(mission_bgm[c_mission] < -1) mission_bgm[c_mission] = 19;
		}
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || (getPressState(player, 6)))
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// TYPE
		if(statc[0 + player * 10] == 0) {
			mission_type[c_mission]++;
			if(mission_type[c_mission] > 41) mission_type[c_mission] = 0;
		}
		// NORM
		if(statc[0 + player * 10] == 1) {
			mission_norm[c_mission]++;
			if(mission_norm[c_mission] > 99) mission_norm[c_mission] = 0;
		}
		// TIME
		if(statc[0 + player * 10] == 2) {
			mission_time[c_mission] = mission_time[c_mission] + 60;
			if(mission_time[c_mission] > 60 * 60 * 20) mission_time[c_mission] = 0;
		}
		// LEVEL
		if(statc[0 + player * 10] == 3) {
			mission_lv[c_mission]++;
			if(mission_lv[c_mission] > 29) mission_lv[c_mission] = 0;
		}
		// ENDING
		if(statc[0 + player * 10] == 4) {
			mission_end[c_mission]++;
			if(mission_end[c_mission] > 6) mission_end[c_mission] = 0;
		}
		// ERASE LINE
		if(statc[0 + player * 10] == 5) {
			mission_erase[c_mission]++;
			if(mission_erase[c_mission] > 21) mission_erase[c_mission] = -40;
		}
		// OPTIONS
		if(statc[0 + player * 10] == 6) {
			mission_opt_1[c_mission]++;
			if(mission_opt_1[c_mission] > 199) mission_opt_1[c_mission] = 0;
		}
		if(statc[0 + player * 10] == 7) {
			mission_opt_2[c_mission]++;
			if(mission_opt_2[c_mission] > 199) mission_opt_2[c_mission] = 0;
		}
		if(statc[0 + player * 10] == 8) {
			mission_opt_3[c_mission]++;
			if(mission_opt_3[c_mission] > 99) mission_opt_3[c_mission] = 0;
		}
		if(statc[0 + player * 10] == 9) {
			mission_bgm[c_mission]++;
			if(mission_bgm[c_mission] > 19) mission_bgm[c_mission] = -1;
		}
	}
	
	// A�܂���B�{�^��
	if( getPushState(player, 4) || getPushState(player, 5) ) {
		stat[player] = 23;	// �Z���N�g��ʂɖ߂�
		statc[0 + player * 10] = 0;
	}
}

//������������������������������������������������������������������������������
//  ���̕\��
//������������������������������������������������������������������������������
void viewMission() {
	int i,tmp,minus,c_tmp,c_tmp1,c_tmp2;
	tmp = 0;
	minus = 0;
	
	// BltFastRect(�v���[���i���o�[,dx,dy,sx,sy,hx,hy);
	
	// �g
	if(getDrawRate() == 1) {
		if(mission_file <= 24) BltFastRect(44, maxPlay * 208, 12, 160, (20 * mission_file) + (10 * (english)), 80, 10);
		BltFastRect(44, 208 * maxPlay, 112, 288, 368, 112, 128);
	} else {
		if(mission_file <= 24) BltFastRect(44, 8 + maxPlay * 408, 24, 32, (32 * mission_file) + (16 * (english)), 128, 16);
		BltFastRect(44, 16 + maxPlay * 400, 224, 448, 288, 192, 192);
	}
	
	// ���̎��
	if((ending[0] <= 1) || (ending[0] >= 4)){
	if(getDrawRate() == 1) {
		TextLayerOn(0, 6 + 208 * maxPlay, 8 + 112);
		TextSize(0, 10);
	} else {
		TextLayerOn(0, 10 + 16 + maxPlay * 400, 8 + 228);
		TextSize(0, 16);
	}
	TextColor(0, 0, 0, 0);
	TextBackColorDisable(0);
	
	getMissionName(mission_type[c_mission],c_mission);
	
	// �������x���x��
	if((mission_type[c_mission] != 19) && (mission_type[c_mission] != 20) && (mission_type[c_mission] != 29)){
		sprintf(string[70], " LV%02d", mission_lv[c_mission] + 1 - 15 * (mission_lv[c_mission] >= 15));
		strcat(string[0], string[70]);
	}else if(mission_type[c_mission] == 20){
		if(!mission_opt_3[c_mission])
			strcat(string[0]," OLD");
		else
			strcat(string[0], " REAL");
	}
	
	// �`��
	TextOut(0, string[0]);
	TextBlt(0);
	
	// ��������
	if(getDrawRate() == 1) {
		TextMove(0, 6 + 208 * maxPlay, 30 + 112);
	} else {
		TextMove(0, 10 + 16 + maxPlay * 400, 30 + 228);
	}
	
	if(!english) strcpy(string[70], "�������� ");
	else strcpy(string[70], "Time ");
	
	getTime(mission_time[c_mission]);
	if(mission_time[c_mission]>0){
	strcat(string[70], string[0]);
	}else{
		if(!english) strcat(string[70], "������");
		else strcat(string[70], "NoLimit");
	}
	
	// �`��
	TextOut(0, string[70]);
	TextBlt(0);
	
	// �w�ߕ�
	if(getDrawRate() == 1) {
		TextMove(0, 6 + 208 * maxPlay, 52 + 112);
	} else {
		TextMove(0, 10 + 16 + maxPlay * 400, 52 + 228);
	}
	// LITE�ł��Q�l�ɐ���
	if(!english) {//"\n\n���g����\n%d���C�������I",
		sprintf(string[0], mission_info_jp[mission_type[c_mission]], mission_norm[c_mission]);
		if(((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)||(mission_type[c_mission] == 38))&&(mission_opt_2[c_mission]==1))strcat(string[0], "\n\n�����O�ɂ��̃u���b�N\n����x�z�[���h�ɓ����");
		if(((mission_type[c_mission] == 2) || (mission_type[c_mission] == 3))&&(mission_opt_1[c_mission]==1))strcat(string[0], "\n\n�w��ȏ�ł��J�E���g!");
		if(((mission_type[c_mission] == 2) || (mission_type[c_mission] == 3))&&(mission_opt_1[c_mission]==2))strcat(string[0], "\n\n�w��ȊO��\n�m���}���Z�b�g!");
		if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3))strcat(string[0], "\n\n�Ō�̃��C����\n�_�u���ŏ����I");
	} else {
		sprintf(string[0], mission_info_en[mission_type[c_mission]], mission_norm[c_mission]);
		if(((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)||(mission_type[c_mission] == 38))&&(mission_opt_2[c_mission]==1))strcat(string[0], "\n\nBefore Erase \ninto HOLD");
		if(((mission_type[c_mission] == 2) || (mission_type[c_mission] == 3))&&(mission_opt_1[c_mission]==1))strcat(string[0], "\n\nErase over lines count");
		if(((mission_type[c_mission] == 2) || (mission_type[c_mission] == 3))&&(mission_opt_1[c_mission]==2))strcat(string[0], "\n\nDo not erase\n other lines!");
		if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3))strcat(string[0], "\n\nlast erase 2 lines");
		
	}
	
	//�u���b�N�I�[�_�[�n�̃u���b�N�̊G
	if((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)||(mission_type[c_mission] == 38)){
		if(mission_opt_3[c_mission]<=6){
			if( isWRule(0) ) {
				// ���[���h
				c_tmp = wcol[mission_opt_3[c_mission]];
			} else if( (rots[0] >= 4 ) && (rots[0] != 8)) {
				// ARS
				c_tmp = acol[mission_opt_3[c_mission]];
			} else {
				// �N���V�b�N
				c_tmp = ccol[mission_opt_3[c_mission]];
			}
			//7JL 8SZ
			if ( getDrawRate() == 1 ){
				if(!english){
					drawBlockFast(2 + 25 * maxPlay, 20 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), mission_opt_3[c_mission], 0, c_tmp, 0, -1, 0, 0 ,0);
				}else{
					drawBlockFast(3 - (mission_type[c_mission] == 33) + 25 * maxPlay, 21 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), mission_opt_3[c_mission], 0, c_tmp, 0, 1, 0, 0, 0);
				}
			}else{
				if(!english){
					drawBlockFast(2 + 25 * maxPlay, 16 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), mission_opt_3[c_mission], 0, c_tmp, 0, 2, 0, 0, 0);
				}else{
					drawBlockFast(3 - (mission_type[c_mission] == 33) + 25 * maxPlay, 17 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), mission_opt_3[c_mission], 0, c_tmp, 0, 4, 0, 0, 0);
				}
			}
		}else if(mission_opt_3[c_mission]==7){//LJ
			if( isWRule(0) ) {
				// ���[���h
				c_tmp1 = wcol[1];
				c_tmp2 = wcol[5];
			} else if( (rots[0] >= 4 ) && (rots[0] != 8)) {
				// ARS
				c_tmp1 = acol[1];
				c_tmp2 = acol[5];
			} else {
				// �N���V�b�N
				c_tmp1 = ccol[1];
				c_tmp2 = ccol[5];
			}
			//7JL 8SZ
			if ( getDrawRate() == 1 ){
				if(!english){
					drawBlockFast(2 + 25 * maxPlay, 20 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 1, 0, c_tmp1, 0, -1, 0, 0, 0);
					drawBlockFast(6 + 25 * maxPlay, 20 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 5, 0, c_tmp2, 0, -1, 0, 0, 0);
				}else{
					drawBlockFast(3 - (mission_type[c_mission] == 33) + 25 * maxPlay, 21 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)),1, 0, c_tmp1, 0, 1, 0, 0, 0);
					drawBlockFast(7 - (mission_type[c_mission] == 33) + 25 * maxPlay, 21 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)),5, 0, c_tmp2, 0, 1, 0, 0, 0);
				}
			}else{
				if(!english){
					drawBlockFast(2 + 25 * maxPlay, 16 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 1, 0, c_tmp1, 0, 2, 0, 0, 0);
					drawBlockFast(6 + 25 * maxPlay, 16 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 5, 0, c_tmp2, 0, 2, 0, 0, 0);
				}else{
					drawBlockFast(3 - (mission_type[c_mission] == 33) + 25 * maxPlay, 17 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 1, 0, c_tmp1, 0, 4, 0, 0, 0);
					drawBlockFast(7 - (mission_type[c_mission] == 33) + 25 * maxPlay, 17 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 5, 0, c_tmp2, 0, 4, 0, 0, 0);
				}
			}
		}else if(mission_opt_3[c_mission]==8){//SZ
			if( isWRule(0) ) {
				// ���[���h
				c_tmp1 = wcol[3];
				c_tmp2 = wcol[6];
			} else if( (rots[0] >= 4 ) && (rots[0] != 8)) {
				// ARS
				c_tmp1 = acol[3];
				c_tmp2 = acol[6];
			} else {
				// �N���V�b�N
				c_tmp1 = ccol[3];
				c_tmp2 = ccol[6];
			}
			//7JL 8SZ
			if ( getDrawRate() == 1 ){
				if(!english){
					drawBlockFast(2 + 25 * maxPlay, 20 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 3, 0, c_tmp1, 0, -1, 0, 0, 0);
					drawBlockFast(6 + 25 * maxPlay, 20 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 6, 0, c_tmp2, 0, -1, 0, 0, 0);
				}else{
					drawBlockFast(3 - (mission_type[c_mission] == 33) + 25 * maxPlay, 21 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 3, 0, c_tmp1, 0, 1, 0, 0, 0);
					drawBlockFast(7 - (mission_type[c_mission] == 33) + 25 * maxPlay, 21 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 6, 0, c_tmp2, 0, 1, 0, 0, 0);
				}
			}else{
				if(!english){
					drawBlockFast(2 + 25 * maxPlay, 16 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 3, 0, c_tmp1, 0, 2, 0, 0, 0);
					drawBlockFast(6 + 25 * maxPlay, 16 + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 6, 0, c_tmp2, 0, 2, 0, 0, 0);
				}else{
					drawBlockFast(3 - (mission_type[c_mission] == 33) + 25 * maxPlay, 17 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 3, 0, c_tmp1, 0, 4, 0, 0, 0);
					drawBlockFast(7 - (mission_type[c_mission] == 33) + 25 * maxPlay, 17 + (mission_type[c_mission] >= 31) + 
					(mission_type[c_mission] == 33) + isWRule(0) * (mission_opt_3[c_mission] != 0) + 
					((mission_opt_3[c_mission] == 0) && (rots[0] != 8)), 6, 0, c_tmp2, 0, 4, 0, 0, 0);
				}
			}
		}
	}
	
	// �`��
	TextOut(0, string[0]);
	TextBlt(0);
	
	// �g�p�I��
	TextLayerOff(0);
	while(c_mission - tmp > 4){
		tmp = tmp + 5;
	}
	
	// �~�b�V�����ꗗ
	for(i = tmp; i < (tmp+5); i++) {
		if(getDrawRate() == 1) {
			BltFastRect(44, 208 * maxPlay, 32 + (i-tmp) * 16, 288, 304 + (((c_mission == i) && (ending[0] == 0)) * 16) + ((c_mission > i) || (ending[0] != 0)) * 32, 112, 13);
			TextLayerOn(0, 1 + 208 * maxPlay, 1 + 32 + (i-tmp) * 16);
			TextSize(0, 10);
		} else {
			BltFastRect(44, 16 + maxPlay * 400, 64 + (i-tmp) * 32, 448, 224 + (((c_mission == i) && (ending[0] == 0)) * 16) + ((c_mission > i) || (ending[0] != 0)) * 32, 160, 16);
			TextLayerOn(0, 1 + 16 + maxPlay * 400, 1 + 64 + (i-tmp) * 32);
			TextSize(0, 14);
		}
		TextColor(0, 0, 0, 0);
		TextBackColorDisable(0);
		
		getMissionName(mission_type[i],i);
		
		// �`��
		TextOut(0, string[0]);
		TextBlt(0);
		
		// �g�p�I��
		TextLayerOff(0);
		
		// �I���t���O������ꍇ�͂����Ń��[�v�𔲂���
		if(mission_end[i]) break;
	}
	}	//if(!ending[0])
}

// �~�b�V���������擾
void getMissionName(int mtype,int number) {
	if(!english) {
		strcpy(string[0], mission_name_jp[mtype]);
	} else {
		strcpy(string[0], mission_name_en[mtype]);
	}
	if(mission_lv[number] >= 15)
		strcat(string[0],"+");
}
// ���[�h�����擾
void getRoadName(int no){
	if(no == 0)
		sprintf(string[0], " BIG ROAD", 0);
	else if(no == 1)
		sprintf(string[0], " TRICKY ROAD", 0);
	else if(no == 2)
		sprintf(string[0], " GRAND ROAD", 0);
	else if(no == 3)
		sprintf(string[0], " STAR ROAD", 0);
	else if(no == 4)
		sprintf(string[0], "ANOTHER ROAD", 0);
	else if(no == 5)
		sprintf(string[0], " DS ROAD", 0);
	else if(no == 6)
		sprintf(string[0], " DEVIL ROAD", 0);
	else if(no <= 16)
		sprintf(string[0], " TRIAL S%d", no - 6);
	else if(no == 17)
		sprintf(string[0], " TRIAL HM", 0);
	else if(no == 18)
		sprintf(string[0], " TRIAL GOD", 0);
	else if(no == 19)
		sprintf(string[0], "HEBO AMATEUR", 0);
	else if(no == 20)
		sprintf(string[0], " HEBO PRO", 0);
	else if(no == 21)
		sprintf(string[0], " HEBO BRONZE", 0);
	else if(no == 22)
		sprintf(string[0], " HEBO SILVER ", 0);
	else if(no == 23)
		sprintf(string[0], " HEBO GOLD", 0);
	else if(no == 24)
		sprintf(string[0], "HEBO PLATINUM", 0);
	else 
		sprintf(string[0], " NO.%02d", no);
}
/* �~�b�V�������[�h�̃m���}�㏸ */
void missionNormUp(int lines) {
	int i, j,gap;
	int by2, tmp;
	
	// ���x���X�^�[�n��i�r�b�O�HS1&2��A�i�U�[�X-RAY��J���[�E���[�����[���E�~���[�j
	if( (mission_type[c_mission] == 0) || (mission_type[c_mission] == 1) || (mission_type[c_mission] == 8) ||
		(mission_type[c_mission] == 9) || (mission_type[c_mission] == 10) ||
		(mission_type[c_mission] == 12) || (mission_type[c_mission] == 13) || (mission_type[c_mission] == 14) ||
		(mission_type[c_mission] == 15) || (mission_type[c_mission] == 17) || (mission_type[c_mission] == 18) ||
		(mission_type[c_mission] == 19) || (mission_type[c_mission] == 20) || (mission_type[c_mission] == 21) ||
		(mission_type[c_mission] == 22) || (mission_type[c_mission] == 24) || (mission_type[c_mission] == 25))
	{
		c_norm[0] = c_norm[0] + lines;
	}
	
	// �_�u��
	if( mission_type[c_mission] == 2 ) {
		if(mission_opt_1[c_mission] == 1){
			if(lines >= 2) c_norm[0]++;//�_�u���ȏ���F�߂�
		}else if(mission_opt_1[c_mission] == 2){
			if(lines == 2)c_norm[0]++;
			else if(c_norm[0] > 0){
			c_norm[0] = 0;
			PlaySE(45);
			}
		}
		else if(lines == 2) c_norm[0]++;
	}
	
	// �g���v��
	if( mission_type[c_mission] == 3 ) {
		if(mission_opt_1[c_mission] == 1){
			if(lines >= 3) c_norm[0]++;//�g���v���ȏ���F�߂�
		}else if(mission_opt_1[c_mission] == 2){
			if(lines == 3)c_norm[0]++;
			else if(c_norm[0] > 0){
			c_norm[0] = 0;
			PlaySE(45);
			}
		}
		else if(lines == 3) c_norm[0]++;
	}
	
	// �w�{���X
	if( mission_type[c_mission] == 4 ) {
		if(lines == 4) c_norm[0]++;
	}
	
	// �T�C�N��
	if( mission_type[c_mission] == 5 ) {
		if(!cycle[lines - 1]) {
			cycle[lines - 1] = 1;
			c_norm[0]++;
		}
	}
	
	// �^�[�Q�b�g
	if( mission_type[c_mission] == 6 ) {
		// �v���`�i�u���b�N��0
		if(getPlatinumBlock(0) == 0) {
			PlaySE(31);
			c_norm[0]++;
			
			// ���̃X�e�[�W��
			if(c_norm[0] < mission_norm[c_mission]) {
				upLineNo[0] = 0;
				upLines[0] = 0;
				timeOn[0] = 0;
				
				for(i = 0; i < 22; i++) erase[i] = 1;
				
				stat[0] = 25;	// �S���C������
				statc[0 * 10 + 0] = wait1[0];	//�҂����ԃX�L�b�v
				statc[0 * 10 + 1] = 3;	// Ready
				statc[0 * 10 + 2] = 1;	// �X�e�[�W�ǂݍ��݂���
			}
		}
	}
	
	// �C���C�T�[
	if( (mission_type[c_mission] == 7 )||(mission_type[c_mission] == 39)) {
		if((lines >= 4)||(mission_type[c_mission] != 39)){
			for(i = 0; i < 4; i++) {
				// ���ׂ�Y���W�����߂�
				if(rots[0] == 8){
					by2 = (by[0] + blkDDataY[blk[0] * 16 + rt[0] * 4 + i]);
				} else if( isWRule(0) ) {
					by2 = (by[0] + blkWDataY[blk[0] * 16 + rt[0] * 4 + i]);
				} else {
					by2 = (by[0] + blkDataY[blk[0] * 16 + rt[0] * 4 + i]);
				}
				
				// �����ׂ����C�������ׂ�
				for(j = 0; j < eraser_now_lines; j++) {
					if(j >= 4) break;
					
					if( (by2 == eraser_lines[j]) && (erase[by2]) && (!eraser_cleared[j]) ) {
						eraser_cleared[j] = 1;
						c_norm[0]++;
					}
				}
			}
			
			// �S�������Ă���̂Ƀm���}�B�����Ă��Ȃ��ꍇ�͐V���ȃp�^�[���o��
			if(c_norm[0] < mission_norm[c_mission]) {
				tmp = 1;
				
				for(i = 0; i < eraser_now_lines; i++) {
					if(i >= 4) break;
					
					if(!eraser_cleared[i]) {
						tmp = 0;
						break;
					}
				}
				
				if(tmp) {
					eraser_now_pattern++;
					setEraserLines();
				}
			}
		}
	}
	
	// �V���O��
	if( mission_type[c_mission] == 11 ) {
		if(lines == 1) c_norm[0]++;
	}
	
	// T-spin
	if( mission_type[c_mission] == 16 ) {
		if(tspin_flag[0] != 0) c_norm[0]++;
	}
	
	//�ϋv
	if((ltime[0] <= 0) && (mission_type[c_mission] == 23))
		c_norm[0] = mission_norm[c_mission];
	
	// �S����
	if( mission_type[c_mission] == 26 ) {
		c_norm[0]++;
	}
	//�R���{
	if( mission_type[c_mission] == 27 ) {
		if(mission_opt_3[c_mission] == 1) c_norm[0] = combo2[0];
		else c_norm[0] = combo[0];
	}
	// B to B�w�{���X
	if( mission_type[c_mission] == 28 ) {
		if(lines == 4) c_norm[0]++;
		else if(c_norm[0] > 0){
			c_norm[0] = 0;
			gflash[0] = 120;
			gup_down[0] = 0;//regret
			PlaySE(45);
		}
	}
	
	// OOBAKA
	if( (mission_type[c_mission] == 29) && (stat[0] == 6) && ((timeOn[0]) || (repversw < 58)) ) {
		c_norm[0]++;
	}
	
	// �u���b�N�I�[�_�[
	if( mission_type[c_mission] == 30 ) { 
		if( (mission_opt_2[c_mission] == 0) || 
		    ((mission_opt_2[c_mission] == 1) && (dhold2[0]) && (hold_used[0] >= 2)) ){
			if((mission_opt_3[c_mission]>=0)&&(mission_opt_3[c_mission]<=6)){//�P�i
				if(blk[0] == mission_opt_3[c_mission]) c_norm[0] = c_norm[0] + lines;
			}else if(mission_opt_3[c_mission]==7){//LJ
				if((blk[0] == 1)||(blk[0] == 5)) c_norm[0] = c_norm[0] + lines;
			}else if(mission_opt_3[c_mission]==8){//SZ
				if((blk[0] == 3)||(blk[0] == 6)) c_norm[0] = c_norm[0] + lines;
			}
		}
	}
	
	// �u���b�N�I�[�_�[�V���O��SP
	if( mission_type[c_mission] == 31 ) {//0-6
		if( (mission_opt_2[c_mission] == 0) || 
		    ((mission_opt_2[c_mission] == 1) && (dhold2[0]) && (hold_used[0] >= 2)) ){
			if((mission_opt_3[c_mission]>=0)&&(mission_opt_3[c_mission]<=6)){//�P�i
				if((lines == 1) && (blk[0] == mission_opt_3[c_mission])) c_norm[0]++;
			}else if(mission_opt_3[c_mission]==7){//LJ
				if((lines == 1) && ((blk[0] == 1)||(blk[0] == 5))) c_norm[0]++;
			}else if(mission_opt_3[c_mission]==8){//SZ
				if((lines == 1) && ((blk[0] == 3)||(blk[0] == 6))) c_norm[0]++;
			}
		}
	}
	// �_�u���I�[�_�[
	if( mission_type[c_mission] == 32 ) {//0-6
		if( (mission_opt_2[c_mission] == 0) || 
		((mission_opt_2[c_mission] == 1) && (dhold2[0]) && (hold_used[0] >= 2)) ){
			if(mission_opt_1[c_mission]){
				if((mission_opt_3[c_mission]>=0)&&(mission_opt_3[c_mission]<=6)){//�P�i
					if((lines >= 2) && (blk[0] == mission_opt_3[c_mission])) c_norm[0]++;
				}else if(mission_opt_3[c_mission]==7){//LJ
					if((lines >= 2) && ((blk[0] == 1)||(blk[0] == 5))) c_norm[0]++;
				}else if(mission_opt_3[c_mission]==8){//SZ
					if((lines >= 2) && ((blk[0] == 3)||(blk[0] == 6))) c_norm[0]++;
				}
			}else{
				if((mission_opt_3[c_mission]>=0)&&(mission_opt_3[c_mission]<=6)){//�P�i
					if((lines == 2) && (blk[0] == mission_opt_3[c_mission])) c_norm[0]++;
				}else if(mission_opt_3[c_mission]==7){//LJ
					if((lines == 2) && ((blk[0] == 1)||(blk[0] == 5))) c_norm[0]++;
				}else if(mission_opt_3[c_mission]==8){//SZ
					if((lines == 2) && ((blk[0] == 3)||(blk[0] == 6))) c_norm[0]++;
				}
			}
		}
	}
	// ���g���v��SP
	if( mission_type[c_mission] == 33 ) {
		if( (mission_opt_2[c_mission] == 0) || 
		    ((mission_opt_2[c_mission] == 1) && (dhold2[0]) && (hold_used[0] >= 2)) ){
			if((mission_opt_3[c_mission]>=0)&&(mission_opt_3[c_mission]<=6)){//�P�i
				if((lines == 3) && (blk[0] != mission_opt_3[c_mission])) c_norm[0]++;
			}else if(mission_opt_3[c_mission]==7){//LJ
				if((lines == 3) && ((blk[0] != 1)||(blk[0] != 5))) c_norm[0]++;
			}else if(mission_opt_3[c_mission]==8){//SZ
				if((lines == 3) && ((blk[0] != 3)||(blk[0] != 6))) c_norm[0]++;
			}
		}
	}

	// �������_�u��
	if( mission_type[c_mission] == 34 ) {
		if(lines == 2){
			gap=0;	// ����������
			j=0;	// ����������t���O
			for(i=0;i<22;i++){
				if(erase[i])
					j++;
				else if(j!=0)
					gap++;
				if(j>=lines) break;
			}
			if(gap != 0) c_norm[0]++;
		}
	}
	
	// �������g���v��
	if( mission_type[c_mission] == 35 ) {
		if(lines == 3){
			gap=0;	// ����������
			j=0;	// ����������t���O
			for(i=0;i<22;i++){
				if(erase[i])
					j++;
				else if(j!=0)
					gap++;
				if(j>=lines) break;
			}
			if(gap != 0) c_norm[0]++;
		}
	}
	
	// 2�i�����_�u��
	if( mission_type[c_mission] == 36 ) {
		if(lines == 2){
			gap=0;	// ����������
			j=0;	// ����������t���O
			for(i=0;i<22;i++){
				if(erase[i])
					j++;
				else if(j!=0)
					gap++;
				if(j>=lines) break;
			}
			if(gap == 2) c_norm[0]++;
		}
	}
	
	// TSD
	if( mission_type[c_mission] == 37 ) {
		if((tspin_flag[0] == 2) && (lines >= 2)) c_norm[0]++;
	}
	// �g���v��SP
	if( mission_type[c_mission] == 38 ) {
		if( (mission_opt_2[c_mission] == 0) || 
		    ((mission_opt_2[c_mission] == 1) && (dhold2[0]) && (hold_used[0] >= 2)) ){
			if((mission_opt_3[c_mission]>=0)&&(mission_opt_3[c_mission]<=6)){//�P�i
				if((lines == 3) && (blk[0] == mission_opt_3[c_mission])) c_norm[0]++;
			}else if(mission_opt_3[c_mission]==7){//LJ
				if((lines == 3) && ((blk[0] == 1)||(blk[0] == 5))) c_norm[0]++;
			}else if(mission_opt_3[c_mission]==8){//SZ
				if((lines == 3) && ((blk[0] == 3)||(blk[0] == 6))) c_norm[0]++;
			}
		}
	}
		// �X�N�E�F�A�^�S�[���h�X�N�E�F�A
	if((mission_type[c_mission] == 40) || (mission_type[c_mission] == 41))
	{
		 c_norm[0]++;
	}

	// �~�b�V�����N���A�@EX�˓���
	if((c_norm[0] >= mission_norm[c_mission]) && ((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) && (lines == 2)) {
		PlaySE(43);//levelup.wav�̑����stgstar.wav
		StopSE(32);
		if(mission_end[c_mission] == 3)
			PlaySE(18);
		objectCreate2(0, 8, Rand(20) + 180 + 192 * 0 - 96 * maxPlay, 20 + Rand(10), 0, 0, 0, 0); 
		timeOn[0] = 0;
		c_mission++;
		clear_mission++;
		bgfadesw = 1;
		missionSetStatus();
		if(mission_bgm[c_mission] == -1)
			fadelv[0] = 10;
		else if(mission_bgm[c_mission] != mission_bgm[c_mission - 1]){
			StopAllBGM();
			bgmlv = mission_bgm[c_mission];
			changeBGM(0);
		}
	} else if(c_norm[0] >= mission_norm[c_mission]) { //���ʃN���A
		PlaySE(19);
		StopSE(32);
		
		timeOn[0] = 0;
		c_mission++;
		clear_mission++;
		
		// �G���f�B���O�˓��`�F�b�N
		if((c_mission > 29) || (mission_end[c_mission - 1] == 1) || (mission_end[c_mission - 1] >= 4) || (((mission_end[c_mission - 1] == 2) || (mission_end[c_mission - 1] == 3)) && (lines != 2))) {
			c_mission = c_mission - 1;
			c_norm[0] = mission_norm[c_mission];
			if(((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) && (lines != 2))
				ending[0] = 4;
			else
				ending[0] = 1;
			pinch[0] = 0;
			if(mission_end[c_mission] < 4)	//�X�^�b�t���[���J�n�̂��߁AonRecord�����̂܂܂�
				onRecord[0] = 2;
			pinch[0] = 0;
		} else {
			bgfadesw = 1;
			missionSetStatus();
			if(mission_bgm[c_mission] == -1)
				fadelv[0] = 10;
			else if(mission_bgm[c_mission] != mission_bgm[c_mission - 1]){
				StopAllBGM();
				bgmlv = mission_bgm[c_mission];
				changeBGM(0);
			}
		}
	}
}

/* ���̐ݒ�i�������xetc�j���Q�[���ɔ��f������ */
void missionSetStatus() {
	int i;
	int tmp;
	// �m���}
	c_norm[0] = 0;
	
	upLineNo[0] = 0;
	
	// �^�C��
	ltime[0] = mission_time[c_mission];
	
	// ���x��
	lv[0] = mission_lv[c_mission] + 1;
	
	// ���x
	if(mission_lv[c_mission] < 15){
	if(mission_type[c_mission] <= 7){
		// �ʏ�
		if((repversw < 56) || (mission_file == 6))
			sp[0] = lvTableAce55[mission_lv[c_mission]];
		else
			sp[0] = lvTableAce[mission_lv[c_mission]];
		wait1[0] = wait1_Ace;
		wait2[0] = wait2_Ace;
		wait3[0] = wait3_Ace;
		waitt[0] = waitt_Ace;
	} else if(mission_type[c_mission] == 8) {
		// �n�C�X�s�[�h�P
		sp[0] = lvTableHiSpeed1[mission_lv[c_mission]];
		wait1[0] = wait1_HiSpeed1;
		wait2[0] = wait2_HiSpeed1;
		wait3[0] = wait3_HiSpeed1;
		waitt[0] = waitt_HiSpeed1;
	} else if(mission_type[c_mission] == 9) {
		// �n�C�X�s�[�h�Q
		sp[0] = 1200;
		wait1[0] = wait1_HiSpeed2;
		wait2[0] = wait2_HiSpeed2;
		wait3[0] = wait3_HiSpeed2;
		waitt[0] = waitt_HiSpeed2;
	} else if((mission_type[c_mission] == 10) || (mission_type[c_mission] == 23)) {
		// �A�i�U�[&�ϋv
		sp[0] = 1200;
		wait1[0] = wait1_Acea_tbl[mission_lv[c_mission]];
		wait2[0] = wait2_Acea_tbl[mission_lv[c_mission]];
		wait3[0] = wait3_Acea_tbl[mission_lv[c_mission]];
		waitt[0] = waitt_Acea_tbl[mission_lv[c_mission]];
	} else if((mission_type[c_mission] >= 11) && (mission_type[c_mission] <= 18) || (mission_type[c_mission] == 21)) {
		// X-RAY�ȍ~�B�e�L�g�[
		if((repversw < 56) || (mission_file == 6))
			sp[0] = lvTableAce55[mission_lv[c_mission]];
		else
			sp[0] = lvTableAce[mission_lv[c_mission]];
		wait1[0] = wait1_Ace;
		wait2[0] = wait2_Ace;
		wait3[0] = wait3_Ace;
		waitt[0] = waitt_Ace;
	} else if(mission_type[c_mission] == 19) {
		// DEVIL 800
		sp[0] = 1200;
		wait1[0] = wait1_devil_tbl32[8];
		wait2[0] = wait2_devil_tbl32[8];
		wait3[0] = wait3_devil_tbl32[8];
		waitt[0] = waitt_devil_tbl32[8];
	} else if(mission_type[c_mission] == 20) {
		// DEVIL 1200
		sp[0] = 1200;
		if(!mission_opt_3[c_mission]){
			wait1[0] = wait1_devil_tbl32[12];
			wait2[0] = wait2_devil_tbl32[12];
			wait3[0] = wait3_devil_tbl32[12];
			waitt[0] = waitt_devil_tbl32[12];
		} else {
			if(repversw < 60){
				wait1[0] = wait1_devil_tbl[12];
				wait2[0] = wait2_devil_tbl[12];
				wait3[0] = wait3_devil_tbl[12];
				waitt[0] = waitt_devil_tbl[12];
			}else{
				wait1[0] = wait1_doom_tbl[12];
				wait2[0] = wait2_doom_tbl[12];
				wait3[0] = wait3_doom_tbl[12];
				waitt[0] = waitt_doom_tbl[12];
			}
		}
	} else if(mission_type[c_mission] == 22) {
		// �I�[���h�X�^�C��
		sp[0] = lvTableHeboGB[mission_lv[c_mission]];
		wait1[0] = wait1_HeboGB;
		wait2[0] = wait2_HeboGB;
		wait3[0] = wait3_HeboGB_tbl[mission_lv[c_mission]];
		waitt[0] = waitt_HeboGB_tbl[mission_lv[c_mission]];
	} else if(mission_type[c_mission] >= 24) {
		// �Ƃ肠�����ϋv�ȍ~
		if((repversw < 56) || (mission_file == 6))
			sp[0] = lvTableAce55[mission_lv[c_mission]];
		else
			sp[0] = lvTableAce[mission_lv[c_mission]];
		wait1[0] = wait1_Ace;
		wait2[0] = wait2_Ace;
		wait3[0] = wait3_Ace;
		waitt[0] = waitt_Ace;
	}
	}
	//+
	if((mission_lv[c_mission] >= 15) && (mission_type[c_mission] != 20)){
		sp[0] = 1200;
		wait1[0] = wait1_Acea_tbl[mission_lv[c_mission] - 15];
		wait2[0] = wait2_Acea_tbl[mission_lv[c_mission] - 15];
		wait3[0] = wait3_Acea_tbl[mission_lv[c_mission] - 15];
		waitt[0] = waitt_Acea_tbl[mission_lv[c_mission] - 15];
		if(mission_type[c_mission] == 19){
			if(repversw < 60){
				wait1[0] = wait1_devil_tbl[8];
				wait2[0] = wait2_devil_tbl[8];
				wait3[0] = wait3_devil_tbl[8];
				waitt[0] = waitt_devil_tbl[8];
			}else{
				wait1[0] = wait1_doom_tbl[8];
				wait2[0] = wait2_doom_tbl[8];
				wait3[0] = wait3_doom_tbl[8];
				waitt[0] = waitt_doom_tbl[8];
			}
		}
	}
	// OOBAKA
	if(mission_type[c_mission] == 29){
		sp[0] = 1200;
		wait1[0] = (repversw >= 60);
		wait2[0] = 0;
		wait3[0] = 0;
		waitt[0] = 5;
	}
	
	// �T�C�N���p�t���O
	if(mission_type[c_mission] == 5) {
		for(i = 0; i < 4; i++) cycle[i] = 0;
	}
	// �^�[�Q�b�g�p
	if(mission_type[c_mission] == 6) {
	//�X�e�[�W26�܂ł������������Ă��Ȃ����������C��
		for(i = 0; i < 200; i++) target_cleared[i] = 0;
	}
	// �C���C�T�[�p
	if((mission_type[c_mission] == 7)||(mission_type[c_mission] == 39)) {
		eraser_now_pattern = 0;
		setEraserLines();
	}
	
	//�A�i�U�[��opt��1�ȏ�ɂ������@�܂��̓u���C���h
	if(((mission_type[c_mission] == 10) && (mission_opt_3[c_mission])) || (mission_type[c_mission] == 25)){
		isblind[0] = 1;
		blind_flag[0] = 1;
	} else {
		isblind[0] = 0;
		blind_flag[0] = 0;
	}
	// X-RAY�p
	if(mission_type[c_mission] == 12) {
		isxray[0] = 1;
		xray_flag[0] = 1;;
		xray_counter[0] = 0;
	} else {
		isxray[0] = 0;
		xray_flag[0] = 0;
	}
	
	// �J���[�p
	if(mission_type[c_mission] == 13) {
		iscolor[0] = 1;
		color_flag[0] = 1;
	} else {
		iscolor[0] = 0;
		color_flag[0] = 0;
	}
	
	// ���[�����[���p
	if(mission_type[c_mission] == 14) {
		rollroll_flag[0] = 1;
		isrollroll[0] = 1;
	} else {
		rollroll_flag[0] = 0;
		isrollroll[0] = 0;
	}
	
	// �~���[�p
	if(mission_type[c_mission] == 15) {
		isfmirror[0] = 1;
	} else {
		isfmirror[0] = 0;
	}
	
	//��]�s��
	if(mission_type[c_mission] == 17) {
		isrotatelock[0] = 1;
		rt_nblk[0 + 6 * 0] = rand(4,0);
		rt_nblk[1 + 6 * 0] = rand(4,0);
		rt_nblk[2 + 6 * 0] = rand(4,0);
		rt_nblk[3 + 6 * 0] = rand(4,0);
		rt_nblk[4 + 6 * 0] = rand(4,0);
		rt_nblk[5 + 6 * 0] = rand(4,0);
	} else {
		isrotatelock[0] = 0;
		rt_nblk[0 + 6 * 0] = 0;
		rt_nblk[1 + 6 * 0] = 0;
		rt_nblk[2 + 6 * 0] = 0;
		rt_nblk[3 + 6 * 0] = 0;
		rt_nblk[4 + 6 * 0] = 0;
		rt_nblk[5 + 6 * 0] = 0;
	}
	
	//NEXT�s��
	if(mission_type[c_mission] == 18) {
		ishidenext[0] = 1;
	} else {
		ishidenext[0] = 0;
	}
	//DEVIL 800(COPY RISING)
	if(mission_type[c_mission] == 19) {
		st_bdowncnt[0] = 0;
		upLineT[0] = 0;
		if(mission_opt_3[c_mission] == 0)
			mission_opt_3[c_mission] = 20;
		shirase[0] = mission_opt_3[c_mission];
	}else{
		st_bdowncnt[0] = 0;
	}

	//DEVIL 1200([ ])
	if(mission_type[c_mission] == 20) {
		over1000_block[0] = 2;
	} else {
		over1000_block[0] = 0;
	}
	//GARBAGE
	if(mission_type[c_mission] == 21){
		upLineT[0] = 2;
		upLines[0] = mission_opt_3[c_mission];
		if(repversw < 41){
			if(upLines[0] > 18-(2*(!spawn_y_type)))
				upLines[0] = 18-(2*(!spawn_y_type));
		}else{
			if(upLines[0] > 18)
				upLines[0] = 18;
			upLines[0] = upLines[0]-(2*(!spawn_y_type));
		}
	} else {
		upLineT[0] = uplinetype;
		if(repversw >= 40) upLines[0] = 0;
	}
	//�I�[���h�X�^�C��
	if(mission_type[c_mission] == 22) {
		heboGB[0] = 1;
		ishidenext[0] = 2;
		isholdlock[0] = 1;
	} else {
		heboGB[0] = 0;
		isholdlock[0] = 0;
	}
	//�㉺���E�t�]
	if(mission_type[c_mission] == 24) {
		isLRreverse[0] = 1;
		isUDreverse[0] = 1;
	} else {
		isLRreverse[0] = 0;
		isUDreverse[0] = 0;
	}

	//�r�b�O���S����
	if((mission_type[c_mission] == 1) || ((mission_type[c_mission] == 26) && (mission_opt_3[c_mission] == 0))) {
		IsBig[0] = 1;
	} else {
		IsBig[0] = 0;
	}

	if((mission_type[c_mission] == 40) || (mission_type[c_mission] == 41)) {
		squaremode[0] = 1;
	} else {
		squaremode[0] = 0;
	}
}
// �t�B�[���h�̍ŏ�i��Ԃ�
//gamestart.c�Ɉړ� C7U0.8


// �C���C�T�[�p������
void setEraserLines() {
	int i, tmp,max,min;
	int line[22];	// ���C���̏d���h�~�p
	
	for(i = 0; i < 22; i++) line[i] = 0;
	
	eraser_now_lines = 0;
	// �g���o�����͍ō�18�i�܂�
	max = mission_opt_2[c_mission];
	min = mission_opt_1[c_mission];
	
	if((!spawn_y_type) && (mission_opt_1[c_mission] <= 2))
		min = 3;
	if(max >= fldsizeh[0])
		max = fldsizeh[0];
		
	if(min > max){
		min = i;
		min = max;
		i = max;
	}
	
	for(i = 0; i <= mission_opt_3[c_mission]; i++) {
		if(i >= 4) break;	// �ő��4�{�܂�
		if(i >= mission_norm[c_mission] - c_norm[0]) break;
		if((eraser_now_pattern >= 2) && (i >= 1)) break;
		
		eraser_now_lines++;
		
		if(min == max) {
			// �ʒu�Œ�
			tmp = min+1;
		}else if((i >= mission_norm[c_mission] - c_norm[0] - 1) && (mission_norm[c_mission] > 1) && (line[min + 1] != 1) && (repversw >= 54)){
			// �Ō��1�{
			tmp = min+1;
		}else{
			do {
				tmp = rand(22,0);
			} while( (tmp < min+1) || (tmp > max+1) || (line[tmp] == 1) );
		}
		line[tmp] = 1;
		eraser_lines[i] = tmp;
		eraser_cleared[i] = 0;
	}
}

// �C���C�T�[�̐���\��
void viewEraserLines() {
	int i;
	
	for(i = 0; i < eraser_now_lines; i++) {
		if(i >= 4) break;	// �ő��4�{�܂�
		
		if(getDrawRate() == 1)
			BltRect(44, (14 - 12 * maxPlay) * 8, (eraser_lines[i] + 3) * 8, 288, 256 - 64 * (mission_type[c_mission] == 39) + eraser_cleared[i] * 32, 96, 8);
		else
			BltRect(44, (14 - 12 * maxPlay) * 16, (eraser_lines[i] + 3) * 16, 448, 160 - 64 * (mission_type[c_mission] == 39)+ eraser_cleared[i] * 32, 192, 16);
	}
}

// �^�[�Q�b�g�ł̃X�e�[�W�ǂݍ���
void loadTargetStage() {
	int tmp;
statc[0 * 10 + 6] = mission_opt_3[c_mission];
	if(mission_opt_1[c_mission] == mission_opt_2[c_mission]){	//�X�e�[�W��1����
		tmp = mission_opt_1[c_mission];
	}else{
		// �ǉ����ŏo���X�e�[�W�͈̔͂��w��\ #1.60c7s2
		do {
			if(repversw < 46) tmp = rand(100,0);
			else tmp = rand(mission_opt_2[c_mission] + 1,0);
		} while( (tmp < mission_opt_1[c_mission]) || (tmp > mission_opt_2[c_mission]) || (target_cleared[tmp] == 1) );
	target_cleared[tmp] = 1;	// �o���ς݃t���OON
	}
	loadTomoyoStage(0, tmp);
	// �v���`�i�u���b�N�����_�����i����オ��X�e�[�W�̓����_���ɂ��Ȃ��j
	if((repversw >= 58) && (tomoyo_rise[0] == 0) && (mission_opt_3[c_mission] != 0)) randPlatinum(0, mission_opt_3[c_mission]);
}

//������������������������������������������������������������������������������
//  ���f�[�^�̓ǂݍ��݁^�ۑ�
//������������������������������������������������������������������������������
// �t�@�C���t�H�[�}�b�g (4byte�P��)
//   0       �o�[�W���� (0=���� 1=c7r8)
//   1�`  19 ���g�p
//  20�`  39 ���P
//  40�`  59 ���Q

/* ���[�h */
void loadMissionData(int number) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	sprintf(string[0], "stage/mission%02d.sav", number);
	
	LoadFile(string[0], &saveBuf, 930 * 4);
	
	// ���f�[�^��ǂݍ���
	for(i = 0; i < 30; i++) {
		mission_type[i]  = saveBuf[(i + 1) * 20 + 0];	// ���
		mission_norm[i]  = saveBuf[(i + 1) * 20 + 1];	// �m���}
		mission_time[i]  = saveBuf[(i + 1) * 20 + 2];	// ��������
		mission_end[i]   = saveBuf[(i + 1) * 20 + 3];	// �I���t���O
		mission_lv[i]    = saveBuf[(i + 1) * 20 + 4];	// ���x��
		mission_erase[i] = saveBuf[(i + 1) * 20 + 5];	// �N���A���ɏォ��������郉�C����
		mission_opt_1[i] = saveBuf[(i + 1) * 20 + 6];	// �ǉ����P�i�����j
		mission_opt_2[i] = saveBuf[(i + 1) * 20 + 7];	// �ǉ����Q�i����j
		mission_opt_3[i] = saveBuf[(i + 1) * 20 + 8];	// �ǉ����R�i�C���C�T�[���Ɩ{���ASHIRASE800�͂���オ��Ԋu�A���͖��g�p�j
		mission_bgm[i]   = saveBuf[(i + 1) * 20 + 9];	// BGM
	}
}

/* �Z�[�u */
void saveMissionData(int number) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// ���f�[�^
	for(i = 0; i < 30; i++) {
		saveBuf[(i + 1) * 20 + 0] = mission_type[i];	// ���
		saveBuf[(i + 1) * 20 + 1] = mission_norm[i];	// �m���}
		saveBuf[(i + 1) * 20 + 2] = mission_time[i];	// ��������
		saveBuf[(i + 1) * 20 + 3] = mission_end[i];		// �I���t���O
		saveBuf[(i + 1) * 20 + 4] = mission_lv[i];		// ���x��
		saveBuf[(i + 1) * 20 + 5] = mission_erase[i];	// �N���A���ɏォ��������郉�C����
		saveBuf[(i + 1) * 20 + 6] = mission_opt_1[i];	// �ǉ����P
		saveBuf[(i + 1) * 20 + 7] = mission_opt_2[i];	// �ǉ����Q
		saveBuf[(i + 1) * 20 + 8] = mission_opt_3[i];	// �ǉ����R
		saveBuf[(i + 1) * 20 + 9] = mission_bgm[i];		// BGM
	}
	
	sprintf(string[0], "stage/mission%02d.sav", number);
	SaveFile(string[0], &saveBuf, 930 * 4);
}
