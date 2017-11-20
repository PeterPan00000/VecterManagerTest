#include "VecterManager.h"

void VecterManager::CalcVec() {
	Vec3 tmpvec;
	Vec3 tmppos;
	for (auto& iter : vecters) {
		tmppos = iter.GetPos();
		tmpvec.x = tmpM(0, 0)*tmppos.x + tmpM(0, 1)*tmppos.y + tmpM(0, 2)*tmppos.z;
		tmpvec.y = tmpM(1, 0)*tmppos.x + tmpM(1, 1)*tmppos.y + tmpM(1, 2)*tmppos.z;
		tmpvec.z = tmpM(2, 0)*tmppos.x + tmpM(2, 1)*tmppos.y + tmpM(2, 2)*tmppos.z;
		iter.SetPos(tmpvec);
	}
}
void VecterManager::rotatedx(double rad) {
	tmpM << 1.0, 0.0, 0.0,
		0.0, cos(rad), -sin(rad),
		0.0, sin(rad), cos(rad);
	CalcVec();
}
void VecterManager::rotatedy(double rad) {
	tmpM << cos(rad), 0.0, sin(rad),
		0.0, 1.0, 0.0,
		-sin(rad), 0.0, cos(rad);
	CalcVec();
}
void VecterManager::rotatedz(double rad){
	tmpM << cos(rad), -sin(rad), 0.0,
		sin(rad), cos(rad), 0.0,
		0.0, 0.0, 1.0;
	CalcVec();
}
void VecterManager::update() {
}
void VecterManager::add(const Vec3 _pos, const int _num) {
	for (auto& it : IDs) {
		if (it == _num) {
			return;
		}
	}
	IDs.emplace_back(_num);
	vecters.emplace_back(_pos, _num);

}
Vec3 VecterManager::GetVecs(const int id) {
	auto& it = std::find_if(vecters.begin(), vecters.end(), [&](const MyVect& ins) {return id == ins.GetID() ? true : false; });
	return it->GetPos();
}
void VecterManager::EraseVec(const int id) {
	auto& iter = std::remove_if(vecters.begin(), vecters.end(), [&](const MyVect& ins) {return id == ins.GetID() ? true : false; });
	vecters.erase(iter, vecters.end());
	auto& it= std::remove_if(IDs.begin(), IDs.end(), [&](const int& ins) {return id == ins ? true : false; });
	IDs.erase(it, IDs.end());
}