#include <math.h>
#include "DxLib.h"

class Fps{

	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS

public:
	Fps(int fps);

	bool Update();

	void Draw();

	void Wait();
};
