#include"interface.h"
void start_screen()                //开始界面函数
{
	int choices;
	std::cout<<"  ****************************************************************************\n"
	         <<"  *                                欢迎光临                                  *\n"
			 <<"  ****************************************************************************\n"
			 <<"  *                                                                          *\n"                 
			 <<"  *                            1：添加学生信息                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            2：显示学生信息                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            3：查找学生信息                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            4：插入学生信息                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            5：删除学生信息                               *\n"
			 <<"  *                                                                          *\n"
			 <<"  *                            6：导出文本数据                               *\n"
			 <<"  *                                                                          *\n"                         
			 <<"  *                          其它：退出管理系统                              *\n"
			 <<"  *                                                                          *\n"
			 <<"  ****************************************************************************\n";
	         std::cout<<"\t\t您输入的数字是:\t";
}
//作者界面
void writer()
{
std::cout<<" ****************************************************************************\n"
		<<"  *                                欢迎光临                                  *\n"
		<<"  ****************************************************************************\n"
		<<"  *                                                                          *\n"                 
		<<"  *                          本程序由九江职业大学                            *\n"
		<<"  *                                                                          *\n"
		<<"  *                              信息工程学院                                *\n"
		<<"  *                                                                          *\n"
		<<"  *                               手机软件班                                 *\n"
		<<"  *                                                                          *\n"
		<<"  *                                爵哥开发                                  *\n"
		<<"  *                                                                          *\n"
		<<"  *                    本程序为开源软件，可随意修改,使用                     *\n"
		<<"  *                                                                          *\n"
		<<"  *                         如有宝贵意见                                     *\n"
		<<"  *                            可以联系本人QQ2607142492                      *\n"                         
		<<"  *                                                                          *\n"
		<<"  *                           点击进入系统                                   *\n"
		<<"  ****************************************************************************\n";
        std::cin.get();
}
//结构体函数
void create_student(student *stu)                                      //结构体实例化函数
{
	std::cout<<"\t\t\t请输入学生基本信息:\n";
	std::cout<<"\t\t请输入学生的学号:";
	std::cin>>stu->stu_id;
	std::cout<<"\t\t请输入学生的姓名:";
	std::cin>>stu->stu_name;
	std::cout<<"\t\t请输入学生的语文成绩:\t";
	std::cin>>stu->Chinese;
	std::cout<<"\t\t请输入学生的数学成绩:\t";
	std::cin>>stu->Math;
	std::cout<<"\t\t请输入学生的英语成绩:\t";
	std::cin>>stu->English;
	std::cout<<"\t\t请输入学生的理综成绩:\t";
	std::cin>>stu->Science;
}
void show_student(student *stu)                                      //输出函数
{
	std::cout<<"\t\t\t学生基本信息如下:\n";
	std::cout<<"\t\t学生的学号:";
	std::cout<<stu->stu_id<<std::endl;
	std::cout<<"\t\t学生的姓名:";
	std::cout<<stu->stu_name<<std::endl;
	std::cout<<"\t\t学生的语文成绩:";
	std::cout<<stu->Chinese<<std::endl;
	std::cout<<"\t\t学生的数学成绩:";
	std::cout<<stu->Math<<std::endl;
	std::cout<<"\t\t学生的英语成绩:";
	std::cout<<stu->English<<std::endl;
	std::cout<<"\t\t学生的理综成绩:t";
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
					std::cout<<"\t\t当您输入完学生信息后，按其他键继续,按下q\\Q将退出:\n";
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
					std::cout<<"\t\t按下q/Q时，退出";
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
					std::cout<<"\t\t按序号查找请按1\n\t\t按姓名查找请按2\n\t\t按学号查找请按3:\n";
					std::cin>>choices_2;
					switch(choices_2)
					{
					case 1:
						{
							int choices;
							std::cout<<"\t\t请输入要查找的序号:\n";
							std::cin>>choices;
							List.find_num(choices);
							if(List.find_num(choices)!=nullptr)
								show_student(List.find_num(choices));
							else
								std::cout<<"\t\t值非法！\n";
							break;
						}
					case 2:
						{
							std::string name;
							std::cout<<"\t\t请输入要查找的学生姓名:\n";
							std::cin>>name;
							if(List.find_name(name)!=nullptr)
								show_student(List.find_name(name));
							else
							{
								std::cout<<"\t\t查无此人！";
								system("pause");
							}
							break;
						}
					case 3:
						{
							std::string ID;
							std::cout<<"\t\t请输入要查找的学生学号:\n";
							std::cin>>ID;
							if(List.find_No(ID)!=nullptr)
								show_student(List.find_No(ID));
							else
							{
								std::cout<<"\t\t查无此人!";
								system("pause");
							}
							break;
						}
					default:
						{
							char quit;
							std::cout<<"\t\t非法的选项！\n";
							std::cout<<"\t\t当您输入q/Q时退出:\n";
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
					std::cout<<"\t\t您想插入的位置:";
					std::cin>>location;
					List.insert(new_insert,location);
					std::cout<<"\t\t输入q/Q时,退出";
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
					std::cout<<"\t\t请输入要删除的序号位置:\n";
					std::cin>>Location;
					if(!List.Dell(Location))
						std::cout<<"\t\t位置非法！";
					std::cout<<"\t\t输入q/Q时,退出";
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
					std::cout<<"成功导出！位置为C根目录";
					system("pause");
				}
				break;
			}
		default:
			{
				std::cout<<"\t\t谢谢使用";
				exit(0);
				break;
			}
			}
			}
		return 0;
		}
