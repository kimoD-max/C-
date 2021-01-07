#include <iostream>
#include <string>
#include <vector>
#define MAX 1000  //最大可以放多少个联系人

//联系人结构体
struct person
{
	std::string name;
	int sex;//性别 1 男 2女
	int age;
	int telenumber;
	std::string address;
};

//通讯录结构体

struct ADDressbooks
{
	struct person personArray[MAX]; //通讯录中保存的联系人数组
	//vector <person> personArray;
	int m_Size; //通讯录当前记录联系人个数
};

//菜单界面
void showMenu() {
	std::cout << "****** ****** ****** ******" << std::endl;
	std::cout << "****** 1.添加联系人 ******" << std::endl;
	std::cout << "****** 2.显示联系人 ******" << std::endl;
	std::cout << "****** 3.删除联系人 ******" << std::endl;
	std::cout << "****** 4.查找联系人 ******" << std::endl;
	std::cout << "****** 5.修改联系   ****** " << std::endl;
	std::cout << "****** 6.清空联系人 ******" << std::endl;
	std::cout << "****** 0.退出通讯录 ******" << std::endl;
	std::cout << "****** ****** ****** ******" << std::endl;
}

//添加联系人
void addperson(ADDressbooks * abs){
//判断通讯录说否满了
	if (abs->m_Size == MAX)
	{
		std::cout << "通讯录已满" << std::endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		std::string name;
		std::cout << "请输入姓名:" ;
		std::cin >> name;
		abs->personArray[abs->m_Size].name = name;

		//性别
		std::cout << "1--男" << std::endl;
		std::cout << "请输入性别:" ;

		int sex = 0;
		while (true) {
			std::cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].sex = sex;
				break;
			}
			std::cout << "输入有误重新输入" << std::endl;
		}

		//年龄
		int age;
		std::cout << "请输入年龄:" ;
		std::cin >> age;
		abs->personArray[abs->m_Size].age = age;

		//电话
		int number;
		std::cout << "请输入电话号码:" ;
		std::cin >> number;
		abs->personArray[abs->m_Size].telenumber = number;

		//住址
		std::string address;
		
		
		std::cout << "请输入家庭住址:";
		std::cin >> address;

				abs->personArray[abs->m_Size].address = address;

		
		//更新通讯录人数
			abs->m_Size++;
			std::cout << "添加成功" << std::endl;
			system("cls");//清除屏幕操作
	}
}
//显示联系人
void showperson(ADDressbooks* abs) {
	for (int i=0; i<abs->m_Size; i++) {
		std::cout << "姓名:" << abs->personArray[i].name << std::endl;
		std::cout << "年龄:" << abs->personArray[i].age<< std::endl;
		std::cout << "性别:" << (abs->personArray[i].sex == 1 ? "男" : "女")<< std::endl;
		std::cout << "电话:"<< abs->personArray[i].telenumber<< std::endl;
		std::cout << "家庭住址" << abs->personArray[i].address << std::endl;
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在
int isEXist(ADDressbooks* abs, std::string name) {

	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].name ==name){ return i; 
		}
	}
	return -1;
}
//删除联系人
void removeperson(ADDressbooks *abs) {
	std::string d_name ;
	std::cout << "请输入要删除的人的姓名:";
	std::cin >> d_name;
	int ret = isEXist(abs, d_name);
	if (ret == -1) {
		std::cout << "查无此人" << std::endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i+ 1]; //覆盖掉要删除的位置
		}
		abs->m_Size--;//更新联系人数量
		std::cout << "删除成功";
	}	
}
//查找联系人
void findperson(ADDressbooks* abs) {
	std::string name;
	std::cout << "输入要查询的名字:";
	std::cin >> name;
	int ret=isEXist(abs, name);
	if (ret !=-1) {
		std::cout << "查到了" << std::endl;
		std::cout << "姓名:" << abs->personArray[ret].name << std::endl;
		std::cout << "年龄:" << abs->personArray[ret].age << std::endl;
		std::cout << "性别:" << (abs->personArray[ret].sex == 1 ? "男" : "女") << std::endl;
		std::cout << "电话:" << abs->personArray[ret].telenumber << std::endl;
		std::cout << "家庭住址" << abs->personArray[ret].address << std::endl;
		std::cout << "*********************************" << std::endl;
	}
	else {
		std::cout << "查无此人" << std::endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyperson(ADDressbooks* abs) {
	std::string name;
	std::cout << "请输入要修改的联系人的姓名:";
	std::cin >> name;
	int ret=isEXist(abs, name);

	if (ret != -1) {
		std::cout << "原信息" << std::endl;
		std::cout << "姓名:" << abs->personArray[ret].name << std::endl;
		std::cout << "年龄:" << abs->personArray[ret].age << std::endl;
		std::cout << "性别:" << (abs->personArray[ret].sex == 1 ? "男" : "女") << std::endl;
		std::cout << "电话:" << abs->personArray[ret].telenumber << std::endl;
		std::cout << "家庭住址" << abs->personArray[ret].address << std::endl;
		std::cout << "*********************************"<< std::endl;
		std::cout << "请修改信息" << std::endl;
		 
		std::string name;
		std::cout << "请输入姓名:";
		std::cin >>abs->personArray[ret].name;

		//性别
		std::cout << "1--男" << std::endl;
		std::cout << "2--女" << std::endl;
		std::cout << "请输入性别:";

		int sex = 0;
		while (true) {
			std::cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].sex = sex;
				break;
			}
			std::cout << "输入有误重新输入" << std::endl;
		}
		//年龄
		int age;
		std::cout << "请输入年龄:";
		std::cin >>abs->personArray[ret].age ;

		//电话
		int number;
		std::cout << "请输入电话号码:";
		std::cin >>abs->personArray[ret].telenumber;

		//住址
		std::cout << "请输入家庭住址:";
		std::cin >> abs->personArray[ret].address;
		std::cout << "*********************************" << std::endl;
		std::cout << "修改成功" << std::endl;
	}
}
//清空通讯录
void rm_rf(ADDressbooks* abs) {
	std::cout << "确定要清空通讯录全部信息?" << std::endl;
	std::string y;
	std::cout << "按[y]确定其他键结束:";
	std::cin >> y;
	if (y == "y") {
		abs->m_Size = 0;
		std::cout << "清除成功!"<< std::endl;
		system("pause");
		system("cls");
	}
	else {
		return;
	}
}

int main() {

	//创建结构体变量
	ADDressbooks abs;
	person psn;
	abs.m_Size = 0; //初始化联系人


	while (true) {
	showMenu();
	int select = 0;
	std::cout << "请输入你的选择:";
	std::cin >> select;                                                                                                          
	
	switch (select) {

	case 1:
		//.添加联系人
		addperson(&abs);
		break;

	case 2:
		//显示联系人
		showperson(&abs);
		break;

	case 3:
		//删除联系人
		removeperson(&abs);
		break;

	case 4:
		//查找联系人
		findperson(&abs);
		break;

	case 5:
		//修改联系
		modifyperson(&abs);
		break;

	case 6:
		//清空联系人
		rm_rf(&abs);
		break;

	case 0:
		//退出通讯录
		system("pause");
		std::cout << "欢迎下次使用" << std::endl;
		return 0;
		break;
	}
	
}
	
}
