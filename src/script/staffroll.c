//������������������������������������������������������������������������������
//  �X�^�b�t���[���f�[�^��������
//������������������������������������������������������������������������������

void staffInitPl(int player) {
//	staffroll_y_ex[player] = 2000;		//������c
}

//������������������������������������������������������������������������������
//  �X�^�b�t���[���������`��
//������������������������������������������������������������������������������
void staffExecute(int player) {
	int i;
	
	if( ending[player] != 2 ) return;
	
	if(!onRecord[player]) return;

	// �`�悷��
	if ( getDrawRate() != 1 )
		BltRect(70,240 + 384 * player - 192 * maxPlay,80,0,staffroll_y_ex[player],160,320);
	else
		BltRect(70,120 + 192 * player - 96 * maxPlay,40,0,staffroll_y_ex[player] / 2,80,160);
}

//������������������������������������������������������������������������������
//  �V�����������������\��������
//������������������������������������������������������������������������������
void staffRoll(int player) {
	if( (ending[player] == 2) && (onRecord[player]) && (!pause[player]) ) {
		if(fastroll[player]){
			endtime[player]=endtime[player]+2; // �o�ߎ���+1 #1.60c7o6
		}else{
			endtime[player]++; // �o�ߎ���+1 #1.60c7o6
		}
		//������]�΍�
		if((repversw >= 55) && (gameMode[player] >= 1) && ((kickc[player] > 10) || (kickc3[player] > 8)) ){
			endtime[player] = endtime[player] - 1 - (fastroll[player]);
		}else{
			// ��Ɉړ�
			if( (endtime[player] % 2 == 0) && (endtime[player] < 3100) && (!pause[player]) ){
				staffroll_y_ex[player]++;
			}
		}

	}
}
