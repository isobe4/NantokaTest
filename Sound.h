#include "DxLib.h"

#ifndef DEF_SOUND_H

#define DEF_SOUND_H

class Sound{
	int SoundData;			//�T�E���h���L�^�����������̃f�[�^
	int play_start_time;	//�܂��g��Ȃ�
	int play_stop_time;		//�܂��g��Ȃ�
	double volumeData;		//�{�����[���̑傫���i0.00~1.00�j
public:
	//�T�E���h�̏�����
	Sound();

	//�T�E���h���Z�b�g
	void setSound(int sound);
	void setSound(char* sound);

	//�T�E���h�{�����[�����Z�b�g
	void setSoundVolume(int volume);

	//�m�[�}���Đ�
	void playSound_normal();
	void playSound_normal(int sound, int volume);
	void playSound_normal(char* sound, int volume);

	//�o�b�N�O���E���h�Đ�
	void playSound_back();
	void playSound_back(int sound, int volume);
	void playSound_back(char* sound, int volume);

	//���[�v�Đ�
	void playSound_loop();
	void playSound_loop(int sound, int volume);
	void playSound_loop(char* sound, int volume);

	//�Đ��X�g�b�v
	void stopSound();
};
#endif