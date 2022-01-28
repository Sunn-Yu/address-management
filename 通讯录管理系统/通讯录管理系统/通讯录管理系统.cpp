#include<iostream>
using namespace std;
#include<string>
#define Max 1000
//������ϵ�˽ṹ��
struct Parson
{
	//����
	string name;
	//�Ա� 1 �� 2 Ů
	int sex;
	//����
	int age;
	//�绰
	string phone;
	//��ַ
	string addr;
};
//����ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼����
	Parson personArry[Max];
	//ͨѶ¼��ǰ��¼����
	int size;
};

//��ʾ�˵� �޷���ֵ �޲���
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*******1.�����ϵ��*******" << endl;
	cout << "*******2.��ʾ��ϵ��*******" << endl;
	cout << "*******3.ɾ����ϵ��*******" << endl;
	cout << "*******4.������ϵ��*******" << endl;
	cout << "*******5.�޸���ϵ��*******" << endl;
	cout << "*******6.�����ϵ��*******" << endl;
	cout << "*******0.�˳�ͨѶ¼*******" << endl;
	cout << "**************************" << endl;
}
void addParson(Addressbooks *ads)//�����ϵ��
{
	if (ads->size == Max)
	{
		cout << "ͨѶ¼�����ѳ������ֵ���޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		ads->personArry[ads->size].name = name;
		
		//�Ա�
		int sex;
		cout << "�������Ա� 0-�� 1-Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex ==1)
			{
				ads->personArry[ads->size].sex = sex;
				break;
			}
			else
			{
				cout << "��������������ȷֵ��" << endl;
			}
		}
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		ads->personArry[ads->size].age = age;
		//�绰
		string  num;
		cout << "������绰" << endl;
		cin >> num;
		ads->personArry[ads->size].phone = num;
		//סַ
		string  add;
		cout << "������סַ" << endl;
		cin >> add;
		ads->personArry[ads->size].addr = add;
		ads->size++;
		cout << "�����ϵ�˳ɹ�" << endl;
		system("pause");

		system("cls");

	}
}
void showPerson(Addressbooks *ads)
{
	if (ads->size == 0)
	{
		cout << "ͨѶ¼�����ݣ�" << endl;
	}
	else
	{
		for (int i = 0; i < ads->size; i++)
		{
			cout << "������" << ads->personArry[i].name<<"\t";
			cout << "�Ա�" << (ads->personArry[i].sex == 0 ? "��":"Ů") << "\t";
			cout << "���䣺" << ads->personArry[i].name << "\t";
			cout << "�绰��" << ads->personArry[i].phone<< "\t";
			cout << "��ַ��" << ads->personArry[i].addr<<endl;
		}
		
	}
}
//�ж���ϵ���Ƿ����
//������ͨѶ¼��Ҫ���ҵ���ϵ������
//���أ��ҵ���ϵ�˵��±� ��û���ҵ� �򷵻�-1
int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArry[i].name == name)
		{
			return i;
		}
	}
		return -1;
}

//ɾ����ϵ��
void deletePerson(Addressbooks *abs) 
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret==-1)
	{
		cout << "���޴���"<<endl;
	}
	else
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArry[i] = abs->personArry[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void findParson(Addressbooks *abs)
{
	cout << "����������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int val = isExit(abs, name);
		if (val != -1)
		{
			cout << "������" << abs->personArry[val].name << "\t";
			cout << "�Ա�" << (abs->personArry[val].sex == 0 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArry[val].name << "\t";
			cout << "�绰��" << abs->personArry[val].phone << "\t";
			cout << "��ַ��" << abs->personArry[val].addr << endl;
		}
		else
		{
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
}
//�޸���ϵ��
void midParson(Addressbooks* abs)
{
	cout << "����������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int val = isExit(abs, name);
	if (val != -1)
	{
		//�޸���ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArry[val].name = name;

		//�Ա�
		int sex;
		cout << "�������Ա� 0-�� 1-Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArry[val].sex = sex;
				break;
			}
			else
			{
				cout << "��������������ȷֵ��" << endl;
			}
		}
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArry[val].age = age;
		//�绰
		string  num;
		cout << "������绰" << endl;
		cin >> num;
		abs->personArry[val].phone = num;
		//סַ
		string  add;
		cout << "������סַ" << endl;
		cin >> add;
		abs->personArry[val].addr = add;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");

}
void cleanParson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�ѱ����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks ads;
	ads.size = 0;
	int select = 0;
	while (true)
	{
		showMenu();//��ʾ�˵�
		
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addParson(&ads);
				break;
		case 2://2.��ʾ��ϵ��
		    showPerson(&ads);
			break;
		case 3://3.ɾ����ϵ��
	/*	{
			string name;
			cout << "������Ҫ������ϵ������" << endl;
			cin >> name;
			if (isExit(&ads, name)==-1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ���" << endl;
			}
		}*/
			deletePerson(&ads);
			break;
		case 4://4.������ϵ��
			findParson(&ads);
			break;
		case 5://5.�޸���ϵ��
			midParson(&ads);
			break;
		case 6://6.�����ϵ��
			cleanParson(&ads);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}