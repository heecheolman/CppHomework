//#include <iostream>
//
//using namespace std;
//
//class Hero {
//public:
//    Hero() {
//        cout << "Hero 생성" << endl;
//        this->hp = 0;
//        this->mp = 0;
//        this->def = 0;
//    }
//    ~Hero() {
//        cout << "Hero 소멸" << endl;
//    }
//    void showStat() {
//        cout << "hp : " << this->hp << endl;
//        cout << "mp : " << this->mp << endl;
//        cout << "def : " << this->def << endl;
//    }
//    void introduce() {
//        cout << "I'm hero" << endl;
//    }
//    int hp;
//    int mp;
//    int def;
//};
//
//class Warrior : public Hero {
//public:
//    Warrior() {
//        cout << "Warrior 생성" << endl;
//        this->def = 100;
//        this->shield = true;
//    }
//    ~Warrior() {
//        cout << "Warrior 소멸" << endl;
//    }
//
//    void shielding() {
//        if(this->shield) {
//            cout << "실드중입니다" << endl;
//        }
//    }
//    void introduce() {
//        cout << "I'm Warrior" << endl;
//    }
//    bool shield;
//};
//
//int main(void) {
//    //    Hero * h1 = new Warrior();
//    //    h1->introduce();
//
//    Warrior * w1 = (Warrior *)new Hero();
//    w1->shielding();
//    w1->introduce();
//
//    Hero * h1 = new Warrior();
//    h1->introduce();
//
////    Warrior * w2 = (Warrior *)new Hero();
////    Warrior * w3 = new Warrior();
////
////    w2->introduce();
////    w3->introduce();
////
////    Hero * h1 = new Hero();
////    Hero * h2 = new Warrior();
////    h1->introduce();
////    h2->introduce();
//}

#include <iostream>

int main(void) {
    std::cout << "fff" << std::endl;
}
