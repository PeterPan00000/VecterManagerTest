ダウンロードありがとうございます．
バグが見つかったらブログのコメントに報告してもらえると助かります．質問や要望も受け付けています．

クラス内の関数の説明をします．

void rotatedx(double rad);
x軸まわりにrad[rad]回転させます．回転の中心となるオブジェクトがx軸で回転したら，一緒にこの関数を呼んでください．
void rotatedy(double rad);
y軸まわりにrad[rad]回転させます．
void rotatedz(double rad);
z軸まわりにrad[rad]回転させます．


void update();
今のところ何もしません．後日アップデートする予定です．

void add(Vec3 pos, int id);
箱の壁の初期位置とそのidをデータとしてリストに登録します．idがもう登録済みだった場合は何もしません．

Vec3 GetVecs(int id);
idが一致した壁の中心座標を返します．一致するものがない場合はエラーになります．

void EraseVec(int id);
idが一致したデータをリストから削除します．

