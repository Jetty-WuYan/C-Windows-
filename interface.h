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
	student *head;                            //ָ��ṹ���ָ��
public:
	node()                                     //Ĭ�Ϲ��캯��
	{
		head=new student;
		head->next=nullptr;
		head->stu_name="Nobody";
	};
	~node()                                     //������������
	{
		student *work_ps=head,*temp;
		while(work_ps)
		{
			temp=work_ps;
			work_ps=temp;
			delete temp;
		}
	};
	void input(student *stu);             //��һ��Ԫ�ؼ�������
	bool All_Show()const;                      //��ʾȫ��ѧ����Ϣ�ĺ���
	bool insert(student *stu,int Location);    //����һ��ѧ������Ϣ
	bool Dell(int Location);                               //ɾ��һ��ѧ����Ϣ
	student *find_num(int m_number)const;                   //������Ų���ѧ����Ϣ
	student *find_name(std::string & name)const;                //����������ѧ����Ϣ
	student *find_No(std::string &id)const;                    //��ѧ�Ų���ѧ����Ϣ
	bool print(std::ofstream & fout)const;                                         //�ı���������
	int headcount()const; 
};
