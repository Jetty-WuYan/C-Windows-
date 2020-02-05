#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
struct student
{
	std::string stu_id;
	std::string stu_name;
	int Chinese;
	int Math;
	int English;
	int Science;
	student *next;
};
class node
{
	student *head;                            //指向结构体的指针
public:
	node()                                     //默认构造函数
	{
		head=new student;
		head->next=nullptr;
		head->stu_name="Nobody";
	};
	~node()                                     //内联析构函数
	{
		student *work_ps=head,*temp;
		while(work_ps)
		{
			temp=work_ps;
			work_ps=temp;
			delete temp;
		}
	};
	void input(student *stu);             //将一个元素加入链表
	bool All_Show()const;                      //显示全部学生信息的函数
	bool insert(student *stu,int Location);    //插入一个学生的信息
	bool Dell(int Location);                               //删除一个学生信息
	student *find_num(int m_number)const;                   //按照序号查找学生信息
	student *find_name(std::string & name)const;                //按姓名查找学生信息
	student *find_No(std::string &id)const;                    //按学号查找学生信息
	bool print(std::ofstream & fout)const;                                         //文本导出数据
	int headcount()const; 
};
