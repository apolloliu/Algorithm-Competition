// #include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


#define VARDATA(x)          (x->data)
#define VARDATA_ANY(x)      (x->data)
#define VARSIZE_ANY_EXHDR(x) (strlen(VARDATA(x)))
#define VARHDRSZ             4
#define FLEXIBLE_ARRAY_MEMBER  500
typedef int int32;


typedef struct text
{
	int length;
	char *data;	
} text;

// typedef struct PersonName
// {
// 	// text      *family_name;
// 	// text      *given_name;
// 	char *family_name;
// 	char *given_name;
// }              PersonName;


typedef struct PersonName
{
		int32  length;
		char   data[FLEXIBLE_ARRAY_MEMBER];
}         PersonName;

void SET_VARSIZE(PersonName *x, int a) {
	x->length = a;
}


/*****************************************************************************
 * Input/Output functions
 *****************************************************************************/

static int32
check_name_internal(char *str)
{
	// Check titles
	if(strstr(str, "Dr") != NULL|| strstr(str, "Prof") != NULL
		|| strstr(str, "Mr") != NULL || strstr(str, "Ms") != NULL)
		return 0;

	int i = 0, total_size = strlen(str);

	// Check initials 
	if(total_size <= 1)return 0;

	// Check the first letter
	if(str[i] < 'A' || str[i] > 'Z')
		return 0;
	printf("cccccccccccccccccc, str: %s, total_size: %d\n", str, total_size);
	// Check the rest of letters
	for(i = 1; i < total_size; i++)
	{
		if(!((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| str[i] == '-' || str[i] == '\''))
			return 0;

		// Check extra space
		// if(space_num > 1)return 0;
	}

	return 1;
}

static int32
check_extra_space_internal(char *str, int32 valid_space_num)
{
	int i = 0, total_size = strlen(str);
	int j = total_size - 1;
	while(i < j && str[i] == ' ')i++, valid_space_num--;
	while(i < j && str[j] == ' ')j--, valid_space_num--;

	if(valid_space_num < 0)return 0;

	return 1;
}

PersonName* pname_in(char *str)
{

	printf("%s\n", str);
	// elog(NOTICE, "pname_in str: %s, size: %d", str, strlen(str));
	char     *full_name;
	// convert_to_personname_internal(str, full_name);
	
	int32    total_size = strlen(str);
	char     *str_copy = (char*)malloc(total_size);
	memcpy(str_copy, str, total_size);
	str_copy[total_size] = '\0';
	
	/** check validation **/
	char comma[2] = ",";

	char *first_part;
	char *second_part;
	char *others;
	char space[2] = " ";

	first_part = strtok(str, comma);
	second_part = strtok(NULL, comma);
	others = strtok(NULL, comma);

	// check validation - just one name or have more than two names
	if (second_part == NULL || others != NULL)
		{ printf("11111111111111\n");
			return NULL;}


	int32 first_part_size = strlen(first_part);
	int32 second_part_size = strlen(second_part);
	bool has_extra_space = (second_part[0] == ' ');

	/*** Check extra space ***/
	if(!check_extra_space_internal(first_part, 0) || !check_extra_space_internal(second_part, has_extra_space ? 1 : 0))
		{printf("2222222222222\n");
			return NULL;}

	/*** Check first part (family name) ***/
	char* first_part_tmp = (char*)malloc(first_part_size);
	memcpy(first_part_tmp, first_part, first_part_size);
	// strcpy(first_part_tmp, first_part);
	first_part_tmp[first_part_size] = '\0';
	char *split_first_part = strtok(first_part_tmp, space);
	while(split_first_part != NULL)
	{
		if(!check_name_internal(split_first_part))
			{
				printf("33333333333\n");
				return NULL;
			}
		split_first_part = strtok(NULL, space);
	}


	/*** Check second part (given name) ***/
	char* second_part_tmp = (char*)malloc(second_part_size);
	if(has_extra_space)
	{
		// strcpy(second_part_tmp, second_part + 1);
		memcpy(second_part_tmp, second_part + 1, second_part_size - 1);
		second_part_tmp[second_part_size - 1] = '\0';
	}
	else
	{
		// strcpy(second_part_tmp, second_part);
		memcpy(second_part_tmp, second_part, second_part_size);
		second_part_tmp[second_part_size] = '\0';
	}
	char *split_second_part = strtok(second_part_tmp, space);
	while(split_second_part != NULL)
	{
		printf("split_second_part: %s, size: %d\n", split_second_part, strlen(split_second_part));
		if(!check_name_internal(split_second_part))
			{
				printf("44444444444444\n");
				return NULL;
			}
		split_second_part = strtok(NULL, space);
	}

	/** Concat the full name **/
	int32 result_size = first_part_size + (second_part_size - (has_extra_space ? 1 : 0)) + 1;
	
	full_name = (char *) malloc(result_size + 1);
	memcpy(full_name, first_part, first_part_size);
	full_name[first_part_size] = ',';
	memcpy(full_name + first_part_size + 1, second_part + (has_extra_space ? 1 : 0), (second_part_size - (has_extra_space ? 1 : 0)));
	// strcpy(full_name + first_part_size + 1, second_part + (has_extra_space ? 1 : 0));
	full_name[result_size] = '\0';
	// elog(NOTICE, "has extra space: %s", has_extra_space ? "true" : "false");
	// elog(NOTICE, "full name: %s, size: %d", full_name, strlen(full_name));

	// int32    result_size = strlen(full_name);

	PersonName *result = (PersonName *) malloc(result_size + 1 + VARHDRSZ);
	/** Note: leave a space for the '\0' sign **/
	SET_VARSIZE(result, result_size + VARHDRSZ + 1);
	// memcpy(VARDATA(result), full_name, result_size);
	strcpy(VARDATA(result), full_name);

	// elog(NOTICE, "full name result: %s, VARSIZE_ANY_EXHDR size: %d", VARDATA(result), VARSIZE_ANY_EXHDR(result));

	// elog(NOTICE, "pname_in first_part: %s  second_part: %s\n", first_part, second_part);
	// elog(NOTICE, "pname_in full_name: %s  VARDATA(result): %s\n", full_name, VARDATA(result));
	
	// elog(NOTICE, "pname_in result: %s, size: %d\n", VARDATA(result), VARSIZE_ANY_EXHDR(result));


	printf("%s\n", VARDATA(result));

	return result;
}


char* pname_out(PersonName *personName)
{

	// PG_RETURN_CSTRING(result);
	cout << "aaaaaaaaaaaa" << endl;
	// cout << "final res: " << result << endl;

	return VARDATA(personName);
}

void
convert_to_personname_internal(char *str, char *full_name)
{
	int32    total_size = strlen(str);
	char     *tmp = (char*)malloc(total_size);
	memcpy(tmp, str, total_size);
	tmp[total_size] = '\0';
	// check validation
	char comma[2] = ",";

	char *first_part;
	char *second_part;
	char *others;
	char space[2] = " ";

	first_part = strtok(str, comma);
	second_part = strtok(NULL, comma);
	others = strtok(NULL, comma);

	// check validation - just one name or have more than two names
	if (second_part == NULL || others != NULL)
		printf("xxxxxxxxxx\n");


	int32 first_part_size = strlen(first_part);
	int32 second_part_size = strlen(second_part);
	bool has_extra_space = (second_part[0] == ' ');

	/*** Check extra space ***/
	if(!check_extra_space_internal(first_part, 0) || !check_extra_space_internal(second_part, has_extra_space ? 1 : 0))
		printf("xxxxxxxxxxxxx\n");


	/*** Check first part (family name) ***/
	char* first_part_tmp = (char*)malloc(first_part_size);
	// memcpy(first_part_tmp, first_part, first_part_size);
	strcpy(first_part_tmp, first_part);
	// first_part_tmp[first_part_size] = '\0';
	char *split_first_part = strtok(first_part_tmp, space);
	while(split_first_part != NULL)
	{
		if(!check_name_internal(split_first_part))
			printf("xxxxxxxxxxxx\n");
		split_first_part = strtok(NULL, space);
	}


	/*** Check second part (given name) ***/
	char* second_part_tmp = (char*)malloc(second_part_size);
	if(has_extra_space)
	{
		strcpy(second_part_tmp, second_part + 1);
		// memcpy(second_part_tmp, second_part + 1, second_part_size - 1);
		// second_part_tmp[second_part_size - 1] = '\0';
	}
	else
	{
		strcpy(second_part_tmp, second_part);
		// memcpy(second_part_tmp, second_part, second_part_size);
		// second_part_tmp[second_part_size] = '\0';
	}
	char *split_second_part = strtok(second_part_tmp, space);
	while(split_second_part != NULL)
	{
		if(!check_name_internal(split_second_part))
			printf("xxxxxxxxxxxxxx\n");
		split_second_part = strtok(NULL, space);
	}

	int32 result_size = first_part_size + (second_part_size - (has_extra_space ? 1 : 0)) + 1;
	
	full_name = (char *) malloc(result_size*2);
	// full_name = psprintf("%s,%s", first_part, second_part + (has_extra_space ? 1 : 0));
	full_name[result_size] = '\0';

	// return full_name;
}


int personname_cmp_internal(PersonName *a, PersonName *b)
{	

	// char *str_a = (char*) malloc(VARSIZE_ANY_EXHDR(a));
	// memcpy(str_a, VARDATA(a), VARSIZE_ANY_EXHDR(a));
	// char *str_b = (char*) malloc(VARSIZE_ANY_EXHDR(b));
	// memcpy(str_b, VARDATA(b), VARSIZE_ANY_EXHDR(b));
	char *a_family, *a_given;
	char *b_family, *b_given;

	a_family = (char *) malloc(VARSIZE_ANY_EXHDR(a));
	a_given = (char *) malloc(VARSIZE_ANY_EXHDR(a));
	b_family = (char *) malloc(VARSIZE_ANY_EXHDR(b));
	b_given = (char *) malloc(VARSIZE_ANY_EXHDR(b));

	printf("%s\n", VARDATA(a));
	sscanf(VARDATA(a), "%[^,\t\n],%[^\t\n]", a_family, a_given);
	sscanf(VARDATA(b), "%[^,\t\n],%[^\t\n]", b_family, b_given);

	bool a_has_space = (a_given[0] == ' ');
	bool b_has_space = (b_given[0] == ' ');

	int32 family_name_cmp = strcmp(a_family, b_family);
	int32 given_name_cmp = strcmp(a_given + (a_has_space ? 1 : 0), b_given + (b_has_space ? 1 : 0));

	printf("a->family_name: %s a->given_name: %s\n", a_family, a_given + (a_has_space ? 1 : 0));
	printf("b->family_name: %s b->given_name: %s\n", b_family, b_given + (b_has_space ? 1 : 0));
	// elog(NOTICE, "strcmp(a->family_name, b->family_name): %d\n", family_name_cmp);

	// elog(NOTICE, "%s,  %s, first_name, second_name: %d\n", first_name, second_name, strcmp(first_name, second_name));

	if(family_name_cmp != 0) return family_name_cmp;
	else if(given_name_cmp != 0) return given_name_cmp;
	else return 0;

	// char  *first_name;
	// char  *second_name;

	// convert_to_personname_internal(VARDATA(a), first_name);
	// convert_to_personname_internal(VARDATA(b), second_name);


	// return strcmp(first_name, second_name);
}

int main(){
	// freopen("input.txt", "r", stdin);

    char s[] = "Markovic, Dragana Vesna";
	const char *x = ",";

	PersonName *p = pname_in(s);
	// cin >> s;
	// printf("%s\n", strstr(s, x));

	// char *fmaily = strstr(s, x);
	// if(fmaily != NULL){
	// 	// if(fmaily[1] == ' ')cout << "ca" << endl;
	// 	int len = strlen(fmaily);
	// 	cout << fmaily << ' ' << len << endl;

	// 	char *new_str = (char *)malloc(len + 1);
	// 	memcpy(new_str, fmaily, len);
	// 	new_str[len] = '\0';
	// 	cout << "new str: " << new_str << ' ' << strlen(new_str) << endl;
	// } else {
	// 	puts("no");
	// }


	// cout << (strcmp("abc", "abd")) << endl;
	// cout << (strcmp("abd", "abc")) << endl;
	// cout << strlen(strstr("abc", "b")) << endl;

	// PersonName* res = pname_in(s);
	// cout << "11111111111" << endl;
	// char *out = pname_out(res);
	// cout << "out: " << out << endl;
	// // cout << out << endl;
	// // cout << VARDATA(->family_name) << endl;
	// char t[] = " a b'c";
	// char *tmp = t;
	// cout << strstr(t, "'") << endl;
	// char *h = strstr(t, "'");
	// cout << (h[0] == '\'') << endl;

	// cout << "xxxxxxxx" << endl;
	// h = strtok(t, " ");
	// while(h != NULL)
	// {
	// 	cout << h << endl;
	// 	h = strtok(NULL, " ");
	// }

	// // t = t + 1;
	// cout << t << endl;
	// cout << tmp << endl;


	PersonName *pa = (PersonName *) malloc(sizeof(PersonName));
	PersonName *pb = (PersonName *) malloc(sizeof(PersonName));
	char sa[100] = "Mahagedara Patabendige, Minosha Mitsuaki Senakasir";
	char sb[100] = "Mahagedara Patabendige,Minosha Mitsuaki Senakasir";
	memcpy(VARDATA(pa), sa, sizeof(sa));
	memcpy(VARDATA(pb), sb, sizeof(sb));

	cout << personname_cmp_internal(pa, pb) << endl;



	return 0;
}
