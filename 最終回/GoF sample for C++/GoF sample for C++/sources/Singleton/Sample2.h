/*!
	@file	CSample2.h
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	Singleton�̃T���v���R�[�h2
	@detail	�V���O���g���Ń\�[�X���ׂ��ł��l�����L����Ă��邱�Ƃ̏ؖ�
*/
#pragma once
#include "SingletonSample.h"
namespace GoF {
	namespace Singleton {
		/*!
			@class	CSample1
			@brief	�f�X�g���N�^�ŃV���O���g���̃J�E���^�����Z������B
		*/
		class CSample2
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CSample2() {}

			/*!
				@brief	�f�X�g���N�^
				@detail	�V���O���g���̃J�E���^�����Z
			*/
			~CSample2() { CSingleton::GetInstance().AddCount(); }

		private:

		};

	}
}