#include<stdio.h>      
#include<string.h>      
#include<ctype.h>       
#include<time.h>        
#include<stdlib.h>      
#include<windows.h>   

void Menu();
void Register();
void WriteToFile();
void Login();
void Submenu();
void Game();
void Writetohistory();
void Showhistory();
void Clearhistory();

int m = 1, n = 1;

typedef struct user {
	char usename[20];
	char password[20];
	char historytry[20];
	char historytime[20];
}User;
User user[50];
/*a structure named User is defined to store the array*/

char * filename = "user.txt";

int main()
{
	while (m)
	{
		Menu();
	}
	return 0;

}

/*Main menu*/
void Menu()
{
	printf("Welcome to Find the Pairs. Test your memory:\n\nSelect frome the following options:\n\n");
	printf("   a. Login to your account\n");
	printf("   b. Create new account\n");
	printf("   q. Quit\n");
	printf("\n   Option: ");
	char choice;
	while ((choice = getchar()) != 'q')   /*Judge which choice the player make*/
	{
		printf("Welcome to Find the Pairs. Test your memory:\n\nSelect frome the following options:\n\n");
		printf("   a. Login to your account\n");
		printf("   b. Create new account\n");
		printf("   q. Quit\n");
		printf("\n   Option: ");
		if (islower(choice))         /*Judge whether choice is the instructed one*/
			switch (choice)
		{
			case'a': Login();
				m = 0;
				break;
			case'b':Register();
				m = 0;
				break;
			default: printf("Please choose from a, b, or q\n");
		}
	}
	m = 0;
	printf("\n Goodbye\n");
	Sleep(1000);
	exit(0);
}

/*Register function*/
void Register()
{
	char name[20];
	char password[20];
	int i;
	system("cls");
	printf("Register Menu.\n\n");
	printf("Please enter a usename you would like to use: ");
	scanf("%s", &name);
	for (i = 0; i <= 50; i++)
	{
		while (strcmp(user[i].usename, name) == 0)
		{
			printf("user exist.\n");
			return;
		}
	}

	User user;
	strcpy(user.usename, name);
	printf("Please enter the password you would like to use: ");
	scanf("%s", &password);
	strcpy(user.password, password);
	WriteToFile(user);
}

/*store information to file function*/
void WriteToFile(User user)
{
	FILE *fw = fopen("user.txt", "a+");
	fputs(user.usename, fw);
	fprintf(fw, "\t");
	fputs(user.password, fw);
	fprintf(fw, "\n");
	fclose(fw);
	system("cls");

}

/*write to history function*/
void Writetohistory(User user)
{
	FILE *fp = fopen("user.txt", "a");
	fprintf(fp, "\t\t");
	fprintf(fp, "%s", user.historytry);
	fprintf(fp, "\t\t");
	fprintf(fp, "%s", user.historytime);
	fprintf(fp, "\n");
	fclose(fp);
	system("cls");
}

/*login function*/
void Login()
{
	char usename[20];
	char password[20];
	int i;

	FILE *fp;
	fp = fopen("user.txt", "r");


	system("cls");
	printf("Login Menu.\n");
	printf("Please enter your usename: ");
	scanf("%s", &usename);

	for (i = 0; i <= 50; i++)
	{
		fscanf(fp, "%s%s", user[i].usename, user[i].password);  /*determine whether the password is right*/
		if (strcmp(user[i].usename, usename) == 0)
		{
			break;
		}
		else
		{
			continue;
		}
	}

	printf("Please enter your passward: ");
	scanf("%s", &password);
	do
	{
		fscanf(fp, "%s%s", user[i].usename, user[i].password);
		if (strcmp(user[i].password, password) == 0)
		{
			printf("\nSuccess Login!\n\n");
			break;
		}
		else
		{
			printf("Wrong usename or password. Try again.\n");
			Sleep(2000);
			system("cls");
			Menu();
		}
	} while (strcmp(user[i].password, password) == 0);

	while (n)
	{
		Submenu();
	}
	return 0;
}

/*Submenu function*/
void Submenu()
{

	char choice;

	Sleep(1000);
	system("cls");
	printf("Hello player! Please select from the following options:\n\n");
	printf("   a. Start a new Game\n\n   b. Check your Game history\n\n");
	printf("   c. Clear Game history\n\n   d. Back to Menu\n\n   q. Quit\n\n");
	printf("   Option: ");

	while ((choice = getchar()) != 'q')
	{
		system("cls");
		printf("Hello player! Please select from the following options:\n\n");
		printf("   a. Start a new Game\n\n   b. Check your Game history\n\n");
		printf("   c. Clear Game history\n\n   d. Back to Menu\n\n   q. Quit\n\n");
		printf("   Option: ");
		if (islower(choice))
			switch (choice)
		{
			case'a':system("cls"); Game();
				break;
			case'b': system("cls");
				Showhistory();
				break;
			case'c': system("cls");
				Clearhistory();
				break;
			case'd': system("cls");
				Menu();
				break;
			default: printf("Please choose from a, b, c, d or q\n");
		}
	}
	while (getchar() != '\n')
		continue;
	n = 0;
	printf("Logout successfully.\n");
	Sleep(1000);
	exit(0);
}

/*show history function*/
void Showhistory(){
	char quit;
	FILE *fp = "user.txt";
	int WhichLine = 1;             /*Specify which line to read*/
	int CurrentIndex = 0;             /*Currently read line*/
	char StrLine[1024];             /*The maximum number of characters read per line can be expanded according to the actual situation*/
	if ((fp = fopen(filename, "r")) == NULL) /*Determine whether the file exists and is readable*/
	{
		printf("error!");
		return NULL;
	}
	printf("          HISTORY\nPLAYER        Attemp          Time\n");
	while (!feof(fp))
	{

		if (CurrentIndex == WhichLine)
		{
			fgets(StrLine, 1024, fp);  /*Read a line*/
			printf("%s", StrLine);

			WhichLine++;
		}
		fgets(StrLine, 1024, fp);  /*Read one line and position to the next line*/
		CurrentIndex++;

		printf("%s", StrLine);
	}
	fclose(fp);
	printf("Press B back to Submenu or Q to quit\n");
	fflush(stdin);
	quit = getchar();
	if (quit == 'B'){
		return;
	}
	else
	{
		printf("Goodbye");
		Sleep(1000);
		exit(0);
	}
	return NULL;
}

/*clear history function*/
void Clearhistory()
{
	FILE *fp;
	if ((fp = fopen("user.txt", "w+")) == NULL)
	{
		printf("No history.");
		getch();
		exit(0);
	}
	fclose(fp);
}

/*Game function*/
void Game()
{
	char save;
	int yesorno;
	int a[4][4];
	clock_t start, finish;
	int s, fleg;
	int duration;
	int try = 1, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0;
	srand((unsigned int)time(NULL));
	int(*p)[4];
	int b[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int r, c;
	p = b;
	for (r = 0; r < 4; r++){
		for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
		printf("\n\n");   /*show the first matrix*/
	}
	for (int i = 0; i <= 3; i++){
		for (int j = 0; j <= 3; j++){

			do{
				s = rand() % 8;
				fleg = 0;
				switch (s){
				case 0:if (s0 < 2){
						   a[i][j] = 0;
						   printf("@   ");
						   s0++;
						   fleg = 1;
						   break;
				}
					   else { ; break; }
				case 1:if (s1 < 2){
						   a[i][j] = 1; printf("#   ");
						   s1++; fleg = 1; break;
				}
					   else { ; break; }
				case 2:if (s2 < 2){
						   a[i][j] = 2; printf("$   ");
						   s2++; fleg = 1; break;
				}
					   else { ; break; }
				case 3:if (s3 < 2){
						   a[i][j] = 3; printf("!   ");
						   s3++; fleg = 1; break;
				}
					   else { ; break; }
				case 4:if (s4 < 2){
						   a[i][j] = 4; printf("&   ");
						   s4++; fleg = 1; break;
				}
					   else { ; break; }
				case 5:if (s5 < 2){
						   a[i][j] = 5; printf("^   ");
						   s5++; fleg = 1; break;
				}
					   else { ; break; }
				case 6:if (s6 < 2){
						   a[i][j] = 6; printf("*   ");
						   s6++; fleg = 1; break;
				}
					   else { ; break; }
				case 7:if (s7 < 2){
						   a[i][j] = 7; printf("~   ");
						   s7++; fleg = 1; break;
				}
					   else { ; break; }
				}
			} while (fleg != 1);

		}
		printf("\n\n");    /*show the second matrix*/
	}

	printf("Now you have 5 seconds to memorise the board\n\n");
	Sleep(5000);
	printf("Good luck!\n");
	Sleep(1000);

	system("cls");
	for (r = 0; r < 4; r++){
		for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
		printf("\n\n");
	}
	char cover[4][4];
	int q, w;
	p = cover;
	for (q = 0; q < 4; q++){
		for (w = 0; w < 4; w++) printf("_   ");
		printf("\n\n");
	}

	int(*pa)[4];
	pa = a;
	int(*pb)[4];
	pb = a;
	int p1, p2;
	int x1, y1, x2, y2;
	printf("Please enter your first choice:");
	start = clock();
	scanf("%d", &p1);
	while (p1 < 1 || p1 > 16)   /*determine whether it is right*/
	{
		printf("You entered a number out of the required range. Please enter again:");
		fflush(stdin);
		scanf("%d", &p1);
	}
	if (p1 % 4 == 0){
		x1 = 3;
		y1 = p1 / 4 - 1;
	}
	else{
		x1 = p1 % 4 - 1;
		y1 = p1 / 4;
	}

	printf("Please enter your second choice:");
	scanf_s("%d", &p2);
	while (p2 < 1 || p2 > 16)
	{
		printf("You entered a number a number out of the required range. Please enter again:");
		fflush(stdin);
		scanf("%d", &p2);
	}
	if (p2 % 4 == 0){
		x2 = 3;
		y2 = p2 / 4 - 1;
	}
	else{
		x2 = p2 % 4 - 1;
		y2 = p2 / 4;
	}

	/*cover the matrix*/
	char(*sp)[4];
	static char stay[4][4] = { { '_', '_', ' _', '_' }, { '_', '_', ' _', '_' }, { '_', '_', ' _', '_' }, { '_', '_', ' _', '_' } };
	int sr, sc;
	char ch1, ch2;
	sp = stay;
	char(*temp)[4];
	char tempstay[4][4] = { { stay[0][0], stay[0][1], stay[0][2], stay[0][3] }, { stay[1][0], stay[1][1], stay[1][2], stay[1][3] }, { stay[2][0], stay[2][1], stay[2][2], stay[2][3] }, { stay[3][0], stay[3][1], stay[3][2], stay[3][3] } };
	int tr, tc;
	char ch1t, ch2t;
	temp = tempstay;
	int score = 0;
	char quit;
	while (score < 7){
		if (*(*(pa + y1) + x1) != *(*(pb + y2) + x2)){
			system("cls");
			p = b;
			for (r = 0; r < 4; r++){
				for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
				printf("\n\n");
			}
			switch (*(*(pa + y1) + x1)){
			case 0:	ch1 = '@'; break;
			case 1: ch1 = '#'; break;
			case 2: ch1 = '$'; break;
			case 3: ch1 = '!'; break;
			case 4: ch1 = '&'; break;
			case 5: ch1 = '^'; break;
			case 6: ch1 = '*'; break;
			case 7: ch1 = '~'; break;
			}
			tempstay[y1][x1] = ch1;
			switch (*(*(pb + y2) + x2)){
			case 0:	ch2 = '@'; break;
			case 1: ch2 = '#'; break;
			case 2: ch2 = '$'; break;
			case 3: ch2 = '!'; break;
			case 4: ch2 = '&'; break;
			case 5: ch2 = '^'; break;
			case 6: ch2 = '*'; break;
			case 7: ch2 = '~'; break;
			}
			tempstay[y2][x2] = ch2;
			temp = tempstay;
			for (tr = 0; tr < 4; tr++){
				for (tc = 0; tc < 4; tc++) printf("%c   ", *(*(temp + tr) + tc));
				printf("\n\n");
			}

			tempstay[y1][x1] = stay[y1][x1];
			tempstay[y2][x2] = stay[y2][x2];
			printf("Sorry! Please try again!\n");
			Sleep(2000);
			printf("Do you want to continue? Y or N\n");
			fflush(stdin);
			quit = getchar();
			if (quit == 'N'){ break; }
			else{
				system("cls");
				p = b;
				for (r = 0; r < 4; r++){
					for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
					printf("\n\n");
				}

				temp = tempstay;
				for (tr = 0; tr < 4; tr++){
					for (tc = 0; tc < 4; tc++) printf("%c   ", *(*(temp + tr) + tc));
					printf("\n\n");
				}
				printf("Enter anotehr first choice:");
				scanf("%d", &p1);
				while (p1 < 1 || p1 > 16)
				{
					printf("You entered a number out of the required range. Please enter again:");
					fflush(stdin);
					scanf("%d", &p1);
				}
				if (p1 % 4 == 0){
					x1 = 3;
					y1 = p1 / 4 - 1;
				}
				else{
					x1 = p1 % 4 - 1;
					y1 = p1 / 4;
				}

				printf("Enter another second choice:");
				scanf("%d", &p2);
				while (p2 < 1 || p2 > 16)
				{
					printf("You entered a number out of the required range. Please enter again:");
					fflush(stdin);
					scanf("%d", &p2);
				}
				if (p2 % 4 == 0){
					x2 = 3;
					y2 = p2 / 4 - 1;
				}
				else{
					x2 = p2 % 4 - 1;
					y2 = p2 / 4;
				}
				try++;
			}
		}
		else{
			system("cls");
			p = b;
			for (r = 0; r < 4; r++){
				for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
				printf("\n\n");
			}
			switch (*(*(pa + y1) + x1)){
			case 0:	ch1 = '@'; break;
			case 1: ch1 = '#'; break;
			case 2: ch1 = '$'; break;
			case 3: ch1 = '!'; break;
			case 4: ch1 = '&'; break;
			case 5: ch1 = '^'; break;
			case 6: ch1 = '*'; break;
			case 7: ch1 = '~'; break;
			}
			stay[y1][x1] = ch1;
			switch (*(*(pb + y2) + x2)){
			case 0:	ch2 = '@'; break;
			case 1: ch2 = '#'; break;
			case 2: ch2 = '$'; break;
			case 3: ch2 = '!'; break;
			case 4: ch2 = '&'; break;
			case 5: ch2 = '^'; break;
			case 6: ch2 = '*'; break;
			case 7: ch2 = '~'; break;
			}
			stay[y2][x2] = ch2;
			for (sr = 0; sr < 4; sr++){
				for (sc = 0; sc < 4; sc++) printf("%c   ", *(*(sp + sr) + sc));
				printf("\n\n");
			}
			printf("Congratulation! Please Move on!");
			Sleep(2000);

			tempstay[y1][x1] = stay[y1][x1];
			tempstay[y2][x2] = stay[y2][x2];

			system("cls");
			p = b;
			for (r = 0; r < 4; r++){
				for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
				printf("\n\n");
			}

			temp = tempstay;
			for (tr = 0; tr < 4; tr++){
				for (tc = 0; tc < 4; tc++) printf("%c   ", *(*(temp + tr) + tc));
				printf("\n\n");
			}
			printf("Please enter your first choice:");
			scanf("%d", &p1);
			while (p1 < 1 || p1 > 16)
			{
				printf("You entered a number out of the required range. Please enter again:");
				fflush(stdin);
				scanf("%d", &p1);
			}
			if (p1 % 4 == 0){
				x1 = 3;
				y1 = p1 / 4 - 1;
			}
			else{
				x1 = p1 % 4 - 1;
				y1 = p1 / 4;
			}
			printf("Please enter your second choice:");
			scanf("%d", &p2);
			while (p2 < 1 || p2 > 16)
			{
				printf("You entered a number out of the required range. Please enter again:");
				fflush(stdin);
				scanf("%d", &p2);
			}
			if (p2 % 4 == 0){
				x2 = 3;
				y2 = p2 / 4 - 1;
			}
			else{
				x2 = p2 % 4 - 1;
				y2 = p2 / 4;
			}
			score++;
		}
	}
	finish = clock();
	switch (*(*(pa + y1) + x1)){
	case 0:	ch1 = '@'; break;
	case 1: ch1 = '#'; break;
	case 2: ch1 = '$'; break;
	case 3: ch1 = '!'; break;
	case 4: ch1 = '&'; break;
	case 5: ch1 = '^'; break;
	case 6: ch1 = '*'; break;
	case 7: ch1 = '~'; break;
	}
	stay[y1][x1] = ch1;
	switch (*(*(pb + y2) + x2)){
	case 0:	ch2 = '@'; break;
	case 1: ch2 = '#'; break;
	case 2: ch2 = '$'; break;
	case 3: ch2 = '!'; break;
	case 4: ch2 = '&'; break;
	case 5: ch2 = '^'; break;
	case 6: ch2 = '*'; break;
	case 7: ch2 = '~'; break;
	}
	stay[y2][x2] = ch2;
	User user;
	duration = (int)(finish - start) / CLOCKS_PER_SEC;
	system("cls");
	p = b;
	for (r = 0; r < 4; r++){
		for (c = 0; c < 4; c++) printf("%2d  ", *(*(p + r) + c));
		printf("\n\n");
	}
	sp = stay;
	for (sr = 0; sr < 4; sr++){
		for (sc = 0; sc < 4; sc++) printf("%c   ", *(*(sp + sr) + sc));
		printf("\n\n");
	}
	printf("You have made %d attempts and used %d seconds\n ", try, duration);

	for (sr = 0; sr < 4; sr++){
		for (sc = 0; sc < 4; sc++) {
			stay[sr][sc] = '_';
		}
	}
	char buff1[100] = { 0 };
	itoa(try, buff1, 10);
	strcpy(user.historytry, buff1);
	char buff2[20] = { 0 };
	itoa(duration, buff2, 10);
	strcpy(user.historytime, buff2);
	printf("Do you want to save the record? Y or N\n");
	fflush(stdin);
	save = getchar();
	if (save == 'N')
		Submenu();
	else{
		Writetohistory(user);
		Submenu();
	}
}