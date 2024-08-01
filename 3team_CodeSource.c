#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#define sec 1

int main(){

    int j=0, flag[2]={0};
    int LV=1,turn=0;
    char name[50]={0},ch=0;
    double exp=0, turn_exp=0, LV_exp_count[100]={0,300};
    double random_exp=0,event_exp=0.0,event_random=0.0, up_exp=0;
    
    
    srand(time(NULL));

    printf("닉네임을 지정해주세요: ");
    scanf("%s",name);
    while(getchar()!= '\n')

    printf("\n========== 게임을 시작 합니다 ==========\n");

    do{

        turn_exp=0;
        for(j=0;j<5; j++){ 
            random_exp=-35.0+(double)rand()/RAND_MAX*(35.0-(-35.0));
            turn_exp+=random_exp;//턴마다 경험치
        }

        event_random=1.0+(double)rand()/RAND_MAX*(5.0-1.0);
        event_exp=turn_exp*event_random;
        printf("이번턴 경험치 %.2f\n",event_exp*100);

        exp=exp+turn_exp*event_random;
        printf("현재 경험치 %.2f\n",exp*100); 
        printf("-----------------------------------------------\n");
        printf("전 : %s용사님,  %d번째 턴, 현재 레벨 %dLV, 현재 레벨 경험치 경험치 수치 %.2f, 남은 경험치 %.2f\n", name,turn ,LV , LV_exp_count[LV]*100,exp*100);
        printf("-----------------------------------------------\n");

        while(LV_exp_count[LV]<exp){ // 1 ->
            printf("==========================================\n");
            printf("레벨 업 들어옴\n");
            exp=exp-LV_exp_count[LV];// 400 -300
            printf("레벨 업 후 남은 경험치 %.2f\n",exp);//레벨업
            ++LV;//레벨 업
            printf("레벨 업 LV = %d\n", LV); //2

            up_exp=1.8+(double)rand()/RAND_MAX*(2.5-1.8);
            LV_exp_count[LV]=LV_exp_count[LV-1]*up_exp; // 300*2.5
            printf("==========================================\n");
        }
        printf("-----------------------------------------------\n");
        printf("중간 : %s용사님, %d번째 턴, 현재 레벨 %dLV, 현재 레벨 경험치 경험치 수치 %.2f, 남은 경험치 %.2f\n",name, turn ,LV , LV_exp_count[LV]*100,exp*100);
        printf("-----------------------------------------------\n");

        while(exp<0){
            printf("==========================================\n");
            printf("레벨 다운 들어옴\n");
            --LV;
            if(LV<=0)
                break;
            if(LV==1 && LV_exp_count[2]>0){
                flag[1]=1; break;
            }
                
            exp=LV_exp_count[LV]+exp;//300 + (-100)
            printf("레벨 다운 후 남은 경험치 %.2f\n",exp);
            printf("==========================================\n");
        }
        printf("-----------------------------------------------\n");
        printf("후 : %s용사님, %d번째 턴, 현재 레벨 %dLV, 현재 레벨 경험치 경험치 수치 %.2f, 남은 경험치 %.2f\n", name,turn ,LV , LV_exp_count[LV]*100,exp*100);
        printf("-----------------------------------------------\n");

    turn++;
    if(LV<=0){
        flag[0]=1; exp=0; break;
    }
    if(flag[1]==1)
        break;
    
    printf("다음 턴을 진행하시겠습니까?\n");
    printf("진행하려면 y 종료하려면 n을 눌러주세요 : ");
    scanf("%s",&ch);
    if (ch == 'y')
        continue;
    else if(ch == 'n'){
        printf("기다려주세요.\n");
        sleep(3);
        continue;
    }
    else{
        flag[0] =1;
        printf("잘못 입력하셨습니다.\n");
        printf("게임을 종료합니다.\n");
        break;
    }
    printf("-----------------------------------------------\n");
    
    

    }while(LV<100);

    if(flag[0]==1)
        printf("knock down\n");
    else if(flag[1]==1)
        printf("bad ending\n");
    else if (flag[0] == 0 && flag[1] == 0)
        printf("happy ending\n");
    
    printf("%d번째 턴, %s용사님, 현재 레벨 %dLV, 현재 레벨 경험치 경험치 수치 %.2f, 남은 경험치 %.2f\n", turn ,name,LV , LV_exp_count[LV]*100,exp*100);
    
    return 0;
}

