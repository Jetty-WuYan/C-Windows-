#include"interface.h"
void start_screen()                //��ʼ���溯��
{
	int choices;
	std::cout<<"  ****************************************************************************\n"
	         <<"  *                                ��ӭ����                                  *\n"
			 <<"  ****************************************************************************\n"
			 <<"  *                                                                          *\n"                 
			 <<"  *                            1�����ѧ����Ϣ                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            2����ʾѧ����Ϣ                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            3������ѧ����Ϣ                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            4������ѧ����Ϣ                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            5��ɾ��ѧ����Ϣ                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            6�������ı�����                               *\n"
			 <<"  *                                                                          *\n"                         
			 <<"  *                          �������˳�����ϵͳ                              *\n"
			 <<"  *                                                                          *\n"
			 <<"  ****************************************************************************\n";
	         std::cout<<"\t\t�������������:\t";
}
//���߽���
void writer()
{
std::cout<<" ****************************************************************************\n"
		<<"  *                                ��ӭ����                                  *\n"
		<<"  ****************************************************************************\n"
		<<"  *                                                                          *\n"                 
		<<"  *                          �������ɾŽ�ְҵ��ѧ                            *\n"
		<<"  *                                                                          *\n"
		<<"  *                              ��Ϣ����ѧԺ                                *\n"
		<<"  *                                                                          *\n"
		<<"  *                               �ֻ������                                 *\n"
		<<"  *                                                                          *\n"
		<<"  *                                ���翪��                                  *\n"
		<<"  *                                                                          *\n"
		<<"  *                    ������Ϊ��Դ������������޸�,ʹ��                     *\n"
		<<"  *                                                                          *\n"
		<<"  *                         ���б������                                     *\n"
		<<"  *                            ������ϵ����QQ2607142492                      *\n"                         
		<<"  *                                                                          *\n"
		<<"  *                           �������ϵͳ                                   *\n"
		<<"  ****************************************************************************\n";
        std::cin.get();
}
//�ṹ�庯��
void create_student(student *stu)                                      //�ṹ��ʵ��������
{
	std::cout<<"\t\t\t������ѧ��������Ϣ:\n";
	std::cout<<"\t\t������ѧ����ѧ��:";
	std::cin>>stu->stu_id;
	std::cout<<"\t\t������ѧ��������:";
	std::cin>>stu->stu_name;
	std::cout<<"\t\t������ѧ�������ĳɼ�:\t";
	std::cin>>stu->Chinese;
	std::cout<<"\t\t������ѧ������ѧ�ɼ�:\t";
	std::cin>>stu->Math;
	std::cout<<"\t\t������ѧ����Ӣ��ɼ�:\t";
	std::cin>>stu->English;
	std::cout<<"\t\t������ѧ�������۳ɼ�:\t";
	std::cin>>stu->Science;
}
void show_student(student *stu)                                      //�������
{
	std::cout<<"\t\t\tѧ��������Ϣ����:\n";
	std::cout<<"\t\tѧ����ѧ��:";
	std::cout<<stu->stu_id<<std::endl;
	std::cout<<"\t\tѧ��������:";
	std::cout<<stu->stu_name<<std::endl;
	std::cout<<"\t\tѧ�������ĳɼ�:";
	std::cout<<stu->Chinese<<std::endl;
	std::cout<<"\t\tѧ������ѧ�ɼ�:";
	std::cout<<stu->Math<<std::endl;
	std::cout<<"\t\tѧ����Ӣ��ɼ�:";
	std::cout<<stu->English<<std::endl;
	std::cout<<"\t\tѧ�������۳ɼ�:t";
	std::cout<<stu->Science<<std::endl;
}
int main()
{
	char quit;
	node List;
	int choices;
	writer();
	for(;;)
	{
		system("cls");
		start_screen();
		std::cin>>choices;
		system("cls");
		switch (choices)
		{
		case 1:
			{
				for(;;)
				{
					std::cout<<"\t\t����������ѧ����Ϣ�󣬰�����������,����q\\Q���˳�:\n";
					student *new_student=new student;
					create_student(new_student);       
					List.input(new_student);
					std::cin>>quit;
					if(quit=='q' || quit=='Q')
						break;
				}
				break;

			}
		case 2:
			{
				for(;;)
				{
					List.All_Show();
					std::cout<<"\t\t����q/Qʱ���˳�";
					std::cin>>quit;
					if(quit=='q' || quit=='Q')
						break;
				}
				break;
			}
		case 3:
			{
				for(;;)
				{
					char quit;
					int choices_2;
					std::cout<<"\t\t����Ų����밴1\n\t\t�����������밴2\n\t\t��ѧ�Ų����밴3:\n";
					std::cin>>choices_2;
					switch(choices_2)
					{
					case 1:
						{
							int choices;
							std::cout<<"\t\t������Ҫ���ҵ����:\n";
							std::cin>>choices;
							List.find_num(choices);
							if(List.find_num(choices)!=nullptr)
								show_student(List.find_num(choices));
							else
								std::cout<<"\t\tֵ�Ƿ���\n";
							break;
						}
					case 2:
						{
							std::string name;
							std::cout<<"\t\t������Ҫ���ҵ�ѧ������:\n";
							std::cin>>name;
							if(List.find_name(name)!=nullptr)
								show_student(List.find_name(name));
							else
							{
								std::cout<<"\t\t���޴��ˣ�";
								system("pause");
							}
							break;
						}
					case 3:
						{
							std::string ID;
							std::cout<<"\t\t������Ҫ���ҵ�ѧ��ѧ��:\n";
							std::cin>>ID;
							if(List.find_No(ID)!=nullptr)
								show_student(List.find_No(ID));
							else
							{
								std::cout<<"\t\t���޴���!";
								system("pause");
							}
							break;
						}
					default:
						{
							char quit;
							std::cout<<"\t\t�Ƿ���ѡ�\n";
							std::cout<<"\t\t��������q/Qʱ�˳�:\n";
							std::cin>>quit;
							if(quit=='q' || quit=='Q')
								break;
						}
					}
					std::cin>>quit;
					if(quit=='q' || quit=='Q')
						break;
				}
				break;
			}
		case 4:
			{
				for(;;)
				{
					char quit;
					int location;
					student *new_insert=new student;
					create_student(new_insert);
					std::cout<<"\t\t��������λ��:";
					std::cin>>location;
					List.insert(new_insert,location);
					std::cout<<"\t\t����q/Qʱ,�˳�";
					std::cin>>quit;
					if(quit=='q' || quit=='Q')
						break;
				}
				break;
			}
		case 5:
			{
				for(;;)
				{
					int Location;
					char quit;
					std::cout<<"\t\t������Ҫɾ�������λ��:\n";
					std::cin>>Location;
					if(!List.Dell(Location))
						std::cout<<"\t\tλ�÷Ƿ���";
					std::cout<<"\t\t����q/Qʱ,�˳�";
					std::cin>>quit;
					if(quit=='q' || quit=='Q')
						break;
				}
				break;
			}
		case 6:
			{
				const char *file="file.txt";
				std::ofstream fout("c:/file.txt",std::ios_base::app);
				if(List.print(fout))
				{
					std::cout<<"�ɹ�������λ��ΪC��Ŀ¼";
					system("pause");
				}
				break;
			}
		default:
			{
				std::cout<<"\t\tллʹ��";
				exit(0);
				break;
			}
			}
			}
		return 0;
		}
