// D.R.S(�@DT(ry Rotation System�@)

/*
> �� ����]�i�����v���j�̗�Ő�������ƁA
> (1) �u���b�N�̉�]�オ�n�`�Əd�Ȃ�ꍇ�A�{���̈ʒu����1�}�X���ɂ��炷�B
> (2) ����ł��d�Ȃ�ꍇ�́A�{���̈ʒu����1�}�X�E�ɂ��炷�B
> (3) ����ł��d�Ȃ�ꍇ�́A�{���̈ʒu����1�}�X���ɂ��炷�B
> (4) ����ł��d�Ȃ�ꍇ�́A�{���̈ʒu���獶���ɂ��炷�B
> (5) ����ł��d�Ȃ�ꍇ�́A�{���̈ʒu����E���ɂ��炷�B
> ���P���O���Q��
> ���@�^���_�@��
> ���S�@�R�@�T��
> �Ƃ������ƂɂȂ�A���ړ����D��̕ǏR����s���܂��B
> 
> �� �܂��A�E��]�i���v���j�̎��́A
> ���Q���O���P��
> ���@�^���_�@��
> ���T�@�R�@�S��
> �ɂȂ�A�E�ړ����D��ƂȂ�܂��B
> 
> �� ����ɁA�E��]�{�^������������Ԃō���]�{�^���������ƁA
> �u���ړ��D��̉E��]�v�Ƃ�������ȕǏR�肪�����܂��B
> ���̋t�ɁA����]�{�^������������ԂŉE��]�{�^���������ƁA
> �u�E�ړ��D��̍���]�v�ɂȂ�܂��B
> http://dtet.web.infoseek.co.jp/dtet/tech.htm
> ������́u���~4�v�̉�]����́A���̃e�N�j�b�N��p���Ă��܂��B
> 
> �� 180�x��]�ɂ��Ẳ�]������ʏ�̍���]�Ɠ��l�ɁA
> ��̈ʒu����5�������������܂��B
> 
> ��������X���G�ɂȂ�܂������A�����
> �قڑS�Ẳ�]����ɂ��Đ��������Ǝv���܂��B

 Z����L���͉�]�ɂ����1�}�X�̓ʕ������܂������Ƃ��ł��܂��B
�@�@�@�@�@�@�@�@�@�@�@��
�@�@�����@�@����]�@����
���@�������@�@���@������
�������������@�@�@������������

��]��̃u���b�N���n�`�ɏd�Ȃ�ꍇ�A���E�̂ǂ��炩�Ɉړ����܂��B
����]�̏ꍇ�͍��Ɉړ��A�E��]�̏ꍇ�͉E�Ɉړ������悤�ɂȂ��Ă��܂��B
���������āAZ���ō���]�������
�@�@�@�@�@�@�@�@�@�@�@�@��
�@�@�����@�@�@�@�@�@�@����
���@�������@�@���@���@��
�������������@�@�@������������
�{�����̂悤�ɒn�`�Əd�Ȃ�܂����A����]�ɂ���ĂЂƂ����ɂ����
���ƂɂȂ�܂��B���������p���āA
http://dtet.web.infoseek.co.jp/dtet/tech.htm
�̂悤�ȃe�N�j�b�N���\�ɂȂ��Ă��܂��B
*/
int		blkDDataX[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂w�ʒu(7���/ 4�p�x/ 4�u���b�N)
{
	0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, 		1, 1, 1, 1,//I
	1, 0, 0, 2, 		1, 0, 1, 1, 		1, 2, 2, 0, 		1, 2, 1, 1,//L
	1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2, 		1, 1, 2, 2,//��
	1, 0, 1, 2, 		2, 2, 1, 1, 		1, 2, 1, 0, 		0, 0, 1, 1,//Z
	1, 0, 1, 2, 		1, 1, 0, 1, 		1, 2, 1, 0, 		1, 1, 2, 1,//T
	1, 0, 2, 2, 		1, 1, 1, 0, 		1, 2, 0, 0, 		1, 1, 1, 2,//J
	1, 2, 1, 0, 		2, 2, 1, 1, 		1, 0, 1, 2, 		0, 0, 1, 1,//S
};

int		blkDDataY[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂x�ʒu(7���/ 4�p�x/ 4�u���b�N)
{
	2, 2, 2, 2, 		0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0,//I ������C���@C7U3.0
	1, 2, 1, 1, 		1, 0, 0, 2, 		2, 1, 2, 2, 		1, 2, 2, 0,//L
	1, 1, 2, 2, 		1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2,//��
	1, 1, 2, 2, 		1, 0, 1, 2, 		2, 2, 1, 1, 		1, 2, 1, 0,//Z
	1, 1, 2, 1, 		1, 0, 1, 2, 		2, 2, 1, 2, 		1, 2, 1, 0,//T
	1, 1, 1, 2, 		1, 0, 2, 2, 		2, 2, 2, 1, 		1, 2, 0, 0,//J
	1, 1, 2, 2, 		1, 2, 1, 0, 		2, 2, 1, 1, 		1, 0, 1, 2,//S
};

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.05 - �u���b�N�ړ���
//������������������������������������������������������������������������������
void statDMove(int player) {
	int		i, bak, bottom, move, don, flash, kosa, rolling,k,synchro,y_hosei,hosei_type,lockT, fsmooth;

	fsmooth = 0;
	y_hosei=0;
	don = 0;
	synchro = 0;
	hiddenProc(player);
//	statc[player * 10 + 4] = 1; //����s���͂͏�ɉ\

	if(!statc[player * 10 + 2]) {
		padRepeat(player);
		
		// Hold
		if((repversw >= 64) && (!statc[player * 10 + 6])){
			doHold(player, 0);
			// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂� #1.60c7m2
			if(stat[player] == 7) return;
		}

		bs[player] = bs[player] + sp[player];
		
		lockT = wait3[player];
		if(isboost[player]){
			bs[player] = 1200;
			if((sp[player] >= 1200) && (gameMode[player] != 6))
				lockT = wait3[player] / 2;
		}

		// spawn_y_type��1�̏ꍇ��20G #1.60c7s2
		if( (spawn_y_type) && (sp[player] >= 1200) ) bs[player] = 1320;

		// ���[�����[������ #1.60c7j5
		rolling = 0;
		if(isrollroll[player]) {
			// ���^�C�~���O���u�X�e�[�W�^�C����30�t���[���Ŋ���؂��v���ɕύX #1.60c7m5
			if((ending[player] == 2) && (repversw >= 44)){
				/* �G���f�B���O�E���[�� */
				if( edrec[player] % p_rollroll_timer == 0 )
					rolling = 1;
			} else if( gameMode[player] == 6 ) {
				/* TOMOYO */
				//�X�e�[�W20�ȍ~�i�X�e�[�W�^�C�������j
				if((repversw >= 44) && (stage[player] > 19) && (ltime[player] % p_rollroll_timer == 0))
					rolling = 1;
				//�X�e�[�W19�܂�
				else if( stime[player] % p_rollroll_timer == 0 )
					rolling = 1;
			} else if( (gameMode[player] >= 4) || (item_mode[player]) ) {
				/* VERSUS / PRACTICE / MISSION */
				if( time[player] % p_rollroll_timer  == 0 )
					rolling = 1;
			}
		}

		// ��]!!
		if((statc[player * 10 + 6] != 0) && (repversw >= 59))
			move = 0;
		else
			move = (getPushState(player, 5) || rolling) - (getPushState(player, 4));
		if((getPushState(player, 6) != 0) && (statc[player * 10 + 6] == 0)) move = 2;
		if((move != 0) && (isrotatelock[player] == 0)) {
			bak = (rt[player] + move);
				if(istrance[player]){
					do{
						k = rand(7,player);
						setNextBlockColors(player, 1);
					}while(k == blk[player]);
				}else{
					k = blk[player];
				}
			if(move < 2){
				if(bak < 0) bak = 3;
				if(bak > 3) bak = 0;
			}else{
				if(bak > 3) bak = bak - 4;
				if(bak < 0) bak = bak + 4;
			}

			if(judgeBlock(player, bx[player], by[player], k, bak) == 0) {
				// �n�`�ɏd�Ȃ炸�ɉ�]�ł���ꍇ
				if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
				rt[player] = bak;
				blk[player] = k;
				bk_D[player] = 0;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = ccol[k];
				
				// ��]��������+1 #1.60c7s6
				statc[player * 10 + 5]++;
				
				// T-SPIN�����l�� #1.60c7n6
				if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
					if((blk[player] == 4)&&(tspin_type>0)) tspin_flag[player] = 1;
				}
			} else if( (!disable_wallkick) && (heboGB[player]==0) ) {
				// ��]�ł��Ȃ��Ƃ��́A�����E�ɓ������Ă݂悤
				
				//�␳�^�C�v�����߂�@���΂̃{�^���������Ă���΃^�C�v�t�]
				if((move==1)||(move==2)) hosei_type=1 - 0*(getPressState(player, 4));	// R
				else if(move==-1) hosei_type=0 + 1*(getPressState(player, 5));			// L
				
				move = 0;
				
				// BIG�̏ꍇ��2�}�X�����ׂ� #1.60c7o9
				for(i = 0; i <= IsBig[player]; i++) {
					if(hosei_type==0){	//���D�� �D��x�̒Ⴂ�ړ����璲�ׂ�
						if(judgeBlock(player, bx[player] + 1 + i, by[player]+1 + i, k, bak) == 0){//�E��
							move = 1 + i;
							y_hosei=1 + i;
						}
						if(judgeBlock(player, bx[player] - 1 - i, by[player]+1 + i, k, bak) == 0){//����
							move = -1 - i;
							y_hosei=1 + i;
						}
						if(judgeBlock(player, bx[player], by[player]+1 + i, k, bak) == 0){//��
							move = 0;
							y_hosei=1 + i;
						}
						if(judgeBlock(player, bx[player] + 1 + i, by[player], k, bak) == 0){//�E
							move = 1 + i;
							y_hosei=0;
						}
						if(judgeBlock(player, bx[player] - 1 - i, by[player], k, bak) == 0){//��
							move = -1 - i;
							y_hosei=0;
						}
					}if(hosei_type==1){	//�E�D��
						if(judgeBlock(player, bx[player] - 1 - i, by[player]+1 + i, k, bak) == 0){//����
							move = -1 - i;
							y_hosei=1 + i;
						}
						if(judgeBlock(player, bx[player] + 1 + i, by[player]+1 + i, k, bak) == 0){//�E��
							move = 1 + i;
							y_hosei=1 + i;
						}
						if(judgeBlock(player, bx[player], by[player]+1 + i, k, bak) == 0){//��
							move = 0;
							y_hosei=1 + i;
						}
						if(judgeBlock(player, bx[player] - 1 - i, by[player], k, bak) == 0){//��
							move = -1 - i;
							y_hosei=0;
						}
						if(judgeBlock(player, bx[player] +1 + i, by[player], k, bak) == 0){//�E
							move = 1 + i;
							y_hosei=0;
						}
					}
						if((move)||(y_hosei)) {
							if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
							bx[player] = bx[player] + move;
							if(y_hosei) {
								by[player] = by[player] + y_hosei;
								PlaySE(1);
								PlaySE(0);
								bk[player] = 0;		// �Œ莞�ԃ��Z�b�g
							}
							rt[player] = bak;
							blk[player] = k;
							bk_D[player] = 0;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = ccol[k];
							
							// ��]��������+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							// T-SPIN�����l�� #1.60c7n6
							if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
								if((blk[player] == 4)&&(tspin_type>0))tspin_flag[player] = 1;
							}
							break;
						// Ti�����F���R�� ���R���1�񂾂��\ #1.60c3
						} else if((blk[player] == 4) && (kickc[player] == 0)) {
							if((bak == 2) && (judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)) {
								if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
								by[player] = by[player] -1 -i;
								rt[player] = bak;
								blk[player] = k;
								bk_D[player] = 0;
								synchro = 1;
								if(istrance[player])
									c_cblk_r[player] = wcol[k];
								
								// ��]��������+1 #1.60c7s6
								statc[player * 10 + 5]++;
								
								kickc[player]++;
								
								// T-SPIN�����l�� #1.60c7n6
								if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
									if((blk[player] == 4)&&(tspin_type>0))tspin_flag[player] = 1;
								}
								break;
							}
						}else if((blk[player] == 0) && (!move) && (!y_hosei) && (!disable_wallkick) && (heboGB[player]==0)) {
							//����ł��_�����Ȃ��ꍇ
							// Ti���ԕǥ���R�� (�Ƃ肠�������R��͏c�A�ǏR��͉��ɂȂ鎞����) #1.60c3
				
							move = 0;
							// BIG�̏ꍇ��4�}�X�����ׂ� #1.60c7m6
							for(i = 0; i <= IsBig[player] * 3; i++) {
								if((bak == 0) || (bak == 2)) {	// ���ɂȂ鎞
									if(judgeBlock(player, bx[player] -1 -i, by[player], k, bak) == 0)
										move = -1 -i;
									else if(judgeBlock(player, bx[player] - 2 -i, by[player], k, bak) == 0)
										move = -2 - i;
									else if(judgeBlock(player, bx[player] + 1 +i, by[player], k, bak) == 0)
										move = 1 + i;
									else if(judgeBlock(player, bx[player] + 2 +i, by[player], k, bak) == 0)
										move = 2 + i;
									
									if(move) {
										if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
										bx[player] = bx[player] + move;
										rt[player] = bak;
										blk[player] = k;
										bk_D[player] = 0;
										synchro = 1;
										if(istrance[player])
											c_cblk_r[player] = ccol[k];
								
										// ��]��������+1 #1.60c7s6
										statc[player * 10 + 5]++;
								
										break;
									}
								} else if(kickc[player] == 0) {	// �c�ɂȂ鎞
									if(judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)
										move = -1 -i;
									else if(judgeBlock(player, bx[player], by[player] -2 -i, k, bak) == 0)
										move = -2 -i;
									
									// �ڒn���Ă��Ȃ��ꍇ�͏R��Ȃ� #1.60c7k5
									if( (judgeBlock(player,bx[player],by[player]+1+i,k,rt[player]) == 0) && (repversw >= 8) )
										move = 0;
									
									if(move) {
										if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
										by[player] = by[player] + move;
										rt[player] = bak;
										blk[player] = k;
										bk_D[player] = 0;
										synchro = 1;
										if(istrance[player])
											c_cblk_r[player] = ccol[k];
										// ��]��������+1 #1.60c7s6
										statc[player * 10 + 5]++;
								
										kickc[player]++;
										break;
									}
								}
							}
						}
				}
			} 
		}

		// ���E�Ɉړ�
		move = getPressState(player, 3) - getPressState(player, 2);
		if(isLRreverse[player]) move = 0 - move;
		if(move && (statc[player * 10 + 4])) {
			/* �X���[�Y���̕\���ُ���C�� via C++ Port */
			if ( smooth && (sp[player] < 60) )
			{
				// drawCBlock (player, blk[player] + 1, 5, bs[player] * 8 / 60, 0, 1);
			}
			else
			{
				drawCBlock (player, blk[player] + 1, 5, 0, 0, 1);
			}
			// BIG���A2�}�X�P�ʃ��[�h�̏ꍇ�͈ړ��ʂ�2�{���� #1.60c7m6
			if(IsBig[player] && BigMove[player]) move = move * 2;
			
			if((mpc[player] == 1) || (mpc[player] >= waitt[player]) || ((isremote[player]) && (gameMode[player] != 4)) || (mpc[player] >= 10 - (2 * (repversw >= 64))))
				if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					bx[player] = bx[player] + move;
					if(movesound) PlaySE(5);
					bk_D[player] = 0;
					if(!synchro) tspin_flag[player] = 0;	// T-SPIN�������D #1.60c7n6
				}
		}
		synchro = 0;
//		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]

		if(!nanameallow) move = 0;

		// ���𗣂��Ă���A�܂���downtype��0�̏ꍇ�A�����ꐧ������#1.60c7f9
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) || (!downtype)) down_flag[player] = 0;
		if((!getPressState(player, 0+(1*(isUDreverse[player])))) || (!downtype) || (repversw < 12)) up_flag[player] = 0;
		
		// ��������!! �����ꐧ������#1.60c7f9
		if((!move) && getPressState(player, 1-(1*(isUDreverse[player]))) && ((sp[player] < 60) || (repversw  >= 42)) && (!down_flag[player]) && ((statc[player * 10 + 4]) || (repversw < 27))) {
			if(repversw >= 44) bs[player] = bs[player] + 91;
			else bs[player] = 91;
			if((heboGB[player])&&(repversw >= 52)) {
				bs[player] = 61;
			}
			if((gameMode[player]>=9)||((gameMode[player]==6)&&(anothermode[player]==4))||((gameMode[player]==7)&&(anothermode[player]==3))){
				sc[player]++;//������
			}else{
				qdrop[player]++;	//�x�����̃h���b�v�{�[�i�X�����́A�X�R�A�v�Z����
			}
		}
		
		if((ismagnetblock[player]) && (repversw >= 41)) bs[player] = bs[player] + 30;

		for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);

		// �n�ʂɂ�������
		if((judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) {

			if(ismagnetblock[player] == 1)
				bk[player] = 100;

			bs[player] = 0;
			if((bk[player] == 0) && (smooth)) {
				bs[player] = 0;
				don = 1;
			}

			if(lockT != 99) // �ڒ�99���� #1.60c7
				bk[player]++;
			else
				bk[player] = 98;

			// �����ꐧ��#1.60c7f9
			// �Œ莞�ԑ啝�Z�k #1.60c7k8
			if((getPressState(player, 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
						&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)){
				if((sp[player] >= 60) || (heboGB[player]!=0))	// 1G�ȏ㑦�ڒ�
					bk[player] = 100;
				else
					bk_D[player] = bk_D[player] + 4;
			}
			// ����ꑦ�ڒ�
			if( ( (getPressState(player , 0+(1*(isUDreverse[player]))) && (repversw >= 43)) ||
				  (getPushState(player , 0+(1*(isUDreverse[player]))) && (repversw < 43)) )
				&& (rots[player] != 7) && ( (repversw <= 13) || !up_flag[player] ) && (heboGB[player]==0) 
				&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)) {
				bk[player] = bk[player] + lockT;
				PlaySE(44);
				harddrop[player]=1;
				
				// ����ꐧ���ǉ� #1.60c7q8
				if( downtype && (repversw >= 14) ) up_flag[player] = 1;
			}
			
			// �Œ�
			if((bk[player] > lockT) || (bk_D[player] > 30)) {
				if(heboGB[player]==0)
					PlaySE(3);
				else if(heboGB[player] == 1)
					PlaySE(1);
				kickc[player] = 0;	// �i�v���R��h�~�p #1.60c3 
				statc[player * 10 + 2]++;
				drawCBlock(player, 0, 0, 0, 10, 0);
				// �����ꐧ��#1.60c7f9
				if((getPressState(player, 1)) && (downtype) && (!move || nanamedown)) down_flag[player] = 1;
				if((repversw >= 57) && (!harddrop[player])) goto lockflash;	// SUPER��SKIP
				return;
			}
		} else {
			// T.L.S. (Temporary Landing System)  (c)1998 AR��KA(^^;
			// �ʊ֐��ɓƗ� #1.60c7k4
			drawTLSBlock(player, bottom);
			

			// ��L�[�ň�u�ŗ���&�Œ�
			// ����ꐧ���ǉ� #1.60c7p1
			if(getPressState(player , 0+(1*(isUDreverse[player]))) && (!move) && (!sonicdrop) && (!up_flag[player]) && (heboGB[player]==0) && ((statc[player * 10 + 4]) || (repversw < 27))) {
					if(gameMode[player]==10){
						if ( sp[player] <= 240 )
	 					sc[player] = sc[player] + ( bottom - by[player] - 1 ) * 23 / 20;
					}else if((gameMode[player]>=9)||((gameMode[player]==6)&&(anothermode[player]==4))||((gameMode[player]==7)&&(anothermode[player]==3))){
						sc[player] = sc[player]+(bottom -by[player] -1) *2;//������
					}else{
						sdrop[player] = (bottom -by[player] -1) *2;//��Usdrop�֓����
					}
					if(!block_spectrum){
						by[player] = bottom - 1;
					}else{	//�c����`��
						/* �c���J�n�ʒu���X���[�Y�n�_�ɂ��� via C++ Port */
						fsmooth = 0;
						if ( smooth && (sp[player] < 60) )
						{
							/* 1�t���[������ */
							fsmooth = bs[player] * 8 / 60;
						}

						while(by[player] != bottom - 1){
							drawCBlock (player, blk[player] + 1, 4, fsmooth, 0, 1);
							by[player]++;
							fsmooth = 0;
						}
					}
					PlaySE(1);
					PlaySE(3);
					PlaySE(44);
					harddrop[player]=1;
					kickc[player] = 0;
					statc[player * 10 + 2] ++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					if(downtype) up_flag[player] = 1;
					statc[player * 10 + 5] = 0;	// ��]�����������Z�b�g #1.60c7s6
					if((repversw >= 57) && (!harddrop[player])) goto lockflash;	// SUPER��SKIP
					return;
			}
		}
		
		// �u���b�N��������
		while(bs[player] > 60) {
			bk[player] = 0;
			bk_D[player] = 0;
			tspin_flag[player] = 0;	// T-SPIN�������D #1.60c7o9
			
			bs[player] = bs[player] - 60;
			
			// BIG���A2�}�X�P�ʃ��[�h�̏ꍇ�͗�����ʂ�2�{���� #1.60c7m6
			// 3�}�X����Ă��Ă��ڒn���Ă��܂��̂��C�� #1.60c7o9
			if( (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)
			 || (judgeBlock(player, bx[player], by[player] + 1 + (IsBig[player] && BigMove[player] && !ybigtype), blk[player], rt[player]) == 0) )
			{
				if((block_spectrum) && ((!smooth) || (bs[player] >= 60)) && (heboGB[player]==0))	//�c����`��
					drawCBlock (player, blk[player] + 1, 5, 0 , 0, 1);
				by[player] = by[player] + 1 + (IsBig[player] && BigMove[player] && !ybigtype);
			}
			
			// �n�ʂɂ�������
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player])) {
				by[player] = bottom - 1;
				bs[player] = 0;
				if(!smooth) don = 1;
				
				// ���L�[�ŌŒ葬�x�啝�A�b�v #1.60c7r3
				if( getPressState(player, 1-(1*(isUDreverse[player]))) && (!down_flag[player]) && ((!move || nanamedown) || (repversw < 61))) {
					if((heboGB[player]==0) && (sp[player] < 60)) bk_D[player] = bk_D[player] + 4;
					else {
						PlaySE(1);
						if(heboGB[player]==0)
							PlaySE(3);
						kickc[player] = 0;
						kickc2[player] = 0;
						statc[player * 10 + 2]++;
						drawCBlock (player, 0, 0, 0, 10, 0);
						if(downtype) down_flag[player] = 1;
						if((repversw >= 57) && (!harddrop[player])) goto lockflash;	// SUPER��SKIP
						return;
					}
				}
				// ����ꑦ�ڒ� #1.60c7r3
				if( ( (getPressState(player , 0+(1*(isUDreverse[player]))) && (repversw >= 43)) ||
					  (getPushState(player , 0+(1*(isUDreverse[player]))) && (repversw < 43)) )
					&&(!up_flag[player]) && (repversw >= 15) && (heboGB[player]==0) 
					&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)) {
					PlaySE(3);
					kickc[player] = 0;
					harddrop[player]=1;
					statc[player * 10 + 2]++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					if(downtype) up_flag[player] = 1;
					if((repversw >= 57) && (!harddrop[player])) goto lockflash;	// SUPER��SKIP
					if(repversw >= 57) return;
				}
			} else {
				// ��]�����������Z�b�g #1.60c7s6
				statc[player * 10 + 5] = 0;
			}
		}

		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]

//		UpLineBlockJudge(player);

		if((don) && (heboGB[player]==0)) PlaySE(1);

		// �u���b�N��`��
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		kosa = bk[player] * 7 / (lockT + (lockT == 0));
		if(kosa > 6) kosa = 6;
		if(smooth && (sp[player] < 60))
			drawCBlock(player, blk[player] + 1, kosa, bs[player] * 8 / 60, flash, 0);
		else
			drawCBlock(player, blk[player] + 1, kosa, 0, flash, 0);

		// Hold	#1.60c
		if((repversw < 64) && (!statc[player * 10 + 2]) && (!statc[player * 10 + 6])){
			doHold(player, 0);
			// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂� #1.60c7m2
			if(stat[player] == 7) return;
		}
		
		statc[player * 10 + 6] = 0;
		if((repversw >= 57) && (repversw < 61) && (statc[player * 10 + 2] != 0) && (!harddrop[player])) goto lockflash;	// SUPER��SKIP
	} else {
		lockflash:
		statc[player * 10 + 2]++;
		if((c_nblk[0 + player * 6] != 8) && (c_nblk[0 + player * 6] >= 0))drawCBlock (player, 0, 0, 0, 10, 0);
		
		// ���𗣂��Ă���ꍇ�A�����ꐧ������#1.60c7n6
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) && (repversw >= 10)) down_flag[player] = 0;
		else if((downtype) && (repversw >= 61)) down_flag[player] = 1;
		if(!getPressState(player, 0+(1*(isUDreverse[player])))) up_flag[player] = 0;
		else if((downtype) && (repversw >= 61)) up_flag[player] = 1;
		
		if(statc[player * 10 + 2] > 2 - (repversw >= 9)) {	// �ڒ����̊D�F����1�t���Z�k #1.60c7k8
			setBlock(player, bx[player], by[player], blk[player], rt[player]);
			if(stat[player] == 7) return;
			
			ndelay[player] = 1;
			
			lc[player]++;
			
			// T-SPIN�l�� #1.60c7s6
			if((tspin_flag[player]) && (blk[player] == 4)&& ((tspin_type>=2) || (gameMode[player] == 8)) && (statc[player * 10 + 5] > 0) && (isTSpin(player) >= 3) ) {
				PlaySE(34);
				tspin_c[player] = 120;
				last_tspin[player] = 0;
				tspin_flag[player] = 2;
			} else if((tspin_type==2) || (gameMode[player] == 8)){//3�R�[�i�[�����̎��͋t�ɉ��낷
				tspin_flag[player] = 0;
			}
			
			// TGMLV�㏸��statBlock�Ɉړ]���܂���#1.60c7i8
			if(ending[player] == 0) {
				// �u���b�N�𒅏��������� #1.60c7i2
				bdowncnt[player]++;	
				st_bdowncnt[player]++;
				if((gameMode[player] == 3) && (devil_nextrise[player] >= 0) && (devil_randrise)) {
					devil_nextrise[player]--;
				}
			}
			
			// �G���f�B���O���̉ԉΔ��� #1.60c7s8
			if( (ending[player] == 2) && (gameMode[player] == 0) && (repversw <= 37)) {
				hanabi_total[player]++;
				hanabi_waiting[player]++;
			}
			// ACE�J�X�^����IRS
			if((ace_irs == 2) && (repversw >= 35)) doIRS2plus(player);
			// �u���b�N�������f�ɂ��1�t���Z�k #1.60c7k8
			if ((blockEraseJudge(player)) || (repversw < 9)) {
				stat[player] = 8;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
				statc[player * 10 + 6] = 0;
				//�X�e�[�^�X�ύX�Ɠ����Ɏ��̃X�e�[�^�X�֐������s���鎖��1�t���Z�k�@C7V2.1
				if(repversw >= 54) statEraseBlock(player);
			} else {
				stat[player] = 6;
				statc[player * 10] = wait1[player];
				statc[player * 10 + 1] = 15;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
				statc[player * 10 + 6] = 0;

				cmbpts[player] = 0;
				combo[player] = 0;
				combo2[player] = 0;
				hanabi_combo[player] = 0;
				hebocombo[player] = 0;
				scrate[player] = 100;//ori���[�h�p�̃X�R�A���[�g
				pinchCheck(player);
				//�X�e�[�^�X�ύX�Ɠ����Ɏ��̃X�e�[�^�X�֐������s���鎖��1�t���Z�k�@C7V2.1
				if(repversw >= 54) statErase(player);
			}

			return;
		}
	}

	effect(player);
}
