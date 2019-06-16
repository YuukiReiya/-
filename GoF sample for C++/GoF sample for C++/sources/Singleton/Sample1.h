/*!
	@file	CSample1.h
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	Singleton�̃T���v���R�[�h1
	@detail	�V���O���g���Ń\�[�X���ׂ��ł��l�����L����Ă��邱�Ƃ̏ؖ�
*/
#pragma once
#include "SingletonSample.h"
namespace GoF {
	namespace Singleton {
		/*!
			@class	CSample1
			@brief	�R���X�g���N�^�ŃV���O���g���̃J�E���^�����Z������B
		*/
		class CSample1
		{
		public:
			/*!
				@brief	�R���X�g���N�^
				@detail	�V���O���g���̃J�E���^�����Z
			*/
			CSample1() { CSingleton::GetInstance().AddCount(); };

			/*!
				@brief	�f�X�g���N�^
			*/
			~CSample1() {};

		private:

		};

	}
}