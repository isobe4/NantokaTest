/*#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	int image[16];
	LoadDivGraph("c1.png", 28, 7, 4, 128, 128, image); // �摜�̕����ǂݍ���

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0){

		DrawGraph(100, 100, image[9], TRUE);      // �摜��\��

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}*/