int		blkDataX[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂w�ʒu(7���/ 4�p�x/ 4�u���b�N)
{
	0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, 		2, 2, 2, 2,
	1, 0, 0, 2, 		1, 0, 1, 1, 		1, 2, 2, 0, 		1, 2, 1, 1,
	1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2, 		1, 1, 2, 2,
	1, 0, 1, 2, 		2, 2, 1, 1, 		1, 2, 1, 0, 		1, 1, 2, 2,
	1, 0, 1, 2, 		1, 1, 0, 1, 		1, 2, 1, 0, 		1, 1, 2, 1,
	1, 0, 2, 2, 		1, 1, 1, 0, 		1, 2, 0, 0, 		1, 1, 1, 2,
	1, 2, 1, 0, 		1, 1, 0, 0, 		1, 0, 1, 2, 		0, 0, 1, 1,
};

int		blkDataY[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂x�ʒu(7���/ 4�p�x/ 4�u���b�N)
{
	1, 1, 1, 1, 		0, 1, 2, 3, 		1, 1, 1, 1, 		3, 2, 1, 0,
	1, 2, 1, 1, 		1, 0, 0, 2, 		2, 1, 2, 2, 		1, 2, 2, 0,
	1, 1, 2, 2, 		1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2,
	1, 1, 2, 2, 		1, 0, 1, 2, 		2, 2, 1, 1, 		1, 2, 1, 0,
	1, 1, 2, 1, 		1, 0, 1, 2, 		2, 2, 1, 2, 		1, 2, 1, 0,
	1, 1, 1, 2, 		1, 0, 2, 2, 		2, 2, 2, 1, 		1, 2, 0, 0,
	1, 1, 2, 2, 		1, 2, 1, 0, 		2, 2, 1, 1, 		1, 0, 1, 2,
};

// �N���V�b�N���[���̐F #1.60c7j1
// 9�F���ƁAccol[9]���s���Ȓl�ɂȂ��Ă���̂�10�F�ɏC��#1.60c7k6
//int	ccol[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int	ccol[7] = {1,2,3,4,5,6,7};

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.05 - �u���b�N�ړ���
//  �����̕ӂ̑��암���ȊO���C������ꍇ�́Aworld.c���C�����Ă��������B
//������������������������������������������������������������������������������
void statCMove(int player) {
	int		i, bak, bottom, move, don, flash, kosa, rolling,k,synchro,lockT, fsmooth;

	fsmooth = 0;
	don = 0;
	synchro = 0;
	hiddenProc(player);

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

		// Hold
		if(repversw < 35){
			doHold(player, 0);
			// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂� #1.60c7m2
			if(stat[player] == 7) return;
		}
		
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
			move = (getPushState(player, 5) || rolling) - (getPushState(player, 4) || getPushState(player, 6));
		if((move) && (isrotatelock[player] == 0)) {
			bak = (rt[player] + move);
				if(istrance[player]){
					do{
						k = rand(7,player);
						setNextBlockColors(player, 1);
					}while(k == blk[player]);
				}else{
					k = blk[player];
				}
			if(bak < 0) bak = 3;
			if(bak > 3) bak = 0;

			if(judgeBlock(player, bx[player], by[player], k, bak) == 0) {
				// �n�`�ɏd�Ȃ炸�ɉ�]�ł���ꍇ
				if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = ccol[k];
				
				// ��]��������+1 #1.60c7s6
				statc[player * 10 + 5]++;
				
				// T-SPIN�����l�� #1.60c7n6
				if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
					if((blk[player] == 4)&&(tspin_type >0) ) tspin_flag[player] = 1;
				}
			} else if( (blk[player] != 0) && (!disable_wallkick) && (heboGB[player]==0) ) {	// �u���b�N���_�ȊO�̂Ƃ�
				// ��]�ł��Ȃ��Ƃ��́A���E�ɓ������Ă݂悤
				move = 0;
				
				// BIG�̏ꍇ��2�}�X�����ׂ� #1.60c7o9
				for(i = 0; i <= IsBig[player]; i++) {
					// �d�Ȃ��Ă��镔�����^���̗񂾂��ł͂Ȃ����
					if( judgeBlockRotate(player, bx[player], by[player], k, bak) )
					{
						if(judgeBlock(player, bx[player] - 1 - i, by[player], k, bak) == 0)
							move = -1 -i;
						if(judgeBlock(player, bx[player] + 1 + i, by[player], k, bak) == 0)
							move = 1 + i;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
							bx[player] = bx[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = ccol[k];
							
							// ��]��������+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							// T-SPIN�����l�� #1.60c7n6
							if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
								if((blk[player] == 4)&&(tspin_type >0) ) tspin_flag[player] = 1;
							}
							break;
						// Ti�����F���R�� ���R���1�񂾂��\ #1.60c3
						} else if((blk[player] == 4) && (rots[player] == 1) && (kickc[player] == 0)) {
							if((bak == 2) && (judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)) {
								if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
								by[player] = by[player] -1 -i;
								rt[player] = bak;
								blk[player] = k;
								synchro = 1;
								if(istrance[player])
									c_cblk_r[player] = wcol[k];
								
								// ��]��������+1 #1.60c7s6
								statc[player * 10 + 5]++;
								
								kickc[player]++;
								
								// T-SPIN�����l�� #1.60c7n6
								if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
									if((blk[player] == 4)&&(tspin_type >0) ) tspin_flag[player] = 1;
								}
								break;
							}
						}
					}
				}
			} else if((!disable_wallkick) && (heboGB[player]==0)) {
				// Ti���ԕǥ���R�� (�Ƃ肠�������R��͏c�A�ǏR��͉��ɂȂ鎞����) #1.60c3
				if(rots[player] == 1) {
					move = 0;
					// BIG�̏ꍇ��4�}�X�����ׂ� #1.60c7m6
					for(i = 0; i <= IsBig[player] * 3; i++) {
						if((bak == 0) || (bak == 2)) {	// ���ɂȂ鎞
							if(judgeBlock(player, bx[player] -1 -i, by[player], k, bak) == 0)
								move = -1 -i;
							else if(judgeBlock(player, bx[player] + 1 +i, by[player], k, bak) == 0)
								move = 1 + i;
							else if(judgeBlock(player, bx[player] + 2 +i, by[player], k, bak) == 0)
								move = 2 + i;
							
							if(move) {
								if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
								bx[player] = bx[player] + move;
								rt[player] = bak;
								blk[player] = k;
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

		// ���E�Ɉړ�
		move = getPressState(player, 3) - getPressState(player, 2);
		if(isLRreverse[player]) move = 0 - move;
		if(move && (statc[player * 10 + 4])) {
			if((block_spectrum) && (heboGB[player]==0))
			{
				/* �X���[�Y���̕\���ُ���C�� via C++ Port */
				if ( smooth && (sp[player] < 60) )
				{
					// drawCBlock (player, blk[player] + 1, 5, bs[player] * 8 / 60, 0, 1);
				}
				else
				{
					drawCBlock (player, blk[player] + 1, 5, 0, 0, 1);
				}
			}
			// BIG���A2�}�X�P�ʃ��[�h�̏ꍇ�͈ړ��ʂ�2�{���� #1.60c7m6
			if(IsBig[player] && BigMove[player]) move = move * 2;
			
			if((mpc[player] == 1) || (mpc[player] >= waitt[player]) || ((isremote[player]) && (gameMode[player] != 4)))
				if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					bx[player] = bx[player] + move;
					if(movesound) PlaySE(5);
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
		if((!move) && getPressState(player, 1-(1*(isUDreverse[player]))) && (sp[player] < 60) && (!down_flag[player]) && ((statc[player * 10 + 4]) || (repversw < 27))) {
			bs[player] = 61;
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
			// �����ꑦ�ڒ� #1.60c7k8
			if((getPressState(player, 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
						&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown))
				if (repversw < 9)
					bk[player] = bk[player] + 8;
				else 
					bk[player] = 100;
			
			// �Œ�
			if(bk[player] > lockT) {
				if(heboGB[player]==0)
					PlaySE(3);
				else if(heboGB[player] == 1)
					PlaySE(1);
				kickc[player] = 0;	// �i�v���R��h�~�p #1.60c3 
				statc[player * 10 + 2]++;
				drawCBlock(player, 0, 0, 0, 10, 0);
				// �����ꐧ��#1.60c7f9
				if((getPressState(player, 1)) && (downtype) && (!move || nanamedown)) down_flag[player] = 1;
				if(repversw >= 57) goto lockflash;	// SUPER��SKIP
				return;
			}
		} else {
			// T.L.S. (Temporary Landing System)  (c)1998 AR��KA(^^;
			// �ʊ֐��ɓƗ� #1.60c7k4
			drawTLSBlock(player, bottom);
			

			// ��L�[�ň�u�ŗ���
			// ����ꐧ���ǉ� #1.60c7p1
			if(getPressState(player, 0+(1*(isUDreverse[player]))) && (!move) && (!sonicdrop) && (!up_flag[player]) && (heboGB[player]==0) && ((statc[player * 10 + 4]) || (repversw < 27))) {
				if((sp[player] <= 240) && (!ending[player])) {
					if(gameMode[player]==10){
						sc[player] = sc[player] + ( bottom - by[player] - 1 ) * 23 / 20;
					}else if((gameMode[player]>=9)||((gameMode[player]==6)&&(anothermode[player]==4))||((gameMode[player]==7)&&(anothermode[player]==3))){
						sc[player] =sc[player]+ (bottom -by[player] -1) *2;//������
					}else{
						sdrop[player] = (bottom -by[player] -1) *2;//��Usdrop�֓����
					}
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
				bs[player] = 0;
				bk[player] = 0;
				if(!smooth) don = 1;
				if((downtype) && (repversw < 54)) up_flag[player] = 1;
				statc[player * 10 + 5] = 0;	// ��]�����������Z�b�g #1.60c7s6
			}
		}		
		
		// �u���b�N��������
		while(bs[player] > 60) {
			bk[player] = 0;
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
				
				// ���L�[�ő��Œ� #1.60c7r3
				if((getPressState(player, 1-(1*(isUDreverse[player])))) && (!down_flag[player]) && (repversw >= 15) 
							&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)) {
					PlaySE(1);
					if(heboGB[player]==0)
						PlaySE(3);
					kickc[player] = 0;
					statc[player * 10 + 2]++;
					drawCBlock(player, 0, 0, 0, 10, 0);
					if(downtype) down_flag[player] = 1;	// �����ꐧ��
					if(repversw >= 57) goto lockflash;	// SUPER��SKIP
					return;
				}
			} else {
				// ��]�����������Z�b�g #1.60c7s6
				statc[player * 10 + 5] = 0;
			}
		}

		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]
		
		if((don) && (heboGB[player]!=1)) PlaySE(1);

		// �u���b�N��`��
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		kosa = bk[player] * 7 / (lockT + (lockT == 0));
		if(kosa > 6) kosa = 6;
		if(smooth && (sp[player] < 60))
			drawCBlock(player, blk[player] + 1, kosa, bs[player] * 8 / 60, flash, 0);
		else
			drawCBlock(player, blk[player] + 1, kosa, 0, flash, 0);

		// Hold
		if((repversw >= 35) && (repversw < 64) && (!statc[player * 10 + 2]) && (!statc[player * 10 + 6])){
			doHold(player, 0);
			// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂� #1.60c7m2
			if(stat[player] == 7) return;
		}
		
		statc[player * 10 + 6] = 0;
		if((repversw >= 59) && (statc[player * 10 + 2] != 0)) goto lockflash;	// SUPER��SKIP
	} else {
		lockflash:
		statc[player * 10 + 2]++;
		if((c_nblk[0 + player * 6] != 8) && (c_nblk[0 + player * 6] >= 0))drawCBlock (player, 0, 0, 0, 10, 0);
		
		// ���𗣂��Ă���ꍇ�A�����ꐧ������#1.60c7n6
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) && (repversw >= 10)) down_flag[player] = 0;
		else if((downtype) && (repversw >= 54)) down_flag[player] = 1;
		if(!getPressState(player, 0+(1*(isUDreverse[player])))) up_flag[player] = 0;
		else if((downtype) && (repversw >= 54)) up_flag[player] = 1;
		
		if(statc[player * 10 + 2] > 2 - (repversw >= 9)) {	// �ڒ����̊D�F����1�t���Z�k #1.60c7k8
			setBlock(player, bx[player], by[player], blk[player], rt[player]);
			if(stat[player] == 7) return;
			
			ndelay[player] = 1;
			
			lc[player]++;
			
			// T-SPIN�l�� #1.60c7s6
			//���ł�tspin_flag�͗����Ă�
			if((tspin_flag[player]) && (blk[player] == 4) && ((tspin_type>=2) || (gameMode[player] == 8)) && (statc[player * 10 + 5] > 0) && (isTSpin(player) >= 3) ) {
				PlaySE(34);
				tspin_c[player] = 120;
				last_tspin[player] = 0;
				tspin_flag[player] = 2;//3�R�[�i�[��T-spin
			} else if((tspin_type==2) || (gameMode[player] == 8)){
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
				statc[player * 10 + 3] = 2;
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

/* �ǏR��ł��邩����i���������d�Ȃ�ꍇ�͉�]�s�j */
// �߂�l��-1�̂Ƃ��͏R���
int judgeBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int		i, xx, bx2, by2;
	
	if(IsBig[player]) {
		// BIG�̏ꍇ�͐�p�̔��菈�����s�� #1.60c7m6
		return judgeBigBlockRotate(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		xx = blkDataX[kind * 16 + rotate * 4 + i];
		bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + i]);
		by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i]);
		
		// �����łȂ��ꍇ�͏d�Ȃ��Ă��邩����
		if(xx != 1) {
			if( ((bx2 < 0) || (bx2 >= fldsizew[player]) || (by2 > fldsizeh[player]))
			 || ((fld[bx2 + by2 * fldsizew[player] + player * 210] != 0) && (by2 >= 0)) ) {
				return -1;
			}
		}
	}

	return 0;
}

/* BIG�p�ǏR�蔻�� #1.60c7m6 */
// �߂�l��-1�̂Ƃ��͏R���
int judgeBigBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2, xx;
	int		k, l, bx3, by3;
	
	for(i = 0; i < 4; i++) {
		xx = blkDataX[kind * 16 + rotate * 4 + i];
		bx2 = (bx1 + xx * 2);
		by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i] * 2);
		
		// �����łȂ��ꍇ
		if( xx != 1 ) {
			/* 4�u���b�N�����ׂ� */
			for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
				bx3 = bx2 + k;
				by3 = by2 + l;
				
				if( ((bx3 < 0) || (bx3 >= fldsizew[player]) || (by3 > fldsizeh[player])) || 
				    ((fld[bx3 + by3 * fldsizew[player] + player * 210] != 0) && (by3 >= 0)) ) {
					return -1;
				}
			}
		}
	}

	return 0;
}
