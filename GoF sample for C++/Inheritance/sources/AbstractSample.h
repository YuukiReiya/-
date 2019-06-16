/*!
	@file	AbstractSample.h
	@date	2019/06/15
	@author	�ԏ� �G�P
	@brief	���ۃN���X�̃T���v���R�[�h
*/
#pragma once
#include <string>

namespace Inheritance{

#pragma region ���ې錾
	namespace Abstract {
		/*!
			@brief	�����̒��ۃN���X

			NOTE:	abstract�L�[���[�h���g���ƃC���X�^���X�����o���Ȃ��Ȃ�܂��B
					(���ۃN���X�Ƃ̓C���X�^���X���𐧌����ꂽ�N���X�̂���)
		*/
		class AbstractAnimals abstract
		{
		public:
			/*!
				@brief	�R���X�g���N�^
				@detail	abstract�錾�Ȃ̂Ōp�����̃C���X�^���X���͂ł��Ȃ�
			*/
			AbstractAnimals() = default;
			virtual ~AbstractAnimals() = default;

			/*!
				@fn		Update
				@brief	�X�V����
				@detail	���ۃ��\�b�h

				NOTE:	����̓_�~�[�Ȃ̂Ōp������󏈗�
			*/
			virtual void Update()abstract;

			/*!
				@fn		DisplayName
				@brief	�����o�̖��O��\��
			*/
			inline void DisplayName(){
				std::cout << m_Name << std::endl;
			}
		protected:
			/*!
				@var	m_Name
				@brief	���O
			*/
			std::string m_Name;
		};
	}
#pragma endregion

#pragma region ���̐錾
	namespace Entity {
		/*!
			@brief	��
		*/
		class Dog 
			: public Abstract::AbstractAnimals
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			explicit Dog() { m_Name = "��"; };

			/*!
				@brief	�f�X�g���N�^
			*/
			~Dog()override = default;

			/*!
				@fn		Update
				@brief	�X�V����
				@detail	�p�����̃I�[�o�[���C�h

				NOTE:	����̓T���v���R�[�h�Ȃ̂ŋ󏈗�
			*/
			void Update()override {}
		};

		/*!
			@brief	�L
		*/
		class Cat
			: public Abstract::AbstractAnimals
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			explicit Cat() { m_Name = "�L"; };

			/*!
				@brief	�f�X�g���N�^
			*/
			~Cat()override = default;

			/*!
				@fn		Update
				@brief	�X�V����
				@detail	�p�����̃I�[�o�[���C�h

				NOTE:	����̓T���v���R�[�h�Ȃ̂ŋ󏈗�
			*/
			void Update()override {}

		};
	}
#pragma endregion
}