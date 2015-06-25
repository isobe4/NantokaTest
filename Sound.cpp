#include "Sound.h"
#include "DxLib.h"



//������
Sound::Sound(){//����������ɃR���X�g���N�^���g�p
	SoundData = NULL;
	play_start_time = 0;
	play_stop_time = 0;
	volumeData = 1;
};



//�T�E���h�f�[�^���Z�b�g
void Sound::setSound(int sound){//�T�E���h�f�[�^���Z�b�g
	SoundData = sound;
}
void Sound::setSound(char* sound){//�ꏊ���w�肵�ăT�E���h�f�[�^���Z�b�g
	SoundData = LoadSoundMem(sound);
}


void Sound::setSoundVolume(int v){//�{�����[�����Z�b�g
	if (v > 100)v = 100;
	if (v < 0)v = 0;
	volumeData = v * 0.01;
};




//�m�[�}���ŃT�E���h�v���C

void Sound::playSound_normal(){//���ɃZ�b�g���Ă�����̂��m�[�}���ōĐ�
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_NORMAL, TRUE);
}
void Sound::playSound_normal(int sound, int volume){//�������ɃZ�b�g���Ă�����̂��A�{�����[����ς��ăm�[�}���ōĐ�
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volume, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_NORMAL, TRUE);
}
void Sound::playSound_normal(char* sound, int volume){//���ړǂݍ��ݏꏊ�ƃ{�����[����ݒ肵�A�m�[�}���ōĐ�
	int SoundData = LoadSoundMem(sound);
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_NORMAL, TRUE);
}




//�o�b�N�O���E���h�ŃT�E���h�v���C


void Sound::playSound_back(){//���ɃZ�b�g���Ă�����̂��o�b�N�O���E���h�ōĐ�
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_BACK, TRUE);
}
void Sound::playSound_back(int sound, int volume){//�������ɃZ�b�g���Ă�����̂��A�{�����[����ς��ăo�b�N�O���E���h�ōĐ�
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volume, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE);
}
void Sound::playSound_back(char* sound, int volume){//���ړǂݍ��ݏꏊ�ƃ{�����[����ݒ肵�A�o�b�N�O���E���h�ōĐ�
	int SoundData = LoadSoundMem(sound);
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_BACK, TRUE);
}




//���[�v�ŃT�E���h�v���C

void Sound::playSound_loop(){//���ɃZ�b�g���Ă�����̂����[�v�ōĐ�
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_LOOP, TRUE);
}
void Sound::playSound_loop(int sound, int volume){//�������ɃZ�b�g���Ă�����̂��A�{�����[����ς��ă��[�v�ōĐ�
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volume, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP, TRUE);
}
void Sound::playSound_loop(char* sound, int volume){//���ړǂݍ��ݏꏊ�ƃ{�����[����ݒ肵�A���[�v�ōĐ�
	int SoundData = LoadSoundMem(sound);
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_LOOP, TRUE);
}




//�T�E���h�X�g�b�v
void Sound::stopSound(){//�T�E���h�X�g�b�v
	StopSoundMem(SoundData);
}