
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* define functions */
void SaveUser();
void AddUser();
void ViewAllUser();
void DeleteUser();
void CheckUser();
void ChangeUser();
void SaveBook();
void AddBook();
void ViewAllBook();
void DeleteBook();
void FindBookISBN();
void ChangeBook();
void Borrow();
void Return();
void AdminI();

/*Define structure to store information of users*/
typedef struct UserInfo
{
	char name[20];
	char universityid[20];
	char phonenumber[20];
	char identity[20];
	char bookloans[20];
	char charges[20];
}User, *pUser;
User user[20] = { 0 };
int numu = 0;
int Index = 1, Index1 = 1, Index2 = 1;

/*Here are void for user system*/
void SaveUser()
{
	FILE* puserFile = NULL;
	puserFile = fopen("user.txt", "ab");
	if (puserFile != 0)
	{
		fwrite(&numu, 4, 1, puserFile);
		fwrite(&user, sizeof(User), numu, puserFile);
	}
	fclose(puserFile);
}
void ReadUser()
{
	FILE* puserFile = NULL;
	puserFile = fopen("user.txt", "rb+");
	if (puserFile != 0)
	{
		fread(&numu, 4, 1, puserFile);
		fread(&user, sizeof(User), numu, puserFile);
	}
	fclose(puserFile);
}

/*the function of adding user is as follows*/
void AddUser()
{
	ReadUser();
	printf("Please enter the name to be stored£º\n");
	scanf("%s", user[numu].name);
	printf("Please enter the university ID to be stored£º\n");
	scanf("%s", user[numu].universityid);
	printf("Please enter the phone number to be stored£º\n");
	scanf("%s", user[numu].phonenumber);
	printf("Please enter the identity (staff or student) to be stored£º\n");
	scanf("%s", user[numu].identity);
	printf("Please enter the bookloans to be stored£º\n");
	scanf("%s", user[numu].bookloans);
	printf("Please enter the charges to be stored£º\n");
	scanf("%s", user[numu].charges);
	numu++;
	FILE* puserFile = NULL;
	puserFile = fopen("user.txt", "ab");
	if (puserFile != 0)
	{
		fwrite(&numu, 4, 1, puserFile);
		fwrite(&user, sizeof(User), numu, puserFile);
	}
	fclose(puserFile);
	system("pause");
	system("cls");
}

/*the function of checking all user information*/
void ViewAllUser()
{
	ReadUser();
	for (int i = 0; i<numu; i++)
	{
		printf("Name£º%s\n", user[i].name);
		printf("University ID£º%s\n", user[i].universityid);
		printf("Phone number£º%s\n", user[i].phonenumber);
		printf("Identity£º%s\n", user[i].identity);
		printf("Bookloans£º%s\n", user[i].bookloans);
		printf("Charges£º%s\n", user[i].charges);
	}
	system("pause");
	system("cls");
}

/*the function of deleting user information*/
void DeleteUser()
{
	ReadUser();
	char str[20] = { 0 };
	int temp = 0;
	int i = 0;
	printf("Please enter the name to be deleted£º");
	scanf("%s", &str);
	for (i; i < numu; i++)
	{
		if (strcmp(str, user[i].name) == 0)
		{
			for (int nIndex = i; nIndex < numu; nIndex++)
			{
				temp = 1;
				break;
			}
		}
		if (temp == 1)
		{
			strcpy(user[i].name, user[i + 1].name);
			strcpy(user[i].universityid, user[i + 1].universityid);
			strcpy(user[i].phonenumber, user[i + 1].phonenumber);
			strcpy(user[i].identity, user[i + 1].identity);
			strcpy(user[i].bookloans, user[i + 1].bookloans);
			strcpy(user[i].charges, user[i + 1].charges);
			numu--;
			SaveUser();

		}
		else
			printf("No name stored");
	}
	system("pause");
	system("cls");
}

/*the function of checking a user's information*/
void CheckUser()
{
	ReadUser();
	char str[20] = { 0 };
	int i = 0;
	printf("Please enter the name to be viewed£º");
	scanf("%s", &str);
	if (numu == 0)
	{
		printf("Name does not exist\n");
	}
	for (; i < numu; i++)
	{
		if (strcmp(str, user[i].name) == 0)
		{
			printf("Name£º%s\n", user[i].name);
			printf("University ID£º%s\n", user[i].universityid);
			printf("Phone number£º%s\n", user[i].phonenumber);
			printf("Identity£º%s\n", user[i].identity);
			printf("Bookloans£º%s\n", user[i].bookloans);
			printf("Charges£º%s\n", user[i].charges);
		}
	}
	system("pause");
	system("cls");
}

/*the function of modifying user information*/
void ChangeUser()
{
	ReadUser();
	char str[20] = { 0 };
	int i = 0;
	int num2 = 0;
	printf("Please enter the name to be modified£º");
	scanf("%s", &str);
	if (numu == 0)
	{
		printf("Name does not exist\n");
	}
	for (i; i < numu; i++)
	{
		if (strcmp(str, user[i].name) == 0)
		{
			num2 = 1;
		}

	}
	if (num2 == 1)
	{
		printf("Please enter the new university ID£º\n");
		scanf("%s", user[i - 1].universityid);
		printf("Please enter the new phone number£º\n");
		scanf("%s", user[i - 1].phonenumber);
		printf("Please enter the new identity£º\n");
		scanf("%s", user[i - 1].identity);
		printf("Please enter the new bookloans£º\n");
		scanf("%s", user[i - 1].bookloans);
		printf("Please enter the new charges£º\n");
		scanf("%s", user[i - 1].charges);

		FILE* puserFile = NULL;
		puserFile = fopen("user.txt", "wb+");
		if (puserFile != 0)
		{
			fwrite(&numu, 4, 1, puserFile);
			fwrite(&user, sizeof(User), numu, puserFile);
		}
		fclose(puserFile);

	}
	else
	{
		printf("Name does not exist\n");
	}
	system("pause");
	system("cls");
}

void Initialize()
{
	FILE* pFile = NULL;
	errno_t Errno = fopen("123.txt", "rb+");
	if (Errno != 0 || pFile == 0)
	{
		numu = 0;
	}
	else
	{
		fread(&numu, 4, 1, pFile);
		fread(&user, sizeof(User), numu, pFile);
		fclose(pFile);
	}

}

/*Here are void for book storage*/

/*define a structure of books*/
typedef struct BookInfo
{
	char author[20];
	char title[20];
	char ISBN[20];
	char subject[20];
	char type[20];
	char shelfmark[20];
	char loanstatus[20];
	char possession[20];
}Book, *pBook;
Book book[20] = { 0 };
int numb = 0;

/*the function of saving books*/
void SaveBook()
{
	FILE* pbookFile = NULL;
	pbookFile = fopen("book.txt", "ab");
	if (pbookFile != 0)
	{
		fwrite(&numb, 4, 1, pbookFile);
		fwrite(&book, sizeof(Book), numb, pbookFile);
	}
	fclose(pbookFile);
}
void ReadBook(){
	FILE* pbookFile = NULL;
	pbookFile = fopen("book.txt", "rb+");
	if (pbookFile != 0)
	{
		fread(&numb, 4, 1, pbookFile);
		fread(&book, sizeof(Book), numb, pbookFile);
	}
	fclose(pbookFile);
}

/*the function of adding books*/
void AddBook()

{
	ReadBook();
	printf("Adding new book to the Libarary system now.\nPlz input the bookinfo in order:\n----------------------------------------------------------------\n");
	printf("Please enter the author to be stored£º\n");
	scanf("%s", book[numb].author);
	printf("Please enter the book title to be stored£º\n");
	scanf("%s", book[numb].title);
	printf("Please enter the book ISBN to be stored£º\n");
	scanf("%s", book[numb].ISBN);
	printf("Please enter the subject (staff or student) to be stored£º\n");
	scanf("%s", book[numb].subject);
	printf("Please enter the type to be stored£º\n");
	scanf("%s", book[numb].type);
	printf("Please enter the shelfmark to be stored£º\n");
	scanf("%s", book[numb].shelfmark);
	printf("Please enter the loanstatus to be stored£º\n");
	scanf("%s", book[numb].loanstatus);
	strcpy(book[numb].possession, "Null");
	numb++;
	SaveBook();
	system("pause");
	system("cls");
}

/*the function of checking all the information of books*/
void ViewAllBook()
{
	ReadBook();
	for (int i = 0; i<numb; i++)
	{
		printf("Author£º%s\n", book[i].author);
		printf("Title£º%s\n", book[i].title);
		printf("Book ISBN£º%s\n", book[i].ISBN);
		printf("Subject£º%s\n", book[i].subject);
		printf("Type£º%s\n", book[i].type);
		printf("Shelfmark£º%s\n", book[i].shelfmark);
		printf("Loanstatus£º%s\n", book[i].loanstatus);
		printf("Possession:%s\n", book[i].possession);
	}
	system("pause");
	system("cls");
}

/*the function of deleting book information*/
void DeleteBook()
{
	ReadBook();
	char str[20] = { 0 };
	int temp = 0;
	int i = 0;
	printf("Please enter the author to be deleted£º");
	scanf("%s", &str);
	for (i; i < numb; i++)
	{
		if (strcmp(str, book[i].author) == 0)
		{
			temp = 1;
			break;
		}
	}
	if (temp == 1)
	{
		for (int nIndex = i; nIndex < numb; nIndex++)
		{
			strcpy(book[i].author, book[i + 1].author);
			strcpy(book[i].title, book[i + 1].title);
			strcpy(book[i].ISBN, book[i + 1].ISBN);
			strcpy(book[i].subject, book[i + 1].subject);
			strcpy(book[i].type, book[i + 1].type);
			strcpy(book[i].shelfmark, book[i + 1].shelfmark);
			strcpy(book[i].loanstatus, book[i + 1].loanstatus);
			strcpy(book[i].possession, book[i + 1].possession);
		}
		numb--;
		SaveBook();
	}
	else
	{
		printf("No author stored");
	}
	system("pause");
	system("cls");
}

/*the function of checking information of a book*/
void FindBookISBN()
{
	ReadBook();
	char str[20] = { 0 };
	int i = 0;
	printf("Please enter the ISBN to be viewed£º");
	scanf("%s", &str);
	if (numb == 0)
	{
		printf("Author does not exist\n");
	}
	for (; i < numb; i++)
	{
		if (strcmp(str, book[i].ISBN) == 0)
		{
			printf("Author£º%s\n", book[i].author);
			printf("Title£º%s\n", book[i].title);
			printf("Book ISBN£º%s\n", book[i].ISBN);
			printf("Subject£º%s\n", book[i].subject);
			printf("Type£º%s\n", book[i].type);
			printf("Shelfmark£º%s\n", book[i].shelfmark);
			printf("Loanstatus£º%s\n", book[i].loanstatus);
			printf("Possession:%s\n", book[i].possession);
		}
	}
	system("pause");
	system("cls");
}

/*the function of changing information of books*/
void ChangeBook()
{
	ReadBook();
	char str[20] = { 0 };
	int i = 0;
	int temp = 0;
	printf("Please enter the book ISBN to be modified£º");
	scanf("%s", &str);
	if (numb == 0)
	{
		printf("Book does not exist\n");
	}
	for (i; i < numb; i++)
	{
		if (strcmp(str, book[i].ISBN) == 0)
		{
			temp = 1;
		}

	}
	if (temp == 1)
	{
		printf("Please enter the new book title£º\n");
		scanf("%s", book[i - 1].title);
		printf("Please enter the new book author£º\n");
		scanf("%s", book[i - 1].author);
		printf("Please enter the new subject£º\n");
		scanf("%s", book[i - 1].subject);
		printf("Please enter the new type£º\n");
		scanf("%s", book[i - 1].type);
		printf("Please enter the new shelfmark£º\n");
		scanf("%s", book[i - 1].shelfmark);
		SaveBook();
	}
	else
	{
		printf("Book does not exist\n");
	}
	system("pause");
	system("cls");
}

/*the function of borrowing books*/
void Borrow(){
	ReadBook(); ReadUser();
	int numb, end = 0;
	int i, i1, j[100] = { -1 }, k, t = 0;
	char d[20], m[20];

	while (end == 0){
		system("cls");
		printf("Search£º");
		printf("1:bookname              2:ISBN");
		printf("\n\nPlease enter the thing you want to search£º");
		scanf("%d", &k);
		if (k == 1)
		{
			system("cls");
			printf("please enter the book title:");
			scanf("%s", &m);
			for (i = 0; i < numb; i++)
			if (strcmp(m, book[i].title) == 0)
			{
				j[t] = i;
				t++;
				break;
			}
		}
		else if (k == 2)
		{
			system("cls");
			printf("please enter the ISBN:");
			scanf("%s", &d);
			for (i = 0; i < numb; i++)
			if (d == book[i].ISBN)
			{
				j[t] = i;
				t++;
				break;
			}
		}

		if (t == 0)
		{
			printf("book not found\n");
			printf("\n\continue£¿\n¡¾press 1 to continue, other to quit¡¿");
			scanf("%d", &k);
			if (k != 1)
				end = 1;
		}
		else
		{
			system("cls");
			printf("author:%s\n", book[j[i]].author);
			printf("title:%s\n", book[j[i]].title);
			printf("ISBN:%s\n", book[j[i]].ISBN);
			printf("type:%s\n", book[j[i]].type);
			printf("shelfmark:%s\n", book[j[i]].shelfmark);
			printf("loanstatus:%s\n", book[j[i]].loanstatus);
			printf("possession:%s\n", book[j[i]].possession);
			if (strcmp(book[j[i]].possession, "Null") != 0)

				printf("\n\nThe book is borrowed.\n");
			else{
				printf("\n\n*************************\n*************************\n\n1:borrow   2:quit\n\n*************************\n*************************\n");
				int p;
				scanf("%d", &p);
				if (p == 1)
				{
					system("cls");
					strcpy(book[j[i]].loanstatus, "borrowed");
					printf("Plz enter the borrower's name");
					scanf("%s", book[j[i]].possession);
					for (i1 = 0; i1 <= numu; i1++){
						if (strcmp(user[i1].name, book[j[i]].possession) == 0)
							strcpy(user[i1].bookloans, book[j[i]].ISBN);                                        /*one user one book*/
					}
					printf("borrowed\n");
					printf("\n\ncontinue£¿¡¾press 1 to continue, other to quit¡¿");
					scanf("%d", &k);
					if (k != 1)
						end = 1;
				}
			}
		}
	}
}

/*the function of returning books*/
void Return()
{
	ReadBook(); ReadUser();
	int end = 0;
	int i, j[100] = { -1 }, k, t = 0;
	char d[20], m[20];
	end = 0;
	while (end == 0){
	label_1:system("cls");
		printf("Search£º");
		printf("1:bookname              2:ISBN");
		printf("\n\nPlease enter the thing you want to search£º");
		scanf("%d", &k);
		if (k == 1)
		{
			system("cls");
			printf("please enter the book title:");
			scanf("%s", &m);
			for (i = 0; i < numb; i++)
			if (strcmp(m, book[i].title) == 0)
			{
				j[t] = i;
				t++;
				break;
			}
		}
		else if (k == 2)
		{
			system("cls");
			printf("please enter the ISBN:");
			scanf("%s", &d);
			for (i = 0; i < numb; i++)
			if (d == book[i].ISBN)
			{
				j[t] = i;
				t++;
				break;
			}
		}

		if (t == 0)
		{
			printf("book not found\n");
			printf("\n\continue£¿\n¡¾press 1 to continue, other to quit¡¿");
			scanf("%d", &k);
			if (k != 1)
				end = 1;
		}
		else
		{
			system("cls");
			printf("author:%s\n", book[j[i]].author);
			printf("title:%s\n", book[j[i]].title);
			printf("ISBN:%s\n", book[j[i]].ISBN);
			printf("type:%s\n", book[j[i]].type);
			printf("shelfmark:%s\n", book[j[i]].shelfmark);
			printf("loanstatus:%s\n", book[j[i]].loanstatus);
			printf("possession:%s\n", book[j[i]].possession);
			if (strcmp(book[j[i]].possession, "Null") == 0)

				printf("\n\nThe book is in stock, check again.\nConsult administrator for more info\n");
			else{
				printf("\n\n*************************\n*************************\n\n1:return   2:quit\n\n*************************\n*************************\n");
				int p;
				scanf("%d", &p);
				if (p == 1)
				{
					system("cls");
					strcpy(book[j[i]].loanstatus, "in stock");
					strcpy(book[j[i]].possession, "Null");
					printf("returned\n");
					printf("\n\ncontinue£¿¡¾press 1 to continue, other to quit¡¿");
					scanf("%d", &k);
					if (k != 1)
						end = 1;
				}
			}
		}
	}
}

/*define meanings of options*/
#define USER 1
#define BOOK 2
#define ADMIN 3
#define EXIT 4
#define ADDAUSER 1
#define ADDABOOK 2
#define USERADMIN 3
#define BOOKADMIN 4
#define SHOWALLUSER 5
#define SHOWALLBOOK 6
#define BORROWBOOK 7
#define RETURNBOOK 8
#define EXIT2 9

/*the administrator menu part*/
void AdminI(){
	while (Index){
		int Choice1 = 0, temp1 = 0, temp2 = 0;
		system("cls");
		printf("Welcome to the libarary system\n\n---------------------------------------------------------------\n");
		printf("Admin Option:\n\n");
		printf("Add an User---------------------------------- 1\n");
		printf("Add a Book----------------------------------- 2\n");
		printf("Modify User Info----------------------------- 3\n");
		printf("Modify Book Infor---------------------------- 4\n");
		printf("Show All User-------------------------------- 5\n");
		printf("Show All Book-------------------------------- 6\n");
		printf("Borrow Book---------------------------------- 7\n");
		printf("Return Book---------------------------------- 8\n");
		printf("Exit----------------------------------------- 9\n");
		scanf("%d", &Choice1);
		if (Choice1 >= 1 && Choice1 <= 9)
		{
			switch (Choice1)
			{
			case ADDAUSER: { AddUser(); }break;
			case ADDABOOK: { AddBook(); }break;
			case USERADMIN: {system("cls");
				printf("Operation:\n\n");
				printf("Change User Info--------------------- 1\n");
				printf("Delete User Info--------------------- 2\n");
				scanf("%d", &temp1);
				if (temp1 == 1) ChangeUser();
				else if (temp1 == 2) DeleteUser(); }break;

			case BOOKADMIN:{ system("cls");
				printf("Operation:\n\n");
				printf("Change Book Info--------------------- 1\n");
				printf("Delete Book Info--------------------- 2\n");
				scanf("%d", &temp2);
				if (temp2 == 1) ChangeBook();
				else if (temp2 == 2) DeleteBook(); }break;

			case SHOWALLUSER:{ ViewAllUser(); }break;
			case SHOWALLBOOK: {ViewAllBook(); }break;
			case BORROWBOOK: {Borrow(); }break;
			case RETURNBOOK:{Return(); }break;
			case EXIT2:{ printf("Exit successfully!");
				Index = 0;
			}break;
			default: {}break;
			}
		}
		else
		{
			printf("Error! please select again");
		}
	}
}

/*the main menu part*/
int main()
{
	Initialize();
	while (Index){
		int Choice = 0;

		printf("Welcome to the libarary system\n\n---------------------------------------------------------------\n");
		printf("Option:\n\n");
		printf("User interface ------------------------------ 1\n");
		printf("Book storage--------------------------------- 2\n");
		printf("Admin---------------------------------------- 3\n");
		printf("Exit----------------------------------------- 4\n");
		printf("Borrower------------------------------------- 5\n");
		printf("plz select a function\n");
		scanf("%d", &Choice);
		if (Choice >= 1 && Choice <= 5)
		{
			switch (Choice)
			{
			case USER: { CheckUser(); }break;
			case BOOK: { FindBookISBN(); }break;
			case ADMIN:{ AdminI(); }break;
			case EXIT:{ printf("Exit successfully!");
				Index = 0;
			}break;
			case 5:{
					   int temp3;
					   printf("Borrow Book---------------------------------- 1\n");
					   printf("Return Book---------------------------------- 2\n");
					   scanf("%d", &temp3);
					   if (temp3 == 1) Borrow();
					   else if (temp3 == 2) Return();
			}break;
			}
		}
		else
		{
			printf("Error! please select again");
		}
	}
}