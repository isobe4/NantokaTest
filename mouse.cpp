/*#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX,������,����ʐݒ�

	int x, y, Mouse, Wheel, Image;
	double size = 1.0;

	Image = LoadGraph("Character.jpg");//�摜���[�h

	// while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()){
		Mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
		Wheel = GetMouseWheelRotVol();  //�z�C�[���̉�]�ʎ擾
		GetMousePoint(&x, &y);                //�}�E�X�̍��W�擾
		if (Mouse & MOUSE_INPUT_LEFT){ //�}�E�X�̍��{�^����������Ă�����
			DrawString(0, 0, "���{�^����������Ă��܂�", GetColor(255, 255, 255));
		}
		if (Wheel > 0){        //�z�C�[����+�����ɉ�]���Ă�����
			size += 0.1;
		}
		if (Wheel < 0){        //�z�C�[�����|�����ɉ�]���Ă�����
			size -= 0.1;
		}
		DrawRotaGraph(x, y, size, 0.0, Image, TRUE);  //�摜��x,y�̈ʒu�ɃT�C�Ysize�ŕ`��
	}

	DxLib_End();
	return 0;
}*/