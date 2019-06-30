/*!
	@file	TemplateMethodSample.h
	@date	2019/06/30
	@author	�ԏ� �G�P
	@brief	�e���v���[�g���\�b�h�̃T���v���R�[�h
*/
#pragma once
#include <iostream>
#include <vector>
namespace GoF {
	namespace TemplateMethod {

#pragma region �֐��e���v���[�g	

		/*!
			@fn			mul
			@brief		��Z
			@detail		�e���v���[�g���\�b�h
			@param[in]	�|���鐔
			@param[in]	�|�����鐔
			@return		��Z����

			NOTE:		����N���X��\���̂��o����B(���얢��`�ɒ��ӁB)
						���L���\�b�h�ł͈قȂ�^�������ɓn�����ꍇ�A���얢��`�B
		*/
		template<typename T>T mul(T a, T b) { return a * b; }

		/*!
			@fn			mul
			@brief		��Z
			@detail		�e���v���[�g���\�b�h �I�[�o�[���[�h
			@param[in]	�|���鐔
			@param[in]	�|�����鐔
			@return		�|���鐔�Ɠ����^�̏�Z����

			NOTE:		�����ɈقȂ�^��n���ꍇ�́A���̂悤�ɖ����I��2��ނ̌^��n�����������S�B
						���_�b�N�^�C�s���O�ƌ��������͎��ȐӔC�ŁB
		*/
		template<typename T1, typename T2>T1 mul(T1 a, T2 b) { return a * b; }

		/*!
			@fn		FuncSample
			@brief	�֐��e���v���[�g�̃T���v���R�[�h
		*/
		void FuncSample()
		{
			std::cout << "int:" << mul<int>(2, 3) << std::endl;	//	int�^
			std::cout << "float:" << mul<float>(1.5f, 3.0f) << std::endl;//	float�^


			//NOTE:	���L�Ăяo���ł킩��ʂ�A�����͌^���_�����B
			std::cout << "�������v�Z:" << mul<int>(1.5f, 3) << std::endl;//	1.5f��1 => 1 * 3 = 3

			//�����^2��̌Ăяo��
			std::cout << "�����^2��̌Ăяo��:" << mul<int, float>(1, 2.5f) << std::endl;
		}
#pragma endregion

#pragma region �N���X�e���v���[�g
		/*!
			@class	CTemplate
			@brief	�e���v���[�g�N���X
		*/
		template <typename C>class CTemplate{
		public:
			/*!
				@fn		Func
				@brief	�e���v���[�g�N���X�Ɏ��������֐�

				NOTE:	�e���v���[�g�N���X�𗘗p�����p�����g���Όp����ŌĂяo����B
			*/
			void Func() { std::cout << "�e���v���[�g�N���X�Ɏ�������Ă���֐�" << std::endl; }

			/*!
				@fn			MemberFunc
				@brief		�����Ŏ󂯎�����l�̏o��
				@detail		�����o�֐��̃e���v���[�g��
				@param[in]	�o�͂���l

				NOTE:		�������߂�l���w��ł��܂��B
			*/
			template<typename T>
			void MemberFunc(T value) { std::cout << "�󂯎�����l:" << value << std::endl; }

			/*!
				@fn		AbstractFunc
				@brief	�e���v���[�g�N���X�Ɏ������������֐�

				NOTE:	�p����ɏ������z�֐��𓊂��邱�Ƃ��ł���B
						���p����Œ�`���̂��ӂ����A
						�e���v���[�g�N���X�̃C���X�^���X�����o���Ȃ��Ȃ�̂ō���͂��Ȃ��B
			*/
			//virtual void AbstractFunc()abstract;

			/*!
				@fn			SetValue
				@brief		�e���v���[�g�^�̃����o�ւ̃Z�b�^�[
				@param[in]	�Z�b�g����l
			*/
			inline void SetValue(C value) { m_Value = value; }

			/*!
				@fn		GetValue
				@brief	�e���v���[�g�^�̃����o�̃Q�b�^�[
				@return	�����o
			*/
			inline C GetValue() { return m_Value; }
		private:
			/*!
				@var	m_Value
				@brief	�e���v���[�g�^�̃����o�ϐ�

				NOTE:	��肭�ǂ����ǁA�e���v���[�g�^�������o�ɂ��邱�Ƃ��ł��܂��B
						����͐����̂��߂ɁA�֐��ł���Ă��邯�ǁA��ʓI�ɂ̓R���X�g���N�^
						���������ʁB
			*/
			C m_Value;

		};

		//==================================================================
		//	���N���X�e���v���[�g�̗��p��
		//���p�����Ă��鎞�_�Ńe���v���[�g���\�b�h����Ȃ���!
		//==================================================================

		/*!
			@struct	SBase
			@brief	�p�����\����(�N���X)

			NOTE:	�e���v���[�g�N���X�Ɏ���N���X��n���邱�Ƃ̏ؖ��̂��߁A
					����͋�B
		*/
		struct SBase{};

		/*!
			@class	CInt
			@brief	int�^���e���v���[�g�N���X���g���Čp���B
					�����̈Ӗ����Ȃ��B�����p���ł��邾���B
		*/
		class CInt
			: public CTemplate<int>
		{
		public:
			/*!
				@brief	�f�t�H���g�R���X�g���N�^
			*/
			CInt() = default;

			/*!
				@brief	�f�t�H���g�f�X�g���N�^
			*/
			~CInt() = default;
		private:
		};

		/*!
			@class	CInstance
			@brief	SBase�^���e���v���[�g�N���X���g���Čp���B
		*/
		class CInstance
			: public CTemplate<SBase>
		{
		public:
			/*!
				@brief	�f�t�H���g�R���X�g���N�^
			*/
			CInstance() = default;

			/*!
				@brief	�f�t�H���g�f�X�g���N�^
			*/
			~CInstance() = default;

		private:

		};

#pragma endregion

#pragma region �G�C���A�X�e���v���[�g

		//NOTE:	�ȒP�Ɍ�����"�^�ɕʖ�����������"���ƁB
		//�Ⴆ�΁A"int�^"�ɕʂ̌^�����w�肷�邱�Ƃ��o���܂��B
		//��)
		using INT = int;//C++
		//typedef int INT;//C����
		//�������邱�ƂŃR���p�C����"INT�^" = "int�^"�Ƃ��Ĉ����܂��B

		//	�߂����̂Ƃ���"enum�^"����
		
		//	"INT�^"�̕ʖ��錾���R�����g�A�E�g����Ə����錾�̓G���[��f���܂��B
		//�Ȃ̂Ő��m�ɂ�"INT�^"��"int�^"�ł��B
		INT g_INT;


		//	���̌^�錾�����p�����...
		using IntArray4 = int[4];	//int�^�̗v�f��4�̔z��^

		//���̂悤�ɐ錾��Z�k���Ƃ��o���܂��B
		IntArray4 g_IA4 = {0,1,2,3};
		
		//=======================================================
		//	���p
		//=======================================================
		//	��ʓI�Ɏg���Ă���̂�"Template"�Ƃ̕��p�ł��B
		template<typename P>
		using vector2 = std::vector<std::vector<P>>;//�ʓ|��2�d�ϒ��z�񂪒Z���ł��܂����B


		//�g�p�ၫ
		vector2<int>g_v2;//�g�����͒ʏ�ǂ���
#pragma endregion

	}
}