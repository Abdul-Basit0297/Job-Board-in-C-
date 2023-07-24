#include<iostream>
#include<fstream>
using namespace std;

bool FileOpen(ifstream &fin, const char *);
void CreateAccount(ofstream & fout, ofstream &userprofiledata, char filename1[], char filename2[], char FirstName[], char LastName[], char UniqueName[], char pasword[], char ConfirmPasword[]);
void CreateJobSeekerProfile(ofstream & fout2, char filename5[], char *FirstName, char *LastName, char *PhoneNumber, char *Address, char *Education, char *PastJob, char *Experience);
void Modifying(ifstream& fin2, char[], char* FileCatagery, char* FileCatageryDetail, char* SelectModifyCatagery, char *ModifyngData);
void PostJobDescription(ofstream &fout, char *JobTitle, char *JobDetails, char *JobCatagery, char *DeadLine, char *JobID);
bool ChangePassword(ifstream& fin2, char[], char* FileUniqueID, char* FilePassword);
void ListOfCandidatesApplied(ifstream &fin6, char *FullName, char *CellNumber);
void SerachCatagery(ifstream &fin4, char filename4[], char *AvailableJobs);
bool SignIn(ifstream& fin, char[], char* UserName, char* Password);
void AvailableJobss(ifstream &fin3, char filename7[], char *jobs);
void ViewJobList(ifstream &fin2, char *JobId, char *JobTitle);
char* ReadFromFile(ifstream& fin, char* ptr, int& size);
void CopyOldData(char* ptr, char* ptr2, int size);
char* Regrow1D(char* ptr, int size, char data);
void HireCandidate(ifstream &fin7, char *Hire);
void ApplyForJob(ifstream &fin5, char *Apply);
void DisplayData(char * ptr, int size);
int CheckLength(char FirstName[]);
char* PlaceTxt(char *ptr);
void Reset(char *ptr);
int main()
{
	ofstream fout;
	ofstream userprofiledata;
	ifstream fin;
	ifstream fin2;
	ifstream fin3;
	char filename1[] = { "createaccount.txt" };
	char filename2[] = { "userprofiledata.txt" };
	char filename3[] = { "JobSeekerPassword.txt" };
	char filename4[] = { "JobSeekeraccountdata.txt" };
	char filename7[] = { "AvailableJobs.txt" };
	char FirstName[50] = { '\0' };
	char LastName[15] = { '\0' };
	char UniqueName[15] = { '\0' };
	char pasword[100] = { '\0' };
	char ConfirmPasword[15] = { '\0' };
	char FirstName2[100] = { '\0' };
	char ConfirmPasword2[100] = { '\0' };
	char *FullName = NULL;
	char *CellNumber = NULL;
	char *jobs = NULL;
	char *Apply = NULL;
	char *Hire = NULL;
	char *ModifyngData = NULL;
	char *AvailableJobs = NULL;
	char *SelectModifyCatagery = NULL;
	char *Firstname = NULL;
	char *Lastname = NULL;
	char *PhoneNumber = NULL;
	char *Address = NULL;
	char *Education = NULL;
	char *PastJob = NULL;
	char *Experience = NULL;
	char *FileCatagery = NULL;
	char *FileCatageryDetail = NULL;
	char *confirmPassword = NULL;
	char *FileUniqueID = NULL;
	char *FilePassword = NULL;
	char *Pasword = NULL;
	char *UserName = NULL;
	char *JobTitle = NULL;
	char *JobDetails = NULL;
	char *DeadLine = NULL;
	char *JobCatagery = NULL;
	char *JobID = NULL;
	char *JobId = NULL;
	char *Jobtitle = NULL;
	int employer = 0;
	cout << "\t\t-----------------------------------------------------------------" << endl;
	cout << "\t\t-----------------WELCOME TO THE JOB BOARD SYSTEM-----------------" << endl;
	cout << "\t\t---------------------------DEVELOPED-----------------------------" << endl;
	cout << "\t\t------------------------------BY---------------------------------" << endl;
	cout << "\t\t--------------------------ABDUL BASIT----------------------------" << endl;
	cout << "\n\n";
	cout << "******************************************" << endl;
	cout << "Hello ! Are You a Employe OR Job Seeker ? " << endl;
	cout << "For Job Seeker Press 1 : " << endl;
	cout << "For Employe    Press 2 : " << endl;
	cout << "Enter Your Desired Option ";
	cin >> employer;
	cout << "******************************************" << endl;
	cout << "\n";
	if (employer == 2)
	{
		int account = 0;
		cout << "\n";
		cout << "***********************************************************************************" << endl;
		cout << "Ok ! You Are Our Employe : " << endl;
		cout << "For Sign Up  Press 1 " << endl;
		cout << "For Sign In  Press 2 " << endl;
		cout << "Note ! If you are going to Sign In You need to remember you UserName & Password : ";
		cin >> account;
		cout << "***********************************************************************************" << endl;


		if (account == 1)
		{
			CreateAccount(fout, userprofiledata, filename1, filename2, FirstName, LastName, UniqueName, pasword, ConfirmPasword);

		}
		else if (account == 2)
		{
			int choice = 0;
			cout << "\n";
			cout << "Please Sign in : " << endl;
			if (SignIn(fin, filename1, UserName, Pasword) == false)
			{
				cout << "----------------------------------------------------" << endl;
				cout << "Your Unique I'D or Password is Incorrect, Try Again " << endl;
				do
				{
					cout << "\n";
					cout << "-----------------------------------" << endl;
					cout << "If You Want To try Again Press 1 : " << endl;
					cout << "For Exit                 Press 2 : " << endl;
					cout << "-----------------------------------" << endl;
					cin >> choice;
					if (choice == 2)
					{
						cout << "\n";
						cout << "\t\t******************************************************" << endl;
						cout << "\t\t                    Thank-You                         " << endl;
						cout << "\t\t******************************************************" << endl;
						exit(-1);
					}
				} while (!(choice >= 1 && choice <= 2));

				if (choice == 1)
				{
					if (SignIn(fin, filename1, UserName, Pasword) == false)
					{
						cout << "---------------------------------------------" << endl;
						cout << "Your Unique I'D or Password is Incorrect  " << endl;
						cout << "**********************************************" << endl;
						cout << "\n";
						cout << "Press Any Key To Exit  " << endl;
						cin >> choice;
						if (choice >= 0)
						{
							cout << "\n";
							cout << "\t\t******************************************************" << endl;
							cout << "\t\t                    Thank-You                         " << endl;
							cout << "\t\t******************************************************" << endl;
							exit(-1);
						}
					}
				}

			}
		}
		do
		{
			cout << "\n";
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---If you Want To Change Pasword then  Press 3 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---For Posting Job Description         Press 4 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---For Modify Job Description          Press 5 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---View List Of Posted Jobs            Press 6 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---View List Of Candidates Who Applied Press 7 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---Hire A Candidate                    Press 8 " << endl;
			cout << "\t\t-----------------------------------------------" << endl;
			cout << "\t\t---For Exit                            Press 9 " << endl;
			cout << "\t\t-----------------------------------------------" << endl;
			cout << "\t\t---Enter Your Desired Input : ";
			cin >> account;

			if (account == 3)
			{
				bool flag2 = false;
				int choice = 0;
				if (ChangePassword(fin2, filename1, FileUniqueID, FilePassword) == false)
				{
					do
					{
						cout << "-----------------------------------" << endl;
						cout << "If You Want To Try Again Press 1 : " << endl;
						cout << "Return To Main Menu      Press 2 : " << endl;
						cout << "Enter Your Desrired Input        : ";
						cin >> choice;
						cout << "-----------------------------------" << endl;
						if (choice == 2)
						{
							break;
						}
					} while (!(choice >0 && choice <= 2));
					if (choice == 1)
					{
						if (ChangePassword(fin2, filename1, FileUniqueID, FilePassword) == false)
						{
							cout << "-----------------------------------" << endl;
							cout << "Return To Main Menu      Press 2 : " << endl;
							cout << "Enter Your Desrired Input        : ";
							cin >> choice;
							cout << "-----------------------------------" << endl;
							if (choice == 2)
							{
							}
						}
					}
				}
			}
			else if (account == 4)
			{
				PostJobDescription(fout, JobTitle, JobDetails, JobCatagery, DeadLine, JobID);
			}
			else if (account == 5)
			{
				char *filename = NULL;
				filename = new char[20];
				cout << "Please Enter Job Catagery That You Want To Modify " << endl;
				cin.ignore();
				cin.getline(filename, 50, '\n');
				filename = PlaceTxt(filename);
				AvailableJobss(fin2, filename, jobs);
				cout << "---------------------------------------------------" << endl;
				cout << "********** Warning! Read Before Modifiyng**********" << endl;
				cout << "\n";
				cout << "You are Required to Write, What You Want to Modify " << endl;
				cout << "                 For Example                      " << endl;
				cout << "If you Want to Modify Job Title You Have To Write : 'Job Title' " << endl;
				cout << "If you Want to Modify Detail You Have To Write    : 'Job Detail' " << endl;
				cout << "If you Want to Modify City You Have To Write      :   'City'     " << endl;
				cout << "\n";
				cout << "----------------------------------------" << endl;

				Modifying(fin2, filename, FileCatagery, FileCatageryDetail, SelectModifyCatagery, ModifyngData);
			}
			else if (account == 6)
			{
				ViewJobList(fin2, JobId, Jobtitle);
			}
			else if (account == 7)
			{
				ifstream fin6;
				ListOfCandidatesApplied(fin6, FullName, CellNumber);
			}
			else if (account == 8)
			{
				ifstream fin7;
				HireCandidate(fin7, Hire);
			}
			else if (account == 9)
			{
				cout << "\n";
				cout << "\t\t---------------------------------------" << endl;
				cout << "\t\t        Thank You For Using            " << endl;
				cout << "---------------------------------------" << endl;
			}
		} while (account >0 && account <= 8);
	}
	else if (employer == 1)
	{
		int account = 0;
		cout << "Welcome To The Job Board  : " << endl;
		cout << "For Sin Up   Press 1 " << endl;
		cout << "For Sign In  Press 2 " << endl;
		cout << "Note ! If you are going to Sign In You need to remember you UserName & Password : ";
		cin >> account;

		if (account == 1)
		{
			CreateAccount(fout, userprofiledata, filename3, filename4, FirstName, LastName, UniqueName, pasword, ConfirmPasword);
		}
		else if (account == 2)
		{
			int choice = 0;
			cout << "\n";
			cout << "Please Sign in : " << endl;
			if (SignIn(fin, filename3, UserName, Pasword) == false)
			{
				cout << "----------------------------------------------------" << endl;
				cout << "Your Unique I'D or Password is Incorrect, Try Again " << endl;
				do
				{
					cout << "\n";
					cout << "-----------------------------------" << endl;
					cout << "If You Want To try Again Press 1 : " << endl;
					cout << "For Exit                 Press 2 : " << endl;
					cout << "-----------------------------------" << endl;
					cin >> choice;
					if (choice == 2)
					{
						cout << "\n";
						cout << "\t\t******************************************************" << endl;
						cout << "\t\t                    Thank-You                         " << endl;
						cout << "\t\t******************************************************" << endl;
						exit(-1);
					}
				} while (!(choice >= 1 && choice <= 2));
				if (choice == 1)
				{
					if (SignIn(fin, filename3, UserName, Pasword) == false)
					{
						cout << "---------------------------------------------" << endl;
						cout << "Your Unique I'D or Password is Incorrect  " << endl;
						cout << "**********************************************" << endl;
						cout << "\n";
						cout << "Press Any Key To Exit  " << endl;
						cin >> choice;
						if (choice >= 0)
						{
							cout << "\n";
							cout << "\t\t******************************************************" << endl;
							cout << "\t\t                    Thank-You                         " << endl;
							cout << "\t\t******************************************************" << endl;
							exit(-1);
						}
					}
				}
			}
		}
		do
		{
			cout << "\n";
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---If you Want To Change Pasword then  Press 3 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---Create UserProfile                  Press 4 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---For Modify User Profile             Press 5 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---View List Of Available Jobs         Press 6 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---Search Job By Catargery             Press 7 " << endl;
			cout << "\t\t----------------------------------------------" << endl;
			cout << "\t\t---Apply For A Job                     Press 8 " << endl;
			cout << "\t\t-----------------------------------------------" << endl;
			cout << "\t\t---View List Of Applied Jobs           Press 9 " << endl;
			cout << "\t\t-----------------------------------------------" << endl;
			cout << "\t\t---View List Of Accepted Jobs          Press 10" << endl;
			cout << "\t\t-----------------------------------------------" << endl;
			cout << "\t\t---For Exit                            Press 11" << endl;
			cout << "\t\t-----------------------------------------------" << endl;
			cout << "\t\t---Enter Your Desired Input : ";
			cin >> account;

			if (account == 3)
			{
				bool flag2 = false;
				int choice = 0;
				if (ChangePassword(fin2, filename3, FileUniqueID, FilePassword) == false)
				{
					do
					{
						cout << "-----------------------------------" << endl;
						cout << "If You Want To Try Again Press 1 : " << endl;
						cout << "Return To Main Menu      Press 2 : " << endl;
						cout << "Enter Your Desrired Input        : ";
						cin >> choice;
						cout << "-----------------------------------" << endl;
						if (choice == 2)
						{
							break;
						}
					} while (!(choice >0 && choice <= 2));
					if (choice == 1)
					{
						if (ChangePassword(fin2, filename3, FileUniqueID, FilePassword) == false)
						{
							cout << "-----------------------------------" << endl;
							cout << "Return Main Menu         Press 2 : " << endl;
							cin >> choice;
							cout << "-----------------------------------" << endl;
							if (choice == 2)
							{
							}
						}
					}
				}
			}
			else if (account == 4)
			{
				ofstream fout2;
				char filename5[10] = { '\0' };
				cout << "Please Enter (txt) File Name In Which You Want to Wirte Profile Data : ";
				cin >> filename5;
				CreateJobSeekerProfile(fout2, filename5, Firstname, Lastname, PhoneNumber, Address, Education, PastJob, Experience);
			}
			else if (account == 5)
			{
				char filename[50] = { '\0' };
				cout << "Please Enter User (txt) File Name Which You Want To Modify : ";
				cout << "Enter File Name : ";
				cin >> filename;
				cout << "\n";
				cout << "*************        Your Profile Data      *********************" << endl;
				AvailableJobss(fin3, filename, jobs);
				cout << "\n";
				cout << "---------------------------------------------------" << endl;
				cout << "**********     Read Before Modifiyng     **********" << endl;
				cout << "\n";
				cout << "You are Required to Write, What You Want to Modify " << endl;
				cout << "                 For Example                      " << endl;
				cout << "If you Want to Modify First Name You Have To Write      : 'First Name' " << endl;
				cout << "If you Want to Modify Phone Number You Have To Write    : 'Phone Number' " << endl;
				cout << "If you Want to Modify Addres You Have To Write          :   'Address'     " << endl;
				cout << "\n";
				cout << "----------------------------------------" << endl;
				cin.ignore();
				Modifying(fin2, filename, FileCatagery, FileCatageryDetail, SelectModifyCatagery, ModifyngData);
			}
			else if (account == 6)
			{
				AvailableJobss(fin3, filename7, jobs);
			}
			else if (account == 7)
			{
				ifstream fin4;
				char *filename4 = NULL;
				filename4 = new char[20];
				cout << "Please Enter Job Catagery That You Want To Search : ";
				cin.ignore();
				cin.getline(filename4, 20, '\n');
				filename4 = PlaceTxt(filename4);
				AvailableJobss(fin4, filename4, AvailableJobs);
				

			}
			else if (account == 8)
			{
				ifstream fin5;
				cout << "\n";
				cout << "\t\t *********       These Are Avaiable Jobs         *************" << endl;
				cout << "\t\t                  Apply Any One Of Them                       " << endl;
				AvailableJobss(fin3, filename7, jobs);
				ApplyForJob(fin5, Apply);
			}
			else if (account == 9)
			{
				ifstream fin5;
				char filename8[] = { "AppliedJobs.txt" };
				cout << "\n\n";
				cout << "\t\t**************************************************************" << endl;
				cout << "\t\t----         Your Applied Jobs With Detail        ------------" << endl;
				AvailableJobss(fin5, filename8, jobs);
				cout << "\n";
			}
			else if (account == 10)
			{
				ifstream fin9;
				char filename10[] = { "AcceptedJobs.txt" };
				AvailableJobss(fin9, filename10, jobs);
			}
			else if (account == 11)
			{
				cout << "\n";
				cout << "\t\t------------------------------------------" << endl;
				cout << "\t\t        Thank You For Comming             " << endl;
				cout << "\t\t------------------------------------------" << endl;
				exit(-1);
			}
		} while (account >0 && account <= 11);
	}
	system("pause");
	return 0;
}
bool FileOpen(ifstream &fin, const char *filename)
{
	bool flag = false;
	fin.open(filename);
	if (fin.is_open())
	{
		flag = true;
	}
	return flag;

}
void CreateAccount(ofstream & fout, ofstream &userprofiledata, char filename1[], char filename2[], char FirstName[], char LastName[], char UniqueName[], char pasword[], char ConfirmPasword[])
{

	fout.open(filename1, ios::app);
	userprofiledata.open(filename2, ios::app);
	int length = 0, length2 = 0;
	cin.ignore();
	cout << "Enter  First Name : ";
	cin.getline(FirstName, 15, '\n');
	cout << "Enter  Last Name : ";
	cin.getline(LastName, 15, '\n');
	cout << "Enter Unique Name (It Should Be In Digits) :";
	cin.getline(UniqueName, 15, '\n');
	cout << "Enter Pasword : ";
	cin.getline(pasword, 15, '\n');
	cout << "Please Re-Enter Your Pasword : ";
	cin.getline(ConfirmPasword, 15, '\n');

	length = CheckLength(pasword);

	length2 = CheckLength(ConfirmPasword);


	if (length != length2)
	{
		cout << "Your Password Doesn't Match Please Try Again" << endl;
		do
		{
			cout << "Please Re-Enter Your Password : ";
			cin.getline(ConfirmPasword, 15, '\n');
			length2 = 0;
			for (int i = 0; ConfirmPasword[i] != '\0'; i++)
			{
				length2++;
			}
			if (length == length2)
			{

				for (int j = 0; pasword[j] != '\0'; j++)
				{
					if (pasword[j] != ConfirmPasword[j])
					{
						cout << " PassWords Are Not Matched Re-Enter " << endl;
						do
						{
							cin.getline(ConfirmPasword, 15);
						} while (ConfirmPasword[j] != pasword[j]);
					}
					else
					{
						break;
					}
				}
			}
		} while (length != length2);
	}

	else if (length == length2)
	{


		for (int j = 0; pasword[j] != '\0'; j++)
		{
			if (pasword[j] != ConfirmPasword[j])
			{
				cout << " Passwords Are Not Matched Re-Enter " << endl;
				do
				{
					cin.getline(ConfirmPasword, 15);
				} while (ConfirmPasword[j] != pasword[j]);
			}
			else
			{
				break;
			}
		}
	}
	userprofiledata << FirstName << " " << LastName << "," << UniqueName << "," << ConfirmPasword << endl;

	fout << UniqueName << "," << ConfirmPasword << endl;
	fout.close();
	userprofiledata.close();
	cout << "\n";
	cout << "\t\t*********************************************" << endl;
	cout << "\t\t        Your Account Has Been Created        " << endl;
	cout << "\t\t*********************************************" << endl;


}

bool SignIn(ifstream& fin, char filename1[], char* UserName, char* Password)
{
	bool flag3 = true;
	fin.open(filename1);
	UserName = new char[20];
	Password = new char[20];
	int flag = 0;
	int Length = 0;
	int Length2 = 0;
	char* UniqueID = NULL;
	char* UniqueID2 = NULL;
	UniqueID = new char[15];
	UniqueID2 = new char[15];
	cin.ignore();
	cout << "Please Enter Your Unique ID : ";
	cin.getline(UniqueID, 14, '\n');
	for (int i = 0; UniqueID[i] != '\0'; i++)
	{
		Length++;
	}
	int Length3 = 0;
	int Length4 = 0;
	int temp = 0;
	if (!fin.is_open())
	{
		cout << "File Not Open ! " << endl;
	}
	else
	{
		while (fin.getline(UserName, 19, ','))
		{
			flag = 0;
			Length3 = 0;
			for (int i = 0; UserName[i] != '\0' && fin; i++)
			{
				Length3++;
			}

			fin.getline(Password, 19, '\n');
			Length4 = 0;
			for (int j = 0; Password[j] != '\0'; j++)
			{
				Length4++;
			}
			if (Length == Length3)
			{
				for (int i = 0; UserName[i] != '\0'; i++)
				{
					if (UserName[i] != UniqueID[i])
					{
						flag = 1;
						break;
						return false;
					}
					else
					{
						continue;
					}
				}
				if (flag == 0)
				{
					int flag2 = 0;
					cout << "-------------------------------" << endl;
					cout << "Please Enter Your Password : ";
					cin.getline(UniqueID2, 14, '\n');
					Length3 = 0;
					for (int i = 0; UniqueID2[i] != '\0'; i++)
					{
						Length3++;
					}
					if (Length3 == Length4)
					{
						for (int i = 0; UniqueID2[i] != '\0'; i++)
						{
							if (UniqueID2[i] != Password[i])
							{

								flag2 = 1;
								break;
								return false;

							}
							else
							{
								continue;
							}
						}
						if (flag2 == 0)
						{
							cout << "\n";
							cout << "\t\t----------------------------------------------" << endl;
							cout << "\t\tYou Have Successfully Login Into Your Account " << endl;
							return true;
						}

					}
				}

			}
		}
	}
	fin.close();
}

bool ChangePassword(ifstream& fin2, char filename1[], char* FileUniqueID, char* FilePassword)
{
	ofstream fout;
	char* YourUniqueID = NULL;
	char* OldPassword = NULL;
	int  flag = 0;
	bool flag2 = false;
	FileUniqueID = new char[100];
	FilePassword = new char[100];
	YourUniqueID = new char[20];
	OldPassword = new char[20];
	char* NewPassword = new char[20];
	int Length = 0;
	int Length2 = 0;
	int Length3 = 0, Length4 = 0;
	fout.open("temp.txt");
	fin2.open(filename1);

	cin.ignore();
	cout << "\n";
	cout << "------------------------------------" << endl;
	cout << "Please Enter Your Unique ID : ";
	cin.getline(YourUniqueID, 19, '\n');
	cout << "------------------------------------" << endl;
	for (int i = 0; YourUniqueID[i] != '\0'; i++)
	{
		Length++;
	}
	if (!fin2.is_open())
	{
		cout << "File is not Opened " << endl;
	}
	else
	{
		cout << "---------------------------------" << endl;
		cout << "Please Enter Your Old Password : ";
		cin.getline(OldPassword, 19, '\n');
		cout << "------------------------------------" << endl;
		for (int i = 0; OldPassword[i] != '\0'; i++)
		{
			Length2++;
		}
		while (fin2.getline(FileUniqueID, 99, ','))
		{
			Length3 = 0;
			for (int i = 0; FileUniqueID[i] != '\0'; i++)
			{
				Length3++;
			}
			fin2.getline(FilePassword, 99, '\n');

			Length4 = 0;
			for (int i = 0; FilePassword[i] != '\0'; i++)
			{
				Length4++;
			}
			if (Length == Length3 && Length2 == Length4)
			{
				for (int k = 0; OldPassword[k] != '\0' && YourUniqueID[k] != '\0'; k++)
				{
					if (FilePassword[k] != OldPassword[k] && YourUniqueID[k] != FilePassword[k])
					{
						flag = 1;
						cout << "-----------------------------------------------------" << endl;
						cout << "*******Your User Name or Password is Incorrect ******" << endl;
						cout << "-----------------------------------------------------" << endl;
						flag2 = false;
						break;
					}
				}
				if (flag == 0)
				{
					cout << "--------------------------" << endl;
					cout << "Enter New Password Please " << endl;
					cin.getline(NewPassword, 19, '\n');
					cout << "------------------------------------------------------------" << endl;
					cout << "\t\t***********Your Password Has Been Changed**************" << endl;
					cout << "\t\t*********     You Can Check In txt File         ********" << endl;
					cout << "\t\t--------------------------------------------------------" << endl;
					fout << FileUniqueID << "," << NewPassword << endl;
					flag2 = true;
				}
				else
				{
					fout << FileUniqueID << "," << FilePassword << endl;
				}
			}
			else
			{
				fout << FileUniqueID << "," << FilePassword << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "*******Your User Name or Password is Incorrect ******" << endl;
				cout << "-----------------------------------------------------" << endl;
				flag2 = false;
				break;
			}
		}
	}
	fin2.close();
	fout.close();

	fout.open(filename1, ios::trunc);
	fin2.open("temp.txt");
	if (!fin2.is_open())
	{
		cout << "File  Not Open " << endl;
	}
	else
	{
		while (fin2.getline(FileUniqueID, 99, ','))
		{
			fin2.getline(FilePassword, 99, '\n');
			fout << FileUniqueID << "," << FilePassword << endl;
		}
		fin2.close();
		fout.close();
	}
	remove("temp.txt");

	return flag2;
}
void PostJobDescription(ofstream &fout, char *JobTitle, char *JobDetails, char *JobCatagery, char *DeadLine, char *JobID)
{
	int job = 0;
	char *Post = NULL;
	Post = new char[20];
	JobTitle = new char[15];
	JobDetails = new char[100];
	JobCatagery = new char[15];
	DeadLine = new char[50];
	JobID = new char[15];
	char City[15] = { '\0' };
	char Experience[100] = { '\0' };
	char jobStatus[10] = { '\0' };

	do{
		cout << "\n";
		cout << "--------------------------------------" << endl;
		cout << "For Posting Job Description Press 1 : " << endl;
		cout << "For Exit                    Press 2 : " << endl;
		cout << "Enter Your Desired Input            : ";
		cin >> job;
		cout << "--------------------------------------" << endl;
		if (job == 1)
		{
			cin.ignore();
			cout << "You Are Going To Posting a Job " << endl;
			cout << "PLease Write Job Catagery That You Want To Post : ";
			cin.getline(Post, 20, '\n');
			Post = PlaceTxt(Post);
			cout << "--------------------------------------" << endl;
			cout << "Enter Job Title : ";
			cin.getline(JobTitle, 15, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter Job Catagery : ";
			cin.getline(JobCatagery, 15, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter City : ";
			cin.getline(City, 15, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter Experience Required : ";
			cin.getline(Experience, 100, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter Job Status : ";
			cin.getline(jobStatus, 10, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter Deadline For Applying : ";
			cin.getline(DeadLine, 50, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter Job I'd : ";
			cin.getline(JobID, 10, '\n');
			cout << "--------------------------------------" << endl;
			cout << "Enter Job Details : ";
			cout << "When You Complete Press ' + '  To Stop" << endl;
			cin.getline(JobDetails, 100, '+');
			cout << "--------------------------------------" << endl;
			fout.open(Post, ios::app);

			fout << "Job Title:" << JobTitle << endl;
			fout << "Job Catagery:" << JobCatagery << endl;
			fout << "City:" << City << endl;
			fout << "Experience Required:" << Experience << endl;
			fout << "Job Status:" << jobStatus << endl;
			fout << "Job Applying DeadLine:" << DeadLine << endl;
			fout << "Job I'd:" << JobID << endl;
			fout << "Job Detail:" << JobDetails << endl;
			fout.close();

			ofstream fout2;
			fout2.open("JobList.txt", ios::app);
			fout2 << "Job Title:" << JobTitle << endl;
			fout2 << "Job I'd:" << JobID << endl;
			fout2 << "Job Status:" << jobStatus << endl;
			fout2.close();

			ofstream fout3;
			fout3.open("AvailableJobs.txt", ios::app);
			fout3 << "Job Title:" << JobTitle << endl;
			fout3 << "Job Catagery:" << JobCatagery << endl;
			fout3 << "City:" << City << endl;
			fout3 << "Job I'd:" << JobID << endl;
			fout3 << "Job Detail:" << JobDetails << endl;
			fout3.close();

			ofstream fout4;
			fout4.open("ApplyJobsFile.txt");
			fout4 << "Job Title:" << JobTitle << endl;

			fout4.close();
		}
		else if (job > 1)
		{
			break;
		}
	} while (job > 0 && job <= 1);
}
void Modifying(ifstream& fin2, char filename[], char* FileCatagery, char* FileCatageryDetail, char* SelectModifyCatagery, char *ModifyngData)
{
	ofstream fout;
	bool flag = true;
	FileCatagery = new char[100];
	FileCatageryDetail = new char[1000];
	SelectModifyCatagery = new char[100];
	ModifyngData = new char[100];
	int Length = 0;
	int Length2 = 0;

	fout.open("temp.txt");
	fin2.open(filename);
	if (!fin2.is_open())
	{
		cout << "File Not Open" << endl;
		exit(-1);
	}


	cout << "Please Write Which Catagery You Want to Modify : ";
	cin.getline(SelectModifyCatagery, 100, '\n');
	cout << "------------------------------------" << endl;
	for (int i = 0; SelectModifyCatagery[i] != '\0'; i++)
	{
		Length++;
	}

	while (fin2.getline(FileCatagery, 1000, ':'))
	{
		Length2 = 0;
		for (int i = 0; FileCatagery[i] != '\0'; i++)
		{
			Length2++;
		}
		fin2.getline(FileCatageryDetail, 99, '\n');

		if (Length == Length2)
		{
			for (int k = 0; SelectModifyCatagery[k] != '\0'; k++)
			{
				if (SelectModifyCatagery[k] != FileCatagery[k])
				{
					flag = false;
					cout << "----------------------------------------------------------" << endl;
					cout << "******* Sorry ! This Catagery : " << SelectModifyCatagery << " : does not Exist**********" << endl;
					cout << "----------------------------------------------------------" << endl;
					break;
				}
				else
				{
					flag = true;
				}
			}
			if (flag == true)
			{

				cout << "Please Start Modifying " << endl;
				cin.getline(ModifyngData, 100, '\n');
				cout << "------------------------------------------------------------" << endl;
				cout << "\t\t***********        Detail Modified       **************" << endl;
				cout << "\t\t*********    You Can Check In Your txt File     ********" << endl;
				cout << "\t\t--------------------------------------------------------" << endl;
				fout << FileCatagery << ":" << ModifyngData << endl;

			}
			else
			{
				fout << FileCatagery << ":" << FileCatageryDetail << endl;
			}
		}
		else
		{
			fout << FileCatagery << ":" << FileCatageryDetail << endl;
		}
	}
	fin2.close();
	fout.close();

	fout.open(filename, ios::trunc);
	fin2.open("temp.txt");
	if (!fin2.is_open())
	{
		cout << "File is not Opened there " << endl;
	}
	else
	{
		while (fin2.getline(FileCatagery, 99, ':'))
		{
			fin2.getline(FileCatageryDetail, 99, '\n');
			fout << FileCatagery << ":" << FileCatageryDetail << endl;
		}
		fin2.close();
		fout.close();
	}
	remove("temp.txt");
}
void ViewJobList(ifstream &fin2, char *JobId, char *Jobtitle)
{

	JobId = new char[1000];
	Jobtitle = new char[1000];
	fin2.open("JobList.txt");
	if (!fin2.is_open())
	{
		cout << "File Not Open ";
		exit(-1);
	}
	while (fin2.getline(JobId, 1000, ':'))
	{
		fin2.getline(Jobtitle, 1000, '\n');
		cout << JobId << ":" << Jobtitle << endl;
	}

	fin2.close();


}
int CheckLength(char FirstName[])
{
	int j = 0;
	for (int i = 0; FirstName[i] != '\0'; i++)
	{
		j++;
	}
	return j;
}
void CreateJobSeekerProfile(ofstream & fout2, char filename5[], char *FirstName, char *LastName, char *PhoneNumber, char *Address, char *Education, char *PastJob, char *Experience)
{
	fout2.open(filename5, ios::out);
	FirstName = new char[15];
	LastName = new char[15];
	PhoneNumber = new char[15];
	Address = new char[100];
	Education = new char[100];
	PastJob = new char[50];
	Experience = new char[10];
	cout << "\n";
	cin.ignore();
	cout << "----------------------------------" << endl;
	cout << "Please Enter Your First Name    : " << endl;
	cin.getline(FirstName, 15, '\n');
	cout << "-----------------------------------" << endl;
	cout << "Please Enter Your Last Name     :  " << endl;
	cin.getline(LastName, 15, '\n');
	cout << "----------------------------------" << endl;
	cout << "Please Enter Your Phone Number  : " << endl;
	cin.ignore();
	cin >> PhoneNumber;
	cin.ignore();
	cout << "----------------------------------" << endl;
	cout << "Please Enter Your Address        : " << endl;
	cin.getline(Address, 100, '\n');
	cout << "----------------------------------" << endl;
	cout << "Please Enter Your Education     : " << endl;
	cin.getline(Education, 100, '\n');
	cout << "----------------------------------" << endl;
	cout << "Please Enter Your Past Job      : " << endl;
	cin.getline(PastJob, 50, '\n');
	cout << "----------------------------------" << endl;
	cout << "Please Enter Your Experience In Years: " << endl;
	cin.getline(Experience, 10, '\n');
	cout << "--------------------------------------" << endl;
	fout2 << "First Name:" << FirstName << endl;
	fout2 << "Last Name:" << LastName << endl;
	fout2 << "Phone Number:" << PhoneNumber << endl;
	fout2 << "Address:" << Address << endl;
	fout2 << "Education:" << Education << endl;
	fout2 << "Past Job:" << PastJob << endl;
	fout2 << "Experience:" << Experience;

	cout << "--------------------------------------------------------------------" << endl;
	cout << "\t\t***********     Your Profile Has Been Created     **************" << endl;
	cout << "\t\t----------------------------------------------------------------" << endl;

	fout2.close();
	Reset(FirstName);
	Reset(LastName);
	Reset(PhoneNumber);
	Reset(Address);
	Reset(Education);
	Reset(PastJob);
	Reset(Experience);
}
void AvailableJobss(ifstream &fin3, char filename7[], char *jobs)
{
	jobs = new char[100];
	int size = 0;
	fin3.open(filename7);
	if (!fin3.is_open())
	{
		cout << "Sorry ! Job Doesn't Exist ";
		exit(-1);
	}
	size++;
	jobs = ReadFromFile(fin3, jobs, size);
	cout << "\n";
	cout << "***************************************************************************" << endl;
	DisplayData(jobs, size);
	fin3.close();


}
void DisplayData(char * ptr, int size)
{
	for (int i = 0; i<size; i++)
	{
		cout << ptr[i];
	}
	cout << "\n";
	cout << "***************************************************************************" << endl;
	cout << "\n";
}
void SerachCatagery(ifstream &fin4, char filename4[], char *AvailableJobs)
{
	AvailableJobs = new char[100];
	int size = 0;
	fin4.open(filename4);
	if (!fin4.is_open())
	{
		cout << "Sorry ! This Job Does Not Exist ";
		exit(-1);
	}
	AvailableJobs = ReadFromFile(fin4, AvailableJobs, size);
	DisplayData(AvailableJobs, size);
	Reset(AvailableJobs);


}
void ApplyForJob(ifstream &fin5, char *Apply)
{
	Apply = new char[100];
	char *FileJobTitle = NULL;
	char *FileJobName = NULL;
	char *FullName = NULL;
	char *Address = NULL;
	char *CellNumber = NULL;
	FullName = new char[15];
	CellNumber = new char[50];
	Address = new char[100];
	FileJobTitle = new char[1000];
	FileJobName = new char[1000];
	bool flag = false;
	ofstream fout6;
	cin.ignore();
	char *file = NULL;
	int length = 0;
	cout << "For Applying Please Write Job Catagery : ";
	cin.getline(Apply, 50, '\n');
	Apply = PlaceTxt(Apply);
	for (int i = 0; Apply[i] != '\0'; i++)
	{
		length++;
	}
	file = new char[length];
	fin5.open(Apply);
	if (!fin5.is_open())
	{
		cout << "Job Does't Exist ";
		exit(-1);
	}
	cout << "Please Enter Your Detail " << endl;

	cout << "Enter Your Full Name : " << endl;
	cin.getline(FullName, 15, '\n');
	cout << "Enter Your Phone Number : " << endl;
	cin.getline(CellNumber, 50, '\n');
	cout << "Enter Your Address : " << endl;
	cin.getline(Address, 100, '\n');
	cout << "You Have Applied For This Job " << endl;
	fout6.open("AppliedJobs.txt", ios::app);
	while (fin5.getline(FileJobTitle, 99, ':'))
	{
		fin5.getline(FileJobName, 99, '\n');
		fout6 << FileJobTitle << ":" << FileJobName << endl;
	}


	fin5.close();
	fin5.open(Apply);
	if (!fin5.is_open())
	{
		cout << "File not open" << endl;
	}
	fin5.getline(FileJobTitle, 100, '\n');
	ofstream fout7;
	fout6 << "You Have Applied For This Job " << endl;

	fout7.open("ListOfCandidates.txt", ios::app);
	fout7 << FileJobTitle << endl;
	fout7 << "Full Name:" << FullName << endl;
	fout7 << "Phone Number:" << CellNumber << endl;
	fout7 << "Address :" << Address << endl;
	fin5.close();
	fout6.close();
	fout7.close();
	fin5.close();


}
void HireCandidate(ifstream &fin7, char *Hire)
{
	bool flag = false;
	Hire = new char[100];
	char *number = NULL;
	char *Hire2 = NULL;
	Hire2 = new char[100];
	number = new char[15];
	ofstream fout7;
	int length = 0, length2 = 0, length3 = 0, length4 = 0;
	fin7.open("ListOfCandidates.txt");
	if (!fin7.is_open())
	{
		cout << "File not open" << endl;
		exit(-1);
	}
	while (fin7.getline(Hire, 100, ':'))
	{
		fin7.getline(Hire2, 100, '\n');
		cout << Hire << ":" << Hire2 << endl;

	}
	fin7.close();
	fin7.open("ListOfCandidates.txt");

	fout7.open("AcceptedJobs.txt", ios::app);
	if (!fin7.is_open())
	{
		cout << "File not open" << endl;
		exit(-1);
	}
	cin.ignore();
	cout << "--------------------------------------------------------------" << endl;
	cout << "Please Enter Phone Number Of Candidate Which You Want To Hire " << endl;
	cout << "So That He/She Will Be Notified " << endl;
	cout << "Please Enter Number : ";
	cin.getline(number, 15, '\n');
	for (int i = 0; number[i] != '\0'; i++)
	{
		length++;
	}
	while (fin7.getline(Hire, 100, ':'))
	{
		fin7.getline(Hire2, 100, '\n');
		length2 = 0;

		for (int i = 0; Hire2[i] != '\0'; i++)
		{
			length2++;
		}
		if (length == length2)
		{

			for (int i = 0; Hire2[i] != '\0'; i++)
			{
				if (Hire2[i] != number[i])
				{
					flag = false;
				}
				else
				{
					flag = true;
				}
			}
			if (flag == true)
			{
				fout7 << Hire << ":" << Hire2 << endl;
			}
			else
			{
				fout7 << Hire << ":" << Hire2 << endl;
			}
		}
		else
		{
			fout7 << Hire << ":" << Hire2 << endl;
		}
	}
	fin7.close();
	fout7.close();



}
void ListOfCandidatesApplied(ifstream &fin6, char *FullName, char *CellNumber)
{
	FullName = new char[1000];
	fin6.open("ListOfCandidates.txt");
	if (!fin6.is_open())
	{
		cout << "File Not Open";
		exit(-1);
	}
	int size = 0;
	cout << "List Of Candidates who Applied For Job " << endl;
	FullName = ReadFromFile(fin6, FullName, size);
	for (int i = 0; i<size; i++)
	{
		cout << FullName[i];
	}
	/*while(fin6.getline(FullName,100,':'))
	{
	fin6.getline(CellNumber,100,'\n');
	}*/
	fin6.close();


}
char* ReadFromFile(ifstream& fin, char* ptr, int& size)
{
	char data = '\0';
	fin.get(data);
	if (data == '\0')
	{
		ptr = NULL;
		return NULL;
	}
	else
	{
		while (data != '\0' && fin)
		{

			size++;
			ptr = Regrow1D(ptr, size, data);
			fin.get(data);
		}
		ptr[size] = NULL;
		return ptr;
	}
}
char* Regrow1D(char* ptr, int size, char data)
{
	char* ptr2 = NULL;
	if (size == 1)
	{
		ptr2 = new char[size];
		ptr2[size - 1] = data;

	}
	else
	{
		ptr2 = new char[size];
		CopyOldData(ptr, ptr2, size);
		ptr2[size - 1] = data;
		Reset(ptr);

	}
	return ptr2;

}
void CopyOldData(char* ptr, char* ptr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		ptr2[i] = ptr[i];
	}
}
char* PlaceTxt(char *ptr)
{
	char text[] = { ".txt" };
	int length = 0;
	for (int i = 0; ptr[i] != '\0'; i++)
	{
		length++;
	}

	int size3 = length + 5;
	char* ptr2 = new char[size3];
	int i = 0;
	for (i = 0; ptr[i] != '\0'; i++)
	{
		ptr2[i] = ptr[i];
	}
	for (int j = 0; text[j] != '\0'; j++)
	{
		ptr2[i] = text[j];
		i++;
	}
	ptr2[i] = '\0';
	return ptr2;
}
void Reset(char *ptr)
{
	delete[] ptr;
	ptr = NULL;
}
