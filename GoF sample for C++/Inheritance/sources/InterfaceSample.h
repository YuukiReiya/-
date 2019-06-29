/*!
	@file	InterfaceSample.h
	@date	2019/06/15
	@author	�ԏ� �G�P
	@brief	�C���^�[�t�F�C�X�̃T���v���R�[�h
*/
#pragma once
#include <iostream>

namespace Inheritance {
	
#pragma region �C���^�[�t�F�C�X�錾
	namespace Interface {
		/*!
			@brief	�L�����N�^�[�̃C���^�[�t�F�C�X

			NOTE:	�C���^�[�t�F�C�X�̓����o�ϐ������������Ȃ��̂Œ���!!
					���d�p�������S�ɏo����̂������b�g�I
					(C++���C#�̂����ʓI)
		*/
		__interface ICharacter
		{
			/*!
				@fn		Action
				@brief	�A�N�V�������\�b�h
			*/
			void Action();

			/*!
				@fn		Move
				@brief	�ړ����\�b�h
			*/
			void Move();

			/*!
				@fn		Damage
				@brief	�W�����v���\�b�h
			*/
			void Jump();
		};
	}
#pragma endregion

#pragma region ���̐錾
	namespace Entity {

		/*!
			@brief	�v���C���[
		*/
		class Player
			: public Interface::ICharacter
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			explicit Player() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~Player() = default;

			/*!
				@fn		Action
				@brief	�A�N�V�������\�b�h
			*/
			inline void ICharacter::Action() {
				std::cout << "�v���C���[�̃A�N�V����";
			}

			/*!
				@fn		Move
				@brief	�ړ����\�b�h
			*/
			inline void ICharacter::Move() {
				std::cout << "�v���C���[�̈ړ�";
			}

			/*!
				@fn		Damage
				@brief	�W�����v���\�b�h
			*/
			inline void ICharacter::Jump() {
				std::cout << "�v���C���[�̃W�����v";
			}

		private:
		};

		/*!
			@brief	�G�l�~�[
		*/
		class Enemy
			: public Interface::ICharacter
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			Enemy() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~Enemy() = default;


			/*!
				@fn		Action
				@brief	�A�N�V�������\�b�h
			*/
			inline void ICharacter::Action() {
				std::cout << "�G�l�~�[�̃A�N�V����";
			}

			/*!
				@fn		Move
				@brief	�ړ����\�b�h
			*/
			inline void ICharacter::Move() {
				std::cout << "�G�l�~�[�̈ړ�";
			}

			/*!
				@fn		Damage
				@brief	�W�����v���\�b�h
			*/
			inline void ICharacter::Jump() {
				std::cout << "�G�l�~�[�̃W�����v";
			}
		private:
		};
	}
#pragma endregion

}