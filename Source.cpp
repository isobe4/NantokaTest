/*#include "DxLib.h"

int Key[256]; // �L�[��������Ă���t���[�������i�[����

// �L�[�̓��͏�Ԃ��X�V����
int gpUpdateKey(){
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i<256; i++){
		if (tmpKey[i] != 0){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}

// ���j���[���ڂ̕\���ɕK�v�ȍ\���̂�p�ӂ���
typedef struct{
	int x, y;       // ���W�i�[�p�ϐ�
	char name[128]; // ���ږ��i�[�p�ϐ�
} MenuElement_t;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	// ���j���[���ڗv�f��5���
	MenuElement_t MenuElement[5] = {
		{ 80, 100, "�Q�[���X�^�[�g" }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��80���Ay��100���Aname��"�Q�[���X�^�[�g"��
		{ 100, 150, "���܂�" },
		{ 100, 200, "�w���v" },
		{ 100, 250, "�R���t�B�O" },
		{ 100, 300, "�Q�[���I��" },
	};
	int SelectNum = 0; // ���݂̑I��ԍ�

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�X�V)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0){

		// �v�Z�t�F�[�Y 

		if (Key[KEY_INPUT_DOWN] == 1){ // ���L�[�������ꂽ�u�Ԃ�������

			SelectNum = (SelectNum + 1) % 5; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

			for (int i = 0; i<5; i++){              // ���j���[���ڐ��ł���5���[�v����
				if (i == SelectNum){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
					MenuElement[i].x = 80; // ���W��80�ɂ���
				}
				else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
					MenuElement[i].x = 100;// ���W��100�ɂ���
				}
			}
		}

		// �`��t�F�[�Y

		for (int i = 0; i<5; i++){ // ���j���[���ڂ�`��
			DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 255, 255), MenuElement[i].name);
		}

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}*/