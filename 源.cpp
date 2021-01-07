#include <iostream>
#include <string>
#include <vector>
#define MAX 1000  //�����ԷŶ��ٸ���ϵ��

//��ϵ�˽ṹ��
struct person
{
	std::string name;
	int sex;//�Ա� 1 �� 2Ů
	int age;
	int telenumber;
	std::string address;
};

//ͨѶ¼�ṹ��

struct ADDressbooks
{
	struct person personArray[MAX]; //ͨѶ¼�б������ϵ������
	//vector <person> personArray;
	int m_Size; //ͨѶ¼��ǰ��¼��ϵ�˸���
};

//�˵�����
void showMenu() {
	std::cout << "****** ****** ****** ******" << std::endl;
	std::cout << "****** 1.�����ϵ�� ******" << std::endl;
	std::cout << "****** 2.��ʾ��ϵ�� ******" << std::endl;
	std::cout << "****** 3.ɾ����ϵ�� ******" << std::endl;
	std::cout << "****** 4.������ϵ�� ******" << std::endl;
	std::cout << "****** 5.�޸���ϵ   ****** " << std::endl;
	std::cout << "****** 6.�����ϵ�� ******" << std::endl;
	std::cout << "****** 0.�˳�ͨѶ¼ ******" << std::endl;
	std::cout << "****** ****** ****** ******" << std::endl;
}

//�����ϵ��
void addperson(ADDressbooks * abs){
//�ж�ͨѶ¼˵������
	if (abs->m_Size == MAX)
	{
		std::cout << "ͨѶ¼����" << std::endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		std::string name;
		std::cout << "����������:" ;
		std::cin >> name;
		abs->personArray[abs->m_Size].name = name;

		//�Ա�
		std::cout << "1--��" << std::endl;
		std::cout << "�������Ա�:" ;

		int sex = 0;
		while (true) {
			std::cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].sex = sex;
				break;
			}
			std::cout << "����������������" << std::endl;
		}

		//����
		int age;
		std::cout << "����������:" ;
		std::cin >> age;
		abs->personArray[abs->m_Size].age = age;

		//�绰
		int number;
		std::cout << "������绰����:" ;
		std::cin >> number;
		abs->personArray[abs->m_Size].telenumber = number;

		//סַ
		std::string address;
		
		
		std::cout << "�������ͥסַ:";
		std::cin >> address;

				abs->personArray[abs->m_Size].address = address;

		
		//����ͨѶ¼����
			abs->m_Size++;
			std::cout << "��ӳɹ�" << std::endl;
			system("cls");//�����Ļ����
	}
}
//��ʾ��ϵ��
void showperson(ADDressbooks* abs) {
	for (int i=0; i<abs->m_Size; i++) {
		std::cout << "����:" << abs->personArray[i].name << std::endl;
		std::cout << "����:" << abs->personArray[i].age<< std::endl;
		std::cout << "�Ա�:" << (abs->personArray[i].sex == 1 ? "��" : "Ů")<< std::endl;
		std::cout << "�绰:"<< abs->personArray[i].telenumber<< std::endl;
		std::cout << "��ͥסַ" << abs->personArray[i].address << std::endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isEXist(ADDressbooks* abs, std::string name) {

	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].name ==name){ return i; 
		}
	}
	return -1;
}
//ɾ����ϵ��
void removeperson(ADDressbooks *abs) {
	std::string d_name ;
	std::cout << "������Ҫɾ�����˵�����:";
	std::cin >> d_name;
	int ret = isEXist(abs, d_name);
	if (ret == -1) {
		std::cout << "���޴���" << std::endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i+ 1]; //���ǵ�Ҫɾ����λ��
		}
		abs->m_Size--;//������ϵ������
		std::cout << "ɾ���ɹ�";
	}	
}
//������ϵ��
void findperson(ADDressbooks* abs) {
	std::string name;
	std::cout << "����Ҫ��ѯ������:";
	std::cin >> name;
	int ret=isEXist(abs, name);
	if (ret !=-1) {
		std::cout << "�鵽��" << std::endl;
		std::cout << "����:" << abs->personArray[ret].name << std::endl;
		std::cout << "����:" << abs->personArray[ret].age << std::endl;
		std::cout << "�Ա�:" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << std::endl;
		std::cout << "�绰:" << abs->personArray[ret].telenumber << std::endl;
		std::cout << "��ͥסַ" << abs->personArray[ret].address << std::endl;
		std::cout << "*********************************" << std::endl;
	}
	else {
		std::cout << "���޴���" << std::endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyperson(ADDressbooks* abs) {
	std::string name;
	std::cout << "������Ҫ�޸ĵ���ϵ�˵�����:";
	std::cin >> name;
	int ret=isEXist(abs, name);

	if (ret != -1) {
		std::cout << "ԭ��Ϣ" << std::endl;
		std::cout << "����:" << abs->personArray[ret].name << std::endl;
		std::cout << "����:" << abs->personArray[ret].age << std::endl;
		std::cout << "�Ա�:" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << std::endl;
		std::cout << "�绰:" << abs->personArray[ret].telenumber << std::endl;
		std::cout << "��ͥסַ" << abs->personArray[ret].address << std::endl;
		std::cout << "*********************************"<< std::endl;
		std::cout << "���޸���Ϣ" << std::endl;
		 
		std::string name;
		std::cout << "����������:";
		std::cin >>abs->personArray[ret].name;

		//�Ա�
		std::cout << "1--��" << std::endl;
		std::cout << "2--Ů" << std::endl;
		std::cout << "�������Ա�:";

		int sex = 0;
		while (true) {
			std::cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].sex = sex;
				break;
			}
			std::cout << "����������������" << std::endl;
		}
		//����
		int age;
		std::cout << "����������:";
		std::cin >>abs->personArray[ret].age ;

		//�绰
		int number;
		std::cout << "������绰����:";
		std::cin >>abs->personArray[ret].telenumber;

		//סַ
		std::cout << "�������ͥסַ:";
		std::cin >> abs->personArray[ret].address;
		std::cout << "*********************************" << std::endl;
		std::cout << "�޸ĳɹ�" << std::endl;
	}
}
//���ͨѶ¼
void rm_rf(ADDressbooks* abs) {
	std::cout << "ȷ��Ҫ���ͨѶ¼ȫ����Ϣ?" << std::endl;
	std::string y;
	std::cout << "��[y]ȷ������������:";
	std::cin >> y;
	if (y == "y") {
		abs->m_Size = 0;
		std::cout << "����ɹ�!"<< std::endl;
		system("pause");
		system("cls");
	}
	else {
		return;
	}
}

int main() {

	//�����ṹ�����
	ADDressbooks abs;
	person psn;
	abs.m_Size = 0; //��ʼ����ϵ��


	while (true) {
	showMenu();
	int select = 0;
	std::cout << "���������ѡ��:";
	std::cin >> select;                                                                                                          
	
	switch (select) {

	case 1:
		//.�����ϵ��
		addperson(&abs);
		break;

	case 2:
		//��ʾ��ϵ��
		showperson(&abs);
		break;

	case 3:
		//ɾ����ϵ��
		removeperson(&abs);
		break;

	case 4:
		//������ϵ��
		findperson(&abs);
		break;

	case 5:
		//�޸���ϵ
		modifyperson(&abs);
		break;

	case 6:
		//�����ϵ��
		rm_rf(&abs);
		break;

	case 0:
		//�˳�ͨѶ¼
		system("pause");
		std::cout << "��ӭ�´�ʹ��" << std::endl;
		return 0;
		break;
	}
	
}
	
}
