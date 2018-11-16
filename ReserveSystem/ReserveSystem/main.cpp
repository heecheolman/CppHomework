//
//  main.cpp
//  ReserveSystem
//
//  Created by HeeCheol Kim on 13/11/2018.
//  Copyright © 2018 HeeCheol Kim. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


using namespace std;

const string STORE_LIST_DIR = "store-list";
const string ORDER_LIST_DIR = "order-list";
const string CONSUMER_DIR = "consumer";
const string DEFAULT_PATH = "/Users/heecheolkim/XcodeProjects/cpp/ReserveSystem/ReserveSystem";
const string STORE_DATA = "store.data";
const string STORE_ITEM_DATA = "store-item.data";

typedef struct VirtualItem {
    int storeId;
    string itemName;
    int itemPrice;
    int itemCount;
} VirtualItem;

typedef struct OrderGroup {
    vector <VirtualItem*> groupedItem;
    int storeId;
} OrderGroup;

// 결제 시스템 인터페이스
class Bill {
public:
    virtual void printBill() = 0;
};



class Item {
public:
    Item(string itemName, int itemPrice, int itemCount) {
        this->itemName = itemName;
        this->itemPrice = itemPrice;
        this->itemCount = itemCount;
    }
    
    void showItemInfo() {
        cout << "아이템 이름 : " << itemName << endl;
        cout << "아이템 가격 : " << itemPrice << endl;
        cout << "아이템 수량: " << itemCount << endl;
    }
    inline void setItemCount(int count) {
        this->itemCount -= count;
    }
    inline string getItemName() {
        return this->itemName;
    }
    inline int getItemCount() {
        return this->itemCount;
    }
    inline int getItemPrice() {
        return this->itemPrice;
    }
private:
    string itemName;
    int itemPrice;
    int itemCount;
};






// 사용자의 장바구니를 표현하는 클래스
class ShoppingBasket {
public:
    ShoppingBasket() {
        this->totalPrice = 0;
    }
    // 장바구니에 아이템을 추가하는 함수, 중복된 아이템이있다면 수량만 추가해줌
    void addItemToBasket(int storeId, string itemName, int itemCount, int itemPrice) {
        for(int i = 0; i < this->basketList.size(); i++) {
            if(basketList[i]->itemName.compare(itemName) == 0) {
                basketList[i]->itemCount += itemCount;
                return;
            }
        }
        VirtualItem *vItem = new VirtualItem;
        vItem->storeId = storeId;
        vItem->itemName = itemName;
        vItem->itemCount = itemCount;
        vItem->itemPrice = itemPrice;
        basketList.push_back(vItem);
    }
    void clearBasket() {
        basketList.erase(basketList.begin(), basketList.end());
        this->totalPrice = 0;
        this->doDelivery = false;
    }
    void showBasketItemList() {
        for(int i = 0; i < basketList.size(); i++) {
            VirtualItem *vi = basketList[i];
            cout << vi->itemName << ": " << vi->itemCount << "개 :" << endl;
        }
    }
    void calcTotalItemPrice() {
        for(int i = 0; i < basketList.size(); i++) {
            VirtualItem *vi = basketList[i];
            this->totalPrice += vi->itemCount * vi->itemPrice;
        }
        if(this->doDelivery) {
            this->totalPrice += 2500;
        }
    }
    inline void setDeliveryState(bool state) {
        this->doDelivery = state;
    }
    inline int getTotalPrice() {
        return this->totalPrice;
    }
    
    vector <VirtualItem*> basketList;
private:
    int totalPrice;
    bool doDelivery;
};






class Store {
public:
    Store(string storeDir, string storeName, string robot, int storeId) {
        this->storeDir = storeDir;
        this->storeName = storeName;
        this->robot = robot;
        this->storeId = storeId;
        this->orderId = 0;
    }
    // 상점의 정보를 보여주는 함수
    void showStoreInfo() {
        cout << "id : " << this->storeId;
        cout << "       상점 이름 : " << this->storeName;
        cout << ":::::: " << this->robot << endl;
    }
    // 프로그램 초기에  아이템리스트에 아이템을 등록하는 함수
    void addItemFromList(string itemName, int itemPrice, int itemCount) {
        Item *item = new Item(itemName, itemPrice, itemCount);
        (this->itemList).push_back(item);
    }
    // 재고 업데이트
    void updateStock(int itemId, int count) {
        itemList[itemId]->setItemCount(count);
    }
    // 사용자가 선택한 아이템의 정보를 주는 함수
    inline Item* getSelectedItem(int selectedItem) {
        return itemList[selectedItem];
    }
    void showItemList() {
        for(int i = 0; i < (this->itemList).size(); i++) {
            cout << i + 1 << "번 아이템" << endl;
            (this->itemList[i])->showItemInfo();
            cout << "---------------------" << endl;
        }
    }

    inline int getStoreId() {
        return this->storeId;
    }
    inline void increaseOrderId() {
        (this->orderId)++;
    }
    inline int getOrderId() {
        return this->orderId;
    }
private:
    string storeDir;
    string storeName;
    string robot;
    int orderId;
    int storeId;
public:
    vector <Item*> itemList;
};

class Time {
public:
    char* getCurrentTimeYYMMDD() {
        time(&(this->rawtime));
        this->timeInfo = localtime(&(this->rawtime));
        strftime(this->buffer, 80, "%Y%m%d", this->timeInfo);
        return buffer;
    }
    char* getCurrentTimeYYMMDDHHMMSS() {
//        time(&(this->rawtime));
//        this->timeInfo = localtime(&(this->rawtime));
        strftime(this->buffer, 80, "%Y%m%d%H%M%S", this->timeInfo);
        return buffer;
    }
    char* getCurrentTimeBeautify() {
        strftime(this->buffer, 80, "%Y-%m-%d %H:%M:%S", this->timeInfo);
        return buffer;
    }
    void setTimeInfo() {
        time(&(this->rawtime));
        this->timeInfo = localtime(&(this->rawtime));
    }
            
private:
    time_t rawtime;
    tm* timeInfo;
    char buffer[80];
};

class POS {
public:
    virtual void purchase(ofstream *out, vector <OrderGroup> group) = 0;
protected:
    Time t;
    ofstream fileout;
};

class OrderSheet : public POS {
public:
    OrderSheet() {
        
    }
    virtual void purchase(ofstream *out, vector <OrderGroup> group) {
//        string CONSUMER_PATH = this->defaultPath + "/" + CONSUMER_DIR;
//        for(int i = 0; i < group.size(); i++) {
//            os.purchase(&out, &group[i]);
//        }
        
        // 오늘날짜를 얻어온다.
        string CURRENT_DATE = t.getCurrentTimeYYMMDD();
        // store폴더를 결정
        for(int i = 0; i < group.size(); i++) {
            OrderGroup groupEle = group[i];
            string STORE_ID = to_string(groupEle.storeId + 1);
            STORE_ID = STORE_ID.length() == 1 ? "0" + STORE_ID : STORE_ID;
            string ORDER_SHEET_PATH = DEFAULT_PATH + "/" + STORE_LIST_DIR + "/" + "store" + STORE_ID + "/" + ORDER_LIST_DIR + "/" + CURRENT_DATE;
            const char *CHAR_ORDER_SHEET_PATH = ORDER_SHEET_PATH.c_str();
            int mkdirState = mkdir(CHAR_ORDER_SHEET_PATH, 0777);
            
            if(mkdirState == 0 || errno == EEXIST) {
                t.setTimeInfo();
                string ORDER_FILE = (string)t.getCurrentTimeYYMMDDHHMMSS();
                for(int j = 0; j < groupEle.groupedItem.size(); j++) {
                    string FULLPATH = ORDER_SHEET_PATH + "/" + ORDER_FILE;
                    out->open(FULLPATH, ios_base::app);
                    if(out->is_open()) {
                        *out << groupEle.groupedItem[j]->itemName << endl;
                        *out << groupEle.groupedItem[j]->itemCount << endl;
                        *out << groupEle.groupedItem[j]->itemPrice * groupEle.groupedItem[j]->itemCount << endl;
                    } else {
                        cout << "FAIL:: FILE EXPORT" << endl;
                    }
                    out->close();
                }
            } else {
                cout << "MKDIR ERROR" << endl;
            }
            usleep(1000000);
        }
//        string STORE_ID = to_string(group->storeId + 1);
        // 한글자일경우 01 로 만들어주고 10 이면 그냥 둠
//        STORE_ID = STORE_ID.length() == 1 ? "0" + STORE_ID : STORE_ID;
        
        // 오늘날짜 경로임
//        string ORDER_SHEET_PATH = DEFAULT_PATH + "/" + STORE_LIST_DIR + "/" + "store" + STORE_ID + "/" + ORDER_LIST_DIR + "/" + CURRENT_DAY;
        // mkdir을 위해 임시로 변환
//        const char *CHAR_ORDER_SHEET_PATH = ORDER_SHEET_PATH.c_str();
        
        // 폴더 생성, 생성된 상태는 mkdirState 가 가지고있음
        // 0 이면 성공적으로 생성
        // EEXIST 는 이미 있는 디렉토리이므로 그쪽으로 이동하면 됨
//        int mkdirState = mkdir(CHAR_ORDER_SHEET_PATH, 0777);
//        if(mkdirState == 0 || errno == EEXIST) {
//            string ORDER_FILE = (string)t.getCurrentTimeYYMMDDHHMMSS();
//            for(int i = 0; i < group->groupedItem.size(); i++) {
//                string FULLPATH = ORDER_SHEET_PATH + "/" + ORDER_FILE;
//                out->open(FULLPATH, ios_base::app);
//                if(out->is_open()) {
//                    *out << group->groupedItem[i]->itemName << endl;
//                    *out << group->groupedItem[i]->itemCount << endl;
//                    *out << group->groupedItem[i]->itemPrice * group->groupedItem[i]->itemCount << endl;
//                } else {
//                    cout << "FAIL:: FILE EXPORT" << endl;
//                }
//                out->close();
//            }
//        } else {
//            cout << "MKDIR ERROR" << endl;
//        }
    }
//    virtual void purchase(ofstream *out, OrderGroup *group) {
//        // 오늘날짜를 얻어온다.
//        string CURRENT_DAY = t.getCurrentTimeYYMMDD();
//        // store폴더를 결정
//        string STORE_ID = to_string(group->storeId + 1);
//        // 한글자일경우 01 로 만들어주고 10 이면 그냥 둠
//        STORE_ID = STORE_ID.length() == 1 ? "0" + STORE_ID : STORE_ID;
//
//        // 오늘날짜 경로임
//        string ORDER_SHEET_PATH = DEFAULT_PATH + "/" + STORE_LIST_DIR + "/" + "store" + STORE_ID + "/" + ORDER_LIST_DIR + "/" + CURRENT_DAY;
//        // mkdir을 위해 임시로 변환
//        const char *CHAR_ORDER_SHEET_PATH = ORDER_SHEET_PATH.c_str();
//
//        // 폴더 생성, 생성된 상태는 mkdirState 가 가지고있음
//        // 0 이면 성공적으로 생성
//        // EEXIST 는 이미 있는 디렉토리이므로 그쪽으로 이동하면 됨
//        int mkdirState = mkdir(CHAR_ORDER_SHEET_PATH, 0777);
//        if(mkdirState == 0 || errno == EEXIST) {
//            string ORDER_FILE = (string)t.getCurrentTimeYYMMDDHHMMSS();
//            for(int i = 0; i < group->groupedItem.size(); i++) {
//                string FULLPATH = ORDER_SHEET_PATH + "/" + ORDER_FILE;
//                out->open(FULLPATH, ios_base::app);
//                if(out->is_open()) {
//                    *out << group->groupedItem[i]->itemName << endl;
//                    *out << group->groupedItem[i]->itemCount << endl;
//                    *out << group->groupedItem[i]->itemPrice * group->groupedItem[i]->itemCount << endl;
//                } else {
//                    cout << "FAIL:: FILE EXPORT" << endl;
//                }
//                out->close();
//            }
//        } else {
//            cout << "MKDIR ERROR" << endl;
//        }
//    }
};

class Receipt : public POS {
public:
    Receipt() {
        
    }
    virtual void purchase(ofstream *out, vector <OrderGroup> group) {
        // 날짜를 기반으로 한 폴더를 만들고
        // group 에 있는 모든 상품들을 한개의 파일에 등록
        string CONSUMER_PATH = DEFAULT_PATH + "/" + CONSUMER_DIR;
        string CURRENT_DATE = t.getCurrentTimeYYMMDD();
        CONSUMER_PATH = CONSUMER_PATH + "/" + CURRENT_DATE;
        const char *CHAR_CONSUMER_PATH = CONSUMER_PATH.c_str();
        int mkdirState = mkdir(CHAR_CONSUMER_PATH, 0777);
        t.setTimeInfo();
        string CURRENT_TIME = (string)t.getCurrentTimeYYMMDDHHMMSS();
        string FORMAT_TIME = (string)t.getCurrentTimeBeautify();
        CONSUMER_PATH = CONSUMER_PATH + "/" + CURRENT_TIME;
        out->open(CONSUMER_PATH);
        if(mkdirState == 0 || errno == EEXIST) {
            *out << FORMAT_TIME << endl;
            if(out->is_open()) {
                for(int i = 0; i < group.size(); i++) {
                    OrderGroup og = group[i];
                    *out << "----" << og.storeId + 1 << "번 상점 ---" << endl;
                    for(int j = 0; j < og.groupedItem.size(); j++) {
                        *out << og.groupedItem[j]->itemName << endl;
                        *out << og.groupedItem[j]->itemCount << endl;
                        *out << og.groupedItem[j]->itemPrice * og.groupedItem[j]->itemCount << endl;
                    }
                }
            } else {
                cout << "FAIL:: FILE EXPORT" << endl;
            }
        } else {
            cout << "MKDIR ERROR" << endl;
        }
        out->close();
    }
};




class MiddleMan {
public:
    MiddleMan() {
        this->defaultPath = DEFAULT_PATH;
        this->shoppingBasket = new ShoppingBasket();
    }
    // 상품을 초기 등록
    void registStoreList() {
        string STORE_LIST_PATH = this->defaultPath + "/" + STORE_LIST_DIR;
        const char *CHAR_STORE_LIST_PATH = STORE_LIST_PATH.c_str();
        dir = opendir(CHAR_STORE_LIST_PATH);
        int storeId = 0;
        if(dir) {
            while((ent = readdir(dir))) {
                string STORE_DIR;
                STORE_DIR = ent->d_name;
                if(STORE_DIR.length() >= 7) {
                    string storeDataPath = STORE_LIST_PATH + "/" + STORE_DIR + "/" + STORE_DATA;
                    in.open(storeDataPath);
                    if(in.is_open()) {
                        string storeName;
                        string storeRobot;
                        getline(in, storeName);
                        getline(in, storeRobot);
                        storeId++;
                        // 스토어 생성
                        Store *store = new Store(STORE_DIR, storeName, storeRobot, storeId);
                        // 스토어를 중개자의 리스트에 넣어줌
                        (this->storeList).push_back(store);
                        // 해당 스토어의 아이템리스트들을 등록시켜줘야함
                        ifstream datain;
                        datain.open(STORE_LIST_PATH + "/" + STORE_DIR + "/" + STORE_ITEM_DATA);
                        while(!datain.eof()) {
                            string itemName;
                            int itemPrice;
                            int itemCount;
                            datain >> itemName >> itemPrice >> itemCount;
                            if(itemName.length()) {
                                // 아이템 초기 등록
                                store->addItemFromList(itemName, itemPrice, itemCount);
                            }
                        }
                        datain.close();
                    }
                    in.close();
                }
            }
            closedir(dir);
        } else {
            cout << "READING FILE FAIL" << endl;
            exit(1);
        }
    }
    void showStoreList() {
        for(int i = 0; i < storeList.size(); i++) {
            Store *target = storeList[i];
            target->showStoreInfo();
        }
    }
    void groupingBasket() {
        bool hasStoreId;
        for(int i = 0; i < this->shoppingBasket->basketList.size(); i++) {
            // storeId initializing
            hasStoreId = false;
            // vi 로 장바구니의 아이템 가리킴
            VirtualItem *vi = this->shoppingBasket->basketList[i];
            // 그룹을 돌면서 vi 의 상점 id 와 그룹된 상점의 id가 같으면 넣어주고 hasStoreId 를 true로 바꿔줌
            for(int j = 0; j < group.size(); j++) {
                if(group[j].storeId == vi->storeId) {
                    group[j].groupedItem.push_back(vi);
                    hasStoreId = true;
                    break;
                }
            }
            // 만약 hasStoreId 가 false 라면 장바구니의 아이템이 그룹에 속하지않는것임으로 새로 그룹을 만들어줌
            if(!hasStoreId) {
                OrderGroup og;
                og.storeId = vi->storeId;
                og.groupedItem.push_back(vi);
                group.push_back(og);
            }
        }
    }
    
    
    // 각 상점들에 주문서를 출력
    void makeOutOrderSheet() {
        os.purchase(&out, group);
//        for(int i = 0; i < group.size(); i++) {
//            os.purchase(&out, &group[i]);
//            // 1초 = 1000000 microseconds
//            usleep(1000000);
//            out.close();
//        }
    }
    void makeOutReceipt() {
        r.purchase(&out, group);
//        string CONSUMER_PATH = this->defaultPath + "/" + CONSUMER_DIR;
//        for(int i = 0; i < group.size(); i++) {
//            os.purchase(&out, &group[i]);
//        }
        
//        out.open();
        /*
         목표 : 해당 주문건에대해 영수증을 출력해야함
         1. group에 있는 아이템들을 순회하며
         
         
         */
    }
    // 중개자의 장바구니에 추가
    void putItemToBasket(int storeId, string itemName, int itemCount, int itemPrice) {
        // 장바구니에 더해주고
        shoppingBasket->addItemToBasket(storeId, itemName, itemCount, itemPrice);
        cout << itemName << " : " << itemCount << "개 추가" << endl;
    }
    void clearBasketData() {
        this->shoppingBasket->clearBasket();
        this->group.erase(group.begin(), group.end());
    }
private:
    string defaultPath;
    DIR *dir;
    struct dirent *ent;
    ofstream out;
    ifstream in;
    OrderSheet os;
    Receipt r;
public:
    vector <OrderGroup> group;
    vector <Store*> storeList;
    ShoppingBasket *shoppingBasket;
};

class MessageSystem {
public:
    static void selectStoreMessage() {
        cout << "-----SELECT STORE-----   0 누르면 주문 " << endl;
    }
    static void selectItemMessage() {
        cout << "-----상품을 고르세요-----" << endl;
    }
    static bool willDelivery() {
        int select = 0;
        cout << "배송서비스를 이용하시겠습니까 ? 이용시 2500원 추가비용 발생" << endl;
        do {
            cout << "1. 이용함" << endl;
            cout << "2. 이용안함" << endl;
            cin >> select;
        } while(!(select == 1 || select == 2));
        return select == 1;
    }
    static bool willPayment() {
        int select = 0;
        cout << "결제하시겠습니까 ?" << endl;
        do {
            cout << "1. 결제" << endl;
            cout << "2. 결제안함" << endl;
            cin >> select;
        } while(!(select == 1|| select == 2));
        return select == 1;
    }
};

int main(void) {
    MiddleMan * md = new MiddleMan();
    md->registStoreList();
    int menu;
    cout << endl;
    do {
        MessageSystem().selectStoreMessage();
        md->showStoreList();
        cin >> menu;
        if(0 < menu && menu <= md->storeList.size()) {
            // 선택함
            int storeId = menu - 1;
            Store *selectedStore = md->storeList[storeId];
            // 아이템들을 보여줌
            // 아이템 고르기
            int selectItem;
            do {
                selectedStore->showItemList();
                MessageSystem().selectItemMessage();
                cin >> selectItem;
                // 아이템이 리스트내에 있는경우
                if(0 < selectItem && selectItem <= selectedStore->itemList.size()) {
                    // 장바구니에 담음
                    Item *selectedItem = selectedStore->getSelectedItem(selectItem - 1);
                    // 수량
                    int itemCount;
                    cout << "수량 선택 >> ";
                    cin >> itemCount;
                    if(0 < itemCount && itemCount <= selectedItem->getItemCount()) {
                        // 장바구니 추가
                        md->putItemToBasket(storeId, selectedItem->getItemName(), itemCount, selectedItem->getItemPrice());
                        // 재고 갱신
                        selectedStore->updateStock(selectItem - 1, itemCount);
                        // 장바구니 리스트 보여주기
                        md->shoppingBasket->showBasketItemList();
                    } else {
                        cout << "수량이 유효하지 않습니다" << endl;
                    }
                } else {
                    cout << "없는 아이템입니다" << endl;
                }
                
            } while(selectItem != -1);
        } else if(menu == 0) {
            if(md->shoppingBasket->basketList.size() > 0) {
                // 배송 여부를 묻고 배송시 2500 원 추가
                md->shoppingBasket->setDeliveryState(MessageSystem().willDelivery());
                // 총 금액 계산
                md->shoppingBasket->calcTotalItemPrice();
                cout << "총 금액 : " << md->shoppingBasket->getTotalPrice();
                bool isPayment = MessageSystem().willPayment();
                // 주문서 등록 하고, 지불이 이루어졌으니
                // consumer 에 영수증  ㄱ ㄱ
                if(isPayment) {
                    getchar();
                    md->groupingBasket();
                    md->makeOutOrderSheet();
                    md->makeOutReceipt();
                    // 영수증 출력
                } else {
                    cout << "결제를 취소했습니다. 돌아갑니다." << endl;
                }
            } else {
                cout << "장바구니에 담아놓은 물품이 없습니다" << endl;
            }
            md->clearBasketData();
        }
    } while(menu != -1);
    
    // 주문
    /*
        1. 배송여부
        2. 배송비 + 2500 원
        3. 주문이 들어왔다는 주문로그가 찍혀야함
            3-1. 각 가게의 order-list 폴더에 order01 order02 ...
        4. 판매완료
            4-1. 각 가게의 order-list 의 order01-success 라고 바꿔줌
            4-2. 구매자에게 영수증을 줌 consumer 폴더의 receipt01 ...
     
     */
    // 장바구니에 아이템이 있을 경우

    
    
    return 0;
}
