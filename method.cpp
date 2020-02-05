#include"interface.h"
//�����෽��
void node::input(student *stu)                         //��ͨ����෽��
{
	student *work_ps;                               //work_psΪ����ָ��
	for(work_ps=head;work_ps->next!=nullptr;work_ps=work_ps->next)
		continue;
	work_ps->next=stu;
	stu->next=nullptr;
}
bool node::All_Show()const                               //�鿴������������
{
	student *show_work_ps=head;
	int i=0;
	if(show_work_ps->next==nullptr)
	{
		std::cout<<"\t\t����û���κ�ѧ����Ϣ��\n";
		system("pause");
		system("cls");
		return false;
	}
	for(show_work_ps=head->next;show_work_ps!=nullptr;show_work_ps=show_work_ps->next)
	{
		++i;
		std::cout<<i<<"\tѧ��:"<<show_work_ps->stu_id<<" ����:"<<show_work_ps->stu_name
			<<" ����:"<<show_work_ps->Chinese<<" ��ѧ:"<<show_work_ps->Math<<" Ӣ��:"<<show_work_ps->English
			<<" ����:"<<show_work_ps->Science<<std::endl;
	}
	return true;
}
bool node::insert(student *stu,int Location)              //����ѧ������Ϣ
{
	if(Location==0)
	{
		std::cout<<"λ�ô���";
		return false;
	}
	int i=1;
	student *work=head,*temp;
	while(Location>i)
	{
		work=work->next;
		if(work==nullptr)
		{
			std::cout<<"�Ƿ���λ�ã�";
			return false;
		}
		i++;
	}
	temp=work->next;                              //tempָ��ָ��Ҫ������Ľ��
	stu->next=temp;                        //��Ҫ������Ľ��ĺ����ַ�����½ڵ�
	work->next=stu;
	return true;
}
bool node::Dell(int Location)                       //ɾ�����ĳ�Ա����
{
	student *work=head,*temp;               //����2��ָ��
	if(Location<=0)
	{
		std::cout<<"ɾ��λ�÷Ƿ���";
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
	temp=work->next;                    //tempָ��ָ��ɾ����ָ��
	work->next=temp->next;              //�ѱ�ɾ���ĺ���Ľ���뱻ɾ��ǰ��Ľ������
	temp->next=nullptr;
	delete temp;                         //�ͷ�tempָ��ָ��ɾ��ָ����ڴ�
	std::cout<<"ɾ���ɹ���";
	return true;
}
student *node::find_num(int m_number)const    //������Ų���ѧ����Ϣ
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
bool node::print(std::ofstream &fout)const                                   //�ı��������ݺ���
{
	int i=0;
	if(!fout.is_open())
	{
		std::cout<<"�޷����ļ�";
		system("pause");
		return false;
	}
	student *work,*temp;
	for(work=head->next;work!=nullptr;work=work->next)
	{
		++i;
		fout<<i<<"\tѧ��:"<<work->stu_id<<" ����:"<<work->stu_name
			<<" ����:"<<work->Chinese<<" ��ѧ:"<<work->Math<<" Ӣ��:"<<work->English
			<<" ����:"<<work->Science<<std::endl;
	}
	fout.close();
	return true;
}
student * node::find_name(std::string &name)const           //����������ѧ����Ϣ
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
student *node::find_No(std::string & id)const                //��ѧ�Ų���ѧ����Ϣ
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