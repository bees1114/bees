#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char number[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char familyname[19][5] = {"Kim", "Kim", "Kim", "Kim", "Lee", "Lee", "Lee",
	"Park", "Park", "Choi", "Cha", "Han", "Baek", "Yoon",
	"Ha", "Cho", "Hyun", "Koo", "Lim"};
char jaeum[18][3] = {"k", "n", "d", "r", "l",
	"m", "b", "p", "s", "c",
	"a", "j", "g", "ch", "kh",
	"t", "ph", "h"};
char moeum[13][3] = {"a", "ya", "uh", "yu", "o", "yo", "u", "yu", "eu", "i",
"ae", "ea", "oi"};
char batchim[6][4] = {" ", "k ", "p ", "n ", "m ", "ng "};
char city[16][15] = {"Seoul", "Kyeonggi", "Kangwon", "Chungbuk", "Chungnam", 
	"Daejeon", "Incheon", "Daegu", "Kyungbuk", "Kyungnam",
	"Ulsan", "Pusan", "Junbuk", "Junman", "Jeonju", 
	"Kwangju"};

char orderState[3][4] = {"ING", "PRE", "COM"};
char month[3][3] = {"09", "10", "11"};
char day[30][3] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
	"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
	"21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
char sidArray[700][21];

int main(void) {
	//order and cart data
	char category_id[21], cid[21], pid[21], garbage[101], tempString[5];
	char order_day[12], delivery_detail[4];
	int i, j, index, amount;
	FILE * customer, *output;
	customer = fopen("customer.txt", "r");
	output = fopen("order.txt", "w");
	for(i = 0; i < 700; i++) {
		
		fgets(garbage, 100, customer);
		j = 0;
		sidArray[i][0] = '\0';
		while(garbage[j] != '|') {
			tempString[0] = garbage[j];
			tempString[1] = '\0';
			strcat(sidArray[i], tempString);
			j++;
		}
		printf("%s\n", sidArray[i]);
	}
	fclose(customer);
	
	srand(time(NULL));
	for(i = 0; i < 1000; i++) {
		cid[0] = '\0';pid[0] = '\0'; order_day[0] = '\0'; delivery_detail[0]='\0';
		index = ((double)rand())/((double)32768)*700;
		strcpy(cid, sidArray[index]);
		index = ((double)rand())/((double)32767)*700;
		itoa(index, pid, 10);
		amount = ((double)rand())/((double)32767)*15+1;
		index = ((double)rand())/((double)32768)*3;
		strcat(order_day, "2016-");
		strcat(order_day, month[index]);
		strcat(order_day, "-");
		index = ((double)rand())/((double)32768)*30;
		
		strcat(order_day, day[index]);
		index = ((double)rand())/((double)32768)*3;
		strcat(delivery_detail, orderState[index]);
		fprintf(output, "%s|%s|%s|%s|%d\n", cid, pid, order_day, delivery_detail, amount);
	}

	/////////////////////////////////////////////////////////////
	/*make category
	char category_id[21], category_name[21], tempString[5];
	int i, j, index, namelen;
	FILE *p = fopen("category.txt", "w");
	srand(time(NULL));
	for(i = 0; i < 26; i++) {
		category_id[0]='\0'; category_name[0]='\0';
		tempString[0] = alphabet[i];
		tempString[1] = '\0';
		strcpy(category_id, tempString);

		namelen = ((double)rand())/((double)32767)*7+5;
		for(j = 0; j < namelen; j++) {
			index = ((double)rand())/((double)32767)*25;
			tempString[0] = alphabet[index];
			tempString[1] = '\0';
			strcat(category_name, tempString);
		}

		fprintf(p, "%s|%s\n", category_id, category_name);
	}



	*/


	///////////////////////////////////////////////////////////////////

	/*
	char pid[21], pname[21], sid[21], garbage[100], tempString[5], category_id[21];
	int pnamelen, price, amount, i, j, index;
	double rate;
	FILE *output, *seller;
	output = fopen("product.txt", "w");
	seller = fopen("seller.txt", "r");
	for(i = 0; i < 700; i++) {
		
		fgets(garbage, 100, seller);
		j = 0;
		sidArray[i][0] = '\0';
		while(garbage[j] != '|') {
			tempString[0] = garbage[j];
			tempString[1] = '\0';
			strcat(sidArray[i], tempString);
			j++;
		}
	}
	fclose(seller);

	srand(time(NULL));
	for(i = 0; i < 1200; i++) {
		
		pid[0]='\0';tempString[0]='\0'; pname[0]='\0';category_id[0]='\0';sid[0]='\0';
		itoa(i, tempString, 10);
		strcpy(pid, tempString);

		pnamelen = ((double)rand())/((double)32767) * 7 + 5;
		for(j = 0; j < pnamelen; j++) {
			index = ((double)rand())/((double)32767)*25;
			tempString[0] = alphabet[index];
			tempString[1] = '\0';
			strcat(pname, tempString);
		}
		index = ((double)rand())/((double)32767)*25;
		tempString[0] = alphabet[index];
		tempString[1] = '\0';
		strcat(category_id, tempString);
		
		price = ((double)rand())/((double)32767)*100000 + 1000;
		rate = ((double)rand())/((double)32767)*10;
		amount = ((double)rand())/((double)32767)*100 + 1;
		index = ((double)rand())/((double)32767)*699;
		strcpy(sid, sidArray[index]);
		fprintf(output, "%s|%s|%d|%.2f|%s|%s|%d\n", pid, pname, price, rate, category_id, sid, amount);
	}
	*/
	////////////////////////////////////////////////////////////////////////
	/* seller and customer data
	char id[21], name[21], phoneNumber[21], address[51],;
	FILE *p, *fid, *fname, *fphoneNumber, *faddress;
	int idlen, namelen, i, j, index;
	p = fopen("customer.txt", "w");
	srand(time(NULL));
	for(i = 0; i < 700; i++) {
		
		idlen = ((double)rand())/((double)32767) * 7 + 5;
		id[0]='\0';name[0] = '\0';phoneNumber[0] = '\0';address[0] = '\0';
		for(j = 0; j < idlen; j++) {
			index = ((double)rand())/((double)32767)*25;
			tempString[0] = alphabet[index];
			tempString[1] = '\0';
			strcat(id, tempString);
		}

		/*people name
		index = ((double)rand())/((double)32767)*18;
		strcat(name, familyname[index]);
		strcat(name, " ");
		index = ((double)rand())/((double)32767)*17;
		strcat(name, jaeum[index]);
		index = ((double)rand())/((double)32767)*12;
		strcat(name, moeum[index]);
		index = ((double)rand())/((double)32767)*5;
		strcat(name, batchim[index]);
		index = ((double)rand())/((double)32767)*17;
		strcat(name, jaeum[index]);
		index = ((double)rand())/((double)32767)*12;
		strcat(name, moeum[index]);
		index = ((double)rand())/((double)32767)*5;
		strcat(name, batchim[index]);
		*/
		//phonenumber
		/*
		phoneNumber[0] = '\0';
		strcat(phoneNumber, "010");
		for(j = 0;j < 8; j++) {
			index = ((double)rand())/((double)32767)*9;
			tempString[0] = number[index];
			tempString[1] = '\0';
			strcat(phoneNumber, tempString);
		}
		*/
		/*city
		index = ((double)rand())/((double)32767)*15;
		strcat(address, city[index]);
		*/
	/*
		fprintf(p, "%s|%s|%s|%s\n", id, name, phoneNumber, address);

	}

	*/
	////////////////////////////////////////////////////////////////////////////
	return 0;
}
