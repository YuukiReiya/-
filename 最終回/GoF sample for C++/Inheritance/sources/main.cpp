/*!
	@file	main.cpp
	@date	2019/06/05
	@author	�ԏ� �G�P
	@brief	�G���g���[�|�C���g
*/
#include <iostream>
#include "AbstractSample.h"
#include "InterfaceSample.h"

/*!
	@using	Inheritance::Abstract
	@brief	using�f�B���N�e�B�u
*/
using namespace Inheritance::Abstract;

/*!
	@using	Inheritance::Entity
	@brief	using�f�B���N�e�B�u
*/
using namespace Inheritance::Entity;

/*!
	@using	Inheritance::Interface
	@brief	using�f�B���N�e�B�u
*/
using namespace Inheritance::Interface;

/*!
	@using	std
	@brief	using�f�B���N�e�B�u
*/
using namespace std;

/*!
	@def	INHERITANCE
	@brief	�p��
*/
#define INHERITANCE

/*!
	@def	INTERFACE
	@brief	�C���^�[�t�F�C�X
*/
#define INTERFACE

int main()
{
#pragma region ���ۃN���X
#ifdef INHERITANCE
	//	�C���X�^���X��
	Dog*dog;
	Cat*cat;
	dog = new Dog;
	cat = new Cat;

	//	�|�C���^
	AbstractAnimals*animals[2] = { dog,cat };

	cout << "���ۃN���X�̃e�X�g" << endl;

	//	���O�\��
	for (auto it : animals) {
		cout << "������:";
		it->DisplayName();
	}

	//	�X�V����
	//	����͋󏈗��Ȃ̂łȂɂ��s��Ȃ�
	for (auto it : animals) {
		it->Update();
	}
	cout << endl;
#endif // INHERITANCE
#pragma endregion

#pragma region �C���^�[�t�F�C�X
#ifdef INTERFACE

	/*!
		@var	c_EnemyCount
		@brief	�G�l�~�[��
	*/
	static constexpr unsigned int c_EnemyCount = 100;
	ICharacter* player;
	ICharacter* enemys[c_EnemyCount];
	
	//	�C���X�^���X��
	player = new Player;
	for (size_t i = 0; i < c_EnemyCount; ++i) { enemys[i] = new Enemy; }

	//	�Q�ƕ���
	ICharacter* characters[c_EnemyCount + 1];
	characters[0] = player;
	for (size_t i = 0; i < c_EnemyCount; ++i) { characters[i + 1] = enemys[i]; }

	cout << "�C���^�[�t�F�C�X�̃e�X�g" << endl;

	//////////////////////////////////////////
	//	�C���^�[�t�F�C�X�̃��\�b�h�Ăяo����
	//////////////////////////////////////////

	//	�A�N�V����
	for (auto it : characters) { it->Action();	cout << endl; }

	//	�ړ�
	for (auto it : characters) { it->Move(); cout << endl; }

	//	�W�����v
	for (auto it : characters) { it->Jump(); cout << endl; }
#endif // INTERFACE
#pragma endregion


	system("pause");
	return 0;
}