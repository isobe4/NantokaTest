#include "DxLib.h"
#include "Map.h"



//���̊֐����ł̕ϐ�
static int map_image=NULL;

static int window_W, window_H;//�E�B���h�E�̃T�C�Y
static int map_W, map_H;//�}�b�v�T�C�Y
static int map_X, map_Y;//�}�b�v���W
static int scroll_speed = 8;
static int jump_scroll_speed = 3;
static int fall_scroll_speed = 5;
static int right_flag=0;
static int motion_flag = 0;

static int map_back;
static int map_front;

static int chip_jump_data=0;


//������
void initializeMap(){

	
	map_image = LoadGraph("map1.jpg");  //�}�b�v���������ɓǂݍ���
	

	GetGraphSize(map_image, &map_W, &map_H);//�����Əc���擾

	GetWindowSize(&window_W, &window_H);

	//map_Y = window_H - map_H;
	map_Y = 0;
	map_X = 0;
}

//�}�b�v��`�悷��
void drawMap(){
	
	/*DrawGraph(map_X, map_Y, map_image, FALSE);
	DrawGraph(map_X, map_Y, map_back, true);
	DrawGraph(map_X, map_Y, map_front, true);*/

	DrawExtendGraph(map_X, map_Y, map_X+640,map_Y+480, map_image, TRUE);

	

}

/*//�X�N���[���}�b�v
void scrollMap(){

	switch (motion_flag){
	case 0:map_X += scroll_speed;//��(�L����)�}�b�v�͉E�֗����
		break;
	case 1:map_X -= scroll_speed;//�E�i�L�����j�}�b�v�͍��֗����
		break;
	case 2://stop(�L����)�}�b�v�͎~�܂�
		break;
	}

}*/

//�}�b�v���E�ɃX�N���[��

void rightScroll(){
	map_X += scroll_speed;
}

//�}�b�v�����ɃX�N���[��

void leftScroll(){
	map_X -= scroll_speed;
}

//�}�b�v�����ɃX�N���[��

void downScroll(){
	map_Y += jump_scroll_speed;
}

//�}�b�v����ɃX�N���[��

void upScroll(){
	map_Y -= jump_scroll_speed;
}

//�W�����v�X�N���[���֐�

void jumpScroll(){

	chip_jump_data++;
	
	if (chip_jump_data <= 24){
		map_Y += 10;
	}
	else{
		if (chip_jump_data <= 56){
			map_Y -= 7;
		}
		else{ chip_jump_data = 0; }
	}
}
