/*
 *
 * Banking system ver 0.1
 * 작성자 : 방은정
 * 내용: OOP 단계별 프로젝트의 기본 틀 구성
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 15
#define ACCOUNT_LEN 13

using namespace std;

typedef struct s_info{
    char account[ACCOUNT_LEN];
    char name[NAME_LEN];
    int money;
}t_info;

enum{MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

void show_menu(int client);
void make_account(t_info *info, int *client);
int deposit_money(t_info *clients, int client);
int withdraw_money(t_info *clients, int client);
int show_all_client(t_info *clients, int client);
t_info *find_client(t_info *clients, int client, char *account);


int main()
{
    int menu;
    int client = 0;

    t_info clients[101];
    while(1) {
        show_menu(client);
        cin >> menu;
        if(menu == MAKE) {
            make_account(clients, &client);
            client++;
        }
        else if(menu == DEPOSIT) {
            if (deposit_money(clients, client))
                return (1);
        }
        else if(menu == WITHDRAW) {
            if (withdraw_money(clients, client))
                return (1);
        }
        else if(menu == INQUIRE) {
            if (show_all_client(clients, client))
                return (1);
        }
        else if(menu == EXIT)
            break;
    }
}

void show_menu(int client)
{
    cout << "환영합니다. 은정 은행 고객 수: "<< client <<"입니다.\n";
    cout <<"----------Menu----------\n";
    cout << "1. 계좌개설\n";
    cout << "2. 입금\n";
    cout << "3. 출금\n";
    cout << "4. 계좌정보 전체 출력\n";
    cout << "5. 프로그램 종료\n";
    cout <<"선택 : ";
}


void make_account(t_info *info, int *client)
{
    cout << "[계좌개설]\n";
    cout << "계좌ID:";
    cin >>  info[*client].account;
    cout << "이름:";
    cin >> info[*client].name;
    cout << "입금액:";
    cin >> info[*client].money;
    cout <<"[입금정보] \n " << "성함 :" << info[*client].name <<" 계좌 ID: "<< info[*client].account << "입금 액: " << info[*client].money<<"\n";
}

t_info *find_client(t_info *clients, int client, char *account)
{
    for(int i= 0; i < client; i++) {
        cout << clients[i].account<<"\n";

        if (strcmp(clients[i].account, account) == 0)
               return &clients[i];
    }
    cout <<"cannot find account\n";
    return NULL;
}

int deposit_money(t_info *clients, int client)
{
    char account[13];
    int money;
    t_info *client_account;

    cout <<"[입금]\n";
    cout <<"계좌번호를 입력하세요: ";
    cin >> account;
    client_account = find_client(clients, client, account);
    if(! client_account)
        return (-1);
    cout <<"입금 금액을 입력하세요: ";
    cin >> money;
    client_account->money += money;
    cout <<"입금이 완료되었습니다.\n";
    return 0;
}

int withdraw_money(t_info *clients, int client)
{
    char account[13];
    int money;
    t_info *client_account;

    cout <<"[출금]\n계좌번호를 입력하세요: ";
    cin >> account;
    client_account = find_client(clients, client, account);
    if(! client_account)
        return (-1);
    cout <<"입금 금액을 입력하세요: ";
    cin >> money;
    if(client_account->money - money < 0)
    {
        cout <<"출금 금액이 너무 큽니다." <<"\n";
        return (-1);
    }
    client_account->money -= money;
    cout <<"출금이 완료되었습니다.\n";
    return 0;
}

int show_all_client(t_info *clients, int client)
{
   if(client <= 0)
       return (1);
    cout <<"[계좌정보 출력]\n";
    for(int i= 0; i < client; i++)
    {
        cout << "성함 : "<< clients[i].name <<"\n";
        cout <<"계좌번호 : "<< clients[i].account <<"\n";
        cout << "잔액 : "<<clients[i].money <<"\n";
    }
    return 0;
}
