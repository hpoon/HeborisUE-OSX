// �V���O����Ή� & �G���f�B���O���Ɂ������������Ă��_�𑝉������Ȃ�#1.60c6.1a
// �ڒ�99, Big�Ή��@#1.60c7
/*
world��]�@������

��:�E��]  ������]
L:  �O      �P      �Q      �R        J:  �O      �P      �Q      �R
��������������������������������      ��������������������������������
������  ������  ������  ������        ������  ������  ������  ������
��������������������������������      ��������������������������������

S:  �O      �P      �Q      �R        Z:  �O      �P      �Q      �R
��������������������������������      ��������������������������������
������  ������  ������  ������        ������  ������  ������  ������
��������������������������������      ��������������������������������

T:  �O      �P      �Q      �R        ��:TTC�����͂���Ȃ񂾂�������?
��������������������������������      ��������������������������������
������  ������  ������  ������        ������  ������  ������  ������
��������������������������������      ��������������������������������

I:    �O        �P        �Q        �R
��������  ��������  ��������  ��������
����������������������������������������
����������������������������������������
��������  ��������  ��������  ��������

��]�␳(I�ȊO����)
0>>1:(-1, 0)>(-1, -1)>(0, +2)>(-1, +2)  0>>3:(+1, 0)>(+1, -1)>(0, +2)>(+1, +2)
1>>2:(+1, 0)>(+1, +1)>(0, -2)>(+1, -2)  3>>2:(-1, 0)>(-1, +1)>(0, -2)>(-1, -2)
2>>3:(+1, 0)>(+1, -1)>(0, +2)>(+1, +2)  2>>1:(-1, 0)>(-1, -1)>(0, +2)>(-1, +2)
3>>0:(-1, 0)>(-1, +1)>(0, -2)>(-1, -2)  1>>0:(+1, 0)>(+1, +1)>(0, -2)>(+1, -2)
a>>b�Ƃ����
a==1: (+1, 0)>(+1, +1)>(0, -2)>(+1, -2)
a==3: (-1, 0)>(-1, +1)>(0, -2)>(-1, -2)
b==1: (-1, 0)>(-1, -1)>(0, +2)>(-1, +2)
b==3: (+1, 0)>(+1, -1)>(0, +2)>(+1, +2)

I�̂�
0>>1:(-2, 0)>(+1, 0)>(+1, -2)            0>>3:(+2, 0)>(-1, 0)>(-1, -2)		5/14�C��
1>>2:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)   3>>2:(+1, 0)>(-2, 0)>(+1, -2)>(-2, +1)
2>>3:(-1, 0)>(+2, 0)>(+2, -1)            2>>1:(+1, 0)>(-2, 0)>(-2, -1)
3>>0:(+1, 0)>(-2, 0)>(-2, -1)>(+1, +2)   1>>0:(-1, 0)>(+2, 0)>(+2, -1)>(-1, +2)

0>>1:(+1, 0)>(-2, 0)>(+1, -2)
0>>3:(-1, 0)>(+2, 0)>(-1, -2)
�̕���������₷�����v���C���₷�����c
*/

int	blkWDataX[7 * 4 * 4] =	// world�^�C�v�~�m ����X�ʒu
{
	0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, 		1, 1, 1, 1, // I
	2, 2, 1, 0, 		2, 1, 1, 1, 		0, 0, 1, 2, 		0, 1, 1, 1, // L
	1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2, 		1, 1, 2, 2, // ��
	0, 1, 1, 2, 		2, 2, 1, 1, 		2, 1, 1, 0, 		0, 0, 1, 1, // Z
	1, 0, 1, 2, 		2, 1, 1, 1, 		1, 2, 1, 0, 		0, 1, 1, 1, // T
	0, 0, 1, 2, 		2, 1, 1, 1, 		2, 2, 1, 0, 		0, 1, 1, 1, // J
	2, 1, 1, 0, 		2, 2, 1, 1, 		0, 1, 1, 2, 		0, 0, 1, 1, // S
};

int	blkWDataY[7 * 4 * 4] =	// world�^�C�v�~�m ����Y�ʒu
{
	1, 1, 1, 1, 		0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, // I
	0, 1, 1, 1, 		2, 2, 1, 0, 		2, 1, 1, 1, 		0, 0, 1, 2, // L
	0, 0, 1, 1, 		0, 1, 1, 0, 		1, 1, 0, 0, 		1, 0, 0, 1, // ��
	0, 0, 1, 1, 		0, 1, 1, 2, 		2, 2, 1, 1, 		2, 1, 1, 0, // Z
	0, 1, 1, 1, 		1, 0, 1, 2, 		2, 1, 1, 1, 		1, 2, 1, 0, // T
	0, 1, 1, 1, 		0, 0, 1, 2, 		2, 1, 1, 1, 		2, 2, 1, 0, // J
	0, 0, 1, 1, 		2, 1, 1, 0, 		2, 2, 1, 1, 		0, 1, 1, 2, // S
};

// 9�F���ƁAwcol[9]���s���Ȓl�ɂȂ��Ă���̂�10�F�ɏC��#1.60c7k6
// ���ꂪ[]���Ԃɉ����錴���������킯����
//int	wcol[20] = {0, 5, 2, 3, 1, 7, 6, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int	wcol[7] = {5,2,3,1,7,6,4};

/*
0>>3:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)  0>>1:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)
3>>2:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)  1>>2:(+2, 0)>(-1, 0)>(-1, -2)>(+2, +1)
2>>1:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +1)  2>>3:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +1)
1>>0:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +2)  3>>0:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +2)
*/

// I�^�u���b�N�ǏR��e�[�u���i4���~4�����~2��]�~2�␳���W�j
/*
int iBlockKickTable[4 * 4 * 2 * 2] = {
	// ����]
	-1, 0,		 2, 0,		-1, -2,		 2, 1,		// 0>>3
	 2, 0,		-1, 0,		 2, -1,		-1, 2,		// 1>>0
	-2, 0,		 1, 0,		-2, -1,		 1, 1,		// 2>>1
	-2, 0,		 1, 0,		 1, -2,		-2, 1,		// 3>>2

	// �E��]
	-2, 0,		 1, 0,		 1, -2,		-2, 1,		// 0>>1
	 2, 0,		-1, 0,		-1, -2,		 2, 1,		// 1>>2
	 2, 0,		-1, 0,		 2, -1,		-1, 1,		// 2>>3
	-2, 0,		 1, 0,		-2, -1,		 1, 2		// 3>>0
};
*/

// ����]�̏ꍇ�́A�_����ւ����۔�����ق����D��
// �E��]�̏ꍇ�́A�_�����Ɏ��܂�ق����D��
int iBlockKickTable[4 * 4 * 2 * 2] = {
	// ����]
	-1, 0,		 2, 0,		-1, -2,		 2, 1,		// 0>>3
	 2, 0,		-1, 0,		 2, -1,		-1, 2,		// 1>>0
	-2, 0,		 1, 0,		-2, -1,		 1, 1,		// 2>>1
	-2, 0,		 1, 0,		 1, -2,		-2, 1,		// 3>>2

	// �E��]
	-2, 0,		 1, 0,		-2, 1,		 1, -2,		// 0>>1
	 2, 0,		-1, 0,		 2, 1,		-1, -2,		// 1>>2
	 2, 0,		-1, 0,		-1, 1,		 2, -1,		// 2>>3
	-2, 0,		 1, 0,		 1, 2,		-2, -1		// 3>>0
};
// SRS-X��p�@180�x��]�ǏR��e�[�u���iI�ȊO�j
// �����ԍ���2��180����]����Ό��̈ʒu�ɖ߂�i��������Ȃ��j���A
// ��ԍ��͉��ւ̕␳���D�悳���i��������Ȃ��j
int otherBlock180KickTable[11 * 2 * 4] ={
	 1, 0,   2, 0,   1, 1,   2, 1,  -1, 0,  -2, 0,  -1, 1,  -2, 1,   0,-1,   3, 0,  -3, 0,		// 0>>2����
	 0, 1,   0, 2,  -1, 1,  -1, 2,   0,-1,   0,-2,  -1,-1,  -1,-2,   1, 0,   0, 3,   0,-3,		// 1>>3������
	-1, 0,  -2, 0,  -1,-1,  -2,-1,   1, 0,   2, 0,   1,-1,   2,-1,   0, 1,  -3, 0,   3, 0,		// 2>>0������
	 0, 1,   0, 2,   1, 1,   1, 2,   0,-1,   0,-2,   1,-1,   1,-2,  -1, 0,   0, 3,   0,-3		// 3>>1������
};

// SRS-X��p�@180�x��]�ǏR��e�[�u���iI�j
// ��������ł͋��ق̕ǔ�΂��A�ǔ������\ww
int iBlock180KickTable[11 * 2 * 4] ={
	 -1, 0,  -2, 0,   1, 0,   2, 0,   0, 1,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  0, 1,   0, 2,   0,-1,   0,-2,  -1, 0,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  1, 0,   2, 0,  -1, 0,  -2, 0,   0,-1,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  0, 1,   0, 2,   0,-1,   0,-2,   1, 0,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0
};
// player: �v���C���[�ԍ�
// kickm : �ڒn��Ԃňړ��ł����
// kickr : �ڒn��Ԃŉ�]�ł����
void statWMove(int player, int kickm, int kickr) {
	int		bak, bottom, move, don, flash, kosa, rolling ,synchro,landing, fsmooth;
	int		mx, my, sx[11], sy[11], i, k, l;
	int		j,lockT;

	fsmooth = 0;
	don = 0;
	synchro = 0;
	landing = 0;
	if((repversw >= 35) && (kickm != -1)) kickm++;
	hiddenProc (player);

	if(!statc[player * 10 + 2]) {
		padRepeat (player);
		
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

		// ��]
		// ��]�����t�]�ݒ�Ή�#1.60c7f8
		if((statc[player * 10 + 6] != 0) && (repversw >= 59))
			move = 0;
		else if(w_reverse)
			move = (getPushState(player , 4) || getPushState(player , 6) || rolling) - (getPushState(player , 5));
		else
			move = (getPushState(player , 5) || rolling) - (getPushState(player , 4) || getPushState(player , 6));
		if((rots[player] == 7) && (getPushState(player , 6) != 0) && (repversw >= 23) && (statc[player * 10 + 6] == 0)) move = 2;
		if((move != 0 ) && (isrotatelock[player] == 0)) {
				bak = (rt[player] + move);
				if(istrance[player]){
					do{
						k = rand(7,player);
						setNextBlockColors(player, 1);
					}while(k == blk[player]);
				}else{
					k = blk[player];
				}
				mx = 0; my = 0;
			if(move < 2){
				if(bak < 0) bak = 3;
				if(bak > 3) bak = 0;
			}else{
				if(bak > 3) bak = bak - 4;
				if(bak < 0) bak = bak + 4;
			}
			if((repversw >= 35) && (judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) landing = 1;
			if(judgeBlock (player, bx[player], by[player], k, bak) == 0) {
				if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = wcol[k];
				
				// ��]��������+1 #1.60c7s6
				statc[player * 10 + 5]++;
			} else if((!disable_wallkick) && (heboGB[player]==0)) {	// ���Ȃ�������
				if(move == 2){	// SRS-X 180����]�̎�
//					j = (move > 0) * 88;
					if(blk[player] != 0){
						for(i = 0; i < 11; i++) {
							sx[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
							sy[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1 ];
						}
					}else {
						for(i = 0; i < 11; i++) {
							sx[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
							sy[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1 ];
						}
					}
				}else if(blk[player] != 0) {	//	I�ȊO�̎�
					/*
					1>>0, 2: (+1, 0)>(+1, +1)>(0, -2)>(+1, -2)
					3>>0, 2: (-1, 0)>(-1, +1)>(0, -2)>(-1, -2)
					0, 2>>1: (-1, 0)>(-1, -1)>(0, +2)>(-1, +2)
					0, 2>>3: (+1, 0)>(+1, -1)>(0, +2)>(+1, +2)
					*/
					sx[0] = co(((rt[player]==1)||(bak==3)), 1, -1);
					sy[0] = 0;
					sx[1] = sx[0];
					sy[1] = co(rt[player]%2, 1, -1);
					sx[2] = 0;
					sy[2] = sy[1]*(-2);
					sx[3] = sx[0];
					sy[3] = sy[2];
				} else {		//	I�̎�
					if(world_i_rot) {
						/*
						�񍶉E�Ώ̃o�[�W���� #1.60c7r7
						
						����]                                  �E��]
						0>>3:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)  0>>1:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)
						3>>2:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)  1>>2:(+2, 0)>(-1, 0)>(-1, -2)>(+2, +1)
						2>>1:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +1)  2>>3:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +1)
						1>>0:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +2)  3>>0:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +2)
						*/
						
						j = (move > 0) * 32;
						
						for(i = 0; i < 4; i++) {
							sx[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + j ];
							sy[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + j + 1 ];
							
							//sprintf(string[0], "move:%d no:%d rt:%d sx:%d sy:%d", move, i, rt[player], sx[i], sy[i]);
							//InnerLogMes(string[0]);
						}
					} else {
						/*
						0>>1:(-2, 0)>(+1, 0)>(+1, -2)>(,)         2>>3:(-1, 0)>(+2, 0)>(+2, -1)>(,)
						2>>1:(+1, 0)>(-2, 0)>(-2, -1)>(,)         0>>3:(+2, 0)>(-1, 0)>(-1, -2)>(,)
						1>>2:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)    3>>2:(+1, 0)>(-2, 0)>(+1, -2)>(-2, +1)
						1>>0:(-1, 0)>(+2, 0)>(+2, -1)>(-1, +2)    3>>0:(+1, 0)>(-2, 0)>(-2, -1)>(+1, +2)
						*/
						sx[0] = co(((rt[player]==3)||(bak == 1)), 1, -1);
						sy[0] = 0;
						sx[1] = sx[0]*(-2);
						sy[1] = 0;
						sx[2] = co((rt[player]+bak==3), co(sx[0]==1, -2, -1), co(sx[0]==1, 1, 2));
						sy[2] = co(sx[2]%2, -2, -1);
						sx[3] = (rt[player]%2)*co(bak, sx[0], sx[1]);
						sy[3] = (rt[player]%2)*co(bak, 1, 2);
						if(rt[player] == 0) {		// ���0����̉�]�������C��
							i = sx[0]; sx[0] = sx[1]; sx[1] = i;
						}
					}
				}
				
				// BIG�ł͕␳�ʂ�2�{���� #1.60c7m6
				if(IsBig[player]) {
					for(i = 0; i < 4+(7*((move == 2) && (repversw >= 48))); i++) {
						sx[i] = sx[i] * 2;
						sy[i] = sy[i] * 2;
					}
				}
				
				for(i = 0; i < 4+(7*(move == 2)); i++) {
					if(judgeBlock (player, bx[player]+sx[i], by[player]+sy[i], k, bak) == 0) {
						mx = sx[i];
						my = sy[i];
						break;
					}
				}
			}

			if(mx || my) {
				if(rotate_snd) {
					PlaySE(4);	// ��]���ݒ�#1.60c7f7
				}
				if(move == 2) PlaySE(0);
				bx[player] = bx[player] + mx;
				by[player] = by[player] + my;
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = wcol[k];
				
				// ��]��������+1 #1.60c7s6
				statc[player * 10 + 5]++;
			}
			l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
			if((rt[player] == bak) && ((l != 0) || ((landing) && (repversw >= 35))) && (heboGB[player]==0)) {
				if(repversw < 40) kickc[player]++;	// �ڒn������Ԃł̉�]�񐔂��J�E���g
				else kickc3[player]++;
				if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
					PlaySE(1);
				if((((kickc[player] < kickm) || (kickm == -1)) && (repversw < 40)) || (kickc3[player] < kickr) || (kickr == -1)) {
					bk[player] = 0;		// �Œ莞�ԃ��Z�b�g
				}
				// T-SPIN�����l�� #1.60c7n6
				if((blk[player] == 4 )&&(tspin_type >0)) tspin_flag[player] = 1;
			}
		}

		//	���E�Ɉړ�
				move = getPressState(player , 3) - getPressState(player , 2);
		if(isLRreverse[player]) move = 0 - move;
		if( move && (statc[player * 10 + 4] != 0) ) {
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
			if((repversw >= 35) && (judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) landing = 1;
			if((mpc[player] == 1) || (mpc[player] >= waitt[player]) || ( (rots[player] == 6) && (mpc[player] >= 10 - (repversw >= 64)) && (repversw >= 19) ) || ((isremote[player])&&(gameMode[player] != 4)))
				if(judgeBlock (player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					bx[player] = bx[player] + move;
					if(movesound) PlaySE(5);	// �ړ����ݒ肪���f����Ȃ��̂��C��#1.60c7f7
					l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
					if(((l != 0) || ((landing) && (repversw >= 35))) && (heboGB[player]==0)) {	// ���ړ��ł��Œ莞�ԃ��Z�b�g
						if((!synchro) || (repversw < 35)) kickc[player]++;
						if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
							PlaySE(1);
						if((kickc[player] < kickm) || (kickm == -1)) {
							bk[player] = 0;
						}
					}
					if(!synchro) tspin_flag[player] = 0;	// �V���N���łȂ��Ȃ�T-SPIN�������D #1.60c7n6
				}
		}
		synchro = 0;

//		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]

		if(!nanameallow) move = 0;

		//	���𗣂��Ă���A�܂���downtype��0�̏ꍇ�A�����ꐧ������#1.60c7f9
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) || (!downtype)) down_flag[player] = 0;
		if((!getPressState(player, 0+(1*(isUDreverse[player])))) || (!downtype) || (repversw < 12)) up_flag[player] = 0;
		
		//	��������!! ���������#1.60c7f9
		if((!move) && getPressState(player , 1-(1*(isUDreverse[player]))) && ((sp[player] < 60) || ((rots[player] == 7) && (repversw >= 44))) && (!down_flag[player]) && ((statc[player * 10 + 4]) || (repversw < 27))) {
			if((heboGB[player])&& (repversw >= 52)){
				bs[player] = bs[player] + 20;//1/3G
			}else if(((rots[player] == 3) || (rots[player] == 6)) && (repversw >= 20)){
				bs[player] = bs[player] + 30;		//ACE-SRS��DS-WORLD�̍���������x��
			}else{
				if((rots[player] == 7) && (repversw >= 44)) bs[player] = bs[player] + 90;
				else bs[player] = 61;
			}
			if((gameMode[player]>=9)||((gameMode[player]==6)&&(anothermode[player]==4))||((gameMode[player]==7)&&(anothermode[player]==3))){
					sc[player]++;//������
			}else{
				qdrop[player]++;	//�x�����̃h���b�v�{�[�i�X�����́A�X�R�A�v�Z����
			}
		}
		
		if((ismagnetblock[player]) && (repversw >= 41)) bs[player] = bs[player] + 30;

		for(bottom = by[player]; judgeBlock (player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);

		//	�n�ʂɂ�������
		if((judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) {

			if((ismagnetblock[player] == 1) || ((kickc[player] >= kickm) && (kickm != -1) && (rots[player] != 6) && (repversw >= 30)) ||
			((kickc3[player] >= kickr) && (kickr != -1) && (rots[player] != 6)))
				bk[player] = 100;
				
			bs[player] = 0;
			if((bk[player] == 0) && (smooth)) don = 1;

			if(lockT != 99) // �ڒ�99�����@#1.60c7
				bk[player]++;
			else
				bk[player] = 98;

			// ���������#1.60c7f9
			if((getPressState(player , 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
						&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown))
				if((rots[player] == 7) || (heboGB[player]!=0))	// SRS-X���ڒ�
					bk[player] = 100;
				else
					bk[player] = bk[player] + 1 + ((rots[player] == 2) && (repversw >= 30) && (!nanamedown));
			
			// ����ꑦ�ڒ�
			if( ( (getPressState(player , 0+(1*(isUDreverse[player]))) && (repversw >= 43)) ||
				  (getPushState(player , 0+(1*(isUDreverse[player]))) && (repversw < 43)) )
				 && (rots[player] != 7) && ( (repversw <= 13) || !up_flag[player] ) && (heboGB[player]==0) 
				 && (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)) {
				bk[player] = bk[player] + lockT;
				if((rots[player] == 3) || (rots[player] == 6))	//ACE-SRS�͐�p��SE��炷
					PlaySE(44);
				
				// ����ꐧ���ǉ� #1.60c7q8
				if( downtype && (repversw >= 14) && (repversw < 54)) up_flag[player] = 1;
			}
			
			if((bk[player] > lockT) || ((kickc[player] > kickm) && (kickm != -1)) || ((kickc3[player] > kickr) && (kickr != -1))) {
				if(heboGB[player]==0)
					PlaySE(3);
				else if(heboGB[player] == 1)
					PlaySE(1);
				kickc[player] = 0;
				kickc3[player] = 0;
				statc[player * 10 + 2] ++;
				drawCBlock (player, 0, 0, 0, 10, 0);
				// �����ꐧ��#1.60c7f9
				if((getPressState(player , 1-(1*(isUDreverse[player])))) && (downtype) && (!move || nanamedown)) down_flag[player] = 1;
				if((repversw >= 57) && (rots[player] != 6)) goto lockflash;	// SUPER��SKIP
				return;
			}
		} else {
			// T.L.S. (Temporary Landing System)  (c)1998 AR��KA(^^;
			// �ʊ֐��ɓƗ� #1.60c7k4
			drawTLSBlock(player, bottom);
			
			// ��L�[�ň�u�ŗ���&�Œ�
			// ����ꐧ���ǉ� #1.60c7p1
			if(getPressState(player , 0+(1*(isUDreverse[player]))) && (!move) && (!sonicdrop) && (!up_flag[player]) && (heboGB[player]==0) && ((statc[player * 10 + 4]) || (repversw < 27))) {
				if(rots[player] != 7){
					if(gameMode[player]==10){//15%
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
					if((world_drop_snd == 1) || ((world_drop_snd == 3) && (rots[player] != 2)) || (rots[player] == 3) || (rots[player] == 6)) PlaySE(1);
					PlaySE(3);
					if((rots[player] == 3) || (rots[player] == 6))	//ACE-SRS�͐�p��SE��炷
						PlaySE(44);
					kickc[player] = 0;
					kickc3[player] = 0;
					statc[player * 10 + 2] ++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					if((downtype) && (repversw < 54)) up_flag[player] = 1;
					statc[player * 10 + 5] = 0;	// ��]�����������Z�b�g #1.60c7s6
					if((repversw >= 57) && (rots[player] != 6)) goto lockflash;	// SUPER��SKIP
					return;
				}
				else {	//SRS-X
					if((sp[player] <= 240) && (!ending[player])) {
						if((gameMode[player]>=9)||((gameMode[player]==6)&&(anothermode[player]==4))||((gameMode[player]==7)&&(anothermode[player]==3))){
							sc[player] = sc[player]+(bottom -by[player] -1) *2;//������
						}else{
							sdrop[player] = (bottom -by[player] -1) *2;//��Usdrop�֓����
						}
					}
//					PlaySE(44);
					if(!block_spectrum){
						by[player] = bottom - 1;
					}else{	//�c����`��
						while(by[player] != bottom - 1){
							drawCBlock (player, blk[player] + 1, 4, 0 , 0, 1);
							by[player]++;
						}
					}
					bs[player] = 0;
					bk[player] = 0;
					if(!smooth) don = 1;
					if((downtype) && (repversw < 54)) up_flag[player] = 1;
					statc[player * 10 + 5] = 0;	// ��]�����������Z�b�g #1.60c7s6
				}
			}

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
					
					if((ismagnetblock[player] == 1) || ((kickc[player] >= kickm) && (kickm != -1) && (rots[player] != 6) && (repversw >= 30)) ||
					((kickc3[player] >= kickr) && (kickr != -1) && (rots[player] != 6)))
						bk[player] = 100;
					
					// ���L�[�ŌŒ葬�x�A�b�v #1.60c7r3
					if( getPressState(player, 1-(1*(isUDreverse[player]))) && (!down_flag[player]) && (repversw >= 15) 
							&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)) {
						if((rots[player] != 7) && (heboGB[player]==0)) bk[player] = bk[player] + 1 + ((rots[player] == 2) && (repversw >= 30) && (!nanamedown));
						else {	// SRS-X���Œ�
							PlaySE(1);
							if(heboGB[player]==0)
								PlaySE(3);
							kickc[player] = 0;
							kickc3[player] = 0;
							statc[player * 10 + 2]++;
							drawCBlock (player, 0, 0, 0, 10, 0);
							if(downtype) down_flag[player] = 1;
							if((repversw >= 57) && (rots[player] != 6)) goto lockflash;	// SUPER��SKIP
							return;
						}
					}
					
					// ����ꑦ�ڒ� #1.60c7r3
					if( ( (getPressState(player , 0+(1*(isUDreverse[player]))) && (repversw >= 43)) ||
						  (getPushState(player , 0+(1*(isUDreverse[player]))) && (repversw < 43)) )
						&& (rots[player] != 7) &&(!up_flag[player]) && (repversw >= 15) && (heboGB[player]==0) 
						&& (statc[player * 10 + 4] || (repversw < 27)) && (!move || nanamedown)) {
						PlaySE(3);
						if((rots[player] == 3) || (rots[player] == 6))	//ACE-SRS�͐�p��SE��炷
							PlaySE(44);
						kickc[player] = 0;
						kickc3[player] = 0;
						statc[player * 10 + 2]++;
						drawCBlock (player, 0, 0, 0, 10, 0);
						if(downtype) up_flag[player] = 1;
						if((repversw >= 57) && (rots[player] != 6)) goto lockflash;	// SUPER��SKIP
						if(repversw >= 57) return;
					}
				} else {
					// ��]�����������Z�b�g #1.60c7s6
					statc[player * 10 + 5] = 0;
				}
			}
		}

		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]
				
		// �ڒn����炷
		// world_drop_snd��1�̏ꍇ�̂� #1.60c7m9
		if( (don) && (world_drop_snd >= 1) && (heboGB[player]!=1) ) PlaySE(1);
			
		// �u���b�N��`��
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		kosa = bk[player] * 7 / (lockT + (lockT == 0));
		if(kosa > 6) kosa = 6;
		if(smooth && (sp[player] < 60))
			drawCBlock (player, blk[player] + 1, kosa, bs[player] * 8 / 60 , flash, 0);
		else
			drawCBlock (player, blk[player] + 1, kosa, 0 , flash, 0);
			
		if((repversw >= 35) && (repversw < 64) && (!statc[player * 10 + 2]) && (!statc[player * 10 + 6])){
			 doHold(player, 0);
			// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂� #1.60c7m2
			if(stat[player] == 7) return;
		}
		
		statc[player * 10 + 6] = 0;
		if((repversw >= 57) && (statc[player * 10 + 2] != 0)) goto lockflash;	// SUPER��SKIP
	} else {
		lockflash:
		statc[player * 10 + 2] ++;
		if((c_nblk[0 + player * 6] != 8) && (c_nblk[0 + player * 6] >= 0))drawCBlock (player, 0, 0, 0, 10, 0);
		
		// ���𗣂��Ă���ꍇ�A�����ꐧ������#1.60c7n6
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) && (repversw >= 10)) down_flag[player] = 0;
		else if((downtype) && (repversw >= 54)) down_flag[player] = 1;
		if(!getPressState(player, 0+(1*(isUDreverse[player])))) up_flag[player] = 0;
		else if((downtype) && (repversw >= 54)) up_flag[player] = 1;
		
		if(statc[player * 10 + 2] > 2 - (repversw >= 9)) {	// �ڒ����̊D�F����1�t���Z�k #1.60c7k8
			setBlock (player, bx[player], by[player], blk[player], rt[player]);
			if(stat[player] == 7) return;
			
			ndelay[player] = 1;
			
			lc[player]++;
			
			// T-SPIN�l�� #1.60c7s6
			//3-�R�[�i�[�`�F�b�N(�X���C�h�̂�͂��łɃ`�F�b�N����Ă�)
			if((tspin_flag[player]) && (blk[player] == 4) && ((tspin_type>=2) || (gameMode[player] == 8)) && (statc[player * 10 + 5] > 0) && (isTSpin(player) >= 3) ) {
				PlaySE(34);
				tspin_c[player] = 120;
				tspin_flag[player] = 2;
				last_tspin[player] = 0;
			} else if((tspin_type==2) || (gameMode[player] == 8)){
				tspin_flag[player] = 0;
			}
			
			lc[player]++;
			
			// TGMLV�㏸��statBlock�Ɉړ]���܂���#1.60c7i7
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
				statc[player * 10 + 3] = 2 * (rots[player] != 6);
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
	effect (player);
}


int	co(int a, int b, int c) {	// conditional op
	if(a) return b;
	else return c;
}
