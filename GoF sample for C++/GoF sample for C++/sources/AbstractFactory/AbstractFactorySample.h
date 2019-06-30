/*!
	@file	AbstractFactorySample.h
	@date	2019/06/29
	@author	�ԏ� �G�P
	@brief	�A�u�X�g���N�g�t�@�N�g���[�̃T���v���R�[�h

	NOTE:	AbstractFactory.h�̕��ɖŒ��ꒃ�ׂ��������Ă��܂��B
			���������Ȃ肷����...
			���������͂�������Q�l��etc.
			���r���܂ł��������ĂȂ��ł��B
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace AbstractFactory {

#pragma region ����

		//	�ŏ�

		/*!
			@class	AbstractProduct
			@brief	�������̒��ۃN���X
		*/
		class AbstractProduct abstract
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			AbstractProduct() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~AbstractProduct() {}
		private:
		};

		/*!
			@class	CProduct
			@brief	���ۃN���X���p��������ۃN���X
		*/
		class CProduct
			: public AbstractProduct
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CProduct() :AbstractProduct() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CProduct() {}
		private:

		};
#pragma endregion

#pragma region �T���v��

#pragma region �C���^�[�t�F�C�X�E���ۃN���X
		/*!
			@interface	ICharacter
			@brief		�L�����N�^�[�̃C���^�[�t�F�C�X
		*/
		__interface ICharacter
		{
			/*!
				@fn		Move
				@brief	�ړ�
			*/
			void Move();

			/*!
				@fn		Attack
				@brief	�U��
			*/
			void Attack();

			/*!
				@fn		Damage
				@brief	�_���[�W
			*/
			void Damage();
		};

		/*!
			@class	AbstractEnemy
			@brief	�G�̒��ۃN���X
		*/
		class AbstractEnemy abstract
			: public ICharacter
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			AbstractEnemy() :m_ID(0), m_HP(10), m_ATK(1), m_DEF(1), m_SPD(1) {}

			/*!
				@brief	���z�f�X�g���N�^
			*/
			virtual~AbstractEnemy() {};

		private:

		protected:
			/*!
				@var	m_ID
				@brief	�G�L�����̎���ID
			*/
			unsigned int m_ID;

			/*!
				@var	m_HP
				@brief	HP
			*/
			unsigned int m_HP;

			/*!
				@var	m_ATK
				@brief	�U����
			*/
			unsigned int m_ATK;

			/*!
				@var	m_DEF
				@brief	�h���
			*/
			unsigned int m_DEF;

			/*!
				@var	m_SPD
				@brief	���x
			*/
			unsigned int m_SPD;
		};


#pragma endregion

#pragma region ��ۃN���X

		/*!
			@class	CPlayer
			@brief	�v���C���[�̃N���X
		*/
		class CPlayer
			: public ICharacter
		{
		public:
			/*!
				@brief	�f�t�H���g�R���X�g���N�^
			*/
			CPlayer() = default;

			/*!
				@brief	�f�t�H���g�f�X�g���N�^
			*/
			~CPlayer() = default;

			/*!
				@fn		Move
				@brief	�ړ�
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Move() {
				std::cout << "�v���C���[�̈ړ�";

			}

			/*!
				@fn		Attack
				@brief	�U��
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Attack() {
				std::cout << "�v���C���[�̍U��";

			}

			/*!
				@fn		Damage
				@brief	�_���[�W
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Damage() {
				std::cout << "�v���C���[�փ_���[�W";

			}
		private:

		};

		/*!
			@class	CFriend
			@brief	���Ԃ̃N���X
		*/
		class CFriend
			: public ICharacter
		{
		public:
			/*!
				@brief	�f�t�H���g�R���X�g���N�^
			*/
			CFriend() = default;

			/*!
				@brief	�f�t�H���g�f�X�g���N�^
			*/
			~CFriend() =default;

			/*!
				@fn		Move
				@brief	�ړ�
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Move() {
				std::cout << "���Ԃ̈ړ�";
			}

			/*!
				@fn		Attack
				@brief	�U��
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Attack() {
				std::cout << "���Ԃ̍U��";
			}

			/*!
				@fn		Damage
				@brief	�_���[�W
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Damage() {
				std::cout << "���Ԃփ_���[�W";
			}
		private:

		};

		/*!
			@class	CMobEnemy
			@brief	�G���u
		*/
		class CMobEnemy
			: public AbstractEnemy
		{
		public:
			/*!
				@brief	�R���X�g���N�^
				@detail	���N���X�̃R���X�g���N�^�ŏ�����
			*/
			CMobEnemy() : AbstractEnemy() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CMobEnemy() {};

			/*!
				@fn		Move
				@brief	�ړ�
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Move() {
				std::cout << "�G���u�̈ړ�";
			}

			/*!
				@fn		Attack
				@brief	�U��
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Attack() {
				std::cout << "�G���u�̍U��";
			}

			/*!
				@fn		Damage
				@brief	�_���[�W
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Damage() {
				std::cout << "�G���u�փ_���[�W";
			}

		private:

		};

		/*!
			@class	CBossEnemy
			@brief	�G�{�X
		*/
		class CBossEnemy
			: public AbstractEnemy
		{
		public:
			/*!
				@brief	�R���X�g���N�^
				@detail	���N���X�̃R���X�g���N�^�ŏ�������A�㏑��
			*/
			CBossEnemy() : AbstractEnemy() {
				m_ID = 100, m_HP = 100, m_ATK = 100, m_DEF = 100, m_SPD = 10;
			}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CBossEnemy() {};

			/*!
				@fn		Move
				@brief	�ړ�
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Move() {
				std::cout << "�G�{�X�̈ړ�";
			}

			/*!
				@fn		Attack
				@brief	�U��
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Attack() {
				std::cout << "�G�{�X�̍U��";
			}

			/*!
				@fn		Damage
				@brief	�_���[�W
				@detail	�C���^�[�t�F�C�X����
			*/
			void ICharacter::Damage() {
				std::cout << "�G�{�X�փ_���[�W";
			}

		private:

		};
#pragma endregion

#pragma endregion

	}
}