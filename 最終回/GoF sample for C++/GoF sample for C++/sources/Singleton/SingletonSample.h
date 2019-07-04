/*!
	@file	SingletonSample.h
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	�V���O���g���̃T���v���R�[�h
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace Singleton {
		/*!
			@class	CSingleton
			@brief	�V���O���g���̃T���v���N���X
		*/
		class CSingleton
		{
		public:
			/*!
				@fn		GetInstance
				@brief	�C���X�^���X�̃Q�b�^�[
				@detail	�ÓI�C���X�^���X������A�N�Z�X

				@sample	���\�b�h�̌Ăяo����
						CSingleton::GetInstance().GetAdd();
			*/
			static inline CSingleton&GetInstance() {
				static CSingleton instance;
				return instance;
			}

#pragma region ���I���\�b�h

			/*!
				@fn		AddCount
				@brief	�J�E���g�̉��Z
			*/
			void AddCount() { m_Count++; }

			/*!
				@fn		GetCount
				@brief	�J�E���g�̎擾
			*/
			const int GetCount() { return m_Count; }
#pragma endregion

#pragma region �ÓI���\�b�h

			/*!
				@fn		DisplayCount
				@brief	�J�E���^�̕\��

				@sample	���\�b�h�Ăяo����
						CSingleton::DisplayCount();
						�����OK�B

						��
						CSingleton::GetInstance().DisplayCount();
						�ł����삷��B
			*/
			static void DisplayCount() { std::cout << GetInstance().m_Count; }
#pragma endregion

		private:
			//NOTE:	�R���X�g���N�^��private�ɂ��邱�ƂŃC���X�^���X�����𐧌����邱�Ƃ��o����B

			/*!
				@brief	�R���X�g���N�^
			*/
			CSingleton() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~CSingleton() = default;

			/*!
				@value	m_Count
				@brief	�J�E���g
			*/
			int m_Count = 0;

			static int m_DummyBuffer;
		};

	}
}