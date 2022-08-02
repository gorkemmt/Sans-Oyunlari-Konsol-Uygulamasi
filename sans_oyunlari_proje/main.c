#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int statsSansTopu2[14][2],statsSayisalLoto[49][2], statsOnNumara[80][2],statsSuperLoto[54][2],statsSansTopu[34][2];
int prizeOnNumara=0,prizeSansTopu=0,prizeSayisalLoto=0,prizeSuperLoto=0,statsDataCreate=0,totalPrize=0;

char selectch;
int selectint;

int main(){


    int seed;

    printf("Bir seed degeri giriniz: ");
    scanf("%d",&seed);
    srand(seed);

    if(statsDataCreate==0){
        dtCreate();
        statsDataCreate=1;
    }
   printf("\n");

   system("@cls||clear");

   mainMenu();

}

void dtCreate(){ // İstatistiklerin hata vermemesi için dizilere değer atanıyor.

    int i;

    for(i=0; i<49; i++){
        statsSayisalLoto[i][0]=i+1;
        statsSayisalLoto[i][1]=0;
    }

    for(i=0; i<34; i++){
        statsSansTopu[i][0]=i+1;
        statsSansTopu[i][1]=0;
    }

    for(i=0; i<14; i++){
        statsSansTopu2[i][0]=i+1;
        statsSansTopu2[i][1]=0;
    }

    for(i=0; i<80; i++){
        statsOnNumara[i][0]=i+1;
        statsOnNumara[i][1]=0;
    }

    for(i=0; i<54; i++){
        statsSuperLoto[i][0]=i+1;
        statsSuperLoto[i][1]=0;
    }
}

void randomNum(int ary[][2], int maxNum, int amount, int game){ // Random sayıları dizlere atamak için yaptığımız void

    int i, temp, checkedNum;

    srand(time(NULL));
    for(i=0; i<amount; i++){
        temp = 1+rand()%maxNum;
        checkedNum = checkNum(temp, ary, i+1, 0);

        if(checkedNum==1){
            ary[i][0]=temp;
            addDt(game, temp-1);
        }

        else i--;
    }
}

void mainMenu(){ // Uygulama açıldığında açılıcak ana menü

    selectint = 0;

    printf("\t Ana Menu \n");
    printf("1) Sans Oyunlari \n");
    printf("2) Cekilis Istatistikleri \n");
    printf("3) Cikis \n");

    printf("Hangi islemi yapmak istiyorsunuz ? "), scanf("%d", &selectint);

    system("@cls||clear");

    switch(selectint){
        case 1 : SansOyunlari();
        case 2 : Stats();
        case 3 : quit();
        default: printf("Lutfen 1-3 arasinda bir sayi degeri giriniz..\n"); mainMenu();
    }
}

void Stats(){
    statsMenu();
}

void statsMenu(){ // İstatistik Menüsü

    selectint = 0;

    printf("\tCekilis Istatistikleri \n");
    printf("\n 1) Sayisal Loto ");
    printf("\n 2) Sans Topu");
    printf("\n 3) On Numara");
    printf("\n 4) Super Loto");
    printf("\n 5) Ana Menu\n");

    printf("Yapmak istediginiz islemi seciniz:"), scanf("%d", &selectint);

    system("@cls||clear");

    switch(selectint){
        case 1: stats_SayisalLoto();
        case 2: stats_SansTopu();
        case 3: stats_OnNumara();
        case 4: stats_SuperLoto();
        case 5: mainMenu();
        default: printf("Lütfen 1-5 arasýnda bir sayi giriniz..");statsMenu();
    }
}

void addDt(int games_stats, int indexes){ // İstatistik dizilerinin değer ataması
    if(games_stats == 1)statsSayisalLoto[indexes][1]++;
    else if(games_stats == 2)statsSansTopu[indexes][1]++;
    else if(games_stats == 3)statsOnNumara[indexes][1]++;
    else if(games_stats == 4)statsSuperLoto[indexes][1]++;
    else if(games_stats == 5)statsSansTopu2[indexes][1]++;
    }

void quit(){ //Çıkış için kullanılan void

    selectch = ' ';

    printf("Cikmak istediginizden emin misiniz? (Evet: e/E, Hayýr: h/H )");
    scanf("%s",&selectch);

    system("@cls||clear");

    switch(tolower(selectch)){
        case 'e' : exit(0);
        case 'h' : mainMenu();
        default: printf("Lütfen e/E veya h/H degerlerini giriniz."); quit();
    }
}

void checkStats(int ary[][2], int ary_Size, int amount){ // Random üretilen sayıların kaç defa yazıldığını gösteren program

    int i;

    for(i=amount; i<ary_Size; i++){
        if(ary[amount-1][1]==ary[i][1]){
            printf("%d sayisi -", ary[i][0]);
            printf(" %d kere", ary[i][1]);
            printf("\n");
        }

    }
}

void quitStats(){ // İstatistiklerden çıkmak için hazırlanan küçük bir void

    char select2 = ' ';
    selectch = ' ';

    printf("\nDiger istatistikleri ogrenmek ister misiniz?(e/h)");
    scanf("%s",&selectch);

    system("@cls||clear");

    if(selectch == 'e' ){
       printf("\n");
       statsMenu();
    }

    else if(selectch == 'h'){
       printf("\nAna menuye donmek ister misiniz?(e/h)");
       scanf("%s",&select2);

       system("@cls||clear");

       if(select2 == 'e'){
          printf("\n");
          mainMenu();
       }

       else
          exit(0);
    }

}

int checkNum(int number, int ary[][2], int control_input, int ary_control){ // Kullanıcının ve bilgisayarın ürettiği random değerleri kendi aralarında kontrol eden void
    int i;

    for(i=0; i<control_input; i++){
         if(number == ary[i][ary_control])
            return 0;
    }

    return 1;
}

void sorting(int ary[][2], int ary_Size, int control_user){ //Kullanıcının girdiği değerleri sıralayan void

     int i, j, temp;

     for(i=0; i<ary_Size-1; i++)
        for(j=i+1; j<ary_Size; j++)
                if(ary[i][control_user] > ary[j][control_user]){
                    temp=ary[i][control_user];
                    ary[i][control_user]=ary[j][control_user];
                    ary[j][control_user]=temp;
                }
}

void sortingStats(int ary[][2], int ary_Size){ // İstatistikleri sıralayan void

     int i, j;
     int temp=0, temp2=0, temp3=0;

     for(i=0; i<ary_Size-1; i++){
        for(j=i+1; j<ary_Size; j++){
            if(ary[i][1] < ary[j][1]){
                temp=ary[i][1];
                ary[i][1]=ary[j][1];
                ary[j][1]=temp;

                temp2=ary[i][0];
                ary[i][0]=ary[j][0];
                ary[j][0]=temp2;
            }

            if(ary[i][1]==ary[j][1] && ary[i][0]>ary[j][0]){
                    temp3=ary[i][0];
                    ary[i][0]=ary[j][0];
                    ary[j][0]=temp3;
            }
        }
     }
}

void printAry(int ary[][2], int arraySize, int control_user){ //Dizileri yazdırmak için yazılan void

    int i;

    for(i=0; i<arraySize; i++)
        printf(" %d ",ary[i][control_user]);
}

void printStats(int ary[][2], int amount){ // İstatistikleri yazdıran void

    int i;

    for(i=0; i<amount; i++){
        printf("%d sayisi - ", ary[i][0]);
        printf(" %d defa", ary[i][1]);
        printf("\n");
    }
}

void SansOyunlari(){

    selectint = 0;

    totalPrize= prizeSayisalLoto + prizeSansTopu + prizeOnNumara + prizeSuperLoto;

    printf("\t Sans Oyunlari \n");
    printf("1) Sayisal Loto Oynama\n");
    printf("2) Sans Topu Oynama\n");
    printf("3) On Numara Oynama\n");
    printf("4) Super Loto Oynama\n");
    printf("5) Ana Menu\n");
    printf("Skorunuz : %d \n Baska bir oyun oynamak istiyormusunuz ?", totalPrize);
    scanf("%d", &selectint);

    system("@cls||clear");

    switch(selectint){
        case 1: SayisalLoto();
        case 2: SansTopu();
        case 3: OnNumara();
        case 4: SuperLoto();
        case 5: mainMenu();
        default: printf("Lütfen 1-5 arasinda bir deger giriniz..\n"); SansOyunlari();
    }
}

void SayisalLoto(){

    int ary_SayisalLoto[6][2];
    int i, j, checkedNum, tempNum, count ;
    selectch = ' ';

    for(i=0; i<=5; i++)
        for(j=0; j<=1; j++)
            ary_SayisalLoto[i][j] = 0;

    printf("\n Sayisal Loto \n");
    printf("1-49 arasinda 6 tane sayi giriniz..\n");

    for(i=0; i<=5; i++){
        printf("%d. sayi: ", i+1), scanf("%d", &tempNum);

        if(tempNum>=1 && tempNum<=49){

           checkedNum = checkNum(tempNum, ary_SayisalLoto, i+1, 1);

           if(checkedNum == 1)
              ary_SayisalLoto[i][1] = tempNum;

           else{
              printf("Bu degeri daha once girilmis... Lütfen tekrar deneyin..\n");
              i--;
           }
        }
        else{
            printf("Lutfen [1-49] araliginda bir sayi giriniz..\n");
            i--;
        }
    }

    randomNum(ary_SayisalLoto, 49, 6, 1);

    sorting(ary_SayisalLoto, 6, 1);
    sorting(ary_SayisalLoto, 6, 0);

    system("@cls||clear");

    printf("\nGirdiðiniz sayilar: ");
    printAry(ary_SayisalLoto, 6, 1);

    printf("\nÜretilen rastgele sayilar: ");
    printAry(ary_SayisalLoto, 6, 0);

    printf("\n");

    count=crossCheck(ary_SayisalLoto, 6, 6);

    if(count==0)
        printf("\nSayi tutturamadiniz.\n");

    else
        printf("\n%d sayi dogru tahmin ettiniz.\n", count);

    prizeSayisalLoto+= prize_SLoto(count);
    printf("\nSayisal Loto Toplam Puaniniz: %d\n", prizeSayisalLoto);

    for(i=0; i<1; i++){
        printf("\nYeniden oynamak ister misiniz?(e/h)"), scanf("%s",&selectch);

        switch(tolower(selectch)){
            case 'e': SayisalLoto();
            case 'h': SansOyunlari();
            default: printf("Lütfen e/E veya h/H karakterleri giriniz.."); i--;
        }
    }

}

void SansTopu(){
  int ary_STopu[6][2];
    int i, j, checkedNum, tempNum, count1, count2 ;
    selectch = ' ';

    for(i=0; i<=4; i++)
        for(j=0; j<=1; j++)
            ary_STopu[i][j] = 0;

    printf("\n Sans Topu \n");
    printf("1-34 araliginda 5 farkli sayi giriniz..\n");



    for(i=0; i<=4; i++){
        printf("%d. sayi: ", i+1);
        scanf("%d", &tempNum);

        if(tempNum>=1 && tempNum<=34){

           checkedNum = checkNum(tempNum, ary_STopu, i+1, 1);

           if(checkedNum == 1)
              ary_STopu[i][1] = tempNum;

           else{
              printf("Bu degeri daha once girdiniz. Lutfen farkli bir deger giriniz..\n");
              i--;
           }
        }
        else{
            printf("Lutfen [1-34] araliginda bir sayi giriniz..\n");
            i--;
        }
    }
    randomNum(ary_STopu, 34, 5, 2);
    sorting(ary_STopu, 5, 1);
    sorting(ary_STopu, 5, 0);

    printf("\nGirdiðiniz sayilar: ");
    printAry(ary_STopu, 5, 1);

    printf("\nÜretilen rastgele sayilar: ");
    printAry(ary_STopu, 5, 0);

    printf("\n");

    count1=crossCheck(ary_STopu, 5, 5);


    printf("[1-14] arasýnda bir sayi giriniz..\n");

    for(i=0; i<1; i++){
        printf("%d. sayi: ", i+1);
        scanf("%d", &tempNum);

        if(tempNum>=1 && tempNum<=14){

           checkedNum = checkNum(tempNum, ary_STopu, i+1, 1);

           if(checkedNum == 1)
              ary_STopu[i][1] = tempNum;

           else{
              printf("Bu degeri daha once girdiniz. Lutfen farkli bir deger giriniz..\n");
              i--;
           }
        }
        else{
            printf("Lutfen [1-14] araliginda bir sayi giriniz..\n");
            i--;
        }
    }


    randomNum(ary_STopu, 14, 1, 5);
    sorting(ary_STopu, 1, 1);
    sorting(ary_STopu, 1, 0);

    printf("\nGirdiðiniz sayilar: ");
    printAry(ary_STopu, 1, 1);

    printf("\nÜretilen rastgele sayilar: ");
    printAry(ary_STopu, 1, 0);

    printf("\n");

    count2=crossCheck(ary_STopu, 1, 1);

    if(count2==0)
        printf("\nSayi tutturamadiniz.\n");

    else
        printf("\n%d sayi dogru tahmin ettiniz.\n", count2);

    prizeSansTopu+=prize_SansTopu(count1,count2);
    printf("\nSans Topu Toplam Puaniniz: %d\n", prizeSansTopu);

    for(i=0; i<1; i++){
        printf("\nYeniden oynamak ister misiniz?(e/h)"), scanf("%s",&selectch);

        switch(tolower(selectch)){
            case 'e': SansTopu();
            case 'h': SansOyunlari();
            default: printf("Lütfen e/E veya h/H karakterleri giriniz.."); i--;
        }
    }

}

void OnNumara(){

    int i, j, checkedNum, tempNum, counter, arrayOnNumara[22][2];
    selectch = ' ';

    for(i=0; i<=21; i++)
        for(j=0; j<=1; j++)
            arrayOnNumara[i][j] = 0;

    printf("\nON NUMARA\n");
    printf("[1-80] araliginda 10 farkli sayi giriniz..\n");

    for(i=0; i<=9; i++){
        printf("%d. sayi: ", i+1), scanf("%d", &tempNum);

        if(tempNum>=1 && tempNum<=80){

           checkedNum = checkNum(tempNum, arrayOnNumara, i+1, 1);

           if(checkedNum == 1)
              arrayOnNumara[i][1] = tempNum;

           else{
              printf("Bu degeri daha once girdiniz. Lutfen farkli bir deger giriniz..\n");
              i--;
           }
        }
        else{
            printf("Lutfen [1-80] araliginda bir sayi giriniz..\n");
            i--;
        }
    }

    randomNum(arrayOnNumara, 80, 22, 3);

    sorting(arrayOnNumara, 10, 1);
    sorting(arrayOnNumara, 22, 0);

    system("@cls||clear");

    printf("\nGirdiginiz sayilar -->");
    printAry(arrayOnNumara, 10, 1);

    printf("\n");

    printf("Belirlenen sayilar -->");
    printAry(arrayOnNumara, 22, 0);

    printf("\n");

    counter=crossCheck(arrayOnNumara, 10, 22);

    if(counter==0)
        printf("\nSayi tutturamadiniz.\n");

    else
        printf("\n%d sayi dogru tahmin ettiniz.\n", counter);

    prizeOnNumara+=prize_OnNumara(counter);
    printf("\nOn Numara Toplam Puaniniz:%d\n", prizeOnNumara);

    for(i=0; i<1; i++){
        printf("\nYeniden oynamak ister misiniz?(e/h)"), scanf("%s",&selectch);

        switch(tolower(selectch)){
            case 'e': OnNumara();
            case 'h': SansOyunlari();
            default: printf("Lütfen e/E yada h/H karakterleri giriniz.."); i--;
        }
    }
}

void SuperLoto(){
    int ary_SuperLoto[6][2];
    int i, j, checkedNum, tempNum, puan ;
    selectch = ' ';

    for(i=0; i<=5; i++)
        for(j=0; j<=1; j++)
            ary_SuperLoto[i][j] = 0;

    printf("\n   SUPER LOTO \n");
    printf("[1-54] araliginda 6 farkli sayi giriniz..\n");

    for(i=0; i<=5; i++){
        printf("%d.sayiyi giriniz: ", i+1), scanf("%d", &tempNum);

        if(tempNum>=1 && tempNum<=54){

           checkedNum = checkNum(tempNum, ary_SuperLoto, i+1, 1);

           if(checkedNum == 1)
              ary_SuperLoto[i][1] = tempNum;

           else{
              printf("birbirinden farkli degerler girmelisiniz\n");
              i--;
           }
        }
        else{
            printf("lutfen [1-54] araliginda bir sayi giriniz..\n");
            i--;
        }
    }

    randomNum(ary_SuperLoto, 54, 6, 4);

    sorting(ary_SuperLoto, 6, 1);
    sorting(ary_SuperLoto, 6, 0);

    printf("\n|--girdiginiz degerler: ");
    printAry(ary_SuperLoto, 6, 1);

    printf("\n|--rastgele degerler: ");
    printAry(ary_SuperLoto, 6, 0);

    printf("\n");

    puan=crossCheck(ary_SuperLoto, 6, 6);

    if(puan==0)
        printf("\nhic sayi tutturamadiniz.\n");

    else
        printf("\neslesen degerler:%d \n", puan);

    prizeSuperLoto+= prize_SuperLoto(puan);
    printf("\nsuper loto puaniniz: %d\n", prizeSuperLoto);

    for(i=0; i<1; i++){
        printf("\nYeniden oynamak ister misiniz?(e/h)"), scanf("%s",&selectch);

        switch(tolower(selectch)){
            case 'e': SuperLoto();
            case 'h': SansOyunlari();
            default: printf("Lütfen e/E veya h/H karakterleri giriniz.."); i--;
        }
    }

}

void stats_SayisalLoto(){
    system("@cls||clear");

    printf("\tSayisal Lotonun Istatistikleri\n");
    sortingStats(statsSayisalLoto, 49);
    printStats(statsSayisalLoto, 6);
    checkStats(statsSayisalLoto, 49, 6);
    quitStats();
}

void stats_SansTopu(){
    system("@cls||clear");

    printf("\tSans Topunun Istatistikleri\n");
    sortingStats(statsSansTopu, 34);
    printStats(statsSansTopu, 6);
    checkStats(statsSansTopu, 34, 6);
    printf("----------|[0-14] arasi degerler|---------------\n");
    sortingStats(statsSansTopu2, 14);
    printStats(statsSansTopu2, 1);
    checkStats(statsSansTopu2, 14, 1);
    quitStats();
   }

void stats_OnNumara(){
    system("@cls||clear");

    printf("\tOn Numaranın Istatistikleri\n");

    sortingStats(statsOnNumara, 80);

    printf("\n");

    printStats(statsOnNumara, 10);

    checkStats(statsOnNumara, 80, 10);

    quitStats();
}

void stats_SuperLoto(){
    system("@cls||clear");

    printf("\tSuper Lotonun Istatistikleri\n");

    sortingStats(statsSuperLoto, 54);
    printStats(statsSuperLoto, 6);
    checkStats(statsSuperLoto, 54, 6);
    quitStats();
}

int crossCheck(int ary[][2], int ary_Size, int ary_Size2){ // Rastgele sayılar ile girilen sayıları karşılaştırıp sayacı arttırıp geri döndüren void

    int i, j, count=0, count2=0;

    printf("\n Tutturdugunuz sayilar: ");
    for(i=0; i<ary_Size; i++)
        for(j=0; j<ary_Size2; j++)
           if(ary[i][1]==ary[j][0]){
                count++;
                printf(" %d ", ary[i][1]);
           }

           return count;
}

int prize_SLoto(int count){ // Puanları hesaplayıp geri döndüren voidler

    int prize=0;

    if(count<=2 && count>=0)
        printf("\n Malesef puan kazanamadiniz.");

    else if(count==3){
        prize=32;
        printf("\n Tebrikler! \n Puaniniz: %d ", prize);
    }


    else if(count==4){
        prize=64;
        printf("\n Tebrikler! \n Puaniniz: %d", prize);
    }


    else if(count==5){
        prize=128;
        printf("\n Tebrikler! \n Puaniniz: %d", prize);
    }

    else if(count==6){
        prize=256;
        printf("\n Tebrikler! \n Puaniniz: %d", prize);
    }

    return prize;
}

int prize_SansTopu(int count1, int count2){

    int prize=0;

    if(count1==1&&count2==1){
        prize=2;
        printf("\n|--%d puan kazandiniz--|" , prize);
    }
        else if(count1==2&&count2==1){
        prize=4;
        printf("\n|--%d puan kazandiniz--|", prize);
    }

        else if(count1==3&&count2!=1){
        prize=8;
        printf("\n|--%d puan kazandiniz--|", prize);
    }
        else if(count1==3&&count2==1){
        prize=16;
        printf("\n|--%d puan kazandiniz--|", prize);
    }

        else if(count1==4&&count2!=1){
        prize=32;
        printf("\n|--%d puan kazandiniz--|", prize);
    }
        else if(count1==4&&count2==1){
        prize=64;
        printf("\n|--%d puan kazandiniz--|", prize);
    }
        else if(count1==5&&count2!=1){
        prize=128;
        printf("\n|--%d puan kazandiniz--|", prize);
    }
       else if(count1==5&&count2==1){
        prize=256;
        printf("\n|--%d puan kazandiniz--|", prize);
    }
    else{
            printf("puan kazanamadınız");
    }

    return prize;
}

int prize_SuperLoto(int puan){

    int prize=0;

    if(puan<=2 && puan>=0)
        printf("\n hic puan kazanamadiniz.");

    else if(puan==3){
        prize=32;
        printf("\n|--%d puan kazandiniz--|" , prize);
    }


    else if(puan==4){
        prize=64;
        printf("\n|--%d puan kazandiniz--|", prize);
    }


    else if(puan==5){
        prize=128;
        printf("\n|--%d puan kazandiniz--|", prize);
    }

    else if(puan==6){
        prize=256;
        printf("\n|--%d puan kazandiniz--|", prize);
    }

    return prize;
}

int prize_OnNumara(int counter){

    int reward=0;

    if(counter>=1 && counter<=6)
        printf("\nPuan kazanamadiniz.");

    else if(counter==0){
        reward=8;
        printf("\nTebrikler! %d puan kazandiniz.", reward);
    }

    else if(counter==6){
        reward=16;
        printf("\nTebrikler! %d puan kazandiniz.", reward);
    }

    else if(counter==7){
        reward=32;
        printf("\nTebrikler! %d puan kazandiniz.", reward);
    }

    else if(counter==8){
        reward=64;
        printf("\nTebrikler! %d puan kazandiniz.", reward);
    }

    else if(counter==9){
        reward=128;
        printf("\nTebrikler! %d puan kazandiniz.", reward);
    }

    else{
        reward=256;
        printf("\nTebrikler! %d puan kazandiniz.", reward);
    }

    return reward;
}
