#include "DxLib.h"

#ifndef DEF_PLAYER_H //��dinclude�h�~

#define DEF_PLAYER_H

// ������������
void initializePlayer();

// �`�悷��
void drawPlayer();

//�v���C���[��set����
void setPlayer();

//���ړ�
void leftMove();

//�E�ړ�
void rightMove();

//��~����
void stopPlayer();

//�W�����v
void jumpMove();

//�_�b�V��
void dashPlayer();

//���ʉ��w��
void setSound();

//�}�b�v�����蔻��
void mapSize();

//�R���t�B�O��Ԃ�\������
void drawConfig();

// �I������������
void Player_Finalize();


#endif 