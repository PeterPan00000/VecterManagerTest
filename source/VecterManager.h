#pragma once
#include<Siv3D.hpp>
// 1. マクロを定義．
#define EIGEN_NO_DEBUG // コード内のassertを無効化．
#define EIGEN_DONT_PARALLELIZE // 並列を無効化．
#define EIGEN_MPL2_ONLY // LGPLライセンスのコードを使わない．

// 2. Eigenをインクルード．
#include "Eigen/Core"
//下のウラルわかりやすい
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
	int num;//ベクトルの登録番号

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
	Array<int> IDs;//id検索用
	void CalcVec();
	Eigen::Matrix3d tmpM;
};
