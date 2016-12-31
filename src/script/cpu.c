//������������������������������������������������������������������������������
//  �R���s���[�^�̎v�l���[�`��
//������������������������������������������������������������������������������
// �v�l���[�`�����ňꎞ�g�p����ϐ�
int		cp_fld[10 * 22 * 2];	// ���z�t�B�[���h x + y * 10
int		cp_erase[22 * 2];

/* �u���b�N�̂����蔻�� */
int cpu_judgeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	
	if(IsBig[player]) {
		// BIG�̏ꍇ�͐�p�̔��菈�����s��
		return cpu_judgeBigBlock(player, bx1, by1, kind, rotate);
	}
	for(i = 0; i < 4; i++) {
		if(rots[player] == 8) {
			bx2 = (bx1 + blkDDataX[kind * 16 + rotate * 4 + i]);
			by2 = (by1 + blkDDataY[kind * 16 + rotate * 4 + i]);
		} else if( isWRule(player) ) {
			bx2 = (bx1 + blkWDataX[kind * 16 + rotate * 4 + i]);
			by2 = (by1 + blkWDataY[kind * 16 + rotate * 4 + i]);
		} else {
			bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + i]);
			by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i]);
		}
		if(((bx2 < 0) || (bx2 >= fldsizew[player]) ||
			(by2 > fldsizeh[player])) || ((cp_fld[bx2 + by2 * fldsizew[player] + player * 220] != 0) && (by2 >= 0))) {
			return -1;
		}
	}
	return 0;
}

/* �u���b�N��ݒu���� */
int cpu_setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2,puted;
	puted = 0;
	
	if(IsBig[player]) {
		// BIG�̏ꍇ�͐�p�̐ݒu�������s��
		return cpu_setBigBlock(player, bx1, by1, kind, rotate);
	}
	for(i = 0; i < 4; i++) {
		if(rots[player] == 8) {
			bx2 = (bx1 + blkDDataX[kind * 16 + rotate * 4 + i]);
			by2 = (by1 + blkDDataY[kind * 16 + rotate * 4 + i]);
		} else if( isWRule(player) ) {
			bx2 = (bx1 + blkWDataX[kind * 16 + rotate * 4 + i]);
			by2 = (by1 + blkWDataY[kind * 16 + rotate * 4 + i]);
		} else {
			bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + i]);
			by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i]);
		}
		if((bx2 >= 0) && (bx2 < fldsizew[player]) && (by2 >= 0+(1*((repversw <= 27) || (!spawn_y_type)))) && (by2 <= fldsizeh[player])) {
			if(by2 >= 2)puted++;
			cp_fld[bx2 + by2 * fldsizew[player] + player * 220] = c_cblk_r[player] + 1;
		}
	}
	return puted;
}

/* BIG�p�����蔻�� */
int cpu_judgeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	
	for(i = 0; i < 4; i++) {
		if(rots[player] == 8) {
			bx2 = (bx1 + blkDDataX[kind * 16 + rotate * 4 + i] * 2);
			by2 = (by1 + blkDDataY[kind * 16 + rotate * 4 + i] * 2);
		} else if( isWRule(player) ) {
			bx2 = (bx1 + blkWDataX[kind * 16 + rotate * 4 + i] * 2);
			by2 = (by1 + blkWDataY[kind * 16 + rotate * 4 + i] * 2);
		} else {
			bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + i] * 2);
			by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i] * 2);
		}
		
		/* 4�u���b�N�����ׂ� */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ((bx3 < 0) || (bx3 >= fldsizew[player]) || (by3 > fldsizeh[player])) || 
			    ((cp_fld[bx3 + by3 * fldsizew[player] + player * 220] != 0) && (by3 >= 0)) ) {
				return -1;
			}
		}
	}
	return 0;
}

/* BIG�p�ݒu���� */
int cpu_setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2,puted;
	int		k, l, bx3, by3;
	puted = 0;
	
	for(i = 0; i < 4; i++) {
		if(rots[player] == 8) {
			bx2 = (bx1 + blkDDataX[kind * 16 + rotate * 4 + i] * 2);
			by2 = (by1 + blkDDataY[kind * 16 + rotate * 4 + i] * 2);
		} else if( isWRule(player) ) {
			bx2 = (bx1 + blkWDataX[kind * 16 + rotate * 4 + i] * 2);
			by2 = (by1 + blkWDataY[kind * 16 + rotate * 4 + i] * 2);
		} else {
			bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + i] * 2);
			by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i] * 2);
		}
		/* 4�u���b�N���ݒu���� */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( (bx3 >= 0) && (bx3 < fldsizew[player]) && (by3 >= 0) && (by3 <= fldsizeh[player]) ) {
				cp_fld[bx3 + by3 * fldsizew[player]+ player * 220] = c_cblk_r[player] + 1;
				puted++;
			}
		}
	}
	return puted;
}

/* �ړI�̏ꏊ�փu���b�N���ړ������� */
void cpuMove(int player) {
	int i, slow;
	
	// �L�[���͏�����
	for(i=0;i<10;i++) {
		cp_input[i + player * 10] = 0;
	}
	
	slow = (((rots[player] == 6) || (rots[player] == 8)) && (sp[player] < 40)) * (gameMode[player] == 4);
	slow = slow + 2 * ((isfmirror[player]) || (isxray[player]) || (iscolor[player]) || (item_monochrome[player]) ||
					   (ishidenext[player]) || (isdark[player]) || (isfakenext[player]) || (ismiss[player]));
		   
	
	if(cp_rot_c[player] > 0) cp_rot_c[player]--;
	
	// �ړ�
	if( (stat[player] == 4) || (stat[player] == 5) ) {
		if(cp_hold[player]) {
			// HOLD
			if(istrance[player]) cp_input[4 + player * 10] = 1;
			else cp_input[7 + player * 10] = 1;
			cp_hold[player] = 0;
		} else if( (rt[player] != cp_rt[player]) && (blk[player] != 2) && ((!isrollroll[player]) || (sp[player] >= 30))) {
			// ��]
			cp_input[4 + player * 10] = 1;
		} else {
			// �E�ֈړ�
			if(bx[player] < cp_x[player]) {
				if(count%(2+(4*slow)) == 0)
					cp_input[3-(1*((isLRreverse[player]) && (item_timer[player] < 360))) + player * 10] = 1;
				
				// �E�ɕǂ�����
				if(judgeBlock(player, bx[player]+1, by[player], blk[player], rt[player]) != 0) {
					if((isWRule(player)) && (blk[player] != 2)){
						cp_input[5 + player * 10] = 0;
						cp_input[4 + player * 10] = 0;
						if((cp_rot_c[player] == 0) || (isrollroll[player])){
							if((blk[player] == 3) || (blk[player] == 6))
								cp_input[5 -(1*(cp_rot_c[player] > 10))+ player * 10] = 1;
							else
								cp_input[4 +(1*(cp_rot_c[player] > 10))+ player * 10] = 1;
							cp_rot_c[player] = 10;
						}
					// �u���͖̂����Ȃ̂ŗ��Ƃ�
					}else if((dhold[player] == 0) && (!item[player])){
						cp_hold[player] = 1;
					}else{
						cp_input[3 + player * 10] = 0;
						cpuDrop(player);
					}
				}else{
			//		cp_rot_c[player] = 0;
				}
			}
			// ���ֈړ�
			else if(bx[player] > cp_x[player]) {
				if(count%(2+(4*slow)) == 0)
					cp_input[2+(1*((isLRreverse[player]) && (item_timer[player] < 360))) + player * 10] = 1;
				
				// ���ɕǂ�����
				if(judgeBlock(player, bx[player]-1, by[player], blk[player], rt[player]) != 0) {
					if((isWRule(player)) && (blk[player] != 2)){
						cp_input[5 + player * 10] = 0;
						cp_input[4 + player * 10] = 0;
						if((cp_rot_c[player] == 0) || (isrollroll[player])){
							if((blk[player] == 3) || (blk[player] == 6))
								cp_input[4 -(1*(cp_rot_c[player] > 10))+ player * 10] = 1;
							else
								cp_input[5 +(1*(cp_rot_c[player] > 10))+ player * 10] = 1;
							cp_rot_c[player] = 10;
						}
					// �u���͖̂����Ȃ̂ŗ��Ƃ�
					}else if((dhold[player] == 0) && (!item[player])){
						cp_hold[player] = 1;
					}else{
						cp_input[3 + player * 10] = 0;
						cpuDrop(player);
					}
				}else{
			//		cp_rot_c[player] = 0;
				}
			}
			// �ݒu
			else if((bx[player] == cp_x[player]) && (!isrotatelock[player]) && ((rt[player] == cp_rt[player]) || (blk[player] == 2))) {
				if(istrance[player])
					cpuCheckBestSpot(player);
				if((bx[player] == cp_x[player]) && ((rt[player] == cp_rt[player]) || (blk[player] == 2))){
					cpuDrop(player);
				}
			}
		}
	}
}

void cpuDrop(int player){

	if(isUDreverse[player]){	//�㉺�t�]��
		if((sonicdrop) || (heboGB[player] == 0) && 
			((rots[player] <= 1) || (rots[player] == 5) || (rots[player] == 7))){
			if(!up_flag[player]){
				cp_input[0 + player * 10] = 0;
				cp_input[1 + player * 10] = 1;
			}
		}else{
			if(!down_flag[player]){
				cp_input[0 + player * 10] = 1;
				cp_input[1 + player * 10] = 0;
			}
		}
	}else{	// �ʏ펞
		if((!up_flag[player]) && (!sonicdrop) && (heboGB[player] == 0) && 
			((rots[player] == 2) || (rots[player] == 3) || (rots[player] == 4) || (rots[player] == 6) || (rots[player] == 8))){
			cp_input[0 + player * 10] = 1;
			cp_input[1 + player * 10] = 0;
		}else{
			if((sonicdrop) || (heboGB[player] != 0) ||  
				(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)){	// �n�ʂɂ�������
				if(!down_flag[player]){
					cp_input[0 + player * 10] = 0;
					cp_input[1 + player * 10] = 1;
				}
			}else{
				if(!up_flag[player]){
					cp_input[0 + player * 10] = 1;
					cp_input[1 + player * 10] = 0;
				}
			}
		}
	}
}

/* �u���b�N�̑����𒲂ׂ� */
int cpuBlockHowManyFilled(int player, int y) {
	int		j, ret;
	ret = 0;
	
	for(j = 0; j < fldsizew[player]; j++)
		if(cp_fld[j + y * fldsizew[player] + player * 220]) {
			ret++;
		}
	return ret;
}

// �w�肵���s�ō��[����A�����Ă���u���b�N�̐������߂�
int blockHowManyFilledFromLeft(int player, int y) {
	int		j, ret;
	ret = 0;
	
	for(j = 0; j < fldsizew[player]; j++)
		if(!cp_fld[j + y * fldsizew[player] + player * 220]) {
			break;
		} else {
			ret++;
		}
	
	return ret;
}

/* ���Ɍ��Ԃ����邩���ׂ� */
int cpuCheckFloating(int player, int x, int y) {
	int y2, y3;
	
	y2 = y + 1;
	if(y2 > fldsizeh[player]) y2 = fldsizeh[player];
	y3 = y + 2;
	if(y3 > fldsizeh[player]) y3 = fldsizeh[player];
	
	if( (!cp_fld[x + y2 * fldsizew[player] + player * 220]) || (!cp_fld[x + y3 * fldsizew[player] + player * 220]) ) {
		return -1;
	}
	
	return 0;
}
int cpuCheckFloatingE(int player, int x, int y) {
	int y2;
	
	//���̃u���b�N��������Ȃ�X���[
//	if(cp_erase[y+22*player]) return 0;
	
	y2 = y + 1;
	if(y2 > fldsizeh[player]) y2 = fldsizeh[player];
	
	if(!cp_fld[x + y2 * fldsizew[player] + player * 220]) {
		return -1;
	}
	
	return 0;
}

/* ���Ƀu���b�N���אڂ��Ă��邩���ׂ� */
int cpuCheckLeftRight(int player, int x, int y) {
	int ret, x2, x3;
	
	ret = 0;
	x2 = x + 1;
	x3 = x - 1;
	
	if( (x2 >= fldsizew[player]) || (cp_fld[x2 + y * fldsizew[player] + player * 220]) ) ret++;
	if( (x3 >= fldsizew[player]) || (cp_fld[x3 + y * fldsizew[player] + player * 220]) ) ret++;
	
	return ret;
}

/* ���C���������邩���ׂ� */
int cpu_blockEraseJudge(int player) {
	int		i, j, sr,ret;

	ret = 0;
	for(i = 0; i <= fldsizeh[player]; i++) {
		sr = 1;
		for(j = 0; j < fldsizew[player]; j++)
			if(cp_fld[j + i * fldsizew[player] + player * 220] == 0) {
				sr = 0;
				break;
			}
		ret = ret + sr;
		if(sr) cp_erase[i+22*player] = 1;
	}
	
	return ret;
}

// �w�{���X�_���K�v�Ȍ�����������̂����ׂ�
//���@��
//���@������ȏ�ԂȂ�K�v�Ɣ��f
//���@��
int cpu_HowManyNeedIblock(int player) {
	int i,j, count_left, count_right,total,by,by2;
	
	count_left = 0;
	count_right = 0;
	total = 0;
	
	for(j = 0;j < fldsizew[player];j++) {
		by = cpu_checkHoleStart(player,j);
		by2 = cpu_checkFieldTop(player,j);
		for(i = by; i < by2; i++) {
			// �����Ƀu���b�N������i�܂��͒[�j
			if((j == 0) || (fld[(j - 1) + i * 10 + player * 220] != 0))
				count_left++;
			
			// �E���Ƀu���b�N������
			if((j == fldsizew[player] - 1 ) || (fld[(j + 1) + i * 10 + player * 220] != 0))
				count_right++;
		}
		if((count_left >= 3) && (count_right >= 3)) total++;	//�_���v��Ɣ��f
		count_left=0;
		count_right=0;
	}
	
	
	return total;
}

/* ���݂̃t�B�[���h�����z�t�B�[���h�ɃR�s�[ */
void cpuCopyField(int player) {
	int i;
	
	for(i=0; i<220; i++) {
		cp_fld[i + player * 220] = fld[i + player * 220];
	}
}

int cpu_checkFieldTop(int player,int x) {
	int i;
	
	for(i = 0; i <= fldsizeh[player]; i++)
		if(fld[x + i * fldsizew[player] + player * 220])
			return i;
	
	// ����ۂ̏ꍇ
	return 22;
}
//�����n�܂�ʒu��T��
//���@��
int cpu_checkHoleStart(int player,int x) {
	int i,top;
	top = cpu_checkFieldTop(player,x);
	
	for(i = 0; i < top; i++)
		if( ((x == 0) || (fld[(x - 1) + i * 10 + player * 220] != 0)) && ((x == fldsizew[player] - 1 ) || (fld[(x + 1) + i * 10 + player * 220] != 0)) )
			return i;
	
	return top;
}

/* �őP��̏ꏊ�����߂� */
void cpuCheckBestSpot(int player) {
	int i, j, k;
	int bx2, by2;
	int bottom;
	int pts;
	int tmp;
	int mfilled;	// �ł����܂��Ă鐔
	int mrot,mrot_s;		// ���ׂ��]������
	
	for(i=0;i<=21;i++) cp_erase[i+22*player] = 0;
	
	mfilled = 0;
	cp_hold[player] = 0;
	
	// ���ׂ��]�����������߂�
	mrot = 4;
	mrot_s = 0;
	
	// �ԁA�΁A����2�p�^�[���̂�
	if(!isWRule(player)) {
		if( (blk[player] == 0) || (blk[player] == 3) || (blk[player] == 6) ) mrot = 2;
	}
	
	// ���F�͉��Ȃ�
	if( (blk[player] == 2) && (!istrance[player]) ) mrot = 1;
	// �񂹂Ȃ�
	else if(isrotatelock[player] ){
		mrot = rt[player] + 1;
		mrot_s = rt[player];
	}
	
	for(j=mrot_s; j<mrot; j++) { /* ��]���� */
		for(i=-3; i<fldsizew[player]; i++) { /* X���W */
			// ��𒲂ׂ�
			for(bottom = 0; judgeBlock(player, i, bottom, blk[player], j) == 0; bottom++);
			bottom = bottom - 1;
			
			if( judgeBlock(player, i, bottom, blk[player], j) == 0 ) {
				// ���݂̃t�B�[���h�����z�t�B�[���h�ɃR�s�[
				cpuCopyField(player);
				
				// ���z�t�B�[���h�Ƀu���b�N��ݒu����
				if(cpu_setBlock(player, i, bottom, blk[player], j)==0){
					pts = 0;
					break;	// ��ʊO���S�������
				}
				
				pts = 0;
				
				for(k=0; k<4; k++) {
					// ���W�����߂�
					if(rots[player] == 8) {
						bx2 = (i + blkDDataX[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
						by2 = (bottom + blkDDataY[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
					} else if( isWRule(player) ) {
						bx2 = (i + blkWDataX[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
						by2 = (bottom + blkWDataY[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
					} else {
						bx2 = (i + blkDataX[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
						by2 = (bottom + blkDataY[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
					}
					
					// 2���C���ȏ������΃{�[�i�X
					tmp = cpu_blockEraseJudge(player);
					
					// ��1�}�X�Ɍ��Ԃ���������I��
					if( cpuCheckFloatingE(player, bx2, by2) == -1 ) {
						pts = 0;
						break;
					}
					
					// �����𒲂ׂ�
					//pts = pts + cpuBlockHowManyFilled(player, by2);
					pts = pts + blockHowManyFilledFromLeft(player, by2);
					
					// �ǂƗאڂ�����
					pts = pts + cpuCheckLeftRight(player, bx2, by2);
					
					
					//����u���b�N����DEL FIELD�AMOV FIELD�AFREE FALL�Ȃ������`���ŗD��
					if((item[player] == 17) || (item[player] == 29) || (item[player] == 30) || (item[player] == 35) || (item[player] == 28))
						tmp = tmp * 1000;
					//�s���`�Ȃ�DEL EVEN�A��DEL FIELD���_��
					if((pinch[player]) && ((item[player] == 18) || (item[player] == 19)))
						tmp = tmp * 1000;
					if(tmp >= 2) {
						pts = pts + tmp * 2;
					} else if( (tmp == 1) && (!pinch[player]) && (cp_type) && (((item[player] == 17) || (item[player] == 29) || (item[player] == 30)) && (tmp != 0)) ) {
						// 1���C�����������Ȃ��ꍇ�͂��̎���̂Ă�
						pts = 0;
						break;
					}
				}
				// �őP��̏ꍇ
				if(pts >= mfilled) {
					mfilled = pts;
					cp_x[player] = i;
					cp_rt[player] = j;
				}
			}
		}/* for(i=-3; i<fldsizew[player]; i++) */
	}/* for(j=0; j<mrot; j++) */
	
	// �_��HOLD����
	if( (blk[player] == 0) && (hold[player] != 0) && (!dhold[player]) && (mfilled <= 40) && (!pinch[player]) && (!item[player])) {
		// ���̃u���b�N��O�AZ�AS�łȂ��ꍇ��HOLD����
		if( (next[player] != 2) && (next[player] != 3) && (next[player] != 6) && (cpu_HowManyNeedIblock(player) < 2 - (1 * (pinch[player]))) ) {
			cp_hold[player] = 1;
		}
	}
	
	// �_��HOLD�g����Ăяo��
	if( (hold[player] == 0) && (!dhold[player]) && (cpu_HowManyNeedIblock(player) >= 2 - (1 * (pinch[player]))) )
		cp_hold[player] = 1;
	
	// �L���Ȏ肪�����ꍇ
	if(mfilled == 0) {
		// �_��HOLD�g����Ăяo��
		if( (hold[player] == 0) && (!dhold[player]) && (cpu_HowManyNeedIblock(player) >= 1 ) )
			cp_hold[player] = 1;
		else if( (dhold[player] == 0) && (!item[player]) ) {
			// HOLD�ł���Ȃ�HOLD����
			// �������A�C�e��������ꍇ�͂��Ȃ� #1.60c7o9
			cp_hold[player] = 1;
		} else {
			// HOLD�ł��Ȃ��Ȃ�Ë�
			for(j=0; j<mrot; j++) { /* ��]���� */
				for(i=-3; i<fldsizew[player]; i++) { /* X���W */
					// ��𒲂ׂ�
					for(bottom = 0; judgeBlock(player, i, bottom, blk[player], j) == 0; bottom++);
					bottom = bottom - 1;
					
					if( judgeBlock(player, i, bottom, blk[player], j) == 0 ) {
						// ���݂̃t�B�[���h�����z�t�B�[���h�ɃR�s�[
						cpuCopyField(player);
						
						// ���z�t�B�[���h�Ƀu���b�N��ݒu����
						cpu_setBlock(player, i, bottom, blk[player], j);
						
						pts = 0;
						
						for(k=0; k<4; k++) {
							// ���W�����߂�
							if(rots[player] == 8) {
								bx2 = (i + blkDDataX[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
								by2 = (bottom + blkDDataY[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
							} else if( isWRule(player) ) {
								bx2 = (i + blkWDataX[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
								by2 = (bottom + blkWDataY[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
							} else {
								bx2 = (i + blkDataX[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
								by2 = (bottom + blkDataY[blk[player] * 16 + j * 4 + k] * (IsBig[player] + 1));
							}
							
							// ���C����������΃{�[�i�X
							tmp = cpu_blockEraseJudge(player) * 10;
							
							// ��1�}�X�Ɍ���
							if( cpuCheckFloatingE(player, bx2, by2) == -1 )
								pts = pts - 10;
							// �����𒲂ׂ�
							pts = pts + cpuBlockHowManyFilled(player, by2);
							
							// �ǂƗאڂ�����
							pts = pts + cpuCheckLeftRight(player, bx2, by2);
							
							if((tmp >= 2) || (pinch[player])) {
								pts = pts + (tmp * 10) + 10;	// �{�[�i�X
							}
							//����u���b�N����DEL FIELD�܂���MOV FIELD�Ȃ������`���ŗD��
							if((item[player] == 17) || (item[player] == 29) || (item[player] == 30))
								tmp = tmp * 1000;
							//�s���`�Ȃ�DEL EVEN�A��DEL FIELD�AFREE FALL���_��
							if((pinch[player]) && ((item[player] == 18) || (item[player] == 19) || (item[player] == 28)))
								tmp = tmp * 1000;
						}
						
						// �őP��̏ꍇ
						if(pts >= mfilled) {
							mfilled = pts;
							cp_x[player] = i;
							cp_rt[player] = j;
						}
					}
				}/* for(i=-3; i<fldsizew[player]; i++) */
			}/* for(j=0; j<mrot; j++) */
		}
	}/* if(mfilled == 0) */
	// BEGINNER�i�r�Q�[�V�����p�ɁA�őP��̏ꏊ�ցA���z�t�B�[���h�Ƀu���b�N��ݒu
	for(bottom = 0; judgeBlock(player, cp_x[player], bottom, blk[player], cp_rt[player]) == 0; bottom++);
		bottom = bottom - 1;
	cpuCopyField(player);
	cpu_setBlock(player, cp_x[player], bottom, blk[player], cp_rt[player]);
}
