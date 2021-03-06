#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int n1=0,n2=0,n,nresult,nresult2,carry=0;
    int nn;
    int p=1;
    struct ListNode* p1=l1;
    struct ListNode* p2=l2;
    struct ListNode* resultp,*newnode,*result;
    for(int i=0; ;i++){
        if(i!=0){
            p=p*10;
        }
        if(p1==NULL && p2==NULL){
            if(i==0){
                return NULL;
            }
            if(carry!=0){
                newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
                newnode->val=carry;
                newnode->next=NULL;
                if(i==0){
                    result=newnode;
                    resultp=newnode;
                    continue;
                }
                resultp->next=newnode;
                resultp=resultp->next;
            }
            break;
        }
        if(p1!=NULL){
            n1=p1->val;
            //printf("n1=%d\n",n1);
            p1=p1->next;
        }else{
            n1=0;
        }
        if(p2!=NULL){
            n2=p2->val;
            //printf("n2=%d\n",n2);
            //printf("%d %d %ld\n",p2->val,p,p*(p2->val));
            p2=p2->next;
        }else{
            n2=0;
        }
        n=n1+n2+carry;
        if(n<10){
            carry=0;
            newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=n;
            newnode->next=NULL;
            if(i==0){
                result=newnode;
                resultp=newnode;
                continue;
            }
            resultp->next=newnode;
            resultp=resultp->next;
        }else{
            carry=1;
            n=n%10;
            newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=n;
            newnode->next=NULL;
            if(i==0){
                result=newnode;
                resultp=newnode;
                continue;
            }
            resultp->next=newnode;
            resultp=resultp->next;
        }
    }
    return result;
}

int main(){
    struct ListNode *l1, *l2,*newnode,*p,*result;
    for(int i=0;i<9;i++){
        newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=9;
        newnode->next=NULL;
        if(i==0){
            l1=newnode;
            l1->next=NULL;
            p=l1;
            continue;
        }
        p->next=newnode;
        p=p->next;
    }
    for(int i=0;i<9;i++){
        newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=9;
        newnode->next=NULL;
        if(i==0){
            l2=newnode;
            l2->next=NULL;
            p=l2;
            continue;
        }
        p->next=newnode;
        p=p->next;
    }

    result=addTwoNumbers(l1,l2);
    for(int i=0;i<15;i++){
        if(result==NULL){
            printf("\n");
            break;
        }
        printf("%d->",result->val);
        result=result->next;
    }
    return 0;
}
