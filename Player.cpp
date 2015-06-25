#include "DxLib.h"
#include "Player.h"



// ���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�
static int p_x=150;     //x���W
static int p_y=150;		//y���W
static int c_tip[28]; //�L�����摜�i�[�z��
static int char_chip[20];//���בւ����L�����`�b�v
static int flag=0;	//�L�����̍��E���]���̃t���O
static int flag_stop = 0;//�L�����̒�~
static int flag_jump = 0;//�L�����̃W�����v
//static int char_wait=4;

//�t���[���Ǘ��ϐ�
static int frame_left = 0;
static int frame_right = 0;
static int frame_stop = 0;
static int frame_jump = 0;

static int frame_left_data = 0;
static int frame_right_data = 0;
static int frame_stop_data = 0;
static int frame_jump_data = 0;

//�R���t�B�O�ɂ��g�p����ϐ�
static int char_chip_count_left = 5;//���ړ��p
static int char_chip_count_right = 5;//�E�ړ��p
static int char_chip_count_stop = 0;//��~�p
static int char_chip_count_jump = 13;//�W�����v�p
static int char_flag = 0;//�L�����̃��[�V�����̏������t���O
static int p_w, p_h;



// ������������
void initializePlayer(){
	LoadDivGraph("c1.png", 28, 7, 4, 128, 128, c_tip);//���j�e�B�[�����ǂݍ���
	
	// 0�`2�A��~
	char_chip[0] = c_tip[0];
	char_chip[1] = c_tip[1];
	char_chip[2] = c_tip[2];

	//�g���ĂȂ�
	char_chip[3] = c_tip[3];
	char_chip[4] = c_tip[4];
	
	//�ړ�����5~8
	char_chip[5] = c_tip[7];
	char_chip[6] = c_tip[8];
	char_chip[7] = c_tip[9];
	char_chip[8] = c_tip[10];
	//�ړ�����9~12
	char_chip[9] = c_tip[14];
	char_chip[10] = c_tip[15];
	char_chip[11] = c_tip[16];
	char_chip[12] = c_tip[17];

	//�W�����v�����i�㏸���j13~15
	char_chip[13] = c_tip[21];
	char_chip[14] = c_tip[22];
	char_chip[15] = c_tip[23];

	//�W�����v����(���~��)16~18
	char_chip[16] = c_tip[24];
	char_chip[17] = c_tip[25];
	char_chip[18] = c_tip[26];
	char_chip[19] = c_tip[27];

	GetGraphSize(char_chip[0], &p_w, &p_h);//�����Əc���擾

	//�L�����N�^�[�𒆉��ɐݒu
	int window_W, window_H;
	GetWindowSize(&window_W,&window_H);
	p_x = window_W / 2 - p_w / 2;
	//p_y = window_H / 2 - p_h / 2;
	p_y = window_H - p_h;


}


// �`�悷��
void drawPlayer(){
	
	switch (flag){

	case 0: DrawTurnGraph(p_x, p_y, char_chip[char_chip_count_left], TRUE);
		
		break;//���`��
	
	case 1: DrawGraph(p_x, p_y, char_chip[char_chip_count_right], TRUE);
		

		break;//�E�`��
	
	case 2: if (flag_stop == 0){ DrawTurnGraph(p_x, p_y, char_chip[char_chip_count_stop], TRUE); }
			else{ DrawGraph(p_x, p_y, char_chip[char_chip_count_stop], TRUE); }
		break;//��~

		
	}
	
}

//���ړ�
void leftMove(){

	/*
	//char_chip��5�ɃZ�b�g����(���񏉊������Ȃ��̂́A��̃`�b�v�������f����Ȃ��Ȃ邽��)
	while(char_chip_count<4*char_wait||char_chip_count>11*char_wait){
	char_chip_count++;
	if (char_chip_count==12*char_wait){
	char_chip_count = 0;
	}
	}
	//�L�����𓮂�����
	char_chip_count++;
	if (char_chip_count==12*char_wait){
	char_chip_count = 4;
	}
	*/
	if (frame_left_data == 5){

	if (char_chip_count_left == 12){
		char_chip_count_left = 5;
	}
	else
	{
		char_chip_count_left++;
	}

	//���E���]����

	flag = 0;
	flag_stop = 0;
	}
	//�t���[������
	frame_left_data = (frame_left % 5 + 1);
	frame_left++;

	if (frame_left >= 5)frame_left = 0;
}

//�E�ړ�
void rightMove(){
	if (frame_right_data==5){
	if (char_chip_count_right == 12){
		char_chip_count_right = 5;
	}
	else
	{
		char_chip_count_right++;
	}


	//���E���]����

	flag = 1;
	flag_stop = 1;
	}
	
	//�t���[������
	frame_right_data = (frame_right % 5 + 1);
	frame_right++;
	if (frame_right >= 5)frame_right = 0;
}

//��~����
void stopPlayer(){

	if (frame_stop_data == 20){
		if (char_chip_count_stop == 2){
			char_chip_count_stop = 0;
		}
		else
		{
			char_chip_count_stop++;
		}

		flag = 2;
	}
	
	//�t���[������
	frame_stop_data = (frame_stop % 20 + 1);
	frame_stop++;
	if (frame_stop >= 20)frame_stop = 0;
}

//�_�b�V��
void dashPlayer(){
}
//���ʉ��ݒ�
void setSound(){
}
//mapSize
void mapSize(){
}
//�R���t�B�O��Ԃ�\������
void drawConfig(){
	clsDx();

	//���[�V������\��

	if (flag == 3){
		printfDx("�L�����`�b�v�ԍ� : %d\n", char_chip_count_jump);
		printfDx("�L�������[�V���� : �W�����v\n");
	}


	if (flag == 1){
		printfDx("�L�����`�b�v�ԍ� : %d\n", char_chip_count_right);
		printfDx("�L�������[�V���� : �E�ړ�\n");
	}
	else if(flag == 0){
		printfDx("�L�����`�b�v�ԍ� : %d\n", char_chip_count_left);
		printfDx("�L�������[�V���� : ���ړ�\n");
	}else if (flag == 2){
		if (flag_stop == 1){
			printfDx("�L�����`�b�v�ԍ� : %d\n", char_chip_count_stop);
			printfDx("�L�������[�V���� : �E��~\n");
		}else{
			printfDx("�L�����`�b�v�ԍ� : %d\n", char_chip_count_stop);
			printfDx("�L�������[�V���� : ����~\n");
		}
	}

	//X���W�Ƃx���W��\��
	printfDx("�L�����Q���W�Q�w : %d\n", p_x);
	printfDx("�L�����Q���W�Q�x : %d\n", p_y);

	//�����Əc���̕\��
	printfDx("�L�����T�C�Y�Q�v : %d\n",p_w);
	printfDx("�L�����T�C�Y�Q�g : %d\n", p_h);

}

