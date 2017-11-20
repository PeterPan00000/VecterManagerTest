#pragma once
#include<Siv3D.hpp>
// 1. �}�N�����`�D
#define EIGEN_NO_DEBUG // �R�[�h����assert�𖳌����D
#define EIGEN_DONT_PARALLELIZE // ����𖳌����D
#define EIGEN_MPL2_ONLY // LGPL���C�Z���X�̃R�[�h���g��Ȃ��D

// 2. Eigen���C���N���[�h�D
#include "Eigen/Core"
//���̃E�����킩��₷��
//https://qiita.com/vs4sh/items/7e8bc95250db8d88bc41

class MyVect
{
public:
	MyVect(const Vec3 initpos,int _num):
		init_pos(initpos),
		num(_num) {
		pos = init_pos;
	}
	MyVect& operator =(const MyVect& v) {
		this->init_pos = v.init_pos;
		this->num = v.num;
		this->pos = v.pos;
		return *this;
	}
	void SetPos(Vec3 _pos) { pos = _pos; }
	Vec3 GetPos() const { return pos; }
	int GetID() const { return num; }

private:
	Vec3 init_pos;
	Vec3 pos;
	int num;//�x�N�g���̓o�^�ԍ�

};

class VecterManager
{
public:
	VecterManager() = default;
	~VecterManager() {};
	void rotatedx(double);
	void rotatedy(double);
	void rotatedz(double);
	void update();
	void add(Vec3, int);
	Vec3 GetVecs(int);
	void EraseVec(int);
private:
	Array<MyVect> vecters;
	Array<int> IDs;//id�����p
	void CalcVec();
	Eigen::Matrix3d tmpM;
};
