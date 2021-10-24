#include <bits/stdc++.h>
using namespace std;

typedef struct Node node;

struct customer
{
    int arrival_hour,arrival_minute,business_time;
};
struct Node
{
    struct customer         data;
    struct Node* next;
};
///comparison for sorting
bool compare_for_sorting(struct customer customer_1, struct customer customer_2)///sort korte toe 2 ta customer lagbei

{

    if(customer_1.arrival_hour==customer_2.arrival_hour);
    ///hour same hoile minute diye compared kore je age ashbe take pathabo
    return customer_1.arrival_minute<=customer_2.arrival_minute;
    return customer_1.arrival_hour<=customer_2.arrival_hour;
}
node* insert(node* head, struct customer customer_1)
{
    node *temp, *previous, *upcoming;
    temp = (node*)malloc(sizeof(node));
    temp->data = customer_1;///customer 1 er data gula temp e dhukaccie
    temp->next = NULL;///null because keu nai
    if(!head)
    {
        head=temp;///head mane mathe .ekta matha ber hoiye gele toe arekta matha head hoiye jabe.
    }
    else
    {
        previous = NULL;
        upcoming = head;
        while(upcoming && compare_for_sorting(upcoming->data,customer_1))
        {
            previous = upcoming;///chinta kor ki vane grameen phone center manus serial by serial jai
            upcoming = upcoming->next;
        }
        if(!upcoming)
        {
            previous->next = temp;
        }
        else
        {
            if(previous)
            {
                temp->next = previous->next;
                previous-> next = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
        }
    }
    return head;
}
int main()
{
    srand(time(0));
    int window_numbers_in_bank;///window numbers in bank
    while(1)
    {
        cout<<endl;
        cout<<" Please Enter the number of windows for the bank: ";
        cin>>window_numbers_in_bank;
        cout<<endl;

        if(window_numbers_in_bank<=0)
            break; /// if window_numbers_in_bank<=0 program will terminate
        int n=1+rand()%100;

        int hour,minute,business_time;
        node* Head=NULL;
        for(int i=0; i<n; ++i) ///i mane windo loop
        {
            hour=9+rand()%8;///working hours 9 to 5 //r 8 mane 8 ghonta
            minute=rand()%60;
            business_time=rand()%30;///30 mane 30 mins er besi hobe na
            struct customer customer_1;
            customer_1.arrival_hour = hour;
            customer_1.arrival_minute = minute;
            customer_1.business_time = business_time;
            Head = insert(Head,customer_1);
        }

        int last[window_numbers_in_bank]= {0},customer_number=0,service_cnt[window_numbers_in_bank]= {0};
        node* temp_node = Head;

        while(temp_node != NULL)  ///joto khon projonto last customer ashe ni totokhon projonto cholte thakbe
        {

            struct customer temp = temp_node->data;
            if(temp.business_time==0)///tui jodi service na nish tahole toe 0 e hobe . tarpor porer jon dhuke jabe
            {
                temp_node = temp_node ->next;
                continue;
            }
            ++customer_number;///service nei ni tao add hobe
            int minimum_last=0; ///suru hoar age toe shob kichu 0 e thake
            int j;
            for( j=1; j<window_numbers_in_bank; ++j)
            {
                if(last[j]<last[minimum_last])
                    minimum_last=j;///kun windowr kaj age sshes hocce and jar ta age shes hocce next jon tar tatei jabe
            }
            ++service_cnt[minimum_last];
            int waiting_time=last[minimum_last]-temp.arrival_hour*60-temp.arrival_minute; ///waiting time calulation
            waiting_time=max(waiting_time,0); ///waiting cant be negative
            last[minimum_last]=(temp.arrival_hour*60+temp.arrival_minute+waiting_time+temp.business_time); /// updating the last of the current window
            ///printing the output into the screen

            cout<<"---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<" Number ["<<customer_number<<"] Customer "<<temp.arrival_hour<<":"<<temp.arrival_minute<<" Arrive|| Wait for  "<<waiting_time<<" Minutes|| " ;

            int x=temp.arrival_hour,y=temp.arrival_minute;///time gula conver korce minute e
            ///convertinig in to hour and minute
            y+=waiting_time;
            x+=(y/60);
            y%=60;
            cout<<x<<":"<<y<<" Time at number "<<minimum_last+1<<" window  handle business|| last "<<temp.business_time<<" minutes.\n";
            temp_node = temp_node->next;
        }
        cout<<endl;
        cout<<" No longer accept customer business, ready to leave work."<<endl<<endl;
        for(int i=0; i<window_numbers_in_bank; ++i)
        {
            cout<<" Number "<<i+1<<" window serve totallY "<<service_cnt[i]<<" customers." <<endl;
        }
    }
    return 0;
}

