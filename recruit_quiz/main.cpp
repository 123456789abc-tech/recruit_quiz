#include<iostream>
#include<string>
#include<vector>
#include<random>
using namespace std;

//問題文と答えをまとめる構造体
struct Question
{
	string q;	//問題文
	int	a;		//答え
};

int main()
{
	vector<Question> questions(3);
	
	random_device rd;
	mt19937 rand(rd());

	//掛け算
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	questions[0].q = to_string(x) + "x" + to_string(y)+ "の答えは？";
	questions[0].a = x * y;

	//割り算
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	questions[1].q = to_string(x*y) + "÷" + to_string(y) + "の答えは？";
	questions[1].a = x ;

	//複雑な式
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].q =
		to_string(x) + "-(" + to_string(y*w) + "+" + to_string(z*w) + ")÷" +
		to_string(y) + "の答えは？";
	questions[2].a = x-(y+z) ;

	//三角形の面積
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 2;
	questions.push_back({
		"面積"+to_string(x*y/2)+"cm^2、底辺"+to_string(y)+"cmの三角形の高さを求めよ。",
		x});

	//円錐の体積
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 3;
	questions.push_back({
		"底面の半径" + to_string(x) + "cm　高さ" + to_string(y) + "cmの円錐がある。\n"+
		"この円錐の体積をπcm^3とする。ｘの値を求めよ。",
		x * x * y / 3 });


	cout << "[リクルート試験対策クイズ]\n";

	for (const auto& e : questions) {
		cout << e.q << "\n";
		int answer;
		cin >> answer;

		if (answer == e.a) {
			cout << "正解！\n";
		}else {
			cout << "間違い！正解は" << e.a << "\n";
		}
	}//	for questions
}
