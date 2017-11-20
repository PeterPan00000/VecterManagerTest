
# include "VecterManager.h"

void Main()
{
	Camera camera;
	camera.lookat.set(0, 30, 0);
	camera.pos.set(0, 120, -120);
	Graphics3D::SetCamera(camera);
	Box box(Vec3(0, 0, 0), Vec3(50, 1, 50));
	Box wbox(Vec3(0, 0, 0), Vec3(1, 10, 50));
	Box wbox2(Vec3(0, 0, 0), Vec3(1, 10, 50));
	Box wbox3(Vec3(0, 0, 0), Vec3(50, 10, 1));
	Box wbox4(Vec3(0, 0, 0), Vec3(50, 10, 1));
	const double rad = 30.0*Pi / 180.0;

	VecterManager *vm = new VecterManager;
	//-----------SetVect----------------
	vm->add(Vec3(-25.0, 0.0, 0.0), 0);
	vm->add(Vec3(25.0, 0.0, 0.0), 1);
	vm->add(Vec3(0.0, 0.0, -25.0), 2);
	vm->add(Vec3(0.0, 0.0, 25.0), 3);
	vm->add(Vec3(0.0, 0.0, 25.0), 4);
	while (System::Update())
	{
		if (Input::KeyUp.pressed) {//x
			box.rotation.rotateRollPitchYaw(0.0, rad, 0.0);
			wbox.rotation.rotateRollPitchYaw(0.0, rad, 0.0);
			wbox2.rotation.rotateRollPitchYaw(0.0, rad, 0.0);
			wbox3.rotation.rotateRollPitchYaw(0.0, rad, 0.0);
			wbox4.rotation.rotateRollPitchYaw(0.0, rad, 0.0);
			vm->rotatedx(rad);
		}
		if (Input::KeyDown.pressed) {
			box.rotation.rotateRollPitchYaw(0.0, -rad, 0.0);
			wbox.rotation.rotateRollPitchYaw(0.0, -rad, 0.0);
			wbox2.rotation.rotateRollPitchYaw(0.0, -rad, 0.0);
			wbox3.rotation.rotateRollPitchYaw(0.0, -rad, 0.0);
			wbox4.rotation.rotateRollPitchYaw(0.0, -rad, 0.0);
			vm->rotatedx(-rad);
		}
		if (Input::KeyLeft.pressed) {//z
			box.rotation.rotateRollPitchYaw(rad, 0.0, 0.0);
			wbox.rotation.rotateRollPitchYaw(rad, 0.0, 0.0);
			wbox2.rotation.rotateRollPitchYaw(rad, 0.0, 0.0);
			wbox3.rotation.rotateRollPitchYaw(rad, 0.0, 0.0);
			wbox4.rotation.rotateRollPitchYaw(rad, 0.0, 0.0);
			vm->rotatedz(rad);
		}
		if (Input::KeyRight.pressed) {
			box.rotation.rotateRollPitchYaw(-rad, 0.0, 0.0);
			wbox.rotation.rotateRollPitchYaw(-rad, 0.0, 0.0);
			wbox2.rotation.rotateRollPitchYaw(-rad, 0.0, 0.0);
			wbox3.rotation.rotateRollPitchYaw(-rad, 0.0, 0.0);
			wbox4.rotation.rotateRollPitchYaw(-rad, 0.0, 0.0);
			vm->rotatedz(-rad);
		}
		if (Input::KeySpace.clicked) {
			vm->EraseVec(4);//要素の削除
		}
		wbox.center.set(vm->GetVecs(0));//壁の中心座標を指定
		wbox2.center.set(vm->GetVecs(1));
		wbox3.center.set(vm->GetVecs(2));
		wbox4.center.set(vm->GetVecs(3));

		box.draw(Palette::Red);
		wbox.draw(Palette::White);
		wbox2.draw(Palette::White);
		wbox3.draw(Palette::White);
		wbox4.draw(Palette::White);
	}
}
