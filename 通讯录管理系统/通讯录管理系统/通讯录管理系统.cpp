#include<iostream>
using namespace std;
#include<string>
#define Max 1000
//创建联系人结构体
struct Parson
{
	//姓名
	string name;
	//性别 1 男 2 女
	int sex;
	//年龄
	int age;
	//电话
	string phone;
	//地址
	string addr;
};
//创建通讯录结构体
struct Addressbooks
{
	//通讯录容量
	Parson personArry[Max];
	//通讯录当前记录人数
	int size;
};

//显示菜单 无返回值 无参数
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*******1.添加联系人*******" << endl;
	cout << "*******2.显示联系人*******" << endl;
	cout << "*******3.删除联系人*******" << endl;
	cout << "*******4.查找联系人*******" << endl;
	cout << "*******5.修改联系人*******" << endl;
	cout << "*******6.清空联系人*******" << endl;
	cout << "*******0.退出通讯录*******" << endl;
	cout << "**************************" << endl;
}
void addParson(Addressbooks *ads)//添加联系人
{
	if (ads->size == Max)
	{
		cout << "通讯录数量已超过最大值，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		ads->personArry[ads->size].name = name;
		
		//性别
		int sex;
		cout << "请输入性别 0-男 1-女" << endl;
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
				cout << "请您重新输入正确值！" << endl;
			}
		}
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		ads->personArry[ads->size].age = age;
		//电话
		string  num;
		cout << "请输入电话" << endl;
		cin >> num;
		ads->personArry[ads->size].phone = num;
		//住址
		string  add;
		cout << "请输入住址" << endl;
		cin >> add;
		ads->personArry[ads->size].addr = add;
		ads->size++;
		cout << "添加联系人成功" << endl;
		system("pause");

		system("cls");

	}
}
void showPerson(Addressbooks *ads)
{
	if (ads->size == 0)
	{
		cout << "通讯录无数据！" << endl;
	}
	else
	{
		for (int i = 0; i < ads->size; i++)
		{
			cout << "姓名：" << ads->personArry[i].name<<"\t";
			cout << "性别：" << (ads->personArry[i].sex == 0 ? "男":"女") << "\t";
			cout << "年龄：" << ads->personArry[i].name << "\t";
			cout << "电话：" << ads->personArry[i].phone<< "\t";
			cout << "地址：" << ads->personArry[i].addr<<endl;
		}
		
	}
}
//判断联系人是否存在
//参数：通讯录，要查找的联系人姓名
//返回：找到联系人的下标 若没有找到 则返回-1
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

//删除联系人
void deletePerson(Addressbooks *abs) 
{
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret==-1)
	{
		cout << "查无此人"<<endl;
	}
	else
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArry[i] = abs->personArry[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findParson(Addressbooks *abs)
{
	cout << "请输入您想要查找联系人的姓名" << endl;
	string name;
	cin >> name;
	int val = isExit(abs, name);
		if (val != -1)
		{
			cout << "姓名：" << abs->personArry[val].name << "\t";
			cout << "性别：" << (abs->personArry[val].sex == 0 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArry[val].name << "\t";
			cout << "电话：" << abs->personArry[val].phone << "\t";
			cout << "地址：" << abs->personArry[val].addr << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
}
//修改联系人
void midParson(Addressbooks* abs)
{
	cout << "请输入您想要查找联系人的姓名" << endl;
	string name;
	cin >> name;
	int val = isExit(abs, name);
	if (val != -1)
	{
		//修改联系人
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArry[val].name = name;

		//性别
		int sex;
		cout << "请输入性别 0-男 1-女" << endl;
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
				cout << "请您重新输入正确值！" << endl;
			}
		}
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArry[val].age = age;
		//电话
		string  num;
		cout << "请输入电话" << endl;
		cin >> num;
		abs->personArry[val].phone = num;
		//住址
		string  add;
		cout << "请输入住址" << endl;
		cin >> add;
		abs->personArry[val].addr = add;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}
void cleanParson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已被清空" << endl;
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
		showMenu();//显示菜单
		
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addParson(&ads);
				break;
		case 2://2.显示联系人
		    showPerson(&ads);
			break;
		case 3://3.删除联系人
	/*	{
			string name;
			cout << "请输入要查找联系人姓名" << endl;
			cin >> name;
			if (isExit(&ads, name)==-1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到了" << endl;
			}
		}*/
			deletePerson(&ads);
			break;
		case 4://4.查找联系人
			findParson(&ads);
			break;
		case 5://5.修改联系人
			midParson(&ads);
			break;
		case 6://6.清空联系人
			cleanParson(&ads);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
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