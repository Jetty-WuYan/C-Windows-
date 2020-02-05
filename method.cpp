#include"interface.h"
//链表类方法
void node::input(student *stu)                         //普通添加类方法
{
	student *work_ps;                               //work_ps为搜索指针
	for(work_ps=head;work_ps->next!=nullptr;work_ps=work_ps->next)
		continue;
	work_ps->next=stu;
	stu->next=nullptr;
}
bool node::All_Show()const                               //查看表中所有数据
{
	student *show_work_ps=head;
	int i=0;
	if(show_work_ps->next==nullptr)
	{
		std::cout<<"\t\t表中没有任何学生信息！\n";
		system("pause");
		system("cls");
		return false;
	}
	for(show_work_ps=head->next;show_work_ps!=nullptr;show_work_ps=show_work_ps->next)
	{
		++i;
		std::cout<<i<<"\t学号:"<<show_work_ps->stu_id<<" 姓名:"<<show_work_ps->stu_name
			<<" 语文:"<<show_work_ps->Chinese<<" 数学:"<<show_work_ps->Math<<" 英语:"<<show_work_ps->English
			<<" 理综:"<<show_work_ps->Science<<std::endl;
	}
	return true;
}
bool node::insert(student *stu,int Location)              //插入学生的信息
{
	if(Location==0)
	{
		std::cout<<"位置错误！";
		return false;
	}
	int i=1;
	student *work=head,*temp;
	while(Location>i)
	{
		work=work->next;
		if(work==nullptr)
		{
			std::cout<<"非法的位置！";
			return false;
		}
		i++;
	}
	temp=work->next;                              //temp指针指向要被插入的结点
	stu->next=temp;                        //把要被插入的结点的后面地址赋给新节点
	work->next=stu;
	return true;
}
bool node::Dell(int Location)                       //删除结点的成员函数
{
	student *work=head,*temp;               //创建2个指针
	if(Location<=0)
	{
		std::cout<<"删除位置非法！";
		return false;
	}
	int i=1;
	while(Location>i)
	{
		work=work->next;
		if(work==nullptr)
			return false;
		i++;
	}
	temp=work->next;                    //temp指针指向被删除的指针
	work->next=temp->next;              //把被删除的后面的结点与被删除前面的结点连接
	temp->next=nullptr;
	delete temp;                         //释放temp指针指向被删除指针的内存
	std::cout<<"删除成功！";
	return true;
}
student *node::find_num(int m_number)const    //按照序号查找学生信息
{
	if(m_number<=0)
	{
		return nullptr;
	}
	int i=1;
	student *work=head;
	while(m_number>=i)
	{
		work=work->next;
		if(work==nullptr)
			return nullptr;
		i++;
	}
	return work;
}
bool node::print(std::ofstream &fout)const                                   //文本导出数据函数
{
	int i=0;
	if(!fout.is_open())
	{
		std::cout<<"无法打开文件";
		system("pause");
		return false;
	}
	student *work,*temp;
	for(work=head->next;work!=nullptr;work=work->next)
	{
		++i;
		fout<<i<<"\t学号:"<<work->stu_id<<" 姓名:"<<work->stu_name
			<<" 语文:"<<work->Chinese<<" 数学:"<<work->Math<<" 英语:"<<work->English
			<<" 理综:"<<work->Science<<std::endl;
	}
	fout.close();
	return true;
}
student * node::find_name(std::string &name)const           //按姓名查找学生信息
{
	student *work=head,*temp;
	while(work!=nullptr)
	{
		work=work->next;
		if(work->stu_name==name)
			break;
	}
	return work;
}
student *node::find_No(std::string & id)const                //按学号查找学生信息
{
	student *work=head,*temp;
	while(work!=nullptr)
	{
		work=work->next;
		if(work->stu_id==id)
			break;
	}
	return work;
}